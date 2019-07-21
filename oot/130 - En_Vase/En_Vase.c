#include <z64ovl/oot/debug.h>

#define ACT_ID 0x0082
#define OBJ_ID 0x0086

/*** object ***/
#define DL_VASE 0x06000000

typedef struct {
	z64_actor_t actor;
	uint32_t unknown[4];
} entity_t; /* 014C */


/*** function prototypes ***/
static void init(entity_t *en, z64_global_t *gl);
static void dest(entity_t *en, z64_global_t *gl);
static void draw(entity_t *en, z64_global_t *gl);

/*** functions ***/
static void init(entity_t *en, z64_global_t *gl)
{
	actor_set_scale(&en->actor, 0.01f);
	en->actor.pos_3.x = en->actor.pos_2.x;
	en->actor.pos_3.y = en->actor.pos_2.y;
	en->actor.pos_3.z = en->actor.pos_2.z;
	actor_init_shadow(&en->actor.rot_2, 0.0f, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 6.0f);
}

static void dest(entity_t *en, z64_global_t *gl)
{
}

static void draw(entity_t *en, z64_global_t *gl)
{
	draw_static_dlist_opa(gl, DL_VASE);
}

const z64_actor_init_t init_vars = {
	.number = ACT_ID,
	.type = Prop,
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

/***
external_func_80035118:
	sw	a0, 0($sp)
	jr	$ra
	sw	a1, 4($sp)
***/
