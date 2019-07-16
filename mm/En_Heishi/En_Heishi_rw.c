#include <z64ovl/mm/u10.h>

#define OBJ_ID 438

/*** Skeleton ***/
#define SKL            0x0600D640
#define LIMB_ROOT      00
#define LIMB_WAIST     01
#define LIMB_LTHIGH    02
#define LIMB_LSHIN     03
#define LIMB_LFOOT     04
#define LIMB_RTHIGH    05
#define LIMB_RSHIN     06
#define LIMB_RFOOT     07
#define LIMB_TORSO     08
#define LIMB_LSHOULDER 09
#define LIMB_LFOREARM  10
#define LIMB_LHAND 		 11
#define LIMB_RSHOULDER 12
#define LIMB_RFOREARM  13
#define LIMB_RHAND     14
#define LIMB_HEAD      15

/*** Animations ***/
#define ANIM0 0x06000A54 /* Idling, hand over heart */
#define ANIM1 0x060020D8 /* Sitting, drinking from bottle */
#define ANIM2 0x06002A84 /* Cheering */
#define ANIM3 0x06003380 /* Sitting, reaching out */
#define ANIM4 0x06003BFC /* Sitting, waving */
#define ANIM5 0x06004770 /* Getting up off of the ground */
#define ANIM6 0x06004AC0 /* Turning on Mido mode */
#define ANIM7 0x06005320 /* Wafting away fart */
#define ANIM8 0x060057BC /* Transition: Impeding your progress */
#define ANIM9 0x06005D28 /* Idle: Impeding your progress */
#define ANIMA 0x060064C0 /* Idle: Impeding your progress more */
#define ANIMB 0x06006C18 /* Idle: Standing with hand on hip */
#define ANIMC 0x0600DC7C /* Idle: Standing with hand on hip, but looking down */

typedef struct {
    z64_actor_t actor;       /* 0x0000, size 0x0144 */
		uint16_t *unk144;        /* 0x0144, size 0x0002 */
		uint8_t unk146;          /* 0x0146, size 0x0001 */
		PADDING(1);              /* 0x0147, size 0x0001 */
		uint32_t unk148;         /* 0x0148, size 0x0004 */
		PADDING(0x18);           /* 0x014C, size 0x0018 */
		uint32_t unk164;         /* 0x0164, size 0x0004 */
    PADDING(0xEC);           /* 0x0168, size 0x00EC */
    z64_actorfunc_t *unk254; /* 0x0254, size 0x0004 */
		int16_t unk258;          /* 0x0258, size 0x0002 */
		int16_t unk25A;          /* 0x025A, size 0x0002 */
    PADDING(2);              /* 0x025C, size 0x0002 */
		int16_t unk25E;          /* 0x025E, size 0x0002 */
    int16_t unk260;          /* 0x0260, size 0x0002 */
		PADDING(6);              /* 0x0262, size 0x0006 */
		int16_t unk268;          /* 0x0268, size 0x0002 */
		int16_t unk26A;          /* 0x026A, size 0x0002 */
		int16_t unk26C;          /* 0x026C, size 0x0002 */
    PADDING(0x02);           /* 0x026E, size 0x0002 */
		int16_t unk270;          /* 0x0270, size 0x0002 */
    int16_t unk272;          /* 0x0272, size 0x0002 */
    PADDING(4);              /* 0x0274, size 0x0004 */
    uint16_t unk278;         /* 0x0278, size 0x0002 */
		PADDING(0x0A);           /* 0x027A, size 0x000A */
		void *unk284;         	 /* 0x0284, size 0x0004 */
    PADDING(0x48);           /* 0x0288, size 0x0048 */
} entity_t; /* 02D0 */


extern void external_func_800E11EC(z64_global_t *gl, uint32_t *collision); /* Previously actor_capsule_free */
asm("external_func_800E11EC = 0x800E11EC");

extern void external_func_8012C28C(z64_gfx_t *gfx);
asm("external_func_8012C28C = 0x8012C28C");

extern void external_func_80133F28(z64_global_t *global, u32 a, u32 b, u32 c, void *callback0, void *callback1, z64_actor_t *actor);
asm("external_func_80133F28 = 0x80133F28");

extern void external_func_800B670C(z64_actor_t *actor);
asm("external_func_800B670C = 0x800B670C");

extern void external_func_800B6A88(z64_actor_t *actor);
asm("external_func_800B6A88 = 0x800B6A88");

extern void external_func_800B78B8(z64_global_t *global, z64_actor_t *actor, f32 below, f32 radius, f32 above, u32 flags);
asm("external_func_800B78B8 = 0x800B78B8");

extern void external_func_800B67E0(z64_actor_t *actor, f32 scale);
asm("external_func_800B67E0 = 0x800B67E0");

extern void external_func_800B675C(z64_actor_t *actor, f32 height);
asm("external_func_800B675C = 0x800B675C");

extern int32_t external_func_800FFEBC(int16_t *rot, int16_t unk0, int16_t unk1, int32_t unk2, int unk3);
asm("external_func_800FFEBC = 0x800FFEBC");

extern void external_func_800E7DF8(z64_actor_t *actor, void *collision);
asm("external_func_800E7DF8 = 0x800FFEBC");

extern void external_func_800E2928(z64_global_t *global, void *simple_body_groups, z64_capsule_t *collision);
asm("external_func_800E2928 = 0x800E2928");

extern void external_func_80136CD0(void *skelanime);
asm("external_func_80136CD0 = 0x80136CD0");

/*** function prototypes ***/
void data_80BE9214(void); /* 0 internal, 0 external, 4 lines */
void data_80BE9380(void); /* 0 internal, 0 external, 23 lines */
int16_t func_80BE9148(entity_t *en, z64_global_t *gl); /* 0 internal, 0 external, 40 lines */
void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 11 lines */
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 2 external, 22 lines */
void func_80BE90BC(entity_t *en, int unk0); /* 0 internal, 2 external, 35 lines */
void func_80BE91DC(entity_t *en); /* 1 internal, 0 external, 14 lines */
void data_80BE8F20(void); /* 1 internal, 4 external, 96 lines */
void play(entity_t *en, z64_global_t *gl); /* 1 internal, 9 external, 92 lines */


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
	ANIMB,
	ANIM2,
	ANIM4,
	ANIM3,
	ANIM5
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

int16_t func_80BE9148(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 40 lines */
{
	/* Simplified by <z64.me>*/
	asm(
		".set at        \n"
		".set reorder   \n"
		/*".Lfunc_80BE9148: \n"*/
	);

	int16_t temp_v0_2;
	int16_t temp_v0;
	int phi_v1;

	temp_v0 = (en->unk272 - en->actor.speedRot.y) & 0xFFFF;
	phi_v1 = ABS(temp_v0);
	en->unk260 = 0;
	if (en->actor.dist_from_link_xz < 200.0f)
	{
			if (phi_v1 < ROT16(110))
			{
					en->unk260 = (en->unk272 - en->actor.speedRot.y);
					if (en->unk260 >= ROT16(55))
					{
							en->unk260 = ROT16(55);
							return en->unk260;
					}
					en->unk260 = MAX(en->unk260, ROT16(-55));
			}
	}
	return temp_v0;
}

void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 11 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);
	external_func_800E11EC(gl, AADDR(en, 0x0284));
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 2 external, 22 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	external_func_8012C28C(gl->common.gfx_ctxt);
	external_func_80133F28(gl, en->unk148, en->unk164, en->unk146, data_80BE9380, 0, &en->actor);
}

void func_80BE90BC(entity_t *en, int unk0) /* 0 internal, 2 external, 35 lines */
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

void func_80BE91DC(entity_t *en) /* 1 internal, 0 external, 14 lines */
{
    asm(
        ".set at        \n"
        ".set reorder   \n"
        ".Lfunc_80BE91DC: \n"
    );
    func_80BE90BC(en, 0);
    en->unk278 = 0;
    en->unk254 = (z64_actorfunc_t*)data_80BE9214;
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
		"jal             0x800B670C                 \n"
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
		"jal             0x800B670C                 \n"
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
void play(entity_t *en, z64_global_t *gl) /* 1 internal, 9 external, 92 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lplay: \n"
	);
    external_func_80136CD0(&en->unk144); /* anime_update_frame */
    if (en->unk270 != 0)
    {
        en->unk270 -= 1;
    }
    en->actor.rot_2.y = en->actor.speedRot.y;
    if (en->unk268 != 0)
    {
        if ((AVAL(SAVE_CONTEXT, uint8_t, 0x0018)) == 3)
        {
            if ((AVAL(SAVE_CONTEXT, uint8_t, 0x0010)) != 0)
            {
                external_func_800B670C(&en->actor); /* actor_kill */
                return;
            }
        }
    }
		z64_actorfunc_t *playfunc = en->unk254;
    playfunc(en, gl);
    external_func_800B6A88(&en->actor); /* Function to move in direction (0x32) at set velocity (0x68) */
    external_func_800B78B8(gl, &en->actor, 20.0f, 20.0f, 50.0f, 0x1D); /* possibly primary actor collision call */
    external_func_800B67E0(&en->actor, 0.01f); /* actor_set_scale */
    if (en->unk26C != 0)
    {
        func_80BE9148(en, gl);
    }
    external_func_800B675C(&en->actor, 60.0f); /* actor_set_height */
    external_func_800FFEBC(&en->unk25A, en->unk260, 1, 0x0BB8, 0);
    external_func_800FFEBC(&en->unk258, en->unk25E, 1, 0x03E8, 0);
    external_func_800E7DF8(&en->actor, en->unk284); /* actor_capsule_update */
    external_func_800E2928(gl, AADDR(gl, 0x18884), en->unk284); /* Set to collision pool OT*/
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
	.dest = dest,
	.main = play,
	.draw = draw
};
