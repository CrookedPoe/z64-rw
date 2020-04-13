#include <z64ovl/oot/debug.h>

#define ACT_ID 0x0082
#define OBJ_ID 0x0086

/*** object ***/
#define DL_VASE 0x06000000

typedef struct {
	z64_actor_t actor;
	/* uint8_t[16] debug_padding; */
} entity_t; /* 014C */


/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);

/*** functions ***/
static void init(entity_t *en, z64_global_t *gl)
{
	z_actor_set_scale(&en->actor, 0.01f);
	(en->actor).pos_focus.x = (en->actor).pos.x;
	(en->actor).pos_focus.y = (en->actor).pos.y;
	(en->actor).pos_focus.z = (en->actor).pos.z;
	z_actor_shadow_init(&(en->actor).rot, 0.0f, &Z_SHADOW_CIRCLE, 6.0f);
}

static void dest(entity_t *en, z64_global_t *gl)
{
}

static void draw(entity_t *en, z64_global_t *gl)
{
	z_cheap_proc_draw_opa(gl, DL_VASE);
}

const z64_actor_init_t init_vars = {
	.number = ACT_ID,
	.type = OVLTYPE_PROP,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = (void*)0x80035118,
	.draw = draw
};
