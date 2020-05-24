/************
 * z_en_light.c faithfully rewritten by CrookedPoe <nickjs.site>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit c0ef798a73e95211ce2db1b1ced2439b00f45ff4
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>
#include "z_en_light.h"

/*** instance structure ***/
typedef struct {
	z64_actor_t actor;
	/* uint8_t debug_ex[16]; */
	uint8_t inst_014C;
	z64_light_node_t* light_node;
	z64_lightinfo_t light_info;
	uint16_t inst_0158;
	uint16_t inst_015A;
	uint16_t inst_015C;
	int16_t inst_015E;
	int16_t inst_0160;
} entity_t; /* 0164 */


/*** function prototypes ***/
static void destructor(entity_t *en, z64_global_t *gl); /* OK */
static void billboard(entity_t *en, z64_global_t *gl); /* OK */
static void constructor(entity_t *en, z64_global_t *gl); /* OK */
static void draw(entity_t *en, z64_global_t *gl); /* OK */
static void behavior(entity_t *en, z64_global_t *gl); /* OK */
static void behavior_candle(entity_t *en, z64_global_t *gl); /* OK */


/*** variables ***/
uint8_t data_80A9E840[] =
{
0xFF, 0xC8, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x4B,
0xFF, 0xC8, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x4B,
0x00, 0xAA, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x4B,
0xAA, 0xFF, 0x00, 0xFF, 0x00, 0x96, 0x00, 0x4B,
0xFF, 0xC8, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x28,
0xFF, 0xC8, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x4B,
0xAA, 0xFF, 0x00, 0xFF, 0x00, 0x96, 0x00, 0x4B,
0x00, 0xAA, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x4B,
0xFF, 0x00, 0xAA, 0xFF, 0xC8, 0x00, 0x00, 0x4B,
0xFF, 0xFF, 0xAA, 0xFF, 0xFF, 0x32, 0x00, 0x4B,
0xFF, 0xFF, 0xAA, 0xFF, 0xFF, 0xFF, 0x00, 0x4B,
0xFF, 0xFF, 0xAA, 0xFF, 0x64, 0xFF, 0x00, 0x4B,
0xFF, 0xAA, 0xFF, 0xFF, 0xFF, 0x00, 0x64, 0x4B,
0xFF, 0xAA, 0xFF, 0xFF, 0x64, 0x00, 0xFF, 0x4B,
0xAA, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x4B,
0xAA, 0xFF, 0xFF, 0xFF, 0x00, 0x96, 0xFF, 0x4B
};

/*** functions ***/
static void destructor(entity_t *en, z64_global_t *gl)
{
	z_lights_kill(gl, &gl->lighting, en->light_node);
}

static void billboard(entity_t *en, z64_global_t *gl)
{
	int16_t _rot = external_func_8005A9F4(gl->camera.pointer[0]);
	z64_actor_t *at = (en->actor).attached_a;

	(en->actor).rot.y = (_rot - ROT16(180));
	if (at)
	{
		z_lib_vec3f_copy(&(en->actor).pos, &at->pos);
		(en->actor).pos.y += 17.0f;
	}
	en->inst_014C += 1;
}

static void constructor(entity_t *en, z64_global_t *gl)
{
	int iVar3;

	iVar3 = ((en->actor).variable < 0) ? 1 : 0x28;
	if ((AVAL(Z64GL_SAVE_CONTEXT, uint32_t, 0x135C)) == 3)
	{
		z_lights_init_pos_0(
			&en->light_info
			, (en->actor).pos.x
			, (int16_t)((en->actor).pos.y + iVar3) & 0xFFFF
			, (en->actor).pos.z
			, 255, 255, 180
			, 255
		);
	}
	else
	{
		z_lights_init_pos_2(
			&en->light_info
			, (en->actor).pos.x
			, (int16_t)((en->actor).pos.y + iVar3) & 0xFFFF
			, (en->actor).pos.z
			, 255, 255, 180
			, 255
		);
	}

	en->light_node = z_lights_insert(gl, &gl->lighting, &en->light_info);

	float scale = (data_80A9E840[(((en->actor).variable & 0x000F) * 8) + 7]) * 0.0001f;
	z_actor_set_scale(&en->actor, scale);

	en->inst_014C = math_rand_zero_one() * 255.0f;
	if ((en->actor).variable & 0x0400 != 0)
		(en->actor).main_proc = (z64_actorfunc_t*)behavior_candle;
}

static void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 8 external, 224 lines */
{
	z64_disp_buf_t *xlu = &ZQDL(gl, poly_xlu);
	z64_gfx_t *gfx_ctxt = (gl->common).gfx_ctxt;

	uint32_t dlist;
	uint8_t *color_variables;
	color_variables = data_80A9E840 + (((en->actor).variable & 0x000F) << 3);

	/* Draw Flame Display List */
	if ((en->actor).variable < 0)
	{
		dlist = DL_FLAME_CANDLE;
		Gfx* timg_scroll = z_rcp_gen_2_settilesize(
			gfx_ctxt
			, 0
			, 0
			, 0
			, 0x10
			, 0x20
			, 1
			, (en->inst_014C & 0x1F) << 1
			, (en->inst_014C * -6) & 0x7F
			, 0x10
			, 0x20
		);

		/* Initialize Segment 0x08 for Display List */
		gMoveWd(xlu->p++, G_MW_SEGMENT, G_MWO_SEGMENT_8, timg_scroll);
		/* Initialize Primitive Color (minlevel, lodfrac, r, g, b, a) */
		gDPSetPrimColor(xlu->p++, 0xC0, 0xC0, 0xFF, 0xC8, 0x00, 0x00);
		/* Initialize Environment Color (r, g, b, a) */
		gDPSetEnvColor(xlu->p++, 255, 0, 0, 0);
	}
	else
	{
		dlist = DL_EN_LIGHT_FLAME;
		Gfx* timg_scroll = z_rcp_gen_2_settilesize(
			gfx_ctxt
			, 0
			, 0
			, 0
			, 0x20
			, 0x40
			, 1
			, 0
			, (en->inst_014C * -20) & 0x01FF
			, 0x20
			, 0x80
		);

		/* Initialize Segment 0x08 for Display List */
		gMoveWd(xlu->p++, G_MW_SEGMENT, G_MWO_SEGMENT_8, timg_scroll);
		/* Initialize Primitive Color (minlevel, lodfrac, r, g, b, a) */
		gDPSetPrimColor(xlu->p++, 0x80, 0x80, color_variables[0], color_variables[1], color_variables[2], color_variables[3]);
		/* Initialize Environment Color (r, g, b, a) */
		gDPSetEnvColor(xlu->p++, color_variables[4], color_variables[5], color_variables[6], 0);
	}

	/* Rotate Flame on Y Axis -- Billboarding */
	int16_t _rot = external_func_8005A9F4(gl->camera.pointer[0]);
	z_matrix_yaw((int16_t)((_rot - ((en->actor).rot.y + ROT16(180))) * 0.0001f), 1);

	if ((en->actor).variable & 1)
		z_matrix_yaw(PI, 1);

	z_matrix_scale_3f(1.0f, 1.0f, 1.0f, 1);
	z_cheap_proc_draw_xlu(gl, dlist);
}

static void behavior(entity_t *en, z64_global_t *gl)
{
	int var = ((en->actor).variable & 0x000F) << 3;
	int16_t glow_radius = ((en->actor).variable < 0) ? 100 : 300;
	rgb8_t glow_color;

	/* Initialize Flame/Glow Color and Flickering*/
    float opacity = (math_rand_zero_one() * 0.5f + 0.5f); /* This is randomized to get a more natural flickering effect */

	glow_color.r = (data_80A9E840[var]) * opacity;
	glow_color.g = (data_80A9E840[var + 1]) * opacity;
	glow_color.b = (data_80A9E840[var + 2]) * opacity;

	if (glow_color.r < 0) glow_color.r = 0xFF;
	if (glow_color.g < 0) glow_color.g = 0xFF;
	if (glow_color.b < 0) glow_color.b = 0xFF;

    z_lights_set_rgb_radius(
		&en->light_info
		, glow_color.r, glow_color.g, glow_color.b
		, glow_radius
	);
    billboard(en, gl);
	if ((en->actor).variable >= 0)
		z_actor_play_sfx2(&en->actor, NA_SE_EV_TORCH);
}

static void behavior_candle(entity_t *en, z64_global_t *gl)
{
	uint32_t uVar1 = SEXT24((en->actor).variable);
	int32_t var = ((en->actor).variable & 0x000F) << 3;
	rgb8_t color;
	int32_t switch_flag = flag_get_switch(gl, ((uVar1 & 0x3F0) >> 4));
	float radius = (en->actor).scale.x / ((data_80A9E840)[var + 7] * 0.0001f);

	if ((uVar1 & 0x800) == 0)
	{
		if (switch_flag == 0)
			z_lib_approx_f(&(en->actor).scale.x, 1.0f, 0.05f);
		else
		{
			if (radius < 0.1f)
			{
				z_actor_set_scale(&en->actor, 0.0f);
				return;
			}
			z_lib_approx_f(&(en->actor).scale.x, 1.0f, 0.05f);
		}
	}
	else
	{
		if (switch_flag == 0)
		{
			if (radius < 0.1f)
			{
				z_actor_set_scale(&en->actor, 0.0f);
				return;
			}
			z_lib_approx_f(&(en->actor).scale.x, 1.0f, 0.05f);
		}
		else
			z_lib_approx_f(&(en->actor).scale.x, 1.0f, 0.05f);
	}

	z_actor_set_scale(&en->actor, 75 * 0.0001f * radius);
	float opacity = (math_rand_zero_one() * 0.5f + 0.5f); /* This is randomized to get a more natural flickering effect */

	color.r = (data_80A9E840[var]) * opacity;
	color.g = (data_80A9E840[var + 1]) * opacity;
	color.b = (data_80A9E840[var + 2]) * opacity;

	if (color.r < 0) color.r = 0xFF;
	if (color.g < 0) color.g = 0xFF;
	if (color.b < 0) color.b = 0xFF;

	z_lights_set_rgb_radius(
		&en->light_info
		, color.r, color.g, color.b
		, radius * 300
	);
	billboard(en, gl);

	if ((en->actor).variable >= 0)
		z_actor_play_sfx2(&en->actor, NA_SE_EV_TORCH);
}

z64_actor_init_t init_vars = {
	.number = 0x0008,
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
