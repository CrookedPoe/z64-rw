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
    z64_actor_t 		 actor;  		/* 0x0000, size 0x0144 */
		z64_skelanime_t  skelanime; /* 0x0144, size 0x0040 */
		uint32_t         unk184; 		/* 0x0184, size 0x0004 */
		uint8_t          unk188; 		/* 0x0188, size 0x0001 */
		PADDING(0x65);           		/* 0x0189, size 0x0065 */
		uint8_t          unk1EE;    /* 0x01EE, size 0x0001 */
		PADDING(0x65);              /* 0x01EF, size 0x0065 */
    z64_actorfunc_t *unk254; 		/* 0x0254, size 0x0004 */
		vec3s_t 				 head_rot; 	/* 0x0258, size 0x0006 */
		int16_t 				 unk25E; 		/* 0x025E, size 0x0002 */
    int16_t 				 unk260; 		/* 0x0260, size 0x0002 */
		int16_t 				 unk262; 		/* 0x0262, size 0x0002 */
		int16_t 				 unk264; 		/* 0x0264, size 0x0002 */
		int16_t 				 unk266; 		/* 0x0266, size 0x0002 */
		vec3s_t 				 unk268; 		/* 0x0268, size 0x0006 */
    PADDING(0x02);           		/* 0x026E, size 0x0002 */
		int16_t 				 unk270; 		/* 0x0270, size 0x0002 */
    int16_t 				 unk272; 		/* 0x0272, size 0x0002 */
    float 					 unk274; 		/* 0x0274, size 0x0004 */
    uint16_t 				 unk278; 		/* 0x0278, size 0x0002 */
		PADDING(0x0A);           		/* 0x027A, size 0x000A */
		z64_capsule_t		 collision; /* 0x0284, size 0x004C */
} entity_t; 								 		/* 0x02D0 */

/*** external functions ***/
extern void external_func_800B6A88(z64_actor_t *actor);
asm("external_func_800B6A88 = 0x800B6A88");

extern void external_func_800B78B8(z64_global_t *global, z64_actor_t *actor, f32 below, f32 radius, f32 above, u32 flags);
asm("external_func_800B78B8 = 0x800B78B8");

extern int32_t external_func_800FFEBC(int16_t rot, int32_t unk0, int16_t unk1, int32_t unk2, int unk3);
asm("external_func_800FFEBC = 0x800FFEBC");

extern void external_func_8012C28C(z64_gfx_t *gfx);
asm("external_func_8012C28C = 0x8012C28C");

extern uint16_t external_func_80134748(u32 a0);
asm("external_func_80134748 = 0x80134748");


/*** function prototypes ***/
void data_80BE9214(entity_t *en, z64_global_t *gl); /* 0 internal, 0 external, 4 lines */
void play(entity_t *en, z64_global_t *gl); /* 1 internal, 9 external, 92 lines */

/* rewritten */
void heishi_limit_rotation(entity_t *en); /* 0 internal, 0 external, 40 lines */
void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 2 external, 22 lines */
void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 11 lines */
int heishi_callback_limb_rotation(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en); /* 0 internal, 0 external, 23 lines */
void heishi_change_animation(entity_t *en, int anim_index); /* 0 internal, 2 external, 35 lines */
void func_80BE91DC(entity_t *en); /* 1 internal, 0 external, 14 lines */
void init(entity_t *en, z64_global_t *gl); /* 1 internal, 4 external, 96 lines */


/*** variables ***/
const z64_capsule_init_t cylinder =
{
	.cso_0x00 = 0x0A,
	.cso_0x01 = 0x00,
	.cso_0x01_02 = 0x00,
	.unk_0x12 = 0x09,
	.unk_0x12_2 = 0x20,
	.cso_0x05 = 0x01,
	.cso_0x08 = 0x00,
	.cso_0x0C = 0x00000000,
	.damage_type = 0x00,
	.damage_amount = 0x00,
	.cso_0x14 = 0xF7CFFFFF,
	.cso_0x18 = 0x00,
	.cso_0x19 = 0x00,
	.cso_0x1C = 0x00,
	.cso_0x1D = 0x01,
	.cso_0x1E = 0x00,
	.radius = 0x0014,
	.height = 0x003C,
	.cso_0x24 = 0x0000,
	.pos = {0, 0, 0}
};

const uint32_t animations[] =
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

int heishi_callback_limb_rotation(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en) /* 0 internal, 0 external, 23 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lheishi_callback_limb_rotation: \n"
	);

	if (target_limb == (LIMB_HEAD + 1))
	{
		limb_rot->x += en->head_rot.y;
		limb_rot->y += en->head_rot.x;
		limb_rot->z += en->head_rot.z;
	}
	return 0;
}

void heishi_limit_rotation(entity_t *en) /* 0 internal, 0 external, 40 lines */
{
    /* Simplified by <z64.me> */
    asm(
        ".set at        \n"
        ".set reorder   \n"
        /*".Lheishi_limit_rotation: \n"*/
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

void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 11 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);
	actor_capsule_free(gl, &en->collision);
}

void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 2 external, 22 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	external_func_8012C28C(gl->common.gfx_ctxt);
	skelanime_draw_mtx(gl, en->skelanime.limb_index, en->skelanime.unk5, en->skelanime.dlist_count, heishi_callback_limb_rotation, 0, &en->actor);
}

void heishi_change_animation(entity_t *en, int anim_index) /* 0 internal, 2 external, 35 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lheishi_change_animation: \n"
	);

  en->unk264 = anim_index;
  en->unk274 = (float)external_func_80134748(animations[anim_index]);
  actor_anime_change(&en->skelanime, animations[en->unk264], 1.0f, 0, en->unk274, data_80BE9490[en->unk264], -10.0f);
}

void func_80BE91DC(entity_t *en) /* 1 internal, 0 external, 14 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		/*".Lfunc_80BE91DC: \n"*/
	);

	heishi_change_animation(en, 0);
	en->unk278 = 0;
	en->unk254 = (z64_actorfunc_t *)data_80BE9214;
}

void init(entity_t *en, z64_global_t *gl)
{
  asm(
    ".set at        \n"
    ".set reorder   \n"
    ".Linit: \n"
  );

  actor_init_shadow(&en->actor.rot_2, 0, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 25.0f);
  skelanime_init_mtx(gl, &en->skelanime, SKL, ANIM4, en->unk188, en->unk1EE, 0x11);
  en->actor.mass = 0xFF;
  en->unk268.x = en->actor.variable;
  en->unk272 = en->actor.speedRot.y;

  uint8_t  _t1 = AVAL(SAVE_CONTEXT, uint8_t, 0x0F37);
  uint32_t _t2 = AVAL(SAVE_CONTEXT, uint32_t, 0x0018);
  uint32_t _t3 = AVAL(SAVE_CONTEXT, uint32_t, 0x0010);

  if (en->actor.variable == 0)
  {
    en->unk268.z = 1;

    if (((_t1 & 0x80) == 0) && ((_t2 != 3) || (_t3 == 0)))
          actor_kill(&en->actor);
  }
  else
  {
    en->collision.radius = 0x001E;
    en->collision.height = 0x003C;
    en->collision.unk_0x44 = 0;

    if (((_t1 & 0x80) != 0) || ((_t2 == 3) && (_t3 != 0)))
          actor_kill(&en->actor);
  }

  en->actor.unk_02_ = 6;
  en->actor.gravity = -3.0f;
  actor_capsule_init(gl, &en->collision, &en->actor, &cylinder);
  en->actor.flags |= 0x08000000;
  func_80BE91DC(en);
}

void play(entity_t *en, z64_global_t *gl)
{
    asm(
      ".set at        \n"
      ".set reorder   \n"
      ".Lplay: \n"
    );

    actor_anime_frame_update_mtx(&en->skelanime);
    if (en->unk270 != 0)
    {
        en->unk270 -= 1;
    }
    en->actor.rot_2.y = en->actor.speedRot.y;
    if (en->unk268.x != 0)
    {
        uint32_t _t1 = AVAL(SAVE_CONTEXT, uint32_t, 0x0018);
        uint32_t _t2 = AVAL(SAVE_CONTEXT, uint32_t, 0x0010);

        if (_t1 == 3)
        {
            if (_t2 != 0)
            {
                actor_kill(&en->actor);
                return;
            }
        }
    }
		z64_actorfunc_t *playfunc = en->unk254;
    playfunc(en, gl);
    external_func_800B6A88(&en->actor);
    external_func_800B78B8(gl, &en->actor, 20.0f, 20.0f, 50.0f, 0x1D);
    actor_set_scale(&en->actor, 0.01f);
    if (en->unk268.z != 0)
    {
        heishi_limit_rotation(en);
    }
    actor_set_height(&en->actor, 60.0f);
    external_func_800FFEBC(en->head_rot.y, en->unk260, 1, 3000, 0);
    external_func_800FFEBC(en->head_rot.x, en->unk25E, 1, 1000, 0);
    actor_capsule_update(&en->actor, &en->collision);
    actor_collision_check_set_ot(gl, AADDR(gl, 0x18884), &en->collision);
}

const z64_actor_init_t init_vars = {
	.number = ACT_ID,
	.type = NPC,
	.room = 0x00,
	.flags = 0x00000009,
	.object = OBJ_ID,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
