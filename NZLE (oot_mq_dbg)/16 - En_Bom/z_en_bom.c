/************
 * z_en_bom.c faithfully rewritten by CrookedPoe <nickjs.site>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit 94c9556d592130e4bf7f29accfaac4216f903cba
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>
#include <z64ovl/oot/gameplay_keep.h>

typedef struct {
	/* 0x0000 */ z64_actor_t actor; 						 // Base Actor
	/* 0x013C */ /* uint8_t[16] debug_ex */ 				 // Debug Only Padding
	/* 0x014C */ z64_collider_cylinder_t collider_c; 		 // Cylinder Collider
	/* 0x0198 */ z64_collider_jntsph_t collider_s; 			 // Sphere Collider
	/* 0x01B8 */ z64_collider_jntsph_item_t collider_s_item; // Sphere Collider Item
	/* 0x01F8 */ int16_t timer;                              // Frames left until explosion
	/* 0x01FA */ int16_t field_0x1fa;
	/* 0x01FC */ float field_0x1fc;
	/* 0x0200 */ uint8_t field_0x200;
	/* 0x0201 */ uint8_t ___pad[3];                          // Padding for Alignment
	/* 0x0204 */ z64_actorfunc_t *state; 					 // State Function
} entity_t; /* 0208 */


/*** function prototypes ***/
static void set_state(entity_t *en, z64_actorfunc_t *state);
static void destructor(entity_t *en, z64_global_t *gl);
static void handle_collider(entity_t *en, z64_global_t *gl); /* Expands collision radius and invokes rumble pak */
static void draw(entity_t *en, z64_global_t *gl);
static void constructor(entity_t *en, z64_global_t *gl);
static void handle_rebound(entity_t *en, z64_global_t *gl); /* Bouncing off walls */
static void behavior(entity_t *en, z64_global_t *gl);
static void state_809C29F4(entity_t *en, z64_global_t *gl); /* Appears to determine whether or not you're able to throw the bomb. */


/*** variables ***/
const z64_collider_init_t bomb_base = {
	.type = COL_TYPE_UNK0
	, .flags_at = 0x00
	, .flags_ac = 0x29
	, .mask_a = 0x39
	, .mask_b = 0x20
	, .shape = COL_SHAPE_CYLINDER
};

const z64_collider_body_init_t bomb_body = {
	.flags_body = 0x02
	, .toucher = {
		.flags = 0x00000000
		, .effect = 0x00
		, .damage = 0x00
	}
	, .bumper = {
		.flags = 0x0003F828
		, .effect = 0x00
		, .defense = 0x00
	}
	, .flags_toucher = 0x00
	, .flags_bumper = 0x01
	, .flags_body_2 = 0x01
};

const z64_cylinder16_t bomb_dim = {
	.radius = 6
	, .height = 11
	, .y_shift = 14
	, .pos = {0, 0, 0}
};

const z64_collider_cylinder_init_t bomb_cylinder = {
	.base = bomb_base
	, .body = bomb_body
	, .dim = bomb_dim
};

z64_collider_jntsph_item_init_t jntsph_list =
{
	.body = {
		.flags_body = 0x00
		, .toucher = {
			.flags = 0x00000008
			, .effect = 0x00
			, .damage = 0x08
		}
		, .bumper = {
			.flags = 0x00000000
			, .effect = 0x00
			, .defense = 0x00
		}
		, .flags_toucher = 0x19
		, .flags_bumper = 0x00
		, .flags_body_2 = 0x00
	}
	, .dim = {
		.joint = 0x00
		, .sphere_model = {
			.center = {0, 0, 0}
			, .radius = 0
		}
		, .scale = 100
	}
};

z64_collider_jntsph_init_t bomb_jntsph =
{
	.base = {
		.type = 0x00
		, .flags_at = 0x39
		, .flags_ac = 0x00
		, .mask_a = 0x00
		, .mask_b = 0x00
		, .shape = COL_SHAPE_JNTSPH
	}
	, .count = 1
	, .list = &jntsph_list
};

const uint32_t ichain[] =
{
	0xC0500000,
	0xB04C07D0,
	0x386CF060
};

/*** functions ***/
static void set_state(entity_t *en, z64_actorfunc_t *state) /* OK */
{
	en->state = state;
}

static void destructor(entity_t *en, z64_global_t *gl) /* OK */
{
	z_collider_jntsph_free(gl, &en->collider_s);
	z_collider_cylinder_free(gl, &en->collider_c);
}

static void handle_collider(entity_t *en, z64_global_t *gl) /* OK */
{
	z64_collider_jntsph_item_t* hitbox = (en->collider_s).list;
	z64_player_t* Link = zh_get_player(gl);

	if ((hitbox->dim).sphere_model.radius == 0)
	{
		(en->actor).flags |= 0x20;
		external_func_800AA000((en->actor).dist_from_link_xz, 0xFF, 0x14, 0x96); // Variable Rumble Pak Intensity based on Link's proximity.
	}

	(hitbox->dim).sphere_world.radius += (en->actor).rot.z + 8;

	if ((en->actor).variable == 1)
	{
		z_collider_hitbox(gl, &gl->hit_ctxt, &en->collider_s);
	}

	if (gl->unk_0x10AB0[0]) gl->unk_0x10AB0[0] -= 0x19;
	if (gl->unk_0x10AB0[1]) gl->unk_0x10AB0[1] -= 0x19;
	if (gl->unk_0x10AB0[2]) gl->unk_0x10AB0[2] -= 0x19;
	if (gl->unk_0x10AB0[3]) gl->unk_0x10AB0[3] -= 0x19;
	if (gl->unk_0x10AB0[4]) gl->unk_0x10AB0[4] -= 0x19;
	if (gl->unk_0x10AB0[5]) gl->unk_0x10AB0[5] -= 0x19;

	if (en->timer == 0)
	{
		if (((Link->state_flags_1 & 0x0800) != 0) && (Link->held_actor == &en->actor))
		{
			(Link->actor).attached_b = 0;
			Link->held_actor = 0;
			Link->interacted_range_actor = 0;
			Link->state_flags_1 &= 0xFFFFF7FF;
		}
		z_actor_kill(&en->actor);
	}
}

static void draw(entity_t *en, z64_global_t *gl) /* OK */
{
	z64_disp_buf_t* opa = &ZQDL(gl, poly_opa);
	z64_gfx_t* gfx_ctxt = (gl->common).gfx_ctxt;
	Gfx gfx_arr[3];
	uint32_t env_color = (((int32_t)en->field_0x1fc << 24) | 0x000028FF);

	z_debug_graph_alloc(gfx_arr, gfx_ctxt, __FILE__, __LINE__);

	if (!(en->actor).variable)
	{
		z_rcp_append_preset_opa(gfx_ctxt);
		z_matrix_rotate_vec3f((vec3f_t*)gl->unk_player_matrix);
		external_func_8002EBCC(&en->actor, gl, 0);

		/* Gold Fuse Cap */
		gSPMatrix(
			opa->p++
			, z_matrix_alloc(gfx_ctxt, __FILE__)
			, G_MTX_LOAD
		);
		gSPDisplayList(opa->p++, DL_EN_BOM_CAP);
		z_matrix_rotate_3s(ROT16(90), 0, 0, 1);

		/* Bomb Body */
		gSPMatrix(
			opa->p++
			, z_matrix_alloc(gfx_ctxt, __FILE__)
			, G_MTX_LOAD
		);
		gDPPipeSync(opa->p++);
		gDPSetEnvColor(opa->p++, RED32(env_color), GREEN32(env_color), BLUE32(env_color), ALPHA32(env_color));
		gDPSetPrimColor(opa->p++, 0, 0, RED32(env_color), GREEN32(env_color), BLUE32(env_color), ALPHA32(env_color));
		gSPDisplayList(opa->p++, DL_EN_BOM_BODY);

		z_collider_translate_index(0, &en->collider_s);
	}
	z_debug_graph_write(gfx_arr, gfx_ctxt, __FILE__, __LINE__);
}

static void constructor(entity_t *en, z64_global_t *gl) /* OK */
{
	int16_t _zr;

	z_lib_ichain_init(&en->actor, ichain);
	z_actor_shadow_init(
		&(en->actor).rot
		, 700.0f
		, &Z_SHADOW_CIRCLE
		, 16.0f
	);

	(en->actor).mass = 200;
	(en->actor).unk_0xA8 = 5;
	(en->actor).unk_0xAA = 10;
	en->timer = 0x46;
	en->field_0x1fa = 7;

	/* Collider Initialization */
	z_collider_cylinder_alloc(gl, &en->collider_c);
	z_collider_cylinder_init(gl, &en->collider_c, &en->actor, &bomb_cylinder);
	z_collider_jntsph_alloc(gl, &en->collider_s);
	z_collider_jntsph_init(gl, &en->collider_s, &en->actor, &bomb_jntsph, &en->collider_s_item);

	(en->collider_s_item).body.toucher.damage += ((en->actor).rot.z >> 8);

	/* What is this initializing? */
	(en->actor).rot.z &= 0xFF;
	_zr = (en->actor).rot.z;
	if ((_zr & 0x80) != 0)
	{
		(en->actor).rot.z = (_zr | 0xFF00);
	}

	set_state(en, (z64_actorfunc_t*)handle_rebound);
}

static void handle_rebound(entity_t *en, z64_global_t *gl) /* OK */
{
	uint16_t bgchk = (en->actor).bgcheck_flags;
	int16_t iVar6;

	if (z_actor_is_attached(&en->actor))
	{
		set_state(en, (z64_actorfunc_t*)state_809C29F4);
		(en->actor).room_index = 0xFF;
		return;
	}

	if ((en->actor).velocity.y > 0)
	{
		if (((en->actor).bgcheck_flags & BGCHK_UNK01) != 0)
		{
			(en->actor).velocity.y = -((en->actor).xz_speed);
		}
	}

	if ((en->actor).xz_speed == 0)
	{
		bgchk &= BGCHK_NEAR_FLOOR;
	}
	else
	{
		if (!(bgchk & BGCHK_NEAR_WALL))
		{
			bgchk &= BGCHK_NEAR_FLOOR;
		}
		else
		{
			/* Bomb Rebound off of Wall and Floor */

			int16_t wrot_diff = ((en->actor).wall_rot - (en->actor).dir.y) & 0xFFFF;
			int16_t _wrot_diff = -(wrot_diff);

			if (wrot_diff >= 0)
			{
				_wrot_diff = wrot_diff;
			}

			if (_wrot_diff >= ROT16(91))
			{
				(en->actor).dir.y = ((en->actor).wall_rot - (en->actor).dir.y) + (en->actor).wall_rot - ROT16(180);
			}

			z_actor_play_sfx2(&en->actor, NA_SE_EV_BOMB_BOUND);
			z_actor_move_dir_vel(&en->actor);

			(en->actor).bgcheck_flags &= 0xFFF7;
			(en->actor).xz_speed *= 0.7f;
			bgchk &= 0xFFFF;
		}
	}

	if (!(bgchk & BGCHK_NEAR_FLOOR))
	{
		z_lib_approx_f(&(en->actor).xz_speed, 0.0f, 0.08f);
	}
	else
	{
		z_lib_approx_f(&(en->actor).xz_speed, 0.0f, 1.0f);
		if (((en->actor).bgcheck_flags & BGCHK_UNK00) && ((en->actor).velocity.y < -3.0f))
		{
			external_func_8002F850(gl, &en->actor);
			(en->actor).bgcheck_flags &= 0xFFFD;
			(en->actor).velocity.y *= -0.3f;
		}
		else
		{
			if (en->timer >= 4)
			{
				z_actor_give_id_0(&en->actor, gl);
			}
		}
	}
	z_actor_move_dir_vel(&en->actor);
}

static void behavior(entity_t *en, z64_global_t *gl)
{
    vec3f_t sp84 = {0.0f, 0.0f, 0.0f};
    vec3f_t sp78 = {0.0f, 0.1f, 0.0f};
    vec3f_t sp6C = {0.0f, 0.0f, 0.0f};
    vec3f_t sp54 = {0.0f, 0.6f, 0.0f};
    vec3f_t eff_pos = (en->actor).pos;
    uint32_t fuse_smoke_color = COLOR32(255, 255, 255, 255);
    float dist_from_link;

    (en->actor).gravity = -1.2f;
    if (en->timer != 0)
    {
        en->timer -= 1;
    }
    if (en->timer == 0x43)
    {
        z_actor_play_sfx2(&en->actor, (0x800 + NA_SE_PL_TAKE_OUT_SHIELD));
        z_actor_set_scale(&en->actor, 0.01f);
    }
    if (!(20.0f <= (en->actor).dist_from_link_xz))
    {
        if (0.0f <= (en->actor).dist_from_link_y)
        {
            dist_from_link = (en->actor).dist_from_link_y;
        }
        else
        {
            dist_from_link = -(en->actor).dist_from_link_y;
        }
        if (80.0f <= dist_from_link)
        {
block_9:
            en->field_0x200 = 1;
        }
    }
    else
    {
        goto block_9;
    }
    z64_actorfunc_t* execute_state = en->state;
    execute_state(en, gl);
    z_actor_find_bounds(gl, &en->actor, 5.0f, 10.0f, 15.0f, 0x1F);
    if ((en->actor).variable == 0)
    {
        if (en->timer < 0x3F)
        {
            eff_pos.y += 17.0f;
            /* Bomb Fuse Effect */
            if ((gl->gameplay_frames & 1) == 0)
            {
                z_effect_spawn_spark(
                    gl
                    , &en->actor
                    , &eff_pos
                    , &sp84
                    , &sp6C
                );
            }
            z_actor_play_sfx2(&en->actor, (NA_SE_IT_BOMB_IGNIT & 0xF0FF));
            eff_pos.y += 3.0f;
            z_effect_spawn_dust_a(
                gl
                , &eff_pos
                , &sp84
                , &sp54
                , &fuse_smoke_color
                , &fuse_smoke_color
                , 0x32
                , 5
            );
        }
        if (((en->collider_c).base.flags_ac & 2) == 0)
        {
            if (((en->collider_c).base.mask_a & 2) != 0)
            {
                /* Explode on Enemy Impact */
                if (((en->collider_c).base.oc)->actor_type == OVLTYPE_ENEMY)
                {
block_18:
                    en->timer = 0;
                    (en->actor).rot.z = 0;
                }
                else
                {
block_19:
                    if (en->timer >= 0x65)
                    {
                        if (external_func_8008EF5C(gl, &(en->actor).pos, 30.0f, 50.0f) != 0)
                        {
                            en->timer = 0x64;
                        }
                    }
                }
            }
            else
            {
                goto block_19;
            }
        }
        else
        {
            goto block_18;
        }
        eff_pos.y += 10.0f;
        if (en->timer != 3)
        {
            if (en->timer != 0x14)
            {
                if (en->timer == 0x28)
                {
block_25:
                    (en->actor).rot.z = 0;
                    en->field_0x1fa = (en->field_0x1fa >> 1);
                }
            }
            else
            {
                goto block_25;
            }
        }
        else
        {
            goto block_25;
        }
        if (en->timer < 0x64)
        {
            if ((en->timer & (en->field_0x1fa + 1)) != 0)
            {
                z_lib_smooth_scale_max_min_f(&en->field_0x1fc, 140.0f, 1.0f, 140.0f / en->field_0x1fa, 0.0f);
            }
            else
            {
block_29:
                z_lib_smooth_scale_max_min_f(&en->field_0x1fc, 0.0f, 1.0f, 140.0f / en->field_0x1fa, 0.0f);
            }
        }
        else
        {
            goto block_29;
        }
        if (en->timer < 3)
        {
            z_actor_set_scale(&en->actor, (en->actor).scale.x + 0.002f);
        }
        /* Explosion */
        if (en->timer == 0)
        {
            eff_pos.y += 10.0f;
            if (z_actor_is_attached(&en->actor) != 0)
            {
                eff_pos.y += 30.0f;
            }
            z_effect_spawn_bomb2(
                gl
                , &eff_pos
                , &sp84
                , &sp78
                , 0x64
                , ((en->actor).rot.z * 6) + 0x13
            );
            eff_pos.y = (en->actor).floor_height;
            if (-32000.0f < (en->actor).floor_height)
            {
                z_effect_spawn_blast_ring(
                    gl
                    , &eff_pos
                    , &sp84
                    , &sp6C
                );
            }
            z_actor_play_sfx2(&en->actor, NA_SE_IT_BOMB_EXPLOSION);
            gl->unk_0x10AB0[5] = 0xFA;
            gl->unk_0x10AB0[2] = 0xFA;
            gl->unk_0x10AB0[4] = gl->unk_0x10AB0[5];
            gl->unk_0x10AB0[3] = gl->unk_0x10AB0[5];
            gl->unk_0x10AB0[1] = gl->unk_0x10AB0[2];
            gl->unk_0x10AB0[0] = gl->unk_0x10AB0[2];
            z_camera_earthquake(&(gl->camera).unk_0, 2, 0xB, 8);
            (en->actor).variable = 1;
            en->timer = 10;
            (en->actor).flags |= 0x20;
            set_state(en, (z64_actorfunc_t*)handle_collider);
        }
    }
    z_actor_set_height(&en->actor, 20.0f);
    if ((en->actor).variable <= 0)
    {
        z_collider_cylinder_update(&en->actor, &en->collider_c);
        if (z_actor_is_attached(&en->actor) == 0)
        {
            if (en->field_0x200 != 0)
            {
                z_collider_bumpbox(gl, &gl->hit_ctxt, &en->collider_c);
            }
        }
        z_collider_hurtbox(gl, &gl->hit_ctxt, &en->collider_c);
    }
    if (0.01 <= (en->actor).scale.x)
    {
        if ((en->actor).variable != 1)
        {
            if (20.0f <= (en->actor).water_surface_dist)
            {
                z_effect_spawn_dead_sound(
                    gl
                    , &(en->actor).unk_0xE4
                    , NA_SE_IT_BOMB_UNEXPLOSION
                    , 1, 1, 0xA
                );
                z_actor_kill(&en->actor);
                return;
            }
            if (((en->actor).bgcheck_flags & BGCHK_IN_WATER1) != 0)
            {
                (en->actor).bgcheck_flags &= 0xFFBF;
                z_actor_play_sfx2(&en->actor, NA_SE_EV_BOMB_DROP_WATER);
            }
        }
    }
}

static void state_809C29F4(entity_t *en, z64_global_t *gl) /* OK */
{
    if (z_actor_is_attached2(&en->actor) != 0)
    {
        set_state(en, (z64_actorfunc_t*)handle_rebound);
        handle_rebound(en, gl);
    }
}

const z64_actor_init_t init_vars = {
	.number = 0x0010,
	.type = 0x03,
	.room = 0x00,
	.flags = 0x00000030,
	.object = 0x0001,
	.padding = 0x0000,
	.instance_size = sizeof(entity_t),
	.init = constructor,
	.dest = destructor,
	.main = behavior,
	.draw = draw
};
