/**
 * tsubo.c
 *
 * A faithful rewrite of the liftable, breakable pot from OoT.
 *
 * by CrookedPoe and Dr.Disco
 *
 * variable structure
 * TODO
 **/

/**
 * TODO
 * global_plus_0x117A4 is used in two places; once as u16 and once as uint32_t...
   what type is this data block?
 * tsubo_playfunc_init() is a huge mess right now
*/

#include <stdint.h>
#include "../../z64ovl/oot_debug.h"
#include "../../z64ovl/helpers.h"

typedef struct {
	z64_actor_t     actor;
	z64_dynapoly_t  dynapoly;
	z64_capsule_t   capsule;
	z64_actorfunc_t *playfunc;
	int data_80BA1B50;
	int16_t data_80BA1B54;
	int data_80BA1B58;
	int16_t data_80BA1B5C;
	char object_index;
} entity;

// Constants
#define NUMSHARDS             15         // number of shards to spawn pot breaks

// Sounds
#define NA_SE_EV_POT_BROKEN   0x2887
#define NA_SE_PL_PULL_UP_POT  0x086F

// Display Lists
#define DL_VASE_DUNGEON       0x05017870 // vase
#define DL_VASE_TSUBO         0x060017C0
#define DL_SHARD_DUNGEON      0x05017A60 // vase shard
#define DL_SHARD_TSUBO        0x06001960

// Objects
#define OBJ_VASE_DUNGEON      0x0003
#define OBJ_VASE_TSUBO        0x012C
#define OBJ                   0x0001    // unspecified primary object dependency (gameplay_keep)

// Variable Macros
#define TSUBO_WHICH(ACTORVAR) ( ( ACTORVAR >> 8 ) & 1 )

// play state prototypes
static void tsubo_playfunc_init(entity *en, z64_global_t *global);
static void tsubo_playfunc_carry(entity *en, z64_global_t *global);
static void tsubo_playfunc_thrown(entity *en, z64_global_t *global);
static void tsubo_playfunc_default(entity *en, z64_global_t *global);

// particle function IDs
enum particle {
	PARTICLE_BREAK = 0,
	PARTICLE_BREAK_WATER
};

uint32_t DL_VASE[] = {
	DL_VASE_DUNGEON,
	DL_VASE_TSUBO
};

uint32_t DL_SHARD[] = {
	DL_SHARD_DUNGEON,
	DL_SHARD_TSUBO
};

uint32_t OBJ_VASE[] = {
	OBJ_VASE_DUNGEON,
	OBJ_VASE_TSUBO
};

// TODO: could this answer some questions regarding other dynapoly bits?
uint32_t dynapoly_vars[] = {
	0xB86CFB50,
	0xB870B1E0,
	0xC8500096, /* usual dynapoly vars */
	0xB0F40384,
	0xB0F80064,
	0x30FC0320
};

// data_80BA1B94
z64_capsule_init_t capsule_data =
{
	.unk1 = 0x0C090939,
	.unk2 = 0x20010000,
	.unk3 = 0x00000000,
	.unk4 = 0x00000002,
	.damage_type = 0x00,
	.damage_amount = 0x01,
	.unk5 = 0x0000,
	.unk6 = 0x4FC1FFFE,
	.unk7 = 0x00000000,
	.unk8 = 0x01010100,
	.radius = 0x0009,
	.height = 0x001A,
	.unk9 = 0x00000000,
	.unk10 = 0x00000000
};

static void draw(entity *en, z64_global_t *global)
{
    draw_static_dlist(global, DL_VASE[ TSUBO_WHICH(en->actor.variable) ] );
}

static void tsubo_particle_shards(entity *en, z64_global_t *global)
{

    uint32_t seed = 0; // seed, used for randomization

	for(int shard=0; shard < NUMSHARDS; ++shard) {

		vec3f_t pos, pos1;

		pos.x = math_sins((int) (seed << 0x10) >> 0x10) * 8.0f;
		pos.y = (math_rand_zero_one() * 5.0f) + 2.0f;
		pos.z = math_coss((int) (seed << 0x10) >> 0x10) * 8.0f;

		pos1.x = (float) (pos.x * 0.23f);
		pos1.y = (float) ((math_rand_zero_one() * 5.0f) + 2.0f);
		pos1.z = (float) (pos.y * 0.23f);

		// TODO: test speed against adding xyz separately
		// if adding xyz separately is more optimal,
		// a global MATH_VEC3F_ADD macro is in order
		math_vec3f_add(&pos, &en->actor.pos_2, &pos);

		float randval = math_rand_zero_one();

		uint32_t unk;

		if (randval < 0.2f)
		{
			unk = 0x60;
		}
		else
		{
			unk = 0x20;
			if (randval < 0.6f)
			{
				unk = 0x40;
			}
		}
		int which = TSUBO_WHICH(en->actor.variable);
		external_func_80029E8C(
			global,
			&pos, &pos1, &en->actor.pos_2,
			-0xf0, unk, 0xa,
			0xa,
			0,
			(math_rand_zero_one() * 95.0f) + 15.0f,
			0,
			0x20,
			0x3c,
			-1,
			OBJ_VASE[which],
			DL_SHARD[which]
		);
		seed = (int) ((seed + 0x4e20) << 0x10) >> 0x10;
	}

	// dust effect
    external_func_80033480(
		global,
		&en->actor.pos_2,
		30.0f/*0x41f00000*/,
		4, 0x14, 0x32, 1
	);
}

static void tsubo_particle_shards_water(entity *en, z64_global_t *global)
{

	// prepare splash effect coordinates
	vec3f_t pos = en->actor.pos_2;
	pos.y += en->actor.water_surface_dist;

	// spawn a small splash
    external_func_8002949C(
		global, &pos,
		0, 0, 0, 0x190
	);

	uint32_t seed = 0; // seed, used for randomization

	for(int shard=0; shard < NUMSHARDS; ++shard) {

		float randval = math_coss( (seed << 0x10) >> 0x10) * 8.0f;

		pos.x = math_sins( (seed << 0x10) >> 0x10) * 8.0f;
		pos.y = (math_rand_zero_one() * 5.0f) + 2.0f;
		pos.z = randval;

		vec3f_t pos1;
		pos1.x = pos.x * 0.2f;
		pos1.y = (math_rand_zero_one() * 4.0f) + 2.0f;
		pos1.z = randval * 0.2f;

		math_vec3f_add(&pos, &en->actor.pos_2, &pos);

		uint32_t unk = 0x20;

		if (math_rand_zero_one() < 0.2f)
		{
			unk = 0x40;
		}
		int which = TSUBO_WHICH(en->actor.variable);
		external_func_80029E8C(
			global,
			&pos, &pos1, &en->actor.pos_2,
			-0xb4, unk, 0x1e,
			0x1e,
			0,
			(math_rand_zero_one() * 95.0f) + 15.0f,
			0,
			0x20,
			0x46,
			-1,
			OBJ_VASE[which],
			DL_SHARD[which]
		);
		seed = ((seed + 0x4e20) << 0x10) >> 0x10;
	}
}

// destroy the pot (spawns effects, plays sounds, and kills the actor)
static void tsubo_destroy(entity *en, z64_global_t *global, const enum particle particle_func)
{
	switch(particle_func) {
		case PARTICLE_BREAK:
			tsubo_particle_shards(en, global);
			break;
		case PARTICLE_BREAK_WATER:
			tsubo_particle_shards_water(en, global);
			break;
	}

	sound_play_position(global, &en->actor.pos_2, 0x14, NA_SE_EV_POT_BROKEN);

    uint32_t seed = (uint32_t) ((en->actor.variable & 0x1F) << 0x10) >> 0x10;
    if (seed >= 0)
    {
        if (seed < 0x1A)
        {
            /*phi_return = */item_drop_collectible(
				global, &en->actor.pos_2,
				(uint32_t) ((seed | ((((uint32_t) en->actor.variable >> 9) & 0x3f) << 8)) << 0x10) >> 0x10
				//, arg0 // TODO What's this extra argument for?
			);
        }
    }

	actor_kill(&en->actor);
}

// physics: update Y speed / velocity
// NOTE: Same as that in kibako! Does this have potential to become a helper to reduce redundant code?
static float tsubo_physics_update_y_vel(entity *en, z64_global_t *global)
{
    en->actor.vel_1.y = (en->actor.vel_1.y + en->actor.gravity);

    if (en->actor.vel_1.y < en->actor.min_vel_y)
    {
        en->actor.vel_1.y = en->actor.min_vel_y;
    }
}

// do a raycast to set the pot on the floor
// returns 1 on successful raycast, 0 on failure
static int tsubo_init_floorpos(entity *en, z64_global_t *global)
{
    int sp34; // TODO: unknown type...
    int sp24; // TODO: unknown type...

	vec3f_t pos = en->actor.pos_2;
	pos.y += 20.0f;

    float result = math_raycast((uint32_t)global + 0x07C0, &sp34, &sp24, &en->actor, &pos);

	// successful raycast
    if ( RAYCAST_SUCCESS(result) )
    {
        en->actor.pos_2.y = result;
		// TODO: Test if this is any faster or more compact than pos1 = pos2
        math_vec3f_copy(&en->actor.pos_1, &en->actor.pos_2);
        return 1;
    }

	// failed raycast
	// TODO what did the original data_80BA1BE0 suggest?
    //debug_message("tsubo raycast fail (x=%d, vram=%X)", en->actor.pos_2.x, (uint32_t)en);
	// original code, for reference:
    //debug_message(&data_80BA1BE0, en->actor.pos_2.x, arg0);
    return 0;
}

// func_80BA0E98
static void tsubo_init_collision(entity *en, z64_global_t *global)
{
	// allocate memory for hitbox capsule
    actor_capsule_alloc(global, &en->capsule);

	// initialize that memory
    actor_capsule_init(global, &en->capsule, &en->actor, &capsule_data);

	// update hitbox position
    actor_capsule_update(&en->actor, &en->capsule);
}

// func_80BA15AC
static void tsubo_setstate_default(entity *en, z64_global_t *global)
{
    en->playfunc = (z64_actorfunc_t*)tsubo_playfunc_default;
}

static void tsubo_setstate_init(entity *en, z64_global_t *global)
{
    en->playfunc = (z64_actorfunc_t*)tsubo_playfunc_init;
}

// 80BA17C4
static void tsubo_setstate_carry(entity *en, z64_global_t *global)
{
    en->playfunc = (z64_actorfunc_t*)tsubo_playfunc_carry;
    en->actor.room_index = 0xFF;
    sound_play_actor(&en->actor, NA_SE_PL_PULL_UP_POT);
    en->actor.flags |= 0x10;
}

static void tsubo_setstate_thrown(entity *en, z64_global_t *global)
{
	// initialize xz velocity, mass
    en->actor.vel_1.x = (math_sins(en->actor.xz_dir) * en->actor.xz_speed);
    en->actor.vel_1.z = (math_coss(en->actor.xz_dir) * en->actor.xz_speed);
    en->actor.mass = 0xF0;

	// default 0; I question whether these are even necessary...
    en->data_80BA1B54 = 0;
    en->data_80BA1B5C = 0;

	// initialize some random seeds (I think...)
    en->data_80BA1B58 = (int)((math_rand_zero_one() - 0.5f) * 2000.0f);
    en->data_80BA1B50 = (int)((math_rand_zero_one() - 0.7f) * 2800.0f);

    en->playfunc = (z64_actorfunc_t*) tsubo_playfunc_thrown;
}

// data_80BA153C
static void tsubo_playfunc_init(entity *en, z64_global_t *global)
{
    if (object_is_loaded(((uint32_t)global + 0x00117A4), en->object_index) )
    {
        en->actor.draw_proc = (void*)draw;
        en->actor.alloc_index = en->object_index;

		// original args: func_80BA15AC(temp_a2_2, temp_a2_2);
		// didn't make sense, so maybe this is broken:
        tsubo_setstate_default(en, global);
        en->actor.flags &= (uint32_t) -0x11; // TODO: -0x11 is ugly, let's go with something ore maintainable...
    }
}

// 80BA15BC
static void tsubo_playfunc_default(entity *en, z64_global_t *global)
{
	// pot lifted by Link
    if ( actor_is_held(&en->actor) )
    {
		tsubo_setstate_carry(en, global);
        return;
    }

	// pot fell in water
    if ( en->actor.bgcheck_flags & 0x20 )
    {
        if (15.0f < en->actor.water_surface_dist)
        {
            tsubo_destroy(en, global, PARTICLE_BREAK_WATER);
            return;
        }
    }

	// TODO: unknown cause of death...
    if ((en->capsule.cso_0x01 & 2) != 0)
    {
        if ((en->capsule.unk_0x3C & 0x4FC1FFFC) != 0)
        {
            tsubo_destroy(en, global, PARTICLE_BREAK);
            return;
        }
    }

	// when the pot is near enough...
    if (en->actor.dist_from_link_xz < 600.0f)
    {
		// ... test for capsule updates...
        actor_capsule_update(&en->actor, &en->capsule);
        en->capsule.cso_0x01 = (s8) (en->capsule.cso_0x01 & 0xFFFD);

		// ... and test for projectiles
        actor_collision_check_set_ac(global, ((uint32_t)global + 0x0011E60), &en->capsule);

		// when pot is *even nearer to Link*...
        if (en->actor.dist_from_link_xz < 150.0f)
        {
			// ... test for collisions against Link
            actor_collision_check_set_ot(global, ((uint32_t)global + 0x0011E60), &en->capsule);
        }
    }
	// TODO: this is just a theory
	// if pot is even nearer to Link, breaking it gives him the item automatically, no spawning
    if (en->actor.dist_from_link_xz < 100.0f)
    {
        helper_lift_test(&en->actor, global, 30.0f, 30.0f);
    }
}

// data_80BA180C
static void tsubo_playfunc_carry(entity *en, z64_global_t *global)
{
	// TODO: document external_func_8002F5A0(); does it really require no arguments?
    if (external_func_8002F5A0() != 0)
    {
        en->actor.room_index = AVAL(global, char, 0x11CBC);
        tsubo_setstate_thrown(en, global);
        tsubo_physics_update_y_vel(en, global);
        actor_update_pos(&en->actor);
        external_func_8002E4B4(global, &en->actor, 5.0f, 15.0f, 0.0f, 0x85);
    }
}

// data_80BA1958
static void tsubo_playfunc_thrown(entity *en, z64_global_t *global)
{
	// almost the same as kibako, definitely worth mapping out these bits!
    if  (   (en->actor.bgcheck_flags & 0xB)
			|| (en->capsule.cso_0x01 & 2)
		)
    {
        tsubo_destroy(en, global, PARTICLE_BREAK);
        return;
    }

	// fell in water
    if ( en->actor.bgcheck_flags & 0x40 )
    {
        tsubo_destroy(en, global, PARTICLE_BREAK_WATER);
        return;
    }

	// update physics (y velocity) and actor location
    tsubo_physics_update_y_vel(en, global);
    actor_update_pos(&en->actor);

	// if I had to guess, this derives a random rotation...
    external_func_8007797C( &en->data_80BA1B54, en->data_80BA1B50, 0x64);
    external_func_8007797C( &en->data_80BA1B5C, en->data_80BA1B58, 0x64);

	// ... to randomize the spin
    en->actor.rot_2.x += (int16_t)en->data_80BA1B54;
    en->actor.rot_2.y += (int16_t)en->data_80BA1B5C;

    external_func_8002E4B4(global, &en->actor, 5.0f, 15.0f, 0.0f, 0x85);

    actor_capsule_update(&en->actor, &en->capsule);

    actor_collision_check_set_ot(global, ((uint32_t)global + 0x0011E60), &en->capsule);
    actor_collision_check_set_at(global, ((uint32_t)global + 0x0011E60), &en->capsule);
}

static void init(entity *en, z64_global_t *global)
{
		actor_set_scale(&en->actor, 0.15f);
    //actor_init_dynapoly(&en->actor, &dynapoly_vars);
    tsubo_init_collision(en, global);
    uint32_t data_80BA1BC0[] = {0x0000000C, 0x003CFF00};
    external_func_80061ED4(&en->actor.damage_table, NULL, data_80BA1BC0);

	// do a raycast to set the pot on the floor; if the raycast fails, kill actor
    if (tsubo_init_floorpos(en, global) == 0)
    {
        actor_kill(&en->actor);
        return;
    }
    en->object_index = object_get_index(
		((uint32_t)global + 0x00117A4),
		OBJ_VASE[ TSUBO_WHICH(en->actor.variable) ]
	);
    if (en->object_index < 0)
    {
		// data_80BA1BF0
		//debug_message("Error: tsubo (arg_data 0x%04x)(%s %d)", en->actor.variable, "../z_obj_tsubo.c", 0x19A);
        actor_kill(&en->actor);
        return;
    }
    tsubo_setstate_init(en, global);
	// data_80BA1C34
    //debug_message("(dungeon keep)(arg_data 0x%04x)", en->actor.variable);
}

static void play(entity *en, z64_global_t *global)
{
  z64_actorfunc_t *playfunc = en->playfunc;
  playfunc(en, global);
}

static void dest(entity *en, z64_global_t *global)
{
    actor_capsule_free(global, &en->capsule);
}

z64_actor_init_t init_vars =
{
	.number = 0xDEAD, .padding = 0xBEEF, // <-- magic values, do not change
	.type = Prop,
	.room = 0x00,
	.flags = 0x00800010,
	.object = OBJ,
	.instance_size = sizeof(entity),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = NULL
};
