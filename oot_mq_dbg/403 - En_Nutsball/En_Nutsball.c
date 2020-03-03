#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

#define OBJ_ID 1

#define DEKUNUTS 0x06002028 /* En_Dekunuts; Mad Scrub */
#define HINTNUTS 0x060012F0 /* En_Hintnuts; Tutorial Scrub (Deku Tree) */
#define SHOPNUTS 0x06004008 /* En_Shopnuts; Business Scrub */
#define DNS_NUTS 0x06002410 /* Mask Theatre Judge */
#define DNK_NUTS 0x06001890 /* Mask Theatre Audience */

typedef struct {
	z64_actor_t actor;
	/* uint8_t debug_ex[16];*/
	z64_actorfunc_t* state;
	uint8_t object_index;
	uint8_t inst0151;
	int16_t timer;
	z64_collider_cylinder_main_t collider;
} entity_t; /* 01A0 */


/*** function prototypes ***/
void dest(entity_t* en, z64_global_t* gl);
void set_draw(entity_t* en, z64_global_t* gl);
void handle_collider(entity_t* en, z64_global_t* gl);
void init(entity_t* en, z64_global_t* gl);
void draw(entity_t* en, z64_global_t* gl);
void update(entity_t* en, z64_global_t* gl);


/*** variables ***/
const uint32_t collider_init[] =
{
	0x0A110939,
	0x20010000,
	0x00000000,
	0xFFCFFFFF,
	0x00080000,
	0xFFCFFFFF,
	0x00000000,
	0x11010100,
	0x000D000D,
	0x00000000,
	0x00000000
};
const uint16_t object_index[] =
{
	0x004A,
	0x0164,
	0x0168,
	0x0171,
	0x0172,
	0x0000
};

const uint32_t dlist_index[] =
{
	DEKUNUTS,
	HINTNUTS,
	SHOPNUTS,
	DNS_NUTS,
	DNK_NUTS,
	0x00000000
};

/*** functions ***/
void dest(entity_t* en, z64_global_t* gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);
	z_collider_cylinder_free(gl, &en->collider);
}

void set_draw(entity_t* en, z64_global_t* gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lset_draw: \n"
	);

	if (z_scene_object_is_loaded(&gl->obj_ctxt, en->object_index))
	{
		(en->actor).draw_proc = (void*)draw;
		(en->actor).rot_2.y = 0;
		en->timer = 30;
		en->state = (z64_actorfunc_t*)handle_collider;
		(en->actor).alloc_index = en->object_index;
		(en->actor).xz_speed = 10.0f;
	}
}

void handle_collider(entity_t* en, z64_global_t* gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lhandle_collider: \n"
	);

	z64_player_t* Link = zh_get_player(gl);
	uint16_t bg_chk = (en->actor).bgcheck_flags;
	uint8_t cldr_flags = (en->collider).base.collider_flags;
	int16_t reflected_dir[2];
	vec3f_t effect_coords;

	en->timer -= 1;

	if (en->timer == 0)
		(en->actor).gravity = -1.0f;
	(en->actor).rot_init.z += 0x2AA8;

	if ((bg_chk & 8) == 0)
	{
		if ((bg_chk & 1) == 0)
		{
			if (((en->collider).base.collider_flags & 2) == 0)
			{
				if (((en->collider).base.collide_flags & 2) == 0)
				{
					if (((en->collider).base.mask_a & 2) == 0)
					{
						if (en->timer != -300)
							return;
						z_actor_kill(&en->actor);
						return;
					}
				}
			}
		}
	}

	effect_coords.x = (en->actor).pos_2.x;
	effect_coords.y = (en->actor).pos_2.y;
	effect_coords.z = (en->actor).pos_2.z;

	/* Essentially, if not using Mirror Shield, do reflect logic */
	if (Link->shield_idx == 1 || Link->shield_idx == 2)
	{
		if ((((cldr_flags & 2) != 0) && ((cldr_flags & 0x10) != 0)) && ((cldr_flags & 4) != 0))
		{
			(en->collider).base.collider_flags &= 0xE9;
			(en->collider).base.collider_flags &= 0xE9 | 8;
			(en->collider).body.toucher.flags = 2;
			external_func_800D20CC(&Link->floatA20, reflected_dir, 0);
			(en->actor).xz_dir = reflected_dir[1] - 0x8000;
			en->timer = 30;
			return;
		}
	}

	if (zh_link_is_adult)
		effect_coords.y = ((en->actor).pos_2.y + 4.0f);

	/* So far, this is the only part of this function that works like it should. */
	z_effect_spawn_hahen_n(
		gl
		, &effect_coords
		, 6.0f
		, 0
		, 7
		, 3
		, 0xF
		, -1
		, 10
		, 0
	);
	sound_play_position(gl, &(en->actor).pos_2, 0x14, 0x38C0);
	z_actor_kill(&en->actor);
}

void init(entity_t* en, z64_global_t* gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit: \n"
	);
	/* Instance Debugging */
	uint32_t* _en = (uint32_t*)0x80600000;
	*_en = (uint32_t)&(zh_get_player(gl)->state_flags_1) - LINK;

	/* Initialize the shadow rendering process and load the collider structure into memory. */
	z_actor_shadow_init(&(en->actor).rot_2, 400.0f, &Z_SHADOW_CIRCLE, 13.0f);
	z_collider_cylinder_alloc(gl, &en->collider);
	z_collider_cylinder_init(gl, &en->collider, &en->actor, (z64_collider_cylinder_init_t*)collider_init);

	/* Grab the correct deku scrub object from the index list. */
	en->object_index = z_scene_object_get_index(&gl->obj_ctxt, object_index[(en->actor).variable]);

	/* If the object isn't loaded, kill the actor process; otherwise, continue. */
	if (en->object_index < 0)
		z_actor_kill(&en->actor);
	else
		en->state = (z64_actorfunc_t*)set_draw;
}

void draw(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 68 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	z64_gfx_t* gfx = (gl->common).gfx_ctxt;
	z64_disp_buf_t* opa = &ZQDL(gl, poly_opa);
	Gfx gfx_debug[3];

	z_debug_graph_alloc(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
	z_rcp_append_preset(gfx);
	z_matrixf_top_multiply(gl->unk_player_matrix, 1);
	/* Rotate the display list on its Z axis. */
	z_matrix_roll(((en->actor).rot_init.z * 0.000095873795f), 1);
	gSPMatrix(opa->p++, z_matrix_alloc(gfx, "../z_en_nutsball.c"/*, __LINE__*/), G_MTX_LOAD);
	/* Grab the display list pointer form the index, based on the variable.*/
	gSPDisplayList(opa->p++, dlist_index[(en->actor).variable]);
	z_debug_graph_write(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
}

void update(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 73 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lmain: \n"
	);
	z64_actorfunc_t* state_func;
	z64_player_t* Link = zh_get_player(gl);

	if (/*(Link->state_flags_1)*/AVAL(Link, uint32_t, 0x067C) & 0x300000C0 == 0) /* Bug: Currently causes the Deku Nut to draw and get frozen in place. */
		state_func = en->state;
	else
	{
		if (en->state != (z64_actorfunc_t*)set_draw)
			return;
		state_func = en->state;
	}
	state_func(en, gl);

	z_actor_move_dir_vel(&en->actor);
	z_actor_find_bounds(gl, &en->actor, 10.0f, /* collider_init.radius*/0x0D, /* collider_init.height*/0x0D, 5);
	z_collider_cylinder_update(&en->actor, &en->collider);
	(en->actor).flags |= 0x01000000;
	z_collider_set_at(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ac(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ot(gl, &gl->hit_ctxt, &en->collider);
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = update,
	.draw = NULL
};
