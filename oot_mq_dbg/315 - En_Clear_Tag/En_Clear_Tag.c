/**
 * z_en_clear_tag.c
 *
 * A faithful rewrite of the Arwing from OoT.
 *
 * by Dr.Disco
 *
 * variable structure
 *  0000 - Plays cutscene
 *  0064 - Laser
 **/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include "zobj.h" /* embedded geometry & textures */

#define OBJ_ID 1
#define ARWING_HEALTH   1  // TODO normally 3, but 1 makes testing easier

// TODO
// improve readability
// finish documenting structures
// name unnamed external functions
// eliminate gotos
// more comments to explain what does what

// possibly TODO: SRD+1
// prim.a fades to 0 and the particle knows it's finished once it reaches 0.
// consider making the smoke particle gradually fade out instead of just
// disappearing. If this is implemented, make it toggle-able via a SRD_PLUS_1
// macro

enum arwing_draw_mode
{
	  DRAW_MODELS_ONLY     = 0
	, DRAW_BOTH            = 1
	, DRAW_PARTICLES_ONLY  = 2
};

enum arwing_particle_type
{
	  PARTICLE_AVAILABLE  = 0
	, PARTICLE_DEBRIS     = 1
	, PARTICLE_FIRE       = 2
	, PARTICLE_SMOKE      = 3
	, PARTICLE_FLASH      = 4
};

#define GFX global->common.gfx_ctxt
#define GFX_POLY_OPA ZQDL( global, poly_opa )
#define GFX_POLY_XLU ZQDL( global, poly_xlu )

typedef struct {
	z64_actor_t actor;      /* 0x0000 */ /* length 0x13C */
	uint8_t unk13C[0x10];   /* 0x013C */ // unused, likely padding
	uint8_t                 /* 0x014C */
		  spawn_explosion   // is set when the Arwing falls and hits the ground
		, draw_mode         /* 0 = models only, 2 = particles only, 1 = both */
		, unk14E            /* seems to be a state based thing */
		, unk14F
	;
	int16_t
		  unk150[3]         /* 0x0150 */
	;
	uint8_t unk156[2];      /* 0x0156 */ // likely padding
	vec3f_t unk158, unk164; /* 0x0158 */
	vec3f_t unk170;         /* 0x0170 */ // physics related, acceleration/deceleration
	uint8_t unk17C, unk17D; /* 0x017C */
	uint8_t unk17E[2];      /* 0x017E */ // likely padding
	float unk180;           /* 0x0180 */
	int16_t unk184, unk186; /* 0x0184 */
	vec3f_t up;             /* 0x0188 */ /* "up" vector, so that the flash
	                                        particle can radiate across
	                                        surfaces of any angle: even walls! */
	z64_capsule_t capsule;  /* 0x0194 */ /* length 0x4C */
	uint8_t
		  cutscene_mode     /* 0x01E0 */
		, padding;
	uint16_t
		camera_id           /* 0x01E2 */
	;
	vec3f_t camera_lookat;  /* 0x01E4 */ // camera look-at
	vec3f_t camera_pos;     /* 0x01F0 */ // camera position
	uint16_t cutscene_time; /* 0x01FC */ // time remaining in cutscene
	uint8_t unk1FE[6];      /* 0x01FE */ // unused
} entity_t; /* 0x0204 bytes */


typedef struct arwing_particle {
	uint8_t
		  type     // 0 if not in use, particle ID otherwise
		, seed     // seed, randomized on spawn
		, pad0
		, pad1
	;
	vec3f_t
		  pos
		, vel
		, acc
	;
	rgbaf_t
		  prim     // primitive color
		, env      // environment color
	;
	int16_t
		  bounces  // number of times particle has bounced off ground
		, timer    // counts frames to expire (not used by all types)
	;
	float
		  scale    // scale
		, scale_b  // some particles gradually resize from scale to scale_b
	;
	vec3f_t
		  rot      // rotation of the particle (used only by debris)
		, up       // "up" vector, so that the flash particle can
	               // radiate across surfaces of any angle: even walls!
	               // TODO this may just be reclassified as rot_b
	;
} arwing_particle_t; /* 0x6C bytes */





/*** variables ***/
static uint8_t data_809DC3D0[10800]={0};
uint32_t data_809D5C30 = 0;

const z64_capsule_init_t arwing_body_capsule =
{
	0x03, 0x11, 0x09, 0x39,
	0x10, 0x01,

	0x00, 0x00, // PADDING

	0x00,

	0x00, 0x00, 0x00, // PADDING

	0xFFCFFFFF, /* 000C */
	0x00, 0x04,
	0x00, 0x00, // PADDING

	0xFFDFFFFF, /* 0014 */
	0x00, 0x00,
	0x00, 0x00, // PADDING

	0x01, 0x01, 0x01, 0x00/*pad*/, /* 001C */
	0x000F, 0x001E, /* 0020 */
	0x000A, /* 0024 */
	{ 0x0000, 0x0000, 0x0000 } /* 0026 */
}; /* 002C */

const z64_capsule_init_t arwing_laser_capsule =
{
	0x09, 0x11, 0x09, 0x39,
	0x10, 0x01,
	0x00, 0x00, // PADDING

	0x00,
	0x00, 0x00, 0x00, // PADDING

	0xFFCFFFFF, /* 000C */

	0x00, 0x04,
	0x00, 0x00, // PADDING

	0xFFDFFFFF, /* 0014 */
	0x00, 0x00,
	0x00, 0x00, // PADDING

	0x01, 0x01, 0x01, 00/*pad*/, /* 001C */
	0x000F, 0x001E, /* 0020 */

	0x000A, /* 0024 */
	{ 0x0000, 0x0000, 0x0000 }
#if 0
	// TODO this has extra stuff at the end, why?
	,
	0x00000000,
	0x00000000
#endif
};

const char source_name[] = "../z_en_clear_tag.c";




/*** functions ***/

static arwing_particle_t *arwing_particle_new(z64_global_t *global)
{
	// TODO can't use global->situdata directly for some reason...
	arwing_particle_t *st = (arwing_particle_t*)AVAL(global,u32,0x11E10);
	for( int i=0; i < 100; ++i, ++st )
	{
		if( ! st->type )
			return st;
	}
	return NULL;
}

// spawns a radial flash effect across the ground where the Arwing collides
// "up" vector, so that the flash particle can
// radiate across surfaces of any angle: even walls!
static void arwing_spawn_particle_flash(z64_global_t *global, vec3f_t *pos, float scale, float floor_height, vec3f_t *up) /* 0 internal, 0 external, 56 lines */
{

	arwing_particle_t *st = arwing_particle_new(global);

	if( ! st )
		return;

	st->type = PARTICLE_FLASH;

	st->pos = *pos;
	st->vel = (vec3f_t){0};
	st->acc = (vec3f_t){0};

	st->prim.a = 180.0f;

	// starts out infinitely small, then grows to the size specified
	st->scale = 0.0f;
	st->scale_b = scale + scale;

	// radial flash particle has two parts at different heights, so for this
	// rot.y fills in as pos.y for one of those parts
	st->rot.y = floor_height;

	st->up = *up;
}
void destroy(entity_t *en, z64_global_t *global) /* 0 internal, 1 external, 10 lines */
{
	actor_capsule_free( global, &en->capsule );
}

void arwing_calculate_up_vector(entity_t *en) /* 0 internal, 1 external, 47 lines */
{
	z64_actor_t *actor = &en->actor;
	float x;
	float y;

	z64_col_poly_t *floor_poly = actor->floor_poly;
	if( !floor_poly )
		return;

	// TODO explain the purpose of this number
	const float data_809DC0E8 = 0.0000305185f;

	x = data_809DC0E8 * floor_poly->norm.x;
	y = data_809DC0E8 * floor_poly->norm.y;
	en->up.x = -external_func_800FD250( -( data_809DC0E8 * floor_poly->norm.z ) * y, 1.0f );
	en->up.z =  external_func_800FD250( -x * y, 1.0f );
}

// fire particles used by Arwing when it's falling to the ground
// also used by debris
void arwing_spawn_particle_fire(z64_global_t *global, vec3f_t *pos, float scale) /* 0 internal, 1 external, 63 lines */
{


	arwing_particle_t *st = arwing_particle_new(global);

	if( ! st )
		return;

	st->type = PARTICLE_FIRE;
	st->seed = math_rand_f32(100);

	st->pos = *pos;

	st->vel = (vec3f_t){0};

	st->acc = (vec3f_t){0, 0.15f ,0 };

	st->prim.a = 200.0f;
	st->scale = scale;
}

// spawns a piece of debris
void arwing_spawn_particle_debris(z64_global_t *global, vec3f_t *pos, vec3f_t *vel, vec3f_t *acc, float scale) /* 0 internal, 1 external, 65 lines */
{
	arwing_particle_t *st = arwing_particle_new(global);

	if( ! st )
		return;

	st->type = PARTICLE_DEBRIS;
	st->seed = math_rand_f32(10);

	st->pos = *pos;

	st->vel = *vel;

	st->acc = *acc;

	st->bounces = 0;
	st->timer = 0;
	st->scale = scale;

	st->rot = (vec3f_t) {
		math_rand_f32( 6.2831854820f ),
		math_rand_f32( 6.2831854820f )
	};
}

// spawns a big smoke cloud that's left behind where the Arwing exploded
void arwing_spawn_particle_smoke(z64_global_t *global, vec3f_t *pos, float scale) /* 0 internal, 1 external, 76 lines */
{

	arwing_particle_t *st = arwing_particle_new(global);

	if( ! st )
		return;

	st->type = PARTICLE_SMOKE;
	st->seed = math_rand_f32(100.0f);

	st->pos = *pos;
	st->vel = (vec3f_t){0};
	st->acc = (vec3f_t){0};

	st->prim = (rgbaf_t) { 200.0f, 20.0f, 0.0f, 255.0f };
	st->env = (rgbaf_t) { 255.0f, 215.0f, 255.0f };

	st->scale = scale;
	st->scale_b = scale + scale;
}
static void init(entity_t *en, z64_global_t *global) /* 0 internal, 5 external, 119 lines */
{
	z64_actor_t *actor = &en->actor;

	actor_capsule_alloc(global, &en->capsule );

	// this is the laser it fires; it spawns lasers
	if( actor->variable == 0x0064 )
	{
		// is laser
		en->unk14E = (u8)0x64;
		// TODO what are these?
		en->unk150[0] = (u16)0x46;
		actor->xz_speed = 35.0f;
		external_func_8002D908(actor); /* mips_to_c had (actor,actor) as arguments */

		actor_update_pos(actor);

		actor->rot_2.x = (s16) (0 - actor->rot_2.x);
		actor->scale.x = 0.4000000060f;
		actor->scale.y = 0.4000000060f;
		actor->scale.z = 2.0f;
		actor->xz_speed = 70.0f;
		external_func_8002D908(actor);
		actor_capsule_init(global, &en->capsule, actor, &arwing_laser_capsule);
		sound_play_actor2(actor, 0x182a);

		// notice draw_mode remains unset here and therefore zero-initialized
		// thus, draw_mode is DRAW_MODELS_ONLY by default
		// this is an optimization so that the lasers don't waste CPU cyles
		// looping through the particle drawing routine
		return;
	}
	// TODO find out what unk1F is
	actor->unk1F = (u8)5;
	actor->flags |= 1;
	actor_capsule_init(global, &en->capsule, actor, &arwing_body_capsule);
	actor->health = ARWING_HEALTH;

	// initialize the cutscene
	if (actor->variable == 0 )
	{
		// is cutscene Arwing
		en->unk14E = (u8)2;
		// TODO document this stuff and explain what it does
		actor->unk30 = (u16)0x4000;
		en->unk150[0] = (u16)0x46;
		en->unk150[1] = (u16)0xfa;
		en->unk150[2] = (u16)0x14;
		en->cutscene_mode = 1;
		en->cutscene_time = 100;
	}

	// TODO possibly a global variable shared between Arwing instances, look into it
	// Either way, it overrides global->situdata
	// TODO see what global->situdata looks like when the Arwing isn't loaded
	//      I have a hunch global->situdata was added specifically for the Arwing...
	if (data_809D5C30 == 0)
	{
		// now that global->situdata has been overridden, don't
		// override it on the next Arwing we spawn
		data_809D5C30 = (u8)1;

		// TODO setting global->situdata directly simply doesn't work;
		//      writing the bytes manually will do in the meantime
		uint8_t *ok = AADDR(global,0x11E10);
		uint32_t yeah = (uint32_t)(data_809DC3D0 + 0x290);
		ok[0] = (yeah>>24);
		ok[1] = (yeah>>16)&0xFF;
		ok[2] = (yeah>>8)&0xFF;
		ok[3] = yeah&0xFF;

		// zero-initialize the ID element of each particle
		// TODO get rid of the AVAL stuff
		arwing_particle_t *st = (arwing_particle_t*)AVAL(global,u32,0x11E10);
		int i;
		for( i = 0; i < 100; ++i, ++st )
			st->type = 0;

		// draw_mode will be set to draw both models and particles, but only
		// for one Arwing; this is to avoid needlessly looping through the
		// particle drawing routines for every Arwing and causing lag
		en->draw_mode = DRAW_BOTH;
	}
}

// is used for rendering the particle effects
void arwing_draw_particles(z64_global_t *global) /* 0 internal, 12 external, 544 lines */
{

	// TODO unknown...
	uint32_t spE8;


	// TODO AVAL works fine here, but accessing situdata directly doesn't
	arwing_particle_t *g11E10 = (arwing_particle_t*)AVAL(global,u32,0x11E10);
	arwing_particle_t *st;
	int iter, k;

	external_func_800C6AC4(&spE8, GFX, source_name, __LINE__); // originally line 1288

	external_func_80093D18( GFX );
	external_func_80093D84( GFX );

	z64_disp_buf_t *opa = & GFX_POLY_OPA;
	z64_disp_buf_t *xlu = & GFX_POLY_XLU;

	for( st=g11E10, k=0, iter=0; iter < 100; ++iter, ++st )
	{
		if( st->type == PARTICLE_DEBRIS )
		{
			// prepend material for first element
			if( k == 0 )
			{
				gSPDisplayList(opa->p++, data_809D9FE8);

				k = 1;
			}
			matrix_translate3f(st->pos.x, st->pos.y, st->pos.z, 0);
			float scale = st->scale;
			matrix_scale3f(scale, scale, scale, 1);
			external_func_800D0D20(st->rot.x, 1);
			external_func_800D0B70(st->rot.y, 1);

			gSPMatrix(
				opa->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1307
				G_MTX_LOAD
			);
			gSPDisplayList(opa->p++, data_809DA068);
		}
	}

	for( k=0, st=g11E10, iter=0; iter < 100; ++iter, ++st )
	{
		// this is the circle that radiates outwards along the ground when
		// the Arwing explodes
		if( st->type == PARTICLE_FLASH )
		{
			// prepend material for first element
			if( k == 0 )
			{
				gDPPipeSync( xlu->p++ );

				gDPSetEnvColor( xlu->p++, 0xFF, 0xFF, 0xC8, 0x00 );

				k = 1;
			}

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				0xFF, 0xFF, 0xC8, st->prim.a
			);


			matrix_translate3f(st->pos.x, st->rot.y, st->pos.z, 0);
			external_func_800D0B70(st->up.x, 1);
			external_func_800D0ED4(st->up.y, 1);

			float xz_scale = st->scale + st->scale;
			matrix_scale3f(xz_scale, 1.0f, xz_scale, 1);

			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1342
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809DBA68);
		}
	}

	for( k=0, st=g11E10, iter=0; iter < 100; ++iter, ++st )
	{
		if( st->type == PARTICLE_SMOKE )
		{
			// prepend material for first element
			if( k == 0 )
			{
				gSPDisplayList(xlu->p++, data_809DA6B0);

				k = 1;
			}

			gDPPipeSync( xlu->p++ );

			gDPSetEnvColor( xlu->p++, (s32) st->env.r, (s32) st->env.g, (s32) st->env.b, 0x80 );

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				(s32) st->prim.r, (s32) st->prim.g, (s32) st->prim.b, (s32) st->prim.a
			);

			// apply texture scrolling to ram segment 08
			gMoveWd(
				xlu->p++,
				G_MW_SEGMENT,
				G_MWO_SEGMENT_8,
				f3dzex_gen_settilesize(
					GFX, 0, 0, (0 - st->seed) * 5, 0x20, 0x40, 1, 0, 0, 0x20, 0x20
				)
			);

			matrix_translate3f(st->pos.x, st->pos.y, st->pos.z, 0);
			external_func_800D1FD4( AADDR(global,0x11da0) );

			float xy_scale = st->scale;
			matrix_scale3f(xy_scale, xy_scale, 1.0f, 1);
			matrix_translate3f(0, 20.0f, 0, 1);

			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1392
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809DA758);
		}
	}

	for( k=0, st=g11E10, iter=0; iter < 100; ++iter, ++st )
	{
		if( st->type == PARTICLE_FIRE )
		{
			// prepend material for first element
			if( k == 0 )
			{
				gSPDisplayList(xlu->p++, data_809DA6B0);

				gDPSetEnvColor( xlu->p++, 0xFF, 0xD7, 0xFF, 0x80 );

				k = 1;
			}

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				0xC8, 0x14, 0x00, (s32) st->prim.a
			);


			// apply texture scrolling to ram segment 08
			gMoveWd(
				xlu->p++,
				G_MW_SEGMENT,
				G_MWO_SEGMENT_8,
				f3dzex_gen_settilesize(
					GFX, 0, 0, ((0 - st->seed) * 0xf) & 0xff, 0x20, 0x40, 1, 0, 0, 0x20, 0x20
				)
			);

			matrix_translate3f(st->pos.x, st->pos.y, st->pos.z, 0);
			external_func_800D1FD4( AADDR(global,0x11da0) );

			float xy_scale = st->scale;
			matrix_scale3f(xy_scale, xy_scale, 1.0f, 1);

			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1439
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809DA758);
		}
	}

	for( k=0, st=g11E10, iter=0; iter < 100; ++iter, ++st )
	{
		if( st->type == PARTICLE_FLASH )
		{
			// prepend material for first element
			if( k == 0 )
			{
				gDPPipeSync( xlu->p++ );

				gDPSetEnvColor( xlu->p++, 0xFF, 0xFF, 0xC8, 0x00 );

				k = 1;
			}

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				0xFF, 0xFF, 0xC8, st->prim.a
			);

			matrix_translate3f(st->pos.x, st->pos.y, st->pos.z, 0);
			external_func_800D1FD4( AADDR(global,0x11da0) );

			float xy_scale = st->scale;
			matrix_scale3f(xy_scale, xy_scale, 1.0f, 1);

			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1470
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809DB7B8);
		}
	}
	external_func_800C6B54(&spE8, GFX, source_name, __LINE__); // originally line 1477
}

// updates physics, positions, etc. of each particle
void arwing_particle_physics(z64_global_t *global) /* 1 internal, 4 external, 256 lines */
{

	arwing_particle_t *st = (arwing_particle_t*)AVAL(global,u32,0x11E10);
	int iter;
	for( iter=0; iter < 100; ++iter, ++st )
	{
		if( ! st->type )
			continue;

		#if 0
		float temp_f12 = st->unk14;
		float temp_f14 = st->unk4 + st->unk10;
		#endif
		st->seed += 1;

		// update position based on velocity
		VEC3_ADD( st->pos, st->vel );

		// gravity and other acceleration factors influence velocity
		VEC3_ADD( st->vel, st->acc );

		switch( st->type )
		{
			case PARTICLE_DEBRIS:
				if (st->vel.y < -5.0f)
				{
					st->vel.y = -5.0f;
				}
				if (st->vel.y < 0.0f)
				{
				#if 0
					float sp74 = st->unk8;
					float sp6C = (f32) (sp6C + 5.0f);
				#endif
					vec3f_t sp68 = { st->pos.x, st->pos.y, st->pos.z };
					// TODO AADDR is ugly, but I can't get &global->col_ctxt to work
					// mips_to_c erroneously made temp_f12 and temp_f14 the a0 and a1 here...
					if( collision_sphere_test( AADDR(global,0x7C0), &sp68, 11.0f ) )
					{
						// bounce once off the ground
						if (st->bounces <= 0)
						{
							st->bounces += 1;
							// randomize number of frames until expiration
							st->timer = math_rand_f32(20.0f) + 0x19;
							// bounce half as high as before
							st->vel.y = st->vel.y * -0.5f;
						}
						// halt all motion; particle stays grounded
						else
						{
							st->vel = (vec3f_t){0};
							st->acc.y = 0.0f;
						}
					}
				}
				// as long as the debris particles are flying through
				// the air, make them spin!
				if (0.0f != st->acc.y)
				{
					st->rot.x += 0.5f;
					st->rot.y += 0.35f;
				}

				// timer expired, mark the slot it's occupying as available
				if (1 == st->timer)
				{
					st->type = 0;
				}
				if (st->seed >= 3)
				{
					st->seed = 0;
					arwing_spawn_particle_fire(global, &st->pos, st->scale * 8.0f);
				}
				else
				{
					st->timer -= 1;
				}
				break;
			case PARTICLE_FIRE:
				// mips_to_c erroneously made temp_f12 and temp_f14 the a0 and a1 here...
				external_func_8007848C( &st->prim.a, 1.0f, 15.0f);

				// effect faded out, mark the slot it's occupying as available
				if (st->prim.a <= 0.0f)
				{
					st->type = 0;
				}
				break;
			case PARTICLE_SMOKE:
				// mips_to_c erroneously made temp_f12 and temp_f14 the a0 and a1 here...
				external_func_8007848C( &st->prim.r, 1.0f, 20.0f);
				external_func_8007848C( &st->prim.g, 1.0f, 2.0f);
				external_func_8007848C( &st->env.r, 1.0f, 25.5f);
				external_func_8007848C( &st->env.g, 1.0f, 21.5f);
				external_func_8007848C( &st->env.b, 1.0f, 25.5f);

				external_func_8007841C( &st->scale, st->scale_b, 0.05f, 0.1f);
				if (0.0f == st->prim.r)
				{
					external_func_8007848C( &st->prim.a, 1.0f, 3.0f);
					// effect faded out, mark the slot it's occupying as available
					if (st->prim.a <= 0.0f)
					{
						st->type = 0;
					}
				}
				break;
			case PARTICLE_FLASH:
				// mips_to_c erroneously made temp_f12 and temp_f14 the a0 and a1 here...
				external_func_8007841C( &st->scale, st->scale_b, 1.0f, 3.0f);
				external_func_8007848C( &st->prim.a, 1.0f, 10.0f);
				// effect faded out, mark the slot it's occupying as available
				if (st->prim.a <= 0.0f)
				{
					st->type = 0;
				}
				break;
		}
	}
}
void draw(entity_t *en, z64_global_t *global) /* 1 internal, 12 external, 391 lines */
{
	int sp84;


	external_func_800C6AC4(&sp84, GFX, source_name, __LINE__); // originally line 983

	if( en->draw_mode != DRAW_PARTICLES_ONLY )
	{
		external_func_80093D84( GFX );

		// is laser
		if (en->unk14E >= 0x64)
		{
			z64_disp_buf_t *buf = & GFX_POLY_XLU;

			gDPSetPrimColor(
				buf->p++, 0, 0,
				0x00, 0xFF, 0x00, 0xFF
			);

			matrix_translate3f(25.0f, 0, 0, 1);


			gSPMatrix(
				buf->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1004
				G_MTX_LOAD
			);

			gSPDisplayList(buf->p++, data_809D9938);

			matrix_translate3f(-50.0f, 0, 0, 1);

			gSPMatrix(
				buf->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1011
				G_MTX_LOAD
			);

			gSPDisplayList(buf->p++, data_809D9938);
		}
		else
		{
			external_func_80093D18( GFX );

			z64_disp_buf_t *opa = & GFX_POLY_OPA;
			z64_disp_buf_t *xlu = & GFX_POLY_XLU;

			// layer OPA geometry

			gDPSetPrimColor(
				opa->p++, 0, 0,
				0xFF, 0xFF, 0xFF, 0xFF
			);

			// TODO readability, please
			if (en->unk184 != 0)
			{
				float sp60 = (f32) ((f32) en->unk184 * 0.05f);
				int32_t temp_at = en->unk17C;
				float sp68 = (f32) (math_sins((s32) (((en->unk17C * 4) - temp_at) * 0x10000000) >> 0x10) * sp60);
				int32_t temp_at_2 = en->unk17C;
				float sp64 = (f32) (math_sins((s32) (((((en->unk17C * 8) - temp_at_2) * 8) - temp_at_2) * 0x1000000) >> 0x10) * sp60);
				external_func_800D0B70(sp68, 1);
				external_func_800D0D20(sp64, 1);
			}
			external_func_800D0ED4(en->unk180, 1);


			gSPMatrix(
				opa->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1030
				G_MTX_LOAD
			);


			gSPDisplayList(opa->p++, data_809D5CA0);

			matrix_translate3f(0, 0, -60.0f, 1);

			external_func_800D1FD4( AADDR(global,0x11da0) );

			matrix_scale3f(2.5f, 1.30f, 0, 1);

			if ((en->unk17C & 1) != 0)
			{
				matrix_scale3f(1.15f, 1.15f, 1.15f, 1);
			}


			// layer XLU geometry

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				0xFF, 0xFF, 0xC8, 0x9B
				// -0x3765
			);

			gDPPipeSync( xlu->p++ );

			gDPSetEnvColor( xlu->p++, 0xFF, 0x32, 0x00, 0x00 );

			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1067
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809D9C38);

			gDPSetPrimColor(
				xlu->p++, 0, 0,
				0x00, 0x00, 0x00, 0x82
			);

			matrix_translate3f(en->actor.pos_2.x, en->actor.floor_height, en->actor.pos_2.z, 0);
			external_func_800D0B70(en->up.x, 1);
			external_func_800D0ED4(en->up.z, 1);

			matrix_scale3f(en->actor.scale.x + 0.35f, 0, en->actor.scale.z + 0.35f, 1);

			float pi = 3.141593f;
			external_func_800D0D20(((f32) en->actor.rot_2.y / 32768.0f) * pi, 1);
			external_func_800D0B70(((f32) en->actor.rot_2.x / 32768.0f) * pi, 1);
			external_func_800D0ED4(((f32) en->actor.rot_2.z / 32768.0f) * pi, 1);
			if (en->unk184 != 0)
			{
				float sp34 = (f32) ((f32) en->unk184 * 0.05f);
				int32_t temp_at_3 = en->unk17C;
				float sp3C = (f32) (math_sins((s32) (((en->unk17C * 4) - temp_at_3) * 0x10000000) >> 0x10) * sp34);
				int32_t temp_at_4 = en->unk17C;
				float sp38 = (f32) (math_sins((s32) (((((en->unk17C * 8) - temp_at_4) * 8) - temp_at_4) * 0x1000000) >> 0x10) * sp34);
				external_func_800D0B70(sp3C, 1);
				external_func_800D0D20(sp38, 1);
			}
			external_func_800D0ED4(en->unk180, 1);



			gSPMatrix(
				xlu->p++,
				matrix_alloc(GFX, source_name, __LINE__), // originally line 1104
				G_MTX_LOAD
			);

			gSPDisplayList(xlu->p++, data_809DBF20);
		}
	}
	if( en->draw_mode != DRAW_MODELS_ONLY )
	{
		arwing_draw_particles(global);
	}
	external_func_800C6B54(&sp84, GFX, source_name, __LINE__); // originally line 1119
}
void update(entity_t *en, z64_global_t *global) /* 6 internal, 32 external, 930 lines */
{

	// Link's actor
	z64_actor_t *player = & helper_get_player(global)->actor;//AADDR( global, 0x1C44 );//(void *) global->unk1C44;

	en->unk17C += 1;
	if (en->draw_mode != 2)
	{
		// decrease each of these until they are 0
		for( int i=0; i<3; ++i )
		{
			int16_t *t = &en->unk150[i];
			if( *t != 0 )
			{
				*t = (s16) ( *t - 1 );
			}
		}

		if (en->cutscene_time != 0)
		{
			en->cutscene_time -= 1;
		}

		int phi_at = 0;

		if (en->unk14E != 0)
		{
			if (en->unk14E != 1)
			{
				if (en->unk14E != 2)
				{
					if (en->unk14E != 0xa)
					{
						if (en->unk14E != 0x64)
						{
							phi_at = en->unk14E < 0x64;
						}
						else
						{
							actor_update_pos(&en->actor);
							uint8_t spC7 = 0;

							z64_capsule_t *capsule = &en->capsule;
							if ((capsule->cso_0x01 & 2) != 0)
							{
								spC7 = 1;
							}
							capsule->radius = (u16)0x17;
							capsule->height = (u16)0x19;
							capsule->unk_0x44 = (u16)-0xa;
							actor_capsule_update(&en->actor, capsule);
							actor_collision_check_set_at(global, AADDR(global,0x11e60), capsule);

							external_func_8002E4B4(global, &en->actor, 50.0f, 80.0f, 100.0f, 5);
							if ((en->actor.bgcheck_flags & 9) == 0)
							{
								// TODO readability, get rid of goto
								if (spC7 == 0)
								{
									if (en->unk150[0] == 0)
									{
block_65:
										actor_kill(&en->actor);
										if (en->unk150[0] != 0)
										{
											sound_play_position(global, &en->actor.pos_2, 0x14, 0x38ad);
										}
									}
								}
								else
								{
									goto block_65;
								}
							}
							else
							{
								goto block_65;
							}
block_68:
							phi_at = en->unk14E < 0x64;
						}
					}
					else
					{
block_50:
						if (en->unk184 != 0)
						{
							en->unk184 = (s16) (en->unk184 - 1);
						}
						actor_update_pos(&en->actor);
						actor_set_height(&en->actor, 0);

						z64_capsule_t *capsule = &en->capsule;
						capsule->radius = (u16)0x14;
						capsule->height = (u16)0xf;
						capsule->unk_0x44 = (u16)-5;
						actor_capsule_update(&en->actor, capsule);

						#if 0 // TODO bitwise what
						temp_a1 = global + 0x11e60;
						sp3C = (bitwise f32) temp_a1;
						#endif
						actor_collision_check_set_ac(global, AADDR(global,0x11e60), capsule);
						actor_collision_check_set_at(global, AADDR(global,0x11e60), capsule);
						if (en->unk150[2] == 0)
						{
							external_func_8002E4B4(global, &en->actor, 50.0f, 30.0f, 100.0f, 5);
							arwing_calculate_up_vector(en);
						}
						if (en->unk14E == 0xa)
						{
							arwing_spawn_particle_fire(global, &en->actor.pos_2, 1.0f);
							en->unk180 = (f32) (en->unk180 - 0.5f);
							en->actor.rot_2.y += 0x10;
							en->actor.vel_1.y -= 0.2f;
							sound_play_actor2(&en->actor, 0x304f);

							// Arwing has fallen onto the ground...
							if ((en->actor.bgcheck_flags & 9) != 0)
							{
								en->spawn_explosion = 1;
								if (en->draw_mode != 0)
								{
									en->draw_mode = (u8)2;
									en->unk186 = (u16)0x46;
									en->actor.flags = (s32) (en->actor.flags & -2);
								}
								else
								{
									actor_kill(&en->actor);
								}
							}
						}
						goto block_68;
					}
				}
				else
				{
block_12:
					if ((en->capsule.cso_0x01_02 & 2) != 0)
					{
						en->capsule.cso_0x01_02 = (s8) (en->capsule.cso_0x01_02 & 0xfffd);
						en->unk184 = (u16)0x14;
						external_func_8003426C(&en->actor, 0x4000, 0xff, 0, 5);
						en->unk170.x = external_func_80033F20(15.0f);
						en->unk170.y = external_func_80033F20(15.0f);
						en->unk170.z = external_func_80033F20(15.0f);
						sound_play_actor2(&en->actor, 0x38ad);
						en->actor.health -= 1;
						if (en->actor.health <= 0)
						{
							en->unk14E = (u8)0xa;
							en->actor.vel_1.y = 0.0f;
						}
						else
						{
block_15:
							actor_set_scale(&en->actor, 0.2f);
							en->actor.xz_speed = 7.0f;
							if (en->unk150[0] == 0)
							{
								if (en->unk150[1] == 0)
								{
									en->unk14E = (u8)1;
									en->unk150[0] = (u16)0x12c;
								}
								else
								{
									en->unk14E = (u8)0;
									en->unk150[0] = (s16) ((s32) math_rand_f32(50.0f) + 0x14);
									if (en->actor.variable == 1)
									{
										float sp94 = math_sins(player->rot_2.y) * 400.0f;
										float temp_f6 = math_coss(player->rot_2.y) * 400.0f;
										en->unk158.x = external_func_80033F20(700.0f) + (player->pos_2.x + sp94);
										en->unk158.y = math_rand_f32(200.0f) + player->pos_2.y + 150.0f;
										en->unk158.z = external_func_80033F20(700.0f) + (player->pos_2.z + temp_f6);
									}
									else
									{
										en->unk158.x = external_func_80033F20(700.0f);
										en->unk158.y = (f32) (math_rand_f32(200.0f) + 150.0f);
										en->unk158.z = external_func_80033F20(700.0f);
									}
								}
								en->unk164.z = 0.0f;
								en->unk164.y = 0.0f;
								en->unk164.x = 0.0f;
							}
							int spC0 = (u16)0xa;
							int spC2 = (u16)0x800;
							float phi_f12;
							if (en->unk14E == 1)
							{
								en->unk158.x = player->pos_2.x;
								en->unk158.y = player->pos_2.y + 40.0f;
								en->unk158.z = player->pos_2.z;
								spC0 = (u16)7;
								spC2 = (u16)0x1000;
								phi_f12 = 150.0f;
							}
							else
							{
								phi_f12 = 100.0f;
								if (en->unk14E == 2)
								{
									en->unk180 = (f32) (en->unk180 + 0.5f);
									if (6.283185f < en->unk180)
									{
										en->unk180 = (f32) (en->unk180 - 6.283185f);
									}
									en->unk158.x = 0.0f;
									en->unk158.y = 300.0f;
									en->unk158.z = 0.0f;
									phi_f12 = 100.0f;
								}
							}
							if (en->unk14E != 2)
							{
								// not used...
								//spA0 = (f32) phi_f12;
								// mips_to_c erroneously got phi_f12 for a0
								external_func_8007848C(&en->unk180, 0.1f, 0.2f);
							}
							float spB0 = (f32) (en->unk158.x - en->actor.pos_2.x);
							float spAC = (f32) (en->unk158.y - en->actor.pos_2.y);
							float temp_f2 = spB0 * spB0;
							float temp_f14 = en->unk158.z - en->actor.pos_2.z;
							float temp_f16 = temp_f14 * temp_f14;
							float phi_f2 = temp_f2;
							float phi_f16 = temp_f16;
							float phi_f14 = temp_f14;
							if (sqrtf((temp_f2 + (spAC * spAC)) + temp_f16) < phi_f12)
							{
								en->unk150[0] = (u16)0;
								if (en->unk14E == 1)
								{
									//sp3C = temp_f2; // unused
									//spA8 = temp_f14;
									//sp38 = temp_f16;
									// TODO mips_to_c (erroneously?) got temp_f14 for a1 of math_rand_f32
									en->unk150[1] = (s16) ((s32) math_rand_f32(100.0f) + 0x64);
								}
								en->unk14E = (u8)0;
							}
							//sp3C = (f32) phi_f2; // unused
							//sp38 = (f32) phi_f16;
							int temp_f18 = (s32) (external_func_800FD250(spAC, sqrtf(phi_f2 + phi_f16)) * 10430.377930f);
							int temp_a1_2 = (s32) (temp_f18 << 0x10) >> 0x10;
							int phi_a1 = temp_a1_2;
							if (((s32) (temp_f18 << 0x10) >> 0x10) < 0)
							{
								phi_a1 = temp_a1_2;
								if (en->actor.pos_2.y < (en->actor.floor_height + 20.0f))
								{
									phi_a1 = 0;
								}
							}
							// TODO this bitwise stuff has me all confused
							#if 0
							temp_a0 = en + 0x30;
							sp3C = (bitwise f32) temp_a0;
							external_func_800787BC(temp_a0, phi_a1, spC0, (s32) ((s32) en->unk164 << 0x10) >> 0x10);
							#else
							int16_t *sp3C = &en->actor.unk30;
							external_func_800787BC(
								&en->actor.unk30, phi_a1, spC0,
								(s32) ((s32) en->unk164.x << 0x10) >> 0x10
							);
							#endif

							// TODO what in tarnation
							int temp_s0_4 = external_func_8007869C(
								&en->actor.xz_dir,
								(s32) (((s32) ((s32) (external_func_800FD250(spB0, phi_f14) * 10430.377930f) << 0x10) >> 0x10) << 0x10) >> 0x10,
								spC0, (s32) ((s32) en->unk164.y << 0x10) >> 0x10,
								0
							);
							temp_s0_4 <<= 0x10;
							temp_s0_4 >>= 0x10;

							external_func_8007841C(&en->unk164.x, (f32) spC2, 1.0f, 256.0f);
							int temp_v0_2 = 0 - temp_s0_4;
							en->unk164.y = (f32) en->unk164.x;
							int phi_v0 = temp_v0_2;
							if (temp_s0_4 >= 0)
							{
								phi_v0 = temp_s0_4;
							}
							if (phi_v0 < 0x1000)
							{
								external_func_800787BC(
									&en->actor.unk34, 0, 0xf,
									(s32) ((s32) en->unk164.z << 0x10) >> 0x10
								);
								external_func_8007841C(&en->unk164.z, 1280.0f, 1.0f, 256.0f);
								if ((en->unk17C & 3) == 0)
								{
									if (math_rand_zero_one() < 0.75f)
									{
										if (en->unk14E == 1)
										{
											en->unk17D = (u8)1;
										}
									}
								}
							}
							else
							{
								int phi_s0_2;
								if (temp_s0_4 > 0)
								{
									phi_s0_2 = -0x2500;
								}
								else
								{
									phi_s0_2 = 0x2500;
								}
								external_func_800787BC(
									&en->actor.unk34, (s32) (phi_s0_2 << 0x10) >> 0x10, spC0,
									(s32) ((s32) en->unk164.z << 0x10) >> 0x10
								);
								external_func_8007841C(&en->unk164.z, 4096.0f, 1.0f, 512.0f);
							}
						#if 0
							lwl             $t7,0($t5)
							lwr             $t7,3($t5)
							swl             $t7,180($s1)
							swr             $t7,183($s1)
							lh              $t8,180($s1)
							lhu             $t7,4($t5)
							subu            $t9,$zero,$t8
							sh              $t9,180($s1)
							jal             external_func_8002D908
							sh              $t7,184($s1)
						#endif
							// TODO mips_to_c can't handle lwl/lwr/swl/swr, so
							// these were used
							// does everything still function the same?
						#if 0
							en->unkB4 = (s16) sp3C->unk0;
							en->unkB7 = (s16) sp3C->unk3;
							en->unkB4 = (s16) (0 - en->unkB4);
							en->unkB8 = (s16) sp3C->pos;
						#endif
							en->actor.rot_2.x = (s16) sp3C[0];
							en->actor.rot_2.y = (s16) sp3C[1];
							en->actor.rot_2.x = (s16) (0 - en->actor.rot_2.x);
							en->actor.rot_2.z = (s16) sp3C[2];
							external_func_8002D908(&en->actor);

							// acceleration / deceleration
							en->actor.vel_1.x += en->unk170.x;
							en->actor.vel_1.y += en->unk170.y;
							en->actor.vel_1.z += en->unk170.z;
							external_func_8007848C(&en->unk170.x, 1.0f, 1.0f);
							external_func_8007848C(&en->unk170.y, 1.0f, 1.0f);
							external_func_8007848C(&en->unk170.z, 1.0f, 1.0f);
							if (en->unk17D != 0)
							{
								en->unk17D = (u8)0;
								actor_spawn(
									AADDR(global,0x1c24), global, 0x13b,
									en->actor.pos_2.x, en->actor.pos_2.y, en->actor.pos_2.z,
									// TODO does this make unk30/32/34 all s16 values,
									//       or should casting be used?
									(s16) en->actor.unk30, (s16) en->actor.xz_dir, (s16) en->actor.unk34,
									0x64
								);
							}
						}
					}
					else
					{
						goto block_15;
					}
					goto block_50;
				}
			}
			else
			{
				goto block_12;
			}
		}
		else
		{
			goto block_12;
		}
		if (phi_at != 0)
		{
			debug_message("DEMO_MODE %d\n", en->cutscene_mode);
			debug_message("CAMERA_NO %d\n", en->camera_id);
			if (en->cutscene_mode != 0)
			{
				vec3f_t appr_lookat = { 0 };
				vec3f_t appr_camera = { 0 };
				if (en->cutscene_mode != 1)
				{
					if (en->cutscene_mode != 2)
					{

					}
					else
					{
block_75:
	;
						int temp_s0_5 = (s32) (en->unk17C * 0x800000) >> 0x10;
						float sp8C = (f32) (math_sins((s32) (temp_s0_5 << 0x10) >> 0x10) * 200.0f);
						appr_lookat.x = (en->actor.pos_2.x + sp8C);
						appr_lookat.y = 200.0f;
						appr_lookat.z = (en->actor.pos_2.z + (math_coss((s32) (temp_s0_5 << 0x10) >> 0x10) * 200.0f));
						appr_camera.x = en->actor.pos_2.x;
						appr_camera.y = en->actor.pos_2.y;
						appr_camera.z = en->actor.pos_2.z;
					}
				}
				else
				{
					en->cutscene_mode = 2;
					external_func_80064520(global, AADDR(global,0x1d64));
					en->camera_id = external_func_800C0230(global);
					external_func_800C0314(global, 0, 1);
					external_func_800C0314(global, en->camera_id, 7);
					goto block_75;
				}
				if (en->camera_id != 0)
				{
					vec3f_t *lookat = &en->camera_lookat;
					external_func_8007841C(&lookat->x, appr_lookat.x, 0.1f, 500.0f);
					external_func_8007841C(&lookat->y, appr_lookat.y, 0.1f, 500.0f);
					external_func_8007841C(&lookat->z, appr_lookat.z, 0.1f, 500.0f);

					vec3f_t *camera = &en->camera_pos;
					external_func_8007841C(&camera->x, appr_camera.x, 0.2f, 500.0f);
					external_func_8007841C(&camera->y, appr_camera.y, 0.2f, 500.0f);
					external_func_8007841C(&camera->z, appr_camera.z, 0.2f, 500.0f);

					external_func_800C04D8(global, en->camera_id, camera, lookat);
				}
				// last frame of cutscene, so diable it
				if (en->cutscene_time == 1)
				{
					// TODO the original function prototype suggests two arguments,
					// but there are three here; going with three for now, please
					// investigate
					external_func_800C08AC(global, en->camera_id, 0);
					en->camera_id = (u16)0;
					en->cutscene_mode = en->camera_id;
					external_func_80064534(global, AADDR(global,0x1d64));
				}
			}
		}
	}
	// Arwing fell onto the ground, spawn an explosion!
	if( en->spawn_explosion )
	{
		en->spawn_explosion = 0;
		sound_play_position(global, &en->actor.pos_2, 0x28, 0x180e);
		vec3f_t pos = { en->actor.pos_2.x, (en->actor.pos_2.y + 40.0f) - 30.0f, en->actor.pos_2.z };
		arwing_spawn_particle_flash(global, &pos, 6.0f, en->actor.floor_height, &en->up);
		pos.y = (en->actor.pos_2.y + 30.0f) - 50.0f;
		arwing_spawn_particle_smoke(global, &pos, 3.0f);
		pos.y = en->actor.pos_2.y;

		// spawn fifteen pieces of flaming debris
		for( int i=0; i < 15; ++i )
		{
			float sp3C = i;
			float sp38 = sp3C * 1.65f;

			// sp54, 58, 5C
			vec3f_t vel = {
				(external_func_80100290(sp38) * sp3C) * 0.3f,
				math_rand_f32(6.0f) + 5.0f,
				(external_func_80104610(sp38) * sp3C) * 0.3f
			};
			vel.x += external_func_80033F20(0.5f);
			vel.y += external_func_80033F20(0.5f);

			vec3f_t acc = { 0.0f, -1.0f, 0.0f };
			arwing_spawn_particle_debris(global, &pos, &vel, &acc, math_rand_f32(0.15f) + 0.075f );
		}
	}
	if (en->draw_mode != 0)
	{
		if (en->draw_mode == 2)
		{
			int phi_v0_2;
			if (en->unk186 == 0)
			{
				phi_v0_2 = (u16)0;
			}
			else
			{
				en->unk186 = (s16) (en->unk186 - 1);
				phi_v0_2 = en->unk186;
			}
			if (phi_v0_2 == 0)
			{
				actor_kill(&en->actor);
			}
		}
		arwing_particle_physics(global);
	}
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x09,
	.room = 0x00,
	.flags = 0x00000035,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = destroy,
	.main = update,
	.draw = draw
};
