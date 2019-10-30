#include <z64ovl/oot/debug.h>

#define OBJ_ID 20

typedef struct {
	z64_actor_t actor;
	uint8_t unknown[220];
} entity_t; /* 0218 */


/*** function prototypes ***/
void func_80864F00(void); /* 0 internal, 0 external, 2 lines */
void func_80865044(void); /* 0 internal, 0 external, 4 lines */
void func_80865084(void); /* 0 internal, 0 external, 11 lines */
void data_80865830(void); /* 0 internal, 12 external, 177 lines */
void data_80864F80(void); /* 0 internal, 1 external, 18 lines */
void func_80865054(void); /* 0 internal, 0 external, 13 lines */
void data_808657EC(void); /* 0 internal, 0 external, 17 lines */
void data_80864FC4(void); /* 1 internal, 1 external, 34 lines */
void func_80865148(void); /* 0 internal, 1 external, 17 lines */
void data_80864F08(void); /* 1 internal, 2 external, 30 lines */
void func_808650AC(void); /* 1 internal, 2 external, 42 lines */
void data_8086518C(void); /* 6 internal, 16 external, 435 lines */


/*** variables ***/
const uint32_t data_80865B00[] =
{
	0x0A090000,
	0x08030000,
	0x02000000,
	0x00000080,
	0x00010000,
	0xFFCFFFFF,
	0x00000000,
	0x05000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x3F000000,
	0x00000000,
	0x00000000,
	0x3F000000,
	0x00000000,
	0xFFFF64FF,
	0xFF320000
};
const uint32_t data_80865B70[] =
{
	0x00000000,
	0x00000000,
	0x00000000
};
const uint32_t data_80865B7C[] =
{
	0x00000000,
	0x00000000,
	0x44610000
};
const uint32_t data_80865B88[] =
{
	0x00000000,
	0x43FA0000,
	0xC53B8000
};
const uint32_t data_80865B94[] =
{
	0x00000000,
	0xC3FA0000,
	0xC53B8000
};
const uint32_t data_80865BA0[] =
{
	0x00000000,
	0x43FA0000,
	0x44960000
};
const uint32_t data_80865BAC[] =
{
	0x00000000,
	0xC3FA0000,
	0x44960000,
	0x00000000,
	0x00000000,
};
const uint32_t data_80865BC0[] =
{
	0x2E2E2F7A,
	0x5F61726D,
	0x735F686F,
	0x6F6B2E63,
	0x00000000
};
const uint32_t data_80865BD4[] =
{
	0x2E2E2F7A,
	0x5F61726D,
	0x735F686F,
	0x6F6B2E63,
	0x00000000
};
const uint32_t data_80865BE8[] =
{
	0x2E2E2F7A,
	0x5F61726D,
	0x735F686F,
	0x6F6B2E63,
	0x00000000
};
const uint32_t data_80865BFC[] =
{
	0x2E2E2F7A,
	0x5F61726D,
	0x735F686F,
	0x6F6B2E63,
	0x00000000
};
const uint32_t data_80865C10[] =
{
	0x380000FD
};
const uint32_t data_80865C14[] =
{
	0x3C75C28F
};
const uint32_t data_80865C18[] =
{
	0x3C23D70A,
	0x00000000
};


/*** functions ***/
void func_80864F00(void) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80864F00: \n"
	);
	asm(
		"jr              $ra                                    \n"
		"sw              $a1,532($a0)                           \n"
	);
}
void func_80865044(void) /* 0 internal, 0 external, 4 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865044: \n"
	);
	asm(
		"lw              $v0,280($a0)                           \n"
		"sw              $v0,284($a0)                           \n"
		"jr              $ra                                    \n"
		"sw              $a0,280($v0)                           \n"
	);
}
void func_80865084(void) /* 0 internal, 0 external, 11 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865084: \n"
	);
	asm(
		"lw              $v0,512($a0)                           \n"
		"beq             $v0,$zero,.L000004                     \n"
		"nop                                                    \n"
		"lw              $t6,4($v0)                             \n"
		"addiu           $at,$zero,-8193                        \n"
		"and             $t7,$t6,$at                            \n"
		"sw              $t7,4($v0)                             \n"
		"sw              $zero,512($a0)                         \n"
		".L000004:                                              \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80865830(void) /* 0 internal, 12 external, 177 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80865830: \n"
	);
	asm(
		"addiu           $sp,$sp,-144                           \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,148($sp)                           \n"
		"lw              $v0,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"lw              $t7,308($v0)                           \n"
		"beql            $t7,$zero,.L000035                     \n"
		"lw              $ra,36($sp)                            \n"
		"lbu             $t8,349($v0)                           \n"
		"addiu           $at,$zero,15                           \n"
		"addiu           $a0,$sp,68                             \n"
		"bne             $t8,$at,.L000036                       \n"
		"lui             $a2,%hi(data_80865BC0)                 \n"
		"lw              $a1,0($a1)                             \n"
		"sw              $v0,132($sp)                           \n"
		"addiu           $a2,$a2,%lo(data_80865BC0)             \n"
		"addiu           $a3,$zero,850                          \n"
		"jal             0x800C6AC4                 \n"
		"sw              $a1,84($sp)                            \n"
		"lw              $t9,532($s0)                           \n"
		"lui             $t0,%hi(data_8086518C)                 \n"
		"addiu           $t0,$t0,%lo(data_8086518C)             \n"
		"bne             $t9,$t0,.L000037                       \n"
		"nop                                                    \n"
		"lh              $t1,528($s0)                           \n"
		"lui             $a0,%hi(data_80865B7C)                 \n"
		"addiu           $a0,$a0,%lo(data_80865B7C)             \n"
		"bgtz            $t1,.L000038                           \n"
		"nop                                                    \n"
		".L000037:                                              \n"
		"lui             $a0,%hi(data_80865B70)                 \n"
		"addiu           $a0,$a0,%lo(data_80865B70)             \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$s0,488                            \n"
		"lui             $a0,%hi(data_80865B88)                 \n"
		"addiu           $a0,$a0,%lo(data_80865B88)             \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$sp,108                            \n"
		"lui             $a0,%hi(data_80865B94)                 \n"
		"addiu           $a0,$a0,%lo(data_80865B94)             \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$sp,96                             \n"
		"b               .L000039                               \n"
		"sw              $zero,460($s0)                         \n"
		".L000038:                                              \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$s0,488                            \n"
		"lui             $a0,%hi(data_80865BA0)                 \n"
		"addiu           $a0,$a0,%lo(data_80865BA0)             \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$sp,108                            \n"
		"lui             $a0,%hi(data_80865BAC)                 \n"
		"addiu           $a0,$a0,%lo(data_80865BAC)             \n"
		"jal             0x800D1AF4                 \n"
		"addiu           $a1,$sp,96                             \n"
		".L000039:                                              \n"
		"addiu           $t2,$sp,96                             \n"
		"sw              $t2,16($sp)                            \n"
		"lw              $a0,148($sp)                           \n"
		"addiu           $a1,$s0,332                            \n"
		"addiu           $a2,$s0,460                            \n"
		"jal             0x80090480                 \n"
		"addiu           $a3,$sp,108                            \n"
		"lw              $t3,148($sp)                           \n"
		"jal             0x80093D18                 \n"
		"lw              $a0,0($t3)                             \n"
		"lw              $a3,84($sp)                            \n"
		"lui             $t5,0xDA38                             \n"
		"ori             $t5,$t5,0x3                            \n"
		"lw              $v0,704($a3)                           \n"
		"lui             $a1,%hi(data_80865BD4)                 \n"
		"addiu           $a1,$a1,%lo(data_80865BD4)             \n"
		"addiu           $t4,$v0,8                              \n"
		"sw              $t4,704($a3)                           \n"
		"sw              $t5,0($v0)                             \n"
		"lw              $t7,148($sp)                           \n"
		"addiu           $a2,$zero,895                          \n"
		"lw              $a0,0($t7)                             \n"
		"jal             0x800D1A88                 \n"
		"sw              $v0,64($sp)                            \n"
		"lw              $v1,64($sp)                            \n"
		"lui             $t9,0x0603                             \n"
		"addiu           $t9,$t9,-19832                         \n"
		"sw              $v0,4($v1)                             \n"
		"lw              $a0,84($sp)                            \n"
		"lui             $t6,0xDE00                             \n"
		"or              $a3,$zero,$zero                        \n"
		"lw              $v0,704($a0)                           \n"
		"addiu           $t8,$v0,8                              \n"
		"sw              $t8,704($a0)                           \n"
		"sw              $t9,4($v0)                             \n"
		"sw              $t6,0($v0)                             \n"
		"lw              $a2,44($s0)                            \n"
		"lwc1            $f14,40($s0)                           \n"
		"jal             0x800D0984                 \n"
		"lwc1            $f12,36($s0)                           \n"
		"lw              $a0,132($sp)                           \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$sp,120                            \n"
		"jal             0x80077ED0                 \n"
		"addiu           $a0,$a0,968                            \n"
		"lwc1            $f12,120($sp)                          \n"
		"lwc1            $f14,128($sp)                          \n"
		"mul.s           $f4,$f12,$f12                          \n"
		"nop                                                    \n"
		"mul.s           $f6,$f14,$f14                          \n"
		"add.s           $f2,$f4,$f6                            \n"
		"sqrt.s          $f0,$f2                                \n"
		"swc1            $f2,88($sp)                            \n"
		"jal             0x800FD250                 \n"
		"swc1            $f0,92($sp)                            \n"
		"mov.s           $f12,$f0                               \n"
		"jal             0x800D0D20                 \n"
		"addiu           $a1,$zero,1                            \n"
		"lwc1            $f2,124($sp)                           \n"
		"lwc1            $f14,92($sp)                           \n"
		"jal             0x800FD250                 \n"
		"neg.s           $f12,$f2                               \n"
		"mov.s           $f12,$f0                               \n"
		"jal             0x800D0B70                 \n"
		"addiu           $a1,$zero,1                            \n"
		"lwc1            $f2,124($sp)                           \n"
		"lwc1            $f10,88($sp)                           \n"
		"lui             $at,%hi(data_80865C14)                 \n"
		"mul.s           $f8,$f2,$f2                            \n"
		"lwc1            $f12,%lo(data_80865C14)($at)           \n"
		"lui             $at,%hi(data_80865C18)                 \n"
		"lwc1            $f16,%lo(data_80865C18)($at)           \n"
		"addiu           $a3,$zero,1                            \n"
		"mov.s           $f14,$f12                              \n"
		"add.s           $f0,$f8,$f10                           \n"
		"sqrt.s          $f0,$f0                                \n"
		"mul.s           $f18,$f0,$f16                          \n"
		"mfc1            $a2,$f18                               \n"
		"jal             0x800D0A8C                 \n"
		"nop                                                    \n"
		"lw              $v1,84($sp)                            \n"
		"lui             $t1,0xDA38                             \n"
		"ori             $t1,$t1,0x3                            \n"
		"lw              $v0,704($v1)                           \n"
		"lui             $a1,%hi(data_80865BE8)                 \n"
		"addiu           $a1,$a1,%lo(data_80865BE8)             \n"
		"addiu           $t0,$v0,8                              \n"
		"sw              $t0,704($v1)                           \n"
		"sw              $t1,0($v0)                             \n"
		"lw              $t2,148($sp)                           \n"
		"addiu           $a2,$zero,910                          \n"
		"or              $s0,$v0,$zero                          \n"
		"jal             0x800D1A88                 \n"
		"lw              $a0,0($t2)                             \n"
		"sw              $v0,4($s0)                             \n"
		"lw              $t3,84($sp)                            \n"
		"lui             $t7,0x0603                             \n"
		"addiu           $t7,$t7,-20496                         \n"
		"lw              $v0,704($t3)                           \n"
		"lui             $t5,0xDE00                             \n"
		"lui             $a2,%hi(data_80865BFC)                 \n"
		"addiu           $t4,$v0,8                              \n"
		"sw              $t4,704($t3)                           \n"
		"sw              $t7,4($v0)                             \n"
		"sw              $t5,0($v0)                             \n"
		"lw              $t8,148($sp)                           \n"
		"addiu           $a2,$a2,%lo(data_80865BFC)             \n"
		"addiu           $a0,$sp,68                             \n"
		"addiu           $a3,$zero,913                          \n"
		"jal             0x800C6B54                 \n"
		"lw              $a1,0($t8)                             \n"
		".L000036:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000035:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,144                            \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
		"nop                                                    \n"
		"nop                                                    \n"
	);
}
void data_80864F80(void) /* 0 internal, 1 external, 18 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80864F80: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"lw              $v0,512($a0)                           \n"
		"or              $a2,$a0,$zero                          \n"
		"or              $a3,$a1,$zero                          \n"
		"beq             $v0,$zero,.L000000                     \n"
		"or              $a0,$a3,$zero                          \n"
		"lw              $t6,4($v0)                             \n"
		"addiu           $at,$zero,-8193                        \n"
		"and             $t7,$t6,$at                            \n"
		"sw              $t7,4($v0)                             \n"
		".L000000:                                              \n"
		"jal             0x8005D060                 \n"
		"addiu           $a1,$a2,332                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80865054(void) /* 0 internal, 0 external, 13 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865054: \n"
	);
	asm(
		"sw              $a0,284($a1)                           \n"
		"sw              $a0,940($a1)                           \n"
		"lw              $t6,284($a0)                           \n"
		"or              $v0,$zero,$zero                        \n"
		"beq             $t6,$zero,.L000003                     \n"
		"nop                                                    \n"
		"sw              $zero,280($a1)                         \n"
		"sw              $zero,284($a0)                         \n"
		"jr              $ra                                    \n"
		"addiu           $v0,$zero,1                            \n"
		".L000003:                                              \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808657EC(void) /* 0 internal, 0 external, 17 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808657EC: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"lw              $t9,532($a0)                           \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"lw              $a0,24($sp)                            \n"
		"lw              $t7,488($a0)                           \n"
		"lw              $t6,492($a0)                           \n"
		"sw              $t7,500($a0)                           \n"
		"lw              $t7,496($a0)                           \n"
		"sw              $t6,504($a0)                           \n"
		"sw              $t7,508($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80864FC4(void) /* 1 internal, 1 external, 34 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80864FC4: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"lw              $t6,280($a0)                           \n"
		"bnel            $t6,$zero,.L000001                     \n"
		"lw              $ra,20($sp)                            \n"
		"lw              $v0,7236($a1)                          \n"
		"addiu           $at,$zero,16                           \n"
		"lui             $a1,%hi(data_8086518C)                 \n"
		"lb              $t8,337($v0)                           \n"
		"addiu           $v0,$zero,26                           \n"
		"addiu           $a1,$a1,%lo(data_8086518C)             \n"
		"bne             $t8,$at,.L000002                       \n"
		"nop                                                    \n"
		"b               .L000002                               \n"
		"addiu           $v0,$zero,13                           \n"
		".L000002:                                              \n"
		"sw              $v0,24($sp)                            \n"
		"jal             func_80864F00                          \n"
		"sw              $a0,32($sp)                            \n"
		"lw              $a0,32($sp)                            \n"
		"jal             0x8002D9A4                 \n"
		"lui             $a1,0x41A0                             \n"
		"lw              $t9,36($sp)                            \n"
		"lw              $a0,32($sp)                            \n"
		"lw              $v0,24($sp)                            \n"
		"lw              $t0,7236($t9)                          \n"
		"sh              $v0,528($a0)                           \n"
		"sw              $t0,280($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		".L000001:                                              \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80865148(void) /* 0 internal, 1 external, 17 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865148: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"lw              $t6,4($a1)                             \n"
		"addiu           $a0,$a1,36                             \n"
		"ori             $t7,$t6,0x2000                         \n"
		"sw              $t7,4($a1)                             \n"
		"lw              $t8,24($sp)                            \n"
		"sw              $a1,512($t8)                           \n"
		"lw              $t9,24($sp)                            \n"
		"addiu           $a1,$t9,36                             \n"
		"jal             0x80077ED0                 \n"
		"addiu           $a2,$t9,516                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80864F08(void) /* 1 internal, 2 external, 30 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80864F08: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $a1,44($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"addiu           $a1,$s0,332                            \n"
		"jal             0x8005D018                 \n"
		"sw              $a1,32($sp)                            \n"
		"lui             $a3,%hi(data_80865B00)                 \n"
		"lw              $a1,32($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_80865B00)             \n"
		"lw              $a0,44($sp)                            \n"
		"jal             0x8005D104                 \n"
		"or              $a2,$s0,$zero                          \n"
		"lui             $a1,%hi(data_80864FC4)                 \n"
		"addiu           $a1,$a1,%lo(data_80864FC4)             \n"
		"jal             func_80864F00                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t7,36($s0)                            \n"
		"lw              $t6,40($s0)                            \n"
		"sw              $t7,488($s0)                           \n"
		"lw              $t7,44($s0)                            \n"
		"sw              $t6,492($s0)                           \n"
		"sw              $t7,496($s0)                           \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_808650AC(void) /* 1 internal, 2 external, 42 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808650AC: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,32($sp)                            \n"
		"lw              $a2,280($a0)                           \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             0x8008F104                 \n"
		"sw              $a2,28($sp)                            \n"
		"beq             $v0,$zero,.L000005                     \n"
		"lw              $a2,28($sp)                            \n"
		"lb              $t7,337($a2)                           \n"
		"lb              $t8,340($a2)                           \n"
		"lw              $a0,32($sp)                            \n"
		"bnel            $t7,$t8,.L000006                       \n"
		"sh              $zero,528($a0)                         \n"
		"lw              $t9,4($a2)                             \n"
		"andi            $t0,$t9,0x100                          \n"
		"bnel            $t0,$zero,.L000006                     \n"
		"sh              $zero,528($a0)                         \n"
		"lw              $t1,1660($a2)                          \n"
		"lui             $at,0x0400                             \n"
		"ori             $at,$at,0x80                           \n"
		"and             $t2,$t1,$at                            \n"
		"beql            $t2,$zero,.L000007                     \n"
		"or              $v0,$zero,$zero                        \n"
		"sh              $zero,528($a0)                         \n"
		".L000006:                                              \n"
		"jal             func_80865084                          \n"
		"sw              $a2,28($sp)                            \n"
		"lw              $a2,28($sp)                            \n"
		"lw              $a0,32($sp)                            \n"
		"addiu           $a1,$a2,968                            \n"
		"jal             0x80077E40                 \n"
		"addiu           $a0,$a0,36                             \n"
		"b               .L000007                               \n"
		"addiu           $v0,$zero,1                            \n"
		".L000005:                                              \n"
		"or              $v0,$zero,$zero                        \n"
		".L000007:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8086518C(void) /* 6 internal, 16 external, 435 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8086518C: \n"
	);
	asm(
		"addiu           $sp,$sp,-200                           \n"
		"sw              $ra,52($sp)                            \n"
		"sw              $s0,48($sp)                            \n"
		"sw              $a1,204($sp)                           \n"
		"lw              $t7,280($a0)                           \n"
		"lw              $a2,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"beq             $t7,$zero,.L000008                     \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             0x8008F104                 \n"
		"sw              $a2,196($sp)                           \n"
		"bne             $v0,$zero,.L000009                     \n"
		"lw              $a0,196($sp)                           \n"
		".L000008:                                              \n"
		"jal             func_80865084                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"b               .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		".L000009:                                              \n"
		"jal             0x8002F8F0                 \n"
		"addiu           $a1,$zero,4107                         \n"
		"jal             func_808650AC                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lh              $v1,528($s0)                           \n"
		"beq             $v1,$zero,.L000011                     \n"
		"nop                                                    \n"
		"lbu             $t8,348($s0)                           \n"
		"andi            $t9,$t8,0x2                            \n"
		"beq             $t9,$zero,.L000011                     \n"
		"nop                                                    \n"
		"lw              $v0,388($s0)                           \n"
		"addiu           $at,$zero,4                            \n"
		"lbu             $t0,20($v0)                            \n"
		"beq             $t0,$at,.L000011                       \n"
		"nop                                                    \n"
		"lw              $a1,336($s0)                           \n"
		"lw              $t1,304($a1)                           \n"
		"beq             $t1,$zero,.L000012                     \n"
		"nop                                                    \n"
		"lw              $t2,4($a1)                             \n"
		"andi            $t3,$t2,0x600                          \n"
		"beq             $t3,$zero,.L000012                     \n"
		"nop                                                    \n"
		"lbu             $t4,22($v0)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t5,$t4,0x4                            \n"
		"beq             $t5,$zero,.L000012                     \n"
		"nop                                                    \n"
		"jal             func_80865148                          \n"
		"sw              $a1,192($sp)                           \n"
		"lw              $a1,192($sp)                           \n"
		"addiu           $at,$zero,1024                         \n"
		"lw              $t6,4($a1)                             \n"
		"andi            $t7,$t6,0x400                          \n"
		"bne             $t7,$at,.L000012                       \n"
		"nop                                                    \n"
		"jal             func_80865044                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000012:                                              \n"
		"lui             $a3,0x8013                             \n"
		"lui             $t8,0x8013                             \n"
		"addiu           $a3,$a3,13280                          \n"
		"sh              $zero,528($s0)                         \n"
		"addiu           $t8,$t8,13288                          \n"
		"sw              $t8,20($sp)                            \n"
		"sw              $a3,16($sp)                            \n"
		"addiu           $a0,$zero,6164                         \n"
		"addiu           $a1,$s0,228                            \n"
		"jal             0x800F738C                 \n"
		"addiu           $a2,$zero,4                            \n"
		"b               .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		".L000011:                                              \n"
		"bne             $v1,$zero,.L000013                     \n"
		"addiu           $t9,$v1,-1                             \n"
		"b               .L000014                               \n"
		"or              $v0,$zero,$zero                        \n"
		".L000013:                                              \n"
		"sh              $t9,528($s0)                           \n"
		"lh              $v0,528($s0)                           \n"
		".L000014:                                              \n"
		"bne             $v0,$zero,.L000015                     \n"
		"nop                                                    \n"
		"lw              $a3,512($s0)                           \n"
		"beql            $a3,$zero,.L000016                     \n"
		"lw              $a0,196($sp)                           \n"
		"lw              $t0,304($a3)                           \n"
		"beql            $t0,$zero,.L000017                     \n"
		"or              $a3,$zero,$zero                        \n"
		"lw              $t1,4($a3)                             \n"
		"addiu           $at,$zero,8192                         \n"
		"andi            $t2,$t1,0x2000                         \n"
		"beql            $t2,$at,.L000018                       \n"
		"lw              $t3,284($s0)                           \n"
		"or              $a3,$zero,$zero                        \n"
		".L000017:                                              \n"
		"b               .L000019                               \n"
		"sw              $zero,512($s0)                         \n"
		"lw              $t3,284($s0)                           \n"
		".L000018:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a1,$a3,$zero                          \n"
		"beql            $t3,$zero,.L000016                     \n"
		"lw              $a0,196($sp)                           \n"
		"jal             0x8002DB48                 \n"
		"sw              $a3,188($sp)                           \n"
		"swc1            $f0,148($sp)                           \n"
		"lwc1            $f2,516($s0)                           \n"
		"lwc1            $f12,520($s0)                          \n"
		"lwc1            $f14,524($s0)                          \n"
		"mul.s           $f4,$f2,$f2                            \n"
		"lw              $a3,188($sp)                           \n"
		"addiu           $a1,$s0,516                            \n"
		"mul.s           $f6,$f12,$f12                          \n"
		"addiu           $a2,$s0,36                             \n"
		"addiu           $a0,$a3,36                             \n"
		"mul.s           $f10,$f14,$f14                         \n"
		"add.s           $f8,$f4,$f6                            \n"
		"add.s           $f0,$f8,$f10                           \n"
		"sqrt.s          $f0,$f0                                \n"
		"jal             0x80077ED0                 \n"
		"swc1            $f0,144($sp)                           \n"
		"lwc1            $f6,148($sp)                           \n"
		"lwc1            $f8,144($sp)                           \n"
		"lui             $at,0x4248                             \n"
		"mtc1            $at,$f4                                \n"
		"sub.s           $f10,$f6,$f8                           \n"
		"lw              $a3,188($sp)                           \n"
		"c.lt.s          $f4,$f10                               \n"
		"nop                                                    \n"
		"bc1fl           .L000016                               \n"
		"lw              $a0,196($sp)                           \n"
		"jal             func_80865084                          \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a3,$zero,$zero                        \n"
		".L000019:                                              \n"
		"lw              $a0,196($sp)                           \n"
		".L000016:                                              \n"
		"addiu           $a1,$s0,36                             \n"
		"sw              $a1,68($sp)                            \n"
		"addiu           $a0,$a0,968                            \n"
		"sw              $a0,64($sp)                            \n"
		"addiu           $a2,$sp,176                            \n"
		"jal             0x80077FD0                 \n"
		"sw              $a3,188($sp)                           \n"
		"lui             $at,0x41F0                             \n"
		"mtc1            $at,$f12                               \n"
		"lw              $a0,64($sp)                            \n"
		"lw              $a3,188($sp)                           \n"
		"c.lt.s          $f0,$f12                               \n"
		"lwc1            $f6,176($sp)                           \n"
		"addiu           $a1,$sp,164                            \n"
		"bc1fl           .L000020                               \n"
		"lw              $t4,284($s0)                           \n"
		"mtc1            $zero,$f2                              \n"
		"mtc1            $zero,$f16                             \n"
		"b               .L000021                               \n"
		"nop                                                    \n"
		"lw              $t4,284($s0)                           \n"
		".L000020:                                              \n"
		"beq             $t4,$zero,.L000022                     \n"
		"nop                                                    \n"
		"b               .L000023                               \n"
		"mov.s           $f2,$f12                               \n"
		".L000022:                                              \n"
		"beq             $a3,$zero,.L000024                     \n"
		"lui             $at,0x4348                             \n"
		"lui             $at,0x4248                             \n"
		"mtc1            $at,$f2                                \n"
		"b               .L000025                               \n"
		"c.le.s          $f0,$f2                                \n"
		".L000024:                                              \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		".L000023:                                              \n"
		"c.le.s          $f0,$f2                                \n"
		".L000025:                                              \n"
		"sub.s           $f16,$f0,$f2                           \n"
		"bc1fl           .L000021                               \n"
		"div.s           $f2,$f16,$f0                           \n"
		"mtc1            $zero,$f16                             \n"
		"nop                                                    \n"
		"div.s           $f2,$f16,$f0                           \n"
		".L000021:                                              \n"
		"mul.s           $f8,$f6,$f2                            \n"
		"lwc1            $f4,180($sp)                           \n"
		"lwc1            $f6,184($sp)                           \n"
		"lw              $a2,196($sp)                           \n"
		"mul.s           $f10,$f4,$f2                           \n"
		"addiu           $a2,$a2,92                             \n"
		"swc1            $f8,164($sp)                           \n"
		"mul.s           $f8,$f6,$f2                            \n"
		"swc1            $f10,168($sp)                          \n"
		"swc1            $f8,172($sp)                           \n"
		"lw              $t5,284($s0)                           \n"
		"bnel            $t5,$zero,.L000026                     \n"
		"addiu           $a0,$sp,176                            \n"
		"beq             $a3,$zero,.L000027                     \n"
		"addiu           $a1,$sp,164                            \n"
		"lh              $t6,0($a3)                             \n"
		"addiu           $at,$zero,213                          \n"
		"lw              $a2,68($sp)                            \n"
		"bnel            $t6,$at,.L000028                       \n"
		"lw              $a2,68($sp)                            \n"
		"addiu           $a0,$a3,36                             \n"
		"jal             0x80077ED0                 \n"
		"addiu           $a1,$s0,516                            \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f16                               \n"
		"b               .L000029                               \n"
		"lui             $at,0x4248                             \n"
		".L000027:                                              \n"
		"lw              $a2,68($sp)                            \n"
		".L000028:                                              \n"
		"sw              $a3,188($sp)                           \n"
		"jal             0x80077E9C                 \n"
		"swc1            $f16,156($sp)                          \n"
		"lw              $a3,188($sp)                           \n"
		"lwc1            $f16,156($sp)                          \n"
		"lw              $a0,68($sp)                            \n"
		"beq             $a3,$zero,.L000030                     \n"
		"addiu           $a1,$s0,516                            \n"
		"addiu           $a2,$a3,36                             \n"
		"jal             0x80077E9C                 \n"
		"swc1            $f16,156($sp)                          \n"
		"b               .L000030                               \n"
		"lwc1            $f16,156($sp)                          \n"
		"addiu           $a0,$sp,176                            \n"
		".L000026:                                              \n"
		"jal             0x80077ED0                 \n"
		"swc1            $f16,156($sp)                          \n"
		"lwc1            $f2,176($sp)                           \n"
		"lwc1            $f18,184($sp)                          \n"
		"lwc1            $f14,180($sp)                          \n"
		"mul.s           $f4,$f2,$f2                            \n"
		"neg.s           $f14,$f14                              \n"
		"mul.s           $f10,$f18,$f18                         \n"
		"add.s           $f0,$f4,$f10                           \n"
		"jal             0x800D0664                 \n"
		"sqrt.s          $f12,$f0                               \n"
		"lw              $t7,196($sp)                           \n"
		"lwc1            $f16,156($sp)                          \n"
		"sh              $v0,48($t7)                            \n"
		".L000030:                                              \n"
		"lui             $at,0x4248                             \n"
		".L000029:                                              \n"
		"mtc1            $at,$f6                                \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f16,$f6                               \n"
		"nop                                                    \n"
		"bc1fl           .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		"jal             func_80865084                          \n"
		"swc1            $f16,156($sp)                          \n"
		"lwc1            $f16,156($sp)                          \n"
		"mtc1            $zero,$f8                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $a1,%hi(data_80864FC4)                 \n"
		"c.eq.s          $f16,$f8                               \n"
		"nop                                                    \n"
		"bc1fl           .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		"jal             func_80864F00                          \n"
		"addiu           $a1,$a1,%lo(data_80864FC4)             \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80865054                          \n"
		"lw              $a1,196($sp)                           \n"
		"beql            $v0,$zero,.L000010                     \n"
		"lw              $ra,52($sp)                            \n"
		"lw              $v0,196($sp)                           \n"
		"lw              $a0,68($sp)                            \n"
		"addiu           $a1,$v0,36                             \n"
		"jal             0x80077ED0                 \n"
		"addiu           $a2,$v0,92                             \n"
		"lw              $t8,196($sp)                           \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f4,96($t8)                            \n"
		"sub.s           $f6,$f4,$f10                           \n"
		"b               .L000031                               \n"
		"swc1            $f6,96($t8)                            \n"
		".L000015:                                              \n"
		"jal             0x8002D8E0                 \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a0,$s0,36                             \n"
		"sw              $a0,68($sp)                            \n"
		"addiu           $a1,$s0,256                            \n"
		"jal             0x80077ED0                 \n"
		"addiu           $a2,$sp,108                            \n"
		"addiu           $a0,$s0,488                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $a0,64($sp)                            \n"
		"jal             0x80077E9C                 \n"
		"addiu           $a1,$sp,108                            \n"
		"lwc1            $f14,96($s0)                           \n"
		"lwc1            $f12,104($s0)                          \n"
		"jal             0x800D0664                 \n"
		"neg.s           $f14,$f14                              \n"
		"lwc1            $f0,500($s0)                           \n"
		"lwc1            $f8,488($s0)                           \n"
		"sh              $v0,180($s0)                           \n"
		"lw              $a0,204($sp)                           \n"
		"sub.s           $f4,$f8,$f0                            \n"
		"addiu           $t9,$sp,136                            \n"
		"addiu           $t0,$zero,1                            \n"
		"addiu           $t1,$zero,1                            \n"
		"sub.s           $f10,$f0,$f4                           \n"
		"addiu           $t2,$zero,1                            \n"
		"addiu           $t3,$zero,1                            \n"
		"addiu           $t4,$sp,132                            \n"
		"swc1            $f10,96($sp)                           \n"
		"lwc1            $f6,492($s0)                           \n"
		"lwc1            $f2,504($s0)                           \n"
		"addiu           $a0,$a0,1984                           \n"
		"lw              $a2,64($sp)                            \n"
		"sub.s           $f8,$f6,$f2                            \n"
		"addiu           $a1,$sp,96                             \n"
		"addiu           $a3,$sp,120                            \n"
		"sub.s           $f4,$f2,$f8                            \n"
		"swc1            $f4,100($sp)                           \n"
		"lwc1            $f10,496($s0)                          \n"
		"lwc1            $f12,508($s0)                          \n"
		"sw              $a0,60($sp)                            \n"
		"sw              $t4,36($sp)                            \n"
		"sub.s           $f6,$f10,$f12                          \n"
		"sw              $t3,32($sp)                            \n"
		"sw              $t2,28($sp)                            \n"
		"sw              $t1,24($sp)                            \n"
		"sub.s           $f8,$f12,$f6                           \n"
		"sw              $t0,20($sp)                            \n"
		"sw              $t9,16($sp)                            \n"
		"jal             0x8003DE84                 \n"
		"swc1            $f8,104($sp)                           \n"
		"beq             $v0,$zero,.L000032                     \n"
		"lw              $a3,132($sp)                           \n"
		"addiu           $t5,$sp,120                            \n"
		"sw              $t5,16($sp)                            \n"
		"lw              $a0,204($sp)                           \n"
		"or              $a1,$s0,$zero                          \n"
		"jal             0x8002F9EC                 \n"
		"lw              $a2,136($sp)                           \n"
		"bne             $v0,$zero,.L000032                     \n"
		"lw              $t6,136($sp)                           \n"
		"lh              $t7,8($t6)                             \n"
		"lui             $at,%hi(data_80865C10)                 \n"
		"lwc1            $f0,%lo(data_80865C10)($at)            \n"
		"mtc1            $t7,$f4                                \n"
		"lw              $a0,68($sp)                            \n"
		"addiu           $a1,$sp,120                            \n"
		"cvt.s.w         $f10,$f4                               \n"
		"mul.s           $f6,$f10,$f0                           \n"
		"swc1            $f6,92($sp)                            \n"
		"lh              $t8,12($t6)                            \n"
		"mtc1            $t8,$f8                                \n"
		"nop                                                    \n"
		"cvt.s.w         $f4,$f8                                \n"
		"mul.s           $f10,$f4,$f0                           \n"
		"jal             0x80077E40                 \n"
		"swc1            $f10,88($sp)                           \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f0                                \n"
		"lwc1            $f8,92($sp)                            \n"
		"lwc1            $f6,36($s0)                            \n"
		"mul.s           $f4,$f0,$f8                            \n"
		"lwc1            $f8,44($s0)                            \n"
		"add.s           $f10,$f6,$f4                           \n"
		"swc1            $f10,36($s0)                           \n"
		"lwc1            $f6,88($sp)                            \n"
		"sh              $zero,528($s0)                         \n"
		"mul.s           $f4,$f0,$f6                            \n"
		"add.s           $f10,$f8,$f4                           \n"
		"swc1            $f10,44($s0)                           \n"
		"lw              $a2,132($sp)                           \n"
		"lw              $a1,136($sp)                           \n"
		"jal             0x80041FE8                 \n"
		"lw              $a0,60($sp)                            \n"
		"beq             $v0,$zero,.L000033                     \n"
		"lw              $a0,204($sp)                           \n"
		"lw              $a3,132($sp)                           \n"
		"addiu           $at,$zero,50                           \n"
		"lw              $a0,60($sp)                            \n"
		"beq             $a3,$at,.L000034                       \n"
		"nop                                                    \n"
		"jal             0x8003EB84                 \n"
		"or              $a1,$a3,$zero                          \n"
		"beq             $v0,$zero,.L000034                     \n"
		"or              $a1,$v0,$zero                          \n"
		"jal             func_80865148                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000034:                                              \n"
		"jal             func_80865044                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $a3,0x8013                             \n"
		"lui             $t9,0x8013                             \n"
		"addiu           $a3,$a3,13280                          \n"
		"addiu           $t9,$t9,13288                          \n"
		"sw              $t9,20($sp)                            \n"
		"sw              $a3,16($sp)                            \n"
		"addiu           $a0,$zero,6185                         \n"
		"addiu           $a1,$s0,228                            \n"
		"jal             0x800F738C                 \n"
		"addiu           $a2,$zero,4                            \n"
		"b               .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		".L000033:                                              \n"
		"jal             0x80062D60                 \n"
		"lw              $a1,68($sp)                            \n"
		"lui             $a3,0x8013                             \n"
		"lui             $t0,0x8013                             \n"
		"addiu           $a3,$a3,13280                          \n"
		"addiu           $t0,$t0,13288                          \n"
		"sw              $t0,20($sp)                            \n"
		"sw              $a3,16($sp)                            \n"
		"addiu           $a0,$zero,6163                         \n"
		"addiu           $a1,$s0,228                            \n"
		"jal             0x800F738C                 \n"
		"addiu           $a2,$zero,4                            \n"
		"b               .L000010                               \n"
		"lw              $ra,52($sp)                            \n"
		".L000032:                                              \n"
		"lw              $t1,204($sp)                           \n"
		"lhu             $t2,32($t1)                            \n"
		"andi            $t3,$t2,0xc01f                         \n"
		"beql            $t3,$zero,.L000010                     \n"
		"lw              $ra,52($sp)                            \n"
		"sh              $zero,528($s0)                         \n"
		".L000031:                                              \n"
		"lw              $ra,52($sp)                            \n"
		".L000010:                                              \n"
		"lw              $s0,48($sp)                            \n"
		"addiu           $sp,$sp,200                            \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x07,
	.room = 0x00,
	.flags = 0x00000030,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = data_80864F08,
	.dest = data_80864F80,
	.main = data_808657EC,
	.draw = data_80865830
};
