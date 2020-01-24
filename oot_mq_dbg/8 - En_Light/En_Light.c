#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

/*** actor ***/
#define OBJ_ID 1 /* gameplay_keep */

/*** object ***/
#define DL_FLAME_CANDLE 0x05000440 /* gameplay_field/dangeon_keep */
#define DL_FLAME 0x0404D4E0 /* gameplay_keep */

/*** sounds ***/
#define NA_SE_EV_TORCH 0x2031

/*** instance structure ***/
typedef struct {
	z64_actor_t actor;
	/*uint8_t debug_extended[16];*/
	uint8_t inst_014C;
	uint32_t *inst_0150;
	uint32_t inst_0154;
	uint16_t inst_0158;
	uint16_t inst_015A;
	uint16_t inst_015C;
	int16_t inst_015E;
	int16_t inst_0160;
} entity_t; /* 0164 */


/*** function prototypes ***/
static void dest_80A9DD20(entity_t *en, z64_global_t *gl); /* rewritten, NEED TO CONFIRM */
static void local_80A9DD50(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
static void init_80A9DB40(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
static void draw_80A9E4AC(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
static void main_80A9DDD0(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED*/
static void local_80A9E074(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */


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
static void dest_80A9DD20(entity_t *en, z64_global_t *gl)
{
	external_func_8007A7C4(gl, &gl->lighting, en->inst_0150);
}

static void local_80A9DD50(entity_t *en, z64_global_t *gl)
{
	int16_t _rot = external_func_8005A9F4(AVAL(GLOBAL_CONTEXT, uint32_t, 0x0790));
	z64_actor_t *at = (en->actor).attached_a;

	(en->actor).rot_2.y = (_rot - 0x8000);
	if (at != 0x0)
	{
		math_vec3f_copy(&(en->actor).pos_2, &at->pos_2);
		(en->actor).pos_2.y += 17.0f;
	}
	en->inst_014C += 1;
}

static void init_80A9DB40(entity_t *en, z64_global_t *gl)
{
	int iVar3;

	iVar3 = ((en->actor).variable < 0) ? 1 : 0x28;
	if ((AVAL(Z64GL_SAVE_CONTEXT, uint32_t, 0x135C)) == 3)
	{
		external_func_80079D8C(
				&en->inst_0154
			, (int)(en->actor).pos_2.x
			, ((int)((en->actor).pos_2.y + iVar3) * 0x10000 >> 0x10)
			, (int)(en->actor).pos_2.z
			, 0xB4
			, 0xFFFFFFFF
		);
	}
	else
	{
		external_func_80079DF0(
				&en->inst_0154
			, (int)(en->actor).pos_2.x
			, ((int)((en->actor).pos_2.y + iVar3) * 0x10000 >> 0x10)
			, (int)(en->actor).pos_2.z
			, 0xB4
			, 0xFFFFFFFF
		);
	}

	en->inst_0150 = external_func_8007A764(gl, &gl->lighting, (uint32_t)&en->inst_0154);
	float scale = (data_80A9E840[(((en->actor).variable & 0x000F) * 8) + 7]) * 0.0001f;
	actor_set_scale(&en->actor, scale);
	en->inst_014C = math_rand_zero_one() * 255.0f;
	if ((en->actor).variable & 0x0400 != 0)
		(en->actor).main_proc = &local_80A9E074;
}

static void draw_80A9E4AC(entity_t *en, z64_global_t *gl) /* 0 internal, 8 external, 224 lines */
{
	z64_disp_buf_t *xlu = &ZQDL(gl, poly_xlu);
	z64_gfx_t *gfx_ctxt;
	gfx_ctxt = (gl->common).gfx_ctxt;
	uint32_t dlist;
	uint8_t *color_variables;
	color_variables = data_80A9E840 + (((en->actor).variable & 0x000F) << 3);
	/* Draw Flame Display List */
	if ((en->actor).variable < 0)
	{
		dlist = DL_FLAME_CANDLE;
		uint32_t timg_scroll = f3dzex_gen_settilesize(
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
		dlist = DL_FLAME;
		uint32_t timg_scroll = f3dzex_gen_settilesize(
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
	int16_t _rot = external_func_8005A9F4(AVAL(GLOBAL_CONTEXT, uint32_t, 0x0790));
	external_func_800D0D20(((((_rot - (en->actor).rot_2.y) + 0x8000) * 0x10000 >> 0x10) * 0.0001f), 1);
	if (((en->actor).variable & 1) != 0)
		external_func_800D0D20(3.1415927f, 1);
	matrix_scale3f(1.0f, 1.0f, 1.0f, 1);
	draw_dlist_xlu(gl, dlist);
}

static void main_80A9DDD0(entity_t *en, z64_global_t *gl)
{
		int var = ((en->actor).variable & 0x000F) << 3;
		/* Initialize Flame Glow Size and Burning Sound */
		int glow_size;
		if ((en->actor).variable < 0)
			glow_size = 100;
		else
		{
			glow_size = 300;
			sound_play_actor2(&en->actor, NA_SE_EV_TORCH);
		}

		/* Initialize Flame/Glow Color and Flickering*/
    float opacity = (math_rand_zero_one() * 0.5f + 0.5f); /* This is randomized to get a more natural flickering effect */

    int32_t red = (data_80A9E840[var]) * opacity;
    if (red < 0)
			red = 0xFFFFFFFF;

    int32_t green = (data_80A9E840[var + 1]) * opacity;
    if (green < 0)
			green = 0xFFFFFFFF;

    int32_t blue = (data_80A9E840[var + 2]) * opacity;
    if (blue < 0)
			blue = 0xFFFFFFFF;

    external_func_80079E58(&en->inst_0154, (red & 0xFF), (green & 0xFF), (blue & 0xFF), glow_size);
    local_80A9DD50(en, gl);
}

static void local_80A9E074(entity_t *en, z64_global_t *gl)
{
  uint32_t uVar1 = SEXT24((en->actor).variable);
  int32_t var = ((en->actor).variable & 0x000F) << 3;
  int32_t switch_flag = flag_get_switch(gl, ((uVar1 & 0x3F0) >> 4));
  float local_10 = (en->actor).scale.x / ((data_80A9E840)[var + 7] * 0.0001f);

  if ((uVar1 & 0x800) == 0)
  {
    if (switch_flag == 0)
      math_approxf(&(en->actor).scale.x, 1.0f, 0.05f);
    else
    {
      if (local_10 < 0.1f)
      {
        actor_set_scale(&en->actor, 0.0f);
        return;
      }
      math_approxf(&(en->actor).scale.x, 1.0f, 0.05f);
    }
  }
  else
  {
    if (switch_flag == 0)
    {
      if (local_10 < 0.1f)
      {
        actor_set_scale(&en->actor, 0.0f);
        return;
      }
      math_approxf(&(en->actor).scale.x, 1.0f, 0.05f);
    }
    else
      math_approxf(&(en->actor).scale.x, 1.0f, 0.05f);
  }

  actor_set_scale(&en->actor, 75 * 0.0001f * local_10);
  float opacity = (math_rand_zero_one() * 0.5f + 0.5f);

  int32_t red = (data_80A9E840[var]) * opacity;
  if (red < 0)
          red = 0xFFFFFFFF;

  int32_t green = (data_80A9E840[var + 1]) * opacity;
  if (green < 0)
          green = 0xFFFFFFFF;

  int32_t blue = (data_80A9E840[var + 2]) * opacity;
  if (blue < 0)
          blue = 0xFFFFFFFF;

  external_func_80079E58(&en->inst_0154, (red & 0xFF), (green & 0xFF), (blue & 0xFF), local_10 * 300.0f);
  local_80A9DD50(en, gl);

  if ((en->actor).variable >= 0)
    sound_play_actor2(&en->actor, NA_SE_EV_TORCH);
}

z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x07,
	.room = 0x00,
	.flags = 0x00000000,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init_80A9DB40,
	.dest = dest_80A9DD20,
	.main = main_80A9DDD0,
	.draw = draw_80A9E4AC
};
