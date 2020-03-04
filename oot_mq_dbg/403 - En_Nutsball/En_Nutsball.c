#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>

#define OBJ_ID 1

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
	uint8_t inst0151;
	int16_t timer;
	z64_collider_cylinder_main_t collider;
} entity_t; /* 01A0 */

#define OK_80ABBB0C 1
#define OK_80ABBB34 1
#define OK_80ABBBA8 1
#define OK_80ABBA50 1
#define OK_80ABBE90 1
#define OK_80ABBD74 1

/*** function prototypes ***/
void data_80ABBB0C(entity_t* en, z64_global_t* gl);
void data_80ABBB34(entity_t* en, z64_global_t* gl);
void data_80ABBBA8(entity_t* en, z64_global_t* gl);
void data_80ABBA50(entity_t* en, z64_global_t* gl);
void data_80ABBE90(entity_t* en, z64_global_t* gl);
void data_80ABBD74(entity_t* en, z64_global_t* gl);


/*** variables ***/
const uint32_t data_80ABBFC0[] =
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
const uint16_t data_80ABBFEC[] =
{
	OBJ_DEKUNUTS,
	OBJ_HINTNUTS,
	OBJ_SHOPNUTS,
	OBJ_DNS_NUTS,
	OBJ_DNK_NUTS,
	0
};

const uint32_t data_80ABBFF8[] =
{
	DL_DEKUNUTS,
	DL_HINTNUTS,
	DL_SHOPNUTS,
	DL_DNS_NUTS,
	DL_DNK_NUTS,
	0
};

const uint32_t data_80ABC010[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};

const uint32_t data_80ABC024[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};

const uint32_t data_80ABC038[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};

const uint32_t data_80ABC04C[] =
{
	0x38C90FDA
};


/*** functions ***/
#if OK_80ABBB0C
void data_80ABBB0C(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80ABBB0C: \n"
	);
	z_collider_cylinder_free(gl, &en->collider);
}
#else
#include "asm/data_80ABBB0C.c"
#endif

#if OK_80ABBB34
void data_80ABBB34(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 30 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80ABBB34: \n"
	);

	if (z_scene_object_is_loaded(&gl->obj_ctxt, en->object_index))
	{
		(en->actor).draw_proc = (void*)data_80ABBE90;
		(en->actor).rot_2.y = 0;
		en->timer = 30;
		en->state = (z64_actorfunc_t*)data_80ABBBA8;
		(en->actor).alloc_index = en->object_index;
		(en->actor).xz_speed = 10.0f;
	}
}
#else
#include "asm/data_80ABBB34.c"
#endif

#if OK_80ABBBA8
void data_80ABBBA8(entity_t* en, z64_global_t* gl) /* 0 internal, 4 external, 124 lines */
{
  asm(
      ".set at        \n"
      ".set reorder   \n"
      ".Ldata_80ABBBA8: \n"
  );
  z64_player_t* Link = zh_get_player(gl);
  vec3f_t fx_pos;
  int16_t _dir[2];

  if (en->timer == 0)
      en->actor.gravity = -1.0f;

  en->actor.rot_init.z += 0x2AA8;

  if ((en->actor.bgcheck_flags & 8) != 0 || (en->actor.bgcheck_flags & 1) != 0 || (en->collider.base.collider_flags & 2) != 0 || (en->collider.base.collide_flags & 2) != 0)
	{
      if (Link->shield_idx == 1)
          goto LAB_deflect;
			else if ((Link->shield_idx != 2) || (zh_link_is_child()))
					goto LAB_destroy;
  }
  else if ((en->collider.base.collide_flags & 2) == 0)
	{
		if (en->timer != -300)
				return;
		z_actor_kill(&en->actor);
		return;
	}
LAB_deflect:
  if (!((en->collider.base.collider_flags & 2) == 0 || (en->collider.base.collider_flags & 0x10) == 0 || (en->collider.base.collider_flags & 0x4) == 0))
	{
      en->collider.base.collider_flags &= 0xFFE9;
      en->collider.base.collider_flags |= 8;
      en->collider.body.toucher.flags = 2;
      external_func_800D20CC(&Link->floatA20, _dir, 0);
      en->actor.xz_dir = _dir[1] + 0x8000;
      return;
  }
LAB_destroy:
  fx_pos.x = en->actor.pos_2.x;
  fx_pos.y = en->actor.pos_2.y + 4.0f;
  fx_pos.z = en->actor.pos_2.z;

  z_effect_spawn_hahen_n(gl, &fx_pos, 6.0f, 0, 7, 3, 15, -1, 10, 0);
  sound_play_position(gl, &en->actor.pos_2, 0x14, 0x38C0);
  z_actor_kill(&en->actor);
}
#else
#include "asm/data_80ABBBA8.c"
#endif

#if OK_80ABBA50
void data_80ABBA50(entity_t* en, z64_global_t* gl) /* 0 internal, 5 external, 49 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80ABBA50: \n"
	);
	/* Instance Debugging */
	uint32_t* _en = (uint32_t*)0x80600000;
	*_en = (uint32_t)&(zh_get_player(gl)->state_flags_1) - LINK;

	/* Initialize the shadow rendering process and load the collider structure into memory. */
	z_actor_shadow_init(&(en->actor).rot_2, 400.0f, &Z_SHADOW_CIRCLE, 13.0f);
	z_collider_cylinder_alloc(gl, &en->collider);
	z_collider_cylinder_init(gl, &en->collider, &en->actor, (z64_collider_cylinder_init_t*)data_80ABBFC0);

	/* Grab the correct deku scrub object from the index list. */
	en->object_index = z_scene_object_get_index(&gl->obj_ctxt, data_80ABBFEC[(en->actor).variable]);

	/* If the object isn't loaded, kill the actor process; otherwise, continue. */
	if (en->object_index < 0)
		z_actor_kill(&en->actor);
	else
		en->state = (z64_actorfunc_t*)data_80ABBB34;
}
#else
#include "asm/data_80ABBA50.c"
#endif

#if OK_80ABBE90
void data_80ABBE90(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 68 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80ABBE90: \n"
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
	gSPDisplayList(opa->p++, data_80ABBFF8[(en->actor).variable]);
	z_debug_graph_write(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
}
#else
#include "asm/data_80ABBE90.c"
#endif

#if OK_80ABBD74
void data_80ABBD74(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 73 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80ABBD74: \n"
	);

	z64_actorfunc_t* state_func = en->state;
	z64_player_t* Link = zh_get_player(gl);

	if ((Link->state_flags_1 & 0x300000C0) != 0 && state_func != (z64_actorfunc_t*)data_80ABBB34)
			return;

	if (state_func)
		state_func(en, gl);

	z_actor_move_dir_vel(&en->actor);
	z_actor_find_bounds(gl, &en->actor, 10.0f, /* collider_init.radius*/0x0D, /* collider_init.height*/0x0D, 5);
	z_collider_cylinder_update(&en->actor, &en->collider);
	(en->actor).flags |= 0x01000000;
	z_collider_set_at(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ac(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ot(gl, &gl->hit_ctxt, &en->collider);
}
#else
#include "asm/data_80ABBD74.c"
#endif

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = data_80ABBA50,
	.dest = data_80ABBB0C,
	.main = data_80ABBD74,
	.draw = NULL
};
