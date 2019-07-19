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
	z64_actorfunc_t *playfunc;  /* 0x015C, size 0x0004 */
	uint32_t         unk160;    /* 0x0160, size 0x0004 */
	uint16_t         unk164;    /* 0x0164, size 0x0002 */
	uint16_t         unk166;    /* 0x0166, size 0x0002 */
	uint16_t         unk168;    /* 0x0168, size 0x0002 */
} entity_t;

/*** external functions ***/
extern int16_t external_func_80086FA0(void);
asm("external_func_80086FA0 = 0x80086FA0");

extern float external_func_800C411C(void *gl830, void *floorpoly, float a, z64_actor_t *actor, float b);
asm("external_func_800C411C = 0x800C411C");

extern void external_func_800C6314(z64_global_t *gl, void *gl880, uint32_t dynapoly_id);
asm("external_func_800C6314 = 0x800C6314");

extern void external_func_800CA1E8(z64_global_t *gl, void *gl830, float a, float b, uint32_t c, float d);
asm("external_func_800CA1E8 = 0x800CA1E8");

extern void external_func_800CAE34(z64_global_t *gl, z64_actor_t *actor, uint32_t object_collision);
asm("external_func_800CAE34 = 0x800CAE34");

extern int external_func_800CAF70(z64_actor_t *a);
asm("external_func_800CAF70 = 0x800CAF70");

extern float external_func_801794EC(float a);
asm("external_func_801794EC = 0x801794EC");

/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 39 lines */
static void play(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 24 lines */
static void dest(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 13 lines */
static void draw(entity_t *en, z64_global_t *gl); /* 0 internal, 1 external, 13 lines */
static void func_80AD6830(entity_t *en); /* 0 internal, 1 external, 44 lines */
static void data_80AD68DC(entity_t *en, z64_global_t *gl); /* 1 internal, 6 external, 115 lines */
static void data_80AD6A88(entity_t *en, z64_global_t *gl); /* 1 internal, 2 external, 61 lines */
static void data_80AD6B68(entity_t *en, z64_global_t *gl); /* 0 internal, 2 external, 65 lines */

/*** variables ***/
const uint32_t data_80AD6D10[] =
{
	0x48580064,
	0x00000000,
	0x00000000,
	0x00000000,
};

const uint32_t data_80AD6D20 = 0x3F490FDB; /* 0.785398185253143310546875 */
const uint32_t data_80AD6D28 = 0x3C656041; /* 0.013999999500811100006103515625 */
const uint32_t data_80AD6D30 = 0x3D860A92; /* 0.06544984877109527587890625 */


/*** functions ***/
static void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 13 lines */
{
	dynapoly_free(gl, AADDR(gl, 0x0880), &en->dynap_id);
}

static void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 13 lines */
{
	draw_static_dlist_opa(gl, DL_LOTUS);
}

static void play(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 24 lines */
{
	external_func_800CA1E8(gl, (void *)AADDR(gl, 0x0830), en->actor.pos_2.x, en->actor.pos_2.z, en->unk160, (float)data_80AD6D30);
	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, gl);
}

static void func_80AD6830(entity_t *en) /* 0 internal, 1 external, 44 lines */
{
	if (en->actor.variable == 0)
	{
		float _tf2 = (float)((external_func_801794EC(en->unk166 * data_80AD6D20)) * ((data_80AD6D28 * (en->unk166 / 8.0f)) + 0.01f));
		en->actor.scale.x = ((_tf2 + 1.0f) * 0.1f);
		en->actor.scale.z = ((1.0f - _tf2) * 0.1f);
	}
}

static void data_80AD6B68(entity_t *en, z64_global_t *gl) /* 0 internal, 2 external, 65 lines */
{
	if (en->unk166 < 1)
	{
		if ((100.0f < en->actor.dist_from_link_xz) && (en->actor.unk_0xEC.z < 0))
		{
			en->actor.draw_proc = &draw;
			external_func_800C6314(gl, (void *)AADDR(gl, 0x0880), en->dynap_id);
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

static void init(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 39 lines */
{
	actor_init_dynapoly(&en->actor, data_80AD6D10);
	actor_dynapoly_set_move(&en->actor, DPM_PLAYER);
	external_func_800CAE34(gl, &en->actor, DP_COLLIDE);
	en->actor.floor_height = external_func_800C411C((void *)AADDR(gl, 0x0830), &en->actor.floor_poly, data_80AD6D30, &en->actor, en->actor.pos_2.x);
	en->unk168 = 96;
	en->actor.speedRot.y = (external_func_80086FA0() >> 0x10);
	en->playfunc = (z64_actorfunc_t*)data_80AD68DC;

}

static void data_80AD6A88(entity_t *en, z64_global_t *gl) /* 1 internal, 2 external, 61 lines */
{
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

	if (en->unk166 < 1)
	{
		int _temp_approx = math_approxf(&en->actor.scale.x, 0.0f, (float)0x3BA3D70B);
		if (_temp_approx != 0)
		{
			en->actor.draw_proc = 0;
			en->unk166 = 100;
			external_func_8003EBF8(gl, (uint32_t)AADDR(gl, 0x0880), en->dynap_id);
			en->playfunc = (z64_actorfunc_t*)data_80AD6B68;
		}
		en->actor.scale.z = en->actor.scale.x;
	}
	else
	{
		en->unk166 -= 1;
		func_80AD6830(en);
	}

}

static void data_80AD68DC(entity_t *en, z64_global_t *gl) /* 1 internal, 6 external, 115 lines */
{
	en->unk168 -= 1;
  float _sp34 = (external_func_801794EC(en->unk168 * data_80AD6D30) * 6.0f);
  if (en->actor.variable == 0)
  {
      en->actor.pos_2.x = ((math_sins(en->actor.speedRot.y) * _sp34) + en->actor.pos_1.x);
      en->actor.pos_2.z = ((math_coss(en->actor.speedRot.y) * _sp34) + en->actor.pos_1.z);
      if (en->unk168 == 0)
      {
          en->unk168 = 96;
          en->actor.speedRot.y += (external_func_80086FA0() >> 0x12);
      }
  }

  if (en->unk160 < en->actor.floor_height)
  {
      en->actor.pos_2.y = en->actor.floor_height;
  }
  else
  {
      en->actor.pos_2.y = en->unk160;
      if (external_func_800CAF70(&en->actor) != 0)
      {
          if (en->unk164 == 0)
          {
              effect_spawn_water_ripple(gl, &en->actor.pos_2, 1000, 0x0578, 0);
              effect_spawn_water_ripple(gl, &en->actor.pos_2, 1000, 0x0578, 8);
              en->unk166 = 40;
          }
          if ((AVAL(SAVE_CONTEXT, uint32_t, 0x0020)) != 3)
          {
              en->unk166 = 40;
              en->actor.flags |= 0x10;
              en->playfunc = (z64_actorfunc_t *)data_80AD6A88;
              return;
          }
          en->unk164 = 1;
      }
      else
      {
          en->unk164 = 0;
      }
  }
  if (en->unk166 > 0)
  {
      en->unk166 -= 1;
  }
  func_80AD6830(en);
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
