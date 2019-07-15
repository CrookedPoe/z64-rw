#include <z64ovl/mm/u10.h>

#define OBJ_ID 438

typedef struct {
	z64_actor_t actor;
	uint8_t unknown[404];
} entity_t; /* 02D0 */


/*** function prototypes ***/
void data_80BE9214(void); /* 0 internal, 0 external, 4 lines */
void data_80BE9380(void); /* 0 internal, 0 external, 23 lines */
void func_80BE9148(void); /* 0 internal, 0 external, 40 lines */
void data_80BE9090(void); /* 0 internal, 1 external, 11 lines */
void data_80BE93D8(void); /* 0 internal, 2 external, 22 lines */
void func_80BE90BC(void); /* 0 internal, 2 external, 35 lines */
void func_80BE91DC(void); /* 1 internal, 0 external, 14 lines */
void data_80BE8F20(void); /* 1 internal, 4 external, 96 lines */
void data_80BE9224(void); /* 1 internal, 9 external, 92 lines */


/*** variables ***/
const uint32_t data_80BE9450[] =
{
	0x0A000009,
	0x20010000,
	0x00000000,
	0x00000000,
	0x00000000,
	0xF7CFFFFF,
	0x00000000,
	0x00000100,
	0x0014003C,
	0x00000000,
	0x00000000
};
const uint32_t data_80BE947C[] =
{
	0x06006C18,
	0x06002A84,
	0x06003BFC,
	0x06003380,
	0x06004770
};
const uint32_t data_80BE9490[] =
{
	0x00000000,
	0x02000000,
	0x00000000,
	0x00000000
};


/*** functions ***/
void data_80BE9214(void) /* 0 internal, 0 external, 4 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE9214: \n"
	);
	asm(
		"sw              $a0,0($sp)                             \n"
		"sw              $a1,4($sp)                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80BE9380(void) /* 0 internal, 0 external, 23 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE9380: \n"
	);
	asm(
		"sw              $a0,0($sp)                             \n"
		"sw              $a2,8($sp)                             \n"
		"sw              $a3,12($sp)                            \n"
		"addiu           $at,$zero,16                           \n"
		"bne             $a1,$at,.L000012                       \n"
		"lw              $v0,20($sp)                            \n"
		"lw              $v1,16($sp)                            \n"
		"lh              $t7,602($v0)                           \n"
		"lh              $t6,0($v1)                             \n"
		"lh              $t9,2($v1)                             \n"
		"lh              $t2,4($v1)                             \n"
		"addu            $t8,$t6,$t7                            \n"
		"sh              $t8,0($v1)                             \n"
		"lh              $t0,600($v0)                           \n"
		"addu            $t1,$t9,$t0                            \n"
		"sh              $t1,2($v1)                             \n"
		"lh              $t3,604($v0)                           \n"
		"addu            $t4,$t2,$t3                            \n"
		"sh              $t4,4($v1)                             \n"
		".L000012:                                              \n"
		"or              $v0,$zero,$zero                        \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80BE9148(void) /* 0 internal, 0 external, 40 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80BE9148: \n"
	);
	asm(
		"lh              $t6,626($a0)                           \n"
		"lh              $t7,50($a0)                            \n"
		"lui             $at,0x4348                             \n"
		"mtc1            $at,$f6                                \n"
		"subu            $v0,$t6,$t7                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bgez            $v0,.L000004                           \n"
		"or              $v1,$v0,$zero                          \n"
		"b               .L000004                               \n"
		"subu            $v1,$zero,$v0                          \n"
		".L000004:                                              \n"
		"lwc1            $f4,152($a0)                           \n"
		"sh              $zero,608($a0)                         \n"
		"slti            $at,$v1,20000                          \n"
		"c.lt.s          $f4,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000005                               \n"
		"nop                                                    \n"
		"beq             $at,$zero,.L000005                     \n"
		"nop                                                    \n"
		"lh              $t8,626($a0)                           \n"
		"lh              $t9,50($a0)                            \n"
		"addiu           $t1,$zero,10000                        \n"
		"subu            $t0,$t8,$t9                            \n"
		"sh              $t0,608($a0)                           \n"
		"lh              $v0,608($a0)                           \n"
		"slti            $at,$v0,10001                          \n"
		"bnel            $at,$zero,.L000006                     \n"
		"slti            $at,$v0,-10000                         \n"
		"jr              $ra                                    \n"
		"sh              $t1,608($a0)                           \n"
		"slti            $at,$v0,-10000                         \n"
		".L000006:                                              \n"
		"beq             $at,$zero,.L000005                     \n"
		"addiu           $t2,$zero,-10000                       \n"
		"sh              $t2,608($a0)                           \n"
		".L000005:                                              \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80BE9090(void) /* 0 internal, 1 external, 11 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE9090: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"or              $a3,$a1,$zero                          \n"
		"or              $a0,$a3,$zero                          \n"
		"jal             0x800E11EC                 \n"
		"addiu           $a1,$a2,644                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80BE93D8(void) /* 0 internal, 2 external, 22 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE93D8: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a0,40($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lw              $t6,44($sp)                            \n"
		"jal             0x8012C28C                 \n"
		"lw              $a0,0($t6)                             \n"
		"lw              $v0,40($sp)                            \n"
		"lui             $t7,%hi(data_80BE9380)                 \n"
		"addiu           $t7,$t7,%lo(data_80BE9380)             \n"
		"lw              $a1,328($v0)                           \n"
		"lw              $a2,356($v0)                           \n"
		"lbu             $a3,326($v0)                           \n"
		"sw              $zero,20($sp)                          \n"
		"sw              $t7,16($sp)                            \n"
		"lw              $a0,44($sp)                            \n"
		"jal             0x80133F28                 \n"
		"sw              $v0,24($sp)                            \n"
		"lw              $ra,36($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80BE90BC(void) /* 0 internal, 2 external, 35 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80BE90BC: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a0,40($sp)                            \n"
		"lw              $t6,40($sp)                            \n"
		"sll             $t7,$a1,2                              \n"
		"lui             $a0,%hi(data_80BE947C)                 \n"
		"addu            $a0,$a0,$t7                            \n"
		"sw              $a1,612($t6)                           \n"
		"jal             0x80134748                 \n"
		"lw              $a0,%lo(data_80BE947C)($a0)            \n"
		"mtc1            $v0,$f4                                \n"
		"lw              $t0,40($sp)                            \n"
		"lui             $t9,%hi(data_80BE9490)                 \n"
		"cvt.s.w         $f0,$f4                                \n"
		"lw              $v1,612($t0)                           \n"
		"lui             $at,0xC120                             \n"
		"mtc1            $at,$f6                                \n"
		"addu            $t9,$t9,$v1                            \n"
		"lui             $a1,%hi(data_80BE947C)                 \n"
		"swc1            $f0,628($t0)                           \n"
		"lbu             $t9,%lo(data_80BE9490)($t9)            \n"
		"sll             $t8,$v1,2                              \n"
		"addu            $a1,$a1,$t8                            \n"
		"lw              $a1,%lo(data_80BE947C)($a1)            \n"
		"swc1            $f0,16($sp)                            \n"
		"lui             $a2,0x3F80                             \n"
		"addiu           $a3,$zero,0                            \n"
		"addiu           $a0,$t0,324                            \n"
		"swc1            $f6,24($sp)                            \n"
		"jal             0x801373E8                 \n"
		"sw              $t9,20($sp)                            \n"
		"lw              $ra,36($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80BE91DC(void) /* 1 internal, 0 external, 14 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80BE91DC: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a1,$zero,$zero                        \n"
		"jal             func_80BE90BC                          \n"
		"sw              $a0,24($sp)                            \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $t6,%hi(data_80BE9214)                 \n"
		"addiu           $t6,$t6,%lo(data_80BE9214)             \n"
		"sh              $zero,632($a0)                         \n"
		"sw              $t6,596($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80BE8F20(void) /* 1 internal, 4 external, 96 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE8F20: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $s0,40($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lui             $a2,0x800B                             \n"
		"addiu           $a2,$a2,16320                          \n"
		"addiu           $a0,$s0,188                            \n"
		"addiu           $a1,$zero,0                            \n"
		"jal             0x800B3BA4                 \n"
		"lui             $a3,0x41C8                             \n"
		"lui             $a2,0x0601                             \n"
		"lui             $a3,0x0600                             \n"
		"addiu           $t6,$s0,392                            \n"
		"addiu           $t7,$s0,494                            \n"
		"addiu           $t8,$zero,17                           \n"
		"sw              $t8,24($sp)                            \n"
		"sw              $t7,20($sp)                            \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a3,$a3,15356                          \n"
		"addiu           $a2,$a2,-10688                         \n"
		"lw              $a0,52($sp)                            \n"
		"jal             0x80136B30                 \n"
		"addiu           $a1,$s0,324                            \n"
		"lh              $v0,28($s0)                            \n"
		"lh              $t0,50($s0)                            \n"
		"addiu           $t9,$zero,255                          \n"
		"sb              $t9,182($s0)                           \n"
		"sw              $v0,616($s0)                           \n"
		"bne             $v0,$zero,.L000000                     \n"
		"sh              $t0,626($s0)                           \n"
		"lui             $v0,0x801F                             \n"
		"addiu           $t1,$zero,1                            \n"
		"addiu           $v0,$v0,-2448                          \n"
		"sw              $t1,620($s0)                           \n"
		"lbu             $t2,3895($v0)                          \n"
		"andi            $t3,$t2,0x80                           \n"
		"bnel            $t3,$zero,.L000001                     \n"
		"lui             $at,0xC040                             \n"
		"lw              $t4,24($v0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"bne             $t4,$at,.L000002                       \n"
		"nop                                                    \n"
		"lw              $t5,16($v0)                            \n"
		"bnel            $t5,$zero,.L000001                     \n"
		"lui             $at,0xC040                             \n"
		".L000002:                                              \n"
		"nop                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000001                               \n"
		"lui             $at,0xC040                             \n"
		".L000000:                                              \n"
		"lui             $v0,0x801F                             \n"
		"addiu           $t6,$zero,30                           \n"
		"addiu           $t7,$zero,60                           \n"
		"addiu           $v0,$v0,-2448                          \n"
		"sh              $t6,708($s0)                           \n"
		"sh              $t7,710($s0)                           \n"
		"sh              $zero,712($s0)                         \n"
		"lbu             $t8,3895($v0)                          \n"
		"andi            $t9,$t8,0x80                           \n"
		"bne             $t9,$zero,.L000003                     \n"
		"nop                                                    \n"
		"lw              $t0,24($v0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"bnel            $t0,$at,.L000001                       \n"
		"lui             $at,0xC040                             \n"
		"lw              $t1,16($v0)                            \n"
		"beql            $t1,$zero,.L000001                     \n"
		"lui             $at,0xC040                             \n"
		".L000003:                                              \n"
		"nop                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $at,0xC040                             \n"
		".L000001:                                              \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t2,$zero,6                            \n"
		"sb              $t2,31($s0)                            \n"
		"lui             $a3,%hi(data_80BE9450)                 \n"
		"swc1            $f4,116($s0)                           \n"
		"lw              $a0,52($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_80BE9450)             \n"
		"addiu           $a1,$s0,644                            \n"
		"jal             0x800E1374                 \n"
		"or              $a2,$s0,$zero                          \n"
		"lw              $t3,4($s0)                             \n"
		"lui             $at,0x0800                             \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $t4,$t3,$at                            \n"
		"jal             func_80BE91DC                          \n"
		"sw              $t4,4($s0)                             \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80BE9224(void) /* 1 internal, 9 external, 92 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE9224: \n"
	);
	asm(
		"addiu           $sp,$sp,-56                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,60($sp)                            \n"
		"jal             0x80136CD0                 \n"
		"addiu           $a0,$s0,324                            \n"
		"lh              $v0,624($s0)                           \n"
		"beq             $v0,$zero,.L000007                     \n"
		"addiu           $t6,$v0,-1                             \n"
		"sh              $t6,624($s0)                           \n"
		".L000007:                                              \n"
		"lw              $t8,616($s0)                           \n"
		"lh              $t7,50($s0)                            \n"
		"lui             $v0,0x801F                             \n"
		"beq             $t8,$zero,.L000008                     \n"
		"sh              $t7,190($s0)                           \n"
		"addiu           $v0,$v0,-2448                          \n"
		"lw              $t9,24($v0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"bnel            $t9,$at,.L000009                       \n"
		"lw              $t9,596($s0)                           \n"
		"lw              $t0,16($v0)                            \n"
		"beql            $t0,$zero,.L000009                     \n"
		"lw              $t9,596($s0)                           \n"
		"nop                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000010                               \n"
		"lw              $ra,36($sp)                            \n"
		".L000008:                                              \n"
		"lw              $t9,596($s0)                           \n"
		".L000009:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a1,60($sp)                            \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"jal             0x800B6A88                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f0                                \n"
		"lui             $at,0x4248                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t1,$zero,29                           \n"
		"mfc1            $a2,$f0                                \n"
		"mfc1            $a3,$f0                                \n"
		"sw              $t1,20($sp)                            \n"
		"lw              $a0,60($sp)                            \n"
		"or              $a1,$s0,$zero                          \n"
		"jal             0x800B78B8                 \n"
		"swc1            $f4,16($sp)                            \n"
		"lui             $a1,0x3C23                             \n"
		"ori             $a1,$a1,0xd70a                         \n"
		"jal             0x800B67E0                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t2,620($s0)                           \n"
		"beql            $t2,$zero,.L000011                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80BE9148                          \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000011:                                              \n"
		"jal             0x800B675C                 \n"
		"lui             $a1,0x4270                             \n"
		"lh              $a1,608($s0)                           \n"
		"sw              $zero,16($sp)                          \n"
		"addiu           $a0,$s0,602                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             0x800FFEBC                 \n"
		"addiu           $a3,$zero,3000                         \n"
		"lh              $a1,606($s0)                           \n"
		"sw              $zero,16($sp)                          \n"
		"addiu           $a0,$s0,600                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             0x800FFEBC                 \n"
		"addiu           $a3,$zero,1000                         \n"
		"addiu           $a2,$s0,644                            \n"
		"or              $a1,$a2,$zero                          \n"
		"sw              $a2,44($sp)                            \n"
		"jal             0x800E7DF8                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a0,60($sp)                            \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x8884                         \n"
		"lw              $a2,44($sp)                            \n"
		"jal             0x800E2928                 \n"
		"addu            $a1,$a0,$at                            \n"
		"lw              $ra,36($sp)                            \n"
		".L000010:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,56                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
const z64_actor_init_t init_vars = {
	.number = 0x026D,
	.type = 0x04,
	.room = 0x00,
	.flags = 0x00000009,
	.object = OBJ_ID,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = data_80BE8F20,
	.dest = data_80BE9090,
	.main = data_80BE9224,
	.draw = data_80BE93D8
};
