/***
* Bg_Lotus Rewrite by CrookedPoe <nickjs.site>
* MMU10 DMA Entry:   0x0001BE50
* MMU10 Actor Entry: 0x00C48C30
***/

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

/*** external functions ***/
extern int external_func_80086FA0(void);
asm("external_func_80086FA0 = 0x80086FA0");

extern float external_func_800C411C(uint32_t gl830, void *floorpoly, uint32_t sp2C, z64_actor_t *actor, vec3f_t *pos);
asm("external_func_800C411C = 0x800C411C");

extern void external_func_800C6314(z64_global_t *gl, uint32_t gl880, uint32_t *collision);
asm("external_func_800C6314 = 0x800C6314");

extern void external_func_800CA1E8(z64_global_t *gl, uint32_t gl830, float a, float b, uint32_t c);
asm("external_func_800CA1E8 = 0x800CA1E8");

extern void external_func_800CAE34(z64_global_t *gl, z64_actor_t *actor, uint32_t collision);
asm("external_func_800CAE34 = 0x800CAE34");

extern float external_func_801794EC(float a0);
asm("external_func_801794EC = 0x801794EC");

/*** function prototypes ***/
void dest(entity_t *en, z64_global_t *gl); /* Confirmed */
void draw(entity_t *en, z64_global_t *gl); /* Confirmed */
void play(entity_t *en, z64_global_t *gl); /* Confirmed */
void func_80AD6830(entity_t *en); /* Confirmed */
void data_80AD6B68(entity_t *en, z64_global_t *gl); /* Confirmed */
void init(entity_t *en, z64_global_t *gl); /* Confirmed */
void data_80AD6A88(entity_t *en, z64_global_t *gl); /* Confirmed */
void data_80AD68DC(entity_t *en, z64_global_t *gl); /* 1 internal, 6 external, 115 lines */


/*** variables ***/
const uint32_t data_80AD6D10[] =
{
	0x48580064,
	0x00000000,
	0x00000000,
	0x00000000,
};
const float data_80AD6D30 = (float)0x3D860A92;


/*** functions ***/
void dest(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);

	dynapoly_free(gl, AADDR(gl, 0x0880), &en->dynap_id);
}

void draw(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	draw_static_dlist_opa(gl, DL_LOTUS);
}

void play(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lplay: \n"
	);

	external_func_800CA1E8(gl, (uint32_t)AADDR(gl, 0x0830), en->actor.pos_2.x, en->actor.pos_2.z, (uint32_t)&en->unk160);
	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, gl);
}

void func_80AD6830(entity_t *en)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		//".Lfunc_80AD6830: \n"
	);

	if (en->actor.variable == 0)
	{
		float _tf2 = external_func_801794EC(en->unk166 * 0.7854) * ((0.014 * (en->unk166 / 8.0f)) + 0.01f);
		en->actor.scale.x = ((_tf2 + 1.0f) * 0.1f);
		en->actor.scale.z = ((1.0f - _tf2) * 0.1f);
	}
}

void data_80AD6B68(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80AD6B68: \n"
	);

	if (en->unk166 < 1)
	{
		if ((100.0f < en->actor.dist_from_link_xz) && (en->actor.unk_0xEC.z < 0))
		{
			en->actor.draw_proc = &draw;
			external_func_800C6314(gl, (uint32_t)AADDR(gl, 0x0880), &en->dynap_id);
			actor_set_scale(&en->actor, 0.1f);
			if (en->unk160 < en->actor.floor_height)
				en->actor.pos_2.y = en->actor.floor_height;
			else
				en->actor.pos_2.y = en->unk160;
			en->actor.flags &= 0xFFFFFFEF;
			en->unk168 = 96;
			en->playfunc = (z64_actorfunc_t *)data_80AD68DC;
			en->actor.pos_2.x = en->actor.pos_1.x;
			en->actor.pos_2.z = en->actor.pos_1.z;
		}
	}
	else
		en->unk166 -= 1;
}

void init(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit: \n"
	);

	/* This feels kind of gross. */
	uint32_t _sp;
	register unsigned sp asm("29");
	asm("" : "=r" (_sp));
	/* But it seems like it's necessary. */
	actor_init_dynapoly(&en->actor, data_80AD6D10);
	actor_dynapoly_set_move(&en->actor, DPM_PLAYER);
	external_func_800CAE34(gl, &en->actor, DP_COLLIDE);
	en->actor.floor_height = external_func_800C411C((uint32_t)AADDR(gl, 0x0830), &en->actor.floor_poly, (_sp + 0x2C), &en->actor, &en->actor.pos_2);
	en->unk168 = 96;
	en->actor.speedRot.y = (int16_t)(external_func_80086FA0() >> 0x10);
	en->playfunc = (z64_actorfunc_t*)data_80AD68DC;
}

void data_80AD6A88(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80AD6A88: \n"
	);

	if (en->unk160 < en->actor.pos_2.y)
	{
		en->actor.pos_2.y = en->unk160;
	}
	en->actor.pos_2.y -= 1.0f;
	if (en->actor.pos_2.y <= en->actor.floor_height)
	{
		en->actor.pos_2.y = en->actor.floor_height;
		en->unk166 = 0;
	}
	if (en->unk166 > 0)
	{
		en->unk166 -= 1;
		func_80AD6830(en);
		return;
	}
	if ((math_approxf(&en->actor.scale.x, 0, 0.005f)) != 0)
	{
		en->actor.draw_proc = 0;
		en->unk166 = 100;
		external_func_8003EBF8(gl, (uint32_t)AADDR(gl, 0x0880), en->dynap_id);
		en->playfunc = (z64_actorfunc_t*)data_80AD6B68;
	}
	en->actor.scale.z = en->actor.scale.x;
}

void data_80AD68DC(entity_t *en, z64_global_t *gl)
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
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
