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
	uint8_t pad_00[16];
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
void dest(entity_t *en, z64_global_t *gl); /* rewritten, NEED TO CONFIRM */
void func_80A9DD50(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
void init(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
void draw(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED */
void light_play_flame(entity_t *en, z64_global_t *gl); /* rewritten, CONFIRMED*/
void light_play_candle(entity_t *en, z64_global_t *gl); /* 1 internal, 6 external, 291 lines */


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

const uint32_t data_80A9E8F8[] =
{
	0x3F1A36E2,
	0xEB1C432D
};
const uint32_t data_80A9E900[] =
{
	0x3DCCCCCD
};
const uint32_t data_80A9E904[] =
{
	0x3DCCCCCD
};
const uint32_t data_80A9E908[] =
{
	0x3F1A36E2,
	0xEB1C432D
};


/*** functions ***/
void dest(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);

	external_func_8007A7C4(gl, &gl->lighting, en->inst_0150);
}

void func_80A9DD50(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lfunc_80A9DD50: \n"
	);

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

void init(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80A9DB40: \n"
	);

	int iVar3;

	iVar3 = ((en->actor).variable < 0) ? 1 : 0x28;
	if ((AVAL(SAVE_CONTEXT, uint32_t, 0x135C)) == 3)
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
		(en->actor).main_proc = &light_play_candle;
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 8 external, 224 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);
	#define GFX_POLY_XLU ZQDL(gl, poly_xlu)
	z64_disp_buf_t *xlu = &GFX_POLY_XLU;
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

void light_play_flame(entity_t *en, z64_global_t *gl)
{
    asm(
        ".set at        \n"
        ".set reorder   \n"
        ".Lplay: \n"
    );

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
    func_80A9DD50(en, gl);
}

void light_play_candle(entity_t *en, z64_global_t *gl) /* 1 internal, 6 external, 291 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80A9E074: \n"
	);
	asm(
		"addiu           $sp,$sp,-64                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,68($sp)                            \n"
		"lh              $t6,28($a0)                            \n"
		"lui             $t9,%hi(data_80A9E840)                 \n"
		"addiu           $t9,$t9,%lo(data_80A9E840)             \n"
		"andi            $t7,$t6,0xf                            \n"
		"sll             $t8,$t7,3                              \n"
		"addu            $t0,$t8,$t9                            \n"
		"sw              $t0,56($sp)                            \n"
		"lbu             $t1,7($t0)                             \n"
		"or              $s0,$a0,$zero                          \n"
		"lui             $at,0x4F80                             \n"
		"mtc1            $t1,$f4                                \n"
		"bgez            $t1,.L000023                           \n"
		"cvt.s.w         $f6,$f4                                \n"
		"mtc1            $at,$f8                                \n"
		"nop                                                    \n"
		"add.s           $f6,$f6,$f8                            \n"
		".L000023:                                              \n"
		"lui             $at,%hi(data_80A9E8F8)                 \n"
		"ldc1            $f16,%lo(data_80A9E8F8)($at)           \n"
		"cvt.d.s         $f10,$f6                               \n"
		"lwc1            $f4,80($s0)                            \n"
		"mul.d           $f18,$f10,$f16                         \n"
		"lw              $a0,68($sp)                            \n"
		"cvt.d.s         $f8,$f4                                \n"
		"div.d           $f6,$f8,$f18                           \n"
		"cvt.s.d         $f10,$f6                               \n"
		"swc1            $f10,48($sp)                           \n"
		"lh              $v0,28($s0)                            \n"
		"andi            $t2,$v0,0x800                          \n"
		"beq             $t2,$zero,.L000024                     \n"
		"andi            $a1,$v0,0x3f0                          \n"
		"andi            $a1,$v0,0x3f0                          \n"
		"sra             $a1,$a1,4                              \n"
		"jal             0x8002CB40                 \n"
		"lw              $a0,68($sp)                            \n"
		"beq             $v0,$zero,.L000025                     \n"
		"lwc1            $f16,48($sp)                           \n"
		"lui             $a2,0x3D4C                             \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"addiu           $a0,$sp,48                             \n"
		"jal             0x80077A00                 \n"
		"lui             $a1,0x3F80                             \n"
		"beq             $zero,$zero,.L000026                   \n"
		"lw              $t3,56($sp)                            \n"
		".L000025:                                              \n"
		"lui             $at,%hi(data_80A9E900)                 \n"
		"lwc1            $f4,%lo(data_80A9E900)($at)            \n"
		"addiu           $a0,$sp,48                             \n"
		"addiu           $a1,$zero,0                            \n"
		"c.lt.s          $f16,$f4                               \n"
		"lui             $a2,0x3D4C                             \n"
		"bc1f            .L000027                               \n"
		"nop                                                    \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8002D62C                 \n"
		"addiu           $a1,$zero,0                            \n"
		"beq             $zero,$zero,.L000028                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000027:                                              \n"
		"jal             0x80077A00                 \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"beq             $zero,$zero,.L000026                   \n"
		"lw              $t3,56($sp)                            \n"
		".L000024:                                              \n"
		"jal             0x8002CB40                 \n"
		"sra             $a1,$a1,4                              \n"
		"beq             $v0,$zero,.L000029                     \n"
		"addiu           $a0,$sp,48                             \n"
		"lui             $at,%hi(data_80A9E904)                 \n"
		"lwc1            $f18,%lo(data_80A9E904)($at)           \n"
		"lwc1            $f8,48($sp)                            \n"
		"addiu           $a0,$sp,48                             \n"
		"addiu           $a1,$zero,0                            \n"
		"c.lt.s          $f8,$f18                               \n"
		"lui             $a2,0x3D4C                             \n"
		"bc1f            .L000030                               \n"
		"nop                                                    \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8002D62C                 \n"
		"addiu           $a1,$zero,0                            \n"
		"beq             $zero,$zero,.L000028                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000030:                                              \n"
		"jal             0x80077A00                 \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"beq             $zero,$zero,.L000026                   \n"
		"lw              $t3,56($sp)                            \n"
		".L000029:                                              \n"
		"lui             $a2,0x3D4C                             \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"jal             0x80077A00                 \n"
		"lui             $a1,0x3F80                             \n"
		"lw              $t3,56($sp)                            \n"
		".L000026:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lbu             $t4,7($t3)                             \n"
		"mtc1            $t4,$f6                                \n"
		"bgez            $t4,.L000031                           \n"
		"cvt.s.w         $f10,$f6                               \n"
		"lui             $at,0x4F80                             \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"add.s           $f10,$f10,$f16                         \n"
		".L000031:                                              \n"
		"lui             $at,%hi(data_80A9E908)                 \n"
		"ldc1            $f8,%lo(data_80A9E908)($at)            \n"
		"cvt.d.s         $f4,$f10                               \n"
		"lwc1            $f6,48($sp)                            \n"
		"mul.d           $f18,$f4,$f8                           \n"
		"cvt.d.s         $f16,$f6                               \n"
		"mul.d           $f10,$f18,$f16                         \n"
		"cvt.s.d         $f4,$f10                               \n"
		"mfc1            $a1,$f4                                \n"
		"jal             0x8002D62C                 \n"
		"nop                                                    \n"
		"jal             0x800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x3F00                             \n"
		"mtc1            $at,$f12                               \n"
		"lw              $t5,56($sp)                            \n"
		"lui             $at,0x4F80                             \n"
		"mul.s           $f8,$f0,$f12                           \n"
		"lbu             $t6,0($t5)                             \n"
		"addiu           $a0,$s0,340                            \n"
		"mtc1            $t6,$f6                                \n"
		"add.s           $f2,$f8,$f12                           \n"
		"bgez            $t6,.L000032                           \n"
		"cvt.s.w         $f18,$f6                               \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"add.s           $f18,$f18,$f16                         \n"
		".L000032:                                              \n"
		"mul.s           $f10,$f18,$f2                          \n"
		"addiu           $a1,$zero,1                            \n"
		"lui             $at,0x4F00                             \n"
		"cfc1            $t7,$f31                               \n"
		"ctc1            $a1,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f4,$f10                               \n"
		"cfc1            $a1,$f31                               \n"
		"nop                                                    \n"
		"andi            $a1,$a1,0x78                           \n"
		"beql            $a1,$zero,.L000033                     \n"
		"mfc1            $a1,$f4                                \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $a1,$zero,1                            \n"
		"sub.s           $f4,$f10,$f4                           \n"
		"ctc1            $a1,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f4,$f4                                \n"
		"cfc1            $a1,$f31                               \n"
		"nop                                                    \n"
		"andi            $a1,$a1,0x78                           \n"
		"bne             $a1,$zero,.L000034                     \n"
		"nop                                                    \n"
		"mfc1            $a1,$f4                                \n"
		"lui             $at,0x8000                             \n"
		"beq             $zero,$zero,.L000035                   \n"
		"or              $a1,$a1,$at                            \n"
		".L000034:                                              \n"
		"beq             $zero,$zero,.L000035                   \n"
		"addiu           $a1,$zero,-1                           \n"
		"mfc1            $a1,$f4                                \n"
		".L000033:                                              \n"
		"nop                                                    \n"
		"bltz            $a1,.L000034                           \n"
		"nop                                                    \n"
		".L000035:                                              \n"
		"lbu             $t8,1($t5)                             \n"
		"ctc1            $t7,$f31                               \n"
		"andi            $a1,$a1,0xff                           \n"
		"mtc1            $t8,$f8                                \n"
		"lui             $at,0x4F80                             \n"
		"bgez            $t8,.L000036                           \n"
		"cvt.s.w         $f6,$f8                                \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"add.s           $f6,$f6,$f16                           \n"
		".L000036:                                              \n"
		"mul.s           $f18,$f6,$f2                           \n"
		"addiu           $a2,$zero,1                            \n"
		"lui             $at,0x4F00                             \n"
		"cfc1            $t9,$f31                               \n"
		"ctc1            $a2,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f10,$f18                              \n"
		"cfc1            $a2,$f31                               \n"
		"nop                                                    \n"
		"andi            $a2,$a2,0x78                           \n"
		"beql            $a2,$zero,.L000037                     \n"
		"mfc1            $a2,$f10                               \n"
		"mtc1            $at,$f10                               \n"
		"addiu           $a2,$zero,1                            \n"
		"sub.s           $f10,$f18,$f10                         \n"
		"ctc1            $a2,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f10,$f10                              \n"
		"cfc1            $a2,$f31                               \n"
		"nop                                                    \n"
		"andi            $a2,$a2,0x78                           \n"
		"bne             $a2,$zero,.L000038                     \n"
		"nop                                                    \n"
		"mfc1            $a2,$f10                               \n"
		"lui             $at,0x8000                             \n"
		"beq             $zero,$zero,.L000039                   \n"
		"or              $a2,$a2,$at                            \n"
		".L000038:                                              \n"
		"beq             $zero,$zero,.L000039                   \n"
		"addiu           $a2,$zero,-1                           \n"
		"mfc1            $a2,$f10                               \n"
		".L000037:                                              \n"
		"nop                                                    \n"
		"bltz            $a2,.L000038                           \n"
		"nop                                                    \n"
		".L000039:                                              \n"
		"lbu             $t0,2($t5)                             \n"
		"ctc1            $t9,$f31                               \n"
		"andi            $a2,$a2,0xff                           \n"
		"mtc1            $t0,$f4                                \n"
		"lui             $at,0x4F80                             \n"
		"bgez            $t0,.L000040                           \n"
		"cvt.s.w         $f8,$f4                                \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"add.s           $f8,$f8,$f16                           \n"
		".L000040:                                              \n"
		"mul.s           $f6,$f8,$f2                            \n"
		"addiu           $a3,$zero,1                            \n"
		"lui             $at,0x4F00                             \n"
		"cfc1            $t1,$f31                               \n"
		"ctc1            $a3,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f18,$f6                               \n"
		"cfc1            $a3,$f31                               \n"
		"nop                                                    \n"
		"andi            $a3,$a3,0x78                           \n"
		"beql            $a3,$zero,.L000041                     \n"
		"mfc1            $a3,$f18                               \n"
		"mtc1            $at,$f18                               \n"
		"addiu           $a3,$zero,1                            \n"
		"sub.s           $f18,$f6,$f18                          \n"
		"ctc1            $a3,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f18,$f18                              \n"
		"cfc1            $a3,$f31                               \n"
		"nop                                                    \n"
		"andi            $a3,$a3,0x78                           \n"
		"bne             $a3,$zero,.L000042                     \n"
		"nop                                                    \n"
		"mfc1            $a3,$f18                               \n"
		"lui             $at,0x8000                             \n"
		"beq             $zero,$zero,.L000043                   \n"
		"or              $a3,$a3,$at                            \n"
		".L000042:                                              \n"
		"beq             $zero,$zero,.L000043                   \n"
		"addiu           $a3,$zero,-1                           \n"
		"mfc1            $a3,$f18                               \n"
		".L000041:                                              \n"
		"nop                                                    \n"
		"bltz            $a3,.L000042                           \n"
		"nop                                                    \n"
		".L000043:                                              \n"
		"lui             $at,0x4396                             \n"
		"mtc1            $at,$f10                               \n"
		"ctc1            $t1,$f31                               \n"
		"lwc1            $f4,48($sp)                            \n"
		"andi            $a3,$a3,0xff                           \n"
		"mul.s           $f16,$f10,$f4                          \n"
		"trunc.w.s       $f8,$f16                               \n"
		"mfc1            $t3,$f8                                \n"
		"jal             0x80079E58                 \n"
		"sw              $t3,16($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80A9DD50                          \n"
		"lw              $a1,68($sp)                            \n"
		"lh              $t4,28($s0)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"bltzl           $t4,.L000028                           \n"
		"lw              $ra,36($sp)                            \n"
		"jal             0x8002F828                 \n"
		"addiu           $a1,$zero,8241                         \n"
		"lw              $ra,36($sp)                            \n"
		".L000028:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,64                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x07,
	.room = 0x00,
	.flags = 0x00000000,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = light_play_flame,
	.draw = draw
};
