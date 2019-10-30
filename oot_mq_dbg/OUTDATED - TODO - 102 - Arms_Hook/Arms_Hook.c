#include <z64ovl/oot/debug.h>

#define OBJ_ID 20

/*** sounds ***/
#define NA_SE_IT_HOOKSHOT_CHAIN 0x100B

typedef struct {
	z64_actor_t actor;
	uint8_t inst_etc_0[10];
	z64_collider_t *collider_pointer;
	uint8_t inst_etc_1[204];
} entity_t; /* 0218 */


/*** function prototypes ***/
void func_80864F00(entity_t *en, z64_global_t *gl); /* 0 internal, 0 external, 2 lines */
void func_80865044(void); /* 0 internal, 0 external, 4 lines */
void func_80865084(void); /* 0 internal, 0 external, 11 lines */
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 12 external, 177 lines */
void data_80864F80(void); /* 0 internal, 1 external, 18 lines */
void func_80865054(void); /* 0 internal, 0 external, 13 lines */
void data_808657EC(void); /* 0 internal, 0 external, 17 lines */
void data_80864FC4(void); /* 1 internal, 1 external, 34 lines */
void func_80865148(void); /* 0 internal, 1 external, 17 lines */
void init(entity_t *en, z64_global_t *gl); /* 1 internal, 2 external, 30 lines */
void func_808650AC(void); /* 1 internal, 2 external, 42 lines */
void data_8086518C(entity_t *en, z64_global_t *gl); /* 6 internal, 16 external, 435 lines */


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
void func_80864F00(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80864F00: \n"
	);

	*(en->inst_etc + 0xD8) = gl;
}

void func_80865044(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 4 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865044: \n"
	);

	z64_actor_t *attached; /* Set Attached Actor */

	attached = (en->actor.attached_a);
	(en->actor).attached_b = attached;
	*&attached->attached_a = en;

}

void func_80865084(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 11 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80865084: \n"
	);
	int unk_0;

	unk_0 = *(en->inst_etc + 0xC4);
	if (unk_0 != 0)
	{
		*(unk_0 + 4) &= 0xFFFFDFFF;
		*(en->inst_etc + 0xC4) = 0;
	}
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 12 external, 177 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldraw: \n"
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
void init(entity_t *en, z64_global_t *gl) /* 1 internal, 2 external, 30 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Linit: \n"
	);

	float fVar1, fVar2;

	external_func_8005D018(gl); /* Please Document */
	external_func_8005D104(gl, (en->inst_etc + 10), en, &data_80865B00);
	func_80864F00(en, func_80864FC4);
	fVar1 = (en->actor).pos_2.y;
	*(en->inst_etc + 0xAC) = (en->actor).pos_2.x;
	fVar2 = (en->actor).pos_2.z;
	*(en->inst_etc + 0xB0) = fVar1;
	*(en->inst_etc + 0xB4) = fVar2;

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
void data_8086518C(entity_t *en, z64_global_t *gl) /* 6 internal, 16 external, 435 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_8086518C: \n"
	);

	bool bVar1;
	int iVar2;
	short sVar3;
	int16_t iVar4;
	vec3s_t *pvVar5;
	uint8_t *puVar6;
	char *pcVar7;
	vec3f_t *pvVar8;
	z64_actor_t *pzVar9;
	float fVar10;
	float fVar11;
	float fVar12;
	float local_68;
	float local_64;
	float local_60;
	undefined auStack92 [12];
	undefined auStack80 [12];
	int local_44;
	int local_40 [2];
	float local_38;
	float local_34;
	float local_2c;
	float local_24;
	float local_20;
	float local_1c;
	float local_18;
	float local_14;
	float local_10;
	short *local_c;
	int local_8;
	z64_actor_t *local_4;

	pzVar9 = gl->actor_list[2].first;
	if (((en->actor).attached_a == 0x0) || (local_4 = pzVar9, iVar2 = player_is_hookshotting(pzVar9), iVar2 == 0))
	{
		func_80865084(en);
		actor_kill(en);
		return;
	}

	sound_play_actor3(local_4, NA_SE_IT_HOOKSHOT_CHAIN);
	func_808650AC(en);
	sVar3 = *(en->inst_etc + 0xD4);

}
const z64_actor_init_t init_vars = {
	.number = 0xDEAD,
	.type = OVLTYPE_ITEM,
	.room = 0x00,
	.flags = 0x00000030,
	.object = OBJ_ID,
	.padding = 0xBEEF,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = data_80864F80,
	.main = data_808657EC,
	.draw = draw
};
