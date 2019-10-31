/* vRAM Start 0x8085F650. */
#include <z64ovl/oot/debug.h>

#define OBJ_ID 50

typedef struct {
	z64_actor_t actor;
	uint8_t unknown[2028];
} entity_t; /* 0928 */


/*** function prototypes ***/
void func_8085F650(void); /* 0 internal, 0 external, 2 lines */
void init(entity_t *en, z64_global_t *gl); /* 2 internal, 8 external, 149 lines */
void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 40 lines */
void func_8085F938(void); /* 0 internal, 1 external, 53 lines */
void data_8085FA00(void); /* 1 internal, 2 external, 29 lines */
void data_8085FA74(void); /* 1 internal, 0 external, 4 lines */
void data_8085FA84(void); /* 1 internal, 0 external, 5 lines */
void data_8085FA98(void); /* 1 internal, 0 external, 8 lines */
void func_8085FAB0(void); /* 0 internal, 1 external, 71 lines */
void data_8085FBBC(void); /* 1 internal, 0 external, 4 lines */
void data_8085FBCC(void); /* 1 internal, 0 external, 5 lines */
void func_80864158(void); /* 1 internal, 2 external, 36 lines */
void func_8085FDD0(void); /* 1 internal, 1 external, 30 lines */
void data_8085FE48(void); /* 1 internal, 2 external, 61 lines */
void func_8085FF28(void); /* 1 internal, 2 external, 29 lines */
void data_8085FF9C(void); /* 1 internal, 2 external, 54 lines */
void func_80860068(void); /* 1 internal, 2 external, 33 lines */
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 4 external, 72 lines */
void data_80860318(void); /* 1 internal, 3 external, 46 lines */
void data_808603CC(void); /* 1 internal, 2 external, 28 lines */
void func_80860438(void); /* 1 internal, 4 external, 49 lines */
void data_80863FCC(void); /* 0 internal, 1 external, 33 lines */
void func_80860BDC(void); /* 1 internal, 1 external, 18 lines */
void data_80863FC4(void); /* 0 internal, 0 external, 2 lines */
void func_80860EC0(void); /* 1 internal, 2 external, 50 lines */
void data_80860F84(void); /* 2 internal, 8 external, 322 lines */
void func_80861418(void); /* 1 internal, 2 external, 34 lines */
void data_8086149C(void); /* 2 internal, 3 external, 72 lines */
void func_808615A4(void); /* 1 internal, 1 external, 20 lines */
void data_80863FB8(void); /* 0 internal, 0 external, 3 lines */
void func_8086181C(void); /* 1 internal, 1 external, 32 lines */
void data_80861898(void); /* 1 internal, 2 external, 48 lines */
void func_8086194C(void); /* 1 internal, 2 external, 43 lines */
void data_80863FAC(void); /* 0 internal, 0 external, 3 lines */
void func_80861B94(void); /* 1 internal, 3 external, 44 lines */
void data_80861C40(void); /* 1 internal, 3 external, 74 lines */
void func_80861D50(void); /* 1 internal, 2 external, 30 lines */
void data_80861DC8(void); /* 1 internal, 4 external, 64 lines */
void func_80861EC0(void); /* 1 internal, 3 external, 48 lines */
void data_80861F80(void); /* 2 internal, 2 external, 57 lines */
void func_80862050(void); /* 1 internal, 1 external, 19 lines */
void data_8086209C(void); /* 3 internal, 2 external, 49 lines */
void func_80862154(void); /* 1 internal, 3 external, 32 lines */
void data_80863FA0(void); /* 0 internal, 0 external, 3 lines */
void func_80862398(void); /* 1 internal, 3 external, 32 lines */
void data_80863F94(void); /* 0 internal, 0 external, 3 lines */
void func_80862578(void); /* 1 internal, 3 external, 58 lines */
void data_80863F88(void); /* 0 internal, 0 external, 3 lines */
void func_808627C4(void); /* 2 internal, 4 external, 69 lines */
void data_80863F7C(void); /* 0 internal, 0 external, 3 lines */
void func_80862DBC(void); /* 1 internal, 5 external, 46 lines */
void data_80862E6C(void); /* 1 internal, 5 external, 87 lines */
void func_80862FA8(void); /* 2 internal, 2 external, 41 lines */
void data_80863044(void); /* 1 internal, 4 external, 45 lines */
void func_808630F0(void); /* 2 internal, 2 external, 41 lines */
void data_8086318C(void); /* 1 internal, 4 external, 48 lines */
void func_80863240(void); /* 1 internal, 0 external, 21 lines */
void data_80863F70(void); /* 0 internal, 0 external, 3 lines */
void data_80863360(void); /* 1 internal, 1 external, 36 lines */
void data_808633E8(void); /* 0 internal, 3 external, 32 lines */
void func_80863460(void); /* 0 internal, 0 external, 43 lines */
void data_80863F68(void); /* 0 internal, 0 external, 2 lines */
void play(entity_t *en, z64_global_t *gl); /* 1 internal, 5 external, 85 lines */
void data_808637D4(void); /* 0 internal, 3 external, 29 lines */
void data_80863848(void); /* 0 internal, 2 external, 10 lines */
void data_80863870(void); /* 0 internal, 0 external, 5 lines */
void data_80863884(void); /* 0 internal, 2 external, 29 lines */
void data_808638F4(void); /* 2 internal, 5 external, 127 lines */
int32_t skl_callback_80863AB8(z64_global_t *gl, uint8_t limb, uint32_t *dlist, vec3f_t *translation, vec3s_t *rotation, entity_t *en); /* 0 internal, 3 external, 136 lines */
void skl_callback_80863CC4(z64_global_t *gl, uint8_t limb, uint32_t dlist, vec3s_t *rotation, entity_t *en); /* 0 internal, 8 external, 177 lines */
void func_808641E8(void); /* 4 internal, 4 external, 226 lines */
void data_80863294(void); /* 3 internal, 2 external, 55 lines */
void data_80860C24(void); /* 4 internal, 4 external, 182 lines */
void data_808615F4(void); /* 4 internal, 3 external, 150 lines */
void data_808619EC(void); /* 4 internal, 5 external, 116 lines */
void data_808628C8(void); /* 4 internal, 9 external, 349 lines */
void data_80862418(void); /* 5 internal, 3 external, 95 lines */
void data_808621D4(void); /* 5 internal, 3 external, 122 lines */
void func_808634F8(void); /* 5 internal, 5 external, 112 lines */
void data_80862650(void); /* 6 internal, 2 external, 101 lines */
void data_8085FBE0(void); /* 6 internal, 3 external, 135 lines */
void data_808600EC(void); /* 7 internal, 4 external, 151 lines */
void data_808604FC(void); /* 9 internal, 10 external, 478 lines */


/*** variables ***/
const uint32_t data_80864510[] =
{
	0x00000000,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010101,
	0x01010100,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00020500,
	0x00000015,
	0x00320000,
	0x00000928,
	(uint32_t)(void*)init,
	(uint32_t)(void*)dest,
	(uint32_t)(void*)play,
	(uint32_t)(void*)draw
};
const uint32_t data_80864570[] =
{
	0x05000939,
	0x10010000,
	0x00000000,
	0x00000000,
	0x00000000,
	0xFFCFFFFF,
	0x00000000,
	0x00010100,
	0x00190041,
	0x00000000,
	0x00000000
};
const uint32_t data_8086459C[] =
{
	0x09000D00,
	0x00010000,
	0x00000000,
	0x00000000,
	0x00000000,
	0xFFC1FFFF,
	0x00000000,
	0x00010000,
	0x00140046,
	0xFFCE0000,
	0x00000000
};
const uint32_t data_808645C8[] =
{
	0x0A110000,
	0x00030000,
	0x00000000,
	0xFFCFFFFF,
	0x00100000,
	0x00000000,
	0x00000000,
	0x81000000,
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
	0x00000000
};
const uint32_t data_80864618[] =
{
	0x1002D102,
	0x10020210,
	0x01020402,
	0xF4E20202,
	0x0260F3E0,
	0x00000104,
	0x02020804,
	0x00000400
};
const uint32_t data_80864638[] =
{
	0x8917001B,
	0xB04C01F4,
	0xC850000F,
	0xB0540000,
	0x386CFA24,
	0x44898000,
	0xC42F0000,
	0x00000000
};
const uint32_t data_80864658[] =
{
	0x43960000,
	0x00000000,
	0x00000000
};
const uint32_t data_80864664[] =
{
	0x45548000,
	0x00000000,
	0x00000000
};
const uint32_t data_80864670[] =
{
	0x00000000,
	0x00000000,
	0x00000000
};
const uint32_t data_8086467C[] =
{
	0x45DAC000,
	0x447A0000,
	0x00000000
};
const uint32_t data_80864688[] =
{
	0x453B8000,
	0xC4FA0000,
	0xC47A0000
};
const uint32_t data_80864694[] =
{
	0x453B8000,
	0xC4FA0000,
	0x447A0000
};
const uint32_t data_808646A0[] =
{
	0xC4A28000,
	0x44898000,
	0x00000000,
	0xC53B8000,
	0x44ED8000,
	0x44480000,
	0xC53B8000,
	0xC4898000,
	0x44480000,
	0x44ED8000,
	0x44ED8000,
	0x44480000,
	0xC53B8000,
	0xC4898000,
	0x44480000,
	0x44ED8000,
	0xC4898000,
	0x44480000,
	0x44ED8000,
	0x44ED8000,
	0x44480000,
	0x00000000,
	0x00000000,
	0x00000000,
};
const uint32_t data_80864700[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x74657374,
	0x2E630000
};
const uint32_t data_80864710[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x74657374,
	0x2E630000
};
const uint32_t data_80864720[] =
{
	(uint32_t)(void*)data_8085FA00,
	(uint32_t)(void*)data_8085FA00,
	(uint32_t)(void*)data_8085FA98,
	(uint32_t)(void*)data_8085FA84,
	(uint32_t)(void*)data_8085FA84,
	(uint32_t)(void*)data_8085FA00,
	(uint32_t)(void*)data_8085FA00,
	(uint32_t)(void*)data_8085FA84,
	(uint32_t)(void*)data_8085FA74,
	(uint32_t)(void*)data_8085FA98,
	(uint32_t)(void*)data_8085FA98
};
const uint32_t data_8086474C[] =
{
	(uint32_t)(void*)data_8085FBBC,
	(uint32_t)(void*)data_8085FBCC,
	(uint32_t)(void*)data_8085FBE0,
	(uint32_t)(void*)data_8085FBBC,
	(uint32_t)(void*)data_8085FBE0,
	(uint32_t)(void*)data_8085FBCC,
	(uint32_t)(void*)data_8085FBCC,
	(uint32_t)(void*)data_8085FBBC,
	(uint32_t)(void*)data_8085FBCC,
	(uint32_t)(void*)data_8085FBE0
};
const uint32_t data_80864774[] =
{
	0x3E4CCCCD
};
const uint32_t data_80864778[] =
{
	0x3F333333
};
const uint32_t data_8086477C[] =
{
	0x3E999999
};
const uint32_t data_80864780[] =
{
	0x3E999999
};
const uint32_t data_80864784[] =
{
	0x3F333333
};
const uint32_t data_80864788[] =
{
	0x3E19999A
};
const uint32_t data_8086478C[] =
{
	0x3CA3D70A
};
const uint32_t data_80864790[] =
{
	0x3F333333
};
const uint32_t data_80864794[] =
{
	0x3DCCCCCD
};
const uint32_t data_80864798[] =
{
	0x3ECCCCCD
};
const uint32_t data_8086479C[] =
{
	0x3E4CCCCD
};
const uint32_t data_808647A0[] =
{
	0x3DCCCCCD
};
const uint32_t data_808647A4[] =
{
	0x3CA3D70A
};
const uint32_t data_808647A8[] =
{
	0x3CA3D70A
};
const uint32_t data_808647AC[] =
{
	0x3F4CCCCC
};
const uint32_t data_808647B0[] =
{
	0x3F333333
};
const uint32_t data_808647B4[] =
{
	0xBF4CCCCC
};
const uint32_t data_808647B8[] =
{
	0xBF4CCCCC
};
const uint32_t data_808647BC[] =
{
	0x3F333333
};
const uint32_t data_808647C0[] =
{
	0x3F333333
};
const uint32_t data_808647C4[] =
{
	0x3F333333
};
const uint32_t data_808647C8[] =
{
	0x3F333333
};
const uint32_t data_808647CC[] =
{
	0x3F333333
};
const uint32_t data_808647D0[] =
{
	0xBF4CCCCC
};
const uint32_t data_808647D4[] =
{
	0xBF4CCCCC
};
const uint32_t data_808647D8[] =
{
	0x3F333333
};
const uint32_t data_808647DC[] =
{
	0x3C75C28F
};
const uint32_t data_808647E0[] =
{
	0x3B03126F
};
const uint32_t data_808647E4[] =
{
	(uint32_t)(void*)data_808638F4,
	(uint32_t)(void*)data_808637D4,
	(uint32_t)(void*)data_80863848,
	(uint32_t)(void*)data_80863870,
	(uint32_t)(void*)data_80863884
};
const uint32_t data_808647F8[] =
{
	(uint32_t)(void*)data_80863F68,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863F70,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863F88,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FA0,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863F7C,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863F94,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FB8,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FC4,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FCC,
	(uint32_t)(void*)data_80863FAC
};


/*** functions ***/
void func_8085F650(void) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8085F650: \n"
	);
	asm(
		"jr              $ra                                    \n"
		"sw              $a1,1996($a0)                          \n"
	);
}
void init(entity_t *en, z64_global_t *gl) /* 2 internal, 8 external, 149 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Linit: \n"
	);
	asm(
		"addiu           $sp,$sp,-488                           \n"
		"sw              $s1,40($sp)                            \n"
		"or              $s1,$a1,$zero                          \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s0,36($sp)                            \n"
		"lui             $a1,%hi(data_80864638)                 \n"
		"or              $s0,$a0,$zero                          \n"
		"jal             external_func_800780DC                 \n"
		"addiu           $a1,$a1,%lo(data_80864638)             \n"
		"lui             $a2,0x0600                             \n"
		"lui             $a3,0x0600                             \n"
		"addiu           $t6,$s0,460                            \n"
		"addiu           $t7,$s0,826                            \n"
		"addiu           $t8,$zero,61                           \n"
		"sw              $t8,24($sp)                            \n"
		"sw              $t7,20($sp)                            \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a3,$a3,12652                          \n"
		"addiu           $a2,$a2,31784                          \n"
		"or              $a0,$s1,$zero                          \n"
		"jal             external_func_800A457C                 \n"
		"addiu           $a1,$s0,392                            \n"
		"lui             $a2,0x0600                             \n"
		"lui             $a3,0x0600                             \n"
		"addiu           $t9,$s0,1260                           \n"
		"addiu           $t0,$s0,1626                           \n"
		"addiu           $t1,$zero,61                           \n"
		"sw              $t1,24($sp)                            \n"
		"sw              $t0,20($sp)                            \n"
		"sw              $t9,16($sp)                            \n"
		"addiu           $a3,$a3,12652                          \n"
		"addiu           $a2,$a2,31784                          \n"
		"or              $a0,$s1,$zero                          \n"
		"jal             external_func_800A457C                 \n"
		"addiu           $a1,$s0,1192                           \n"
		"lui             $a2,0x8003                             \n"
		"addiu           $a2,$a2,-18236                         \n"
		"addiu           $a0,$s0,180                            \n"
		"addiu           $a1,$zero,0                            \n"
		"jal             external_func_8002B1E0                 \n"
		"lui             $a3,0x42B4                             \n"
		"lw              $t4,40($s0)                            \n"
		"lui             $at,0x4234                             \n"
		"lw              $t5,36($s0)                            \n"
		"sw              $t4,60($s0)                            \n"
		"lwc1            $f4,60($s0)                            \n"
		"mtc1            $at,$f6                                \n"
		"sw              $t5,56($s0)                            \n"
		"lw              $t5,44($s0)                            \n"
		"add.s           $f8,$f4,$f6                            \n"
		"lui             $t6,%hi(data_80864618)                 \n"
		"addiu           $t2,$zero,40                           \n"
		"addiu           $t3,$zero,100                          \n"
		"addiu           $t6,$t6,%lo(data_80864618)             \n"
		"sh              $t2,168($s0)                           \n"
		"sh              $t3,170($s0)                           \n"
		"swc1            $f8,60($s0)                            \n"
		"sw              $t6,152($s0)                           \n"
		"addiu           $a1,$s0,2064                           \n"
		"sw              $t5,64($s0)                            \n"
		"sw              $a1,52($sp)                            \n"
		"jal             external_func_8005C364                 \n"
		"or              $a0,$s1,$zero                          \n"
		"lui             $a3,%hi(data_80864570)                 \n"
		"lw              $a1,52($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_80864570)             \n"
		"or              $a0,$s1,$zero                          \n"
		"jal             external_func_8005C4AC                 \n"
		"or              $a2,$s0,$zero                          \n"
		"addiu           $a1,$s0,2268                           \n"
		"sw              $a1,52($sp)                            \n"
		"jal             external_func_8005C364                 \n"
		"or              $a0,$s1,$zero                          \n"
		"lui             $a3,%hi(data_8086459C)                 \n"
		"lw              $a1,52($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_8086459C)             \n"
		"or              $a0,$s1,$zero                          \n"
		"jal             external_func_8005C4AC                 \n"
		"or              $a2,$s0,$zero                          \n"
		"addiu           $a1,$s0,2140                           \n"
		"sw              $a1,52($sp)                            \n"
		"jal             external_func_8005D018                 \n"
		"or              $a0,$s1,$zero                          \n"
		"lui             $a3,%hi(data_808645C8)                 \n"
		"lw              $a1,52($sp)                            \n"
		"addiu           $a3,$a3,%lo(data_808645C8)             \n"
		"or              $a0,$s1,$zero                          \n"
		"jal             external_func_8005D104                 \n"
		"or              $a2,$s0,$zero                          \n"
		"addiu           $t7,$zero,254                          \n"
		"addiu           $t8,$zero,10                           \n"
		"sb              $t7,174($s0)                           \n"
		"sb              $t8,175($s0)                           \n"
		"addiu           $v0,$zero,255                          \n"
		"addiu           $t9,$zero,255                          \n"
		"addiu           $t0,$zero,64                           \n"
		"addiu           $t1,$zero,4                            \n"
		"addiu           $t2,$zero,2                            \n"
		"addiu           $t3,$sp,72                             \n"
		"sb              $t9,474($sp)                           \n"
		"sb              $v0,473($sp)                           \n"
		"sb              $v0,472($sp)                           \n"
		"sb              $v0,470($sp)                           \n"
		"sb              $v0,469($sp)                           \n"
		"sb              $v0,468($sp)                           \n"
		"sb              $v0,466($sp)                           \n"
		"sb              $v0,465($sp)                           \n"
		"sb              $v0,464($sp)                           \n"
		"sb              $v0,463($sp)                           \n"
		"sb              $v0,462($sp)                           \n"
		"sb              $v0,461($sp)                           \n"
		"sb              $v0,460($sp)                           \n"
		"sb              $zero,471($sp)                         \n"
		"sb              $zero,475($sp)                         \n"
		"sb              $t0,467($sp)                           \n"
		"sw              $t1,476($sp)                           \n"
		"sw              $zero,480($sp)                         \n"
		"sw              $t2,484($sp)                           \n"
		"sw              $t3,20($sp)                            \n"
		"sw              $zero,16($sp)                          \n"
		"or              $a0,$s1,$zero                          \n"
		"addiu           $a1,$s0,2060                           \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_80026CD4                 \n"
		"or              $a3,$zero,$zero                        \n"
		"lh              $t4,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"beq             $t4,$at,.L000000                       \n"
		"nop                                                    \n"
		"jal             func_8085FDD0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000001                   \n"
		"lh              $t5,28($s0)                            \n"
		".L000000:                                              \n"
		"jal             func_8085FF28                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lh              $t5,28($s0)                            \n"
		".L000001:                                              \n"
		"bnel            $t5,$zero,.L000002                     \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $t6,4($s0)                             \n"
		"ori             $t7,$t6,0x80                           \n"
		"sw              $t7,4($s0)                             \n"
		"lw              $ra,44($sp)                            \n"
		".L000002:                                              \n"
		"lw              $s0,36($sp)                            \n"
		"lw              $s1,40($sp)                            \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,488                            \n"
	);
}

void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 40 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldest: \n"
	);

  z64_actor_t *closest; /* Closest Actor Instance */

  if ((en->actor).variable != 2)
  {
    /* external_func_800353F4 */
    if (closest = find_closest_actor_instance_within_range(gl, en, 0x0002, 0x0005, 8000.0f), closest == 0)
    {
      /* external_func_800F5B58 */
      external_func_800F5B58();
    }
  }
  external_func_8002709C(gl, AADDR(en->unknown, 0x06D0)); /* external_func_8002709C */
  actor_collider_cylinder_free(gl, AADDR(en->unknown, 0x07A0)); /* external_func_8005C3AC */
  actor_collider_cylinder_free(gl, AADDR(en->unknown, 0x06D4)); /* external_func_8005C3AC */
  external_func_8005D060(gl, AADDR(en->unknown, 0x0720)); /* external_func_8005D060 */
}

void func_8085F938(void) /* 0 internal, 1 external, 53 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8085F938: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $a0,24($sp)                            \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t7,$zero,1                            \n"
		"lui             $at,0x4F00                             \n"
		"mul.s           $f6,$f0,$f4                            \n"
		"lw              $a2,24($sp)                            \n"
		"cfc1            $t6,$f31                               \n"
		"ctc1            $t7,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f8,$f6                                \n"
		"cfc1            $t7,$f31                               \n"
		"nop                                                    \n"
		"andi            $t7,$t7,0x78                           \n"
		"beql            $t7,$zero,.L000005                     \n"
		"mfc1            $t7,$f8                                \n"
		"mtc1            $at,$f8                                \n"
		"addiu           $t7,$zero,1                            \n"
		"sub.s           $f8,$f6,$f8                            \n"
		"ctc1            $t7,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f8,$f8                                \n"
		"cfc1            $t7,$f31                               \n"
		"nop                                                    \n"
		"andi            $t7,$t7,0x78                           \n"
		"bne             $t7,$zero,.L000006                     \n"
		"nop                                                    \n"
		"mfc1            $t7,$f8                                \n"
		"lui             $at,0x8000                             \n"
		"beq             $zero,$zero,.L000007                   \n"
		"or              $t7,$t7,$at                            \n"
		".L000006:                                              \n"
		"beq             $zero,$zero,.L000007                   \n"
		"addiu           $t7,$zero,-1                           \n"
		"mfc1            $t7,$f8                                \n"
		".L000005:                                              \n"
		"nop                                                    \n"
		"bltz            $t7,.L000006                           \n"
		"nop                                                    \n"
		".L000007:                                              \n"
		"ctc1            $t6,$f31                               \n"
		"sltiu           $at,$t7,11                             \n"
		"beq             $at,$zero,.L000008                     \n"
		"sll             $t7,$t7,2                              \n"
		"lui             $at,%hi(data_80864720)                 \n"
		"addu            $at,$at,$t7                            \n"
		"lw              $t7,%lo(data_80864720)($at)            \n"
		"jr              $t7                                    \n"
		"nop                                                    \n"
	);
}
void data_8085FA00(void) /* 1 internal, 2 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FA00: \n"
	);
	asm(
		"lui             $at,0x435C                             \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f0,144($a2)                           \n"
		"lui             $at,0x432A                             \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1f            .Ldata_8085FA74                        \n"
		"nop                                                    \n"
		"mtc1            $at,$f16                               \n"
		"or              $a0,$a2,$zero                          \n"
		"addiu           $a1,$zero,1820                         \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .Ldata_8085FA74                        \n"
		"nop                                                    \n"
		"jal             external_func_8002E084                 \n"
		"sw              $a2,24($sp)                            \n"
		"beq             $v0,$zero,.Ldata_8085FA74              \n"
		"lw              $a2,24($sp)                            \n"
		"lw              $a0,28($sp)                            \n"
		"or              $a1,$a2,$zero                          \n"
		"jal             external_func_80033A84                 \n"
		"sw              $a2,24($sp)                            \n"
		"beq             $v0,$zero,.Ldata_8085FA74              \n"
		"lw              $a2,24($sp)                            \n"
		"jal             func_80861B94                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000009                   \n"
		"lw              $ra,20($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_8085FA74 \n"
		"nop                 \n"
	);
}
void data_8085FA74(void) /* 1 internal, 0 external, 4 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FA74: \n"
	);
	asm(
		"jal             func_80860438                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000009                   \n"
		"lw              $ra,20($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_8085FA84 \n"
		"nop                 \n"
	);
}
void data_8085FA84(void) /* 1 internal, 0 external, 5 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FA84: \n"
	);
	asm(
		"or              $a0,$a2,$zero                          \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,28($sp)                            \n"
		"beq             $zero,$zero,.L000009                   \n"
		"lw              $ra,20($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_8085FA98 \n"
		"nop                 \n"
	);
}
void data_8085FA98(void) /* 1 internal, 0 external, 8 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FA98: \n"
	);
	asm(
		"jal             func_80861EC0                          \n"
		"or              $a0,$a2,$zero                          \n"
		".L000008:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000009:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_8085FAB0(void) /* 0 internal, 1 external, 71 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8085FAB0: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,20($sp)                            \n"
		"lw              $t0,7236($a1)                          \n"
		"lh              $v1,182($a0)                           \n"
		"or              $a2,$a0,$zero                          \n"
		"lh              $t6,182($t0)                           \n"
		"or              $a3,$a1,$zero                          \n"
		"subu            $v0,$t6,$v1                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bgezl           $v0,.L000010                           \n"
		"slti            $at,$v0,25000                          \n"
		"subu            $v0,$zero,$v0                          \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"slti            $at,$v0,25000                          \n"
		".L000010:                                              \n"
		"bnel            $at,$zero,.L000011                     \n"
		"slti            $at,$v0,16001                          \n"
		"sw              $a2,32($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $a3,36($sp)                            \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t8,$zero,1                            \n"
		"lui             $at,0x4F00                             \n"
		"mul.s           $f6,$f0,$f4                            \n"
		"lw              $a2,32($sp)                            \n"
		"lw              $a3,36($sp)                            \n"
		"cfc1            $t7,$f31                               \n"
		"ctc1            $t8,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f8,$f6                                \n"
		"cfc1            $t8,$f31                               \n"
		"nop                                                    \n"
		"andi            $t8,$t8,0x78                           \n"
		"beql            $t8,$zero,.L000012                     \n"
		"mfc1            $t8,$f8                                \n"
		"mtc1            $at,$f8                                \n"
		"addiu           $t8,$zero,1                            \n"
		"sub.s           $f8,$f6,$f8                            \n"
		"ctc1            $t8,$f31                               \n"
		"nop                                                    \n"
		"cvt.w.s         $f8,$f8                                \n"
		"cfc1            $t8,$f31                               \n"
		"nop                                                    \n"
		"andi            $t8,$t8,0x78                           \n"
		"bne             $t8,$zero,.L000013                     \n"
		"nop                                                    \n"
		"mfc1            $t8,$f8                                \n"
		"lui             $at,0x8000                             \n"
		"beq             $zero,$zero,.L000014                   \n"
		"or              $t8,$t8,$at                            \n"
		".L000013:                                              \n"
		"beq             $zero,$zero,.L000014                   \n"
		"addiu           $t8,$zero,-1                           \n"
		"mfc1            $t8,$f8                                \n"
		".L000012:                                              \n"
		"nop                                                    \n"
		"bltz            $t8,.L000013                           \n"
		"nop                                                    \n"
		".L000014:                                              \n"
		"ctc1            $t7,$f31                               \n"
		"sltiu           $at,$t8,10                             \n"
		"beq             $at,$zero,.L000015                     \n"
		"sll             $t8,$t8,2                              \n"
		"lui             $at,%hi(data_8086474C)                 \n"
		"addu            $at,$at,$t8                            \n"
		"lw              $t8,%lo(data_8086474C)($at)            \n"
		"jr              $t8                                    \n"
		"nop                                                    \n"
	);
}
void data_8085FBBC(void) /* 1 internal, 0 external, 4 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FBBC: \n"
	);
	asm(
		"jal             func_80861EC0                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_8085FBCC \n"
		"nop                 \n"
	);
}
void data_8085FBCC(void) /* 1 internal, 0 external, 5 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FBCC: \n"
	);
	asm(
		"or              $a0,$a2,$zero                          \n"
		"jal             func_808627C4                          \n"
		"or              $a1,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_8085FBE0 \n"
		"nop                 \n"
	);
}
void func_80864158(void) /* 1 internal, 2 external, 36 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80864158: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $a1,28($sp)                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-7504                          \n"
		"sw              $a3,24($sp)                            \n"
		"addiu           $a0,$a0,392                            \n"
		"jal             external_func_800A534C                 \n"
		"lui             $a2,0xC000                             \n"
		"lw              $a3,24($sp)                            \n"
		"lwc1            $f4,28($sp)                            \n"
		"lh              $t6,182($a3)                           \n"
		"swc1            $f4,104($a3)                           \n"
		"addiu           $t7,$t6,16383                          \n"
		"jal             external_func_800FD9AC                 \n"
		"sh              $t7,50($a3)                            \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f10                               \n"
		"mul.s           $f8,$f0,$f6                            \n"
		"lw              $a0,24($sp)                            \n"
		"addiu           $t0,$zero,24                           \n"
		"lui             $a1,%hi(data_808628C8)                 \n"
		"addiu           $a1,$a1,%lo(data_808628C8)             \n"
		"sb              $t0,1992($a0)                          \n"
		"add.s           $f16,$f8,$f10                          \n"
		"trunc.w.s       $f18,$f16                              \n"
		"mfc1            $t9,$f18                               \n"
		"jal             func_8085F650                          \n"
		"sw              $t9,2024($a0)                          \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_8085FDD0(void) /* 1 internal, 1 external, 30 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8085FDD0: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,12652                          \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $at,0x4060                             \n"
		"mtc1            $at,$f8                                \n"
		"lwc1            $f6,12($a0)                            \n"
		"lw              $t7,4($a0)                             \n"
		"mtc1            $zero,$f4                              \n"
		"sub.s           $f10,$f6,$f8                           \n"
		"addiu           $at,$zero,-2                           \n"
		"addiu           $t6,$zero,15                           \n"
		"lui             $a1,%hi(data_8085FE48)                 \n"
		"and             $t8,$t7,$at                            \n"
		"addiu           $a1,$a1,%lo(data_8085FE48)             \n"
		"sb              $zero,1992($a0)                        \n"
		"sw              $t6,2024($a0)                          \n"
		"swc1            $f10,40($a0)                           \n"
		"sw              $t8,4($a0)                             \n"
		"jal             func_8085F650                          \n"
		"swc1            $f4,84($a0)                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8085FE48(void) /* 1 internal, 2 external, 61 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FE48: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $a1,28($sp)                            \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a2,24($sp)                            \n"
		"lui             $at,0x4316                             \n"
		"lw              $v0,2024($a2)                          \n"
		"bne             $v0,$zero,.L000025                     \n"
		"nop                                                    \n"
		"lwc1            $f0,148($a2)                           \n"
		"mtc1            $zero,$f4                              \n"
		"mtc1            $at,$f6                                \n"
		"lui             $a1,%hi(data_80863360)                 \n"
		"c.le.s          $f4,$f0                                \n"
		"addiu           $t6,$zero,3                            \n"
		"addiu           $a1,$a1,%lo(data_80863360)             \n"
		"or              $a0,$a2,$zero                          \n"
		"bc1fl           .L000026                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000026                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000026:                                              \n"
		"c.lt.s          $f2,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000025                               \n"
		"nop                                                    \n"
		"sb              $t6,1992($a2)                          \n"
		"jal             func_8085F650                          \n"
		"sw              $a2,24($sp)                            \n"
		"lw              $a2,24($sp)                            \n"
		"addiu           $at,$zero,2                            \n"
		"lh              $v0,138($a2)                           \n"
		"lh              $t7,28($a2)                            \n"
		"sh              $v0,50($a2)                            \n"
		"beq             $t7,$at,.L000027                       \n"
		"sh              $v0,182($a2)                           \n"
		"jal             external_func_800F5ACC                 \n"
		"addiu           $a0,$zero,56                           \n"
		"beq             $zero,$zero,.L000028                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000025:                                              \n"
		"beq             $v0,$zero,.L000029                     \n"
		"lui             $at,0x4060                             \n"
		"addiu           $t8,$v0,-1                             \n"
		"sw              $t8,2024($a2)                          \n"
		".L000029:                                              \n"
		"lwc1            $f8,12($a2)                            \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"sub.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,40($a2)                           \n"
		".L000027:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000028:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_8085FF28(void) /* 1 internal, 2 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8085FF28: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,12652                          \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $at,0x4316                             \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f4,12($a0)                            \n"
		"addiu           $a1,$zero,0                            \n"
		"sb              $zero,1992($a0)                        \n"
		"add.s           $f8,$f4,$f6                            \n"
		"jal             external_func_8002D62C                 \n"
		"swc1            $f8,40($a0)                            \n"
		"lw              $a0,24($sp)                            \n"
		"addiu           $at,$zero,-2                           \n"
		"lui             $a1,%hi(data_8085FF9C)                 \n"
		"lw              $t6,4($a0)                             \n"
		"addiu           $a1,$a1,%lo(data_8085FF9C)             \n"
		"and             $t7,$t6,$at                            \n"
		"jal             func_8085F650                          \n"
		"sw              $t7,4($a0)                             \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8085FF9C(void) /* 1 internal, 2 external, 54 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FF9C: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $a1,28($sp)                            \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a2,24($sp)                            \n"
		"lui             $at,0x4316                             \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0x4348                             \n"
		"mtc1            $at,$f16                               \n"
		"lwc1            $f10,144($a2)                          \n"
		"lwc1            $f4,12($a2)                            \n"
		"lui             $at,0x43E1                             \n"
		"c.lt.s          $f10,$f16                              \n"
		"add.s           $f8,$f4,$f6                            \n"
		"bc1f            .L000030                               \n"
		"swc1            $f8,40($a2)                            \n"
		"lwc1            $f0,148($a2)                           \n"
		"mtc1            $zero,$f18                             \n"
		"mtc1            $at,$f4                                \n"
		"lui             $a1,%hi(data_80860318)                 \n"
		"c.le.s          $f18,$f0                               \n"
		"addiu           $a1,$a1,%lo(data_80860318)             \n"
		"or              $a0,$a2,$zero                          \n"
		"bc1fl           .L000031                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000031                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000031:                                              \n"
		"c.lt.s          $f2,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000032                               \n"
		"lw              $ra,20($sp)                            \n"
		"jal             func_8085F650                          \n"
		"sw              $a2,24($sp)                            \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $a1,0x3C75                             \n"
		"ori             $a1,$a1,0xc28f                         \n"
		"lw              $t6,4($a0)                             \n"
		"lh              $v0,138($a0)                           \n"
		"ori             $t7,$t6,0x1                            \n"
		"sw              $t7,4($a0)                             \n"
		"sh              $v0,50($a0)                            \n"
		"jal             external_func_8002D62C                 \n"
		"sh              $v0,182($a0)                           \n"
		".L000030:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000032:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80860068(void) /* 1 internal, 2 external, 33 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80860068: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,12652                          \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a2,24($sp)                            \n"
		"addiu           $t6,$zero,10                           \n"
		"jal             external_func_800FD9AC                 \n"
		"sb              $t6,1992($a2)                          \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f8                                \n"
		"mul.s           $f6,$f0,$f4                            \n"
		"lw              $a0,24($sp)                            \n"
		"mtc1            $zero,$f18                             \n"
		"lui             $a1,%hi(data_808600EC)                 \n"
		"lh              $t9,182($a0)                           \n"
		"addiu           $a1,$a1,%lo(data_808600EC)             \n"
		"swc1            $f18,104($a0)                          \n"
		"add.s           $f10,$f6,$f8                           \n"
		"sh              $t9,50($a0)                            \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t8,$f16                               \n"
		"jal             func_8085F650                          \n"
		"sw              $t8,2024($a0)                          \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 4 external, 72 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldraw: \n"
	);

  int16_t sVar2;

  external_func_80093D18((gl->common).gfx_ctxt); /* external_func_80093D18 */
  external_func_8002EBCC(en, gl, 1); /* external_func_8002EBCC */

  if (((en->actor).variable < 4) || ((en->actor).attached_b == 0x0))
  {
    /* external_func_800A15C8 */
    skelanime_draw(gl, *(en->unknown + 0x50), *(en->unknown + 0x6C), /*uint8_t limb_dlists_count,*/ &skl_callback_80863AB8, &skl_callback_80863CC4, en);
  }
  if (*((en->unknown) + 0x06A4) != 0)
  {
    *((en->unknown) + 0x06A4)--;
    sVar2 = *((en->unknown) + 0x06A4);
    (en->actor).damage_color_timer++;
    if ((sVar2 * 3U) == 0)
    {
      external_func_8002A1DC(
        gl,
        en,
        en->unknown + (sVar2 >> 2) * 6 + 10,
        0x96,
        0x96,
        0x96,
        0xFA,
        0xEB,
        0xF5,
        0xFF,
        0x3FC00000
      );
    }
  }
}

void data_80860318(void) /* 1 internal, 3 external, 46 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80860318: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $a1,44($sp)                            \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a0,$a0,392                            \n"
		"sw              $a0,36($sp)                            \n"
		"addiu           $a1,$a1,-15304                         \n"
		"jal             external_func_800A529C                 \n"
		"addiu           $a2,$zero,0                            \n"
		"jal             external_func_800A49FC                 \n"
		"lw              $a0,36($sp)                            \n"
		"lwc1            $f4,128($s0)                           \n"
		"lwc1            $f6,40($s0)                            \n"
		"c.le.s          $f6,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000045                               \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $t7,2020($s0)                          \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f8                                \n"
		"mtc1            $t7,$f10                               \n"
		"addiu           $t6,$zero,12                           \n"
		"sb              $t6,1992($s0)                          \n"
		"cvt.s.w         $f16,$f10                              \n"
		"lui             $at,%hi(data_80864788)                 \n"
		"swc1            $f8,420($s0)                           \n"
		"lwc1            $f18,%lo(data_80864788)($at)           \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,14458                        \n"
		"mul.s           $f4,$f16,$f18                          \n"
		"trunc.w.s       $f6,$f4                                \n"
		"mfc1            $t9,$f6                                \n"
		"jal             external_func_8002F828                 \n"
		"sw              $t9,2024($s0)                          \n"
		"lui             $a1,%hi(data_808603CC)                 \n"
		"addiu           $a1,$a1,%lo(data_808603CC)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,28($sp)                            \n"
		".L000045:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808603CC(void) /* 1 internal, 2 external, 28 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808603CC: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"beql            $v0,$zero,.L000046                     \n"
		"lw              $ra,20($sp)                            \n"
		"jal             func_80860068                          \n"
		"lw              $a0,24($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f8                                \n"
		"mul.s           $f6,$f0,$f4                            \n"
		"lw              $t8,24($sp)                            \n"
		"add.s           $f10,$f6,$f8                           \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t7,$f16                               \n"
		"nop                                                    \n"
		"sw              $t7,2024($t8)                          \n"
		"lw              $ra,20($sp)                            \n"
		".L000046:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80860438(void) /* 1 internal, 4 external, 49 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80860438: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $s0,40($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,44($sp)                            \n"
		"lui             $a0,0x0600                             \n"
		"jal             external_func_800A2000                 \n"
		"addiu           $a0,$a0,7200                           \n"
		"mtc1            $v0,$f4                                \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f0                                \n"
		"cvt.s.w         $f6,$f4                                \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $t6,$zero,2                            \n"
		"mfc1            $a2,$f0                                \n"
		"sw              $t6,20($sp)                            \n"
		"addiu           $a1,$a1,7200                           \n"
		"swc1            $f6,16($sp)                            \n"
		"addiu           $a0,$s0,1192                           \n"
		"addiu           $a3,$zero,0                            \n"
		"jal             external_func_800A51A0                 \n"
		"swc1            $f0,24($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-32332                         \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$s0,392                            \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f8                                \n"
		"lh              $t2,182($s0)                           \n"
		"addiu           $t1,$zero,13                           \n"
		"mul.s           $f10,$f0,$f8                           \n"
		"lui             $a1,%hi(data_808604FC)                 \n"
		"sb              $t1,1992($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_808604FC)             \n"
		"or              $a0,$s0,$zero                          \n"
		"sh              $t2,50($s0)                            \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t8,$f16                               \n"
		"nop                                                    \n"
		"sll             $t9,$t8,16                             \n"
		"sra             $t0,$t9,16                             \n"
		"jal             func_8085F650                          \n"
		"sw              $t0,2024($s0)                          \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863FCC(void) /* 0 internal, 1 external, 33 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863FCC: \n"
	);
	asm(
		"lw              $t0,124($sp)                           \n"
		"lui             $a0,%hi(data_80864670)                 \n"
		"addiu           $a0,$a0,%lo(data_80864670)             \n"
		"bltzl           $t0,.L000322                           \n"
		"lw              $ra,52($sp)                            \n"
		"jal             external_func_800D1AF4                 \n"
		"addiu           $a1,$sp,80                             \n"
		"lwc1            $f10,80($sp)                           \n"
		"lw              $t1,124($sp)                           \n"
		"trunc.w.s       $f16,$f10                              \n"
		"sll             $t2,$t1,2                              \n"
		"subu            $t2,$t2,$t1                            \n"
		"sll             $t2,$t2,1                              \n"
		"mfc1            $t4,$f16                               \n"
		"addu            $v0,$s0,$t2                            \n"
		"sh              $t4,332($v0)                           \n"
		"lwc1            $f18,84($sp)                           \n"
		"trunc.w.s       $f4,$f18                               \n"
		"mfc1            $t6,$f4                                \n"
		"nop                                                    \n"
		"sh              $t6,334($v0)                           \n"
		"lwc1            $f6,88($sp)                            \n"
		"trunc.w.s       $f8,$f6                                \n"
		"mfc1            $t8,$f8                                \n"
		"nop                                                    \n"
		"sh              $t8,336($v0)                           \n"
		".L000321:                                              \n"
		"lw              $ra,52($sp)                            \n"
		".L000322:                                              \n"
		"lw              $s0,48($sp)                            \n"
		"addiu           $sp,$sp,128                            \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80860BDC(void) /* 1 internal, 1 external, 18 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80860BDC: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-7504                          \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"addiu           $t6,$zero,14                           \n"
		"lui             $a1,%hi(data_80860C24)                 \n"
		"addiu           $a1,$a1,%lo(data_80860C24)             \n"
		"jal             func_8085F650                          \n"
		"sb              $t6,1992($a0)                          \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863FC4(void) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863FC4: \n"
	);
	asm(
		"addiu           $t9,$zero,8                            \n"
		"sw              $t9,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863FCC \n"
		"nop                 \n"
	);
}
void func_80860EC0(void) /* 1 internal, 2 external, 50 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80860EC0: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-7504                          \n"
		"jal             external_func_800A52F8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"addiu           $t6,$zero,15                           \n"
		"jal             external_func_800FD9AC                 \n"
		"sb              $t6,1992($s0)                          \n"
		"lui             $at,0x3F00                             \n"
		"mtc1            $at,$f2                                \n"
		"lui             $at,0xBF00                             \n"
		"c.lt.s          $f2,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000100                               \n"
		"swc1            $f2,104($s0)                           \n"
		"mtc1            $at,$f4                                \n"
		"beq             $zero,$zero,.L000100                   \n"
		"swc1            $f4,104($s0)                           \n"
		"swc1            $f2,104($s0)                           \n"
		".L000100:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0x41C8                             \n"
		"mtc1            $at,$f10                               \n"
		"mul.s           $f8,$f0,$f6                            \n"
		"mtc1            $zero,$f4                              \n"
		"lh              $t1,182($s0)                           \n"
		"lui             $a1,%hi(data_80860F84)                 \n"
		"addiu           $a1,$a1,%lo(data_80860F84)             \n"
		"or              $a0,$s0,$zero                          \n"
		"swc1            $f4,2028($s0)                          \n"
		"add.s           $f16,$f8,$f10                          \n"
		"sh              $t1,50($s0)                            \n"
		"trunc.w.s       $f18,$f16                              \n"
		"mfc1            $t8,$f18                               \n"
		"nop                                                    \n"
		"sll             $t9,$t8,16                             \n"
		"sra             $t0,$t9,16                             \n"
		"jal             func_8085F650                          \n"
		"sw              $t0,2024($s0)                          \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80860F84(void) /* 2 internal, 8 external, 322 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80860F84: \n"
	);
	asm(
		"addiu           $sp,$sp,-72                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"lw              $t6,7236($a1)                          \n"
		"mtc1            $zero,$f4                              \n"
		"or              $s0,$a0,$zero                          \n"
		"or              $a2,$a1,$zero                          \n"
		"or              $a0,$a1,$zero                          \n"
		"or              $a1,$s0,$zero                          \n"
		"sw              $a2,76($sp)                            \n"
		"sw              $t6,48($sp)                            \n"
		"jal             func_808641E8                          \n"
		"swc1            $f4,44($sp)                            \n"
		"bne             $v0,$zero,.L000101                     \n"
		"addiu           $a0,$s0,182                            \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $t7,$zero,1                            \n"
		"sw              $t7,16($sp)                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_8007869C                 \n"
		"addiu           $a3,$zero,4000                         \n"
		"lh              $t8,182($s0)                           \n"
		"ori             $at,$zero,0x8000                       \n"
		"mtc1            $zero,$f6                              \n"
		"addiu           $t9,$t8,16000                          \n"
		"sh              $t9,50($s0)                            \n"
		"lw              $t0,48($sp)                            \n"
		"lh              $t1,182($t0)                           \n"
		"addu            $t2,$t1,$at                            \n"
		"sh              $t2,70($sp)                            \n"
		"lwc1            $f0,104($s0)                           \n"
		"c.le.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000102                               \n"
		"lui             $at,0x40C0                             \n"
		"mtc1            $at,$f2                                \n"
		"lui             $at,0x3F00                             \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1f            .L000103                               \n"
		"nop                                                    \n"
		"mtc1            $at,$f8                                \n"
		"nop                                                    \n"
		"add.s           $f10,$f0,$f8                           \n"
		"beq             $zero,$zero,.L000104                   \n"
		"swc1            $f10,104($s0)                          \n"
		".L000103:                                              \n"
		"beq             $zero,$zero,.L000104                   \n"
		"swc1            $f2,104($s0)                           \n"
		".L000102:                                              \n"
		"lui             $at,0xC0C0                             \n"
		"mtc1            $at,$f2                                \n"
		"lui             $at,0x3F00                             \n"
		"c.lt.s          $f2,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000104                               \n"
		"swc1            $f2,104($s0)                           \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"sub.s           $f18,$f0,$f16                          \n"
		"beq             $zero,$zero,.L000104                   \n"
		"swc1            $f18,104($s0)                          \n"
		"swc1            $f2,104($s0)                           \n"
		".L000104:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		"andi            $v0,$v0,0x8                            \n"
		"bne             $v0,$zero,.L000105                     \n"
		"nop                                                    \n"
		"lh              $t3,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"or              $a0,$s0,$zero                          \n"
		"bne             $t3,$at,.L000106                       \n"
		"lw              $a1,76($sp)                            \n"
		"lw              $a2,104($s0)                           \n"
		"jal             external_func_800339B8                 \n"
		"lh              $a3,50($s0)                            \n"
		"bnel            $v0,$zero,.L000107                     \n"
		"lw              $a0,76($sp)                            \n"
		"lhu             $v0,136($s0)                           \n"
		"andi            $v0,$v0,0x8                            \n"
		".L000105:                                              \n"
		"beq             $v0,$zero,.L000108                     \n"
		"lui             $at,%hi(data_808647B4)                 \n"
		"lwc1            $f4,104($s0)                           \n"
		"mtc1            $zero,$f6                              \n"
		"nop                                                    \n"
		"c.le.s          $f6,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000109                               \n"
		"lh              $v0,182($s0)                           \n"
		"lh              $v0,182($s0)                           \n"
		"addiu           $v0,$v0,16383                          \n"
		"sll             $v0,$v0,16                             \n"
		"beq             $zero,$zero,.L000110                   \n"
		"sra             $v0,$v0,16                             \n"
		"lh              $v0,182($s0)                           \n"
		".L000109:                                              \n"
		"addiu           $v0,$v0,-16383                         \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		".L000110:                                              \n"
		"lh              $t4,126($s0)                           \n"
		"subu            $v0,$t4,$v0                            \n"
		"sll             $v0,$v0,16                             \n"
		"beq             $zero,$zero,.L000111                   \n"
		"sra             $v0,$v0,16                             \n"
		".L000108:                                              \n"
		"lwc1            $f8,104($s0)                           \n"
		"lwc1            $f10,%lo(data_808647B4)($at)           \n"
		"or              $v0,$zero,$zero                        \n"
		"mul.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,104($s0)                          \n"
		".L000111:                                              \n"
		"bltz            $v0,.L000112                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000112                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000112:                                              \n"
		"slti            $at,$v1,16385                          \n"
		"bne             $at,$zero,.L000106                     \n"
		"lui             $at,%hi(data_808647B8)                 \n"
		"lwc1            $f4,%lo(data_808647B8)($at)            \n"
		"lwc1            $f18,104($s0)                          \n"
		"mtc1            $zero,$f8                              \n"
		"lui             $at,0x3F00                             \n"
		"mul.s           $f6,$f18,$f4                           \n"
		"swc1            $f6,104($s0)                           \n"
		"lwc1            $f0,104($s0)                           \n"
		"c.lt.s          $f0,$f8                                \n"
		"nop                                                    \n"
		"bc1fl           .L000113                               \n"
		"mtc1            $at,$f18                               \n"
		"lui             $at,0x3F00                             \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"sub.s           $f16,$f0,$f10                          \n"
		"beq             $zero,$zero,.L000106                   \n"
		"swc1            $f16,104($s0)                          \n"
		"mtc1            $at,$f18                               \n"
		".L000113:                                              \n"
		"nop                                                    \n"
		"add.s           $f4,$f0,$f18                           \n"
		"swc1            $f4,104($s0)                           \n"
		".L000106:                                              \n"
		"lw              $a0,76($sp)                            \n"
		".L000107:                                              \n"
		"jal             external_func_80033AB8                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000114                     \n"
		"lui             $at,0x4348                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"swc1            $f2,44($sp)                            \n"
		".L000114:                                              \n"
		"lui             $at,0x42A0                             \n"
		"lwc1            $f2,44($sp)                            \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f0,144($s0)                           \n"
		"addiu           $a0,$s0,2028                           \n"
		"add.s           $f8,$f6,$f2                            \n"
		"lui             $a1,0xC020                             \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3F4C                             \n"
		"c.le.s          $f0,$f8                                \n"
		"lui             $at,0x42DC                             \n"
		"bc1fl           .L000115                               \n"
		"mtc1            $at,$f16                               \n"
		"mtc1            $zero,$f10                             \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f10,16($sp)                           \n"
		"beq             $zero,$zero,.L000116                   \n"
		"mtc1            $zero,$f8                              \n"
		"mtc1            $at,$f16                               \n"
		".L000115:                                              \n"
		"addiu           $a0,$s0,2028                           \n"
		"addiu           $a1,$zero,0                            \n"
		"add.s           $f18,$f16,$f2                          \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x40D4                             \n"
		"c.lt.s          $f18,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000117                               \n"
		"mtc1            $zero,$f6                              \n"
		"mtc1            $zero,$f4                              \n"
		"lui             $a3,0x3F4C                             \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"addiu           $a0,$s0,2028                           \n"
		"lui             $a1,0x4020                             \n"
		"lui             $a2,0x3F80                             \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f4,16($sp)                            \n"
		"beq             $zero,$zero,.L000116                   \n"
		"mtc1            $zero,$f8                              \n"
		"mtc1            $zero,$f6                              \n"
		".L000117:                                              \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f6,16($sp)                            \n"
		"mtc1            $zero,$f8                              \n"
		".L000116:                                              \n"
		"lwc1            $f10,2028($s0)                         \n"
		"c.eq.s          $f8,$f10                               \n"
		"nop                                                    \n"
		"bc1tl           .L000118                               \n"
		"lui             $at,0x3F00                             \n"
		"jal             external_func_80077870                 \n"
		"lh              $a0,182($s0)                           \n"
		"lwc1            $f18,2028($s0)                         \n"
		"lwc1            $f16,36($s0)                           \n"
		"lh              $a0,182($s0)                           \n"
		"mul.s           $f4,$f0,$f18                           \n"
		"add.s           $f6,$f16,$f4                           \n"
		"jal             external_func_80077834                 \n"
		"swc1            $f6,36($s0)                            \n"
		"lwc1            $f10,2028($s0)                         \n"
		"lwc1            $f8,44($s0)                            \n"
		"mul.s           $f18,$f0,$f10                          \n"
		"add.s           $f16,$f8,$f18                          \n"
		"swc1            $f16,44($s0)                           \n"
		"lui             $at,0x3F00                             \n"
		".L000118:                                              \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f4,104($s0)                           \n"
		"lwc1            $f8,416($s0)                           \n"
		"addiu           $a0,$s0,392                            \n"
		"mul.s           $f10,$f4,$f6                           \n"
		"trunc.w.s       $f18,$f8                               \n"
		"mfc1            $v1,$f18                               \n"
		"swc1            $f10,420($s0)                          \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $v1,60($sp)                            \n"
		"mtc1            $zero,$f14                             \n"
		"lwc1            $f0,420($s0)                           \n"
		"lw              $v1,60($sp)                            \n"
		"c.le.s          $f14,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000119                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000119                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000119:                                              \n"
		"lwc1            $f12,416($s0)                          \n"
		"c.le.s          $f14,$f0                               \n"
		"sub.s           $f16,$f12,$f2                          \n"
		"trunc.w.s       $f6,$f12                               \n"
		"trunc.w.s       $f4,$f16                               \n"
		"mfc1            $t8,$f6                                \n"
		"mfc1            $a0,$f4                                \n"
		"bc1fl           .L000120                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000120                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000120:                                              \n"
		"beql            $v1,$t8,.L000121                       \n"
		"lw              $t1,76($sp)                            \n"
		"trunc.w.s       $f10,$f2                               \n"
		"mfc1            $t0,$f10                               \n"
		"nop                                                    \n"
		"addu            $v0,$t0,$v1                            \n"
		"slti            $at,$v0,2                              \n"
		"bnel            $at,$zero,.L000122                     \n"
		"slti            $at,$a0,7                              \n"
		"blez            $a0,.L000123                           \n"
		"slti            $at,$a0,7                              \n"
		".L000122:                                              \n"
		"beq             $at,$zero,.L000124                     \n"
		"slti            $at,$v0,8                              \n"
		"bne             $at,$zero,.L000124                     \n"
		".L000123:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14397                        \n"
		".L000124:                                              \n"
		"lw              $t1,76($sp)                            \n"
		".L000121:                                              \n"
		"lui             $t2,0x0001                             \n"
		"or              $a0,$s0,$zero                          \n"
		"addu            $t2,$t2,$t1                            \n"
		"lw              $t2,7652($t2)                          \n"
		"andi            $t3,$t2,0x5f                           \n"
		"bnel            $t3,$zero,.L000125                     \n"
		"lh              $t4,70($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"lh              $t4,70($sp)                            \n"
		".L000125:                                              \n"
		"lh              $t5,182($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"subu            $v0,$t4,$t5                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bgezl           $v0,.L000126                           \n"
		"slti            $at,$v0,26625                          \n"
		"subu            $v0,$zero,$v0                          \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"slti            $at,$v0,26625                          \n"
		".L000126:                                              \n"
		"beq             $at,$zero,.L000127                     \n"
		"nop                                                    \n"
		"lw              $v0,2024($s0)                          \n"
		"bne             $v0,$zero,.L000128                     \n"
		"nop                                                    \n"
		".L000127:                                              \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,76($sp)                            \n"
		"beq             $zero,$zero,.L000129                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000128:                                              \n"
		"beq             $v0,$zero,.L000101                     \n"
		"addiu           $t6,$v0,-1                             \n"
		"sw              $t6,2024($s0)                          \n"
		".L000101:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000129:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,72                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80861418(void) /* 1 internal, 2 external, 34 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80861418: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-20468                         \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"addiu           $a0,$s0,228                            \n"
		"jal             external_func_800F8A44                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"lbu             $t6,2156($s0)                          \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t8,$zero,16                           \n"
		"lui             $a1,%hi(data_8086149C)                 \n"
		"andi            $t7,$t6,0xfffb                         \n"
		"sb              $t7,2156($s0)                          \n"
		"sb              $t8,1992($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_8086149C)             \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085F650                          \n"
		"swc1            $f4,104($s0)                           \n"
		"lbu             $t0,2014($s0)                          \n"
		"addiu           $t9,$zero,16                           \n"
		"sb              $t9,2169($s0)                          \n"
		"beq             $t0,$zero,.L000130                     \n"
		"addiu           $t1,$zero,3                            \n"
		"sb              $t1,2014($s0)                          \n"
		".L000130:                                              \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8086149C(void) /* 2 internal, 3 external, 72 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8086149C: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lwc1            $f0,416($a0)                           \n"
		"mtc1            $zero,$f4                              \n"
		"or              $s0,$a0,$zero                          \n"
		"trunc.w.s       $f6,$f0                                \n"
		"addiu           $a0,$a0,182                            \n"
		"addiu           $a2,$zero,1                            \n"
		"addiu           $a3,$zero,3000                         \n"
		"mfc1            $v1,$f6                                \n"
		"swc1            $f4,-78($a0)                           \n"
		"slti            $at,$v1,4                              \n"
		"beql            $at,$zero,.L000131                     \n"
		"addiu           $at,$zero,7                            \n"
		"lh              $a1,138($s0)                           \n"
		"jal             external_func_8007869C                 \n"
		"sw              $zero,16($sp)                          \n"
		"lwc1            $f0,416($s0)                           \n"
		"trunc.w.s       $f8,$f0                                \n"
		"mfc1            $v1,$f8                                \n"
		"nop                                                    \n"
		"addiu           $at,$zero,7                            \n"
		".L000131:                                              \n"
		"bne             $v1,$at,.L000132                       \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14393                        \n"
		"lwc1            $f0,416($s0)                           \n"
		".L000132:                                              \n"
		"lui             $at,0x40E0                             \n"
		"mtc1            $at,$f10                               \n"
		"lui             $at,0x4130                             \n"
		"c.lt.s          $f10,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000133                               \n"
		"sb              $zero,2056($s0)                        \n"
		"mtc1            $at,$f16                               \n"
		"addiu           $t8,$zero,1                            \n"
		"c.lt.s          $f0,$f16                               \n"
		"nop                                                    \n"
		"bc1fl           .L000133                               \n"
		"sb              $zero,2056($s0)                        \n"
		"beq             $zero,$zero,.L000133                   \n"
		"sb              $t8,2056($s0)                          \n"
		"sb              $zero,2056($s0)                        \n"
		".L000133:                                              \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"beq             $v0,$zero,.L000134                     \n"
		"lw              $t9,44($sp)                            \n"
		"lui             $t0,0x0001                             \n"
		"addu            $t0,$t0,$t9                            \n"
		"lw              $t0,7652($t0)                          \n"
		"andi            $t1,$t0,0x1                            \n"
		"beq             $t1,$zero,.L000135                     \n"
		"nop                                                    \n"
		"jal             func_808615A4                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000136                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000135:                                              \n"
		"jal             func_8086181C                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000134:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000136:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_808615A4(void) /* 1 internal, 1 external, 20 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808615A4: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-19228                         \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t6,$zero,18                           \n"
		"lui             $a1,%hi(data_808615F4)                 \n"
		"addiu           $a1,$a1,%lo(data_808615F4)             \n"
		"sb              $t6,1992($a0)                          \n"
		"jal             func_8085F650                          \n"
		"swc1            $f4,104($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863FB8(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863FB8: \n"
	);
	asm(
		"addiu           $t8,$zero,7                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t8,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863FC4 \n"
		"nop                 \n"
	);
}
void func_8086181C(void) /* 1 internal, 1 external, 32 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8086181C: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-16820                         \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t8,$zero,17                           \n"
		"lbu             $t6,2156($a0)                          \n"
		"addiu           $t9,$zero,16                           \n"
		"lui             $a1,%hi(data_80861898)                 \n"
		"andi            $t7,$t6,0xfffb                         \n"
		"addiu           $a1,$a1,%lo(data_80861898)             \n"
		"sb              $t7,2156($a0)                          \n"
		"sb              $t8,1992($a0)                          \n"
		"sb              $t9,2169($a0)                          \n"
		"jal             func_8085F650                          \n"
		"swc1            $f4,104($a0)                           \n"
		"lw              $a2,24($sp)                            \n"
		"addiu           $t1,$zero,3                            \n"
		"lbu             $t0,2014($a2)                          \n"
		"beql            $t0,$zero,.L000149                     \n"
		"lw              $ra,20($sp)                            \n"
		"sb              $t1,2014($a2)                          \n"
		"lw              $ra,20($sp)                            \n"
		".L000149:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80861898(void) /* 1 internal, 2 external, 48 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80861898: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"lwc1            $f0,416($a0)                           \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $at,$zero,2                            \n"
		"trunc.w.s       $f6,$f0                                \n"
		"or              $a2,$a0,$zero                          \n"
		"addiu           $a1,$zero,14393                        \n"
		"swc1            $f4,104($a0)                           \n"
		"mfc1            $t7,$f6                                \n"
		"nop                                                    \n"
		"bnel            $t7,$at,.L000150                       \n"
		"lui             $at,0x3F80                             \n"
		"jal             external_func_8002F828                 \n"
		"sw              $a2,24($sp)                            \n"
		"lw              $a2,24($sp)                            \n"
		"lwc1            $f0,416($a2)                           \n"
		"lui             $at,0x3F80                             \n"
		".L000150:                                              \n"
		"mtc1            $at,$f8                                \n"
		"lui             $at,0x4100                             \n"
		"addiu           $a0,$a2,392                            \n"
		"c.lt.s          $f8,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000151                               \n"
		"sb              $zero,2056($a2)                        \n"
		"mtc1            $at,$f10                               \n"
		"addiu           $t8,$zero,1                            \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1fl           .L000151                               \n"
		"sb              $zero,2056($a2)                        \n"
		"beq             $zero,$zero,.L000151                   \n"
		"sb              $t8,2056($a2)                          \n"
		"sb              $zero,2056($a2)                        \n"
		".L000151:                                              \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $a2,24($sp)                            \n"
		"beq             $v0,$zero,.L000152                     \n"
		"lw              $a2,24($sp)                            \n"
		"jal             func_80861418                          \n"
		"or              $a0,$a2,$zero                          \n"
		".L000152:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_8086194C(void) /* 1 internal, 2 external, 43 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_8086194C: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,6520                           \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14444                        \n"
		"addiu           $t6,$zero,20                           \n"
		"addiu           $t7,$zero,5                            \n"
		"lui             $a1,%hi(data_808619EC)                 \n"
		"sb              $t6,1992($s0)                          \n"
		"sw              $t7,2024($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_808619EC)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lbu             $t8,2014($s0)                          \n"
		"addiu           $t9,$zero,3                            \n"
		"beql            $t8,$zero,.L000153                     \n"
		"lh              $t0,28($s0)                            \n"
		"sb              $t9,2014($s0)                          \n"
		"lh              $t0,28($s0)                            \n"
		".L000153:                                              \n"
		"addiu           $at,$zero,3                            \n"
		"beq             $t0,$at,.L000154                       \n"
		"lui             $at,0xC130                             \n"
		"mtc1            $at,$f4                                \n"
		"beq             $zero,$zero,.L000155                   \n"
		"swc1            $f4,104($s0)                           \n"
		".L000154:                                              \n"
		"lui             $at,0xC0E0                             \n"
		"mtc1            $at,$f6                                \n"
		"nop                                                    \n"
		"swc1            $f6,104($s0)                           \n"
		".L000155:                                              \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863FAC(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863FAC: \n"
	);
	asm(
		"addiu           $t7,$zero,6                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t7,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863FB8 \n"
		"nop                 \n"
	);
}
void func_80861B94(void) /* 1 internal, 3 external, 44 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80861B94: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-23772                         \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"addiu           $a0,$s0,228                            \n"
		"jal             external_func_800F8A44                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"lui             $at,0x4100                             \n"
		"mtc1            $at,$f6                                \n"
		"addiu           $t6,$zero,23                           \n"
		"sw              $zero,2024($s0)                        \n"
		"sb              $t6,1992($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,14444                        \n"
		"swc1            $f4,96($s0)                            \n"
		"jal             external_func_8002F828                 \n"
		"swc1            $f6,104($s0)                           \n"
		"lbu             $t8,2156($s0)                          \n"
		"lh              $t7,182($s0)                           \n"
		"lui             $a1,%hi(data_80861C40)                 \n"
		"andi            $t9,$t8,0xfffb                         \n"
		"sb              $t9,2156($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_80861C40)             \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085F650                          \n"
		"sh              $t7,50($s0)                            \n"
		"lbu             $t1,2014($s0)                          \n"
		"addiu           $t0,$zero,32                           \n"
		"sb              $t0,2169($s0)                          \n"
		"beq             $t1,$zero,.L000166                     \n"
		"addiu           $t2,$zero,3                            \n"
		"sb              $t2,2014($s0)                          \n"
		".L000166:                                              \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80861C40(void) /* 1 internal, 3 external, 74 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80861C40: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"addiu           $a0,$a0,392                            \n"
		"sw              $a1,44($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $a0,36($sp)                            \n"
		"beq             $v0,$zero,.L000167                     \n"
		"lw              $a0,36($sp)                            \n"
		"lw              $t6,2024($s0)                          \n"
		"lui             $a1,0x0601                             \n"
		"bnel            $t6,$zero,.L000168                     \n"
		"mtc1            $zero,$f4                              \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a1,$a1,-22116                         \n"
		"addiu           $v0,$zero,1                            \n"
		"sw              $v0,2024($s0)                          \n"
		"sb              $v0,2056($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14393                        \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14444                        \n"
		"beq             $zero,$zero,.L000169                   \n"
		"lw              $t7,2024($s0)                          \n"
		"mtc1            $zero,$f4                              \n"
		".L000168:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80860068                          \n"
		"swc1            $f4,104($s0)                           \n"
		".L000167:                                              \n"
		"lw              $t7,2024($s0)                          \n"
		".L000169:                                              \n"
		"lui             $at,0x40A0                             \n"
		"beql            $t7,$zero,.L000170                     \n"
		"lwc1            $f0,128($s0)                           \n"
		"lwc1            $f6,416($s0)                           \n"
		"mtc1            $at,$f8                                \n"
		"nop                                                    \n"
		"c.le.s          $f8,$f6                                \n"
		"nop                                                    \n"
		"bc1fl           .L000170                               \n"
		"lwc1            $f0,128($s0)                           \n"
		"sb              $zero,2056($s0)                        \n"
		"lwc1            $f0,128($s0)                           \n"
		".L000170:                                              \n"
		"lwc1            $f10,40($s0)                           \n"
		"c.le.s          $f10,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000171                               \n"
		"lw              $ra,28($sp)                            \n"
		"mtc1            $zero,$f2                              \n"
		"lwc1            $f16,104($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"c.eq.s          $f2,$f16                               \n"
		"nop                                                    \n"
		"bc1tl           .L000172                               \n"
		"swc1            $f0,40($s0)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14459                        \n"
		"mtc1            $zero,$f2                              \n"
		"lwc1            $f0,128($s0)                           \n"
		"swc1            $f0,40($s0)                            \n"
		".L000172:                                              \n"
		"swc1            $f2,96($s0)                            \n"
		"swc1            $f2,104($s0)                           \n"
		"lw              $ra,28($sp)                            \n"
		".L000171:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80861D50(void) /* 1 internal, 2 external, 30 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80861D50: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-23772                         \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $at,0x4160                             \n"
		"mtc1            $at,$f4                                \n"
		"lui             $at,0x40C0                             \n"
		"mtc1            $at,$f6                                \n"
		"addiu           $t6,$zero,4                            \n"
		"addiu           $a1,$zero,14444                        \n"
		"sw              $zero,2024($a0)                        \n"
		"sb              $t6,1992($a0)                          \n"
		"swc1            $f4,96($a0)                            \n"
		"jal             external_func_8002F828                 \n"
		"swc1            $f6,104($a0)                           \n"
		"lw              $a0,24($sp)                            \n"
		"lui             $a1,%hi(data_80861DC8)                 \n"
		"addiu           $a1,$a1,%lo(data_80861DC8)             \n"
		"lh              $t7,182($a0)                           \n"
		"jal             func_8085F650                          \n"
		"sh              $t7,50($a0)                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80861DC8(void) /* 1 internal, 4 external, 64 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80861DC8: \n"
	);
	asm(
		"addiu           $sp,$sp,-56                            \n"
		"sw              $s0,40($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $a1,60($sp)                            \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $t6,$zero,1                            \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a0,$a0,182                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_8007869C                 \n"
		"addiu           $a3,$zero,4000                         \n"
		"addiu           $a0,$s0,392                            \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $a0,52($sp)                            \n"
		"lwc1            $f4,128($s0)                           \n"
		"lwc1            $f6,40($s0)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.le.s          $f6,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000173                               \n"
		"lw              $ra,44($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14459                        \n"
		"lwc1            $f10,96($s0)                           \n"
		"lh              $t7,138($s0)                           \n"
		"lwc1            $f8,128($s0)                           \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mtc1            $zero,$f0                              \n"
		"addiu           $t0,$zero,12                           \n"
		"addiu           $t1,$zero,4                            \n"
		"mfc1            $v0,$f16                               \n"
		"sh              $t7,182($s0)                           \n"
		"swc1            $f8,40($s0)                            \n"
		"subu            $v0,$zero,$v0                          \n"
		"bne             $v0,$zero,.L000174                     \n"
		"sw              $v0,2020($s0)                          \n"
		"addiu           $t9,$zero,1                            \n"
		"sw              $t9,2020($s0)                          \n"
		".L000174:                                              \n"
		"swc1            $f0,96($s0)                            \n"
		"swc1            $f0,104($s0)                           \n"
		"sb              $t0,1992($s0)                          \n"
		"sw              $t1,2024($s0)                          \n"
		"lui             $a1,0x0601                             \n"
		"mfc1            $a2,$f0                                \n"
		"mfc1            $a3,$f0                                \n"
		"addiu           $t2,$zero,2                            \n"
		"sw              $t2,20($sp)                            \n"
		"addiu           $a1,$a1,-15304                         \n"
		"swc1            $f0,24($sp)                            \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_800A51A0                 \n"
		"lw              $a0,52($sp)                            \n"
		"lui             $a1,%hi(data_808603CC)                 \n"
		"addiu           $a1,$a1,%lo(data_808603CC)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,44($sp)                            \n"
		".L000173:                                              \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,56                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80861EC0(void) /* 1 internal, 3 external, 48 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80861EC0: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"sw              $s0,40($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,44($sp)                            \n"
		"lui             $a0,0x0600                             \n"
		"jal             external_func_800A2000                 \n"
		"addiu           $a0,$a0,7200                           \n"
		"mtc1            $v0,$f4                                \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f0                                \n"
		"cvt.s.w         $f6,$f4                                \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $t6,$zero,2                            \n"
		"mfc1            $a2,$f0                                \n"
		"sw              $t6,20($sp)                            \n"
		"addiu           $a1,$a1,7200                           \n"
		"swc1            $f6,16($sp)                            \n"
		"addiu           $a0,$s0,392                            \n"
		"addiu           $a3,$zero,0                            \n"
		"jal             external_func_800A51A0                 \n"
		"swc1            $f0,24($sp)                            \n"
		"mtc1            $zero,$f8                              \n"
		"addiu           $t7,$zero,21                           \n"
		"sb              $t7,1992($s0)                          \n"
		"jal             external_func_800FD9AC                 \n"
		"swc1            $f8,104($s0)                           \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f10                               \n"
		"lui             $at,0x4130                             \n"
		"mtc1            $at,$f18                               \n"
		"mul.s           $f16,$f0,$f10                          \n"
		"lh              $t0,182($s0)                           \n"
		"addiu           $t1,$zero,5                            \n"
		"lui             $a1,%hi(data_80861F80)                 \n"
		"sb              $t1,2014($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_80861F80)             \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f4,$f16,$f18                          \n"
		"sh              $t0,50($s0)                            \n"
		"trunc.w.s       $f6,$f4                                \n"
		"mfc1            $t9,$f6                                \n"
		"jal             func_8085F650                          \n"
		"sw              $t9,2024($s0)                          \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80861F80(void) /* 2 internal, 2 external, 57 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80861F80: \n"
	);
	asm(
		"mtc1            $zero,$f0                              \n"
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"mfc1            $a1,$f0                                \n"
		"addiu           $a0,$a0,104                            \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3F00                             \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"lh              $a1,138($s0)                           \n"
		"lh              $t6,182($s0)                           \n"
		"subu            $v0,$a1,$t6                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000175                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000175                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000175:                                              \n"
		"slti            $at,$v1,16001                          \n"
		"bnel            $at,$zero,.L000176                     \n"
		"lw              $v0,2024($s0)                          \n"
		"lh              $t7,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"lw              $t8,44($sp)                            \n"
		"beq             $t7,$at,.L000177                       \n"
		"lui             $t9,0x0001                             \n"
		"addu            $t9,$t9,$t8                            \n"
		"lw              $t9,7652($t9)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t0,$t9,0x1                            \n"
		"beql            $t0,$zero,.L000176                     \n"
		"lw              $v0,2024($s0)                          \n"
		"jal             func_8086194C                          \n"
		"sh              $a1,50($s0)                            \n"
		".L000177:                                              \n"
		"lw              $v0,2024($s0)                          \n"
		".L000176:                                              \n"
		"bne             $v0,$zero,.L000178                     \n"
		"addiu           $t1,$v0,-1                             \n"
		"jal             func_80862050                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000179                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000178:                                              \n"
		"sw              $t1,2024($s0)                          \n"
		"lw              $ra,36($sp)                            \n"
		".L000179:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80862050(void) /* 1 internal, 1 external, 19 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862050: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,12652                          \n"
		"sw              $a3,24($sp)                            \n"
		"addiu           $a0,$a0,392                            \n"
		"jal             external_func_800A534C                 \n"
		"lui             $a2,0xC080                             \n"
		"lw              $a0,24($sp)                            \n"
		"addiu           $t6,$zero,22                           \n"
		"lui             $a1,%hi(data_8086209C)                 \n"
		"addiu           $a1,$a1,%lo(data_8086209C)             \n"
		"jal             func_8085F650                          \n"
		"sb              $t6,1992($a0)                          \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8086209C(void) /* 3 internal, 2 external, 49 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8086209C: \n"
	);
	asm(
		"mtc1            $zero,$f0                              \n"
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"mfc1            $a1,$f0                                \n"
		"addiu           $a0,$a0,104                            \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3FC0                             \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"mtc1            $zero,$f0                              \n"
		"lwc1            $f4,432($s0)                           \n"
		"or              $a1,$s0,$zero                          \n"
		"c.eq.s          $f0,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000180                               \n"
		"lw              $ra,36($sp)                            \n"
		"swc1            $f0,104($s0)                           \n"
		"sb              $zero,2014($s0)                        \n"
		"jal             func_808641E8                          \n"
		"lw              $a0,44($sp)                            \n"
		"bne             $v0,$zero,.L000181                     \n"
		"lui             $at,0x43FA                             \n"
		"lwc1            $f6,144($s0)                           \n"
		"mtc1            $at,$f8                                \n"
		"lw              $a1,44($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f6,$f8                                \n"
		"nop                                                    \n"
		"bc1f            .L000182                               \n"
		"nop                                                    \n"
		"jal             func_8085FAB0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000180                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000182:                                              \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,44($sp)                            \n"
		".L000181:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000180:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80862154(void) /* 1 internal, 3 external, 32 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862154: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-31228                         \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14394                        \n"
		"lui             $at,0xC000                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t6,$zero,8                            \n"
		"sb              $t6,1992($s0)                          \n"
		"addiu           $t7,$zero,8                            \n"
		"swc1            $f4,104($s0)                           \n"
		"sw              $t7,16($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,16384                        \n"
		"addiu           $a2,$zero,255                          \n"
		"jal             external_func_8003426C                 \n"
		"or              $a3,$zero,$zero                        \n"
		"lui             $a1,%hi(data_808621D4)                 \n"
		"addiu           $a1,$a1,%lo(data_808621D4)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863FA0(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863FA0: \n"
	);
	asm(
		"addiu           $t6,$zero,5                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t6,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863FAC \n"
		"nop                 \n"
	);
}
void func_80862398(void) /* 1 internal, 3 external, 32 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862398: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,1092                           \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14394                        \n"
		"lui             $at,0xC000                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $t6,$zero,9                            \n"
		"sb              $t6,1992($s0)                          \n"
		"addiu           $t7,$zero,8                            \n"
		"swc1            $f4,104($s0)                           \n"
		"sw              $t7,16($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,16384                        \n"
		"addiu           $a2,$zero,255                          \n"
		"jal             external_func_8003426C                 \n"
		"or              $a3,$zero,$zero                        \n"
		"lui             $a1,%hi(data_80862418)                 \n"
		"addiu           $a1,$a1,%lo(data_80862418)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863F94(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863F94: \n"
	);
	asm(
		"addiu           $t5,$zero,4                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t5,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863FA0 \n"
		"nop                 \n"
	);
}
void func_80862578(void) /* 1 internal, 3 external, 58 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862578: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $ra,36($sp)                            \n"
		"lui             $at,0xC080                             \n"
		"mtc1            $at,$f6                                \n"
		"lbu             $t7,2018($a0)                          \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t6,$zero,11                           \n"
		"addiu           $at,$zero,14                           \n"
		"or              $s0,$a0,$zero                          \n"
		"sb              $t6,1992($a0)                          \n"
		"sb              $zero,2014($a0)                        \n"
		"sb              $zero,2056($a0)                        \n"
		"swc1            $f6,104($a0)                           \n"
		"bne             $t7,$at,.L000199                       \n"
		"swc1            $f4,420($a0)                           \n"
		"addiu           $t8,$zero,80                           \n"
		"sw              $t8,16($sp)                            \n"
		"addiu           $a1,$zero,-32768                       \n"
		"addiu           $a2,$zero,120                          \n"
		"jal             external_func_8003426C                 \n"
		"or              $a3,$zero,$zero                        \n"
		"beq             $zero,$zero,.L000200                   \n"
		"or              $a0,$s0,$zero                          \n"
		".L000199:                                              \n"
		"addiu           $t9,$zero,80                           \n"
		"sw              $t9,16($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a1,$zero,$zero                        \n"
		"addiu           $a2,$zero,120                          \n"
		"jal             external_func_8003426C                 \n"
		"or              $a3,$zero,$zero                        \n"
		"lbu             $t0,2018($s0)                          \n"
		"addiu           $at,$zero,15                           \n"
		"addiu           $a0,$s0,392                            \n"
		"bne             $t0,$at,.L000201                       \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $t1,$zero,36                           \n"
		"beq             $zero,$zero,.L000202                   \n"
		"sh              $t1,2016($s0)                          \n"
		".L000201:                                              \n"
		"addiu           $a1,$a1,-31228                         \n"
		"jal             external_func_800A529C                 \n"
		"addiu           $a2,$zero,0                            \n"
		".L000202:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		".L000200:                                              \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14494                        \n"
		"lui             $a1,%hi(data_80862650)                 \n"
		"addiu           $a1,$a1,%lo(data_80862650)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,36($sp)                            \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863F88(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863F88: \n"
	);
	asm(
		"addiu           $t4,$zero,3                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t4,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863F94 \n"
		"nop                 \n"
	);
}
void func_808627C4(void) /* 2 internal, 4 external, 69 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808627C4: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"jal             external_func_80033AB8                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000211                     \n"
		"addiu           $a0,$s0,392                            \n"
		"jal             func_80860EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000212                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000211:                                              \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-7504                          \n"
		"jal             external_func_800A534C                 \n"
		"lui             $a2,0xC000                             \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $t6,$zero,1                            \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a0,$s0,182                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_8007869C                 \n"
		"addiu           $a3,$zero,4000                         \n"
		"lw              $t7,44($sp)                            \n"
		"lui             $t8,0x0001                             \n"
		"lui             $at,0x4080                             \n"
		"addu            $t8,$t8,$t7                            \n"
		"lw              $t8,7652($t8)                          \n"
		"andi            $t9,$t8,0x1                            \n"
		"beql            $t9,$zero,.L000213                     \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0xC080                             \n"
		"mtc1            $at,$f4                                \n"
		"beq             $zero,$zero,.L000214                   \n"
		"swc1            $f4,104($s0)                           \n"
		"mtc1            $at,$f6                                \n"
		".L000213:                                              \n"
		"nop                                                    \n"
		"swc1            $f6,104($s0)                           \n"
		".L000214:                                              \n"
		"lh              $t0,182($s0)                           \n"
		"addiu           $t1,$t0,16383                          \n"
		"jal             external_func_800FD9AC                 \n"
		"sh              $t1,50($s0)                            \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f2                                \n"
		"addiu           $t4,$zero,24                           \n"
		"lui             $a1,%hi(data_808628C8)                 \n"
		"mul.s           $f8,$f0,$f2                            \n"
		"sb              $t4,1992($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_808628C8)             \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f10,$f8,$f2                           \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t3,$f16                               \n"
		"jal             func_8085F650                          \n"
		"sw              $t3,2024($s0)                          \n"
		"mtc1            $zero,$f18                             \n"
		"nop                                                    \n"
		"swc1            $f18,2028($s0)                         \n"
		"lw              $ra,36($sp)                            \n"
		".L000212:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863F7C(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863F7C: \n"
	);
	asm(
		"addiu           $t3,$zero,2                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t3,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863F88 \n"
		"nop                 \n"
	);
}
void func_80862DBC(void) /* 1 internal, 5 external, 46 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862DBC: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14394                        \n"
		"addiu           $t6,$zero,2                            \n"
		"sb              $t6,1992($s0)                          \n"
		"lw              $a2,36($sp)                            \n"
		"addiu           $a0,$s0,2032                           \n"
		"jal             external_func_80032E24                 \n"
		"addiu           $a1,$zero,60                           \n"
		"lb              $t7,2056($s0)                          \n"
		"sh              $zero,20($s0)                          \n"
		"bltzl           $t7,.L000247                           \n"
		"lw              $t9,4($s0)                             \n"
		"jal             external_func_80026B0C                 \n"
		"lw              $a0,2060($s0)                          \n"
		"jal             external_func_80020120                 \n"
		"or              $a0,$v0,$zero                          \n"
		"addiu           $t8,$zero,-1                           \n"
		"sb              $t8,2056($s0)                          \n"
		"lw              $t9,4($s0)                             \n"
		".L000247:                                              \n"
		"lh              $t1,28($s0)                            \n"
		"addiu           $at,$zero,-2                           \n"
		"and             $t0,$t9,$at                            \n"
		"addiu           $at,$zero,5                            \n"
		"bne             $t1,$at,.L000248                       \n"
		"sw              $t0,4($s0)                             \n"
		"lw              $a0,36($sp)                            \n"
		"or              $a2,$s0,$zero                          \n"
		"addiu           $a3,$zero,6                            \n"
		"jal             external_func_80033748                 \n"
		"addiu           $a1,$a0,7204                           \n"
		".L000248:                                              \n"
		"lui             $a1,%hi(data_80862E6C)                 \n"
		"addiu           $a1,$a1,%lo(data_80862E6C)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80862E6C(void) /* 1 internal, 5 external, 87 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80862E6C: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lw              $t6,284($a0)                           \n"
		"or              $s0,$a0,$zero                          \n"
		"addiu           $a1,$s0,2032                           \n"
		"bnel            $t6,$zero,.L000249                     \n"
		"lh              $t9,20($s0)                            \n"
		"lh              $t7,20($a0)                            \n"
		"bnel            $t7,$zero,.L000250                     \n"
		"lh              $a3,28($s0)                            \n"
		"lh              $t8,2040($a0)                          \n"
		"sh              $t8,20($a0)                            \n"
		"lh              $a3,28($s0)                            \n"
		".L000250:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a2,44($sp)                            \n"
		"addiu           $a3,$a3,8                              \n"
		"sll             $a3,$a3,16                             \n"
		"jal             external_func_8003305C                 \n"
		"sra             $a3,$a3,16                             \n"
		"beql            $v0,$zero,.L000251                     \n"
		"lw              $ra,36($sp)                            \n"
		"beq             $zero,$zero,.L000252                   \n"
		"sw              $s0,284($s0)                           \n"
		"lh              $t9,20($s0)                            \n"
		".L000249:                                              \n"
		"bnel            $t9,$zero,.L000253                     \n"
		"lh              $t6,28($s0)                            \n"
		"lh              $t1,28($s0)                            \n"
		"addiu           $t0,$zero,10                           \n"
		"addiu           $at,$zero,4                            \n"
		"bne             $t1,$at,.L000254                       \n"
		"sb              $t0,175($s0)                           \n"
		"addiu           $t2,$zero,-1                           \n"
		"beq             $zero,$zero,.L000255                   \n"
		"sh              $t2,28($s0)                            \n"
		".L000254:                                              \n"
		"lw              $a0,44($sp)                            \n"
		"or              $a2,$s0,$zero                          \n"
		"addiu           $a3,$zero,5                            \n"
		"jal             external_func_80033748                 \n"
		"addiu           $a1,$a0,7204                           \n"
		".L000255:                                              \n"
		"lw              $t4,4($s0)                             \n"
		"sw              $zero,284($s0)                         \n"
		"or              $a0,$s0,$zero                          \n"
		"ori             $t5,$t4,0x1                            \n"
		"jal             func_8086194C                          \n"
		"sw              $t5,4($s0)                             \n"
		"beq             $zero,$zero,.L000251                   \n"
		"lw              $ra,36($sp)                            \n"
		"lh              $t6,28($s0)                            \n"
		".L000253:                                              \n"
		"addiu           $at,$zero,5                            \n"
		"lw              $a0,44($sp)                            \n"
		"bne             $t6,$at,.L000252                       \n"
		"or              $a1,$s0,$zero                          \n"
		"lui             $at,0x45FA                             \n"
		"mtc1            $at,$f4                                \n"
		"addiu           $a2,$zero,2                            \n"
		"addiu           $a3,$zero,5                            \n"
		"jal             external_func_800353F4                 \n"
		"swc1            $f4,16($sp)                            \n"
		"bne             $v0,$zero,.L000252                     \n"
		"lw              $a0,44($sp)                            \n"
		"or              $a1,$s0,$zero                          \n"
		"addiu           $a2,$s0,36                             \n"
		"jal             external_func_8001F940                 \n"
		"addiu           $a3,$zero,208                          \n"
		"lw              $v0,280($s0)                           \n"
		"beq             $v0,$zero,.L000256                     \n"
		"nop                                                    \n"
		"lh              $t7,24($v0)                            \n"
		"addiu           $t8,$t7,-1                             \n"
		"sh              $t8,24($v0)                            \n"
		".L000256:                                              \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		".L000252:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000251:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80862FA8(void) /* 2 internal, 2 external, 41 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80862FA8: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $a1,28($sp)                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,5152                           \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14395                        \n"
		"lw              $a2,24($sp)                            \n"
		"addiu           $at,$zero,-2                           \n"
		"mtc1            $zero,$f4                              \n"
		"lw              $t6,4($a2)                             \n"
		"lh              $t8,28($a2)                            \n"
		"sb              $zero,2014($a2)                        \n"
		"and             $t7,$t6,$at                            \n"
		"slti            $at,$t8,4                              \n"
		"sw              $t7,4($a2)                             \n"
		"sb              $zero,276($a2)                         \n"
		"beq             $at,$zero,.L000257                     \n"
		"swc1            $f4,104($a2)                           \n"
		"addiu           $t9,$zero,5                            \n"
		"lui             $a1,%hi(data_80863044)                 \n"
		"sb              $t9,1992($a2)                          \n"
		"addiu           $a1,$a1,%lo(data_80863044)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000258                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000257:                                              \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             func_80862DBC                          \n"
		"lw              $a1,28($sp)                            \n"
		"lw              $ra,20($sp)                            \n"
		".L000258:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863044(void) /* 1 internal, 4 external, 45 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863044: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"beql            $v0,$zero,.L000259                     \n"
		"lwc1            $f10,416($s0)                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f2                                \n"
		"addiu           $t8,$zero,7                            \n"
		"lui             $a1,%hi(data_808633E8)                 \n"
		"mul.s           $f4,$f0,$f2                            \n"
		"sb              $t8,1992($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_808633E8)             \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f6,$f4,$f2                            \n"
		"trunc.w.s       $f8,$f6                                \n"
		"mfc1            $t7,$f8                                \n"
		"jal             func_8085F650                          \n"
		"sw              $t7,2024($s0)                          \n"
		"addiu           $a0,$s0,2032                           \n"
		"addiu           $a1,$zero,60                           \n"
		"jal             external_func_80032E24                 \n"
		"lw              $a2,36($sp)                            \n"
		"lwc1            $f10,416($s0)                          \n"
		".L000259:                                              \n"
		"addiu           $at,$zero,15                           \n"
		"or              $a0,$s0,$zero                          \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t0,$f16                               \n"
		"nop                                                    \n"
		"bnel            $t0,$at,.L000260                       \n"
		"lw              $ra,28($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14458                        \n"
		"lw              $ra,28($sp)                            \n"
		".L000260:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_808630F0(void) /* 2 internal, 2 external, 41 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808630F0: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $a1,28($sp)                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-25968                         \n"
		"sw              $a2,24($sp)                            \n"
		"jal             external_func_800A51E8                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a0,24($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14395                        \n"
		"lw              $a2,24($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t6,$zero,6                            \n"
		"lh              $t7,28($a2)                            \n"
		"sb              $t6,1992($a2)                          \n"
		"sb              $zero,276($a2)                         \n"
		"slti            $at,$t7,4                              \n"
		"sb              $zero,2014($a2)                        \n"
		"beq             $at,$zero,.L000261                     \n"
		"swc1            $f4,104($a2)                           \n"
		"lw              $t8,4($a2)                             \n"
		"addiu           $at,$zero,-2                           \n"
		"lui             $a1,%hi(data_8086318C)                 \n"
		"and             $t9,$t8,$at                            \n"
		"sw              $t9,4($a2)                             \n"
		"addiu           $a1,$a1,%lo(data_8086318C)             \n"
		"jal             func_8085F650                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000262                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000261:                                              \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             func_80862DBC                          \n"
		"lw              $a1,28($sp)                            \n"
		"lw              $ra,20($sp)                            \n"
		".L000262:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8086318C(void) /* 1 internal, 4 external, 48 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8086318C: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"beql            $v0,$zero,.L000263                     \n"
		"lwc1            $f10,416($s0)                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f2                                \n"
		"addiu           $t8,$zero,7                            \n"
		"lui             $a1,%hi(data_808633E8)                 \n"
		"mul.s           $f4,$f0,$f2                            \n"
		"sb              $t8,1992($s0)                          \n"
		"addiu           $a1,$a1,%lo(data_808633E8)             \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f6,$f4,$f2                            \n"
		"trunc.w.s       $f8,$f6                                \n"
		"mfc1            $t7,$f8                                \n"
		"jal             func_8085F650                          \n"
		"sw              $t7,2024($s0)                          \n"
		"addiu           $a0,$s0,2032                           \n"
		"addiu           $a1,$zero,60                           \n"
		"jal             external_func_80032E24                 \n"
		"lw              $a2,36($sp)                            \n"
		"lwc1            $f10,416($s0)                          \n"
		".L000263:                                              \n"
		"addiu           $at,$zero,10                           \n"
		"or              $a0,$s0,$zero                          \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $v0,$f16                               \n"
		"nop                                                    \n"
		"beq             $v0,$at,.L000264                       \n"
		"addiu           $at,$zero,25                           \n"
		"bnel            $v0,$at,.L000265                       \n"
		"lw              $ra,28($sp)                            \n"
		".L000264:                                              \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14458                        \n"
		"lw              $ra,28($sp)                            \n"
		".L000265:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80863240(void) /* 1 internal, 0 external, 21 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80863240: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"lui             $at,0xBF80                             \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f6,416($a0)                           \n"
		"mtc1            $zero,$f8                              \n"
		"addiu           $t6,$zero,2                            \n"
		"addiu           $t7,$zero,19                           \n"
		"lui             $a1,%hi(data_80863294)                 \n"
		"sb              $zero,2056($a0)                        \n"
		"sb              $t6,445($a0)                           \n"
		"sb              $t7,1992($a0)                          \n"
		"addiu           $a1,$a1,%lo(data_80863294)             \n"
		"swc1            $f4,420($a0)                           \n"
		"swc1            $f6,404($a0)                           \n"
		"jal             func_8085F650                          \n"
		"swc1            $f8,408($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863F70(void) /* 0 internal, 0 external, 3 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863F70: \n"
	);
	asm(
		"addiu           $t2,$zero,1                            \n"
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $t2,124($sp)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863F7C \n"
		"nop                 \n"
	);
}
void data_80863360(void) /* 1 internal, 1 external, 36 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863360: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $a1,28($sp)                            \n"
		"or              $a1,$a0,$zero                          \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"sw              $a1,24($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"lw              $a1,24($sp)                            \n"
		"lui             $at,%hi(data_808647DC)                 \n"
		"lwc1            $f4,%lo(data_808647DC)($at)            \n"
		"lwc1            $f0,84($a1)                            \n"
		"lui             $at,%hi(data_808647E0)                 \n"
		"c.lt.s          $f0,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000270                               \n"
		"lwc1            $f4,12($a1)                            \n"
		"lwc1            $f6,%lo(data_808647E0)($at)            \n"
		"lui             $at,0x4060                             \n"
		"mtc1            $at,$f16                               \n"
		"lwc1            $f10,12($a1)                           \n"
		"add.s           $f8,$f0,$f6                            \n"
		"sub.s           $f18,$f10,$f16                         \n"
		"swc1            $f8,84($a1)                            \n"
		"beq             $zero,$zero,.L000271                   \n"
		"swc1            $f18,40($a1)                           \n"
		"lwc1            $f4,12($a1)                            \n"
		".L000270:                                              \n"
		"or              $a0,$a1,$zero                          \n"
		"jal             func_8086194C                          \n"
		"swc1            $f4,40($a1)                            \n"
		".L000271:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808633E8(void) /* 0 internal, 3 external, 32 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808633E8: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"sw              $ra,28($sp)                            \n"
		"addiu           $t6,$zero,1                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sh              $t6,28($a0)                            \n"
		"lh              $a3,28($s0)                            \n"
		"lw              $a2,36($sp)                            \n"
		"jal             external_func_8003305C                 \n"
		"addiu           $a1,$s0,2032                           \n"
		"beq             $v0,$zero,.L000272                     \n"
		"lw              $a0,36($sp)                            \n"
		"or              $a1,$s0,$zero                          \n"
		"addiu           $a2,$s0,36                             \n"
		"jal             external_func_8001F940                 \n"
		"addiu           $a3,$zero,208                          \n"
		"lw              $v0,280($s0)                           \n"
		"beq             $v0,$zero,.L000273                     \n"
		"nop                                                    \n"
		"lh              $t7,24($v0)                            \n"
		"addiu           $t8,$t7,-1                             \n"
		"sh              $t8,24($v0)                            \n"
		".L000273:                                              \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		".L000272:                                              \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_80863460(void) /* 0 internal, 0 external, 43 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80863460: \n"
	);
	asm(
		"sw              $a1,4($sp)                             \n"
		"lh              $t7,182($a0)                           \n"
		"lh              $t6,2002($a0)                          \n"
		"lh              $v0,138($a0)                           \n"
		"addiu           $t1,$zero,-2000                        \n"
		"addu            $t0,$t6,$t7                            \n"
		"subu            $v0,$v0,$t0                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"slti            $at,$v0,-2000                          \n"
		"beq             $at,$zero,.L000274                     \n"
		"addiu           $t5,$zero,-14383                       \n"
		"beq             $zero,$zero,.L000275                   \n"
		"sh              $t1,2008($a0)                          \n"
		".L000274:                                              \n"
		"slti            $at,$v0,2001                           \n"
		"bne             $at,$zero,.L000276                     \n"
		"or              $v1,$v0,$zero                          \n"
		"beq             $zero,$zero,.L000276                   \n"
		"addiu           $v1,$zero,2000                         \n"
		".L000276:                                              \n"
		"sh              $v1,2008($a0)                          \n"
		".L000275:                                              \n"
		"lh              $t2,2002($a0)                          \n"
		"lh              $t3,2008($a0)                          \n"
		"addu            $t4,$t2,$t3                            \n"
		"sh              $t4,2002($a0)                          \n"
		"lh              $v0,2002($a0)                          \n"
		"slti            $at,$v0,-14383                         \n"
		"beql            $at,$zero,.L000277                     \n"
		"slti            $at,$v0,14384                          \n"
		"jr              $ra                                    \n"
		"sh              $t5,2002($a0)                          \n"
		"slti            $at,$v0,14384                          \n"
		".L000277:                                              \n"
		"bne             $at,$zero,.L000278                     \n"
		"or              $v1,$v0,$zero                          \n"
		"beq             $zero,$zero,.L000278                   \n"
		"addiu           $v1,$zero,14383                        \n"
		".L000278:                                              \n"
		"sh              $v1,2002($a0)                          \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863F68(void) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863F68: \n"
	);
	asm(
		"beq             $zero,$zero,.Ldata_80863FCC            \n"
		"sw              $zero,124($sp)                         \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863F70 \n"
		"nop                 \n"
	);
}
void play(entity_t *en, z64_global_t *gl) /* 1 internal, 5 external, 85 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lplay: \n"
	);
	asm(
		"addiu           $sp,$sp,-80                            \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s0,40($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"jal             func_808634F8                          \n"
		"sw              $a1,84($sp)                            \n"
		"lbu             $t6,177($s0)                           \n"
		"addiu           $at,$zero,6                            \n"
		"beql            $t6,$at,.L000288                       \n"
		"addiu           $a1,$s0,2064                           \n"
		"jal             external_func_8002D8E0                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $at,0x41F0                             \n"
		"mtc1            $at,$f0                                \n"
		"addiu           $t7,$zero,29                           \n"
		"sw              $t7,20($sp)                            \n"
		"mfc1            $a3,$f0                                \n"
		"lw              $a0,84($sp)                            \n"
		"or              $a1,$s0,$zero                          \n"
		"lui             $a2,0x4296                             \n"
		"jal             external_func_8002E4B4                 \n"
		"swc1            $f0,16($sp)                            \n"
		"lh              $t8,28($s0)                            \n"
		"addiu           $at,$zero,1                            \n"
		"bnel            $t8,$at,.L000289                       \n"
		"lhu             $t1,136($s0)                           \n"
		"lwc1            $f0,12($s0)                            \n"
		"lwc1            $f4,40($s0)                            \n"
		"c.le.s          $f4,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000290                               \n"
		"lwc1            $f8,128($s0)                           \n"
		"mtc1            $zero,$f6                              \n"
		"swc1            $f0,40($s0)                            \n"
		"swc1            $f6,96($s0)                            \n"
		"lwc1            $f8,128($s0)                           \n"
		".L000290:                                              \n"
		"c.le.s          $f8,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000291                               \n"
		"lw              $t9,1996($s0)                          \n"
		"swc1            $f0,128($s0)                           \n"
		".L000292:                                              \n"
		"lw              $t9,1996($s0)                          \n"
		".L000291:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a1,84($sp)                            \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"lbu             $v0,2014($s0)                          \n"
		"sltiu           $at,$v0,5                              \n"
		"beq             $at,$zero,.Ldata_808638F4              \n"
		"sll             $t0,$v0,2                              \n"
		"lui             $at,%hi(data_808647E4)                 \n"
		"addu            $at,$at,$t0                            \n"
		"lw              $t0,%lo(data_808647E4)($at)            \n"
		"jr              $t0                                    \n"
		"nop                                                    \n"
		"lhu             $t1,136($s0)                           \n"
		".L000289:                                              \n"
		"lw              $a0,84($sp)                            \n"
		"andi            $t2,$t1,0x2                            \n"
		"beq             $t2,$zero,.L000292                     \n"
		"addiu           $a0,$a0,1984                           \n"
		"lw              $a1,120($s0)                           \n"
		"lbu             $a2,125($s0)                           \n"
		"jal             external_func_80041EA4                 \n"
		"sw              $a0,56($sp)                            \n"
		"addiu           $at,$zero,5                            \n"
		"beq             $v0,$at,.L000293                       \n"
		"lw              $a0,56($sp)                            \n"
		"addiu           $at,$zero,12                           \n"
		"beq             $v0,$at,.L000293                       \n"
		"nop                                                    \n"
		"lw              $a1,120($s0)                           \n"
		"jal             external_func_80041D4C                 \n"
		"lbu             $a2,125($s0)                           \n"
		"addiu           $at,$zero,9                            \n"
		"bnel            $v0,$at,.L000291                       \n"
		"lw              $t9,1996($s0)                          \n"
		".L000293:                                              \n"
		"jal             external_func_8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000294                   \n"
		"lw              $ra,44($sp)                            \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_808637D4 \n"
		"nop                 \n"
	);
}
void data_808637D4(void) /* 0 internal, 3 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808637D4: \n"
	);
	asm(
		"lui             $a0,0x0600                             \n"
		"jal             external_func_800A2000                 \n"
		"addiu           $a0,$a0,7200                           \n"
		"mtc1            $v0,$f10                               \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f0                                \n"
		"cvt.s.w         $f16,$f10                              \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $t3,$zero,2                            \n"
		"mfc1            $a2,$f0                                \n"
		"sw              $t3,20($sp)                            \n"
		"addiu           $a1,$a1,7200                           \n"
		"swc1            $f16,16($sp)                           \n"
		"addiu           $a0,$s0,1192                           \n"
		"addiu           $a3,$zero,0                            \n"
		"jal             external_func_800A51A0                 \n"
		"swc1            $f0,24($sp)                            \n"
		"lui             $t4,%hi(data_80864510)                 \n"
		"addiu           $t4,$t4,%lo(data_80864510)             \n"
		"lbu             $a1,392($s0)                           \n"
		"lw              $a2,424($s0)                           \n"
		"lw              $a3,1224($s0)                          \n"
		"sw              $t4,16($sp)                            \n"
		"jal             external_func_800A3548                 \n"
		"lw              $a0,84($sp)                            \n"
		"lbu             $t5,2014($s0)                          \n"
		"addiu           $t6,$t5,1                              \n"
		"beq             $zero,$zero,.Ldata_808638F4            \n"
		"sb              $t6,2014($s0)                          \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863848 \n"
		"nop                 \n"
	);
}
void data_80863848(void) /* 0 internal, 2 external, 10 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863848: \n"
	);
	asm(
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,1192                           \n"
		"lui             $a3,%hi(data_80864510)                 \n"
		"addiu           $a3,$a3,%lo(data_80864510)             \n"
		"addiu           $a0,$s0,392                            \n"
		"lw              $a1,424($s0)                           \n"
		"jal             external_func_800A5428                 \n"
		"lw              $a2,1224($s0)                          \n"
		"beq             $zero,$zero,.L000295                   \n"
		"lbu             $t8,276($s0)                           \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863870 \n"
		"nop                 \n"
	);
}
void data_80863870(void) /* 0 internal, 0 external, 5 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863870: \n"
	);
	asm(
		"lui             $at,0x4080                             \n"
		"mtc1            $at,$f18                               \n"
		"addiu           $t7,$v0,1                              \n"
		"sb              $t7,2014($s0)                          \n"
		"swc1            $f18,1232($s0)                         \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_80863884 \n"
		"nop                 \n"
	);
}
void data_80863884(void) /* 0 internal, 2 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863884: \n"
	);
	asm(
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f12                               \n"
		"lwc1            $f0,1232($s0)                          \n"
		"mtc1            $zero,$f6                              \n"
		"sub.s           $f4,$f0,$f12                           \n"
		"mov.s           $f2,$f0                                \n"
		"swc1            $f4,1232($s0)                          \n"
		"lwc1            $f0,1232($s0)                          \n"
		"c.le.s          $f0,$f6                                \n"
		"nop                                                    \n"
		"bc1fl           .L000296                               \n"
		"div.s           $f8,$f0,$f2                            \n"
		"sb              $zero,2014($s0)                        \n"
		"lwc1            $f0,1232($s0)                          \n"
		"div.s           $f8,$f0,$f2                            \n"
		".L000296:                                              \n"
		"lw              $a1,1224($s0)                          \n"
		"lbu             $a0,392($s0)                           \n"
		"lw              $a3,424($s0)                           \n"
		"or              $a2,$a1,$zero                          \n"
		"sub.s           $f10,$f12,$f8                          \n"
		"jal             external_func_800A2E70                 \n"
		"swc1            $f10,16($sp)                           \n"
		"lui             $a3,%hi(data_80864510)                 \n"
		"addiu           $a3,$a3,%lo(data_80864510)             \n"
		"addiu           $a0,$s0,392                            \n"
		"lw              $a1,424($s0)                           \n"
		"jal             external_func_800A5428                 \n"
		"lw              $a2,1224($s0)                          \n"
	);
	/* fall through to next function */
	asm(
		"beq $zero,$zero,.Ldata_808638F4 \n"
		"nop                 \n"
	);
}
void data_808638F4(void) /* 2 internal, 5 external, 127 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808638F4: \n"
	);
	asm(
		"lbu             $t8,276($s0)                           \n"
		".L000295:                                              \n"
		"bnel            $t8,$zero,.L000288                     \n"
		"addiu           $a1,$s0,2064                           \n"
		"lbu             $t9,175($s0)                           \n"
		"beql            $t9,$zero,.L000288                     \n"
		"addiu           $a1,$s0,2064                           \n"
		"lbu             $v0,1992($s0)                          \n"
		"addiu           $at,$zero,16                           \n"
		"addiu           $a0,$s0,2002                           \n"
		"beq             $v0,$at,.L000297                       \n"
		"or              $a1,$zero,$zero                        \n"
		"addiu           $at,$zero,23                           \n"
		"beql            $v0,$at,.L000298                       \n"
		"addiu           $a2,$zero,1                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80863460                          \n"
		"lw              $a1,84($sp)                            \n"
		"beq             $zero,$zero,.L000288                   \n"
		"addiu           $a1,$s0,2064                           \n"
		".L000297:                                              \n"
		"addiu           $a2,$zero,1                            \n"
		".L000298:                                              \n"
		"addiu           $a3,$zero,1000                         \n"
		"jal             external_func_8007869C                 \n"
		"sw              $zero,16($sp)                          \n"
		"addiu           $a1,$s0,2064                           \n"
		".L000288:                                              \n"
		"sw              $a1,52($sp)                            \n"
		"jal             external_func_800626DC                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t0,40($s0)                            \n"
		"lui             $at,0x4234                             \n"
		"lw              $t1,36($s0)                            \n"
		"sw              $t0,60($s0)                            \n"
		"lwc1            $f16,60($s0)                           \n"
		"mtc1            $at,$f18                               \n"
		"sw              $t1,56($s0)                            \n"
		"lw              $t1,44($s0)                            \n"
		"add.s           $f4,$f16,$f18                          \n"
		"lbu             $t2,175($s0)                           \n"
		"sw              $t1,64($s0)                            \n"
		"lui             $at,0x0001                             \n"
		"swc1            $f4,60($s0)                            \n"
		"bgtz            $t2,.L000299                           \n"
		"lw              $a0,84($sp)                            \n"
		"lbu             $t3,276($s0)                           \n"
		"beq             $t3,$zero,.L000300                     \n"
		".L000299:                                              \n"
		"ori             $at,$at,0x1e60                         \n"
		"addu            $a1,$a0,$at                            \n"
		"sw              $a1,56($sp)                            \n"
		"jal             external_func_8005DC4C                 \n"
		"lw              $a2,52($sp)                            \n"
		"lbu             $t4,1992($s0)                          \n"
		"slti            $at,$t4,10                             \n"
		"bnel            $at,$zero,.L000301                     \n"
		"lbu             $t8,2014($s0)                          \n"
		"lbu             $t5,276($s0)                           \n"
		"lw              $a0,84($sp)                            \n"
		"lw              $a1,56($sp)                            \n"
		"beq             $t5,$zero,.L000302                     \n"
		"nop                                                    \n"
		"lhu             $t6,274($s0)                           \n"
		"andi            $t7,$t6,0x4000                         \n"
		"bnel            $t7,$zero,.L000301                     \n"
		"lbu             $t8,2014($s0)                          \n"
		".L000302:                                              \n"
		"jal             external_func_8005D9F4                 \n"
		"lw              $a2,52($sp)                            \n"
		"lbu             $t8,2014($s0)                          \n"
		".L000301:                                              \n"
		"lw              $a0,84($sp)                            \n"
		"lw              $a1,56($sp)                            \n"
		"beql            $t8,$zero,.L000303                     \n"
		"lb              $t9,2056($s0)                          \n"
		"jal             external_func_8005D9F4                 \n"
		"addiu           $a2,$s0,2268                           \n"
		".L000300:                                              \n"
		"lb              $t9,2056($s0)                          \n"
		".L000303:                                              \n"
		"blezl           $t9,.L000304                           \n"
		"lh              $t3,28($s0)                            \n"
		"lbu             $v0,2156($s0)                          \n"
		"lui             $at,0x0001                             \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t0,$v0,0x4                            \n"
		"bne             $t0,$zero,.L000305                     \n"
		"andi            $t2,$v0,0xfffb                         \n"
		"lw              $a0,84($sp)                            \n"
		"ori             $at,$at,0x1e60                         \n"
		"addiu           $a2,$s0,2140                           \n"
		"jal             external_func_8005D79C                 \n"
		"addu            $a1,$a0,$at                            \n"
		"beq             $zero,$zero,.L000304                   \n"
		"lh              $t3,28($s0)                            \n"
		".L000305:                                              \n"
		"jal             func_80863240                          \n"
		"sb              $t2,2156($s0)                          \n"
		"lh              $t3,28($s0)                            \n"
		".L000304:                                              \n"
		"lw              $t4,84($sp)                            \n"
		"bnel            $t3,$zero,.L000294                     \n"
		"lw              $ra,44($sp)                            \n"
		"lbu             $t5,7207($t4)                          \n"
		"lui             $t8,0x8003                             \n"
		"beql            $t5,$zero,.L000306                     \n"
		"lw              $t9,4($s0)                             \n"
		"lw              $t6,4($s0)                             \n"
		"addiu           $t8,$t8,-18236                         \n"
		"sw              $t8,192($s0)                           \n"
		"ori             $t7,$t6,0x81                           \n"
		"beq             $zero,$zero,.L000307                   \n"
		"sw              $t7,4($s0)                             \n"
		"lw              $t9,4($s0)                             \n"
		".L000306:                                              \n"
		"addiu           $at,$zero,-130                         \n"
		"sw              $zero,192($s0)                         \n"
		"and             $t0,$t9,$at                            \n"
		"sw              $t0,4($s0)                             \n"
		".L000307:                                              \n"
		"lw              $ra,44($sp)                            \n"
		".L000294:                                              \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,80                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

int32_t skl_callback_80863AB8(z64_global_t *gl, uint8_t limb, uint32_t *dlist, vec3f_t *translation, vec3s_t *rotation, entity_t *en) /* 0 internal, 3 external, 136 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lskl_callback_80863AB8: \n"
	);

  if (limb == 0x06)
  {
    rotation->x += *(en + 0x07D2);
    rotation->y -= *(en + 0x07D0);
    rotation->z += *(en + 0x07D4);
  }
  else
  {
    if (limb == 0x0B)
    {
      #define GFX_POLY_OPA ZQDL(gl, poly_opa)
    	z64_disp_buf_t *opa = &GFX_POLY_OPA;
    	z64_gfx_t *gfx_ctxt;
      float colorf;
      int32_t colori;
      uint8_t[4] rgba;
      /*external_func_800C6AC4(unk0, gfx_ctxt, "../z_en_test.c_80864700", __LINE__);*/
      gDPPipeSync(opa->p++); /* 0xE700000000000000 */
      colorf = math_sins(gl->gameplay_frames * 0x07D0); /* external_func_80077870 */
      if ((colorf * 175.0f) < 0)
      {
        colorf = math_sins(gl->gameplay_frames * 0x07D0) /* external_func_80077870 */
        colori = -(colorf * 175.0f);
      }
      else
      {
        colorf = math_sins(gl->gameplay_frames * 0x07D0) /* external_func_80077870 */
        colori = colorf * 175.0f;
      }
      colori = (colori + 0x50) * 0x01000000 | 0xFF;
      rgba[0] = (colori >> 24) & 0xFF;
      rgba[1] = (colori >> 16) & 0xFF;
      rgba[2] = (colori >> 8) & 0xFF;
      rgba[3] = (colori) & 0xFF;
      gDPSetEnvColor(opa->p++, rgba[0], rgba[1], rgba[2], rgba[3]);
      /*external_func_800C6AC4(unk0, gfx_ctxt, "../z_en_test.c_80864710", __LINE__);*/
    }
  }
  if ((en->actor).variable == 0)
  {
    if (((en->actor).flags & 0x80) != 0x80)
    {
      *dlist = 0;
    }
  }
  return 0;
}

void skl_callback_80863CC4(z64_global_t *gl, uint8_t limb, uint32_t dlist, vec3s_t *rotation, entity_t *en) /* 0 internal, 8 external, 177 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863CC4: \n"
	);

  external_func_80032F54(AADDR(en, 0x07F0), limb, 0, 0x3C, 0x3C, dlist, -1); /* external_func_80032F54 */
  if (limb == 0x22)
  {
    //external_func_800D1AF4(data_8086467C);
    //external_func_800D1AF4(data_80864688);
    //external_func_800D1AF4(data_80864694);
    //external_func_800D1AF4(data_808646A0, AADDR(en, 0x08B4));
    external_func_0x80062734(AADDR(en, 0x85C), AADDR(en, 0x89C), AADDR(en, 0x8A8), AADDR(en, 0x8B4), AADDR(en, 0x8C0));
    //external_func_800D1AF4(data_8086467C);
    //external_func_800D1AF4(data_8086467C);

    /*Take It Away, Ghidra*/
        if (('\0' < *(en + 0x808)) && ((*(en + 0x1c) != 0 || (gl->actor_ctxt[3] != '\0')))) {
      uVar1 = func_0x80026b0c(*(en + 0x80c));
      func_0x8001fdf0(uVar1,auStack16,&local_1c);
      sVar3 = *(en + 0x7e0);
      goto LAB_80863f3c;
    }
    if (*(en + 0x808) < '\0') {
      sVar3 = *(en + 0x7e0);
      goto LAB_80863f3c;
    }
    uVar1 = func_0x80026b0c(*(en + 0x80c));
    func_0x80020120(uVar1);
    *(en + 0x808) = 0xff;
  }
  else {
    if ((iVar2 == 0x1b) && (*(en + 0x7de) != '\0')) {
      func_0x800d1af4(&DAT_80864670,&local_1c);
      *(en + 0x922) = local_1c;
      *(en + 0x924) = local_18;
      *(en + 0x926) = local_14;
    }
    else {
      func_0x8002bdb0(en,iVar2,0x30,&DAT_80864658,0x37,&DAT_80864658);
      if ((iVar2 != 0x30) && (iVar2 != 0x37)) {
        sVar3 = *(en + 0x7e0);
        goto LAB_80863f3c;
      }
      if ((*(en + 0x7c8) != '\x15') && (*(en + 0x7c8) != '\x16')) {
        sVar3 = *(en + 0x7e0);
        goto LAB_80863f3c;
      }
      if (*(en + 0x68) == 0.00000000) {
        sVar3 = *(en + 0x7e0);
        goto LAB_80863f3c;
      }
      func_0x800d1af4(&DAT_80864658,&local_1c);
      func_0x80033260(gl,en,&local_1c,0x41200000,1,0x41000000,100,0xf,0);
    }
  }
  sVar3 = *(en + 0x7e0);
  LAB_80863f3c:
  if (sVar3 != 0) {
    switch(iVar2) {
    case 0xb:
      local_4 = 0;
      break;
    case 0xf:
      local_4 = 1;
      break;
    case 0x1b:
      local_4 = 3;
      break;
    case 0x1d:
      local_4 = 5;
      break;
    case 0x22:
      local_4 = 2;
      break;
    case 0x25:
      local_4 = 4;
      break;
    case 0x30:
      local_4 = 7;
      break;
    case 0x39:
      local_4 = 8;
      break;
    case 0x3c:
      local_4 = 6;
    }
    if (-1 < local_4) {
      func_0x800d1af4(&DAT_80864670,&local_30);
      en = en + local_4 * 6;
      *(en + 0x14c) = local_30;
      *(en + 0x14e) = local_2c;
      *(en + 0x150) = local_28;
    }
  }
  return;
}

void func_808641E8(void) /* 4 internal, 4 external, 226 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808641E8: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,40($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"jal             external_func_80033780                 \n"
		"lui             $a2,0x4396                             \n"
		"lw              $a3,44($sp)                            \n"
		"beq             $v0,$zero,.L000327                     \n"
		"or              $a1,$v0,$zero                          \n"
		"or              $a0,$a3,$zero                          \n"
		"sw              $v0,36($sp)                            \n"
		"jal             external_func_8002DA78                 \n"
		"sw              $a3,44($sp)                            \n"
		"lw              $a3,44($sp)                            \n"
		"or              $t0,$zero,$zero                        \n"
		"lhu             $a0,182($a3)                           \n"
		"lhu             $t7,136($a3)                           \n"
		"subu            $v1,$v0,$a0                            \n"
		"sll             $v1,$v1,16                             \n"
		"andi            $t8,$t7,0x8                            \n"
		"beq             $t8,$zero,.L000328                     \n"
		"sra             $v1,$v1,16                             \n"
		"lhu             $t9,126($a3)                           \n"
		"addiu           $t0,$zero,1                            \n"
		"subu            $a2,$t9,$a0                            \n"
		"sll             $a2,$a2,16                             \n"
		"sra             $a2,$a2,16                             \n"
		"beq             $zero,$zero,.L000328                   \n"
		"sh              $a2,32($sp)                            \n"
		".L000328:                                              \n"
		"lw              $a1,36($sp)                            \n"
		"addiu           $a0,$a3,36                             \n"
		"sh              $v1,34($sp)                            \n"
		"sw              $a3,44($sp)                            \n"
		"sh              $t0,30($sp)                            \n"
		"jal             external_func_80077F90                 \n"
		"addiu           $a1,$a1,36                             \n"
		"lui             $at,0x4348                             \n"
		"mtc1            $at,$f4                                \n"
		"lw              $a3,44($sp)                            \n"
		"lh              $v1,34($sp)                            \n"
		"c.lt.s          $f0,$f4                                \n"
		"lh              $a2,32($sp)                            \n"
		"lh              $t0,30($sp)                            \n"
		"lw              $a0,40($sp)                            \n"
		"bc1f            .L000329                               \n"
		"or              $a1,$a3,$zero                          \n"
		"lw              $a0,40($sp)                            \n"
		"or              $a1,$a3,$zero                          \n"
		"sh              $v1,34($sp)                            \n"
		"jal             external_func_80033A84                 \n"
		"sw              $a3,44($sp)                            \n"
		"lh              $v1,34($sp)                            \n"
		"beq             $v0,$zero,.L000330                     \n"
		"lw              $a3,44($sp)                            \n"
		"lw              $t1,36($sp)                            \n"
		"addiu           $at,$zero,102                          \n"
		"lh              $t2,0($t1)                             \n"
		"bne             $t2,$at,.L000330                       \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000330:                                              \n"
		"bltz            $v1,.L000332                           \n"
		"subu            $v0,$zero,$v1                          \n"
		"beq             $zero,$zero,.L000332                   \n"
		"or              $v0,$v1,$zero                          \n"
		".L000332:                                              \n"
		"slti            $at,$v0,8192                           \n"
		"beq             $at,$zero,.L000333                     \n"
		"nop                                                    \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000333:                                              \n"
		"bltz            $v1,.L000334                           \n"
		"subu            $v0,$zero,$v1                          \n"
		"beq             $zero,$zero,.L000334                   \n"
		"or              $v0,$v1,$zero                          \n"
		".L000334:                                              \n"
		"slti            $at,$v0,24576                          \n"
		"beq             $at,$zero,.L000335                     \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000335:                                              \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000329:                                              \n"
		"sh              $v1,34($sp)                            \n"
		"sh              $a2,32($sp)                            \n"
		"sw              $a3,44($sp)                            \n"
		"jal             external_func_80033A84                 \n"
		"sh              $t0,30($sp)                            \n"
		"lh              $v1,34($sp)                            \n"
		"lh              $a2,32($sp)                            \n"
		"lw              $a3,44($sp)                            \n"
		"beq             $v0,$zero,.L000336                     \n"
		"lh              $t0,30($sp)                            \n"
		"lw              $t3,36($sp)                            \n"
		"addiu           $at,$zero,102                          \n"
		"lh              $t4,0($t3)                             \n"
		"bne             $t4,$at,.L000336                       \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000336:                                              \n"
		"bltz            $v1,.L000337                           \n"
		"subu            $v0,$zero,$v1                          \n"
		"beq             $zero,$zero,.L000337                   \n"
		"or              $v0,$v1,$zero                          \n"
		".L000337:                                              \n"
		"slti            $at,$v0,8192                           \n"
		"bne             $at,$zero,.L000338                     \n"
		"lw              $t5,40($sp)                            \n"
		"bltz            $v1,.L000339                           \n"
		"subu            $v0,$zero,$v1                          \n"
		"beq             $zero,$zero,.L000339                   \n"
		"or              $v0,$v1,$zero                          \n"
		".L000339:                                              \n"
		"slti            $at,$v0,24577                          \n"
		"bne             $at,$zero,.L000340                     \n"
		"nop                                                    \n"
		".L000338:                                              \n"
		"lui             $v1,0x0001                             \n"
		"addu            $v1,$v1,$t5                            \n"
		"lw              $v1,7652($v1)                          \n"
		"slti            $at,$a2,8193                           \n"
		"or              $a0,$a3,$zero                          \n"
		"andi            $v1,$v1,0x1                            \n"
		"sll             $v1,$v1,16                             \n"
		"beq             $t0,$zero,.L000341                     \n"
		"sra             $v1,$v1,16                             \n"
		"bne             $at,$zero,.L000341                     \n"
		"slti            $at,$a2,24576                          \n"
		"beq             $at,$zero,.L000341                     \n"
		"nop                                                    \n"
		"beq             $zero,$zero,.L000342                   \n"
		"or              $v1,$zero,$zero                        \n"
		".L000341:                                              \n"
		"beq             $t0,$zero,.L000342                     \n"
		"slti            $at,$a2,-8192                          \n"
		"beq             $at,$zero,.L000342                     \n"
		"slti            $at,$a2,-24575                         \n"
		"bne             $at,$zero,.L000342                     \n"
		"nop                                                    \n"
		"addiu           $v1,$zero,1                            \n"
		".L000342:                                              \n"
		"beq             $v1,$zero,.L000343                     \n"
		"lui             $a1,0x4080                             \n"
		"jal             func_80864158                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000343:                                              \n"
		"jal             func_80864158                          \n"
		"lui             $a1,0xC080                             \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000340:                                              \n"
		"bltz            $v1,.L000344                           \n"
		"subu            $v0,$zero,$v1                          \n"
		"beq             $zero,$zero,.L000344                   \n"
		"or              $v0,$v1,$zero                          \n"
		".L000344:                                              \n"
		"slti            $at,$v0,24576                          \n"
		"beq             $at,$zero,.L000345                     \n"
		"lw              $t6,40($sp)                            \n"
		"lui             $v1,0x0001                             \n"
		"addu            $v1,$v1,$t6                            \n"
		"lw              $v1,7652($v1)                          \n"
		"andi            $v1,$v1,0x1                            \n"
		"sll             $v1,$v1,16                             \n"
		"beq             $t0,$zero,.L000346                     \n"
		"sra             $v1,$v1,16                             \n"
		"bltz            $a2,.L000347                           \n"
		"subu            $v0,$zero,$a2                          \n"
		"beq             $zero,$zero,.L000347                   \n"
		"or              $v0,$a2,$zero                          \n"
		".L000347:                                              \n"
		"slti            $at,$v0,24577                          \n"
		"bne             $at,$zero,.L000346                     \n"
		"nop                                                    \n"
		"beq             $zero,$zero,.L000348                   \n"
		"or              $v1,$zero,$zero                        \n"
		".L000346:                                              \n"
		"beq             $t0,$zero,.L000348                     \n"
		"nop                                                    \n"
		"bltz            $a2,.L000349                           \n"
		"subu            $v0,$zero,$a2                          \n"
		"beq             $zero,$zero,.L000349                   \n"
		"or              $v0,$a2,$zero                          \n"
		".L000349:                                              \n"
		"slti            $at,$v0,8192                           \n"
		"beq             $at,$zero,.L000348                     \n"
		"nop                                                    \n"
		"addiu           $v1,$zero,1                            \n"
		".L000348:                                              \n"
		"beq             $v1,$zero,.L000350                     \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000350:                                              \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$a3,$zero                          \n"
		".L000345:                                              \n"
		"beq             $zero,$zero,.L000331                   \n"
		"addiu           $v0,$zero,1                            \n"
		".L000327:                                              \n"
		"or              $v0,$zero,$zero                        \n"
		".L000331:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80863294(void) /* 3 internal, 2 external, 55 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80863294: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$a0,392                            \n"
		"beql            $v0,$zero,.L000266                     \n"
		"lw              $ra,28($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_808647D8)                 \n"
		"lwc1            $f4,%lo(data_808647D8)($at)            \n"
		"lw              $a1,36($sp)                            \n"
		"lui             $t8,0x0001                             \n"
		"c.lt.s          $f4,$f0                                \n"
		"addu            $t8,$t8,$a1                            \n"
		"bc1fl           .L000267                               \n"
		"lw              $t8,7652($t8)                          \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"mul.s           $f6,$f0,$f2                            \n"
		"add.s           $f8,$f6,$f2                            \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $t7,$f10                               \n"
		"beq             $zero,$zero,.L000268                   \n"
		"sw              $t7,2024($s0)                          \n"
		"lw              $t8,7652($t8)                          \n"
		".L000267:                                              \n"
		"andi            $t9,$t8,0x1                            \n"
		"beq             $t9,$zero,.L000269                     \n"
		"nop                                                    \n"
		"lh              $t0,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"beq             $t0,$at,.L000269                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000266                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000269:                                              \n"
		"jal             func_808627C4                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000268:                                              \n"
		"lw              $ra,28($sp)                            \n"
		".L000266:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80860C24(void) /* 4 internal, 4 external, 182 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80860C24: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"or              $a1,$a2,$zero                          \n"
		"jal             func_808641E8                          \n"
		"sw              $a2,40($sp)                            \n"
		"bne             $v0,$zero,.L000085                     \n"
		"lw              $a2,40($sp)                            \n"
		"lh              $v0,138($a2)                           \n"
		"lh              $a0,182($a2)                           \n"
		"subu            $v0,$v0,$a0                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"blezl           $v0,.L000086                           \n"
		"mtc1            $v0,$f6                                \n"
		"mtc1            $v0,$f4                                \n"
		"lui             $at,0x4228                             \n"
		"mtc1            $at,$f8                                \n"
		"cvt.s.w         $f6,$f4                                \n"
		"lui             $at,0x4396                             \n"
		"mtc1            $at,$f16                               \n"
		"div.s           $f10,$f6,$f8                           \n"
		"add.s           $f18,$f10,$f16                         \n"
		"trunc.w.s       $f4,$f18                               \n"
		"mfc1            $t8,$f4                                \n"
		"nop                                                    \n"
		"sll             $t9,$t8,1                              \n"
		"addu            $t0,$a0,$t9                            \n"
		"sll             $a1,$t8,16                             \n"
		"sra             $a1,$a1,16                             \n"
		"beq             $zero,$zero,.L000087                   \n"
		"sh              $t0,182($a2)                           \n"
		"mtc1            $v0,$f6                                \n"
		".L000086:                                              \n"
		"lui             $at,0x4228                             \n"
		"mtc1            $at,$f10                               \n"
		"cvt.s.w         $f8,$f6                                \n"
		"lui             $at,0x4396                             \n"
		"mtc1            $at,$f18                               \n"
		"div.s           $f16,$f8,$f10                          \n"
		"sub.s           $f4,$f16,$f18                          \n"
		"trunc.w.s       $f6,$f4                                \n"
		"mfc1            $t3,$f6                                \n"
		"nop                                                    \n"
		"sll             $t4,$t3,1                              \n"
		"addu            $t5,$a0,$t4                            \n"
		"sll             $a1,$t3,16                             \n"
		"sra             $a1,$a1,16                             \n"
		"sh              $t5,182($a2)                           \n"
		".L000087:                                              \n"
		"lh              $t6,182($a2)                           \n"
		"blez            $v0,.L000088                           \n"
		"sh              $t6,50($a2)                            \n"
		"mtc1            $a1,$f8                                \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f12                               \n"
		"cvt.s.w         $f10,$f8                               \n"
		"lui             $at,%hi(data_808647A4)                 \n"
		"lwc1            $f16,%lo(data_808647A4)($at)           \n"
		"mul.s           $f2,$f10,$f16                          \n"
		"c.lt.s          $f12,$f2                               \n"
		"nop                                                    \n"
		"bc1f            .L000089                               \n"
		"nop                                                    \n"
		"mov.s           $f2,$f12                               \n"
		".L000089:                                              \n"
		"beq             $zero,$zero,.L000090                   \n"
		"swc1            $f2,420($a2)                           \n"
		".L000088:                                              \n"
		"mtc1            $a1,$f18                               \n"
		"lui             $at,0xBF80                             \n"
		"mtc1            $at,$f12                               \n"
		"cvt.s.w         $f4,$f18                               \n"
		"lui             $at,%hi(data_808647A8)                 \n"
		"lwc1            $f6,%lo(data_808647A8)($at)            \n"
		"mul.s           $f2,$f4,$f6                            \n"
		"c.lt.s          $f2,$f12                               \n"
		"nop                                                    \n"
		"bc1fl           .L000090                               \n"
		"swc1            $f2,420($a2)                           \n"
		"mov.s           $f2,$f12                               \n"
		"swc1            $f2,420($a2)                           \n"
		".L000090:                                              \n"
		"lwc1            $f8,416($a2)                           \n"
		"sw              $a2,40($sp)                            \n"
		"addiu           $a0,$a2,392                            \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $v1,$f10                               \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $v1,28($sp)                            \n"
		"lw              $a2,40($sp)                            \n"
		"mtc1            $zero,$f14                             \n"
		"lw              $v1,28($sp)                            \n"
		"lwc1            $f0,420($a2)                           \n"
		"c.le.s          $f14,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000091                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000091                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000091:                                              \n"
		"lwc1            $f12,416($a2)                          \n"
		"c.le.s          $f14,$f0                               \n"
		"sub.s           $f16,$f12,$f2                          \n"
		"trunc.w.s       $f4,$f12                               \n"
		"trunc.w.s       $f18,$f16                              \n"
		"mfc1            $t0,$f4                                \n"
		"mfc1            $a0,$f18                               \n"
		"bc1fl           .L000092                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000092                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000092:                                              \n"
		"beql            $v1,$t0,.L000093                       \n"
		"or              $a0,$a2,$zero                          \n"
		"trunc.w.s       $f6,$f2                                \n"
		"mfc1            $t2,$f6                                \n"
		"nop                                                    \n"
		"addu            $v0,$t2,$v1                            \n"
		"slti            $at,$v0,3                              \n"
		"bnel            $at,$zero,.L000094                     \n"
		"slti            $at,$a0,7                              \n"
		"blez            $a0,.L000095                           \n"
		"slti            $at,$a0,7                              \n"
		".L000094:                                              \n"
		"beq             $at,$zero,.L000096                     \n"
		"slti            $at,$v0,9                              \n"
		"bne             $at,$zero,.L000096                     \n"
		".L000095:                                              \n"
		"or              $a0,$a2,$zero                          \n"
		"addiu           $a1,$zero,14397                        \n"
		"jal             external_func_8002F828                 \n"
		"sw              $a2,40($sp)                            \n"
		"lw              $a2,40($sp)                            \n"
		".L000096:                                              \n"
		"or              $a0,$a2,$zero                          \n"
		".L000093:                                              \n"
		"addiu           $a1,$zero,1820                         \n"
		"jal             external_func_8002E084                 \n"
		"sw              $a2,40($sp)                            \n"
		"beq             $v0,$zero,.L000085                     \n"
		"lw              $a2,40($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $a2,40($sp)                            \n"
		"lui             $at,%hi(data_808647AC)                 \n"
		"lwc1            $f8,%lo(data_808647AC)($at)            \n"
		"lw              $a2,40($sp)                            \n"
		"c.lt.s          $f8,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000097                               \n"
		"nop                                                    \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $a2,40($sp)                            \n"
		"lui             $at,%hi(data_808647B0)                 \n"
		"lwc1            $f10,%lo(data_808647B0)($at)           \n"
		"lw              $a2,40($sp)                            \n"
		"c.lt.s          $f10,$f0                               \n"
		"or              $a0,$a2,$zero                          \n"
		"bc1f            .L000098                               \n"
		"nop                                                    \n"
		"jal             func_80860EC0                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000099                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000098:                                              \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,44($sp)                            \n"
		"beq             $zero,$zero,.L000099                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000097:                                              \n"
		"jal             func_80860438                          \n"
		"or              $a0,$a2,$zero                          \n"
		".L000085:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000099:                                              \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808615F4(void) /* 4 internal, 3 external, 150 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808615F4: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $a2,32($sp)                            \n"
		"addiu           $a0,$a0,392                            \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $t7,28($sp)                            \n"
		"beq             $v0,$zero,.L000137                     \n"
		"lw              $a2,32($sp)                            \n"
		"lbu             $v0,2156($a2)                          \n"
		"andi            $t8,$v0,0x2                            \n"
		"beq             $t8,$zero,.L000138                     \n"
		"nop                                                    \n"
		"lh              $t0,28($a2)                            \n"
		"andi            $t9,$v0,0xfffd                         \n"
		"addiu           $at,$zero,3                            \n"
		"beq             $t0,$at,.L000138                       \n"
		"sb              $t9,2156($a2)                          \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000138:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $a2,32($sp)                            \n"
		"lui             $at,%hi(data_808647BC)                 \n"
		"lwc1            $f4,%lo(data_808647BC)($at)            \n"
		"lw              $a2,32($sp)                            \n"
		"lw              $a1,28($sp)                            \n"
		"c.lt.s          $f4,$f0                                \n"
		"or              $a0,$a2,$zero                          \n"
		"bc1f            .L000140                               \n"
		"nop                                                    \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             func_80860068                          \n"
		"sw              $a2,32($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f2                                \n"
		"lw              $a2,32($sp)                            \n"
		"mul.s           $f6,$f0,$f2                            \n"
		"add.s           $f8,$f6,$f2                            \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $t2,$f10                               \n"
		"beq             $zero,$zero,.L000137                   \n"
		"sw              $t2,2024($a2)                          \n"
		".L000140:                                              \n"
		"jal             external_func_8002DA78                 \n"
		"sw              $a2,32($sp)                            \n"
		"lw              $a2,32($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sh              $v0,50($a2)                            \n"
		"lui             $at,%hi(data_808647C0)                 \n"
		"lwc1            $f16,%lo(data_808647C0)($at)           \n"
		"lw              $a2,32($sp)                            \n"
		"lw              $t4,28($sp)                            \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000141                               \n"
		"lh              $a0,182($a2)                           \n"
		"lh              $t3,28($a2)                            \n"
		"addiu           $at,$zero,3                            \n"
		"beql            $t3,$at,.L000141                       \n"
		"lh              $a0,182($a2)                           \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		"lh              $a0,182($a2)                           \n"
		".L000141:                                              \n"
		"lh              $t5,182($t4)                           \n"
		"lw              $a1,36($sp)                            \n"
		"subu            $v0,$t5,$a0                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000142                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000142                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000142:                                              \n"
		"slti            $at,$v1,10001                          \n"
		"beq             $at,$zero,.L000143                     \n"
		"nop                                                    \n"
		"lh              $a1,138($a2)                           \n"
		"lw              $t7,28($sp)                            \n"
		"subu            $v0,$a1,$a0                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000144                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000144                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000144:                                              \n"
		"slti            $at,$v1,16001                          \n"
		"bnel            $at,$zero,.L000145                     \n"
		"lw              $t8,1660($t7)                          \n"
		"lh              $t6,28($a2)                            \n"
		"addiu           $at,$zero,3                            \n"
		"or              $a0,$a2,$zero                          \n"
		"beql            $t6,$at,.L000145                       \n"
		"lw              $t8,1660($t7)                          \n"
		"jal             func_8086194C                          \n"
		"sh              $a1,50($a2)                            \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		"lw              $t8,1660($t7)                          \n"
		".L000145:                                              \n"
		"andi            $t9,$t8,0x10                           \n"
		"beq             $t9,$zero,.L000146                     \n"
		"nop                                                    \n"
		"lbu             $t0,268($a2)                           \n"
		"lw              $a1,36($sp)                            \n"
		"lui             $t1,0x0001                             \n"
		"beq             $t0,$zero,.L000147                     \n"
		"addu            $t1,$t1,$a1                            \n"
		"jal             func_80861418                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000147:                                              \n"
		"lw              $t1,7652($t1)                          \n"
		"andi            $t2,$t1,0x1                            \n"
		"beq             $t2,$zero,.L000148                     \n"
		"nop                                                    \n"
		"jal             func_808627C4                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000148:                                              \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000146:                                              \n"
		"jal             func_80861418                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000139                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000143:                                              \n"
		"jal             func_808627C4                          \n"
		"or              $a0,$a2,$zero                          \n"
		".L000137:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000139:                                              \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808619EC(void) /* 4 internal, 5 external, 116 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808619EC: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $s0,32($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $t6,$zero,1                            \n"
		"sw              $t6,16($sp)                            \n"
		"addiu           $a0,$a0,182                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_8007869C                 \n"
		"addiu           $a3,$zero,3000                         \n"
		"lw              $v1,2024($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"bne             $v1,$zero,.L000156                     \n"
		"addiu           $t7,$v1,-1                             \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"beq             $zero,$zero,.L000157                   \n"
		"nop                                                    \n"
		".L000156:                                              \n"
		"sw              $t7,2024($s0)                          \n"
		".L000157:                                              \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"beq             $v0,$zero,.L000158                     \n"
		"lui             $at,0x4080                             \n"
		"lw              $a0,44($sp)                            \n"
		"jal             func_808641E8                          \n"
		"or              $a1,$s0,$zero                          \n"
		"bne             $v0,$zero,.L000159                     \n"
		"lui             $at,0x42C8                             \n"
		"lwc1            $f0,144($s0)                           \n"
		"mtc1            $at,$f4                                \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $at,0x435C                             \n"
		"c.le.s          $f0,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000160                               \n"
		"mtc1            $at,$f16                               \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,5461                         \n"
		"beq             $v0,$zero,.L000161                     \n"
		"nop                                                    \n"
		"jal             func_80861418                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000162                   \n"
		"lw              $t2,4($s0)                             \n"
		".L000161:                                              \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"mul.s           $f6,$f0,$f2                            \n"
		"add.s           $f8,$f6,$f2                            \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $t9,$f10                               \n"
		"beq             $zero,$zero,.L000163                   \n"
		"sw              $t9,2024($s0)                          \n"
		"mtc1            $at,$f16                               \n"
		".L000160:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"c.le.s          $f0,$f16                               \n"
		"nop                                                    \n"
		"bc1f            .L000164                               \n"
		"nop                                                    \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,3640                         \n"
		"beq             $v0,$zero,.L000164                     \n"
		"nop                                                    \n"
		"jal             func_80861B94                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000162                   \n"
		"lw              $t2,4($s0)                             \n"
		".L000164:                                              \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"mul.s           $f18,$f0,$f2                           \n"
		"add.s           $f4,$f18,$f2                           \n"
		"trunc.w.s       $f6,$f4                                \n"
		"mfc1            $t1,$f6                                \n"
		"nop                                                    \n"
		"sw              $t1,2024($s0)                          \n"
		".L000163:                                              \n"
		"lw              $t2,4($s0)                             \n"
		".L000162:                                              \n"
		"ori             $t3,$t2,0x1                            \n"
		"beq             $zero,$zero,.L000159                   \n"
		"sw              $t3,4($s0)                             \n"
		".L000158:                                              \n"
		"lwc1            $f8,408($s0)                           \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f18,416($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"sub.s           $f16,$f8,$f10                          \n"
		"c.eq.s          $f16,$f18                              \n"
		"nop                                                    \n"
		"bc1fl           .L000165                               \n"
		"lw              $ra,36($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14459                        \n"
		".L000159:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000165:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808628C8(void) /* 4 internal, 9 external, 349 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808628C8: \n"
	);
	asm(
		"addiu           $sp,$sp,-80                            \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,84($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"mtc1            $zero,$f4                              \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $t7,72($sp)                            \n"
		"swc1            $f4,52($sp)                            \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $t8,$zero,1                            \n"
		"sw              $t8,16($sp)                            \n"
		"addiu           $a0,$a0,182                            \n"
		"addiu           $a2,$zero,1                            \n"
		"jal             external_func_8007869C                 \n"
		"addiu           $a3,$zero,4000                         \n"
		"lbu             $v1,2014($s0)                          \n"
		"mtc1            $zero,$f6                              \n"
		"bne             $v1,$zero,.L000215                     \n"
		"addiu           $t9,$v1,1                              \n"
		"sb              $t9,2014($s0)                          \n"
		".L000215:                                              \n"
		"lwc1            $f0,104($s0)                           \n"
		"c.le.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000216                               \n"
		"lui             $at,0x40C0                             \n"
		"mtc1            $at,$f2                                \n"
		"lui             $at,0x3E00                             \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1f            .L000217                               \n"
		"nop                                                    \n"
		"mtc1            $at,$f8                                \n"
		"nop                                                    \n"
		"add.s           $f10,$f0,$f8                           \n"
		"beq             $zero,$zero,.L000218                   \n"
		"swc1            $f10,104($s0)                          \n"
		".L000217:                                              \n"
		"beq             $zero,$zero,.L000218                   \n"
		"swc1            $f2,104($s0)                           \n"
		".L000216:                                              \n"
		"lui             $at,0xC0C0                             \n"
		"mtc1            $at,$f2                                \n"
		"lui             $at,0x3E00                             \n"
		"c.lt.s          $f2,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000218                               \n"
		"swc1            $f2,104($s0)                           \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"sub.s           $f18,$f0,$f16                          \n"
		"beq             $zero,$zero,.L000218                   \n"
		"swc1            $f18,104($s0)                          \n"
		"swc1            $f2,104($s0)                           \n"
		".L000218:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		"andi            $v0,$v0,0x8                            \n"
		"bne             $v0,$zero,.L000219                     \n"
		"nop                                                    \n"
		"lh              $t0,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"or              $a0,$s0,$zero                          \n"
		"bnel            $t0,$at,.L000220                       \n"
		"lh              $t2,182($s0)                           \n"
		"lh              $a3,182($s0)                           \n"
		"lw              $a1,84($sp)                            \n"
		"lw              $a2,104($s0)                           \n"
		"addiu           $a3,$a3,16383                          \n"
		"sll             $a3,$a3,16                             \n"
		"jal             external_func_800339B8                 \n"
		"sra             $a3,$a3,16                             \n"
		"bnel            $v0,$zero,.L000220                     \n"
		"lh              $t2,182($s0)                           \n"
		"lhu             $v0,136($s0)                           \n"
		"andi            $v0,$v0,0x8                            \n"
		".L000219:                                              \n"
		"beq             $v0,$zero,.L000221                     \n"
		"lui             $at,%hi(data_808647D0)                 \n"
		"lwc1            $f4,104($s0)                           \n"
		"mtc1            $zero,$f6                              \n"
		"nop                                                    \n"
		"c.le.s          $f6,$f4                                \n"
		"nop                                                    \n"
		"bc1fl           .L000222                               \n"
		"lh              $v0,182($s0)                           \n"
		"lh              $v0,182($s0)                           \n"
		"addiu           $v0,$v0,16383                          \n"
		"sll             $v0,$v0,16                             \n"
		"beq             $zero,$zero,.L000223                   \n"
		"sra             $v0,$v0,16                             \n"
		"lh              $v0,182($s0)                           \n"
		".L000222:                                              \n"
		"addiu           $v0,$v0,-16383                         \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		".L000223:                                              \n"
		"lh              $t1,126($s0)                           \n"
		"subu            $v0,$t1,$v0                            \n"
		"sll             $v0,$v0,16                             \n"
		"beq             $zero,$zero,.L000224                   \n"
		"sra             $v0,$v0,16                             \n"
		".L000221:                                              \n"
		"lwc1            $f8,104($s0)                           \n"
		"lwc1            $f10,%lo(data_808647D0)($at)           \n"
		"or              $v0,$zero,$zero                        \n"
		"mul.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,104($s0)                          \n"
		".L000224:                                              \n"
		"bltz            $v0,.L000225                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000225                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000225:                                              \n"
		"slti            $at,$v1,16385                          \n"
		"bne             $at,$zero,.L000226                     \n"
		"lui             $at,%hi(data_808647D4)                 \n"
		"lwc1            $f4,%lo(data_808647D4)($at)            \n"
		"lwc1            $f18,104($s0)                          \n"
		"mtc1            $zero,$f8                              \n"
		"lui             $at,0x3F00                             \n"
		"mul.s           $f6,$f18,$f4                           \n"
		"swc1            $f6,104($s0)                           \n"
		"lwc1            $f0,104($s0)                           \n"
		"c.lt.s          $f0,$f8                                \n"
		"nop                                                    \n"
		"bc1fl           .L000227                               \n"
		"mtc1            $at,$f18                               \n"
		"lui             $at,0x3F00                             \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"sub.s           $f16,$f0,$f10                          \n"
		"beq             $zero,$zero,.L000226                   \n"
		"swc1            $f16,104($s0)                          \n"
		"mtc1            $at,$f18                               \n"
		".L000227:                                              \n"
		"nop                                                    \n"
		"add.s           $f4,$f0,$f18                           \n"
		"swc1            $f4,104($s0)                           \n"
		".L000226:                                              \n"
		"lh              $t2,182($s0)                           \n"
		".L000220:                                              \n"
		"or              $a1,$s0,$zero                          \n"
		"addiu           $t3,$t2,16383                          \n"
		"sh              $t3,50($s0)                            \n"
		"jal             external_func_80033AB8                 \n"
		"lw              $a0,84($sp)                            \n"
		"beq             $v0,$zero,.L000228                     \n"
		"lui             $at,0x4348                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"swc1            $f2,52($sp)                            \n"
		".L000228:                                              \n"
		"lui             $at,0x42A0                             \n"
		"lwc1            $f2,52($sp)                            \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f0,144($s0)                           \n"
		"addiu           $a0,$s0,2028                           \n"
		"add.s           $f8,$f6,$f2                            \n"
		"lui             $a1,0xC020                             \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3F4C                             \n"
		"c.le.s          $f0,$f8                                \n"
		"lui             $at,0x42DC                             \n"
		"bc1fl           .L000229                               \n"
		"mtc1            $at,$f16                               \n"
		"mtc1            $zero,$f10                             \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f10,16($sp)                           \n"
		"beq             $zero,$zero,.L000230                   \n"
		"mtc1            $zero,$f8                              \n"
		"mtc1            $at,$f16                               \n"
		".L000229:                                              \n"
		"addiu           $a0,$s0,2028                           \n"
		"addiu           $a1,$zero,0                            \n"
		"add.s           $f18,$f16,$f2                          \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x40D4                             \n"
		"c.lt.s          $f18,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000231                               \n"
		"mtc1            $zero,$f6                              \n"
		"mtc1            $zero,$f4                              \n"
		"lui             $a3,0x3F4C                             \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"addiu           $a0,$s0,2028                           \n"
		"lui             $a1,0x4020                             \n"
		"lui             $a2,0x3F80                             \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f4,16($sp)                            \n"
		"beq             $zero,$zero,.L000230                   \n"
		"mtc1            $zero,$f8                              \n"
		"mtc1            $zero,$f6                              \n"
		".L000231:                                              \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f6,16($sp)                            \n"
		"mtc1            $zero,$f8                              \n"
		".L000230:                                              \n"
		"lwc1            $f10,2028($s0)                         \n"
		"c.eq.s          $f8,$f10                               \n"
		"nop                                                    \n"
		"bc1tl           .L000232                               \n"
		"lui             $at,0x3F00                             \n"
		"jal             external_func_80077870                 \n"
		"lh              $a0,182($s0)                           \n"
		"lwc1            $f18,2028($s0)                         \n"
		"lwc1            $f16,36($s0)                           \n"
		"lh              $a0,182($s0)                           \n"
		"mul.s           $f4,$f0,$f18                           \n"
		"add.s           $f6,$f16,$f4                           \n"
		"jal             external_func_80077834                 \n"
		"swc1            $f6,36($s0)                            \n"
		"lwc1            $f10,2028($s0)                         \n"
		"lwc1            $f8,44($s0)                            \n"
		"mul.s           $f18,$f0,$f10                          \n"
		"add.s           $f16,$f8,$f18                          \n"
		"swc1            $f16,44($s0)                           \n"
		"lui             $at,0x3F00                             \n"
		".L000232:                                              \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f4,104($s0)                           \n"
		"lwc1            $f8,416($s0)                           \n"
		"addiu           $a0,$s0,392                            \n"
		"mul.s           $f10,$f4,$f6                           \n"
		"trunc.w.s       $f18,$f8                               \n"
		"mfc1            $t5,$f18                               \n"
		"swc1            $f10,420($s0)                          \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $t5,64($sp)                            \n"
		"mtc1            $zero,$f14                             \n"
		"lwc1            $f0,420($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,14392                        \n"
		"c.le.s          $f14,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000233                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000233                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000233:                                              \n"
		"lwc1            $f12,416($s0)                          \n"
		"c.le.s          $f14,$f0                               \n"
		"sub.s           $f16,$f12,$f2                          \n"
		"trunc.w.s       $f4,$f16                               \n"
		"mfc1            $v1,$f4                                \n"
		"bc1fl           .L000234                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000234                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000234:                                              \n"
		"lw              $t7,2024($s0)                          \n"
		"andi            $t8,$t7,0x1f                           \n"
		"bnel            $t8,$zero,.L000235                     \n"
		"trunc.w.s       $f6,$f12                               \n"
		"sw              $v1,60($sp)                            \n"
		"jal             external_func_8002F828                 \n"
		"swc1            $f2,44($sp)                            \n"
		"lw              $v1,60($sp)                            \n"
		"lwc1            $f2,44($sp)                            \n"
		"lwc1            $f12,416($s0)                          \n"
		"trunc.w.s       $f6,$f12                               \n"
		".L000235:                                              \n"
		"lw              $a0,64($sp)                            \n"
		"mfc1            $t0,$f6                                \n"
		"nop                                                    \n"
		"beql            $a0,$t0,.L000236                       \n"
		"lw              $v0,2024($s0)                          \n"
		"trunc.w.s       $f10,$f2                               \n"
		"mfc1            $t2,$f10                               \n"
		"nop                                                    \n"
		"addu            $v0,$t2,$a0                            \n"
		"slti            $at,$v0,2                              \n"
		"bnel            $at,$zero,.L000237                     \n"
		"slti            $at,$v1,7                              \n"
		"blez            $v1,.L000238                           \n"
		"slti            $at,$v1,7                              \n"
		".L000237:                                              \n"
		"beq             $at,$zero,.L000239                     \n"
		"slti            $at,$v0,8                              \n"
		"bne             $at,$zero,.L000239                     \n"
		".L000238:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14397                        \n"
		".L000239:                                              \n"
		"lw              $v0,2024($s0)                          \n"
		".L000236:                                              \n"
		"lw              $a0,84($sp)                            \n"
		"bne             $v0,$zero,.L000240                     \n"
		"addiu           $t8,$v0,-1                             \n"
		"jal             external_func_80033AB8                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000241                     \n"
		"lw              $a0,84($sp)                            \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000242                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000241:                                              \n"
		"jal             external_func_80033A84                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000243                     \n"
		"lw              $t3,72($sp)                            \n"
		"lw              $a0,84($sp)                            \n"
		"jal             func_808641E8                          \n"
		"or              $a1,$s0,$zero                          \n"
		"bne             $v0,$zero,.L000244                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,84($sp)                            \n"
		"beq             $zero,$zero,.L000242                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000243:                                              \n"
		"lb              $t4,337($t3)                           \n"
		"lw              $t5,84($sp)                            \n"
		"lui             $t6,0x0001                             \n"
		"beq             $t4,$zero,.L000245                     \n"
		"addu            $t6,$t6,$t5                            \n"
		"lw              $t6,7652($t6)                          \n"
		"andi            $t7,$t6,0x1                            \n"
		"beq             $t7,$zero,.L000246                     \n"
		"nop                                                    \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000242                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000246:                                              \n"
		"jal             func_80860438                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000242                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000245:                                              \n"
		"jal             func_80860438                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000242                   \n"
		"lw              $ra,36($sp)                            \n"
		".L000240:                                              \n"
		"sw              $t8,2024($s0)                          \n"
		".L000244:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000242:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,80                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80862418(void) /* 5 internal, 3 external, 95 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80862418: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"mtc1            $zero,$f0                              \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"lui             $a3,0x3DCC                             \n"
		"mfc1            $a1,$f0                                \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"addiu           $a0,$a0,104                            \n"
		"lui             $a2,0x3F80                             \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_80078310                 \n"
		"sw              $t7,44($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"beql            $v0,$zero,.L000192                     \n"
		"lw              $t8,44($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"or              $a1,$s0,$zero                          \n"
		"swc1            $f4,104($s0)                           \n"
		"jal             func_808641E8                          \n"
		"lw              $a0,52($sp)                            \n"
		"bne             $v0,$zero,.L000193                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,52($sp)                            \n"
		"lw              $t8,44($sp)                            \n"
		".L000192:                                              \n"
		"lb              $t9,2115($t8)                          \n"
		"beql            $t9,$zero,.L000194                     \n"
		"lw              $ra,36($sp)                            \n"
		"lhu             $t0,136($s0)                           \n"
		"andi            $t1,$t0,0x8                            \n"
		"beq             $t1,$zero,.L000195                     \n"
		"nop                                                    \n"
		"lh              $t2,126($s0)                           \n"
		"lh              $t3,182($s0)                           \n"
		"subu            $v0,$t2,$t3                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000196                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000196                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000196:                                              \n"
		"slti            $at,$v1,14500                          \n"
		"beq             $at,$zero,.L000195                     \n"
		"lui             $at,0x42A0                             \n"
		"mtc1            $at,$f8                                \n"
		"lwc1            $f6,144($s0)                           \n"
		"c.lt.s          $f6,$f8                                \n"
		"nop                                                    \n"
		"bc1f            .L000195                               \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000197                   \n"
		"addiu           $t7,$zero,8                            \n"
		".L000195:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_808647C8)                 \n"
		"lwc1            $f10,%lo(data_808647C8)($at)           \n"
		"c.lt.s          $f10,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000198                               \n"
		"nop                                                    \n"
		"lh              $t4,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"lw              $t5,44($sp)                            \n"
		"beq             $t4,$at,.L000198                       \n"
		"nop                                                    \n"
		"lb              $t6,2114($t5)                          \n"
		"addiu           $at,$zero,17                           \n"
		"beq             $t6,$at,.L000198                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000197                   \n"
		"addiu           $t7,$zero,8                            \n"
		".L000198:                                              \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $t7,$zero,8                            \n"
		".L000197:                                              \n"
		"sb              $t7,1992($s0)                          \n"
		".L000193:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000194:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808621D4(void) /* 5 internal, 3 external, 122 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808621D4: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"mtc1            $zero,$f0                              \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"lui             $a3,0x3DCC                             \n"
		"mfc1            $a1,$f0                                \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"addiu           $a0,$a0,104                            \n"
		"lui             $a2,0x3F80                             \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_80078310                 \n"
		"sw              $t7,44($sp)                            \n"
		"jal             external_func_800A49FC                 \n"
		"addiu           $a0,$s0,392                            \n"
		"beql            $v0,$zero,.L000183                     \n"
		"lw              $t2,44($sp)                            \n"
		"lhu             $t8,136($s0)                           \n"
		"mtc1            $zero,$f4                              \n"
		"or              $a1,$s0,$zero                          \n"
		"andi            $t9,$t8,0x8                            \n"
		"beq             $t9,$zero,.L000184                     \n"
		"swc1            $f4,104($s0)                           \n"
		"lh              $t0,126($s0)                           \n"
		"lh              $t1,182($s0)                           \n"
		"subu            $v0,$t0,$t1                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000185                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000185                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000185:                                              \n"
		"slti            $at,$v1,14500                          \n"
		"beq             $at,$zero,.L000184                     \n"
		"lui             $at,0x42A0                             \n"
		"mtc1            $at,$f8                                \n"
		"lwc1            $f6,144($s0)                           \n"
		"c.lt.s          $f6,$f8                                \n"
		"nop                                                    \n"
		"bc1f            .L000184                               \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000183                   \n"
		"lw              $t2,44($sp)                            \n"
		".L000184:                                              \n"
		"jal             func_808641E8                          \n"
		"lw              $a0,52($sp)                            \n"
		"bne             $v0,$zero,.L000186                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,52($sp)                            \n"
		"lw              $t2,44($sp)                            \n"
		".L000183:                                              \n"
		"lb              $t3,2115($t2)                          \n"
		"beql            $t3,$zero,.L000187                     \n"
		"lw              $ra,36($sp)                            \n"
		"lhu             $t4,136($s0)                           \n"
		"andi            $t5,$t4,0x8                            \n"
		"beq             $t5,$zero,.L000188                     \n"
		"nop                                                    \n"
		"lh              $t6,126($s0)                           \n"
		"lh              $t7,182($s0)                           \n"
		"subu            $v0,$t6,$t7                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000189                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000189                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000189:                                              \n"
		"slti            $at,$v1,14500                          \n"
		"beq             $at,$zero,.L000188                     \n"
		"lui             $at,0x42A0                             \n"
		"mtc1            $at,$f16                               \n"
		"lwc1            $f10,144($s0)                          \n"
		"c.lt.s          $f10,$f16                              \n"
		"nop                                                    \n"
		"bc1f            .L000188                               \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000190                   \n"
		"addiu           $t1,$zero,8                            \n"
		".L000188:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_808647C4)                 \n"
		"lwc1            $f18,%lo(data_808647C4)($at)           \n"
		"c.lt.s          $f18,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000191                               \n"
		"nop                                                    \n"
		"lh              $t8,28($s0)                            \n"
		"addiu           $at,$zero,3                            \n"
		"lw              $t9,44($sp)                            \n"
		"beq             $t8,$at,.L000191                       \n"
		"nop                                                    \n"
		"lb              $t0,2114($t9)                          \n"
		"addiu           $at,$zero,17                           \n"
		"beq             $t0,$at,.L000191                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000190                   \n"
		"addiu           $t1,$zero,8                            \n"
		".L000191:                                              \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $t1,$zero,8                            \n"
		".L000190:                                              \n"
		"sb              $t1,1992($s0)                          \n"
		".L000186:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000187:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void func_808634F8(void) /* 5 internal, 5 external, 112 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_808634F8: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"lbu             $v0,2285($a0)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"lw              $a3,7236($a1)                          \n"
		"andi            $t7,$v0,0x80                           \n"
		"beq             $t7,$zero,.L000279                     \n"
		"andi            $t8,$v0,0xff7f                         \n"
		"lbu             $t9,2081($a0)                          \n"
		"lbu             $t1,1992($a0)                          \n"
		"sb              $t8,2285($a0)                          \n"
		"andi            $t0,$t9,0xfffd                         \n"
		"slti            $at,$t1,10                             \n"
		"bne             $at,$zero,.L000280                     \n"
		"sb              $t0,2081($a0)                          \n"
		"lui             $at,0xC080                             \n"
		"mtc1            $at,$f4                                \n"
		"beq             $zero,$zero,.L000280                   \n"
		"swc1            $f4,104($a0)                           \n"
		".L000279:                                              \n"
		"lbu             $v1,2081($s0)                          \n"
		"andi            $t2,$v1,0x2                            \n"
		"beql            $t2,$zero,.L000281                     \n"
		"lw              $ra,28($sp)                            \n"
		"lbu             $a0,177($s0)                           \n"
		"andi            $t3,$v1,0xfffd                         \n"
		"addiu           $at,$zero,13                           \n"
		"beq             $a0,$at,.L000280                       \n"
		"sb              $t3,2081($s0)                          \n"
		"addiu           $at,$zero,6                            \n"
		"beq             $a0,$at,.L000280                       \n"
		"addiu           $a1,$s0,2088                           \n"
		"lb              $t4,2056($s0)                          \n"
		"sb              $a0,2018($s0)                          \n"
		"or              $a0,$s0,$zero                          \n"
		"blezl           $t4,.L000282                           \n"
		"lbu             $t5,2117($a3)                          \n"
		"sb              $zero,2056($s0)                        \n"
		"lbu             $t5,2117($a3)                          \n"
		".L000282:                                              \n"
		"lh              $t6,138($s0)                           \n"
		"or              $a2,$zero,$zero                        \n"
		"sb              $t5,2012($s0)                          \n"
		"jal             external_func_80035650                 \n"
		"sh              $t6,50($s0)                            \n"
		"addiu           $a0,$s0,228                            \n"
		"jal             external_func_800F8A44                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"lbu             $v0,177($s0)                           \n"
		"addiu           $at,$zero,1                            \n"
		"beq             $v0,$at,.L000283                       \n"
		"addiu           $at,$zero,15                           \n"
		"beq             $v0,$at,.L000283                       \n"
		"addiu           $at,$zero,14                           \n"
		"bne             $v0,$at,.L000284                       \n"
		"or              $a0,$s0,$zero                          \n"
		".L000283:                                              \n"
		"lbu             $t7,1992($s0)                          \n"
		"addiu           $at,$zero,11                           \n"
		"beql            $t7,$at,.L000281                       \n"
		"lw              $ra,28($sp)                            \n"
		"jal             external_func_80035628                 \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80862578                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000281                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000284:                                              \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,16384                        \n"
		"beq             $v0,$zero,.L000285                     \n"
		"nop                                                    \n"
		"jal             external_func_80035628                 \n"
		"or              $a0,$s0,$zero                          \n"
		"bne             $v0,$zero,.L000286                     \n"
		"lw              $a0,36($sp)                            \n"
		"jal             external_func_80032C7C                 \n"
		"or              $a1,$s0,$zero                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80862FA8                          \n"
		"lw              $a1,36($sp)                            \n"
		"beq             $zero,$zero,.L000281                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000286:                                              \n"
		"jal             func_80862154                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000281                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000285:                                              \n"
		"jal             external_func_80035628                 \n"
		"or              $a0,$s0,$zero                          \n"
		"bne             $v0,$zero,.L000287                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_808630F0                          \n"
		"lw              $a1,36($sp)                            \n"
		"lw              $a0,36($sp)                            \n"
		"jal             external_func_80032C7C                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000281                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000287:                                              \n"
		"jal             func_80862398                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000280:                                              \n"
		"lw              $ra,28($sp)                            \n"
		".L000281:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_80862650(void) /* 6 internal, 2 external, 101 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80862650: \n"
	);
	asm(
		"addiu           $sp,$sp,-48                            \n"
		"lui             $at,0x3F80                             \n"
		"mtc1            $at,$f2                                \n"
		"mtc1            $zero,$f0                              \n"
		"sw              $ra,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"sw              $a1,52($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"mfc1            $a2,$f2                                \n"
		"mfc1            $a3,$f2                                \n"
		"mfc1            $a1,$f0                                \n"
		"addiu           $a0,$a0,104                            \n"
		"swc1            $f0,16($sp)                            \n"
		"jal             external_func_80078310                 \n"
		"sw              $t7,44($sp)                            \n"
		"lbu             $t8,276($s0)                           \n"
		"bnel            $t8,$zero,.L000203                     \n"
		"lw              $ra,36($sp)                            \n"
		"lbu             $t9,175($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t0,44($sp)                            \n"
		"bnel            $t9,$zero,.L000204                     \n"
		"lb              $t1,2115($t0)                          \n"
		"jal             func_80862FA8                          \n"
		"lw              $a1,52($sp)                            \n"
		"beq             $zero,$zero,.L000203                   \n"
		"lw              $ra,36($sp)                            \n"
		"lb              $t1,2115($t0)                          \n"
		".L000204:                                              \n"
		"beql            $t1,$zero,.L000205                     \n"
		"mtc1            $zero,$f10                             \n"
		"lhu             $t2,136($s0)                           \n"
		"andi            $t3,$t2,0x8                            \n"
		"beq             $t3,$zero,.L000206                     \n"
		"nop                                                    \n"
		"lh              $t4,126($s0)                           \n"
		"lh              $t5,182($s0)                           \n"
		"subu            $v0,$t4,$t5                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000207                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000207                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000207:                                              \n"
		"slti            $at,$v1,14500                          \n"
		"beq             $at,$zero,.L000206                     \n"
		"lui             $at,0x42A0                             \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f4,144($s0)                           \n"
		"c.lt.s          $f4,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000206                               \n"
		"nop                                                    \n"
		"jal             func_80861D50                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000208                   \n"
		"addiu           $t8,$zero,8                            \n"
		".L000206:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_808647CC)                 \n"
		"lwc1            $f8,%lo(data_808647CC)($at)            \n"
		"lw              $t6,44($sp)                            \n"
		"c.lt.s          $f8,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000209                               \n"
		"nop                                                    \n"
		"lb              $t7,2114($t6)                          \n"
		"addiu           $at,$zero,17                           \n"
		"beq             $t7,$at,.L000209                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000208                   \n"
		"addiu           $t8,$zero,8                            \n"
		".L000209:                                              \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $t8,$zero,8                            \n"
		".L000208:                                              \n"
		"beq             $zero,$zero,.L000210                   \n"
		"sb              $t8,1992($s0)                          \n"
		"mtc1            $zero,$f10                             \n"
		".L000205:                                              \n"
		"or              $a1,$s0,$zero                          \n"
		"swc1            $f10,104($s0)                          \n"
		"jal             func_808641E8                          \n"
		"lw              $a0,52($sp)                            \n"
		"bne             $v0,$zero,.L000210                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,52($sp)                            \n"
		".L000210:                                              \n"
		"lw              $ra,36($sp)                            \n"
		".L000203:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"addiu           $sp,$sp,48                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_8085FBE0(void) /* 6 internal, 3 external, 135 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_8085FBE0: \n"
	);
	asm(
		"lh              $t9,28($a2)                            \n"
		"addiu           $at,$zero,3                            \n"
		"beql            $t9,$at,.L000016                       \n"
		"lw              $ra,20($sp)                            \n"
		"lh              $t1,138($a2)                           \n"
		"or              $a0,$a2,$zero                          \n"
		"jal             func_8086194C                          \n"
		"sh              $t1,50($a2)                            \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		"slti            $at,$v0,16001                          \n"
		".L000011:                                              \n"
		"beq             $at,$zero,.L000017                     \n"
		"or              $a0,$a2,$zero                          \n"
		"lh              $a1,138($a2)                           \n"
		"lui             $t2,0x0001                             \n"
		"addu            $t2,$t2,$a3                            \n"
		"subu            $v0,$a1,$v1                            \n"
		"sll             $v0,$v0,16                             \n"
		"sra             $v0,$v0,16                             \n"
		"bltz            $v0,.L000018                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000018                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000018:                                              \n"
		"slti            $at,$v1,16001                          \n"
		"bnel            $at,$zero,.L000019                     \n"
		"lui             $at,0x42DC                             \n"
		"lw              $t2,7652($t2)                          \n"
		"andi            $t3,$t2,0x1                            \n"
		"beql            $t3,$zero,.L000020                     \n"
		"lui             $at,0x435C                             \n"
		"lh              $t4,28($a2)                            \n"
		"addiu           $at,$zero,3                            \n"
		"or              $a0,$a2,$zero                          \n"
		"beql            $t4,$at,.L000020                       \n"
		"lui             $at,0x435C                             \n"
		"jal             func_8086194C                          \n"
		"sh              $a1,50($a2)                            \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		"lui             $at,0x435C                             \n"
		".L000020:                                              \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f0,144($a2)                           \n"
		"lui             $at,0x432A                             \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1f            .L000021                               \n"
		"nop                                                    \n"
		"mtc1            $at,$f16                               \n"
		"or              $a0,$a2,$zero                          \n"
		"addiu           $a1,$zero,1820                         \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000021                               \n"
		"nop                                                    \n"
		"sw              $a2,32($sp)                            \n"
		"jal             external_func_8002E084                 \n"
		"sw              $a3,36($sp)                            \n"
		"lw              $a2,32($sp)                            \n"
		"beq             $v0,$zero,.L000015                     \n"
		"lw              $a3,36($sp)                            \n"
		"or              $a0,$a3,$zero                          \n"
		"or              $a1,$a2,$zero                          \n"
		"jal             external_func_80033A84                 \n"
		"sw              $a2,32($sp)                            \n"
		"bne             $v0,$zero,.L000015                     \n"
		"lw              $a2,32($sp)                            \n"
		"jal             func_80861B94                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000021:                                              \n"
		"jal             func_80860438                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		"lui             $at,0x42DC                             \n"
		".L000019:                                              \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f18,144($a2)                          \n"
		"or              $a0,$a2,$zero                          \n"
		"c.lt.s          $f18,$f4                               \n"
		"nop                                                    \n"
		"bc1f            .L000022                               \n"
		"nop                                                    \n"
		"sw              $a2,32($sp)                            \n"
		"sw              $a3,36($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sw              $t0,24($sp)                            \n"
		"lui             $at,%hi(data_80864774)                 \n"
		"lwc1            $f6,%lo(data_80864774)($at)            \n"
		"lw              $a2,32($sp)                            \n"
		"lw              $a3,36($sp)                            \n"
		"c.lt.s          $f6,$f0                                \n"
		"lw              $t0,24($sp)                            \n"
		"bc1fl           .L000016                               \n"
		"lw              $ra,20($sp)                            \n"
		"lw              $t5,1660($t0)                          \n"
		"andi            $t6,$t5,0x10                           \n"
		"beq             $t6,$zero,.L000023                     \n"
		"nop                                                    \n"
		"lbu             $t7,268($a2)                           \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $t7,$zero,.L000024                     \n"
		"nop                                                    \n"
		"jal             func_80861418                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000024:                                              \n"
		"jal             func_808627C4                          \n"
		"or              $a1,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000023:                                              \n"
		"jal             func_80861418                          \n"
		"or              $a0,$a2,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000022:                                              \n"
		"jal             func_8085F938                          \n"
		"or              $a1,$a3,$zero                          \n"
		"beq             $zero,$zero,.L000016                   \n"
		"lw              $ra,20($sp)                            \n"
		".L000017:                                              \n"
		"jal             func_8085F938                          \n"
		"or              $a1,$a3,$zero                          \n"
		".L000015:                                              \n"
		"lw              $ra,20($sp)                            \n"
		".L000016:                                              \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808600EC(void) /* 7 internal, 4 external, 151 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808600EC: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a1,44($sp)                            \n"
		"lw              $t7,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"addiu           $a0,$a0,392                            \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $t7,36($sp)                            \n"
		"lw              $a0,44($sp)                            \n"
		"jal             func_808641E8                          \n"
		"or              $a1,$s0,$zero                          \n"
		"bne             $v0,$zero,.L000033                     \n"
		"lw              $a0,36($sp)                            \n"
		"lui             $at,0x42C8                             \n"
		"mtc1            $at,$f6                                \n"
		"lwc1            $f4,144($s0)                           \n"
		"lh              $t8,182($a0)                           \n"
		"lh              $t9,182($s0)                           \n"
		"c.lt.s          $f4,$f6                                \n"
		"subu            $v0,$t8,$t9                            \n"
		"sll             $v0,$v0,16                             \n"
		"bc1f            .L000034                               \n"
		"sra             $v0,$v0,16                             \n"
		"lb              $t0,2115($a0)                          \n"
		"beql            $t0,$zero,.L000035                     \n"
		"lw              $v0,2024($s0)                          \n"
		"bltz            $v0,.L000036                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000036                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000036:                                              \n"
		"slti            $at,$v1,8000                           \n"
		"bnel            $at,$zero,.L000035                     \n"
		"lw              $v0,2024($s0)                          \n"
		"lh              $v0,138($s0)                           \n"
		"sh              $v0,50($s0)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sh              $v0,182($s0)                           \n"
		"lui             $at,%hi(data_80864778)                 \n"
		"lwc1            $f8,%lo(data_80864778)($at)            \n"
		"lw              $t1,36($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f8,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000037                               \n"
		"nop                                                    \n"
		"lb              $t2,2114($t1)                          \n"
		"addiu           $at,$zero,17                           \n"
		"beq             $t2,$at,.L000037                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000037:                                              \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,44($sp)                            \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000034:                                              \n"
		"lw              $v0,2024($s0)                          \n"
		".L000035:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000039                     \n"
		"addiu           $t3,$v0,-1                             \n"
		"beq             $zero,$zero,.L000033                   \n"
		"sw              $t3,2024($s0)                          \n"
		".L000039:                                              \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,5461                         \n"
		"beq             $v0,$zero,.L000040                     \n"
		"lui             $at,0x435C                             \n"
		"lwc1            $f0,144($s0)                           \n"
		"mtc1            $at,$f10                               \n"
		"lui             $at,0x4320                             \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1f            .L000041                               \n"
		"nop                                                    \n"
		"mtc1            $at,$f16                               \n"
		"nop                                                    \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000041                               \n"
		"nop                                                    \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_8086477C)                 \n"
		"lwc1            $f18,%lo(data_8086477C)($at)           \n"
		"lw              $a0,44($sp)                            \n"
		"c.lt.s          $f0,$f18                               \n"
		"nop                                                    \n"
		"bc1f            .L000041                               \n"
		"nop                                                    \n"
		"jal             external_func_80033A84                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000042                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80861B94                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000042:                                              \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,44($sp)                            \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000041:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_80864780)                 \n"
		"lwc1            $f4,%lo(data_80864780)($at)            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f4,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000043                               \n"
		"nop                                                    \n"
		"jal             func_80860438                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000043:                                              \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,44($sp)                            \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000040:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_80864784)                 \n"
		"lwc1            $f6,%lo(data_80864784)($at)            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000044                               \n"
		"nop                                                    \n"
		"jal             func_80860BDC                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000038                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000044:                                              \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,44($sp)                            \n"
		".L000033:                                              \n"
		"lw              $ra,28($sp)                            \n"
		".L000038:                                              \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
void data_808604FC(void) /* 9 internal, 10 external, 478 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_808604FC: \n"
	);
	asm(
		"addiu           $sp,$sp,-112                           \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s0,40($sp)                            \n"
		"lw              $t6,7236($a1)                          \n"
		"mtc1            $zero,$f2                              \n"
		"or              $s0,$a0,$zero                          \n"
		"or              $a2,$a1,$zero                          \n"
		"or              $a0,$a1,$zero                          \n"
		"or              $a1,$s0,$zero                          \n"
		"sw              $a2,116($sp)                           \n"
		"sw              $t6,84($sp)                            \n"
		"jal             func_808641E8                          \n"
		"swc1            $f2,104($sp)                           \n"
		"bne             $v0,$zero,.L000047                     \n"
		"lwc1            $f2,104($sp)                           \n"
		"lw              $t7,2024($s0)                          \n"
		"or              $a1,$s0,$zero                          \n"
		"addiu           $t8,$t7,1                              \n"
		"sw              $t8,2024($s0)                          \n"
		"swc1            $f2,104($sp)                           \n"
		"jal             external_func_80033AB8                 \n"
		"lw              $a0,116($sp)                           \n"
		"beq             $v0,$zero,.L000048                     \n"
		"lwc1            $f2,104($sp)                           \n"
		"lui             $at,0x4316                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		".L000048:                                              \n"
		"lui             $at,0x42A0                             \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f0,144($s0)                           \n"
		"addiu           $a0,$s0,104                            \n"
		"add.s           $f6,$f4,$f2                            \n"
		"lui             $a1,0xC0A0                             \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3F4C                             \n"
		"c.le.s          $f0,$f6                                \n"
		"lui             $at,0x42DC                             \n"
		"bc1fl           .L000049                               \n"
		"mtc1            $at,$f10                               \n"
		"mtc1            $zero,$f8                              \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f8,16($sp)                            \n"
		"beq             $zero,$zero,.L000050                   \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f10                               \n"
		".L000049:                                              \n"
		"addiu           $a0,$s0,104                            \n"
		"lui             $a1,0x40A0                             \n"
		"add.s           $f16,$f10,$f2                          \n"
		"lui             $a2,0x3F80                             \n"
		"lui             $a3,0x3F4C                             \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000050                               \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $zero,$f18                             \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"jal             external_func_80078310                 \n"
		"swc1            $f18,16($sp)                           \n"
		"lui             $at,0x40A0                             \n"
		".L000050:                                              \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f0,104($s0)                           \n"
		"lui             $at,0xC0A0                             \n"
		"or              $a0,$s0,$zero                          \n"
		"c.le.s          $f4,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000051                               \n"
		"mtc1            $at,$f8                                \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f6                                \n"
		"beq             $zero,$zero,.L000052                   \n"
		"swc1            $f6,104($s0)                           \n"
		"mtc1            $at,$f8                                \n"
		".L000051:                                              \n"
		"lui             $at,0xC0A0                             \n"
		"c.lt.s          $f0,$f8                                \n"
		"nop                                                    \n"
		"bc1fl           .L000053                               \n"
		"lh              $t9,28($s0)                            \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"swc1            $f10,104($s0)                          \n"
		".L000052:                                              \n"
		"lh              $t9,28($s0)                            \n"
		".L000053:                                              \n"
		"addiu           $at,$zero,3                            \n"
		"lw              $a1,116($sp)                           \n"
		"bnel            $t9,$at,.L000054                       \n"
		"lwc1            $f0,104($s0)                           \n"
		"lw              $a2,104($s0)                           \n"
		"jal             external_func_800339B8                 \n"
		"lh              $a3,50($s0)                            \n"
		"bne             $v0,$zero,.L000055                     \n"
		"lui             $at,0xBF80                             \n"
		"lwc1            $f16,104($s0)                          \n"
		"mtc1            $at,$f18                               \n"
		"nop                                                    \n"
		"mul.s           $f4,$f16,$f18                          \n"
		"swc1            $f4,104($s0)                           \n"
		".L000055:                                              \n"
		"lwc1            $f0,104($s0)                           \n"
		".L000054:                                              \n"
		"mtc1            $zero,$f6                              \n"
		"lui             $at,0x4040                             \n"
		"mtc1            $at,$f8                                \n"
		"c.le.s          $f6,$f0                                \n"
		"lui             $a0,0x0600                             \n"
		"bc1fl           .L000056                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000056                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000056:                                              \n"
		"c.lt.s          $f2,$f8                                \n"
		"nop                                                    \n"
		"bc1f            .L000057                               \n"
		"nop                                                    \n"
		"lui             $a0,0x0601                             \n"
		"jal             external_func_800A2000                 \n"
		"addiu           $a0,$a0,-32332                         \n"
		"mtc1            $v0,$f10                               \n"
		"lw              $a3,416($s0)                           \n"
		"lui             $at,0xC0C0                             \n"
		"cvt.s.w         $f16,$f10                              \n"
		"mtc1            $at,$f18                               \n"
		"addiu           $a0,$s0,392                            \n"
		"lui             $a1,0x0601                             \n"
		"addiu           $a1,$a1,-32332                         \n"
		"sw              $a0,52($sp)                            \n"
		"swc1            $f16,16($sp)                           \n"
		"sw              $zero,20($sp)                          \n"
		"addiu           $a2,$zero,0                            \n"
		"jal             external_func_800A51A0                 \n"
		"swc1            $f18,24($sp)                           \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f0,104($s0)                           \n"
		"lw              $a0,52($sp)                            \n"
		"mul.s           $f2,$f0,$f4                            \n"
		"beq             $zero,$zero,.L000058                   \n"
		"mtc1            $zero,$f6                              \n"
		".L000057:                                              \n"
		"jal             external_func_800A2000                 \n"
		"addiu           $a0,$a0,9940                           \n"
		"mtc1            $v0,$f6                                \n"
		"lw              $a3,416($s0)                           \n"
		"lui             $at,0xC080                             \n"
		"cvt.s.w         $f8,$f6                                \n"
		"mtc1            $at,$f10                               \n"
		"addiu           $a0,$s0,392                            \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,9940                           \n"
		"sw              $a0,52($sp)                            \n"
		"swc1            $f8,16($sp)                            \n"
		"sw              $zero,20($sp)                          \n"
		"addiu           $a2,$zero,0                            \n"
		"jal             external_func_800A51A0                 \n"
		"swc1            $f10,24($sp)                           \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f16                               \n"
		"lwc1            $f0,104($s0)                           \n"
		"lui             $at,%hi(data_8086478C)                 \n"
		"lwc1            $f4,%lo(data_8086478C)($at)            \n"
		"mul.s           $f18,$f0,$f16                          \n"
		"lw              $a0,52($sp)                            \n"
		"mul.s           $f2,$f18,$f4                           \n"
		"nop                                                    \n"
		"mtc1            $zero,$f6                              \n"
		".L000058:                                              \n"
		"lui             $at,0xC020                             \n"
		"c.le.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000059                               \n"
		"mtc1            $at,$f0                                \n"
		"lbu             $v0,2014($s0)                          \n"
		"lui             $at,0x4020                             \n"
		"mtc1            $at,$f0                                \n"
		"bne             $v0,$zero,.L000060                     \n"
		"addiu           $t0,$v0,1                              \n"
		"sb              $t0,2014($s0)                          \n"
		".L000060:                                              \n"
		"c.lt.s          $f0,$f2                                \n"
		"nop                                                    \n"
		"bc1f            .L000061                               \n"
		"nop                                                    \n"
		"mov.s           $f2,$f0                                \n"
		".L000061:                                              \n"
		"beq             $zero,$zero,.L000062                   \n"
		"swc1            $f2,420($s0)                           \n"
		"mtc1            $at,$f0                                \n"
		".L000059:                                              \n"
		"nop                                                    \n"
		"c.lt.s          $f2,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000062                               \n"
		"swc1            $f2,420($s0)                           \n"
		"mov.s           $f2,$f0                                \n"
		"swc1            $f2,420($s0)                           \n"
		".L000062:                                              \n"
		"lw              $a1,84($sp)                            \n"
		"lui             $at,0x42C8                             \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f8,144($s0)                           \n"
		"lh              $t2,182($s0)                           \n"
		"lh              $t1,182($a1)                           \n"
		"c.lt.s          $f8,$f10                               \n"
		"subu            $v0,$t1,$t2                            \n"
		"sll             $v0,$v0,16                             \n"
		"bc1f            .L000063                               \n"
		"sra             $v0,$v0,16                             \n"
		"lb              $t3,2115($a1)                          \n"
		"beql            $t3,$zero,.L000064                     \n"
		"lwc1            $f18,416($s0)                          \n"
		"bltz            $v0,.L000065                           \n"
		"subu            $v1,$zero,$v0                          \n"
		"beq             $zero,$zero,.L000065                   \n"
		"or              $v1,$v0,$zero                          \n"
		".L000065:                                              \n"
		"slti            $at,$v1,8000                           \n"
		"bnel            $at,$zero,.L000064                     \n"
		"lwc1            $f18,416($s0)                          \n"
		"lh              $v0,138($s0)                           \n"
		"sh              $v0,50($s0)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"sh              $v0,182($s0)                           \n"
		"lui             $at,%hi(data_80864790)                 \n"
		"lwc1            $f16,%lo(data_80864790)($at)           \n"
		"lw              $t4,84($sp)                            \n"
		"c.lt.s          $f16,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000066                               \n"
		"nop                                                    \n"
		"lb              $t5,2114($t4)                          \n"
		"addiu           $at,$zero,17                           \n"
		"beq             $t5,$at,.L000066                       \n"
		"nop                                                    \n"
		"jal             func_8086194C                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000066:                                              \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000063:                                              \n"
		"lwc1            $f18,416($s0)                          \n"
		".L000064:                                              \n"
		"trunc.w.s       $f4,$f18                               \n"
		"mfc1            $v1,$f4                                \n"
		"jal             external_func_800A49FC                 \n"
		"sw              $v1,96($sp)                            \n"
		"lwc1            $f0,420($s0)                           \n"
		"mtc1            $zero,$f6                              \n"
		"mtc1            $zero,$f16                             \n"
		"lw              $v1,96($sp)                            \n"
		"c.le.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1fl           .L000068                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000068                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000068:                                              \n"
		"lwc1            $f12,416($s0)                          \n"
		"c.le.s          $f16,$f0                               \n"
		"sub.s           $f8,$f12,$f2                           \n"
		"trunc.w.s       $f18,$f12                              \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $t9,$f18                               \n"
		"mfc1            $a0,$f10                               \n"
		"bc1fl           .L000069                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000069                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000069:                                              \n"
		"beql            $v1,$t9,.L000070                       \n"
		"lw              $t2,2024($s0)                          \n"
		"trunc.w.s       $f4,$f2                                \n"
		"mfc1            $t1,$f4                                \n"
		"nop                                                    \n"
		"addu            $v0,$t1,$v1                            \n"
		"slti            $at,$v0,2                              \n"
		"bnel            $at,$zero,.L000071                     \n"
		"slti            $at,$a0,7                              \n"
		"blez            $a0,.L000072                           \n"
		"slti            $at,$a0,7                              \n"
		".L000071:                                              \n"
		"beq             $at,$zero,.L000073                     \n"
		"slti            $at,$v0,8                              \n"
		"bne             $at,$zero,.L000073                     \n"
		".L000072:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14397                        \n"
		".L000073:                                              \n"
		"lw              $t2,2024($s0)                          \n"
		".L000070:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t3,$t2,0x1f                           \n"
		"bnel            $t3,$zero,.L000074                     \n"
		"lui             $at,0x435C                             \n"
		"jal             external_func_8002F828                 \n"
		"addiu           $a1,$zero,14392                        \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f6                                \n"
		"lw              $t4,2024($s0)                          \n"
		"mul.s           $f8,$f0,$f6                            \n"
		"trunc.w.s       $f10,$f8                               \n"
		"mfc1            $t6,$f10                               \n"
		"nop                                                    \n"
		"sll             $t7,$t6,16                             \n"
		"sra             $t8,$t7,16                             \n"
		"addu            $t9,$t4,$t8                            \n"
		"sw              $t9,2024($s0)                          \n"
		"lui             $at,0x435C                             \n"
		".L000074:                                              \n"
		"mtc1            $at,$f16                               \n"
		"lwc1            $f0,144($s0)                           \n"
		"lui             $at,0x4320                             \n"
		"c.lt.s          $f0,$f16                               \n"
		"nop                                                    \n"
		"bc1f            .L000075                               \n"
		"nop                                                    \n"
		"mtc1            $at,$f18                               \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f18,$f0                               \n"
		"nop                                                    \n"
		"bc1f            .L000075                               \n"
		"nop                                                    \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,1820                         \n"
		"beq             $v0,$zero,.L000075                     \n"
		"lw              $a0,116($sp)                           \n"
		"jal             external_func_80033A84                 \n"
		"or              $a1,$s0,$zero                          \n"
		"beq             $v0,$zero,.L000076                     \n"
		"lw              $t0,84($sp)                            \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_80864794)                 \n"
		"lwc1            $f4,%lo(data_80864794)($at)            \n"
		"c.lt.s          $f0,$f4                                \n"
		"nop                                                    \n"
		"bc1f            .L000075                               \n"
		"nop                                                    \n"
		"jal             func_80861B94                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000076:                                              \n"
		"lb              $t1,337($t0)                           \n"
		"beq             $t1,$zero,.L000075                     \n"
		"nop                                                    \n"
		"lbu             $t2,268($s0)                           \n"
		"lw              $t3,116($sp)                           \n"
		"lui             $t5,0x0001                             \n"
		"beq             $t2,$zero,.L000077                     \n"
		"addu            $t5,$t5,$t3                            \n"
		"lw              $t5,7652($t5)                          \n"
		"or              $a1,$t3,$zero                          \n"
		"or              $a0,$s0,$zero                          \n"
		"andi            $t6,$t5,0x1                            \n"
		"beq             $t6,$zero,.L000078                     \n"
		"nop                                                    \n"
		"jal             func_808627C4                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000078:                                              \n"
		"jal             func_8085FAB0                          \n"
		"lw              $a1,116($sp)                           \n"
		"beq             $zero,$zero,.L000075                   \n"
		"nop                                                    \n"
		".L000077:                                              \n"
		"jal             func_80860EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000075:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_80864798)                 \n"
		"lwc1            $f6,%lo(data_80864798)($at)            \n"
		"or              $a0,$s0,$zero                          \n"
		"c.lt.s          $f0,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000079                               \n"
		"nop                                                    \n"
		"lh              $v0,138($s0)                           \n"
		"sh              $v0,50($s0)                            \n"
		"sh              $v0,182($s0)                           \n"
		".L000079:                                              \n"
		"jal             external_func_8002E084                 \n"
		"addiu           $a1,$zero,4551                         \n"
		"bne             $v0,$zero,.L000080                     \n"
		"lui             $at,0x42DC                             \n"
		"jal             func_80860068                          \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f2                                \n"
		"nop                                                    \n"
		"mul.s           $f8,$f0,$f2                            \n"
		"add.s           $f10,$f8,$f2                           \n"
		"trunc.w.s       $f16,$f10                              \n"
		"mfc1            $t4,$f16                               \n"
		"beq             $zero,$zero,.L000047                   \n"
		"sw              $t4,2024($s0)                          \n"
		".L000080:                                              \n"
		"lwc1            $f18,144($s0)                          \n"
		"mtc1            $at,$f4                                \n"
		"nop                                                    \n"
		"c.lt.s          $f18,$f4                               \n"
		"nop                                                    \n"
		"bc1f            .L000081                               \n"
		"nop                                                    \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_8086479C)                 \n"
		"lwc1            $f6,%lo(data_8086479C)($at)            \n"
		"lw              $t8,84($sp)                            \n"
		"c.lt.s          $f6,$f0                                \n"
		"nop                                                    \n"
		"bc1f            .L000082                               \n"
		"nop                                                    \n"
		"lw              $t9,1660($t8)                          \n"
		"andi            $t0,$t9,0x10                           \n"
		"beq             $t0,$zero,.L000083                     \n"
		"nop                                                    \n"
		"lbu             $t1,268($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $t1,$zero,.L000084                     \n"
		"nop                                                    \n"
		"jal             func_80861418                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000084:                                              \n"
		"jal             func_808627C4                          \n"
		"lw              $a1,116($sp)                           \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000083:                                              \n"
		"jal             func_80861418                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000082:                                              \n"
		"jal             func_80861EC0                          \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000067                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000081:                                              \n"
		"jal             external_func_800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,%hi(data_808647A0)                 \n"
		"lwc1            $f8,%lo(data_808647A0)($at)            \n"
		"lui             $at,0x40A0                             \n"
		"c.lt.s          $f0,$f8                                \n"
		"nop                                                    \n"
		"bc1fl           .L000067                               \n"
		"lw              $ra,44($sp)                            \n"
		"mtc1            $at,$f10                               \n"
		"nop                                                    \n"
		"swc1            $f10,104($s0)                          \n"
		".L000047:                                              \n"
		"lw              $ra,44($sp)                            \n"
		".L000067:                                              \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,112                            \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x05,
	.room = 0x00,
	.flags = 0x00000015,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init, /* 8085F658 */
	.dest = dest, /* 8085F8A0 */
	.main = play, /* 80863694 */
	.draw = draw  /* 80864048 */
};
