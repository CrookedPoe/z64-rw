/***
* En_Heishi Rewrite by CrookedPoe
* MMU10 DMA Entry: 	 0x0001C940
* MMU10 Actor Entry: 0x00C4A2B0
***/

#include <z64ovl/mm/u10.h>

#define ACT_ID 0x026D
#define OBJ_ID 0x01B6

/*** Display Lists ***/
#define DL_UNK0 		 0x06000630
#define DL_UNK1 		 0x06000768
#define DL_TORSO 		 0x06009EB0
#define DL_HEAD 		 0x0600A1A8
#define DL_RSHOULDER 0x0600A678
#define DL_RFOREARM  0x0600A768
#define DL_RHAND 		 0x0600A9A8 /* Right Hand + Spear */
#define DL_LSHOULDER 0x0600ADE0
#define DL_LFOREARM  0x0600AED0
#define DL_LHAND 		 0x0600B120
#define DL_WAIST 		 0x0600B438
#define DL_RTHIGH 	 0x0600B5B0
#define DL_RSHIN 		 0x0600B698
#define DL_RFOOT 	   0x0600B988
#define DL_LTHIGH 	 0x0600BAD0
#define DL_LSHIN 		 0x0600BBB8
#define DL_LFOOT 		 0x0600BEB8

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
    z64_actor_t 		 actor;  /* 0x0000, size 0x0144 */
		uint16_t 				 unk144; /* 0x0144, size 0x0002 */
		uint8_t 				 unk146; /* 0x0146, size 0x0001 */
		PADDING(1);              /* 0x0147, size 0x0001 */
		uint32_t 				 unk148; /* 0x0148, size 0x0004 */
		PADDING(0x18);           /* 0x014C, size 0x0018 */
		uint32_t 				 unk164; /* 0x0164, size 0x0004 */
    PADDING(0xEC);           /* 0x0168, size 0x00EC */
    z64_actorfunc_t *unk254; /* 0x0254, size 0x0004 */
		vec3s_t 				 unk258; /* 0x0258, size 0x0006 */
		int16_t 				 unk25E; /* 0x025E, size 0x0002 */
    int 						 unk260; /* 0x0260, size 0x0004 */
		int 						 unk264; /* 0x0264, size 0x0004 */
		vec3s_t 				 unk268; /* 0x0268, size 0x0006 */
    PADDING(0x02);           /* 0x026E, size 0x0002 */
		int16_t 				 unk270; /* 0x0270, size 0x0002 */
    int16_t 				 unk272; /* 0x0272, size 0x0002 */
    float 					 unk274; /* 0x0274, size 0x0004 */
    uint16_t 				 unk278; /* 0x0278, size 0x0002 */
		PADDING(0x0A);           /* 0x027A, size 0x000A */
		z64_capsule_t		*unk284; /* 0x0284, size 0x0004 */
		PADDING(0x48);           /* 0x0288, size 0x0048 */
} entity_t; 								 /* 0x02D0 */

/*** external functions ***/
extern void external_func_800E11EC(z64_global_t *gl, z64_capsule_t *collision); /* Previously actor_capsule_free */
asm("external_func_800E11EC = 0x800E11EC");

extern void external_func_8012C28C(z64_gfx_t *gfx);
asm("external_func_8012C28C = 0x8012C28C");

extern void external_func_80133F28(z64_global_t *global, u32 a, u32 b, u32 c, void *callback0, void *callback1, z64_actor_t *actor);
asm("external_func_80133F28 = 0x80133F28");

extern uint16_t external_func_80134748(u32 a0);
asm("external_func_80134748 = 0x80134748");

extern void external_func_801373E8(void *skelanime, u32 animation, f32 playback_speed, f32 unk0, f32 frame_count, u8 unk_1, f32 transition_rate);
asm("external_func_801373E8 = 0x801373E8");


/*** function prototypes ***/
void data_80BE9214(entity_t *en, z64_global_t *gl); /* 0 internal, 0 external, 4 lines */
void data_80BE8F20(entity_t *en, z64_global_t *gl); /* 1 internal, 4 external, 96 lines */
void data_80BE9224(void); /* 1 internal, 9 external, 92 lines */

/* rewritten */
void func_80BE9148(entity_t *en, z64_global_t *gl); /* 0 internal, 0 external, 40 lines */
void data_80BE93D8(entity_t *en, z64_global_t *gl); /* 0 internal, 2 external, 22 lines */
void data_80BE9090(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 11 lines */
int data_80BE9380(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en); /* 0 internal, 0 external, 23 lines */
void func_80BE90BC(entity_t *en, int anim_index); /* 0 internal, 2 external, 35 lines */
void func_80BE91DC(entity_t *en); /* 1 internal, 0 external, 14 lines */


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
void data_80BE9214(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 4 lines */
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

int data_80BE9380(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en) /* 0 internal, 0 external, 23 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80BE9380: \n"
	);

	if (target_limb == (LIMB_HEAD + 1))
	{
		limb_rot->x += en->unk258.y;
		limb_rot->y += en->unk258.x;
		limb_rot->z += en->unk258.z;
	}
	return 0;
}

void func_80BE9148(entity_t *en, z64_global_t *gl) /* 0 internal, 0 external, 40 lines */
{
    /* Simplified by <z64.me> */
    asm(
        ".set at        \n"
        ".set reorder   \n"
        ".Lfunc_80BE9148: \n"
    );

    en->unk260 = 0;
    if (en->actor.dist_from_link_xz < 200.0f)
    {
        int16_t temp_v0;

        temp_v0 = (en->unk272 - en->actor.speedRot.y) & 0xFFFF;

        if (ABS(temp_v0) < ROT16(110))
        {
            en->unk260 = (en->unk272 - en->actor.speedRot.y);
            if (en->unk260 >= ROT16(55))
            {
                en->unk260 = ROT16(55);
                return;
            }
            en->unk260 = MAX(en->unk260, ROT16(-55));
        }
    }
}

void data_80BE9090(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 11 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80BE9090: \n"
	);
	external_func_800E11EC(gl, en->unk284);
}

void data_80BE93D8(entity_t *en, z64_global_t *gl) /* 0 internal, 2 external, 22 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldata_80BE93D8: \n"
	);

	external_func_8012C28C(gl->common.gfx_ctxt);
	external_func_80133F28(gl, en->unk148, en->unk164, en->unk146, data_80BE9380, 0, &en->actor);
}

void func_80BE90BC(entity_t *en, int anim_index) /* 0 internal, 2 external, 35 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lfunc_80BE90BC: \n"
	);

  en->unk264 = anim_index;
  en->unk274 = (float)external_func_80134748(data_80BE947C[anim_index]);
  external_func_801373E8(&en->unk144, data_80BE947C[en->unk264], 1.0f, 0, en->unk274, data_80BE9490[en->unk264], -10.0f);
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
	en->unk254 = (z64_actorfunc_t *)data_80BE9214;
}
void data_80BE8F20(entity_t *en, z64_global_t *gl) /* 1 internal, 4 external, 96 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80BE8F20: \n"
	);
	/* Debug Instance Address */
  uint32_t * _inst = (uint32_t *)0x80702050;
  *_inst = (uint32_t)en;
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
		"jal             0x800B670C                 \n"
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
	.number = ACT_ID,
	.type = NPC,
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
