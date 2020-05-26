/************
 * z_en_m_thunder.c faithfully rewritten by CrookedPoe <nickjs.site> and Dr. Disco <z64.me>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit c523a0a26ae54f3d126dc4f33d3aeab24a6fe787
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include "z_bg_menkuri_kaiten.h"

typedef struct {
  z64_actor_t actor;
  z64_dynapoly_t dynapoly;
} entity_t;

/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void play(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);

/*** Compact Instance Initialization Variables ***/
const uint32_t ichain[] = {
  ICHAIN(ICHAIN_VEC3Fdiv1000, scale, 100) & ICHAIN_LAST
};

static void init(entity_t *en, z64_global_t *gl)
{
  uint32_t collision_offset = 0;
  z_lib_ichain_init(&en->actor, ichain);
  actor_dynapoly_set_move(&en->actor, (DPM_PLAYER | DPM_ENEMY));
  dynapoly_alloc(DYNAPOLY, &collision_offset);
  (en->dynapoly).poly_id = actor_register_dynapoly(gl, AADDR(&gl->col_ctxt, 0x0050), &en->actor, collision_offset);
}

static void play(entity_t *en, z64_global_t *gl)
{
  if (flag_get_switch(gl, (en->actor).variable) == 0)
  {
      if (actor_dynapoly_get_link_floorcast(&en->actor) != 0)
      {
          z_actor_play_sfx_flag(&en->actor, NA_SE_EV_ELEVATOR_MOVE);
          (en->actor).rot.y += 0x80;
      }
  }
}

static void dest(entity_t *en, z64_global_t *gl)
{
    z_dynapoly_free(gl, AADDR(&gl->col_ctxt, 0x0050), (en->dynapoly).poly_id);
}

static void draw(entity_t *en, z64_global_t *gl)
{
    z_cheap_proc_draw_opa(gl, DL_PLATFORM);
}

const z64_actor_init_t init_vars =
{
  .number = ACT_ID,
  .type = OVLTYPE_BG,
  .room = 0x00,
  .flags = 0x00000030,
  .object = OBJ_ID,
  .padding = 0x0000,
  .instance_size = sizeof(entity_t),
  .init = init,
  .dest = dest,
  .main = play,
  .draw = draw
};
