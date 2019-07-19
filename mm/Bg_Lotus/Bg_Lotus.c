#include <z64ovl/mm/u10.h>

#define ACT_ID 0x01B9
#define OBJ_ID 0x01A5
/* object */
#define DL_LOTUS   0x06000040
#define DP_COLLIDE 0x06000A20

typedef struct {
	z64_actor_t      actor;     /* 0x0000, size 0x0144 */
	uint32_t         dynap_id;  /* 0x0144, size 0x0004 */
	PADDING(0x14);
	z64_actorfunc_t *playfunc;  /* 0x015C, size 0x0004 */
	uint32_t         unk160;    /* 0x0160, size 0x0004 */
	uint16_t         unk164;    /* 0x0164, size 0x0002 */
	uint16_t         unk166;    /* 0x0166, size 0x0002 */
	uint16_t         unk168;    /* 0x0168, size 0x0002 */
	uint16_t         unk16A;
} entity_t;


/*** function prototypes ***/
void data_80AD67FC(void); /* 0 internal, 1 external, 13 lines */
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 13 lines */
void data_80AD6C5C(void); /* 0 internal, 1 external, 24 lines */
void func_80AD6830(void); /* 0 internal, 1 external, 44 lines */
void data_80AD6B68(void); /* 0 internal, 2 external, 65 lines */
void data_80AD6760(void); /* 0 internal, 5 external, 39 lines */
void data_80AD6A88(void); /* 1 internal, 2 external, 61 lines */
void data_80AD68DC(void); /* 1 internal, 6 external, 115 lines */


/*** variables ***/
const uint32_t data_80AD6D10[] =
{
	0x48580064,
	0x00000000,
	0x00000000,
	0x00000000,
};
const uint32_t data_80AD6D20[] =
{
	0x3F490FDB
};
const uint32_t data_80AD6D24[] =
{
	0x3DCCCCCD
};
const uint32_t data_80AD6D28[] =
{
	0x3C656041
};
const uint32_t data_80AD6D2C[] =
{
	0x3C23D70A
};
const uint32_t data_80AD6D30[] =
{
	0x3D860A92,
	0x00000000,
	0x00000000,
	0x00000000
};


/*** functions ***/
void data_80AD67FC(void) /* 0 internal, 1 external, 13 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD67FC: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"or              $a3,$a1,$zero                          \n"
		"lw              $t6,24($sp)                            \n"
		"or              $a0,$a3,$zero                          \n"
		"addiu           $a1,$a3,2176                           \n"
		"jal             0x800C64CC                 \n"
		"lw              $a2,324($t6)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 13 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);
	
	draw_static_dlist_opa(gl, DL_LOTUS);
}

void data_80AD6C5C(void) /* 0 internal, 1 external, 24 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD6C5C: \n"
	);
	asm(
		"addiu           $sp,$sp,-56                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,60($sp)                            \n"
		"lw              $a0,60($sp)                            \n"
		"lw              $a2,36($s0)                            \n"
		"lw              $a3,44($s0)                            \n"
		"addiu           $t7,$s0,352                            \n"
		"addiu           $t8,$sp,44                             \n"
		"sw              $t8,20($sp)                            \n"
		"sw              $t7,16($sp)                            \n"
		"jal             0x800CA1E8                 \n"
		"addiu           $a1,$a0,2096                           \n"
		"lw              $t9,348($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a1,60($sp)                            \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,56                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void func_80AD6830(void) /* 0 internal, 1 external, 44 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80AD6830: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"lh              $t6,28($a0)                            \n"
		"bnel            $t6,$zero,.L000000                     \n"
		"lw              $ra,20($sp)                            \n"
		"lh              $t7,358($a0)                           \n"
		"lui             $at,%hi(data_80AD6D20)                 \n"
		"lwc1            $f8,%lo(data_80AD6D20)($at)            \n"
		"mtc1            $t7,$f4                                \n"
		"sw              $a0,24($sp)                            \n"
		"cvt.s.w         $f6,$f4                                \n"
		"mul.s           $f12,$f6,$f8                           \n"
		"jal             0x801794EC                 \n"
		"nop                                                    \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f12                               \n"
		"lh              $t8,358($a0)                           \n"
		"lui             $at,%hi(data_80AD6D24)                 \n"
		"lwc1            $f14,%lo(data_80AD6D24)($at)           \n"
		"mtc1            $t8,$f10                               \n"
		"lui             $at,0x4100                             \n"
		"mtc1            $at,$f18                               \n"
		"cvt.s.w         $f16,$f10                              \n"
		"lui             $at,%hi(data_80AD6D28)                 \n"
		"lwc1            $f6,%lo(data_80AD6D28)($at)            \n"
		"lui             $at,%hi(data_80AD6D2C)                 \n"
		"lwc1            $f10,%lo(data_80AD6D2C)($at)           \n"
		"div.s           $f4,$f16,$f18                          \n"
		"mul.s           $f8,$f6,$f4                            \n"
		"add.s           $f16,$f8,$f10                          \n"
		"mul.s           $f2,$f0,$f16                           \n"
		"add.s           $f18,$f12,$f2                          \n"
		"sub.s           $f4,$f12,$f2                           \n"
		"mul.s           $f6,$f18,$f14                          \n"
		"nop                                                    \n"
		"mul.s           $f8,$f4,$f14                           \n"
		"swc1            $f6,88($a0)                            \n"
		"swc1            $f8,96($a0)                            \n"
		"lw              $ra,20($sp)                            \n"
		".L000000:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void data_80AD6B68(void) /* 0 internal, 2 external, 65 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD6B68: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lh              $v0,358($a3)                           \n"
		"lui             $at,0x42C8                             \n"
		"blez            $v0,.L000014                           \n"
		"addiu           $t6,$v0,-1                             \n"
		"b               .L000015                               \n"
		"sh              $t6,358($a3)                           \n"
		".L000014:                                              \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f6,152($a3)                           \n"
		"c.lt.s          $f4,$f6                                \n"
		"nop                                                    \n"
		"bc1fl           .L000016                               \n"
		"lw              $ra,20($sp)                            \n"
		"lwc1            $f8,244($a3)                           \n"
		"mtc1            $zero,$f10                             \n"
		"lui             $t7,%hi(draw)                 \n"
		"addiu           $t7,$t7,%lo(draw)             \n"
		"c.lt.s          $f8,$f10                               \n"
		"nop                                                    \n"
		"bc1fl           .L000016                               \n"
		"lw              $ra,20($sp)                            \n"
		"sw              $t7,316($a3)                           \n"
		"lw              $a0,28($sp)                            \n"
		"lw              $a2,324($a3)                           \n"
		"sw              $a3,24($sp)                            \n"
		"jal             0x800C6314                 \n"
		"addiu           $a1,$a0,2176                           \n"
		"lui             $a1,0x3DCC                             \n"
		"lw              $a0,24($sp)                            \n"
		"jal             0x800B67E0                 \n"
		"ori             $a1,$a1,0xcccd                         \n"
		"lw              $a3,24($sp)                            \n"
		"lui             $t2,%hi(data_80AD68DC)                 \n"
		"addiu           $at,$zero,-17                          \n"
		"lwc1            $f0,352($a3)                           \n"
		"lwc1            $f2,136($a3)                           \n"
		"addiu           $t1,$zero,96                           \n"
		"addiu           $t2,$t2,%lo(data_80AD68DC)             \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1fl           .L000017                               \n"
		"swc1            $f0,40($a3)                            \n"
		"b               .L000017                               \n"
		"swc1            $f2,40($a3)                            \n"
		"swc1            $f0,40($a3)                            \n"
		".L000017:                                              \n"
		"lw              $t9,4($a3)                             \n"
		"lwc1            $f16,8($a3)                            \n"
		"lwc1            $f18,16($a3)                           \n"
		"and             $t0,$t9,$at                            \n"
		"sw              $t0,4($a3)                             \n"
		"sh              $t1,360($a3)                           \n"
		"sw              $t2,348($a3)                           \n"
		"swc1            $f16,36($a3)                           \n"
		"swc1            $f18,44($a3)                           \n"
		".L000015:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000016:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void data_80AD6760(void) /* 0 internal, 5 external, 39 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD6760: \n"
	);
	asm(
		"addiu           $sp,$sp,-56                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,60($sp)                            \n"
		"lui             $a1,%hi(data_80AD6D10)                 \n"
		"addiu           $a1,$a1,%lo(data_80AD6D10)             \n"
		"jal             0x800FFADC                 \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x800CAE10                 \n"
		"addiu           $a1,$zero,1                            \n"
		"lui             $a2,0x0600                             \n"
		"addiu           $a2,$a2,2592                           \n"
		"lw              $a0,60($sp)                            \n"
		"jal             0x800CAE34                 \n"
		"or              $a1,$s0,$zero                          \n"
		"lw              $a0,60($sp)                            \n"
		"addiu           $t6,$s0,36                             \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a1,$s0,128                            \n"
		"addiu           $a2,$sp,44                             \n"
		"or              $a3,$s0,$zero                          \n"
		"jal             0x800C411C                 \n"
		"addiu           $a0,$a0,2096                           \n"
		"addiu           $t7,$zero,96                           \n"
		"swc1            $f0,136($s0)                           \n"
		"jal             0x80086FA0                 \n"
		"sh              $t7,360($s0)                           \n"
		"lui             $t9,%hi(data_80AD68DC)                 \n"
		"sra             $t8,$v0,16                             \n"
		"addiu           $t9,$t9,%lo(data_80AD68DC)             \n"
		"sh              $t8,50($s0)                            \n"
		"sw              $t9,348($s0)                           \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,56                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void data_80AD6A88(void) /* 1 internal, 2 external, 61 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD6A88: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lwc1            $f2,352($a3)                           \n"
		"lwc1            $f0,40($a3)                            \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f4                                \n"
		"c.lt.s          $f2,$f0                                \n"
		"lui             $a2,0x3BA3                             \n"
		"ori             $a2,$a2,0xd70b                         \n"
		"addiu           $a0,$a3,88                             \n"
		"bc1f            .L000009                               \n"
		"addiu           $a1,$zero,0                            \n"
		"swc1            $f2,40($a3)                            \n"
		"lwc1            $f0,40($a3)                            \n"
		".L000009:                                              \n"
		"sub.s           $f6,$f0,$f4                            \n"
		"lwc1            $f2,136($a3)                           \n"
		"swc1            $f6,40($a3)                            \n"
		"lwc1            $f8,40($a3)                            \n"
		"c.le.s          $f8,$f2                                \n"
		"nop                                                    \n"
		"bc1fl           .L000010                               \n"
		"lh              $v0,358($a3)                           \n"
		"swc1            $f2,40($a3)                            \n"
		"sh              $zero,358($a3)                         \n"
		"lh              $v0,358($a3)                           \n"
		".L000010:                                              \n"
		"blez            $v0,.L000011                           \n"
		"addiu           $t6,$v0,-1                             \n"
		"sh              $t6,358($a3)                           \n"
		"jal             func_80AD6830                          \n"
		"or              $a0,$a3,$zero                          \n"
		"b               .L000012                               \n"
		"lw              $ra,20($sp)                            \n"
		".L000011:                                              \n"
		"jal             0x800FF03C                 \n"
		"sw              $a3,24($sp)                            \n"
		"lw              $a0,28($sp)                            \n"
		"beq             $v0,$zero,.L000013                     \n"
		"lw              $a3,24($sp)                            \n"
		"addiu           $t7,$zero,100                          \n"
		"sw              $zero,316($a3)                         \n"
		"sh              $t7,358($a3)                           \n"
		"lw              $a2,324($a3)                           \n"
		"sw              $a3,24($sp)                            \n"
		"jal             0x800C62BC                 \n"
		"addiu           $a1,$a0,2176                           \n"
		"lw              $a3,24($sp)                            \n"
		"lui             $t8,%hi(data_80AD6B68)                 \n"
		"addiu           $t8,$t8,%lo(data_80AD6B68)             \n"
		"sw              $t8,348($a3)                           \n"
		".L000013:                                              \n"
		"lwc1            $f10,88($a3)                           \n"
		"swc1            $f10,96($a3)                           \n"
		"lw              $ra,20($sp)                            \n"
		".L000012:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void data_80AD68DC(void) /* 1 internal, 6 external, 115 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80AD68DC: \n"
	);
	asm(
		"addiu           $sp,$sp,-56                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,60($sp)                            \n"
		"lh              $t6,360($s0)                           \n"
		"lui             $at,%hi(data_80AD6D30)                 \n"
		"addiu           $t7,$t6,-1                             \n"
		"sh              $t7,360($s0)                           \n"
		"lh              $t8,360($s0)                           \n"
		"lwc1            $f8,%lo(data_80AD6D30)($at)            \n"
		"mtc1            $t8,$f4                                \n"
		"nop                                                    \n"
		"cvt.s.w         $f6,$f4                                \n"
		"mul.s           $f12,$f6,$f8                           \n"
		"jal             0x801794EC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40C0                             \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"mul.s           $f16,$f0,$f10                          \n"
		"swc1            $f16,52($sp)                           \n"
		"lh              $t9,28($s0)                            \n"
		"bnel            $t9,$zero,.L000001                     \n"
		"lwc1            $f0,352($s0)                           \n"
		"jal             0x800FED84                 \n"
		"lh              $a0,50($s0)                            \n"
		"lwc1            $f18,52($sp)                           \n"
		"lwc1            $f6,8($s0)                             \n"
		"lh              $a0,50($s0)                            \n"
		"mul.s           $f4,$f0,$f18                           \n"
		"add.s           $f8,$f4,$f6                            \n"
		"jal             0x800FED44                 \n"
		"swc1            $f8,36($s0)                            \n"
		"lwc1            $f10,52($sp)                           \n"
		"lwc1            $f18,16($s0)                           \n"
		"lh              $t0,360($s0)                           \n"
		"mul.s           $f16,$f0,$f10                          \n"
		"addiu           $t1,$zero,96                           \n"
		"add.s           $f4,$f16,$f18                          \n"
		"bne             $t0,$zero,.L000002                     \n"
		"swc1            $f4,44($s0)                            \n"
		"jal             0x80086FA0                 \n"
		"sh              $t1,360($s0)                           \n"
		"lh              $t2,50($s0)                            \n"
		"sra             $t5,$v0,18                             \n"
		"addu            $t6,$t2,$t5                            \n"
		"sh              $t6,50($s0)                            \n"
		".L000002:                                              \n"
		"lwc1            $f0,352($s0)                           \n"
		".L000001:                                              \n"
		"lwc1            $f2,136($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1f            .L000003                               \n"
		"nop                                                    \n"
		"b               .L000004                               \n"
		"swc1            $f2,40($s0)                            \n"
		".L000003:                                              \n"
		"jal             0x800CAF70                 \n"
		"swc1            $f0,40($s0)                            \n"
		"beql            $v0,$zero,.L000004                     \n"
		"sb              $zero,356($s0)                         \n"
		"lbu             $t7,356($s0)                           \n"
		"lw              $a0,60($sp)                            \n"
		"addiu           $a1,$s0,36                             \n"
		"bne             $t7,$zero,.L000005                     \n"
		"addiu           $a2,$zero,1000                         \n"
		"addiu           $a3,$zero,1400                         \n"
		"sw              $zero,16($sp)                          \n"
		"jal             0x800B1EF4                 \n"
		"sw              $a1,44($sp)                            \n"
		"addiu           $t8,$zero,8                            \n"
		"lw              $a1,44($sp)                            \n"
		"sw              $t8,16($sp)                            \n"
		"lw              $a0,60($sp)                            \n"
		"addiu           $a2,$zero,1000                         \n"
		"jal             0x800B1EF4                 \n"
		"addiu           $a3,$zero,1400                         \n"
		"addiu           $t9,$zero,40                           \n"
		"sh              $t9,358($s0)                           \n"
		".L000005:                                              \n"
		"lui             $t0,0x801F                             \n"
		"lbu             $t0,-2416($t0)                         \n"
		"addiu           $at,$zero,3                            \n"
		"addiu           $t1,$zero,40                           \n"
		"beq             $t0,$at,.L000006                       \n"
		"addiu           $t5,$zero,1                            \n"
		"lw              $t3,4($s0)                             \n"
		"lui             $t2,%hi(data_80AD6A88)                 \n"
		"addiu           $t2,$t2,%lo(data_80AD6A88)             \n"
		"ori             $t4,$t3,0x10                           \n"
		"sh              $t1,358($s0)                           \n"
		"sw              $t4,4($s0)                             \n"
		"b               .L000007                               \n"
		"sw              $t2,348($s0)                           \n"
		".L000006:                                              \n"
		"b               .L000004                               \n"
		"sb              $t5,356($s0)                           \n"
		"sb              $zero,356($s0)                         \n"
		".L000004:                                              \n"
		"lh              $v0,358($s0)                           \n"
		"blez            $v0,.L000008                           \n"
		"addiu           $t6,$v0,-1                             \n"
		"sh              $t6,358($s0)                           \n"
		".L000008:                                              \n"
		"jal             func_80AD6830                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000007:                                              \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,56                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

const z64_actor_init_t init_vars = {
	.number = ACT_ID,
	.type = 0x01,
	.room = 0x00,
	.flags = 0x00000000,
	.object = OBJ_ID,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = data_80AD6760,
	.dest = data_80AD67FC,
	.main = data_80AD6C5C,
	.draw = draw
};
