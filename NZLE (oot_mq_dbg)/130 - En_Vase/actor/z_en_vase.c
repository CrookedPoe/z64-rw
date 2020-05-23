/************
 * z_en_vase.c faithfully rewritten by CrookedPoe <nickjs.site>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit 7e47fc9a8c85706869fb7d24285d3f1cc1a13644
*************/

#include <z64ovl/oot/debug.h>
#include "z_en_vase.h"
#include "../object/map.h"

typedef struct {
	z64_actor_t actor;
	/* uint8_t[16] debug_padding; */
} z_en_vase_t; /* 014C */


/*** function prototypes ***/
static void init(z_en_vase_t *en, z64_global_t *gl);
static void dest(z_en_vase_t *en, z64_global_t *gl);
static void draw(z_en_vase_t *en, z64_global_t *gl);

/*** functions ***/
static void init(z_en_vase_t *en, z64_global_t *gl)
{
	z_actor_set_scale(&en->actor, 0.01f);
	(en->actor).pos_focus.x = (en->actor).pos.x;
	(en->actor).pos_focus.y = (en->actor).pos.y;
	(en->actor).pos_focus.z = (en->actor).pos.z;
	z_actor_shadow_init(&(en->actor).rot, 0.0f, &Z_SHADOW_CIRCLE, 6.0f);
}

static void dest(z_en_vase_t *en, z64_global_t *gl)
{
	/* Empty */
}

static void draw(z_en_vase_t *en, z64_global_t *gl)
{
	z_cheap_proc_draw_opa(gl, dl_vase);
}

const z64_actor_init_t init_vars = {
	.number = 0x0082,
	.type = OVLTYPE_PROP,
	.room = 0x00,
	.flags = 0x00000010,
	.object = 0x0086,
	.padding = 0x0000,
	.instance_size = sizeof(z_en_vase_t),
	.init = init,
	.dest = dest,
	.main = (void*)0x80035118,
	.draw = draw
};
