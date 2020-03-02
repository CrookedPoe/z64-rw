[-] zzcovl v0.01 r0  <z64.me> (based on zovldis by Kjartan Skjervoy <kskjer@gmail.com> and Rhett Osborne <rmo@spinout182.com>)
[-] Built: Jul 27 2019 14:55:38
[-] Input file: En_Nutsball-nzle.zovl
[-] Start address 0x80ABBA50.
#include <z64ovl/oot/debug.h>

#define OBJ_ID 1

typedef struct {
	z64_actor_t actor;
	uint8_t unknown[100];
} entity_t; /* 01A0 */


/*** function prototypes ***/
void data_80ABBB0C(void); /* 0 internal, 1 external, 10 lines */
void data_80ABBB34(void); /* 0 internal, 1 external, 30 lines */
void data_80ABBBA8(void); /* 0 internal, 4 external, 124 lines */
void data_80ABBA50(void); /* 0 internal, 5 external, 49 lines */
void data_80ABBE90(void); /* 0 internal, 6 external, 68 lines */
void data_80ABBD74(void); /* 0 internal, 6 external, 73 lines */


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
	0x000D0000 /* 2 bytes, expanded to 4 for alignment */,
	0x00000000,
	0x00000000,
	0x00000000 /* 2 bytes, expanded to 4 for alignment */
};
const uint32_t data_80ABBFEC[] =
{
	0x01640164,
	0x01680171,
	0x01720000
};
const uint32_t data_80ABBFF8[] =
{
	0x06002028,
	0x060012F0,
	0x06004008,
	0x06002410,
	0x06001890,
	0x00000000,
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
void data_80ABBB0C(void) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBB0C: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"jal             external_func_8005C3AC                 \n"
		"addiu           $a1,$a2,340                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80ABBB34(void) /* 0 internal, 1 external, 30 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBB34: \n"
	);
	asm(
		"lui             $at,0x0001                             \n"
		"addiu           $sp,$sp,-24                            \n"
		"or              $a2,$a0,$zero                          \n"
		"ori             $at,$at,0x17a4                         \n"
		"sw              $ra,20($sp)                            \n"
		"addu            $a0,$a1,$at                            \n"
		"lb              $a1,336($a2)                           \n"
		"jal             external_func_80098188                 \n"
		"sw              $a2,24($sp)                            \n"
		"beq             $v0,$zero,.L000002                     \n"
		"lw              $a2,24($sp)                            \n"
		"lui             $at,0x4120                             \n"
		"lb              $t6,336($a2)                           \n"
		"mtc1            $at,$f4                                \n"
		"lui             $t7,%hi(data_80ABBE90)                 \n"
		"lui             $t9,%hi(data_80ABBBA8)                 \n"
		"addiu           $t7,$t7,%lo(data_80ABBE90)             \n"
		"addiu           $t8,$zero,30                           \n"
		"addiu           $t9,$t9,%lo(data_80ABBBA8)             \n"
		"sw              $t7,308($a2)                           \n"
		"sh              $zero,182($a2)                         \n"
		"sh              $t8,338($a2)                           \n"
		"sw              $t9,332($a2)                           \n"
		"sb              $t6,30($a2)                            \n"
		"swc1            $f4,104($a2)                           \n"
		".L000002:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80ABBBA8(void) /* 0 internal, 4 external, 124 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBBA8: \n"
	);
	asm(
		"addiu           $sp,$sp,-88                            \n"
		"sw              $ra,52($sp)                            \n"
		"sw              $s0,48($sp)                            \n"
		"sw              $a1,92($sp)                            \n"
		"lh              $t7,338($a0)                           \n"
		"lw              $v1,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"addiu           $t8,$t7,-1                             \n"
		"sh              $t8,338($a0)                           \n"
		"lh              $t9,338($a0)                           \n"
		"lui             $at,0xBF80                             \n"
		"bnel            $t9,$zero,.L000003                     \n"
		"lh              $t0,24($s0)                            \n"
		"mtc1            $at,$f4                                \n"
		"nop                                                    \n"
		"swc1            $f4,108($a0)                           \n"
		"lh              $t0,24($s0)                            \n"
		".L000003:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		"addiu           $t1,$t0,10920                          \n"
		"andi            $t2,$v0,0x8                            \n"
		"bne             $t2,$zero,.L000004                     \n"
		"sh              $t1,24($s0)                            \n"
		"andi            $t3,$v0,0x1                            \n"
		"bnel            $t3,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t4,356($s0)                           \n"
		"andi            $t5,$t4,0x2                            \n"
		"bnel            $t5,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t6,357($s0)                           \n"
		"andi            $t7,$t6,0x2                            \n"
		"bnel            $t7,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t8,358($s0)                           \n"
		"andi            $t9,$t8,0x2                            \n"
		"beql            $t9,$zero,.L000006                     \n"
		"lh              $t6,338($s0)                           \n"
		".L000004:                                              \n"
		"lb              $v0,334($v1)                           \n"
		".L000005:                                              \n"
		"addiu           $at,$zero,1                            \n"
		"beq             $v0,$at,.L000007                       \n"
		"addiu           $at,$zero,2                            \n"
		"bne             $v0,$at,.L000008                       \n"
		"lui             $t0,0x8016                             \n"
		"lw              $t0,-6556($t0)                         \n"
		"bnel            $t0,$zero,.L000009                     \n"
		"lwc1            $f6,36($s0)                            \n"
		".L000007:                                              \n"
		"lbu             $v0,356($s0)                           \n"
		"andi            $t1,$v0,0x2                            \n"
		"beq             $t1,$zero,.L000008                     \n"
		"andi            $t2,$v0,0x10                           \n"
		"beq             $t2,$zero,.L000008                     \n"
		"andi            $t3,$v0,0x4                            \n"
		"beq             $t3,$zero,.L000008                     \n"
		"andi            $t5,$v0,0xffe9                         \n"
		"sb              $t5,356($s0)                           \n"
		"ori             $t6,$t5,0x8                            \n"
		"addiu           $t7,$zero,2                            \n"
		"sb              $t6,356($s0)                           \n"
		"sw              $t7,364($s0)                           \n"
		"addiu           $a0,$v1,2592                           \n"
		"addiu           $a1,$sp,76                             \n"
		"jal             external_func_800D20CC                 \n"
		"or              $a2,$zero,$zero                        \n"
		"lh              $t8,78($sp)                            \n"
		"ori             $at,$zero,0x8000                       \n"
		"addiu           $t0,$zero,30                           \n"
		"addu            $t9,$t8,$at                            \n"
		"sh              $t9,50($s0)                            \n"
		"beq             $zero,$zero,.L000010                   \n"
		"sh              $t0,338($s0)                           \n"
		".L000008:                                              \n"
		"lwc1            $f6,36($s0)                            \n"
		".L000009:                                              \n"
		"lui             $at,0x4080                             \n"
		"mtc1            $at,$f10                               \n"
		"swc1            $f6,64($sp)                            \n"
		"lwc1            $f8,40($s0)                            \n"
		"addiu           $t1,$zero,7                            \n"
		"addiu           $t2,$zero,3                            \n"
		"add.s           $f16,$f8,$f10                          \n"
		"addiu           $t3,$zero,15                           \n"
		"addiu           $t4,$zero,-1                           \n"
		"addiu           $t5,$zero,10                           \n"
		"swc1            $f16,68($sp)                           \n"
		"lwc1            $f18,44($s0)                           \n"
		"sw              $zero,36($sp)                          \n"
		"sw              $t5,32($sp)                            \n"
		"sw              $t4,28($sp)                            \n"
		"sw              $t3,24($sp)                            \n"
		"sw              $t2,20($sp)                            \n"
		"sw              $t1,16($sp)                            \n"
		"lw              $a0,92($sp)                            \n"
		"addiu           $a1,$sp,64                             \n"
		"lui             $a2,0x40C0                             \n"
		"or              $a3,$zero,$zero                        \n"
		"jal             external_func_800297A4                 \n"
		"swc1            $f18,72($sp)                           \n"
		"lw              $a0,92($sp)                            \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$zero,20                           \n"
		"jal             external_func_8006BAD8                 \n"
		"addiu           $a3,$zero,14528                        \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000011                   \n"
		"lw              $ra,52($sp)                            \n"
		"lh              $t6,338($s0)                           \n"
		".L000006:                                              \n"
		"addiu           $at,$zero,-300                         \n"
		"bnel            $t6,$at,.L000011                       \n"
		"lw              $ra,52($sp)                            \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		".L000010:                                              \n"
		"lw              $ra,52($sp)                            \n"
		".L000011:                                              \n"
		"lw              $s0,48($sp)                            \n"
		"addiu           $sp,$sp,88                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80ABBA50(void) /* 0 internal, 5 external, 49 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBA50: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lui             $a2,0x8003                             \n"
		"addiu           $a2,$a2,-18964                         \n"
		"lui             $a1,0x43C8                             \n"
		"addiu           $a0,$a0,180                            \n"
		"jal             external_func_8002B1E0                 \n"
		"lui             $a3,0x4150                             \n"
		"addiu           $a1,$s0,340                            \n"
		"sw              $a1,36($sp)                            \n"
		"jal             external_func_8005C364                 \n"
		"lw              $a0,52($sp)                            \n"
		"lui             $a3,%hi(data_80ABBFC0)                 \n"
		"lw              $a1,36($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_80ABBFC0)             \n"
		"lw              $a0,52($sp)                            \n"
		"jal             external_func_8005C4AC                 \n"
		"or              $a2,$s0,$zero                          \n"
		"lh              $t6,28($s0)                            \n"
		"lw              $a0,52($sp)                            \n"
		"lui             $at,0x0001                             \n"
		"lui             $a1,%hi(data_80ABBFEC)                 \n"
		"sll             $t7,$t6,1                              \n"
		"addu            $a1,$a1,$t7                            \n"
		"ori             $at,$at,0x17a4                         \n"
		"lh              $a1,%lo(data_80ABBFEC)($a1)            \n"
		"jal             external_func_8009812C                 \n"
		"addu            $a0,$a0,$at                            \n"
		"sb              $v0,336($s0)                           \n"
		"lb              $t8,336($s0)                           \n"
		"lui             $t9,%hi(data_80ABBB34)                 \n"
		"addiu           $t9,$t9,%lo(data_80ABBB34)             \n"
		"bgezl           $t8,.L000000                           \n"
		"sw              $t9,332($s0)                           \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000001                   \n"
		"lw              $ra,28($sp)                            \n"
		"sw              $t9,332($s0)                           \n"
		".L000000:                                              \n"
		"lw              $ra,28($sp)                            \n"
		".L000001:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80ABBE90(void) /* 0 internal, 6 external, 68 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBE90: \n"
	);
	asm(
		"addiu           $sp,$sp,-72                            \n"
		"sw              $s1,24($sp)                            \n"
		"or              $s1,$a1,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,20($sp)                            \n"
		"sw              $a0,72($sp)                            \n"
		"lw              $a1,0($a1)                             \n"
		"lui             $a2,%hi(data_80ABC010)                 \n"
		"addiu           $a2,$a2,%lo(data_80ABC010)             \n"
		"addiu           $a0,$sp,48                             \n"
		"addiu           $a3,$zero,327                          \n"
		"jal             external_func_800C6AC4                 \n"
		"or              $s0,$a1,$zero                          \n"
		"jal             external_func_80093D18                 \n"
		"lw              $a0,0($s1)                             \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x1da0                         \n"
		"addu            $a0,$s1,$at                            \n"
		"jal             external_func_800D0930                 \n"
		"addiu           $a1,$zero,1                            \n"
		"lw              $t6,72($sp)                            \n"
		"lui             $at,%hi(data_80ABC04C)                 \n"
		"lwc1            $f8,%lo(data_80ABC04C)($at)            \n"
		"lh              $t7,24($t6)                            \n"
		"addiu           $a1,$zero,1                            \n"
		"mtc1            $t7,$f4                                \n"
		"nop                                                    \n"
		"cvt.s.w         $f6,$f4                                \n"
		"mul.s           $f12,$f6,$f8                           \n"
		"jal             external_func_800D0ED4                 \n"
		"nop                                                    \n"
		"lw              $v0,704($s0)                           \n"
		"lui             $t9,0xDA38                             \n"
		"ori             $t9,$t9,0x3                            \n"
		"addiu           $t8,$v0,8                              \n"
		"sw              $t8,704($s0)                           \n"
		"sw              $t9,0($v0)                             \n"
		"lw              $a0,0($s1)                             \n"
		"lui             $a1,%hi(data_80ABC024)                 \n"
		"addiu           $a1,$a1,%lo(data_80ABC024)             \n"
		"addiu           $a2,$zero,333                          \n"
		"jal             external_func_800D1A88                 \n"
		"sw              $v0,44($sp)                            \n"
		"lw              $v1,44($sp)                            \n"
		"lui             $t1,0xDE00                             \n"
		"lui             $t5,%hi(data_80ABBFF8)                 \n"
		"sw              $v0,4($v1)                             \n"
		"lw              $v0,704($s0)                           \n"
		"lui             $a2,%hi(data_80ABC038)                 \n"
		"addiu           $a2,$a2,%lo(data_80ABC038)             \n"
		"addiu           $t0,$v0,8                              \n"
		"sw              $t0,704($s0)                           \n"
		"sw              $t1,0($v0)                             \n"
		"lw              $t2,72($sp)                            \n"
		"addiu           $a0,$sp,48                             \n"
		"addiu           $a3,$zero,337                          \n"
		"lh              $t3,28($t2)                            \n"
		"sll             $t4,$t3,2                              \n"
		"addu            $t5,$t5,$t4                            \n"
		"lw              $t5,%lo(data_80ABBFF8)($t5)            \n"
		"sw              $t5,4($v0)                             \n"
		"jal             external_func_800C6B54                 \n"
		"lw              $a1,0($s1)                             \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,20($sp)                            \n"
		"lw              $s1,24($sp)                            \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,72                             \n"
	);
}
void data_80ABBD74(void) /* 0 internal, 6 external, 73 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBD74: \n"
	);
	asm(
		"addiu           $sp,$sp,-64                            \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s2,40($sp)                            \n"
		"sw              $s1,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"lw              $v0,7236($a1)                          \n"
		"lui             $at,0x3000                             \n"
		"ori             $at,$at,0xc0                           \n"
		"lw              $t6,1660($v0)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"or              $s2,$a1,$zero                          \n"
		"and             $t7,$t6,$at                            \n"
		"beql            $t7,$zero,.L000012                     \n"
		"lw              $t9,332($s0)                           \n"
		"lw              $t9,332($a0)                           \n"
		"lui             $t8,%hi(data_80ABBB34)                 \n"
		"addiu           $t8,$t8,%lo(data_80ABBB34)             \n"
		"bnel            $t8,$t9,.L000013                       \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $t9,332($s0)                           \n"
		".L000012:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a1,$s2,$zero                          \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"jal             external_func_8002D8E0                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $v0,%hi(data_80ABBFC0)                 \n"
		"addiu           $v0,$v0,%lo(data_80ABBFC0)             \n"
		"lh              $t0,32($v0)                            \n"
		"lh              $t1,34($v0)                            \n"
		"addiu           $t2,$zero,5                            \n"
		"mtc1            $t0,$f4                                \n"
		"mtc1            $t1,$f6                                \n"
		"sw              $t2,20($sp)                            \n"
		"cvt.s.w         $f4,$f4                                \n"
		"or              $a0,$s2,$zero                          \n"
		"or              $a1,$s0,$zero                          \n"
		"lui             $a2,0x4120                             \n"
		"cvt.s.w         $f8,$f6                                \n"
		"mfc1            $a3,$f4                                \n"
		"jal             external_func_8002E4B4                 \n"
		"swc1            $f8,16($sp)                            \n"
		"addiu           $s1,$s0,340                            \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             external_func_800626DC                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t3,4($s0)                             \n"
		"lui             $at,0x0100                             \n"
		"or              $a0,$s2,$zero                          \n"
		"or              $t4,$t3,$at                            \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x1e60                         \n"
		"sw              $t4,4($s0)                             \n"
		"addu            $a1,$s2,$at                            \n"
		"sw              $a1,48($sp)                            \n"
		"jal             external_func_8005D79C                 \n"
		"or              $a2,$s1,$zero                          \n"
		"or              $a0,$s2,$zero                          \n"
		"lw              $a1,48($sp)                            \n"
		"jal             external_func_8005D9F4                 \n"
		"or              $a2,$s1,$zero                          \n"
		"or              $a0,$s2,$zero                          \n"
		"lw              $a1,48($sp)                            \n"
		"jal             external_func_8005DC4C                 \n"
		"or              $a2,$s1,$zero                          \n"
		"lw              $ra,44($sp)                            \n"
		".L000013:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"lw              $s1,36($sp)                            \n"
		"lw              $s2,40($sp)                            \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,64                             \n"
	);
}
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

