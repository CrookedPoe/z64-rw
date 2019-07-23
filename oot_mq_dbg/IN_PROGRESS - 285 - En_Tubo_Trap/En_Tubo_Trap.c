#include <z64ovl/oot/debug.h>

#define OBJ_ID 3

/*** object ***/
#define DL_TUBO 0x05017870

typedef struct {
	z64_actor_t actor; 				/* 0x0000, 0x013C */
	uint8_t inst_unk[16]  	  /* 0x013C, 0x0010 */
	z64_actorfunc_t *playfunc /* 0x014C, 0x0004 */
	uint8_t inst_unk_2[16];   /* 0x0150, 0x0010 */
	z64_capsule_t capsule;		/* 0x0160, 0x004C */
} entity_t; /* 01AC */


/*** function prototypes ***/
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 13 lines */

void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 10 lines */
void func_80B259B8(void); /* 0 internal, 1 external, 25 lines */
void data_80B2629C(void); /* 0 internal, 1 external, 36 lines */
void data_80B2612C(void); /* 0 internal, 3 external, 95 lines */
void init(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 40 lines */
void func_80B25A18(void); /* 0 internal, 5 external, 160 lines */
void func_80B25C8C(void); /* 0 internal, 5 external, 161 lines */
void play(entity_t *en, z64_global_t *gl); /* 0 internal, 6 external, 46 lines */
void data_80B26328(void); /* 1 internal, 2 external, 52 lines */
void func_80B25F08(void); /* 3 internal, 2 external, 144 lines */


/*** variables ***/
const uint32_t data_80B264E0[] =
{
	0x0A110900,
	0x20010000,
	0x00000000,
	0xFFCFFFFF,
	0x00040000,
	0xFFCFFFFF,
	0x00000000,
	0x01010000,
	0x00090017,
	0x00000000,
	0x00000000,
	0x011D0600,
	0x00000010,
	0x00030000,
	0x000001AC,
	(uint32_t)(void*)init,
	(uint32_t)(void*)dest,
	(uint32_t)(void*)play,
	(uint32_t)(void*)draw,
	0x00000000,
};
const uint32_t data_80B26530[] =
{
	0x0A0A0000
};
const uint32_t data_80B26534[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xC4DBA5C8,
	0xA5E9A5C3,
	0xA5D720A1,
	0xF9A1F9A1,
	0xF9A1F9A1,
	0xF9202578,
	0x0A1B5B6D,
	0x00000000
};
const uint32_t data_80B26564[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xA4EFA4C6,
	0x20202020,
	0x20A1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0x25660A1B,
	0x5B6D0000
};
const uint32_t data_80B26590[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xA4AAA4A4,
	0xA4C9A4F3,
	0x20A1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0x25660A1B,
	0x5B6D0000
};
const uint32_t data_80B265BC[] =
{
	0x0A0A0000
};
const uint32_t data_80B265C0[] =
{
	0x3E6B851F
};
const uint32_t data_80B265C4[] =
{
	0x3E4CCCCD
};
const uint32_t data_80B265C8[] =
{
	0x3F199999
};
const uint32_t data_80B265CC[] =
{
	0x3E4CCCCD
};
const uint32_t data_80B265D0[] =
{
	0x3E4CCCCD,
	0x00000000,
	0x00000000,
	0x00000000
};


/*** functions ***/
void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 13 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	draw_static_dlist_opa(gl, DL_TUBO);
}

void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);

	actor_capsule_free(gl, &en->capsule);
}

void func_80B259B8(void) /* 0 internal, 1 external, 25 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B259B8: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"lh              $v1,28($a0)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"sra             $v0,$v1,6                              \n"
		"andi            $v0,$v0,0x3ff                          \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000000                           \n"
		"slti            $at,$v0,26                             \n"
		"beq             $at,$zero,.L000000                     \n"
		"or              $a0,$a1,$zero                          \n"
		"andi            $t6,$v1,0x3f                           \n"
		"sll             $t7,$t6,8                              \n"
		"or              $a2,$v0,$t7                            \n"
		"sll             $a2,$a2,16                             \n"
		"sra             $a2,$a2,16                             \n"
		"jal             external_func_8001F548                 \n"
		"addiu           $a1,$a3,36                             \n"
		".L000000:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80B2629C(void) /* 0 internal, 1 external, 36 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80B2629C: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"lh              $t6,182($a0)                           \n"
		"or              $s0,$a0,$zero                          \n"
		"lui             $a2,0x3F4C                             \n"
		"addiu           $t7,$t6,5000                           \n"
		"sh              $t7,182($a0)                           \n"
		"lw              $a1,336($s0)                           \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"addiu           $a0,$a0,40                             \n"
		"jal             external_func_8007841C                 \n"
		"lui             $a3,0x4040                             \n"
		"lwc1            $f4,40($s0)                            \n"
		"lwc1            $f6,336($s0)                           \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f2                                \n"
		"sub.s           $f0,$f4,$f6                            \n"
		"lui             $t9,%hi(data_80B26328)                 \n"
		"addiu           $t9,$t9,%lo(data_80B26328)             \n"
		"abs.s           $f0,$f0                                \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1fl           .L000016                               \n"
		"lw              $ra,28($sp)                            \n"
		"lh              $t8,138($s0)                           \n"
		"swc1            $f2,104($s0)                           \n"
		"sw              $t9,332($s0)                           \n"
		"sh              $t8,50($s0)                            \n"
		"lw              $ra,28($sp)                            \n"
		".L000016:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80B2612C(void) /* 0 internal, 3 external, 95 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80B2612C: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"lui             $t8,0x8016                             \n"
		"lw              $t8,-1392($t8)                         \n"
		"sw              $t7,36($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"lh              $t9,4824($t8)                          \n"
		"beql            $t9,$zero,.L000013                     \n"
		"lui             $at,0x4348                             \n"
		"lwc1            $f4,40($s0)                            \n"
		"lui             $a0,%hi(data_80B26564)                 \n"
		"addiu           $a0,$a0,%lo(data_80B26564)             \n"
		"cvt.d.s         $f6,$f4                                \n"
		"mfc1            $a3,$f6                                \n"
		"mfc1            $a2,$f7                                \n"
		"jal             external_func_80002130                 \n"
		"nop                                                    \n"
		"lw              $t0,36($sp)                            \n"
		"lui             $a0,%hi(data_80B26590)                 \n"
		"addiu           $a0,$a0,%lo(data_80B26590)             \n"
		"lwc1            $f8,40($t0)                            \n"
		"cvt.d.s         $f10,$f8                               \n"
		"mfc1            $a3,$f10                               \n"
		"mfc1            $a2,$f11                               \n"
		"jal             external_func_80002130                 \n"
		"nop                                                    \n"
		"lui             $a0,%hi(data_80B265BC)                 \n"
		"jal             external_func_80002130                 \n"
		"addiu           $a0,$a0,%lo(data_80B265BC)             \n"
		"lui             $at,0x4348                             \n"
		".L000013:                                              \n"
		"mtc1            $at,$f18                               \n"
		"lwc1            $f16,144($s0)                          \n"
		"lw              $t1,36($sp)                            \n"
		"c.lt.s          $f16,$f18                              \n"
		"nop                                                    \n"
		"bc1fl           .L000014                               \n"
		"lw              $ra,28($sp)                            \n"
		"lwc1            $f4,40($t1)                            \n"
		"lwc1            $f6,40($s0)                            \n"
		"lw              $a0,44($sp)                            \n"
		"or              $a2,$s0,$zero                          \n"
		"c.le.s          $f6,$f4                                \n"
		"addiu           $a1,$a0,7204                           \n"
		"bc1fl           .L000014                               \n"
		"lw              $ra,28($sp)                            \n"
		"jal             external_func_80033748                 \n"
		"addiu           $a3,$zero,5                            \n"
		"lw              $t3,4($s0)                             \n"
		"lui             $t5,0x8016                             \n"
		"lui             $at,0xC120                             \n"
		"ori             $t4,$t3,0x1                            \n"
		"sw              $t4,4($s0)                             \n"
		"lw              $t5,-6556($t5)                         \n"
		"mtc1            $at,$f16                               \n"
		"lui             $at,0x4220                             \n"
		"mtc1            $t5,$f8                                \n"
		"mtc1            $at,$f4                                \n"
		"lw              $t6,36($sp)                            \n"
		"cvt.s.w         $f10,$f8                               \n"
		"lwc1            $f0,40($s0)                            \n"
		"lwc1            $f6,40($t6)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"mul.s           $f18,$f10,$f16                         \n"
		"add.s           $f2,$f18,$f4                           \n"
		"add.s           $f8,$f6,$f2                            \n"
		"swc1            $f8,336($s0)                           \n"
		"lwc1            $f10,336($s0)                          \n"
		"c.lt.s          $f10,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000015                               \n"
		"lw              $t8,36($s0)                            \n"
		"add.s           $f16,$f0,$f2                           \n"
		"swc1            $f16,336($s0)                          \n"
		"lw              $t8,36($s0)                            \n"
		".L000015:                                              \n"
		"lw              $t7,40($s0)                            \n"
		"addiu           $a1,$zero,10436                        \n"
		"sw              $t8,340($s0)                           \n"
		"lw              $t8,44($s0)                            \n"
		"sw              $t7,344($s0)                           \n"
		"jal             external_func_8002F828                 \n"
		"sw              $t8,348($s0)                           \n"
		"lui             $t9,%hi(data_80B2629C)                 \n"
		"addiu           $t9,$t9,%lo(data_80B2629C)             \n"
		"sw              $t9,332($s0)                           \n"
		"lw              $ra,28($sp)                            \n"
		".L000014:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void init(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 40 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit: \n"
	);

	actor_init_shadow(&(en->actor).rot_2, 0, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 2.0f);
	//debug_message(&data_80B26530);
	//debug_message(&data_80B26534, (en->actor).variable);
	actor_capsule_alloc(gl, &en->capsule);
	actor_capsule_init(gl, &en->capsule, &en->actor, &data_80B264E0);
	actor_set_scale(&en->actor, 0.1f);
	en->playfunc = (z64_actorfunc_t *)data_80B2612C;
}

void func_80B25A18(void) /* 0 internal, 5 external, 160 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B25A18: \n"
	);
	asm(
		"addiu           $sp,$sp,-224                           \n"
		"sdc1            $f30,112($sp)                          \n"
		"lui             $at,%hi(data_80B265C0)                 \n"
		"lwc1            $f30,%lo(data_80B265C0)($at)           \n"
		"sdc1            $f28,104($sp)                          \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f28                               \n"
		"sdc1            $f26,96($sp)                           \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f26                               \n"
		"sw              $s6,144($sp)                           \n"
		"sdc1            $f24,88($sp)                           \n"
		"lui             $at,0x4100                             \n"
		"sw              $s8,152($sp)                           \n"
		"sw              $s7,148($sp)                           \n"
		"sw              $s5,140($sp)                           \n"
		"sw              $s4,136($sp)                           \n"
		"sw              $s3,132($sp)                           \n"
		"sw              $s2,128($sp)                           \n"
		"sw              $s1,124($sp)                           \n"
		"lui             $s6,0x0501                             \n"
		"mtc1            $at,$f24                               \n"
		"or              $s8,$a1,$zero                          \n"
		"sw              $ra,156($sp)                           \n"
		"sw              $s0,120($sp)                           \n"
		"sdc1            $f22,80($sp)                           \n"
		"sdc1            $f20,72($sp)                           \n"
		"addiu           $s6,$s6,31328                          \n"
		"addiu           $s1,$a0,36                             \n"
		"or              $s2,$zero,$zero                        \n"
		"or              $s3,$zero,$zero                        \n"
		"addiu           $s4,$sp,200                            \n"
		"addiu           $s5,$sp,188                            \n"
		"addiu           $s7,$zero,15                           \n"
		".L000003:                                              \n"
		"sll             $a0,$s2,16                             \n"
		"jal             external_func_80077870                 \n"
		"sra             $a0,$a0,16                             \n"
		"sll             $a0,$s2,16                             \n"
		"mov.s           $f20,$f0                               \n"
		"jal             external_func_80077834                 \n"
		"sra             $a0,$a0,16                             \n"
		"mul.s           $f4,$f20,$f24                          \n"
		"mov.s           $f22,$f0                               \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f4,200($sp)                           \n"
		"mul.s           $f6,$f0,$f26                           \n"
		"lwc1            $f16,200($sp)                          \n"
		"mul.s           $f10,$f22,$f24                         \n"
		"nop                                                    \n"
		"mul.s           $f18,$f16,$f30                         \n"
		"add.s           $f8,$f6,$f28                           \n"
		"swc1            $f10,208($sp)                          \n"
		"swc1            $f8,204($sp)                           \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f18,188($sp)                          \n"
		"mul.s           $f4,$f0,$f26                           \n"
		"lwc1            $f8,208($sp)                           \n"
		"lwc1            $f16,200($sp)                          \n"
		"mul.s           $f10,$f8,$f30                          \n"
		"add.s           $f6,$f4,$f28                           \n"
		"swc1            $f10,196($sp)                          \n"
		"swc1            $f6,192($sp)                           \n"
		"lwc1            $f18,0($s1)                            \n"
		"lwc1            $f6,204($sp)                           \n"
		"add.s           $f4,$f16,$f18                          \n"
		"swc1            $f4,200($sp)                           \n"
		"lwc1            $f10,4($s1)                            \n"
		"add.s           $f16,$f6,$f10                          \n"
		"swc1            $f16,204($sp)                          \n"
		"lwc1            $f18,8($s1)                            \n"
		"add.s           $f4,$f8,$f18                           \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f4,208($sp)                           \n"
		"lui             $at,%hi(data_80B265C4)                 \n"
		"lwc1            $f6,%lo(data_80B265C4)($at)            \n"
		"lui             $at,%hi(data_80B265C8)                 \n"
		"c.lt.s          $f0,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000001                               \n"
		"nop                                                    \n"
		"b               .L000002                               \n"
		"addiu           $s0,$zero,96                           \n"
		".L000001:                                              \n"
		"lwc1            $f10,%lo(data_80B265C8)($at)           \n"
		"addiu           $s0,$zero,32                           \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1f            .L000002                               \n"
		"nop                                                    \n"
		"b               .L000002                               \n"
		"addiu           $s0,$zero,64                           \n"
		".L000002:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4282                             \n"
		"mtc1            $at,$f16                               \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f18                               \n"
		"mul.s           $f8,$f0,$f16                           \n"
		"addiu           $t6,$zero,-240                         \n"
		"addiu           $t7,$zero,10                           \n"
		"addiu           $t8,$zero,10                           \n"
		"addiu           $t1,$zero,32                           \n"
		"addiu           $t2,$zero,60                           \n"
		"addiu           $t3,$zero,-1                           \n"
		"add.s           $f4,$f8,$f18                           \n"
		"addiu           $t4,$zero,3                            \n"
		"sw              $t4,56($sp)                            \n"
		"sw              $t3,52($sp)                            \n"
		"trunc.w.s       $f6,$f4                                \n"
		"sw              $t2,48($sp)                            \n"
		"sw              $t1,44($sp)                            \n"
		"sw              $t8,28($sp)                            \n"
		"mfc1            $t0,$f6                                \n"
		"sw              $t7,24($sp)                            \n"
		"sw              $t6,16($sp)                            \n"
		"or              $a0,$s8,$zero                          \n"
		"or              $a1,$s4,$zero                          \n"
		"or              $a2,$s5,$zero                          \n"
		"or              $a3,$s1,$zero                          \n"
		"sw              $s0,20($sp)                            \n"
		"sw              $zero,32($sp)                          \n"
		"sw              $zero,40($sp)                          \n"
		"sw              $s6,60($sp)                            \n"
		"jal             external_func_80029E8C                 \n"
		"sw              $t0,36($sp)                            \n"
		"addiu           $s2,$s2,20000                          \n"
		"sll             $s2,$s2,16                             \n"
		"addiu           $s3,$s3,1                              \n"
		"bne             $s3,$s7,.L000003                       \n"
		"sra             $s2,$s2,16                             \n"
		"addiu           $t5,$zero,20                           \n"
		"addiu           $t6,$zero,50                           \n"
		"sw              $t6,20($sp)                            \n"
		"sw              $t5,16($sp)                            \n"
		"or              $a0,$s8,$zero                          \n"
		"or              $a1,$s1,$zero                          \n"
		"lui             $a2,0x41F0                             \n"
		"addiu           $a3,$zero,4                            \n"
		"jal             external_func_80033480                 \n"
		"sw              $zero,24($sp)                          \n"
		"lw              $ra,156($sp)                           \n"
		"ldc1            $f20,72($sp)                           \n"
		"ldc1            $f22,80($sp)                           \n"
		"ldc1            $f24,88($sp)                           \n"
		"ldc1            $f26,96($sp)                           \n"
		"ldc1            $f28,104($sp)                          \n"
		"ldc1            $f30,112($sp)                          \n"
		"lw              $s0,120($sp)                           \n"
		"lw              $s1,124($sp)                           \n"
		"lw              $s2,128($sp)                           \n"
		"lw              $s3,132($sp)                           \n"
		"lw              $s4,136($sp)                           \n"
		"lw              $s5,140($sp)                           \n"
		"lw              $s6,144($sp)                           \n"
		"lw              $s7,148($sp)                           \n"
		"lw              $s8,152($sp)                           \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,224                            \n"
	);
}
void func_80B25C8C(void) /* 0 internal, 5 external, 161 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B25C8C: \n"
	);
	asm(
		"addiu           $sp,$sp,-224                           \n"
		"sw              $s1,124($sp)                           \n"
		"sw              $ra,156($sp)                           \n"
		"sw              $s8,152($sp)                           \n"
		"sw              $s7,148($sp)                           \n"
		"sw              $s6,144($sp)                           \n"
		"sw              $s5,140($sp)                           \n"
		"sw              $s4,136($sp)                           \n"
		"sw              $s3,132($sp)                           \n"
		"sw              $s2,128($sp)                           \n"
		"sw              $s0,120($sp)                           \n"
		"sdc1            $f30,112($sp)                          \n"
		"sdc1            $f28,104($sp)                          \n"
		"sdc1            $f26,96($sp)                           \n"
		"sdc1            $f24,88($sp)                           \n"
		"sdc1            $f22,80($sp)                           \n"
		"sdc1            $f20,72($sp)                           \n"
		"addiu           $s1,$a0,36                             \n"
		"lw              $t7,0($s1)                             \n"
		"addiu           $s5,$sp,200                            \n"
		"or              $s4,$a1,$zero                          \n"
		"sw              $t7,0($s5)                             \n"
		"lw              $t6,4($s1)                             \n"
		"addiu           $t8,$zero,400                          \n"
		"or              $a2,$zero,$zero                        \n"
		"sw              $t6,4($s5)                             \n"
		"lw              $t7,8($s1)                             \n"
		"or              $a3,$zero,$zero                        \n"
		"sw              $t7,8($s5)                             \n"
		"lwc1            $f4,204($sp)                           \n"
		"lwc1            $f6,132($a0)                           \n"
		"or              $a0,$a1,$zero                          \n"
		"or              $a1,$s5,$zero                          \n"
		"add.s           $f8,$f4,$f6                            \n"
		"sw              $t8,20($sp)                            \n"
		"sw              $zero,16($sp)                          \n"
		"jal             external_func_8002949C                 \n"
		"swc1            $f8,204($sp)                           \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f30                               \n"
		"lui             $at,%hi(data_80B265CC)                 \n"
		"lwc1            $f28,%lo(data_80B265CC)($at)           \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f26                               \n"
		"lui             $at,0x4100                             \n"
		"lui             $s7,0x0501                             \n"
		"mtc1            $at,$f24                               \n"
		"addiu           $s7,$s7,31328                          \n"
		"or              $s3,$zero,$zero                        \n"
		"or              $s2,$zero,$zero                        \n"
		"addiu           $s8,$zero,15                           \n"
		"addiu           $s6,$sp,188                            \n"
		".L000005:                                              \n"
		"sll             $a0,$s2,16                             \n"
		"jal             external_func_80077870                 \n"
		"sra             $a0,$a0,16                             \n"
		"sll             $a0,$s2,16                             \n"
		"mov.s           $f20,$f0                               \n"
		"jal             external_func_80077834                 \n"
		"sra             $a0,$a0,16                             \n"
		"mul.s           $f10,$f20,$f24                         \n"
		"mov.s           $f22,$f0                               \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f10,200($sp)                          \n"
		"mul.s           $f16,$f0,$f30                          \n"
		"lwc1            $f6,200($sp)                           \n"
		"mul.s           $f4,$f22,$f24                          \n"
		"nop                                                    \n"
		"mul.s           $f8,$f6,$f28                           \n"
		"add.s           $f18,$f16,$f26                         \n"
		"swc1            $f4,208($sp)                           \n"
		"swc1            $f18,204($sp)                          \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f8,188($sp)                           \n"
		"lui             $at,0x4080                             \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f4,208($sp)                           \n"
		"lwc1            $f8,200($sp)                           \n"
		"mul.s           $f16,$f0,$f10                          \n"
		"add.s           $f18,$f16,$f26                         \n"
		"mul.s           $f6,$f4,$f28                           \n"
		"swc1            $f18,192($sp)                          \n"
		"lwc1            $f18,204($sp)                          \n"
		"swc1            $f6,196($sp)                           \n"
		"lwc1            $f10,0($s1)                            \n"
		"add.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,200($sp)                          \n"
		"lwc1            $f6,4($s1)                             \n"
		"add.s           $f8,$f18,$f6                           \n"
		"swc1            $f8,204($sp)                           \n"
		"lwc1            $f10,8($s1)                            \n"
		"add.s           $f16,$f4,$f10                          \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f16,208($sp)                          \n"
		"lui             $at,%hi(data_80B265D0)                 \n"
		"lwc1            $f18,%lo(data_80B265D0)($at)           \n"
		"addiu           $s0,$zero,32                           \n"
		"c.lt.s          $f0,$f18                               \n"
		"nop                                                    \n"
		"bc1f            .L000004                               \n"
		"nop                                                    \n"
		"b               .L000004                               \n"
		"addiu           $s0,$zero,64                           \n"
		".L000004:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4282                             \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f4                                \n"
		"mul.s           $f8,$f0,$f6                            \n"
		"addiu           $t9,$zero,-180                         \n"
		"addiu           $t0,$zero,30                           \n"
		"addiu           $t1,$zero,30                           \n"
		"addiu           $t4,$zero,32                           \n"
		"addiu           $t5,$zero,70                           \n"
		"addiu           $t6,$zero,-1                           \n"
		"add.s           $f10,$f8,$f4                           \n"
		"addiu           $t7,$zero,3                            \n"
		"sw              $t7,56($sp)                            \n"
		"sw              $t6,52($sp)                            \n"
		"trunc.w.s       $f16,$f10                              \n"
		"sw              $t5,48($sp)                            \n"
		"sw              $t4,44($sp)                            \n"
		"sw              $t1,28($sp)                            \n"
		"mfc1            $t3,$f16                               \n"
		"sw              $t0,24($sp)                            \n"
		"sw              $t9,16($sp)                            \n"
		"or              $a0,$s4,$zero                          \n"
		"or              $a1,$s5,$zero                          \n"
		"or              $a2,$s6,$zero                          \n"
		"or              $a3,$s1,$zero                          \n"
		"sw              $s0,20($sp)                            \n"
		"sw              $zero,32($sp)                          \n"
		"sw              $zero,40($sp)                          \n"
		"sw              $s7,60($sp)                            \n"
		"jal             external_func_80029E8C                 \n"
		"sw              $t3,36($sp)                            \n"
		"addiu           $s2,$s2,20000                          \n"
		"sll             $s2,$s2,16                             \n"
		"addiu           $s3,$s3,1                              \n"
		"bne             $s3,$s8,.L000005                       \n"
		"sra             $s2,$s2,16                             \n"
		"lw              $ra,156($sp)                           \n"
		"ldc1            $f20,72($sp)                           \n"
		"ldc1            $f22,80($sp)                           \n"
		"ldc1            $f24,88($sp)                           \n"
		"ldc1            $f26,96($sp)                           \n"
		"ldc1            $f28,104($sp)                          \n"
		"ldc1            $f30,112($sp)                          \n"
		"lw              $s0,120($sp)                           \n"
		"lw              $s1,124($sp)                           \n"
		"lw              $s2,128($sp)                           \n"
		"lw              $s3,132($sp)                           \n"
		"lw              $s4,136($sp)                           \n"
		"lw              $s5,140($sp)                           \n"
		"lw              $s6,144($sp)                           \n"
		"lw              $s7,148($sp)                           \n"
		"lw              $s8,152($sp)                           \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,224                            \n"
	);
}

void play(entity_t *en, z64_global_t *gl) /* 0 internal, 6 external, 46 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lplay: \n"
	);

	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc();
	external_func_8002D8E0(&en->actor); /* Probably to haul ass towards Link */
	external_func_8002E4B4(gl, &en->actor, 10.0f, 10.0f, 20.0f, 0x1D); /* Necessary for drawing a shadow */
	actor_set_height(&en->actor, 0);
	actor_capsule_update(&en->actor, &en->capsule);
	actor_collision_check_set_ac(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
	actor_collision_check_set_at(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
}

void data_80B26328(void) /* 1 internal, 2 external, 52 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80B26328: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lwc1            $f18,340($a0)                          \n"
		"lwc1            $f16,36($a0)                           \n"
		"lwc1            $f14,344($a0)                          \n"
		"lwc1            $f12,40($a0)                           \n"
		"sub.s           $f16,$f18,$f16                         \n"
		"lwc1            $f18,348($a0)                          \n"
		"lwc1            $f10,44($a0)                           \n"
		"sub.s           $f12,$f14,$f12                         \n"
		"or              $s0,$a0,$zero                          \n"
		"swc1            $f16,44($sp)                           \n"
		"sub.s           $f10,$f18,$f10                         \n"
		"swc1            $f12,40($sp)                           \n"
		"addiu           $a1,$zero,12343                        \n"
		"jal             external_func_8002F828                 \n"
		"swc1            $f10,36($sp)                           \n"
		"lwc1            $f2,44($sp)                            \n"
		"lwc1            $f12,40($sp)                           \n"
		"lwc1            $f14,36($sp)                           \n"
		"mul.s           $f4,$f2,$f2                            \n"
		"lui             $at,0x4370                             \n"
		"mtc1            $at,$f16                               \n"
		"mul.s           $f6,$f12,$f12                          \n"
		"lui             $a2,0x3E4C                             \n"
		"ori             $a2,$a2,0xcccd                         \n"
		"mul.s           $f10,$f14,$f14                         \n"
		"addiu           $a0,$s0,108                            \n"
		"lui             $a1,0xC040                             \n"
		"add.s           $f8,$f4,$f6                            \n"
		"add.s           $f0,$f8,$f10                           \n"
		"sqrt.s          $f0,$f0                                \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000017                               \n"
		"lh              $t6,182($s0)                           \n"
		"jal             external_func_8007841C                 \n"
		"lui             $a3,0x3F00                             \n"
		"lh              $t6,182($s0)                           \n"
		".L000017:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $t7,$t6,5000                           \n"
		"sh              $t7,182($s0)                           \n"
		"jal             func_80B25F08                          \n"
		"lw              $a1,52($sp)                            \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80B25F08(void) /* 3 internal, 2 external, 144 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B25F08: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s1,24($sp)                            \n"
		"sw              $s0,20($sp)                            \n"
		"lw              $a2,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"or              $s1,$a1,$zero                          \n"
		"sw              $a2,40($sp)                            \n"
		"lhu             $t6,136($a0)                           \n"
		"lui             $at,0x4170                             \n"
		"andi            $t7,$t6,0x20                           \n"
		"beql            $t7,$zero,.L000006                     \n"
		"lbu             $v0,368($s0)                           \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f6,132($a0)                           \n"
		"c.lt.s          $f4,$f6                                \n"
		"nop                                                    \n"
		"bc1fl           .L000006                               \n"
		"lbu             $v0,368($s0)                           \n"
		"jal             func_80B25C8C                          \n"
		"nop                                                    \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10263                        \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B259B8                          \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000007                               \n"
		"lw              $ra,28($sp)                            \n"
		"lbu             $v0,368($s0)                           \n"
		".L000006:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a1,$s1,$zero                          \n"
		"andi            $t8,$v0,0x4                            \n"
		"beq             $t8,$zero,.L000008                     \n"
		"andi            $t9,$v0,0xfffb                         \n"
		"jal             func_80B25A18                          \n"
		"sb              $t9,368($s0)                           \n"
		"addiu           $a1,$s0,36                             \n"
		"sw              $a1,36($sp)                            \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,6152                         \n"
		"lw              $a1,36($sp)                            \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10375                        \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B259B8                          \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000007                               \n"
		"lw              $ra,28($sp)                            \n"
		".L000008:                                              \n"
		"lbu             $v1,369($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t2,$v0,0x2                            \n"
		"andi            $t0,$v1,0x2                            \n"
		"beq             $t0,$zero,.L000009                     \n"
		"andi            $t1,$v1,0xfffd                         \n"
		"sb              $t1,369($s0)                           \n"
		"jal             func_80B25A18                          \n"
		"or              $a1,$s1,$zero                          \n"
		"addiu           $a1,$s0,36                             \n"
		"sw              $a1,36($sp)                            \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10242                        \n"
		"lw              $a1,36($sp)                            \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10375                        \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B259B8                          \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000007                               \n"
		"lw              $ra,28($sp)                            \n"
		".L000009:                                              \n"
		"beql            $t2,$zero,.L000010                     \n"
		"lhu             $v0,136($s0)                           \n"
		"lw              $t4,356($s0)                           \n"
		"andi            $t3,$v0,0xfffd                         \n"
		"sb              $t3,368($s0)                           \n"
		"bne             $a2,$t4,.L000011                       \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B25A18                          \n"
		"or              $a1,$s1,$zero                          \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10375                        \n"
		"lw              $a1,40($sp)                            \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a2,$zero,40                           \n"
		"addiu           $a3,$zero,2110                         \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a1,$a1,36                             \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B259B8                          \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000007                               \n"
		"lw              $ra,28($sp)                            \n"
		".L000011:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		".L000010:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t5,$v0,0x8                            \n"
		"bne             $t5,$zero,.L000012                     \n"
		"andi            $t6,$v0,0x1                            \n"
		"beql            $t6,$zero,.L000007                     \n"
		"lw              $ra,28($sp)                            \n"
		".L000012:                                              \n"
		"jal             func_80B25A18                          \n"
		"or              $a1,$s1,$zero                          \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$zero,40                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,10375                        \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80B259B8                          \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,28($sp)                            \n"
		".L000007:                                              \n"
		"lw              $s0,20($sp)                            \n"
		"lw              $s1,24($sp)                            \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,48                             \n"
	);
}
const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* for use with zzromtool */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
