/************
 * z_en_m_thunder.c faithfully rewritten by CrookedPoe <nickjs.site>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit 125890e7d8d5e8cad75440f51ed408af060e93ea
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/gameplay_keep.h>
#include <z64ovl/oot/sfx.h>

typedef struct {
	z64_actor_t actor;
	/* uint8_t[16] debug_ex;*/
	z64_collider_cylinder_t collider;
	z64_light_node_t* light_node;
	z64_lightinfo_t light_info;
	uint16_t inst01A0;
	uint8_t inst01A2;
	uint8_t inst01A3;
	uint8_t inst01A4[8];
	float inst01AC;
	float inst01B0;
	float inst01B4;
	float inst01B8;
	float inst01BC;
	z64_actorfunc_t* state;
	uint16_t inst01C4;
	uint8_t attack_level;
	uint8_t equipped_sword;
	uint8_t prim_alpha;
	uint8_t damage_multiplier;
	uint8_t inst01CA;
	uint8_t inst01CB;
} entity_t; /* 01CC */


/*** function prototypes ***/
static void constructor(entity_t* en, z64_global_t* gl); /* OK */
static void destructor(entity_t* en, z64_global_t* gl); /* OK */
static void data_80A9F408(entity_t* en, z64_global_t* gl); /* OK */
static void data_80A9F9B4(entity_t* en, z64_global_t* gl); /* OK */
static void behavior(entity_t* en, z64_global_t* gl); /* OK */
static void draw(entity_t* en, z64_global_t* gl); /* OK */
static void set_state(entity_t* en, z64_actorfunc_t* state); /* OK */
static void func_80A9F314(z64_global_t* gl, float a1); /* OK */
static void func_80A9F350(entity_t* en, z64_global_t* gl); /* OK */
static void func_80A9F938(entity_t* en); /* OK */


/*** variables ***/
const z64_collider_init_t thunder_base = {
	.type = COL_TYPE_UNK10
	, .flags_at = 0x09
	, .flags_ac = 0x00
	, .mask_a = 0x00
	, .mask_b = 0x10
	, .shape = COL_SHAPE_CYLINDER
};

const z64_collider_body_init_t thunder_body = {
	.flags_body = 0x02
	, .toucher = {
		.flags = 0x00000001
		, .effect = 0x00
		, .damage = 0x00
	}
	, .bumper = {
		.flags = 0xFFCFFFFF
		, .effect = 0x00
		, .defense = 0x00
	}
	, .flags_toucher = 0x19
	, .flags_bumper = 0x01
	, .flags_body_2 = 0x01
};

const z64_cylinder16_t thunder_dim = {
	.radius = 200
	, .height = 200
	, .y_shift = 0
	, .pos = {0, 0, 0}
};

const z64_collider_cylinder_init_t thunder_collision = {
	.base = thunder_base
	, .body = thunder_body
	, .dim = thunder_dim
};

const int32_t small_spin_toucher_flags[] =
{
	0x01000000,
	0x00400000,
	0x00800000
};

const uint32_t big_spin_toucher_flags[] =
{
	0x08000000,
	0x02000000,
	0x04000000
};

const uint16_t release_sfx[] =
{
	NA_SE_IT_ROLLING_CUT_LV2,
	NA_SE_IT_ROLLING_CUT_LV1,
	NA_SE_IT_ROLLING_CUT_LV2,
	NA_SE_IT_ROLLING_CUT_LV1
};


/*** functions ***/
static void set_state(entity_t* en, z64_actorfunc_t* state) /* OK */
{
	en->state = state;
}

static void func_80A9F938(entity_t* en) /* OK */
{
	if (en->inst01C4 < 2)
	{
		if (en->prim_alpha < 0x28)
		{
			en->prim_alpha = 0;
		}
		else
		{
			en->prim_alpha -= 0x28;
		}
	}

	en->inst01B4 += (en->inst01B0 * 2);

	if (en->inst01AC <= en->inst01BC)
	{
		en->inst01BC = en->inst01AC;
		return;
	}

	en->inst01BC += (en->inst01AC - en->inst01BC) * 0.1f;
}

static void draw(entity_t* en, z64_global_t* gl) /* OK */
{
	Gfx dbg_gfx[2];
	z64_gfx_t* gfx_ctxt = (gl->common).gfx_ctxt;
	z64_disp_buf_t* xlu = &ZQDL(gl, poly_xlu);
	z64_player_t* Link = zh_get_player(gl);

	z_debug_graph_alloc(dbg_gfx, gfx_ctxt, __FILE__, __LINE__);
	z_rcp_append_preset_xlu_80093D84(gfx_ctxt);
	z_matrix_scale_3f(0.02f, 0.02f, 0.02f, 1);
	gSPMatrix(
		xlu->p++
		, z_matrix_alloc(gfx_ctxt, __FILE__)
		, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW
	);
	if (en->attack_level == 0 || en->attack_level == 1)
	{
		gSPSegment(xlu->p++
			, 8
			, z_rcp_gen_2_settilesize(
				gfx_ctxt
				, 0
				, 255 - ((en->inst01B4) * 30.0f + 255)
				, 0
				, 0x40
				, 0x20
				, 1
				, 255 - ((en->inst01B4) * 20.0f + 255)
				, 0
				, 8
				, 8
			)
		);
	}
	if (en->attack_level == 0) /* Red Spin Attack Ring */
	{
		uint32_t alpha = FLOOR((en->inst01B0 * 255.0f));
		if (alpha < 0)
			alpha = 0xFFFFFFFF;
		gDPSetPrimColor(xlu->p++, 0x00, 0x80, 0xFF, 0xFF, 0xAA, (alpha & 0xFF));
		gSPDisplayList(xlu->p++, DL_M_THUNDER_SPIN_BIG_X);
		gSPDisplayList(xlu->p++, DL_M_THUNDER_SPIN_BIG_Y);
	}
	else if (en->attack_level == 1) /* Blue Spin Attack Ring */
	{
		uint32_t alpha = FLOOR((en->inst01B0 * 255.0f));
		if (alpha < 0)
			alpha = 0xFFFFFFFF;
		gDPSetPrimColor(xlu->p++, 0x00, 0x80, 0xAA, 0xFF, 0xFF, (alpha & 0xFF));
		gSPDisplayList(xlu->p++, DL_M_THUNDER_SPIN_SMALL_X);
		gSPDisplayList(xlu->p++, DL_M_THUNDER_SPIN_SMALL_Y);
	}
	z_matrixf_top_multiply((float*)Link->sword_mf, 0);
	if (en->equipped_sword == 0) /* Master Sword */
	{
		z_matrix_translate_3f(0.0f, 300.0f, 0.0f, 1);
		z_matrix_scale_3f(-1.2f, -1.0f, -0.69f, 1);
		z_matrix_pitch(16384.0f, 1);
	}
	else if (en->equipped_sword == 1) /* Kokiri Sword */
	{
		z_matrix_translate_3f(0.0f, 220.0f, 0.0f, 1);
		z_matrix_scale_3f(-0.7f, -0.6f, -0.4f, 1);
		z_matrix_pitch(16384.0f, 1);
	}
	else if (en->equipped_sword == 2) /* Biggoron Sword */
	{
		z_matrix_translate_3f(200.0f, 350.0f, 0.0f, 1);
		z_matrix_scale_3f(-1.8f, -1.4f, -0.69f, 1);
		z_matrix_pitch(16384.0f, 1);
	}
	uint32_t local_14 = 0x14;
	float f_80AA046C[9] = {
			0.1f, 0.15f, 0.2f
		, 0.25f, 0.3f, 0.25f
		, 0.2f, 0.15f, 0.0f
	};
	float tube_scale;
	if ((en->inst01B8 >= 0.85f))
	{
		tube_scale = f_80AA046C[gl->gameplay_frames & 7];
		tube_scale *= 6.0f;
		uint32_t prim = (en->prim_alpha | 0xFFFFAA00);
		gDPSetPrimColor(xlu->p++, 0x00, 0x80, 0xFF, 0xFF, 0xAA, en->prim_alpha);
		local_14 = 0x28;
		gDPSetEnvColor(xlu->p++, 255, 100, 0, 128);
	}
	else
	{
		tube_scale = f_80AA046C[gl->gameplay_frames & 7];
		tube_scale += tube_scale;
		gDPSetPrimColor(xlu->p++, 0x00, 0x80, 0xAA, 0xFF, 0xFF, en->prim_alpha);
		gDPSetEnvColor(xlu->p++, 0, 100, 255, 128);
	}
	z_matrix_scale_3f(1.0f, tube_scale + 1.0f, tube_scale + 1.0f, 1);
	gSPMatrix(
		xlu->p++
		, z_matrix_alloc(gfx_ctxt, __FILE__)
		, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW
	);
	gSPSegment(xlu->p++
		, 9
		, z_rcp_gen_2_settilesize(
			gfx_ctxt
			, 0
			, (gl->gameplay_frames * 5) & 0xFF
			, 0
			, 0x20
			, 0x20
			, 1
			, (gl->gameplay_frames * 0x14) & 0xFF
			, (gl->gameplay_frames * local_14) & 0xFF
			, 8
			, 8
		)
	);
	gSPDisplayList(xlu->p++, DL_M_THUNDER_CHARGE); /* Spin Attack Charing Tube */
	z_debug_graph_write(dbg_gfx, gfx_ctxt, __FILE__, __LINE__);
}

static void func_80A9F314(z64_global_t* gl, float a1)
{
	external_func_800773A8(gl, a1, 850.0f, 0.2f, 0.0f);
}

static void func_80A9F350(entity_t* en, z64_global_t* gl) /* OK */
{
	z64_player_t* Link = zh_get_player(gl);

	if (Link->state_flags_2 << 14 < 0)
	{
		if (Link->sword_anim_index < 0x17)
		{
			z_sfx_play_system(NA_SE_IT_ROLLING_CUT, &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
			z_sfx_play_system(NA_SE_IT_SWORD_SWING_HARD, &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
		}
		z_actor_kill(&en->actor);
	}
	else
	{
		if ((Link->state_flags_1 & 0x1000) == 0)
		{
			z_actor_kill(&en->actor);
		}
	}
}

static void behavior(entity_t* en, z64_global_t* gl) /* OK */
{
	uint8_t _r;
	uint8_t _b;

	z64_actorfunc_t* execute_state = en->state;
	execute_state(en, gl);
	func_80A9F314(gl, en->inst01BC);

	_r = FLOOR(en->inst01AC * 255.0f);
	_r = (_r < 0) ? 0xFF : _r;

	_b = FLOOR(en->inst01AC * 100.0f);
	_b = (_b < 0) ? 0xFF : _b;

	z_lights_init_pos_0(
		&en->light_info
		, (en->actor).pos.x
		, (en->actor).pos.y
		, (en->actor).pos.z
		, _r, _r, _b
		, en->inst01AC * 800.0f
	);
}

static void destructor(entity_t* en, z64_global_t* gl) /* OK */
{
	if (en->inst01CA != 0)
	{
		external_func_800876C8(gl);
	}
	z_collider_cylinder_free(gl, &en->collider);
	func_80A9F314(gl, 0.0f);
	z_lights_kill(gl, &gl->lighting, en->light_node);
}

static void data_80A9F9B4(entity_t* en, z64_global_t* gl) /* OK */
{
	z64_player_t* Link = zh_get_player(gl);
	if (z_lib_approx_f(&en->inst01AC, 0.0f, 0.0625f) == 0)
	{
		z_lib_smooth_scale_max_min_f(&(en->actor).scale.x, en->damage_multiplier, 0.6f, 0.8f, 0);
		z_actor_set_scale(&en->actor, (en->actor).scale.x);
		(en->collider).dim.radius = (en->actor).scale.x * 25.0f;
		z_collider_cylinder_update(&en->actor, &en->collider);
		z_collider_hitbox(gl, &gl->hit_ctxt, &en->collider);
	}
	else
	{
		z_actor_kill(&en->actor);
	}

	if (en->inst01C4 != 0)
	{
		(en->actor).pos.x = (Link->field_0x908).x;
		en->inst01C4 -= 1;
		(en->actor).pos.z = (Link->field_0x908).z;
	}

	if (0.6f < en->inst01AC)
	{
		en->inst01B0 = 1.0f;
	}
	else
	{
		en->inst01B0 = (en->inst01AC * 1.6f);
	}

	func_80A9F938(en);
	if (external_func_800BFC84(gl) != 0)
	{
		z_actor_kill(&en->actor);
	}
}

static void constructor(entity_t* en, z64_global_t* gl) /* 1 internal, 8 external, 183 lines */
{
	z64_player_t* Link = zh_get_player(gl);

	z_collider_cylinder_alloc(gl, &en->collider);
	z_collider_cylinder_init(gl, &en->collider, &en->actor, &thunder_collision);
	en->equipped_sword = (en->actor).variable - 1;
	z_lights_init_pos_0(
	  &en->light_info
	  , (en->actor).pos.x
	  , (en->actor).pos.y
	  , (en->actor).pos.z
	  , 255, 255, 255
	  , 0
	);
	en->light_node = z_lights_insert(gl, &gl->lighting, &en->light_info);
	(en->collider).dim.radius = 0;
	(en->collider).dim.height = 40;
	(en->collider).dim.y_shift = -20;
	en->inst01C4 = 8;
	en->inst01B4 = 0.0f;
	(en->actor).pos.x = (Link->field_0x908).x;
	(en->actor).pos.y = (Link->field_0x908).y;
	(en->actor).pos.z = (Link->field_0x908).z;
	en->inst01AC = 0.0f;
	en->inst01BC = 0.0f;
	(en->actor).rot.y = (Link->actor).rot.y + ROT16(-180);
	z_actor_set_scale(&en->actor, 0.1f);
	en->inst01CA = 0;

	if (Link->state_flags_2 << 14 < 0)
	{
	    if (((AVAL(Z64GL_SAVE_CONTEXT, uint8_t, 0x3A) == 0) || (AVAL(Z64GL_SAVE_CONTEXT, uint8_t, 0x13F0) != 0))
	    || ((((en->actor).variable & 0xFF00 >> 8) != 0)
	    && (z_parameter_subtract_magic(gl, (((en->actor).variable & 0xFF00) >> 8), 0) == 0))) {
	       z_sfx_play_system(NA_SE_IT_ROLLING_CUT, &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
	       z_sfx_play_system(NA_SE_IT_SWORD_SWING_HARD, &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
	       z_actor_kill(&en->actor);
	       return;
	    }
	    Link->state_flags_2 &= 0xFFFDFFFF;
	    en->inst01CA = 1;
	    en->attack_level = 1;
	    (en->collider).body.toucher.flags = small_spin_toucher_flags[en->equipped_sword];
	    if (en->equipped_sword == 1)
	      en->damage_multiplier = 2;
	    else
	      en->damage_multiplier = 4;
	    set_state(en, (z64_actorfunc_t*)data_80A9F9B4);
	    en->inst01C4 = 8;
	    z_sfx_play_system(NA_SE_IT_ROLLING_CUT, &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
	    en->inst01AC = 1.0f;
	}
	else
	{
	  set_state(en, (z64_actorfunc_t*)data_80A9F408);
	}
	(en->actor).attached_b = 0x0;
}

static void data_80A9F408(entity_t* en, z64_global_t* gl) /* OK */
{
	z64_player_t* Link = zh_get_player(gl);
	z64_actor_t* z_eff_dust = (en->actor).attached_b;
	int16_t upper_var = ((en->actor).variable & 0xFF00) >> 8;
	en->inst01B8 = Link->field_0x858;
	(en->actor).pos.x = (Link->field_0x908).x;
	(en->actor).pos.y = (Link->field_0x908).y;
	(en->actor).pos.z = (Link->field_0x908).z;
	(en->actor).rot.y = (Link->actor).rot.y + ROT16(180);

	if (!en->inst01CA && (Link->field_0x858 >= 0.1f))
	{
		if ((AVAL(Z64GL_SAVE_CONTEXT, uint16_t, 0x13F0)) || ((upper_var) && (!(z_parameter_subtract_magic(gl, upper_var, 4)))))
		{
			func_80A9F350(en, gl);
			set_state(en, (z64_actorfunc_t*)func_80A9F350);
			en->prim_alpha = 0;
			en->inst01BC = 0.0f;
			en->inst01AC = 0.0f;
			return;
		}
		en->inst01CA = 1.0f;
	}

	if (Link->field_0x858 >= 0.1f)
	{
		uint8_t _rumble = (uint8_t)(Link->field_0x858 * 150.0f);
		external_func_800AA000(0.0f, _rumble, 0x02, _rumble);
	}

	if ((Link->state_flags_2 << 0x0E) < 0)
	{
		if ((z_eff_dust) && (z_eff_dust->main_proc))
		{
			z_eff_dust->attached_a = 0x0;
		}

		if (Link->field_0x858 <= 0.15f)
		{
			if ((Link->field_0x858 >= 0.1f) && (Link->sword_anim_index > 0x17))
			{
				vec3f_t* sfx_pos = &(Link->actor).unk_0xE4;
				z_sfx_play_system(NA_SE_IT_ROLLING_CUT, sfx_pos, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
				z_sfx_play_system(NA_SE_IT_SWORD_SWING_HARD, sfx_pos, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
			}
			z_actor_kill(&en->actor);
		}
		else
		{
			Link->state_flags_2 &= 0xFFFDFFFF;
			if (upper_var)
			{
				AVAL(Z64GL_SAVE_CONTEXT, uint16_t, 0x13F0) = 1;
			}

			if (Link->field_0x858 < 0.85f)
			{
				en->attack_level = 1;
				(en->collider).body.toucher.flags = small_spin_toucher_flags[en->equipped_sword];
				if (en->equipped_sword == 1)
				{
					en->damage_multiplier = 2;
				}
				else
				{
					en->damage_multiplier = 4;
				}
			}
			else
			{
				en->attack_level = 0;
				(en->collider).body.toucher.flags = big_spin_toucher_flags[en->equipped_sword];
				if (en->equipped_sword == 1)
				{
					en->damage_multiplier = 4;
				}
				else
				{
					en->damage_multiplier = 8;
				}
			}
			set_state(en, (z64_actorfunc_t*)data_80A9F9B4);
			en->inst01C4 = 8;
			z_sfx_play_system(release_sfx[en->attack_level], &(Link->actor).unk_0xE4, 4, (float*)0x801333E0, (float*)0x801333E0, (float*)0x801333E8);
			en->inst01AC = 1.0f;
		}
	}
	else
	{
		if (!(Link->state_flags_1 & 0x1000))
		{
			z_eff_dust = (en->actor).attached_b;
			if (z_eff_dust)
			{
				z_eff_dust->attached_a = 0;
			}
			z_actor_kill(&en->actor);
		}
		else
		{
			if (Link->field_0x858 > 0.15f)
			{
				z_eff_dust = (en->actor).attached_b;
				en->prim_alpha = 255;

				if (!z_eff_dust)
				{
					z_actor_spawn_attached(
						gl->actor_ctxt
						, &en->actor
						, gl
						, 0x0101
						, (en->actor).pos.x, (en->actor).pos.y, (en->actor).pos.z
						, 0, (en->actor).rot.y, 0
						, (en->equipped_sword + 2)
					);
				}
				en->inst01BC += ((Link->field_0x858 - 0.15f) * 1.5f - en->inst01BC) * 0.5f;
			}
			else
			{
				if (Link->field_0x858 > 0.1f)
				{
					en->prim_alpha = ((Link->field_0x858 - 0.1f) * 255.0f) * 20.0f;
					en->inst01AC = (Link->field_0x858 - 0.1f) * 10.0f;
				}
				else
				{
					en->prim_alpha = 0;
				}
			}

			if (Link->field_0x858 > 0.85)
			{
				external_func_800F4254(&(Link->actor).unk_0xE4, 2);
			}
			else
			{
				if (Link->field_0x858 > 0.15f)
				{
					external_func_800F4254(&(Link->actor).unk_0xE4, 1);
				}
				else
				{
					if (Link->field_0x858 > 0.1f)
					{
						external_func_800F4254(&(Link->actor).unk_0xE4, 0);
					}
				}
			}
			if (external_func_800BFC84(gl))
			{
				z_actor_kill(&en->actor);
			}
		}
	}
}

const z64_actor_init_t init_vars = {
	.number = 0x0057,
	.type = 0x07,
	.room = 0x00,
	.flags = 0x00000000,
	.object = 0x0001,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = constructor,
	.dest = destructor,
	.main = behavior,
	.draw = draw
};
