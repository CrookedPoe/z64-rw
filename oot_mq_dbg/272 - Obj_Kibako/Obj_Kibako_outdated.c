/**
 * kibako.c
 *
 * A faithful rewrite of the small liftable,
 * breakable, switch-activating crate from OoT.
 *
 * by CrookedPoe and Dr.Disco
 *
 * variable structure
 * TODO
 **/

#include <stdint.h>
#include "../../z64ovl/oot/debug.h"

// Actor Information
#define OBJ          0x0003       /* gameplay_dangeon_keep */
#define SFX_BREAK    0x28AA       /* NA_SE_EV_WOODBOX_BREAK */
#define SFX_PICKUP   0x0878       /* NA_SE_PL_PULL_UP_WOODBOX */
#define SFX_SETDOWN  0x28AB       /* NA_SE_EV_PUT_DOWN_WOODBOX */
#define SFX_RADIUS   0x14
#define NUMPLANKS    12           /* number of planks to spawn when destroyed */

// uncomment to use dynapoly function for scale:
// (actor will be 16 bytes larger; may excise the dynapoly
// stuff completely once we confirm it serves no other purposes...)
//#define DPSCALE

// Object Information
#define DL_CRATE     0x05005290
#define DL_PLANK     0x05005380   /* plank display list     */

typedef struct {
	z64_actor_t      actor;
	z64_dynapoly_t   dynapoly;
	z64_capsule_t    capsule;
	z64_actorfunc_t* playfunc;
} entity;

// particle function IDs
enum particle {
	PARTICLE_BREAK = 0,
	PARTICLE_BREAK_WATER
};

// TODO: map out these bits...
uint32_t data_80B9587C[] = {0x0000000C, 0x003CFE00};

// play state prototypes
static void kibako_playfunc_thrown  (entity *en, z64_global_t *global);
static void kibako_playfunc_carry   (entity *en, z64_global_t *global);
static void kibako_playfunc_default (entity *en, z64_global_t *global);

z64_capsule_init_t capsule_data =
{
	.cso_0x00 = 0x0A,
	.cso_0x01 = 0x09,
	.cso_0x01_02 = 0x09,
	.unk_0x12 = 0x39,
	.unk_0x12_2 = 0x20,
	.cso_0x05 = 0x01,
	.cso_0x08 = 0x00,
	.cso_0x0C = 0x00000002,
	.damage_type = 0x00,
	.damage_amount = 0x01,
	.cso_0x14 = 0x4FC00748,
	.cso_0x18 = 0x00,
	.cso_0x19 = 0x00,
	.cso_0x1C = 0x01,
	.cso_0x1D = 0x01,
	.cso_0x1E = 0x01,
	.radius = 0x000C,
	.height = 0x001B,
	.cso_0x24 = 0x0005,
	.pos = {0, 0, 0}
};

#ifdef DPSCALE
z64_dynapoly_init_t dynapoly_vars = {
	.unk_0 = {0xC8, 0x50},
	.scale = 100,
	.unk_1 = 0xB0F403E8,
	.unk_2 = 0xB0F8003C,
	.unk_3 = 0x30FC03E8,
	.unk_4 = 0x00000000
};
#endif

/* ****************************************************************** */

// physics: update Y speed / velocity
static void kibako_physics_update_y_vel(entity *en, z64_global_t *global)
{
    en->actor.vel_1.y += en->actor.gravity;

    if (en->actor.vel_1.y < en->actor.min_vel_y)
    {
        en->actor.vel_1.y = en->actor.min_vel_y;
    }
}

/* ****************************************************************** */

// particles: spawn planks and dust on break
static void kibako_particle_planks(entity *en, z64_global_t *global)
{
    int seed = 0;

	for(int plank=0; plank < NUMPLANKS; ++plank) {

		vec3f_t unk0, unk1;

		unk0.x = (f32) (math_sins((s32) (seed << 0x10) >> 0x10) * 16.0f);
		unk0.y = (math_rand_zero_one() * 5.0f) + 2.0f;
		unk0.z = math_coss((s32) (seed << 0x10) >> 0x10) * 16.0f;

		unk1.x = unk0.x * 0.2f;
		unk1.y = (math_rand_zero_one() * 6.0f) + 2.0f;
		unk1.z = unk0.z * 0.2f;

		unk0.x += en->actor.pos_2.x;
		unk0.z += en->actor.pos_2.z;
		unk0.y += en->actor.pos_2.y;

		float temp_ret = math_rand_zero_one();

		short unk_s16;
		if (temp_ret < 0.1f)
		{
			unk_s16 = 0x60;
		}
		else
		{
			unk_s16 = 0x20;
			if (temp_ret < 0.7f)
			{
				unk_s16 = 0x40;
			}
		}
		effect_spawn_fragment(
			global,
			&unk0, &unk1, &en->actor.pos_2,
			-200, unk_s16,
			10, 10,
			0,
			(math_rand_zero_one() * 30.0f) + 10,
			0,
			32,
			60,
			-1,
			OBJ,
			DL_PLANK
		);
		seed = ((seed + 0x4e20) << 0x10) >> 0x10;
	}

	// spawn dust or something...
    external_func_80033480(
		global,
		&en->actor.pos_2,
		40.0f/*0x42200000*/,
		3, 0x32, 0x8c, 1
	);
}

// particles: plank particles spawn a little differently when the box is dropped in water,
//            and no dust is spawned
static void kibako_particle_planks_water(entity *en, z64_global_t *global)
{

	// prepare splash effect coordinates
	vec3f_t pos = en->actor.pos_2;
	pos.y += en->actor.water_surface_dist;

	// spawn a small splash effect
    effect_spawn_water_splash(
		global, &pos,
		0, 0, 0, 0x1f4
	);

    int seed = 0; // seed, used for randomization
	for(int plank=0; plank < NUMPLANKS; ++plank) {

		vec3f_t unk1;

		pos.x = (f32) (math_sins((s32) (seed << 0x10) >> 0x10) * 16.0f);
		pos.y = (math_rand_zero_one() * 5.0f) + 2.0f;
		pos.z = math_coss((s32) (seed << 0x10) >> 0x10) * 16.0f;

		unk1.x = pos.x * 0.18f;
		unk1.y = (math_rand_zero_one() * 4.0f) + 2.0f;
		unk1.z = pos.z * 0.18f;

		pos.x += en->actor.pos_2.x;
		pos.z += en->actor.pos_2.z;
		pos.y += en->actor.pos_2.y;

		s16 phi_s0 = 0x20;
		if (math_rand_zero_one() < 0.2f)
		{
			phi_s0 = 0x40;
		}

		// spawn plank particle
		effect_spawn_fragment(
			global,
			&pos, &unk1, &en->actor.pos_2,
			-0xb4, phi_s0, 0x1e,
			0x1e,
			0,
			((math_rand_zero_one() * 30.0f) + 10.0f),
			0,
			0x20,
			0x46,
			-1,
			OBJ,
			DL_PLANK
		);
		seed = ((seed + 0x4e20) << 0x10) >> 0x10;

	}
}

/* ****************************************************************** */

// destroy the box (spawns effects, plays sounds, and kills the actor)
static int kibako_destroy(entity *en, z64_global_t *global, const enum particle particle_func)
{
	switch(particle_func) {
		case PARTICLE_BREAK:
			kibako_particle_planks(en, global);
			break;
		case PARTICLE_BREAK_WATER:
			kibako_particle_planks_water(en, global);
			break;
	}

	sound_play_position(global, &en->actor.pos_2, SFX_RADIUS, SFX_BREAK);

	int v0 = (((en->actor.variable & 0x1F) << 0x10) >> 0x10);

	if (v0 >= 0)
	{
		if (v0 < 0x1A)
		{
			// TODO: Doesn't this function have no return value?
			/*phi_return = */item_drop_collectible(
				global, &en->actor.pos_2,
				((v0 | (((en->actor.variable >> 8) & 0x3F) << 8)) << 0x10) >> 0x10
				//,en->actor // this function only has 3 args; is this excess necessary?
			); /* This doesn't seem right...*/
		}
	}

	actor_kill(&en->actor);
}

// initialize collision
static void kibako_init_collision(entity *en, z64_global_t *global)
{
	/* Initialize Hitbox Capsule */
	actor_capsule_alloc(global, &en->capsule);

	/* Load Collision Array to Actor Instance */
	actor_capsule_init(global, &en->capsule, &en->actor, &capsule_data);

	/* Update Hitbox Position */
	actor_capsule_update(&en->actor, &en->capsule);
}

/* ****************************************************************** */

// set state: thrown
static void kibako_setstate_thrown(entity *en, z64_global_t *global)
{
	// set XZ speed / velocity and mass
    en->actor.vel_1.x = math_sins(en->actor.xz_dir) * en->actor.xz_speed;
    en->actor.vel_1.z = math_coss(en->actor.xz_dir) * en->actor.xz_speed;
    en->actor.mass = 0xF0;

	// set the play function
    en->playfunc = (z64_actorfunc_t*) kibako_playfunc_thrown;
}

// set state: Link begins carrying the box
static void kibako_setstate_carry(entity *en, z64_global_t *global)
{
    en->playfunc = (z64_actorfunc_t*) kibako_playfunc_carry;
    en->actor.room_index = 0xFF;
    sound_play_actor(&en->actor, SFX_PICKUP);
}

// set state: default
static void kibako_setstate_default(entity *en, z64_global_t *global)
{
	en->playfunc = (z64_actorfunc_t*) kibako_playfunc_default;
	en->actor.mass = 0xFE;
}

/* ****************************************************************** */

// play state: thrown
static void kibako_playfunc_thrown(entity *en, z64_global_t *global)
{
    if  (	(en->actor.bgcheck_flags & 0xB)
			|| (en->capsule.cso_0x01 & 2)
			|| (en->actor.bgcheck_flags & 0x40)
		)
    {
        kibako_destroy(en, global, PARTICLE_BREAK);
        return;
    }

	// update physics (y velocity) and actor location
    kibako_physics_update_y_vel(en, global);
    actor_update_pos(&en->actor);

	/* Maybe used for shadow? */
    external_func_8002E4B4(global, &en->actor, 19.0f, 20.0f, 0.0f, 5);

	/* Update Hitbox Position */
    actor_capsule_update(&en->actor, &en->capsule);

	/* Subscribe to Collision Pool OT */
    actor_collision_check_set_ot(global, &global->sbc_group_at_1, &en->capsule);

	/* Subscribe to Collision Pool AT */
    actor_collision_check_set_at(global, &global->sbc_group_at_1, &en->capsule);
}

// play state: being carried by Link
static void kibako_playfunc_carry(entity *en, z64_global_t *global)
{
	// TODO: document external_func_8002F5A0(); does it really require no arguments?
    if (external_func_8002F5A0() != 0)
    {
		//(0x10000 + global)->unk1CBC; // Some kind of room index thing:
        en->actor.room_index = AVAL(global, char, 0x11CBC);

		// crate is being placed down carefully
        if (en->actor.xz_speed < 0.1f)
        {
            sound_play_actor2(&en->actor, SFX_SETDOWN);
            kibako_setstate_default(en, global);
			// TODO: document this bitfield, why is it doing this?
            en->capsule.unk_0x12 = (en->capsule.unk_0x12 & 0xfff7);
        }
        else // crate has been thrown
        {
            kibako_setstate_thrown(en, global);
            kibako_physics_update_y_vel(en, global);
            actor_update_pos(&en->actor);
        }

		/* TODO: Maybe used for shadow? */
        external_func_8002E4B4(global, &en->actor, 19.0f, 20.0f, 0.0f, 5);
    }
}

// play state: default
static void kibako_playfunc_default(entity *en, z64_global_t *global)
{

	if ( actor_is_held(&en->actor) )
	{
		kibako_setstate_carry(en, global);
		return;
	}

	if ( en->actor.bgcheck_flags & 0x20 )
	{
		if (19.0f < en->actor.water_surface_dist)
		{
			kibako_destroy(en, global, PARTICLE_BREAK_WATER);
			return;
		}
	}

	// TODO : This needs a name OR the bitfield needs documented...
	if ( en->capsule.cso_0x01 & 2 )
	{
		kibako_destroy(en, global, PARTICLE_BREAK);
		return;
	}
	external_func_8002D8E0(&en->actor); /* Move in Direction (0x32) at set velocity (0x68) */
	external_func_8002E4B4(global, &en->actor, 19.0f, 20.0f, 0.0f, 5); /* Maybe used for shadow? */
	if ( (en->capsule.unk_0x12 & 8) == 0)
	{
		if (28.0f < en->actor.dist_from_link_xz)
		{
			en->capsule.unk_0x12 = (en->capsule.unk_0x12 | 8);
		}
	}
	if ( en->actor.dist_from_link_xz < 600.0f )
	{
		actor_capsule_update(&en->actor, &en->capsule);
		/* Subscribe to Collision Pool AC */
		actor_collision_check_set_ac(global, &global->sbc_group_at_1, &en->capsule);
		if ( en->actor.dist_from_link_xz < 180.0f )
		{	/* Subscribe to Collision Pool OT */
			actor_collision_check_set_ot(global, &global->sbc_group_at_1, &en->capsule);
		}
	}
	if ( en->actor.dist_from_link_xz < 100.0f )
	{
		// TODO: Are you sure this function has a return value?
		// from z64_functions.h: Give Item Wrapper (80022CF4) | Sets A2 to 0;
		// no a2, would this be a pointer to a u32 or something? Please investigate.
		/*phi_return = */actor_give_item_gid0(&en->actor, global); /* Give Item Wrapper */
	}
}

/* ****************************************************************** */

static void init(entity *en, z64_global_t *global)
{
#ifdef DPSCALE
	actor_init_dynapoly(&en->actor, &dynapoly_vars);
#else
	actor_set_scale(&en->actor, 0.1f);
#endif
	en->actor.gravity = -1.2f;
	en->actor.min_vel_y = -13.0f;

	/* Initalize Collision Capsule */
	kibako_init_collision(en, global);

	/* Initialize Damage Table */
	external_func_80061ED4(&en->actor.damage_table, NULL, data_80B9587C);

	// Set default state
	kibako_setstate_default(en, global);

	//Debugging Function
	/*char data_80B958A0[] = "(dungeon keep \000ÚÈ¢)(arg_data 0x%04x)";
	external_func_80002130(&data_80B958A0, en->actor.variable);*/

}

static void dest(entity *en, z64_global_t *global)
{
	actor_capsule_free(global, &en->capsule);
}

static void play(entity *en, z64_global_t *global)
{
	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, global);
}

static void draw(entity *en, z64_global_t *global)
{
	draw_static_dlist(global, DL_CRATE);
}

z64_actor_init_t init_vars =
{
	.number = 0xDEAD, .padding = 0xBEEF, // <-- magic values, do not change
	.type = Prop,
	.room = 0x00,
	.flags = 0x04000010,
	.object = OBJ,
	.instance_size = sizeof(entity),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
