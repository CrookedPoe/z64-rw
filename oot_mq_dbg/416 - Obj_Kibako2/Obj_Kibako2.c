/**
 * Obj_Kibako2.c
 *
 * A faithful rewrite of the breakable crate from OoT.
 *
 * by CrookedPoe and Dr.Disco
 *
 * variable structure
 * TODO
 **/

#include <z64ovl/oot/debug.h>

// Actor Information
#define OBJ          0x0170       /* object_kibako2 */
#define SFX          0x28AA       /* NA_SE_EV_WOODBOX_BREAK */

// Object Information
#define DL_CRATE     0x06000960   /* Crate Display List */
#define DL_PLANK     0x06001000   /* Plank (Broken Crate) Display List */
#define DYNAPOLY     0x06000B70   /* Dynapoly Collision Data */

typedef struct entity {
	z64_actor_t     						 actor; /* Common Actor Instance */
	z64_dynapoly_t  						 dynapoly; /* Dynapoly Structure */
	z64_collider_cylinder_main_t cylinder_body; /* Cylindrical Simple Body Collision */
	z64_actorfunc_t 						*machine_state; /* A Main Behavior Function (State Machine Code) */
	uint32_t        						 drop_seed; /* A Seed to Determine Item Drop */
} entity_t;

const z64_collider_cylinder_init_t simplebody =
{
	0x0A, 0x00, 0x09, 0x00, 0x20, 0x01,
	0x00, 0x00,
	0x00,
	0x00, 0x00, 0x00,
	0x00000000,
	0x00, 0x00,
	0x00, 0x00,
	0x40000040,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x00,
	0x00,
	0x001F, 0x0030, 0x0000,
	0x0000, 0x0000, 0x0000
};

const z64_dynapoly_init_t dynapoly_vars = {
	.unk_0 = {0xC8, 0x50},
	.scale = 100,
	.unk_1 = 0xB0F40BB8,
	.unk_2 = 0xB0F801F4,
	.unk_3 = 0x30FC03E8,
	.unk_4 = 0x00000000
};

/* Complete */
static void kibako2_init_simplebody(entity_t *en, z64_global_t *gl)
{
    actor_collider_cylinder_alloc(gl, &en->cylinder_body); /* Initialize Hitbox Capsule */
    actor_collider_cylinder_init(gl, &en->cylinder_body, &en->actor, &simplebody); /* Load Collision Array to Actor Instance */
    actor_collider_cylinder_update(&en->actor, &en->cylinder_body); /* Update Hitbox Position */
}

/* Rewrite status: Still quite a bit to figure out... */
// spawns planks and dust
static void kibako2_state_destroyed(entity_t *en, z64_global_t *gl)
{

	int16_t rspeed;
	int32_t rando_seed = 0;
	int32_t plank_count = 0;

	/* Spawn Pieces */
	do {
		vec3f_t burst_depth[2];
		float rando;
		rando = math_rand_zero_one() * 30.0f;
		/* burst_depth_x */
		burst_depth[0].x = (math_sins((rando_seed << 0x10) >> 0x10) * rando);
		burst_depth[0].y = (math_rand_zero_one() * 10.0f) + 2.0f;
		burst_depth[0].z = (math_coss((rando_seed << 0x10) >> 0x10) * rando);
		/* burst_depth_y */
		burst_depth[1].x = (float)(burst_depth[0].x * 0.2f);
		burst_depth[1].y = (float)(math_rand_zero_one() * 10.0f) + 2.0f;
		burst_depth[1].z = (float)(burst_depth[0].z * 0.2f);
		VEC3_ADD(burst_depth[0], (en->actor).pos_2)

		rando = math_rand_zero_one();

		if (rando < 0.05f)
		{
			rspeed = 0x60;
		}
		else
		{
			rspeed = 0x20;
			if (rando < 0.7f)
			{
				rspeed = 0x40;
			}
		}

		/* The Heavy Lifting */
		effect_spawn_fragment(
			gl
		,	&burst_depth[0], &burst_depth[1], &(en->actor).pos_2
		, -200
		, uVar1
		, 0x1C
		, 2
		, 0
		, (math_rand_zero_one() * 30.0f) + 5.0f
		, 0
		, 0
		, 0x46
		, -1
		, 0x170
		, DL_PLANK
	);
		plank_count++;
		rando_seed = (int)((rando_seed + 0x4E20) * 0x10000) >> 0x10;
	} while(plank_count != 16);

	// spawn dust particle effect
    external_func_80033480(gl, &(en->actor).pos_2, 90.0f, 6, 0x64, 0xA0, 1);
}

/* Complete */
static int kibako2_state_drop_item(entity_t *en, z64_global_t *gl)
{
		if ((-1 < (en->actor).init.rot.x) && ((en->actor).init.rot.x < 0x001A))
		{
			item_drop_collectible(gl, &(en->actor).pos_2, (uint16_t)((en->actor).init.rot.x | (en->drop_seed << 8)));
		}
}

/* Complete */
static void kibako2_state_sutaruspawn(entity_t *en, z64_global_t *gl)
{
    if (((en->actor).variable & 0x8000) == 0) /* Spawn Gold Skulltula */
    {
        actor_spawn(gl->actor_ctxt, gl, 0x0095, (en->actor).pos_2.x, (en->actor).pos_2.y, (en->actor).pos_2.z, 0, (en->actor).rot_2.y, 0, ((en->actor).variable | 0x8000));
    }
    kibako2_state_drop_item(en, gl);
    actor_kill(&en->actor);
}

/* Complete */
static void kibako2_state_default(entity_t *en, z64_global_t *gl)
{
    if (((((en->cylinder_body).base.collide_flags & 2)) == 0)
		&& ((en->actor).init.rot.z == 0)
		&& !(external_func_80033684(gl, en))
		)
    {
			if ((en->actor).dist_from_link_xz < 600.0f)
			{
					actor_collision_check_set_ac(gl, &gl->sbc_group_at_1, &en->cylinder_body); /* Subscribe to Collision Pool AC */
			}
    }
		else
		{
			kibako2_state_destroyed(en, gl);
			sound_play_position(gl, &en->actor.pos_2, 0x14, SFX);
			(en->actor).flags |= 0x10;
			external_func_8003EBF8(gl, AADDR(&gl->col_ctxt, 0x0050), (en->dynapoly).id); /* Dynapoly Collision Related */
			(en->actor).draw_proc = 0;
			en->machine_state = (z64_actorfunc_t*)kibako2_state_sutaruspawn;
		}
}

/* Complete */
static void init(entity_t *en, z64_global_t *gl)
{
    uint32_t dynapoly_pointer = 0;

    actor_dynapoly_set_move(&en->actor, DPM_NONE);
    actor_init_dynapoly(&en->actor, &dynapoly_vars);
    kibako2_init_simplebody(en, gl);
    dynapoly_alloc(DYNAPOLY, &dynapoly_pointer);

    (en->actor).rot_2.x = 0;
    en->drop_seed = (int16_t)((en->actor).init.rot.z & 0x3F);
    (en->dynapoly).id = actor_register_dynapoly(gl, AADDR(&gl->col_ctxt, 0x0050), &en->actor, dynapoly_pointer);
    en->machine_state = (z64_actorfunc_t*)kibako2_state_default;
    (en->actor).unk30 = (en->actor).rot_2.x;
    (en->actor).rot_2.z = (en->actor).rot_2.x;
    (en->actor).unk34 = (en->actor).rot_2.x;
    (en->actor).init.rot.z = (en->actor).rot_2.x;
		/*** Debug Information ***/
    //char data_80B96010[] = "_(_)(arg_&04xH)(item_%04xH_%d)";
    //external_func_80002130(&data_80B96010, (en->actor).variable, en->drop_seed, en->actor.init.rot.x);
}

/* Complete */
static void dest(entity_t *en, z64_global_t *gl)
{
    actor_collider_cylinder_free(gl, &en->cylinder_body);
    dynapoly_free(gl, AADDR(&gl->col_ctxt, 0x0050), (en->dynapoly).id);
}

/* Complete */
static void play(entity_t *en, z64_global_t *gl)
{
	z64_actorfunc_t *state_change = en->machine_state;
	state_change(en, gl);
}

/* Complete */
static void draw(entity_t *en, z64_global_t *gl)
{
    draw_dlist_opa(gl, DL_CRATE);
}

z64_actor_init_t init_vars =
{
	.number = 0xDEAD, .padding = 0xBEEF, // <-- magic values, do not change
	.type = OVLTYPE_BG,
	.room = 0x00,
	.flags = 0x00000000,
	.object = OBJ,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
