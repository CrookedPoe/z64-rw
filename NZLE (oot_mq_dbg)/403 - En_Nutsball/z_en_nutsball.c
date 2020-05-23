/************
 * z_en_nutsball.c faithfully rewritten by CrookedPoe <nickjs.site>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit 7e47fc9a8c85706869fb7d24285d3f1cc1a13644
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>

#define DL_DEKUNUTS 0x06002028 /* En_Dekunuts; Mad Scrub */
#define DL_HINTNUTS 0x060012F0 /* En_Hintnuts; Tutorial Scrub (Deku Tree) */
#define DL_SHOPNUTS 0x06004008 /* En_Shopnuts; Business Scrub */
#define DL_DNS_NUTS 0x06002410 /* Mask Theatre Judge */
#define DL_DNK_NUTS 0x06001890 /* Mask Theatre Audience */

#define OBJ_DEKUNUTS 0x004A
#define OBJ_HINTNUTS 0x0164
#define OBJ_SHOPNUTS 0x0168
#define OBJ_DNS_NUTS 0x0171
#define OBJ_DNK_NUTS 0x0172

typedef struct {
	z64_actor_t actor;
	/* uint8_t debug_ex[16];*/
	z64_actorfunc_t* state;
	uint8_t object_index;
	int16_t timer;
	z64_collider_cylinder_t collider;
} z_en_nutsball_t; /* 01A0 */

/*** function prototypes ***/
void dest(z_en_nutsball_t* en, z64_global_t* gl);
void set_draw(z_en_nutsball_t* en, z64_global_t* gl);
void handle_collider(z_en_nutsball_t* en, z64_global_t* gl);
void init(z_en_nutsball_t* en, z64_global_t* gl);
void draw(z_en_nutsball_t* en, z64_global_t* gl);
void update(z_en_nutsball_t* en, z64_global_t* gl);


/*** variables ***/
const z64_collider_init_t nutsball_base = {
	.type = COL_TYPE_UNK10
	, .flags_at = 0x11
	, .flags_ac = 0x09
	, .mask_a = 0x39
	, .mask_b = 0x20
	, .shape = COL_SHAPE_CYLINDER
};

const z64_collider_body_init_t nutsball_body = {
	.flags_body = 0x00
	, .toucher = {
		.flags = 0xFFCFFFFF
		, .effect = 0x00
		, .damage = 0x08
	}
	, .bumper = {
		.flags = 0xFFCFFFFF
		, .effect = 0x00
		, .defense = 0x00
	}
	, .flags_toucher = 0x11
	, .flags_bumper = 0x01
	, .flags_body_2 = 0x01
};

const z64_cylinder16_t nutsball_dim = {
	.radius = 13
	, .height = 13
	, .y_shift = 0
	, .pos = {0, 0, 0}
};

const z64_collider_cylinder_init_t nutsball_collision = {
	.base = nutsball_base
	, .body = nutsball_body
	, .dim = nutsball_dim
};

const uint16_t obj_index[] =
{
	OBJ_DEKUNUTS,
	OBJ_HINTNUTS,
	OBJ_SHOPNUTS,
	OBJ_DNS_NUTS,
	OBJ_DNK_NUTS,
	0
};

const uint32_t dl_index[] =
{
	DL_DEKUNUTS,
	DL_HINTNUTS,
	DL_SHOPNUTS,
	DL_DNS_NUTS,
	DL_DNK_NUTS,
	0
};

/*** functions ***/
/* Main Destructor Function */
void dest(z_en_nutsball_t* en, z64_global_t* gl)
{
	z_collider_cylinder_free(gl, &en->collider);
}

void set_draw(z_en_nutsball_t* en, z64_global_t* gl) /* 0 internal, 1 external, 30 lines */
{
	if (OBJ_IS_LOADED(&gl->obj_ctxt, en->object_index))
	{
		(en->actor).draw_proc = (void*)draw;
		(en->actor).rot.y = 0;
		en->timer = 30;
		en->state = (z64_actorfunc_t*)handle_collider;
		(en->actor).alloc_index = en->object_index;
		(en->actor).xz_speed = 10.0f;
	}
}

void handle_collider(z_en_nutsball_t* en, z64_global_t* gl) /* 0 internal, 4 external, 124 lines */
{
  z64_player_t* Link = zh_get_player(gl);
  vec3f_t fx_pos;
  vec3s_t _dir;

  if (en->timer == 0)
      en->actor.gravity = -1.0f;

  en->actor.rot_init.z += 0x2AA8;

  if ((en->actor.bgcheck_flags & 8) != 0 || (en->actor.bgcheck_flags & 1) != 0 || (en->collider.base.flags_at & 2) != 0 || (en->collider.base.flags_ac & 2) != 0)
	{
      if (Link->shield_idx == 1) /* If Link is using the Deku Shield, make an exception to deflect the deku nut. */
          goto LAB_deflect;
			else if ((Link->shield_idx != 2) || (zh_link_is_child())) /* If Link is a child, or the Hylian Shield is not being used, do not deflect the deku nut. */
					goto LAB_destroy;
  }
  else if ((en->collider.base.flags_ac & 2) == 0)
	{
		if (en->timer != -300)
				return;
		z_actor_kill(&en->actor);
		return;
	}
LAB_deflect:
  if (!((en->collider.base.flags_at & 2) == 0 || (en->collider.base.flags_at & 16) == 0 || (en->collider.base.flags_at & 4) == 0))
	{
      en->collider.base.flags_at &= 0xFFE9;
      en->collider.base.flags_at |= 8;
      en->collider.body.toucher.flags = 2;
      z_vec3s_from_mtxf((float*)Link->shield_mf, &_dir, 0);
      en->actor.dir.y = _dir.y + ROT16(180);
      return;
  }
LAB_destroy:
  fx_pos = (en->actor).pos;
  fx_pos.y += 4.0f;

  z_effect_spawn_hahen_n(gl, &fx_pos, 6.0f, 0, 7, 3, 15, -1, 10, 0);
  z_sfx_play_position(gl, &en->actor.pos, 0x14, NA_SE_EN_OCTAROCK_ROCK);
  z_actor_kill(&en->actor);
}

void init(z_en_nutsball_t* en, z64_global_t* gl) /* 0 internal, 5 external, 49 lines */
{
	/* Initialize the shadow rendering process and load the collider structure into memory. */
	z_actor_shadow_init(&(en->actor).rot, 400.0f, &Z_SHADOW_CIRCLE, 13.0f);
	z_collider_cylinder_alloc(gl, &en->collider);
	z_collider_cylinder_init(gl, &en->collider, &en->actor, &nutsball_collision);

	/* Grab the correct deku scrub object from the index list. */
	en->object_index = z_scene_object_get_index(&gl->obj_ctxt, obj_index[(en->actor).variable]);

	/* If the object isn't loaded, kill the actor process; otherwise, continue. */
	if (en->object_index < 0)
		z_actor_kill(&en->actor);
	else
		en->state = (z64_actorfunc_t*)set_draw;
}

void draw(z_en_nutsball_t* en, z64_global_t* gl) /* 0 internal, 6 external, 68 lines */
{
	z64_gfx_t* gfx = (gl->common).gfx_ctxt;
	z64_disp_buf_t* opa = &ZQDL(gl, poly_opa);
	Gfx gfx_debug[3];

	z_debug_graph_alloc(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
	z_rcp_append_preset_opa(gfx);
	z_matrixf_top_multiply(gl->unk_player_matrix, 1);
	/* Rotate the display list on its Z axis. */
	z_matrix_roll(((en->actor).rot_init.z * 0.000095873795f), 1);
	gSPMatrix(opa->p++, z_matrix_alloc(gfx, "../z_en_nutsball.c"/*, __LINE__*/), G_MTX_LOAD);
	/* Grab the display list pointer form the index, based on the variable.*/
	gSPDisplayList(opa->p++, dl_index[(en->actor).variable]);
	z_debug_graph_write(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
}

void update(z_en_nutsball_t* en, z64_global_t* gl) /* 0 internal, 6 external, 73 lines */
{
	z64_actorfunc_t* state_func = en->state;
	z64_player_t* Link = zh_get_player(gl);

	if ((Link->state_flags_1 & 0x300000C0) != 0 && state_func != (z64_actorfunc_t*)set_draw)
			return;

	if (state_func)
		state_func(en, gl);

	z_actor_move_dir_vel(&en->actor);
	z_actor_find_bounds(gl, &en->actor, 10.0f, (nutsball_collision.dim).radius, (nutsball_collision.dim).height, 5);
	z_collider_cylinder_update(&en->actor, &en->collider);
	(en->actor).flags |= 0x01000000;
	z_collider_hitbox(gl, &gl->hit_ctxt, &en->collider);
	z_collider_hurtbox(gl, &gl->hit_ctxt, &en->collider);
	z_collider_bumpbox(gl, &gl->hit_ctxt, &en->collider);
}

const z64_actor_init_t init_vars = {
	.number = 0x0193,
	.type = OVLTYPE_PROP,
	.room = 0x00,
	.flags = 0x00000010,
	.object = 0x0001,
	.padding = 0x0000,
	.instance_size = sizeof(z_en_nutsball_t),
	.init = init,
	.dest = dest,
	.main = update,
	.draw = NULL
};
