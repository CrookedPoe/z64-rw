#include <z64ovl/oot/debug.h>
#include "C:/msys64/opt/n64/mips64/include/z64ovl/h/ichain.h"

#define ACT_ID                          0xDEAD
#define OBJ_ID                          0x004D /* object_menkuri_objects */
#define NA_SE_EV_ELEVATOR_MOVE          0x2024

/*** object ***/
#define DLIST                           0x060038D0
#define DYNAPOLY                        0x060042D8

typedef struct {
  z64_actor_t actor;
  z64_dynapoly_t dynapoly;
} entity_t;

/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);

/*** Compact Instance Initialization Variables ***/
const uint32_t ichain[] = {
  ICHAIN(ICHAIN_VEC3Fdiv1000, scale, 100) & ICHAIN_LAST
};

static void init(entity_t *en, z64_global_t *gl)
{
  uint32_t collision_offset = 0;
  actor_init_ichain(&en->actor, ichain);
  actor_dynapoly_set_move(&en->actor, (DPM_PLAYER | DPM_ENEMY));
  dynapoly_alloc(DYNAPOLY, &collision_offset);
  en->dynapoly.id = actor_register_dynapoly(gl, AADDR(&gl->col_ctxt, 0x0050), &en->actor, collision_offset);
}

static void play(entity_t *en, z64_global_t *gl)
{
  if (flag_get_switch(gl, (en->actor).variable) == 0)
  {
      if (actor_dynapoly_get_link_floorcast(&en->actor) != 0)
      {
          actor_flag_play_sound(&en->actor, NA_SE_EV_ELEVATOR_MOVE);
          (en->actor).rot_2.y += 0x80;
      }
  }
}

static void dest(entity_t *en, z64_global_t *gl)
{
    dynapoly_free(gl, AADDR(&gl->col_ctxt, 0x0050), (en->dynapoly).id);
}

static void draw(entity_t *en, z64_global_t *gl)
{
    draw_dlist_opa(gl, DLIST);
}

const z64_actor_init_t init_vars =
{
  .number = ACT_ID,
  .type = OVLTYPE_BG,
  .room = 0x00,
  .flags = 0x00000030,
  .object = OBJ_ID,
  .padding = 0xBEEF,
  .instance_size = sizeof(entity_t),
  .init = init,
  .dest = dest,
  .main = play,
  .draw = draw
};
