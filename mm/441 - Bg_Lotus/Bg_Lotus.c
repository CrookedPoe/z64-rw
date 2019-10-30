/***
* Bg_Lotus Rewrite by CrookedPoe <nickjs.site>
* MMU10 DMA Entry:    0x0001BE50
* MMU10 Actor Entry:  0x00C48C30
***/

#include <z64ovl/mm/u10.h>

#define ACT_ID 0x01B9
#define OBJ_ID 0x01A5
/* object */
#define DL_LOTUS    0x06000040
#define DP_COLLIDE  0x06000A20

typedef struct {
   z64_actor_t      actor;
   struct
   {
       uint32_t id;
       PADDING(0x14);
   } dynap;
   z64_actorfunc_t *playfunc;
   float            unk160;
   uint8_t          unk164;
   int16_t          unk166;
   int16_t          unk168;
} entity_t;

/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void play(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);
static void data_80AD6B68(entity_t *en, z64_global_t *gl);
static void lotus_surface_disturbed(entity_t *en);
static void lotus_destroyed_shrink(entity_t *en, z64_global_t *gl);
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
   uint32_t unknown = 0;

   actor_init_dynapoly(&en->actor, data_80AD6D10);
   actor_dynapoly_set_move(&en->actor, DPM_PLAYER);
   actor_dynapoly_new(gl, &en->actor, DP_COLLIDE);
   en->actor.floor_height =
      external_func_8003C940(
           AADDR(gl, 0x0830)
         , &en->actor.floor_poly
         , &unknown
         , &en->actor
         , &en->actor.pos_2
      );
   en->unk168 = 0x60;
   en->actor.speedRot.y = external_func_800FD970();
   en->playfunc = (z64_actorfunc_t *)lotus_interact;
}

static void dest(entity_t *en, z64_global_t *gl)
{
   dynapoly_free(gl, AADDR(gl, 0x0880), &en->dynap_id);
}

static void play(entity_t *en, z64_global_t *gl)
{
   uint32_t unknown = 0;
   external_func_8002F758(
        gl
      , AADDR(gl, 0x0830)
      , en->actor.pos_2.x
      , en->actor.pos_2.z
      , &en->unk160
      , &unknown
   );
   z64_actorfunc_t *playfunc = en->playfunc;
   playfunc(en, gl);
}

static void draw(entity_t *en, z64_global_t *gl)
{
   draw_static_dlist_opa(gl, DL_LOTUS);
}

static void data_80AD6B68(entity_t *en, z64_global_t *gl)
{

   if (en->unk166 < 1)
   {
      if (   100.0f < en->actor.dist_from_link_xz
          && en->actor.unk_0xEC.z < 0.0f
         )
      {
         en->actor.draw_proc = &draw;
         external_func_8003EC50(
              gl
            , AADDR(gl, 0x0880)
            , &en->dynap_id
         );
         actor_set_scale(&en->actor, 0.1f);
         if (en->unk160 < en->actor.floor_height)
         {
            en->actor.pos_2.y = en->actor.floor_height;
         }
         else {
            en->actor.pos_2.y = en->unk160;
         }
         en->actor.flags &= 0xFFFFFFEF;
         en->unk168 = 0x60;
         en->playfunc = (z64_actorfunc_t *)lotus_interact;
         en->actor.pos_2.x = en->actor.pos_1.x;
         en->actor.pos_2.z = en->actor.pos_1.z;
      }
   }
   else { en->unk166 -= 1; }
}

static void lotus_surface_disturbed(entity_t *en)
{
   if (en->actor.variable == 0)
   {
      float factor;

      factor = external_func_800CA720(en->unk166 * 0.7854f);
      factor = factor * (0.014f * (en->unk166 / 8.0f) + 0.01f);
      en->actor.scale.x = (factor + 1.0f) * 0.1f;
      en->actor.scale.z = (1.0f - factor) * 0.1f;
   }
}

static void lotus_destroyed_shrink(entity_t *en, z64_global_t *gl)
{

   if (en->unk160 < en->actor.pos_2.y) {
      en->actor.pos_2.y = en->unk160;
   }
   en->actor.pos_2.y -= 1.0f;
   if (en->actor.pos_2.y <= en->actor.floor_height) {
      en->actor.pos_2.y = en->actor.floor_height;
      en->unk166 = 0;
   }
   if (en->unk166 < 1) {
      int result = math_approxf(&en->actor.scale.x, 0, 0.005f);
      if (result != 0) {
         en->actor.draw_proc = 0;
         en->unk166 = 100;
         external_func_8003EBF8(gl, AADDR(gl, 0x0880), en->dynap_id);
         en->playfunc = (z64_actorfunc_t *)data_80AD6B68;
      }
      en->actor.scale.z = en->actor.scale.x;
   }
   else {
      en->unk166 -= 1;
      lotus_surface_disturbed(en);
   }
}

static void lotus_interact(entity_t *en, z64_global_t *gl)
{
   en->unk168 -= 1;
   if (en->actor.variable == 0) {
      float factor;

      factor = external_func_800CA720(en->unk168 * 0.0654f);;
      en->actor.pos_2.x =
            math_sins(en->actor.speedRot.y)
         * factor
         * 6.0f
         + en->actor.pos_1.x
      ;
      en->actor.pos_2.z =
            math_coss(en->actor.speedRot.y)
         * factor
         * 6.0f
         + en->actor.pos_1.z
      ;
      if (en->unk168 == 0) {
         en->unk168 = 0x60;
         en->actor.speedRot.y += external_func_800FD970() >> 2;
      }
   }
   if (en->unk160 < en->actor.floor_height) {
      en->actor.pos_2.y = en->actor.floor_height;
   }
   else {
      en->actor.pos_2.y = en->unk160;
      if (external_func_8004356C(&en->actor) == 0) {
         en->unk164 = 0;
      }
      else {
         if (en->unk164 == 0) {
            effect_spawn_water_ripple(gl, &en->actor.pos_2, 1000, 0x578, 0);
            effect_spawn_water_ripple(gl, &en->actor.pos_2, 1000, 0x578, 8);
            en->unk166 = 0x28;
         }
         if (AVAL(SAVE_CONTEXT, int8_t, 0x0020) != 3) {
            en->unk166 = 0x28;
            en->actor.flags |= 0x10;
            en->playfunc = (z64_actorfunc_t *)lotus_destroyed_shrink;
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
