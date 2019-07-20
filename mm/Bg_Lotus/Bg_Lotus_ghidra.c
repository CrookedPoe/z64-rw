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
	PADDING(0x14);              /* 0x0148, size 0x0014 */
	z64_actorfunc_t *playfunc;  /* 0x015C, size 0x0004 */
	float            unk160;    /* 0x0160, size 0x0004 */
	uint8_t          unk164;    /* 0x0164, size 0x0001 */
	uint8_t          unk165;    /* 0x0165, size 0x0001 */
	int16_t          unk166;    /* 0x0166, size 0x0002 */
	int16_t          unk168;    /* 0x0168, size 0x0002 */
	uint16_t         unk16A;    /* 0x016A, size 0x0002 */
} entity_t;                   /* 0x016C */

/*** external functions ***/
extern int32_t external_func_80086FA0(void);
asm("external_func_80086FA0 = 0x80086FA0");

extern float external_func_800C411C(uint32_t gl830, void *floorpoly, void *unk_sp2C, z64_actor_t *actor, vec3f_t *pos);
asm("external_func_800C411C = 0x800C411C");

extern void external_func_800C6314(z64_global_t *gl, uint32_t gl880, uint32_t *collision);
asm("external_func_800C6314 = 0x800C6314");

extern void external_func_800CA1E8(z64_global_t *gl, uint32_t gl830, float a, float b, float *c, void *unk);
asm("external_func_800CA1E8 = 0x800CA1E8");

extern void external_func_800CAE34(z64_global_t *gl, z64_actor_t *actor, uint32_t collision);
asm("external_func_800CAE34 = 0x800CAE34");

extern int external_func_800CAF70(z64_actor_t *actor);
asm("external_func_800CAF70 = 0x800CAF70");

extern float external_func_801794EC(float a0);
asm("external_func_801794EC = 0x801794EC");

/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void play(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);
static void data_80AD6B68(entity_t *en, z64_global_t *gl);
static void lotus_surface_disturbed(entity_t *en);
static void lotus_destoryed_shrink(entity_t *en, z64_global_t *gl);
static void lotus_interact(entity_t *en, z64_global_t *gl);

/*** variables ***/
const uint32_t data_80AD6D10[] =
{
	0x48580064,
	0x00000000,
	0x00000000,
	0x00000000,
};

static void init(entity_t *en, z64_global_t *gl)
{
  z64_angle_t extraout_var;
  float unk_fl;
  uint32_t unknown = 0;

  actor_init_dynapoly(&en->actor, data_80AD6D10);
  actor_dynapoly_set_move(&en->actor, DPM_PLAYER);
  external_func_800CAE34(gl, &en->actor, DP_COLLIDE);
  unk_fl = external_func_800C411C((uint32_t)AADDR(gl, 0x0830), &(en->actor).floor_poly, &unknown, &en->actor, &(en->actor).pos_2);
  (en->actor).floor_height = unk_fl;
  en->unk168 = 0x60;
  external_func_80086FA0();
  (en->actor).speedRot.y = extraout_var;
  en->playfunc = (z64_actorfunc_t *)lotus_interact;
}

static void dest(entity_t *en, z64_global_t *gl)
{
  dynapoly_free(gl, (void *)AADDR(gl, 0x0880), &en->dynap_id);
}

static void play(entity_t *en, z64_global_t *gl)
{
  uint32_t unknown = 0;
  external_func_800CA1E8(gl, (uint32_t)AADDR(gl, 0x0830), (en->actor).pos_2.x, (en->actor).pos_2.z, &en->unk160, &unknown);
  z64_actorfunc_t *playfunc = en->playfunc;
  playfunc(en, gl);
}

static void draw(entity_t *en, z64_global_t *gl)
{
  draw_static_dlist_opa(gl, DL_LOTUS);
}

static void data_80AD6B68(entity_t *en, z64_global_t *gl)
{
  float fVar1;
  float fVar2;

  if (en->unk166 < 1)
  {
    if ((100.0f < (en->actor).dist_from_link_xz) && ((en->actor).unk_0xEC.z < 0.0f))
    {
      (en->actor).draw_proc = &draw;
      external_func_800C6314(gl, (uint32_t)AADDR(gl, 0x0880), &en->dynap_id);
      actor_set_scale(&en->actor, 0.1f);
      fVar1 = (en->actor).floor_height;
      if (en->unk160 < fVar1) { (en->actor).pos_2.y = fVar1; }
      else { (en->actor).pos_2.y = en->unk160; }
      fVar1 = (en->actor).pos_1.x;
      fVar2 = (en->actor).pos_1.z;
      (en->actor).flags &= 0xFFFFFFEF;
      en->unk168 = 0x60;
      en->playfunc = (z64_actorfunc_t *)lotus_interact;
      (en->actor).pos_2.x = fVar1;
      (en->actor).pos_2.z = fVar2;
    }
  }
  else { en->unk166 -= 1; }
}

static void lotus_surface_disturbed(entity_t *en)
{
  float fVar1;
  float fVar2;

  if ((en->actor).variable == 0)
  {
    fVar1 = external_func_801794EC(en->unk166 * 0.7854f);
    fVar1 = fVar1 * (0.014f * (en->unk166 / 8.0f) + 0.01f);
    fVar2 = (1.0f - fVar1) * 0.1f;
    (en->actor).scale.x = (fVar1 + 1.0f) * 0.1f;
    (en->actor).scale.z = fVar2;
  }
}

static void lotus_destoryed_shrink(entity_t *en, z64_global_t *gl)
{
  short sVar1;
  int iVar2;
  float fVar3;
  float fVar4;

  fVar3 = (en->actor).pos_2.y;
  if (en->unk160 < fVar3) {
    (en->actor).pos_2.y = en->unk160;
    fVar3 = (en->actor).pos_2.y;
  }
  fVar4 = (en->actor).floor_height;
  (en->actor).pos_2.y = fVar3 - 1.0f;
  if ((en->actor).pos_2.y <= fVar4) {
    (en->actor).pos_2.y = fVar4;
    en->unk166 = 0;
    sVar1 = en->unk166;
  }
  else {
    sVar1 = en->unk166;
  }
  if (sVar1 < 1) {
    iVar2 = math_approxf(&(en->actor).scale.x, 0, 0.005f);
    if (iVar2 != 0) {
      (en->actor).draw_proc = 0;
      en->unk166 = 100;
      external_func_8003EBF8(gl, (uint32_t)AADDR(gl, 0x0880), en->dynap_id);
      en->playfunc = (z64_actorfunc_t *)data_80AD6B68;
    }
    (en->actor).scale.z = (en->actor).scale.x;
  }
  else {
    en->unk166 = sVar1 + -1;
    lotus_surface_disturbed(en);
  }
}

static void lotus_interact(entity_t *en, z64_global_t *gl)
{
  short sVar1;
  short extraout_var;
  int iVar2;
  uint32_t uVar4;
  float fVar5;
  float fVar6;

  en->unk168 -= 1;
  fVar5 = external_func_801794EC(en->unk168 * 0.0654f);
  if ((en->actor).variable == 0) {
    fVar6 = math_sins((en->actor).speedRot.y);
    sVar1 = (en->actor).speedRot.y;
    (en->actor).pos_2.x = fVar6 * fVar5 * 6.0f + (en->actor).pos_1.x;
    fVar6 = math_coss(sVar1);
    sVar1 = en->unk168;
    (en->actor).pos_2.z = fVar6 * fVar5 * 6.0f + (en->actor).pos_1.z;
    if (sVar1 == 0) {
      en->unk168 = 0x60;
      external_func_80086FA0();
      (en->actor).speedRot.y = (en->actor).speedRot.y + (extraout_var >> 2);
    }
    fVar5 = en->unk160;
  }
  else {
    fVar5 = en->unk160;
  }
  fVar6 = (en->actor).floor_height;
  if (fVar5 < fVar6) {
    (en->actor).pos_2.y = fVar6;
  }
  else {
    (en->actor).pos_2.y = fVar5;
    iVar2 = external_func_800CAF70(&en->actor);
    if (iVar2 == 0) {
      en->unk164 = 0;
    }
    else {
      if (en->unk164 == 0) {
        effect_spawn_water_ripple(gl, &(en->actor).pos_2, 1000, 0x578, 0);
        effect_spawn_water_ripple(gl, &(en->actor).pos_2, 1000, 0x578, 8);
        en->unk166 = 0x28;
      }
      if (AVAL(SAVE_CONTEXT, int8_t, 0x0020) != 3) {
        uVar4 = (en->actor).flags;
        en->unk166 = 0x28;
        (en->actor).flags = uVar4 | 0x10;
        en->playfunc = (z64_actorfunc_t *)lotus_destoryed_shrink;
        return;
      }
      en->unk164 = 1;
    }
  }
  if (0 < en->unk166) {
    en->unk166 -= 1;
  }
  lotus_surface_disturbed(en);
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
