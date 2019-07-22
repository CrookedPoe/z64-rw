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
#define OBJ          0x0170       /* object_kibako2         */
#define SFX          0x28AA       /* NA_SE_EV_WOODBOX_BREAK */
// Object Information
#define DL_CRATE     0x06000960   /* crate display list     */
#define DL_PLANK     0x06001000   /* plank display list     */
#define DYNAPOLY     0x06000B70   /* crate collision data   */

typedef struct {
	z64_actor_t     actor;
	z64_dynapoly_t  dynapoly;
	z64_capsule_t   capsule;
	z64_actorfunc_t *playfunc;
	uint32_t        drop_seed; // seed for item dropped; based on actor's Z rotation, later mixed with X rotation
} entity_t;

const z64_capsule_init_t capsule_data =
{
	.cso_0x00 = 0x0A,
	.cso_0x01 = 0x00,
	.cso_0x01_02 = 0x09,
	.unk_0x12 = 0x00,
	.unk_0x12_2 = 0x20,
	.cso_0x05 = 0x01,
	.cso_0x08 = 0x00,
	.cso_0x0C = 0x00000000,
	.damage_type = 0x00,
	.damage_amount = 0x00,
	.cso_0x14 = 0x40000040,
	.cso_0x18 = 0x00,
	.cso_0x19 = 0x00,
	.cso_0x1C = 0x01,
	.cso_0x1D = 0x00,
	.cso_0x1E = 0x00,
	.radius = 0x001F,
	.height = 0x0030,
	.cso_0x24 = 0x0000,
	.pos = {0, 0, 0}
};

const z64_dynapoly_init_t dynapoly_vars = {
	.unk_0 = {0xC8, 0x50},
	.scale = 100,
	.unk_1 = 0xB0F40BB8,
	.unk_2 = 0xB0F801F4,
	.unk_3 = 0x30FC03E8,
	.unk_4 = 0x00000000
};

/* Rewrite status: Complete */
// initializes collision capsule
static void collision_capsule_setup(entity_t *en, z64_global_t *gl)
{
    actor_capsule_alloc(gl, &en->capsule); /* Initialize Hitbox Capsule */
    actor_capsule_init(gl, &en->capsule, &en->actor, &capsule_data); /* Load Collision Array to Actor Instance */
    actor_capsule_update(&en->actor, &en->capsule); /* Update Hitbox Position */
}

/* Rewrite status: Still quite a bit to figure out... */
// spawns planks and dust
static void kibako2_spawn_planks(entity_t *en, z64_global_t *gl)
{

	int seed = 0; // random seed

	// spawn 16 planks
	for(int planks=0; planks < 16; ++planks) {
		float randf_result;
		randf_result = math_rand_zero_one() * 30.0f;

		vec3f_t unk0, unk1;

		unk0.x = (math_sins((seed << 0x10) >> 0x10) * randf_result);
		unk0.y = ((math_rand_zero_one() * 10.0f) + 2.0f);
		unk0.z = (math_coss((seed << 0x10) >> 0x10) * randf_result);

		unk1.x = (unk0.x * 0.2f);
		unk1.y = ((math_rand_zero_one() * 10.0f) + 2.0f);
		unk1.z = (unk0.z * 0.2f);

		unk0.x += en->actor.pos_2.x;
		unk0.y += en->actor.pos_2.y;
		unk0.z += en->actor.pos_2.z;

		// randomized rotation speed
		randf_result = math_rand_zero_one();
		s16 rspeed;
		if (randf_result < 0.05f)
		{
			rspeed = 96;
		}
		else
		{
			rspeed = 32;
			if (randf_result < 0.7f)
			{
				rspeed = 64;
			}
		}

		// spawn plank particle
		effect_spawn_fragment(
			gl,
			&unk0, &unk1, &unk0,
			-200, rspeed, 28, // likely rotation
			2,
			0,
			((math_rand_zero_one() * 30.0f) + 5.0f), // scale
			0,
			0,
			0x46,
			-1,
			OBJ,
			DL_PLANK
		);
		seed = ((seed + 0x4E20) << 0x10) >> 0x10;
	}
	// spawn dust particle effect
    external_func_80033480(gl, &en->actor.pos_2, 90.0f, 6, 0x64, 0xA0, 1);
}

/* Rewrite status: Complete */
// spawns a collectible, based on the actor's XZ rotation
// TODO: This funtion's return value is not used; does it really return something?
static int kibako2_spawn_collectible(entity_t *en, z64_global_t *gl)
{
    int out;

    out = en->actor.rot_init.x;
    if (en->actor.rot_init.x >= 0)
    {
        out = en->actor.rot_init.x;
        if (en->actor.rot_init.x < 0x1A)
        {
			// TODO : Does this function really have a return value?
            /*out = */item_drop_collectible(
				gl, &en->actor.pos_2,
				((en->actor.rot_init.x | (en->drop_seed << 8)) << 0x10) >> 0x10
			);
        }
    }
    return out;
}

/* Rewrite status: Complete */
static void kibako2_playfunc_goldskulltula(entity_t *en, z64_global_t *gl)
{
    if ((en->actor.variable & 0x8000) == 0) /* Spawn Gold Skulltula */
    {
        actor_spawn((void *)AS_A0, gl, 0x0095, en->actor.pos_2.x, en->actor.pos_2.y, en->actor.pos_2.z, 0, en->actor.rot_2.y, 0, (en->actor.variable | 0x8000));
    }
    kibako2_spawn_collectible(en, gl);
    actor_kill(&en->actor);
}

/* Rewrite status: Figure out what en->0x0175 is supposed to be. */
// I'm pretty sure that would be en->capsule[0x21], which happens to
// translate to (en->capsule.cso_0x14>>16)&0xFF at this time.
// It may be time to start breaking cso_0x14 up into a bitfield, or named array
static void kibako2_playfunc_default(entity_t *en, z64_global_t *gl)
{
    if  (	( (en->capsule.cso_0x14 >> 16) & 2)
			|| en->actor.rot_init.z
			|| external_func_80033684(gl, &en->actor)
		)
    {
        kibako2_spawn_planks(en, gl);
        sound_play_position(gl, &en->actor.pos_2, 0x14, SFX);
        en->actor.flags = (en->actor.flags | 0x10);
        external_func_8003EBF8(gl, AADDR(gl, 0x0810), en->dynapoly.id); /* Dynapoly Collision Related */
        en->actor.draw_proc = 0;
        en->playfunc = (z64_actorfunc_t*)kibako2_playfunc_goldskulltula;
        return;
    }
    if (en->actor.dist_from_link_xz < 600.0f)
    {
        actor_collision_check_set_ac(gl, AADDR(gl, 0x011E60), &en->capsule); /* Subscribe to Collision Pool AC */
    }
}

/* Rewrite status: Complete */
static void init(entity_t *en, z64_global_t *gl)
{
    uint32_t dynapoly_pointer = 0;
    actor_dynapoly_set_move(&en->actor, 0);
    actor_init_dynapoly(&en->actor, &dynapoly_vars);
    collision_capsule_setup(en, gl);
    dynapoly_alloc(DYNAPOLY, &dynapoly_pointer);
    en->actor.rot_2.x = 0;
    en->drop_seed = (int16_t)(en->actor.rot_init.z & 0x3F);
    en->dynapoly.id = actor_register_dynapoly(gl, AADDR(gl, 0x0810), &en->actor, dynapoly_pointer);
    en->playfunc = (z64_actorfunc_t*)kibako2_playfunc_default;
    en->actor.unk30 = en->actor.rot_2.x;
    en->actor.rot_2.z = en->actor.rot_2.x;
    en->actor.unk34 = en->actor.rot_2.x;
    en->actor.rot_init.z = en->actor.rot_2.x;
    //char data_80B96010[] = "ÚÈ¢(¿øÃÖ)(arg %04xH)(item %04xH %d)";
    //external_func_80002130(&data_80B96010, en->actor.variable, en->drop_seed, en->actor.rot_init.x); /* Debugging Function */
}

/* Rewrite status: Complete */
static void dest(entity_t *en, z64_global_t *gl)
{
    actor_capsule_free(gl, &en->capsule); /* Kill Capsule Hitbox */
    dynapoly_free(gl, AADDR(gl, 0x0810), &en->dynapoly.id);
}

/* Rewrite status: Can we even execute a function like this? */
static void play(entity_t *en, z64_global_t *gl)
{
	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, gl);
}

/* Rewrite status: Complete */
static void draw(entity_t *en, z64_global_t *gl)
{
    draw_static_dlist_opa(gl, DL_CRATE);
}

z64_actor_init_t init_vars =
{
	.number = 0xDEAD, .padding = 0xBEEF, // <-- magic values, do not change
	.type = Bg,
	.room = 0x00,
	.flags = 0x00000000,
	.object = OBJ,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
