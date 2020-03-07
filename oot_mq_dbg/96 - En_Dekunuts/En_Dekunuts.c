#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>
#include "En_Dekunuts.h"

typedef struct {
	z64_actor_t actor;
	/* uint8_t[16] debug_ex; */
	z64_skelanime_t skelanime;
	uint8_t dekunuts_ex_0[4];
	z64_actorfunc_t* state;
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
static void data_809E96C8(entity_t* en, z64_global_t* gl); /* 0 internal, 1 external, 14 lines */
static void func_809E9770(entity_t* en); /* 0 internal, 1 external, 18 lines */
static void func_809E97B8(entity_t* en); /* 0 internal, 1 external, 18 lines */
static void func_809E9920(entity_t* en); /* 0 internal, 1 external, 22 lines */
static void func_809E9978(entity_t* en); /* 0 internal, 1 external, 25 lines */
static void func_809E9800(entity_t* en); /* 0 internal, 1 external, 28 lines */
static int32_t data_809EA98C(z64_global_t* gl, int32_t limb, uint32_t* dlist, vec3f_t* translation, vec3s_t* rotation, void* _en); /* 0 internal, 1 external, 84 lines */
static void func_809E9868(entity_t* en); /* 0 internal, 2 external, 19 lines */
static void func_809E9B48(entity_t* en); /* 0 internal, 2 external, 20 lines */
static void func_809E98B4(entity_t* en); /* 0 internal, 2 external, 27 lines */
static void data_809EAAC4(entity_t* en, z64_global_t* gl); /* 0 internal, 2 external, 29 lines */
static void func_809E96FC(entity_t* en); /* 0 internal, 3 external, 29 lines */
static void func_809E9AB4(entity_t* en); /* 0 internal, 4 external, 37 lines */
static void func_809E99D8(entity_t* en); /* 0 internal, 5 external, 57 lines */
static void data_809EA5B0(entity_t* en, z64_global_t* gl); /* 0 internal, 6 external, 89 lines */
static void data_809EA4E8(entity_t* en); /* 1 internal, 2 external, 20 lines */
static void data_809EA1D8(entity_t* en); /* 1 internal, 2 external, 27 lines */
static void data_809EA480(entity_t* en); /* 1 internal, 2 external, 28 lines */
static void data_809E9DFC(entity_t* en); /* 1 internal, 2 external, 36 lines */
static void data_809E9560(entity_t* en, z64_global_t* gl); /* 1 internal, 7 external, 94 lines */
static void data_809EA0C4(entity_t* en); /* 1 internal, 3 external, 75 lines */
static void data_809E9F6C(entity_t* en, z64_global_t* gl); /* 1 internal, 8 external, 90 lines */
static void data_809EA534(entity_t* en); /* 1 internal, 3 external, 35 lines */
static void data_809E9E80(entity_t* en); /* 2 internal, 3 external, 65 lines */
static void data_809EA82C(entity_t* en, z64_global_t* gl); /* 1 internal, 7 external, 93 lines */
static void data_809EA240(entity_t* en); /* 2 internal, 7 external, 158 lines */
static void data_809E9B98(entity_t* en); /* 3 internal, 3 external, 169 lines */
static void func_809EA70C(entity_t* en, z64_global_t* gl); /* 3 internal, 4 external, 79 lines */


/*** variables ***/
typedef enum {
	NONE,
	STUN,
	FIRE
} DAMAGE_FX;

const z64_collider_cylinder_init_t data_809EAB50 = {
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

z64_damagechart_init_t data_809EAB84 = {
.nut = Z_DAMAGE(0, STUN)
, .entry01 = Z_DAMAGE(2, NONE) /* Deku Stick and Vase / Rock*/
, .slingshot = Z_DAMAGE(1, NONE)
, .explode = Z_DAMAGE(2, NONE)
, .boomerang = Z_DAMAGE(1, NONE)
, .hookshot = Z_DAMAGE(2, NONE)
, .slash.sword0 = Z_DAMAGE(1, NONE)
, .slash.sword1 = Z_DAMAGE(2, NONE)
, .slash.sword2 = Z_DAMAGE(4, NONE)
, .arrow = Z_DAMAGE(2, NONE)
, .magic_arrow.fire = Z_DAMAGE(4, FIRE)
, .magic_arrow.ice = Z_DAMAGE(2, NONE)
, .magic_arrow.light = Z_DAMAGE(2, NONE)
, .magic_arrow.wind = Z_DAMAGE(2, NONE)
, .magic_arrow.spirit = Z_DAMAGE(2, NONE)
, .magic_arrow.shadow = Z_DAMAGE(2, NONE)
, .magic.fire = Z_DAMAGE(4, FIRE)
, .littlespin.sword0 = Z_DAMAGE(1, NONE)
, .littlespin.sword1 = Z_DAMAGE(2, NONE)
, .littlespin.sword2 = Z_DAMAGE(4, NONE)
, .entry19 = Z_DAMAGE(2, NONE)
/* Kokiri Sword Jump Attack */
/* Kokiri Sword Spin Attack (Full Charge) */
/* Broken Giant's Knife Jump Attack */
/* Broken Giant's Knife Spin Attack (Full Charge) */
, .entry1A = Z_DAMAGE(8, NONE)
/* Biggoron Sword and Giant's Knife Jump Attack */
/* Biggoron Sword and Giant's Knife Spin Attack (Full Charge) */
, .entry1B = Z_DAMAGE(4, NONE)
/* Master Sword Jump Attack */
/* Master Sword Spin Attack (Full Charge) */
, .hammer_swing = Z_DAMAGE(2, NONE)
, .hammer_jump = Z_DAMAGE(4, NONE)
};

/*
.littlespin.sword2 = 0x01;
.magic_arrow.shadow = 0x00;
.magic.fire = 0x12;
.magic.ice = 0x00;
.magic.light = 0x20;
.littlespin.sword0 = 0xFF;
*/
const uint32_t data_809EAB7C[] =
{
	0x01000012,
	0x0020FF00
};

const uint32_t data_809EABA4[] =
{
    ICHAIN(ICHAIN_S8, navi_enemy_text_id, 0x4D)
    , ICHAIN(ICHAIN_F, gravity, 0xFFFF)
    , ICHAIN(ICHAIN_F, unk_07_, 2600) & ICHAIN_LAST
};


/*** functions ***/
static void data_809E96C8(entity_t* en, z64_global_t* gl)
{
	if ((en->actor).variable != VAR_FLOWER)
		z_collider_cylinder_free(gl, &en->collider);
}

static void func_809E9770(entity_t* en)
{
	z_skelanime_anim_set(&en->skelanime, ANIM_LOOK_AROUND);
	en->inst0196 = 2;
	en->state = (z64_actorfunc_t*)data_809E9DFC;
}

static void func_809E97B8(entity_t* en)
{
	z_skelanime_change_anim_inst(&en->skelanime, ANIM_SHOOT_DEKU_NUT, en);
	en->state = (z64_actorfunc_t*)data_809E9F6C;
	en->inst0196 = en->inst019A;
}

static void func_809E9920(entity_t* en)
{
	z_skelanime_anim_set(&en->skelanime, ANIM_FLAIL);
	en->inst0196 = 2;
	en->inst0194 = 0;
	(en->collider).base.collide_flags |= 1;
	en->state = (z64_actorfunc_t*)data_809EA240;
}

static void func_809E9978(entity_t* en)
{
	z_skelanime_anim_set(&en->skelanime, ANIM_FLINCHING);
	en->inst0196 = 3;
	(en->actor).xz_speed = 0.0f;
	if (en->inst0195)
		en->inst0195--;
	en->state = (z64_actorfunc_t*)data_809EA480;
}

static void func_809E9800(entity_t* en)
{
	z_skelanime_change_frame_count(&en->skelanime, ANIM_IDLE, -3.0f);
	if (en->state == (z64_actorfunc_t*)data_809E9F6C)
		en->inst0196 = 0x1002;
	else
		en->inst0196 = 1;
	en->state = (z64_actorfunc_t*)data_809E9E80;
}

static int32_t data_809EA98C(z64_global_t* gl, int32_t limb, uint32_t* dlist, vec3f_t* translation, vec3s_t* rotation, void* _en)
{
	entity_t* en = _en;
	float frame_now;
	float x;
	float y;

	/* If Limb 7 and Shooting a Deku Nut */
	if ((limb == (L_SNOUT)) && (en->state == (z64_actorfunc_t*)data_809E9F6C))
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

static void func_809E9868(entity_t* en)
{
	z_skelanime_change_anim_trate(&en->skelanime, ANIM_BURROW, -5.0f);
	z_actor_play_sfx2(&en->actor, SOUND_BURROW);
	en->state = (z64_actorfunc_t*)data_809EA0C4;
}

static void func_809E9B48(entity_t* en)
{
	z_skelanime_change_anim_inst(&en->skelanime, ANIM_DEAD_FALL, en);
	en->state = (z64_actorfunc_t*)data_809EA5B0;
	(en->actor).xz_speed = 0.0f;
	z_actor_play_sfx2(&en->actor, SOUND_KILLED);
}

static void func_809E98B4(entity_t* en)
{
	z_skelanime_change_anim_trate(&en->skelanime, ANIM_JUMP, -3.0f);
	(en->collider).height = 0x25;
	(en->actor).mass = 0x32;
	z_actor_play_sfx2(&en->actor, SOUND_DAMAGE);
	en->state = (z64_actorfunc_t*)data_809EA1D8;
	(en->collider).base.collide_flags &= 0xFE;
}

static void data_809EAAC4(entity_t* en, z64_global_t* gl)
{
	if ((en->actor).variable == VAR_FLOWER)
		z_cheap_proc_draw_opa(gl, DL_FLOWER);
	else
	{
		z_skelanime_draw(gl, 0, en, &en->skelanime, &data_809EA98C, 0);
	}
}

static void func_809E96FC(entity_t* en)
{
	z_skelanime_change_anim_bframe(&en->skelanime, ANIM_RISE, 0);
	en->inst0196 = z_lib_math_rand_s16_offset(100, 50);
	(en->collider).height = 5;
	z_lib_vec3f_copy(&(en->actor).pos_2, &(en->actor).pos_1);
	(en->collider).base.collide_flags &= 0xFE;
	en->state = (z64_actorfunc_t*)data_809E9B98;
}

static void func_809E9AB4(entity_t* en)
{
	z_skelanime_change_frame_count(&en->skelanime, ANIM_STUN_SPIN, -3.0);
	en->inst0196 = 5; /* Stun Timer, Animation is played this many times. */
	en->state = (z64_actorfunc_t*)data_809EA534;
	(en->actor).xz_speed = 0.0f;
	z_actor_play_sfx2(&en->actor, SOUND_STUN);
	z_actor_damage_color(&en->actor, 0, 0xFF, 0, (z_skelanime_anim_nframes(ANIM_STUN_SPIN) * en->inst0196));
}

static void func_809E99D8(entity_t* en)
{
	int16_t yaw;

	z_skelanime_change_anim_trate(&en->skelanime, ANIM_STUN_SPIN, -3.0f);

	if (((uint32_t)(en->collider).body.colliding & 0x1F824) == 0)
	{
		yaw = z_actor_math_yaw_actor(&en->actor, (en->collider).base.colliding_actor);
		(en->actor).xz_dir = yaw - 0x8000;
	}
	else
		(en->actor).xz_dir = ((en->collider).base.colliding_actor)->xz_dir;

	(en->collider).base.collide_flags &= 0xFE;
	en->state = (z64_actorfunc_t*)data_809EA4E8;
	(en->actor).xz_speed = 10.0f;
	z_actor_play_sfx2(&en->actor, SOUND_DAMAGE);
	z_actor_play_sfx2(&en->actor, SOUND_SLASHED);
	z_actor_damage_color(&en->actor, 0x4000, 0xFF, 0, z_skelanime_anim_nframes(ANIM_STUN_SPIN));
}

static void data_809EA5B0(entity_t* en, z64_global_t* gl)
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

static void data_809EA4E8(entity_t* en)
{
	z_lib_approx_f(&(en->actor).xz_speed, 0.0f, 1.0f);
  if (z_skelanime_draw_table(&en->skelanime))
    func_809E9B48(en);
}

static void data_809EA1D8(entity_t* en)
{
	if (z_skelanime_draw_table(&en->skelanime))
	{
		en->inst0195 = 3;
		en->inst0198 = (en->actor).rot_toward_link_y + 0x8000;
		func_809E9920(en);
	}
	z_lib_smooth_scale_max_s(&(en->actor).rot_2.y, (en->actor).rot_toward_link_y, 2, 0xE38);
}

static void data_809EA480(entity_t* en)
{
	z_skelanime_draw_table(&en->skelanime);
  if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
    en->inst0196--;
  if (!en->inst0196)
    func_809E9920(en);
}

static void data_809E9DFC(entity_t* en)
{
	z_skelanime_draw_table(&en->skelanime);
	if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
		en->inst0196--;
	if (((en->actor).dist_from_link_xz < 120.0f) || (!en->inst0196))
		func_809E9868(en);
}

static void data_809E9560(entity_t* en, z64_global_t* gl)
{
	z64_actor_t* flower_pad;

	z_lib_ichain_init(&en->actor, data_809EABA4);
	if ((en->actor).variable == VAR_FLOWER)
		(en->actor).flags &= 0xFFFFFFFA;
	else
	{
		z_actor_shadow_init(&(en->actor).rot_2, 0, &Z_SHADOW_CIRCLE, 35.0f);
		_z_skelanime_init(gl, &en->skelanime, SKL, ANIM_IDLE, en->dt_rot, en->dt_pos, (LIMB_TOTAL + 1));
		z_collider_cylinder_alloc(gl, &en->collider);
		z_collider_cylinder_init(gl, &en->collider, &en->actor, &data_809EAB50);
		z_actor_damage_table_init(&(en->actor).damage_table, &data_809EAB84, data_809EAB7C);
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
			, VAR_FLOWER
		);
	}
}

static void data_809EA0C4(entity_t* en)
{
	int32_t iVar1;
	int32_t iVar2;
	float frame;

	if (!(z_skelanime_draw_table(&en->skelanime)))
	{
	  frame = (en->skelanime).anim_current_frame;
	  if (frame < 1.0f)
	    frame = 1.0f;
	  else if (3.0f < frame)
	      frame = 3.0f;
	  (en->collider).height = (3.0f - frame) * 12.0f + 5.0f;
	}
	else
	  func_809E96FC(en);

	if (z_skelanime_frame_index_test(&en->skelanime, 4.0f))
	  (en->collider).base.collide_flags &= 0xFE;

	z_lib_smooth_scale_max_f(&(en->actor).pos_2.x, (en->actor).pos_1.x, 0.5f, 3.0f);
	z_lib_smooth_scale_max_f(&(en->actor).pos_2.z, (en->actor).pos_1.z, 0.5f, 3.0f);
}

static void data_809E9F6C(entity_t* en, z64_global_t* gl)
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
        z_actor_play_sfx2(&en->actor, SOUND_SPIT);
    }
  }
  else
    func_809E9800(en);
}

static void data_809EA534(entity_t* en)
{
	z_skelanime_draw_table(&en->skelanime);
	if (z_skelanime_frame_index_test(&en->skelanime, 0))
	{
		if (en->inst0196)
		{
			en->inst0196--;
		}
		if (!(en->inst0196))
			func_809E9920(en);
		else
			z_actor_play_sfx2(&en->actor, SOUND_FAINT);
	}
}

static void data_809E9E80(entity_t* en)
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

static void data_809EA82C(entity_t* en, z64_global_t* gl)
{
  if ((en->actor).variable != VAR_FLOWER)
	{
    func_809EA70C(en,gl);
    (*en->state)(en,gl);
    z_actor_move_dir_vel(&en->actor);
    z_actor_find_bounds(gl, &en->actor, 20.0f, (en->collider).radius, (en->collider).height, 0x1D);
    z_collider_cylinder_update(&en->actor, &en->collider);
    if (((en->collider).base.collide_flags & 1) != 0)
      z_collider_set_ac(gl, &gl->hit_ctxt, &en->collider);
    z_collider_set_ot(gl, &gl->hit_ctxt, &en->collider);
    if (en->state == (z64_actorfunc_t*)data_809E9B98)
      z_actor_set_height(&en->actor, (en->skelanime).anim_current_frame);
    else
		{
      if (en->state == (z64_actorfunc_t*)data_809EA0C4)
        z_actor_set_height(&en->actor, 20.0f - ((en->skelanime).anim_current_frame * 20.0f) / z_skelanime_anim_nframes(ANIM_BURROW));
      else
        z_actor_set_height(&en->actor, 20.0f);
    }
  }
}

/* The NSA says hello. */
static void data_809EA240(entity_t* en)
{
	uint8_t bVar1;
	int16_t xz_dir;
	int32_t xz_vel_approx;
	uint16_t uVar4;
	uint16_t bg_chk;
	int32_t iVar6;
	int32_t iVar7;
	float fVar8;

	z_skelanime_draw_table(&en->skelanime);
	if ((z_skelanime_frame_index_test(&en->skelanime, 0)) && (en->inst0196))
		en->inst0196--;
	if (!(en->inst0194))
		en->inst0194 = 1;
	else
	{
		z_actor_play_sfx2(&en->actor, SOUND_WALK);
		en->inst0194 = 0;
	}
	xz_vel_approx = z_lib_approx_f(&(en->actor).xz_speed, 7.5f, 1.0f);
	z_lib_smooth_scale_max_min_s(&(en->actor).xz_dir, en->inst0198, 1, 0xE38, 0xB6);
	if (xz_vel_approx == 0)
	{
		bg_chk = (en->actor).bgcheck_flags;
		if ((bg_chk & 0x20) == 0)
		{
			if ((bg_chk & 8) == 0)
			{
				if (en->inst0195 == 0)
				{
					iVar7 = (en->actor).rot_toward_link_y;
					iVar6 = ((z_actor_math_yaw_vec3f(&en->actor, &(en->actor).pos_1)) - iVar7) * 0x10000 >> 0x10;
					xz_vel_approx = -iVar6;
					if (-1 < iVar6)
					{
						xz_vel_approx = iVar6;
					}
					if (xz_vel_approx < 0x2001)
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
						en->inst0198 = z_actor_math_yaw_vec3f(&en->actor, &(en->actor).pos_1);
				}
				else
					en->inst0198 = (en->actor).rot_toward_link_y + 0x8000;
			}
			else
				en->inst0198 = (en->actor).wall_rot;
		}
		else
			en->inst0198 = z_actor_math_yaw_vec3f(&en->actor, &(en->actor).pos_1);
		xz_dir = (en->actor).xz_dir;
	}
	else
		xz_dir = (en->actor).xz_dir;
	bVar1 = en->inst0195;
	(en->actor).rot_2.y = xz_dir + -0x8000;
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

static void data_809E9B98(entity_t* en)
{
	float frame_now;

	if (((en->skelanime).anim_playback_speed < 0.5f) && (en->inst0196 != 0))
		en->inst0196--;
	if (z_skelanime_frame_index_test(&en->skelanime, 9.0f) == 0)
	{
		if (z_skelanime_frame_index_test(&en->skelanime, 8.0f) != 0)
			z_actor_play_sfx2(&en->actor, SOUND_EMERGE);
	}
	else
		(en->collider).base.collide_flags |= 1;
	frame_now = (en->skelanime).anim_current_frame;
	if (frame_now < 9.0f)
		frame_now = 9.0f;
	else if (12.0f < frame_now)
		frame_now = 12.0f;
	(en->collider).height = (frame_now - 9.0f) * 9.0f + 5.0f;
	if (((en->skelanime).anim_playback_speed < 0.5f) || (120.0f <= (en->actor).dist_from_link_xz))
	{
		if (z_skelanime_draw_table(&en->skelanime) != 0)
		{
			if ((en->actor).dist_from_link_xz < 120.0f)
				func_809E9868(en);
			else
			{
				if ((en->inst0196 != 0) || ((en->actor).dist_from_link_xz <= 320.0f))
					func_809E9800(en);
				else
					func_809E9770(en);
			}
		}
	}
	else
		func_809E9868(en);
	if ((en->skelanime).anim_playback_speed < 0.5f)
    if ((en->actor).dist_from_link_xz > 160.0f)
      if (ABS((en->actor).dist_from_link_y) < 120.0f)
        if ((en->inst0196 == 0 || ((en->actor).dist_from_link_xz < 480.0f)))
          (en->skelanime).anim_playback_speed = 1.0f;
}

static void func_809EA70C(entity_t* en, z64_global_t* gl)
{
	uint8_t damage_fx = (en->actor).damage_effect;

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
    z_actor_is_frozen(&en->actor, &(en->collider).body, 1);
    if ((en->actor).mass == 0x32)
		{
      if ((damage_fx != NONE) || ((en->actor).damage != 0))
			{
        if (damage_fx == STUN)
				{
          if (en->state != (z64_actorfunc_t*)data_809EA534)
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
          if (damage_fx == NONE)
					{
            z_actor_play_sound_defeated(gl, &en->actor);
          }
        }
      }
    }
    else
      func_809E98B4(en);
  }
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x05,
	.room = 0x00,
	.flags = 0x00000005,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = data_809E9560,
	.dest = data_809E96C8,
	.main = data_809EA82C,
	.draw = data_809EAAC4
};
