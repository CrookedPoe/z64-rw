#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

#define OBJ_ID 1

#define DEKUNUTS 0x06002028 /* En_Dekunuts; Mad Scrub */
#define HINTNUTS 0x060012F0 /* En_Hintnuts; Tutorial Scrub (Deku Tree) */
#define SHOPNUTS 0x06004008 /* En_Shopnuts; Business Scrub */
#define DNS_NUTS 0x06002410 /* Mask Theatre Judge */
#define DNK_NUTS 0x06001890 /* Mask Theatre Audience */

typedef struct {
	z64_actor_t actor;
	/* uint8_t debug_ex[16];*/
	z64_actorfunc_t* state;
	uint8_t object_index;
	uint8_t inst0151;
	int16_t timer;
	z64_collider_cylinder_main_t collider;
} entity_t; /* 01A0 */


/*** function prototypes ***/
void dest(entity_t* en, z64_global_t* gl); /* 0 internal, 1 external, 10 lines */
void set_draw(entity_t* en, z64_global_t* gl); /* 0 internal, 1 external, 30 lines */
void data_80ABBBA8(entity_t* en, z64_global_t* gl); /* 0 internal, 4 external, 124 lines */
void init(entity_t* en, z64_global_t* gl); /* 0 internal, 5 external, 49 lines */
void draw(entity_t* en, z64_global_t* gl); /* 0 internal, 6 external, 68 lines */
void main(entity_t* en, z64_global_t* gl); /* 0 internal, 6 external, 73 lines */


/*** variables ***/
const uint32_t data_80ABBFC0[] =
{
	0x0A110939,
	0x20010000,
	0x00000000,
	0xFFCFFFFF,
	0x00080000,
	0xFFCFFFFF,
	0x00000000,
	0x11010100,
	0x000D0000 /* 2 bytes, expanded to 4 for alignment */,
	0x00000000,
	0x00000000,
	0x00000000 /* 2 bytes, expanded to 4 for alignment */
};
const uint16_t data_80ABBFEC[] =
{
	0x004A,
	0x0164,
	0x0168,
	0x0171,
	0x0172,
	0x0000
};

const uint32_t data_80ABBFF8[] =
{
	DEKUNUTS,
	HINTNUTS,
	SHOPNUTS,
	DNS_NUTS,
	DNK_NUTS,
	0x00000000
};

const uint32_t data_80ABC010[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};
const uint32_t data_80ABC024[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};
const uint32_t data_80ABC038[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x6E757473,
	0x62616C6C,
	0x2E630000
};
const uint32_t data_80ABC04C[] =
{
	0x38C90FDA
};


/*** functions ***/
void dest(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);
	z_collider_cylinder_free(gl, &en->collider);
}

void set_draw(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 30 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lset_draw: \n"
	);

	if (z_scene_object_is_loaded(&gl->obj_ctxt, en->object_index))
	{
		(en->actor).draw_proc = (void*)draw;
		(en->actor).rot_2.y = 0;
		en->timer = 30;
		en->state = (z64_actorfunc_t*)data_80ABBBA8;
		(en->actor).alloc_index = en->object_index;
		(en->actor).xz_speed = 10.0f;
	}
}

void data_80ABBBA8(entity_t* en, z64_global_t* gl) /* 0 internal, 4 external, 124 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBBA8: \n"
	);
	asm(
		"addiu           $sp,$sp,-88                            \n"
		"sw              $ra,52($sp)                            \n"
		"sw              $s0,48($sp)                            \n"
		"sw              $a1,92($sp)                            \n"
		"lh              $t7,338($a0)                           \n"
		"lw              $v1,7236($a1)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"addiu           $t8,$t7,-1                             \n"
		"sh              $t8,338($a0)                           \n"
		"lh              $t9,338($a0)                           \n"
		"lui             $at,0xBF80                             \n"
		"bnel            $t9,$zero,.L000003                     \n"
		"lh              $t0,24($s0)                            \n"
		"mtc1            $at,$f4                                \n"
		"nop                                                    \n"
		"swc1            $f4,108($a0)                           \n"
		"lh              $t0,24($s0)                            \n"
		".L000003:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		"addiu           $t1,$t0,10920                          \n"
		"andi            $t2,$v0,0x8                            \n"
		"bne             $t2,$zero,.L000004                     \n"
		"sh              $t1,24($s0)                            \n"
		"andi            $t3,$v0,0x1                            \n"
		"bnel            $t3,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t4,356($s0)                           \n"
		"andi            $t5,$t4,0x2                            \n"
		"bnel            $t5,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t6,357($s0)                           \n"
		"andi            $t7,$t6,0x2                            \n"
		"bnel            $t7,$zero,.L000005                     \n"
		"lb              $v0,334($v1)                           \n"
		"lbu             $t8,358($s0)                           \n"
		"andi            $t9,$t8,0x2                            \n"
		"beql            $t9,$zero,.L000006                     \n"
		"lh              $t6,338($s0)                           \n"
		".L000004:                                              \n"
		"lb              $v0,334($v1)                           \n"
		".L000005:                                              \n"
		"addiu           $at,$zero,1                            \n"
		"beq             $v0,$at,.L000007                       \n"
		"addiu           $at,$zero,2                            \n"
		"bne             $v0,$at,.L000008                       \n"
		"lui             $t0,0x8016                             \n"
		"lw              $t0,-6556($t0)                         \n"
		"bnel            $t0,$zero,.L000009                     \n"
		"lwc1            $f6,36($s0)                            \n"
		".L000007:                                              \n"
		"lbu             $v0,356($s0)                           \n"
		"andi            $t1,$v0,0x2                            \n"
		"beq             $t1,$zero,.L000008                     \n"
		"andi            $t2,$v0,0x10                           \n"
		"beq             $t2,$zero,.L000008                     \n"
		"andi            $t3,$v0,0x4                            \n"
		"beq             $t3,$zero,.L000008                     \n"
		"andi            $t5,$v0,0xffe9                         \n"
		"sb              $t5,356($s0)                           \n"
		"ori             $t6,$t5,0x8                            \n"
		"addiu           $t7,$zero,2                            \n"
		"sb              $t6,356($s0)                           \n"
		"sw              $t7,364($s0)                           \n"
		"addiu           $a0,$v1,2592                           \n"
		"addiu           $a1,$sp,76                             \n"
		"jal             0x800D20CC                 \n"
		"or              $a2,$zero,$zero                        \n"
		"lh              $t8,78($sp)                            \n"
		"ori             $at,$zero,0x8000                       \n"
		"addiu           $t0,$zero,30                           \n"
		"addu            $t9,$t8,$at                            \n"
		"sh              $t9,50($s0)                            \n"
		"beq             $zero,$zero,.L000010                   \n"
		"sh              $t0,338($s0)                           \n"
		".L000008:                                              \n"
		"lwc1            $f6,36($s0)                            \n"
		".L000009:                                              \n"
		"lui             $at,0x4080                             \n"
		"mtc1            $at,$f10                               \n"
		"swc1            $f6,64($sp)                            \n"
		"lwc1            $f8,40($s0)                            \n"
		"addiu           $t1,$zero,7                            \n"
		"addiu           $t2,$zero,3                            \n"
		"add.s           $f16,$f8,$f10                          \n"
		"addiu           $t3,$zero,15                           \n"
		"addiu           $t4,$zero,-1                           \n"
		"addiu           $t5,$zero,10                           \n"
		"swc1            $f16,68($sp)                           \n"
		"lwc1            $f18,44($s0)                           \n"
		"sw              $zero,36($sp)                          \n"
		"sw              $t5,32($sp)                            \n"
		"sw              $t4,28($sp)                            \n"
		"sw              $t3,24($sp)                            \n"
		"sw              $t2,20($sp)                            \n"
		"sw              $t1,16($sp)                            \n"
		"lw              $a0,92($sp)                            \n"
		"addiu           $a1,$sp,64                             \n"
		"lui             $a2,0x40C0                             \n"
		"or              $a3,$zero,$zero                        \n"
		"jal             0x800297A4                 \n"
		"swc1            $f18,72($sp)                           \n"
		"lw              $a0,92($sp)                            \n"
		"addiu           $a1,$s0,36                             \n"
		"addiu           $a2,$zero,20                           \n"
		"jal             0x8006BAD8                 \n"
		"addiu           $a3,$zero,14528                        \n"
		"jal             0x8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000011                   \n"
		"lw              $ra,52($sp)                            \n"
		"lh              $t6,338($s0)                           \n"
		".L000006:                                              \n"
		"addiu           $at,$zero,-300                         \n"
		"bnel            $t6,$at,.L000011                       \n"
		"lw              $ra,52($sp)                            \n"
		"jal             0x8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		".L000010:                                              \n"
		"lw              $ra,52($sp)                            \n"
		".L000011:                                              \n"
		"lw              $s0,48($sp)                            \n"
		"addiu           $sp,$sp,88                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void init(entity_t* en, z64_global_t* gl) /* 0 internal, 5 external, 49 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit: \n"
	);

	z_actor_shadow_init(&(en->actor).rot_2, 400.0f, &Z_SHADOW_CIRCLE, 13.0f);
	z_collider_cylinder_alloc(gl, &en->collider);
	z_collider_cylinder_init(gl, &en->collider, &en->actor, (z64_collider_cylinder_init_t*)data_80ABBFC0);

	/* Grab the correct Scrub Object Index */
	en->object_index = z_scene_object_get_index(&gl->obj_ctxt, data_80ABBFEC[(en->actor).variable]);

	/* If the object isn't loaded, kill the actor process. Otherwise, continue. */
	if (en->object_index < 0)
		z_actor_kill(&en->actor);
	else
		en->state = (z64_actorfunc_t*)set_draw;
}

void draw(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 68 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	z64_gfx_t* gfx = (gl->common).gfx_ctxt;
	z64_disp_buf_t* opa = &ZQDL(gl, poly_opa);
	Gfx gfx_debug[3];

	z_debug_graph_alloc(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
	z_rcp_append_preset(gfx);
	z_matrixf_top_multiply(gl->unk_player_matrix, 1);
	z_matrix_roll(((en->actor).rot_init.z * 0.000095873795f), 1);
	gSPMatrix(opa->p++, z_matrix_alloc(gfx, "../z_en_nutsball.c"/*, __LINE__*/), G_MTX_LOAD);
	gSPDisplayList(opa->p++, data_80ABBFF8[(en->actor).variable]);
	z_debug_graph_write(gfx_debug, gfx, "../z_en_nutsball.c", __LINE__);
}

void main(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 73 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lmain: \n"
	);
	z64_actorfunc_t* state_func;

	if (((int32_t)(gl->actor_list[2].first[5].scale.x) & 0x300000C0) == 0)
		state_func = en->state;
	else
	{
		if (en->state != (z64_actorfunc_t*)set_draw)
			return;
		state_func = en->state;
	}
	state_func(en, gl);

	z_actor_move_dir_vel(&en->actor);
	z_actor_find_bounds(gl, &en->actor, 10.0f, /* collider_init.radius*/0x0D, /* collider_init.height*/0x0D, 5);
	z_collider_cylinder_update(&en->actor, &en->collider);
	(en->actor).flags |= 0x01000000;
	z_collider_set_at(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ac(gl, &gl->hit_ctxt, &en->collider);
	z_collider_set_ot(gl, &gl->hit_ctxt, &en->collider);
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = main,
	.draw = NULL
};
