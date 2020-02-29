#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

/*** object documentation ***/
#define OBJ_ID 							74 /* object_dekunuts */
#define SKL 								0x06003268 /* Skeleton */
/* Display Lists*/
#define	DL_HEAD 						0x060018C0
#define	DL_RFOOT 						0x060019F8
#define	DL_RTHIGH 					0x06001AA8
#define	DL_TORSO 						0x06001B48
#define	DL_SNOUT 						0x06001BF0
#define	DL_LTHIGH 					0x06001D08
#define	DL_LFOOT 						0x06001DA8
#define	DL_HAT 							0x06001E58
#define	DL_HAT_TIP 					0x06001F50
#define	DL_LEAF 						0x06002028
#define	DL_FLOWER 					0x06002298
/* Animations */
#define ANIM_SHOOT_DEKU_NUT 0x060001C4
#define	ANIM_STUN_SPIN 			0x06000368
#define	ANIM_BURROW 				0x060004D8
#define	ANIM_DEAD_FALL 			0x060006B0
#define	ANIM_JUMP 					0x060008C4
#define	ANIM_LOOK_AROUND 		0x06000AF0
#define	ANIM_RISE 					0x06000D1C
#define	ANIM_IDLE 					0x06000E6C
#define	ANIM_FLINCHING 			0x06001024
#define	ANIM_FLAIL 					0x06003650
/* Skeleton Limbs */
#define	L_ROOT              1
#define	L_BLANK0            2
#define	L_BLANK1            3
#define	L_HEAD  						4
#define	L_BLANK2  					5
#define	L_BLANK3						6
#define	L_SNOUT							7
#define	L_BLANK4						8
#define	L_BLANK5						9
#define	L_HAT								10
#define	L_BLANK6						11
#define	L_BLANK7						12
#define	L_HAT_TOP						13
#define	L_TORSO							14
#define	L_BLANK8						15
#define	L_BLANK9						16
#define	L_BLANKA						17
#define	L_LFOOT							18
#define	L_LTHIGH						19
#define	L_BLANKB						20
#define	L_BLANKC						21
#define	L_BLANKD						22
#define	L_RFOOT							23
#define	L_RTHIGH						24
#define LIMB_TOTAL 					24
/* Sound Effects */
#define NA_SE_EN_STAL_DEAD 			0x393B
#define NA_SE_EN_NUTS_UP 				0x387C
#define NA_SE_EN_NUTS_DOWN 			0x387D
#define NA_SE_EN_NUTS_THROW 		0x387E
#define NA_SE_EN_NUTS_WALK 			0x387F
#define NA_SE_EN_NUTS_DAMAGE 		0x3880
#define NA_SE_EN_NUTS_DEAD 			0x3881
#define NA_SE_EN_NUTS_FAINT 		0x3882
#define NA_SE_EN_GOMA_JR_FREEZE 0x389E

typedef struct {
	z64_actor_t actor;
	/* uint8_t[16] debug_ex; */
	z64_skelanime_t skelanime;
	uint8_t dekunuts_ex_0[4];
	z64_actorfunc_t* machine_state;
	uint8_t inst0194;
	uint8_t inst0195;
	uint16_t inst0196;
	uint16_t inst0198;
	uint16_t inst019A;
	vec3s_t dt_rot[LIMB_TOTAL + 1];
	vec3s_t dt_pos[LIMB_TOTAL + 1];
	z64_collider_cylinder_main_t collider;
} entity_t; /* 0314 */


/*** function prototypes ***/
static void dest_809E96C8(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void func_809E9770(entity_t* en); /* Rewritten; Working */
static void func_809E97B8(entity_t* en); /* Rewritten; Working */
static void func_809E9920(entity_t* en); /* Rewritten; Working */
static void func_809E9978(entity_t* en); /* Rewritten; Working */
static void func_809E9800(entity_t* en); /* Rewritten; Working */
static int32_t callback_809EA98C(z64_global_t* gl, int32_t limb, uint32_t* dlist, vec3f_t* translation, vec3s_t* rotation, void* _en); /* Rewritten; Working */
static void func_809E9868(entity_t* en); /* Rewritten; Working */
static void func_809E9B48(entity_t* en); /* Rewritten; Working */
static void func_809E98B4(entity_t *en); /* Rewritten; Working */
static void draw_809EAAC4(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void func_809E96FC(entity_t* en);  /* Rewritten; Working */
static void func_809E9AB4(entity_t *en); /* Rewritten; Working */
static void func_809E99D8(entity_t* en); /* Rewritten; Working */
static void data_809EA5B0(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void data_809EA4E8(entity_t *en); /* Rewritten; Working */
static void data_809EA1D8(entity_t* en); /* Rewritten; Working */
static void data_809EA480(entity_t* en); /* Rewritten; Working */
static void data_809E9DFC(entity_t* en); /* Rewritten; Working */
static void init_809E9560(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void data_809EA0C4(entity_t* en); /* Rewritten; Working */
static void data_809E9F6C(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void data_809EA534(entity_t* en); /* Rewritten; Working */
static void data_809E9E80(entity_t* en); /* Rewritten; Working */
static void main_809EA82C(entity_t* en, z64_global_t* gl); /* Rewritten; Working */
static void data_809EA240(entity_t* en); /* Rewritten; Working */
static void data_809E9B98(entity_t* en); /* Rewritten; Working */
static void func_809EA70C(entity_t* en, z64_global_t *gl); /* Rewritten; Working */

/*** Bugs ***/

/*** variables ***/

typedef enum {
	NONE,
	STUN,
	FIRE
} DAMAGE_FX;

const z64_collider_cylinder_init_t collider_data = {
    . body = {
        .unk_0x14 = 0x06,
        .collider_flags = 0x00,
        .collide_flags = 0x09,
        .mask_a = 0x39,
        .mask_b = 0x10,
        .type = COL_TYPE_CYLINDER,
        .unk_0x06_ = 0x0000,
        .body_flags = 0x00,
        .unk_0x09_ = 0x000000,
        .toucher_mask = 0x00000000,
        .bumper_effect = BUMP_FX_KNOCKBACK,
        .toucher_damage = 0x00,
        .unk_0x12_ = 0x0000,
        .bumper_mask = 0xFFCFFFFF,
        .unk_0x18_ = 0x00000000,
        .toucher_flags = 0x00,
        .bumper_flags = 0x01,
        .body_flags_2 = 0x01,
        .unk_0x1F = 0x00
    },
    .radius = 18,
    .height = 32,
    .y_shift = 0,
    .position = {
        .x = 0,
        .y = 0,
        .z = 0
    }
};

/*
.littlespin.sword2 = 0x01;
.magic_arrow.shadow = 0x00;
.magic.fire = 0x12;
.magic.ice = 0x00;
.magic.light = 0x20;
.littlespin.sword0 = 0xFF;
*/
const uint32_t damage_chart_a2[] =
{
	0x01000012,
	0x0020FF00
};

z64_damagechart_init_t damage_chart = {
.nut = Z_DAMAGE(0, STUN), .entry01 = 0x02, .slingshot = 0x01, .explode = 0x02,
.boomerang = 0x01, .arrow = 0x02, .hammer_swing = 0x02, .hookshot = 0x02,
.slash.sword0 = 0x01, .slash.sword1 = 0x02, .slash.sword2 = 0x04, .magic_arrow.fire = Z_DAMAGE(4, FIRE),
.magic_arrow.ice = 0x02, .magic_arrow.light = 0x02, .magic_arrow.wind = 0x02, .magic_arrow.spirit = 0x02,
.magic_arrow.shadow = 0x02, .magic.fire = Z_DAMAGE(4, FIRE), .magic.ice = 0x00, .magic.light = 0x00,
.unk_00 = 0x00, .unk_01= 0x00, .littlespin.sword0 = 0x01, .littlespin.sword2 = 0x04,
.littlespin.sword1 = 0x02, .entry19 = 0x02, .entry1A = 0x08, .entry1B = 0x04,
.unk_02 = 0x00, .unk_03 = 0x00, .hammer_jump = 0x04, .unk_04 = 0x00
};

const uint32_t ichain[] =
{
    ICHAIN(ICHAIN_S8, navi_enemy_text_id, 0x4D)
    , ICHAIN(ICHAIN_F, gravity, 0xFFFF)
    , ICHAIN(ICHAIN_F, unk_07_, 2600) & ICHAIN_LAST
};

/*** functions ***/
static void dest_809E96C8(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 14 lines */
{
	if ((en->actor).variable != 0x000A)
		z_collider_cylinder_free(gl, &en->collider);
}

static void func_809E9770(entity_t* en) /* 0 internal, 1 external, 18 lines */
{
	z_skelanime_anim_set(&en->skelanime, ANIM_LOOK_AROUND);
	en->inst0196 = 2;
	en->machine_state = (z64_actorfunc_t*)data_809E9DFC;
}

static void func_809E97B8(entity_t* en) /* 0 internal, 1 external, 18 lines */
{
	z_skelanime_change_anim_inst(&en->skelanime, ANIM_SHOOT_DEKU_NUT, en);
	en->machine_state = (z64_actorfunc_t*)data_809E9F6C;
	en->inst0196 = en->inst019A;
}

static void func_809E9920(entity_t* en) /* 0 internal, 1 external, 22 lines */
{
	uint8_t col_flags;

	z_skelanime_anim_set(&en->skelanime, ANIM_FLAIL);
	col_flags = (en->collider).base.collide_flags;
	en->inst0196 = 2;
	en->inst0194 = 0;
	(en->collider).base.collide_flags = col_flags | 1;
	en->machine_state = (z64_actorfunc_t*)data_809EA240;
}

static void func_809E9978(entity_t* en) /* 0 internal, 1 external, 25 lines */
{
	uint8_t uVar1;

	z_skelanime_anim_set(&en->skelanime, ANIM_FLINCHING);
	uVar1 = en->inst0195;
	en->inst0196 = 3;
	(en->actor).xz_speed = 0.0f;
	if (uVar1 != 0)
		en->inst0195 = uVar1 - 1;
	en->machine_state = (z64_actorfunc_t*)data_809EA480;
}

static void func_809E9800(entity_t* en) /* 0 internal, 1 external, 28 lines */
{
	z_skelanime_change_frame_count(&en->skelanime, ANIM_IDLE, -3.0f);
	if (en->machine_state == (z64_actorfunc_t*)data_809E9F6C)
		en->inst0196 = 0x1002;
	else
		en->inst0196 = 1;
	en->machine_state = (z64_actorfunc_t*)data_809E9E80;
}

static int32_t callback_809EA98C(z64_global_t* gl, int32_t limb, uint32_t* dlist, vec3f_t* translation, vec3s_t* rotation, void* _en) /* 0 internal, 1 external, 84 lines */
{
	entity_t* en = _en;
	float frame_now;
	float x;
	float y;

	/* If Limb 7 and Shooting a Deku Nut */
	if ((limb == (L_SNOUT)) && (en->machine_state == (z64_actorfunc_t*)data_809E9F6C))
	{
		frame_now = (en->skelanime).anim_current_frame;
		if (frame_now <= 6.0f)
		{
			x = 1.0f - frame_now * 0.0833f;
			y = frame_now * 0.1167f + 1.0f;
		}
		else
		{
			if (frame_now <= 7.0f)
			{
			x = (frame_now - 6.0f) + 0.5f;
			y = 1.7f - (frame_now - 6.0f) * 0.7f;
			}
			else
			{
				if (frame_now > 10.0f)
					return 0;

				x = 1.5f - (frame_now - 7.0f) * 0.1667f;
				y = 1.0f;
			}
		}
		z_matrix_scale_3f(x, y, y, 1);
	}
	return 0;
}

static void func_809E9868(entity_t* en) /* 0 internal, 2 external, 19 lines */
{
	z_skelanime_change_anim_trate(&en->skelanime, ANIM_BURROW, -5.0f);
	z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_DOWN);
	en->machine_state = (z64_actorfunc_t*)data_809EA0C4;
}

static void func_809E9B48(entity_t* en) /* 0 internal, 2 external, 20 lines */
{
	z_skelanime_change_anim_inst(&en->skelanime, ANIM_DEAD_FALL, en);
	en->machine_state = (z64_actorfunc_t*)data_809EA5B0;
	(en->actor).xz_speed = 0.0f;
	z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_DEAD);
}

static void func_809E98B4(entity_t *en) /* 0 internal, 2 external, 27 lines */
{
	uint8_t col_flags;

	z_skelanime_change_anim_trate(&en->skelanime, ANIM_JUMP, -3.0f);
	(en->collider).height = 0x25;
	(en->actor).mass = 0x32;
	z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_DAMAGE); /*	NA_SE_EN_NUTS_DAMAGE */
	col_flags = (en->collider).base.collide_flags;
	en->machine_state = (z64_actorfunc_t*)data_809EA1D8;
	(en->collider).base.collide_flags = col_flags & 0xFE;
}

static void draw_809EAAC4(entity_t* en, z64_global_t* gl) /* 0 internal, 2 external, 29 lines */
{
	if ((en->actor).variable == 0x000A)
		z_cheap_proc_draw_opa(gl, DL_FLOWER);
	else
	{
		z_skelanime_draw(
			gl
			, (en->skelanime).limb_index
			, (en->skelanime).draw_table_rot
			, &callback_809EA98C
			, 0
			, &en->actor
		);
	}
}

static void func_809E96FC(entity_t* en) /* 0 internal, 3 external, 29 lines */
{
	z_skelanime_change_anim_bframe(&en->skelanime, ANIM_RISE, 0);
	en->inst0196 = z_lib_math_rand_s16_offset(100, 50);
	(en->collider).height = 5;
	z_lib_vec3f_copy(&(en->actor).pos_2, &(en->actor).pos_1);
	(en->collider).base.collide_flags &= 0xFE;
	en->machine_state = (z64_actorfunc_t*)data_809E9B98;
}

static void func_809E9AB4(entity_t *en) /* 0 internal, 4 external, 37 lines */
{
	z_skelanime_change_frame_count(&en->skelanime, ANIM_STUN_SPIN, -3.0);
	en->inst0196 = 5; /* Stun Timer, Animation is played this many times. */
	en->machine_state = (z64_actorfunc_t*)data_809EA534;
	(en->actor).xz_speed = 0.0f;
	z_actor_play_sfx2(&en->actor, NA_SE_EN_GOMA_JR_FREEZE);
	z_actor_damage_color(&en->actor, 0, 0xFF, 0, (z_skelanime_anim_nframes(ANIM_STUN_SPIN) * en->inst0196));
}

static void func_809E99D8(entity_t* en) /* 0 internal, 5 external, 57 lines */
{
	int16_t yaw;

	z_skelanime_change_anim_trate(&en->skelanime, ANIM_STUN_SPIN, -3.0f);

	if (((uint32_t)(en->collider).body.colliding & 0x1F824) == 0)
	{
		yaw = z_actor_math_yaw_actor(&en->actor, (en->collider).base.unk_actor_2);
		(en->actor).xz_dir = yaw + -0x8000;
	}
	else
		(en->actor).xz_dir = ((en->collider).base.unk_actor_2)->xz_dir;

	(en->collider).base.collide_flags &= 0xFE;
	en->machine_state = (z64_actorfunc_t*)data_809EA4E8;
	(en->actor).xz_speed = 10.0f;
	z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_DAMAGE);
	z_actor_play_sfx2(&en->actor, NA_SE_EN_STAL_DEAD);
	z_actor_damage_color(&en->actor, 0x4000, 0xFF, 0, z_skelanime_anim_nframes(ANIM_STUN_SPIN));
}

static void data_809EA5B0(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 89 lines */
{
	z64_actor_t *attach = (en->actor).attached_b;
	vec3f_t effect_coordinates = (en->actor).pos_2;
	vec3f_t data_809EABB0 = {0, 0, 0};
	uint32_t smoke_inner_color = 0xFFFFFFFF;
	uint32_t smoke_outer_color = 0x00969696;

	if (z_skelanime_draw_table(&en->skelanime))
	{
		/* Smoke Cloud */
		effect_coordinates.y += 18.0f;
		z_effect_spawn_dead_db(
			gl
			, &effect_coordinates
			, &data_809EABB0
			, &data_809EABB0
			, 200
			, 0
			, RED32(smoke_inner_color), GREEN32(smoke_inner_color), BLUE32(smoke_inner_color)
			, ALPHA32(smoke_inner_color)
			, RED24(smoke_outer_color), GREEN24(smoke_outer_color), BLUE24(smoke_outer_color)
			, 1
			, 13 /* Frames */
			, 1
		);

		/* Leaves */
		effect_coordinates.y = (en->actor).pos_2.y + 10.0f;
		z_effect_spawn_hahen_n(
			gl
			, &effect_coordinates
			, 3.0f
			, 0
			, 0x0C
			, 3
			, 0x0F
			, -1
			, 10
			, 0
		);

		/* Drop Item on Death */
		z_item_drop_random(gl, &en->actor, &(en->actor).pos_2, 0x0030);

		if (attach != 0)
			z_actor_type_change(gl, &gl->actor_ctxt, attach, OVLTYPE_PROP);

		z_actor_kill(&en->actor);
	}
}

static void data_809EA4E8(entity_t *en) /* 1 internal, 2 external, 20 lines */
{
  z_lib_approx_f(&(en->actor).xz_speed, 0.0f, 1.0f);
  if (z_skelanime_draw_table(&en->skelanime))
    func_809E9B48(en);
}

static void data_809EA1D8(entity_t* en) /* 1 internal, 2 external, 27 lines */
{
	if (z_skelanime_draw_table(&en->skelanime))
	{
		en->inst0195 = 3;
		en->inst0198 = (en->actor).rot_toward_link_y + 0x8000;
		func_809E9920(en);
	}
	z_lib_smooth_scale_max_s(&(en->actor).rot_2.y, (en->actor).rot_toward_link_y, 2, 0xE38);
}

static void data_809EA480(entity_t* en) /* 1 internal, 2 external, 28 lines */
{
  z_skelanime_draw_table(&en->skelanime);
  if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
    en->inst0196--;
  if (!en->inst0196)
    func_809E9920(en);
}

static void data_809E9DFC(entity_t* en) /* 1 internal, 2 external, 36 lines */
{
	z_skelanime_draw_table(&en->skelanime);
	if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
		en->inst0196--;
	if (((en->actor).dist_from_link_xz < 120.0f) || (!en->inst0196))
		func_809E9868(en);
}

static void init_809E9560(entity_t* en, z64_global_t* gl) /* 1 internal, 7 external, 94 lines */
{
	z64_actor_t* flower_pad;

	z_lib_ichain_init(&en->actor, ichain);
	if ((en->actor).variable == 0x000A)
		(en->actor).flags &= 0xFFFFFFFA;
	else
	{
		z_actor_shadow_init(&(en->actor).rot_2, 0, &Z_SHADOW_CIRCLE, 35.0f);
		z_skelanime_init(gl, &en->skelanime, SKL, ANIM_IDLE, en->dt_rot, en->dt_pos, (LIMB_TOTAL + 1));
		z_collider_cylinder_alloc(gl, &en->collider);
		z_collider_cylinder_init(gl, &en->collider, &en->actor, &collider_data);
		z_actor_damage_table_init(&(en->actor).damage_table, &damage_chart, damage_chart_a2);
		en->inst019A = (en->actor).variable >> 8 & 0xFF;
		(en->actor).variable &= 0xFF;
		if ((en->inst019A == 0xFF) || !(en->inst019A))
			en->inst019A = 1;
		func_809E96FC(en);
		flower_pad = z_actor_spawn_attached(
			gl->actor_ctxt
			, &en->actor
			, gl
			, 0x0060
			, (en->actor).pos_2.x
			, (en->actor).pos_2.y
			, (en->actor).pos_2.z
			, 0
			, (en->actor).xz_dir
			, 0
			, 0x000A
		);
	}
}

static void data_809EA0C4(entity_t* en) /* 1 internal, 3 external, 75 lines */
{
	int32_t iVar1;
	int32_t iVar2;
	float frame;

	iVar1 = z_skelanime_draw_table(&en->skelanime);
	if (iVar1 == 0)
	{
	  frame = (en->skelanime).anim_current_frame;
	  if (frame < 1.0f)
	  {
	    frame = 1.0f;
	  }
	  else
	  {
	    if (3.0f < frame)
	    {
	      frame = 3.0f;
	    }
	  }
	  (en->collider).height = (3.0f - frame) * 12.0f + 5.0f;
	}
	else
	{
	  func_809E96FC(en);
	}
	iVar2 = z_skelanime_frame_index_test(&en->skelanime, 4.0f);
	if (iVar2 != 0)
	{
	  (en->collider).base.collide_flags &= 0xFE;
	}
	z_lib_smooth_scale_max_f(&(en->actor).pos_2.x, (en->actor).pos_1.x, 0.5f, 3.0f);
	z_lib_smooth_scale_max_f(&(en->actor).pos_2.z, (en->actor).pos_1.z, 0.5f, 3.0f);
}

static void data_809E9F6C(entity_t* en, z64_global_t* gl) /* 1 internal, 8 external, 90 lines */
{
  z64_actor_t *deku_nut;

	z_lib_smooth_scale_max_s(&(en->actor).rot_2.y, (en->actor).rot_toward_link_y, 2, 0xE38);
  if (!(z_skelanime_draw_table(&en->skelanime)))
	{
    if (!(z_skelanime_frame_index_test(&en->skelanime, 6.0f)))
		{
			if ((!(z_skelanime_frame_index_test(&en->skelanime, 12.0f))) && (en->inst0196 > 1))
			{
					z_skelanime_change_anim_trate(&en->skelanime, ANIM_SHOOT_DEKU_NUT, -3.0f);
					if (en->inst0196)
						en->inst0196--;
			}
    }
    else
		{
      deku_nut = z_actor_spawn(
				&gl->actor_ctxt
				, gl
				, 0x0193
				, (z_sin_s((en->actor).rot_2.y)) * 23.0f + (en->actor).pos_2.x
				, (en->actor).pos_2.y + 12.0f
        , (z_cos_s((en->actor).rot_2.y)) * 23.0f + (en->actor).pos_2.z
				, (en->actor).rot_2.x
				, (en->actor).rot_2.y
				, (en->actor).rot_2.z
				, 0x0000
			);
      if (deku_nut)
        z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_THROW);
    }
  }
  else
    func_809E9800(en);
}

static void data_809EA534(entity_t* en) /* 1 internal, 3 external, 35 lines */
{
  z_skelanime_draw_table(&en->skelanime);
  if (z_skelanime_frame_index_test(&en->skelanime, 0))
	{
    if (en->inst0196)
      en->inst0196--;
    else if (!en->inst0196)
      func_809E9920(en);
    else
      z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_FAINT);
  }
}

static void data_809E9E80(entity_t* en) /* 2 internal, 3 external, 65 lines */
{
  z_skelanime_draw_table(&en->skelanime);
  if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
    en->inst0196--;
  if ((en->inst0196 & 0x1000) == 0)
    z_lib_smooth_scale_max_s(&(en->actor).rot_2.y, (en->actor).rot_toward_link_y, 2, 0xE38);
  if (en->inst0196 == 0x1000)
	{
    if ((480.0f < (en->actor).dist_from_link_xz) || ((en->actor).dist_from_link_xz < 120.0f))
      func_809E9868(en);
    else
      func_809E97B8(en);
  }
  else if (en->inst0196 == 0)
      func_809E97B8(en);
}

static void main_809EA82C(entity_t* en, z64_global_t* gl) /* 1 internal, 7 external, 93 lines */
{
	int32_t iVar1;
	z64_actorfunc_t* state_func = en->machine_state;

  if ((en->actor).variable != 0x000A)
	{
    func_809EA70C(en, gl);
		state_func(en, gl);
    z_actor_move_dir_vel(&en->actor);
    z_actor_find_bounds(gl, &en->actor, 20.0f, (en->collider).radius, (en->collider).height, 0x1D);
    z_collider_cylinder_update(&en->actor, &en->collider);
    if (((en->collider).base.collide_flags & 1) != 0)
		{
      z_collider_set_ac(gl, &gl->hit_ctxt, &en->collider);
    }
    z_collider_set_ot(gl, &gl->hit_ctxt, &en->collider);
    if (en->machine_state == (z64_actorfunc_t*)data_809E9B98)
		{
      z_actor_set_height(&en->actor, (en->skelanime).anim_current_frame);
    }
    else
		{
      if (en->machine_state == (z64_actorfunc_t*)data_809EA0C4)
			{
        iVar1 = z_skelanime_anim_nframes(ANIM_BURROW);
        z_actor_set_height(&en->actor, 20.0f - ((en->skelanime).anim_current_frame * 20.0f) / iVar1);
      }
      else {
        z_actor_set_height(&en->actor, 20.0f);
      }
    }
  }
}

static void data_809EA240(entity_t* en) /* 2 internal, 7 external, 158 lines */
{
	uint8_t bVar1;
	int16_t sVar2;
	int32_t iVar3;
	uint16_t uVar4;
	uint16_t uVar5;
	int32_t iVar6;
	int32_t iVar7;
	float fVar8;

	z_skelanime_draw_table(&en->skelanime);
	iVar3 = z_skelanime_frame_index_test(&en->skelanime, 0);
	if ((iVar3 != 0) && (en->inst0196 != 0))
	{
		en->inst0196 = en->inst0196 - 1;
	}
	if (en->inst0194 == 0)
	{
		en->inst0194 = 1;
	}
	else
	{
		z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_WALK );
		en->inst0194 = 0;
	}
	iVar3 = z_lib_approx_f(&(en->actor).xz_speed, 7.5f, 1.0f);
	z_lib_smooth_scale_max_min_s(&(en->actor).xz_dir, en->inst0198, 1, 0xE38, 0xB6);
	if (iVar3 == 0)
	{
		uVar5 = (en->actor).bgcheck_flags;
		if ((uVar5 & 0x20) == 0)
		{
			if ((uVar5 & 8) == 0)
			{
				if (en->inst0195 == 0)
				{
					uVar5 = z_actor_math_yaw_vec3f(&en->actor, &(en->actor).pos_1);
					iVar7 = (en->actor).rot_toward_link_y;
					iVar6 = (uVar5 - iVar7) * 0x10000 >> 0x10;
					iVar3 = -iVar6;
					if (-1 < iVar6)
					{
						iVar3 = iVar6;
					}
					if (iVar3 < 0x2001)
					{
						if (0.0f <= iVar6)
						{
							fVar8 = 1.0f;
						}
						else
						{
							fVar8 = -1.0f;
						}
						en->inst0198 = fVar8 * -8192.0f + iVar7;
					}
					else
					{
						en->inst0198 = uVar5;
					}
				}
				else
				{
					en->inst0198 = (en->actor).rot_toward_link_y + 0x8000;
				}
			}
			else
			{
				en->inst0198 = (en->actor).wall_rot;
			}
		}
		else
		{
			uVar4 = z_actor_math_yaw_vec3f(&en->actor, &(en->actor).pos_1);
			en->inst0198 = uVar4;
		}
		sVar2 = (en->actor).xz_dir;
	}
	else
	{
		sVar2 = (en->actor).xz_dir;
	}
	bVar1 = en->inst0195;
	(en->actor).rot_2.y = sVar2 + -0x8000;
	if (bVar1 == 0)
	{
		fVar8 = z_actor_math_dist_xz_vec3f(&en->actor, &(en->actor).pos_1);
		if (fVar8 < 20.0f)
		{
			if (ABS((en->actor).pos_2.y - (en->actor).pos_1.y) < 2.0f)
			{
				(en->actor).mass = -1;
				(en->actor).xz_speed = 0.0f;
				func_809E9868(en);
				return;
			}
			uVar4 = en->inst0196;
		}
		else
		{
			uVar4 = en->inst0196;
		}
	}
	else
	{
		uVar4 = en->inst0196;
	}
	if (uVar4 == 0)
	{
		func_809E9978(en);
	}
}

static void data_809E9B98(entity_t* en) /* 3 internal, 3 external, 169 lines */
{
	int32_t bVar1;
	int32_t iVar2;
	int32_t iVar3;
	float fVar4;

	bVar1 = (en->skelanime).anim_playback_speed < 0.5f;
	if ((bVar1) && (en->inst0196 != 0))
	{
		en->inst0196 = en->inst0196 - 1;
	}
	iVar2 = z_skelanime_frame_index_test(&en->skelanime, 9.0f);
	if (iVar2 == 0)
	{
		iVar2 = z_skelanime_frame_index_test(&en->skelanime, 8.0f);
		if (iVar2 != 0)
		{
			z_actor_play_sfx2(&en->actor, NA_SE_EN_NUTS_UP);
		}
	}
	else
	{
		(en->collider).base.collide_flags |= 1;
	}
	fVar4 = (en->skelanime).anim_current_frame;
	if (fVar4 < 9.0f)
	{
		fVar4 = 9.0f;
	}
	else
	{
		if (12.0f < fVar4)
		{
			fVar4 = 12.0f;
		}
	}
	(en->collider).height = (fVar4 - 9.0f) * 9.0f + 5.0f;
	if ((bVar1) || (120.0f <= (en->actor).dist_from_link_xz))
	{
		iVar3 = z_skelanime_draw_table(&en->skelanime);
		if (iVar3 != 0)
		{
			fVar4 = (en->actor).dist_from_link_xz;
			if (fVar4 < 120.0f)
			{
				func_809E9868(en);
			}
			else
			{
				if ((en->inst0196 != 0) || (fVar4 <= 320.0f))
				{
					func_809E9800(en);
				}
				else
				{
					func_809E9770(en);
				}
			}
		}
	}
	else
	{
		func_809E9868(en);
	}
	if ((((bVar1) &&
			(fVar4 = (en->actor).dist_from_link_xz, 160.0f < fVar4)) &&
			(ABS((en->actor).dist_from_link_y) < 120.0f)) &&
		 	((en->inst0196 == 0 || (fVar4 < 480.0f))))
			{
				(en->skelanime).anim_playback_speed = 1.0f;
			}
}

static void func_809EA70C(entity_t* en, z64_global_t *gl) /* 3 internal, 4 external, 79 lines */
{
	uint8_t damage_fx;
  uint32_t uVar1;

  if (((en->collider).base.collide_flags & 2) == 0)
	{
    if (((en->actor).mass == -1) && (gl->actor_ctxt[2] != 0))
		{
      func_809E98B4(en);
    }
  }
  else
	{
    (en->collider).base.collide_flags &= 0xFD;
    external_func_80035650(&en->actor, &(en->collider).body, 1);
    if ((en->actor).mass == 0x32)
		{
      damage_fx = (en->actor).damage_effect;
      uVar1 = damage_fx;
      if ((damage_fx != NONE) || ((en->actor).damage != 0))
			{
        if (damage_fx == STUN)
				{
          if (en->machine_state != (z64_actorfunc_t*)data_809EA534)
					{
            func_809E9AB4(en);
          }
        }
        else
				{
          if (damage_fx == FIRE)
					{
            z_effect_spawn_flame_circle(gl, &en->actor, &(en->actor).pos_2, 0x28, 0x32);
          }
          func_809E99D8(en);
          z_actor_update_health(&en->actor);
          if (uVar1 == NONE)
					{
            z_actor_play_sound_defeated(gl, &en->actor);
          }
        }
      }
    }
    else
		{
      func_809E98B4(en);
    }
  }
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x05,
	.room = 0x00,
	.flags = 0x00000005,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init_809E9560,
	.dest = dest_809E96C8,
	.main = main_809EA82C,
	.draw = draw_809EAAC4
};
