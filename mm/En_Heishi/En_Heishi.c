/***
* En_Heishi Rewrite by CrookedPoe <nickjs.site> and Dr. Disco <z64.me>
* MMU10 DMA Entry: 	 0x0001C940
* MMU10 Actor Entry: 0x00C4A2B0
***/

#include <z64ovl/mm/u10.h>

#define ACT_ID 0x026D
#define OBJ_ID 0x01B6

/*** Display Lists ***/
#define DL_UNK0      0x06000630
#define DL_UNK1      0x06000768
#define DL_TORSO     0x06009EB0
#define DL_HEAD      0x0600A1A8
#define DL_RSHOULDER 0x0600A678
#define DL_RFOREARM  0x0600A768
#define DL_RHAND     0x0600A9A8 /* Right Hand + Spear */
#define DL_LSHOULDER 0x0600ADE0
#define DL_LFOREARM  0x0600AED0
#define DL_LHAND     0x0600B120
#define DL_WAIST     0x0600B438
#define DL_RTHIGH    0x0600B5B0
#define DL_RSHIN     0x0600B698
#define DL_RFOOT     0x0600B988
#define DL_LTHIGH    0x0600BAD0
#define DL_LSHIN     0x0600BBB8
#define DL_LFOOT     0x0600BEB8

/*** Skeleton ***/
#define SKL            0x0600D640
#define LIMB_ROOT      0x00
#define LIMB_WAIST     0x01
#define LIMB_LTHIGH    0x02
#define LIMB_LSHIN     0x03
#define LIMB_LFOOT     0x04
#define LIMB_RTHIGH    0x05
#define LIMB_RSHIN     0x06
#define LIMB_RFOOT     0x07
#define LIMB_TORSO     0x08
#define LIMB_LSHOULDER 0x09
#define LIMB_LFOREARM  0x0A
#define LIMB_LHAND     0x0B
#define LIMB_RSHOULDER 0x0C
#define LIMB_RFOREARM  0x0D
#define LIMB_RHAND     0x0E
#define LIMB_HEAD      0x0F

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
  z64_actor_t      actor;
	z64_skelanime_t  skelanime;
	uint32_t         unk184;
	uint8_t          unk188;
	PADDING(0x65);
	uint8_t          unk1EE;
	PADDING(0x65);
	vec3s_t          head_rot;
	int16_t          unk25E;
  int16_t          unk260;
	int16_t          unk262;
	int16_t          unk264;
	int16_t          unk266;
	int16_t          unk268;
  int16_t          unk26A;
  int16_t          unk26C;
  PADDING(0x02);
	int16_t          unk270;
  int16_t          unk272;
  uint16_t         unk278;
	PADDING(0x0A);
	z64_capsule_t    collision;
} entity_t;


/*** function prototypes ***/
static void heishi_limit_rotation(entity_t *en); /* 0 internal, 0 external, 40 lines */
static void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 2 external, 22 lines */
static void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 11 lines */
static int heishi_callback_limb_rotation(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en); /* 0 internal, 0 external, 23 lines */
static void heishi_change_animation(entity_t *en, int anim_index); /* 0 internal, 2 external, 35 lines */
static void func_80BE91DC(entity_t *en); /* 1 internal, 0 external, 14 lines */
static void init(entity_t *en, z64_global_t *gl); /* 1 internal, 4 external, 96 lines */
static void play(entity_t *en, z64_global_t *gl); /* 1 internal, 9 external, 92 lines */


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
	.cso_0x1D = 0x00,
	.cso_0x1E = 0x01,
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
static int heishi_callback_limb_rotation(int a0, int target_limb, int a2, int a3, vec3s_t *limb_rot, entity_t *en) /* 0 internal, 0 external, 23 lines */
{

	if (target_limb == (LIMB_HEAD + 1))
	{
		limb_rot->x += en->head_rot.y;
		limb_rot->y += en->head_rot.x;
		limb_rot->z += en->head_rot.z;
	}
	return 0;
}

static void heishi_limit_rotation(entity_t *en) /* 0 internal, 0 external, 40 lines */
{
    /* Simplified by <z64.me> */
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

static void dest(entity_t *en, z64_global_t *gl)
{
	actor_capsule_free(gl, &en->collision);
}

static void draw(entity_t *en, z64_global_t *gl)
{
	external_func_80093D18(gl->common.gfx_ctxt);
	skelanime_draw_mtx(gl, en->skelanime.limb_index, en->skelanime.unk5, en->skelanime.dlist_count, heishi_callback_limb_rotation, 0, &en->actor);
}

static void heishi_change_animation(entity_t *en, int anim_index)
{
  en->unk264 = anim_index;
  float frames = anime_get_framecount(animations[anim_index]);
  actor_anime_change(&en->skelanime, animations[en->unk264], 1.0f, 0, frames, data_80BE9490[en->unk264], -10.0f);
}

static void func_80BE91DC(entity_t *en)
{
	heishi_change_animation(en, 0);
	en->unk278 = 0;
}

static void init(entity_t *en, z64_global_t *gl)
{
  actor_init_shadow(&en->actor.rot_2, 0, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 25.0f);
  skelanime_init_mtx(gl, &en->skelanime, SKL, ANIM4, en->unk188, en->unk1EE, 0x11);
  en->actor.mass = 0xFF;
  en->unk268 = en->actor.variable;
  en->unk272 = en->actor.speedRot.y;

  if (en->actor.variable == 0)
  {
    en->unk26C = 1;

    if ((((AVAL(SAVE_CONTEXT, uint8_t, 0x0F37)) & 0x80) == 0) && (((AVAL(SAVE_CONTEXT, uint32_t, 0x0018)) != 3) || ((AVAL(SAVE_CONTEXT, uint32_t, 0x0010)) == 0)))
          actor_kill(&en->actor);
  }
  else
  {
    en->collision.radius = 0x001E;
    en->collision.height = 0x003C;
    en->collision.unk_0x44 = 0;

    if ((((AVAL(SAVE_CONTEXT, uint8_t, 0x0F37)) & 0x80) != 0) || (((AVAL(SAVE_CONTEXT, uint32_t, 0x0018)) == 3) && ((AVAL(SAVE_CONTEXT, uint32_t, 0x0010)) != 0)))
          actor_kill(&en->actor);
  }

  en->actor.unk_02_ = 6;
  en->actor.gravity = -3.0f;
  actor_capsule_init(gl, &en->collision, &en->actor, &cylinder);
  en->actor.flags |= 0x08000000;
  func_80BE91DC(en);
}

static void play(entity_t *en, z64_global_t *gl)
{
    actor_anime_frame_update_mtx(&en->skelanime);
    if (en->unk270 != 0)
    {
        en->unk270 -= 1;
    }
    en->actor.rot_2.y = en->actor.speedRot.y;
    if (en->unk268 != 0)
    {
        if ((AVAL(SAVE_CONTEXT, uint32_t, 0x0018)) == 3)
        {
            if ((AVAL(SAVE_CONTEXT, uint32_t, 0x0010)) != 0)
            {
                actor_kill(&en->actor);
                return;
            }
        }
    }
    external_func_8002D8E0(&en->actor);
    external_func_8002E4B4(gl, &en->actor, 20.0f, 20.0f, 50.0f, 0x1D);
    actor_set_scale(&en->actor, 0.01f);
    if (en->unk26C != 0)
    {
        heishi_limit_rotation(en);
    }
    actor_set_height(&en->actor, 60.0f);
    external_func_8007869C(&en->head_rot.y, en->unk260, 1, 3000, 0, 0);
    external_func_8007869C(&en->head_rot.x, en->unk25E, 1, 1000, 0, 0);
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
