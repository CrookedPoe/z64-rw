#include <z64ovl/oot/debug.h>

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

/*** variables ***/
const z64_dynapoly_init_t dynapoly_vars = {
  .unk_0 = {0x48, 0x50},
  .scale = 100,
  .unk_1 = 0x00000000,
  .unk_2 = 0x00000000,
  .unk_3 = 0x00000000
};

static void init(entity_t *en, z64_global_t *gl)
{
  uint32_t collision_offset = 0;
  actor_init_dynapoly(&en->actor, &dynapoly_vars);
  actor_dynapoly_set_move(&en->actor, (DPM_PLAYER | DPM_ENEMY));
  dynapoly_alloc(DYNAPOLY, &collision_offset);
  en->dynapoly.id = actor_register_dynapoly(gl, &gl->col_ctxt.sect_size.z, &en->actor, collision_offset);
}

static void play(entity_t *en, z64_global_t *gl)
{
  if (flag_get_switch(gl, en->actor.variable) == 0)
  {
      if (actor_dynapoly_get_link_floorcast(&en->actor) != 0)
      {
          actor_flag_play_sound(&en->actor, NA_SE_EV_ELEVATOR_MOVE);
          en->actor.rot_2.y += 0x80;
      }
  }
}

static void dest(entity_t *en, z64_global_t *gl)
{
    dynapoly_free(gl, &gl->col_ctxt.sect_size.z, &en->dynapoly.id);
}

static void draw(entity_t *en, z64_global_t *gl)
{
    draw_static_dlist_opa(gl, DLIST);
}

const z64_actor_init_t init_vars =
{
  .number = ACT_ID,
  .type = Bg,
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
