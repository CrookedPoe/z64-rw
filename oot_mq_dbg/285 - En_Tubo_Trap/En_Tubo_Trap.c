#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

#define OBJ_ID 3

/*** object ***/
#define DL_TUBO  0x05017870
#define DL_SHARD 0x05017A60

/*** sounds ***/
#define NA_SE_PL_BODY_HIT          0x083E
#define NA_SE_IT_SHIELD_REFLECT_SW 0x1808
#define NA_SE_EV_EXPLOSION         0x2802
#define NA_SE_EV_BOMB_DROP_WATER   0x2817
#define NA_SE_EV_POT_BROKEN        0x2887
#define	NA_SE_EV_POT_MOVE_START    0x28C4
#define NA_SE_EN_TUBOOCK_FLY       0x3037

typedef struct {
	z64_actor_t actor; 				 							 /* 0x0000, 0x013C */
	uint8_t inst_unk[16];  	   							 /* 0x013C, 0x0010 */
	z64_actorfunc_t *playfunc; 							 /* 0x014C, 0x0004 */
	float pos_y_seek;          							 /* 0x0150, 0x0004 */
	vec3f_t pos_init;          							 /* 0x0154, 0x000C */
	z64_collider_cylinder_main_t capsule;		 /* 0x0160, 0x004C */
} entity_t; /* 01AC */


/*** function prototypes ***/
static void draw(entity_t *en, z64_global_t *gl); /* Confirmed */
static void dest(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_drop_collectible(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_initialize_attack(entity_t *en); /* Confirmed */
static void tubo_trap_test_levitate(entity_t *en, z64_global_t *gl); /* Confirmed */
static void init(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_fragments(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_fragments_water(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 161 lines */
static void play(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_fly(entity_t *en, z64_global_t *gl); /* Confirmed */
static void tubo_trap_test_collider(entity_t *en, z64_global_t *gl); /* Confirmed */


/*** variables ***/
const uint32_t data_80B264E0[] =
{
	0x0A110900,
	0x20010000,
	0x00000000,
	0xFFCFFFFF,
	0x00040000,
	0xFFCFFFFF,
	0x00000000,
	0x01010000,
	0x00090017,
	0x00000000,
	0x00000000
};

/*** functions ***/
static void draw(entity_t *en, z64_global_t *gl)
{
	draw_static_dlist_opa(gl, DL_TUBO);
}

static void dest(entity_t *en, z64_global_t *gl)
{
	actor_capsule_free(gl, &en->capsule);
}

static void tubo_trap_drop_collectible(entity_t *en, z64_global_t *gl)
{
	uint16_t var_s24 = SEXT24((en->actor).variable);
	uint32_t drop_seed = (var_s24 | ((var_s24 >> 6 & 0x03FF) & 0x3F)) << 8;
	if (var_s24 < 0x001A)
	{
		item_drop_collectible(gl, &(en->actor).pos_2, drop_seed);
	}
}

static void tubo_trap_initialize_attack(entity_t *en)
{
	(en->actor).rot_2.y += 5000;
	external_func_8007841C(&(en->actor).pos_2.y, en->pos_y_seek, 0.8f, 3.0f); /* Tween levitation */
	if (ABS((en->actor).pos_2.y - en->pos_y_seek) < 10.0f)
	{
		(en->actor).xz_speed = 10.0f;
		(en->actor).xz_dir = (en->actor).rot_toward_link_y;
		en->playfunc = (z64_actorfunc_t *)tubo_trap_fly;
	}
}

static void tubo_trap_test_levitate(entity_t *en, z64_global_t *gl)
{
	z64_player_t *player = helper_get_player(gl);

	if ((AVAL(0x8015FA90, int16_t, 0x12D8)) != 0)
	{
		float pos_y = (en->actor).pos_2.y;
	}

	float link_y = (player->actor).pos_2.y;

	if (((en->actor).dist_from_link_xz < 200.0f) && ((en->actor).pos_2.y <= link_y))
	{
			float seek_y;

			external_func_80033748(gl, /*gl->actor_ctxt*/&AVAL(gl, char, 0x1C24), &en->actor, 5);
			(en->actor).flags |= 1;
			seek_y = 40.0f - (10.0f * zh_link_is_child()); /* 10 units lower if Child */
			en->pos_y_seek = link_y + seek_y;
			if (en->pos_y_seek < (en->actor).pos_2.y)
			{
					en->pos_y_seek = (en->actor).pos_2.y + seek_y;
			}
			(en->pos_init).x = en->actor.pos_2.x;
			(en->pos_init).y = en->actor.pos_2.y;
			(en->pos_init).z = en->actor.pos_2.z;
			sound_play_actor2(&en->actor, NA_SE_EV_POT_MOVE_START);
			en->playfunc = (z64_actorfunc_t *)tubo_trap_initialize_attack;
	}
}

static void init(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 40 lines */
{
	actor_init_shadow(&(en->actor).rot_2, 0, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 2.0f);
	actor_capsule_alloc(gl, &en->capsule);
	actor_capsule_init(gl, &en->capsule, &en->actor, data_80B264E0);
	actor_set_scale(&en->actor, 0.1f);
	en->playfunc = (z64_actorfunc_t *)tubo_trap_test_levitate;
}

static void tubo_trap_fragments(entity_t *en, z64_global_t *gl)
{
	uint32_t uVar1;
	int rando_seed = 0;
	int shard_count = 0;
	/* spawn fragments */
	do {
		vec3f_t burst_depth[2];
		/* burst_depth_x */
		burst_depth[0].x = math_sins(rando_seed) * 8.0f;
		burst_depth[0].y = (math_rand_zero_one() * 5.0f) + 2.0f;
		burst_depth[0].z = math_coss(rando_seed) * 8.0f;
		/* burst_depth_y */
		burst_depth[1].x = (float)(burst_depth[0].x * 0.23f);
		burst_depth[1].y = (float)(math_rand_zero_one() * 5.0f) + 2.0f;
		burst_depth[1].z = (float)(burst_depth[0].z * 0.23f);
		VEC3_ADD(burst_depth[0], (en->actor).pos_2)

		float rando = math_rand_zero_one();

		if (rando < 0.2f)
		{
			uVar1 = 0x60;
		}
		else
		{
			uVar1 = 0x20;
			if (rando < 0.6f)
			{
				uVar1 = 0x40;
			}
		}

		/* The Heavy Lifting */
		effect_spawn_fragment(
			gl
		,	&burst_depth[0], &burst_depth[1], &(en->actor).pos_2
		, -239
		, uVar1
		, 10
		, 10
		, 0
		, (math_rand_zero_one() * 65.0f) + 15.0f
		, 0
		, 0x20
		, 0x3C
		, -1
		, 3
		, DL_SHARD
	);
		shard_count++;
		rando_seed = (int)((rando_seed + 0x4E20) * 0x10000) >> 0x10;
	} while(shard_count != 15);
	external_func_80033480(gl, &(en->actor).pos_2, 30.0f, 4, 0x14, 0x32, 0);
}

static void tubo_trap_fragments_water(entity_t *en, z64_global_t *gl)
{
	/* prepare splash effect coordinates */
  vec3f_t burst_depth[2];
	math_vec3f_copy(&burst_depth[0], &en->actor.pos_2);
	burst_depth[0].y += (en->actor).water_surface_dist;

	/* spawn a small splash */
	effect_spawn_water_splash(gl, &burst_depth[0], 0, 0, 0, 0x190);

	uint32_t uVar1;
	int rando_seed = 0;
	int shard_count = 0;
	/* spawn fragments */
	do {
		/* burst_depth_x */
		burst_depth[0].x = math_sins(rando_seed) * 8.0f;
		burst_depth[0].y = (math_rand_zero_one() * 5.0f) + 2.0f;
		burst_depth[0].z = math_coss(rando_seed) * 8.0f;
		/* burst_depth_y */
		burst_depth[1].x = (float)(burst_depth[0].x * 0.23f);
		burst_depth[1].y = (float)(math_rand_zero_one() * 5.0f) + 2.0f;
		burst_depth[1].z = (float)(burst_depth[0].z * 0.23f);
		VEC3_ADD(burst_depth[0], (en->actor).pos_2)

		float rando = math_rand_zero_one();

		if (rando < 0.2f)
		{
			uVar1 = 0x60;
		}
		else
		{
			uVar1 = 0x20;
			if (rando < 0.6f)
			{
				uVar1 = 0x40;
			}
		}

		/* The Heavy Lifting */
		effect_spawn_fragment(
			gl
		,	&burst_depth[0], &burst_depth[1], &(en->actor).pos_2
		, -239
		, uVar1
		, 10
		, 10
		, 0
		, (math_rand_zero_one() * 65.0f) + 15.0f
		, 0
		, 0x20
		, 0x3C
		, -1
		, 3
		, DL_SHARD
	);
		shard_count++;
		rando_seed = (int)((rando_seed + 0x4E20) * 0x10000) >> 0x10;
	} while(shard_count != 15);
	external_func_80033480(gl, &(en->actor).pos_2, 30.0f, 4, 0x14, 0x32, 0);
}

static void play(entity_t *en, z64_global_t *gl)
{
	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, gl);
	external_func_8002D8E0(&en->actor); /* Probably to haul ass towards Link */
	external_func_8002E4B4(gl, &en->actor, 10.0f, 10.0f, 20.0f, 0x1D); /* Necessary for drawing a shadow */
	actor_set_height(&en->actor, 0);
	actor_capsule_update(&en->actor, &en->capsule);
	actor_collision_check_set_ac(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
	actor_collision_check_set_at(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
}

static void tubo_trap_fly(entity_t *en, z64_global_t *gl)
{
	vec3f_t pos_delta;
	int16_t rot_y;

	VEC3_SUB(pos_delta, en->pos_init, en->actor.pos_2);
	sound_play_actor2(&en->actor, NA_SE_EN_TUBOOCK_FLY);
	if (240.0f < SQRT((pos_delta.x * pos_delta.x) + (pos_delta.y * pos_delta.y) + (pos_delta.z * pos_delta.z)))
	{
		external_func_8007841C(&(en->actor).gravity, -3.0f, 0.2f, 0.5f); /* Tween to ground */
		rot_y = (en->actor).rot_2.y;
	}
	else
	{
		rot_y = (en->actor).rot_2.y;
	}
	(en->actor).rot_2.y = rot_y + 5000;
	tubo_trap_test_collider(en, gl);
}

static void tubo_trap_test_collider(entity_t *en, z64_global_t *gl)
{
	uint8_t bVar1, bVar2;
	uint16_t uVar3;
	z64_actor_t *collided_actor;
	z64_player_t *player = helper_get_player(gl);

	if (((en->actor).bgcheck_flags & 20) == 0)
	{
		bVar1 = (en->capsule).base.collider_flags;
	}
	else
	{
		if ((en->actor).water_surface_dist > 15.0f)
		{
			tubo_trap_fragments_water(en, gl);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_BOMB_DROP_WATER);
			tubo_trap_drop_collectible(en, gl);
			actor_kill(&en->actor);
			return;
		}
		bVar1 = (en->capsule).base.collider_flags;
	}

	if ((bVar1 & 4) == 0)
	{
		bVar2 = (en->capsule).base.collide_flags;
		if ((bVar2 & 2) == 0)
		{
			if ((bVar1 & 2) == 0)
			{
				uVar3 = (en->actor).bgcheck_flags;
			}
			else
			{
				collided_actor = (en->capsule).base.unk_actor_1;
				(en->capsule).base.collider_flags = bVar1 & 0xFD;
				if (collided_actor == &(player->actor))
				{
					tubo_trap_fragments(en, gl);
					sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
					sound_play_position(gl, &(player->actor).pos_2, 0x28, NA_SE_PL_BODY_HIT);
					tubo_trap_drop_collectible(en, gl);
					actor_kill(&en->actor);
					return;
				}
				uVar3 = (en->actor).bgcheck_flags;
			}
			if (((uVar3 & 8) != 0) || ((uVar3 & 1) != 0))
			{
				tubo_trap_fragments(en, gl);
				sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
				tubo_trap_drop_collectible(en, gl);
				actor_kill(&en->actor);
			}
		}
		else
		{
			(en->capsule).base.collide_flags = bVar2 & 0xFD;
			tubo_trap_fragments(en, gl);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_EXPLOSION);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
			tubo_trap_drop_collectible(en, gl);
			actor_kill(&en->actor);
		}
	}
	else
	{
		(en->capsule).base.collider_flags = bVar1 & 0xFB;
		tubo_trap_fragments(en, gl);
		sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_IT_SHIELD_REFLECT_SW);
		sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
		tubo_trap_drop_collectible(en, gl);
		actor_kill(&en->actor);
	}
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* for use with zzromtool */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
