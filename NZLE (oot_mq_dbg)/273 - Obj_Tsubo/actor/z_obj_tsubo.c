/************
 * z_en_nutsball.c faithfully rewritten by CrookedPoe <nickjs.site> and Dr. Disco <z64.me>
 * This is meant to be a functionally equivalent rewrite, intended to be compiled with <https://github.com/z64me/z64ovl>
 * This is working as of commit dce85c98be05ea81e81e4c8a38cf9731ef8b4750
*************/

#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>
#include <z64ovl/oot/sfx.h>
#include "z_obj_tsubo.h"

typedef struct {
    z64_actor_t actor;
    /* uint8_t[16] debug_ex; */
    z64_actorfunc_t* state;
    z64_collider_cylinder_t collider;
    int8_t obj_index;
    int16_t data_80BA1B50[4];
} z_obj_tsubo_t;

/*** variables ***/
const uint32_t ichain[6] = {
    0xB86CFB50, 0xB870B1E0
    , 0xC8500096, 0xB0F40384
    , 0xB0F80064, 0x30FC0320
};

const uint32_t damage_chart_unk[2] = {
    0x0000000C, 0x003CFF00
};

const int16_t objs[2] = {
    OBJ_GAMEPLAY_DANGEON_KEEP, OBJ_TSUBO
};

const uint32_t dl_pots[2] = {
    DL_POT_GDK, DL_POT
};

const uint32_t dl_shards[2] = {
    DL_SHARD_GDK, DL_SHARD
};

const z64_collider_init_t tsubo_base = {
	.type = COL_TYPE_UNK12
	, .flags_at = 0x09
	, .flags_ac = 0x09
	, .mask_a = 0x39
	, .mask_b = 0x20
	, .shape = COL_SHAPE_CYLINDER
};

const z64_collider_body_init_t tsubo_body = {
	.flags_body = 0x00
	, .toucher = {
		.flags = 0x00000002
		, .effect = 0x00
		, .damage = 0x01
	}
	, .bumper = {
		.flags = 0x4FC1FFFE
		, .effect = 0x00
		, .defense = 0x00
	}
	, .flags_toucher = 0x01
	, .flags_bumper = 0x01
	, .flags_body_2 = 0x01
};

const z64_cylinder16_t tsubo_dim = {
	.radius = 9
	, .height = 26
	, .y_shift = 0
	, .pos = {0, 0, 0}
};

const z64_collider_cylinder_init_t tsubo_collision = {
	.base = tsubo_base
	, .body = tsubo_body
	, .dim = tsubo_dim
};

/*** function prototypes ***/
static void constructor(z_obj_tsubo_t* en, z64_global_t* gl);
static void destructor(z_obj_tsubo_t* en, z64_global_t* gl);
static void behavior(z_obj_tsubo_t* en, z64_global_t* gl);
static void draw(z_obj_tsubo_t* en, z64_global_t* gl);
static void set_arc_velocity(z_obj_tsubo_t* en, z64_global_t* gl);
static void _break(z_obj_tsubo_t* en, z64_global_t* gl);
static void _break_water(z_obj_tsubo_t* en, z64_global_t* gl);
static void collider_init(z_obj_tsubo_t* en, z64_global_t* gl);
static void func_80BA15BC(z_obj_tsubo_t* en, z64_global_t* gl);
static void state_set_carry(z_obj_tsubo_t* en, z64_global_t* gl);
static void state_is_carry(z_obj_tsubo_t* en, z64_global_t* gl);
static void state_set_thrown(z_obj_tsubo_t* en, z64_global_t* gl);
static void state_is_thrown(z_obj_tsubo_t* en, z64_global_t* gl);
static void check_object(z_obj_tsubo_t* en, z64_global_t* gl);
static int32_t snap_to_ground(z_obj_tsubo_t* en, z64_global_t* gl);
static void spawn_drop(z_obj_tsubo_t* en, z64_global_t* gl);

static void constructor(z_obj_tsubo_t* en, z64_global_t* gl)
{
    z_lib_ichain_init(&en->actor, ichain);
    collider_init(en, gl);
    z_actor_damage_table_init(&(en->actor).damage_table, 0, damage_chart_unk);

    if (!snap_to_ground(en, gl))
    {
        z_actor_kill(&en->actor);
    }
    else
    {
        en->obj_index = TSUBO_WHICH((en->actor).variable);
        if (OBJ_IS_LOADED(&gl->obj_ctxt, en->obj_index))
        {
            if (en->obj_index < 0)
            {
                z_console_log(
                    "Error : バンク危険！ (arg_data 0x%04x)(%s %d)\n"
                    , (en->actor).variable
                    , __FILE__
                    , __LINE__
                );
                z_actor_kill(&en->actor);
            }
            else
            {
                en->state = (z64_actorfunc_t*)check_object;
                z_console_log(
                    "(dungeon keep 壷)(arg_data 0x%04x)\n"
                    , (en->actor).variable
                );
            }
        }
    }
}

static void destructor(z_obj_tsubo_t* en, z64_global_t* gl)
{
    z_collider_cylinder_free(gl, &en->collider);
}

static void behavior(z_obj_tsubo_t* en, z64_global_t* gl)
{
    z64_actorfunc_t* execute_state = en->state;
    execute_state(en, gl);
}

static void draw(z_obj_tsubo_t* en, z64_global_t* gl)
{
    z_cheap_proc_draw_opa(gl, dl_pots[TSUBO_WHICH((en->actor).variable)]);
}

static int32_t snap_to_ground(z_obj_tsubo_t* en, z64_global_t* gl)
{
    char stack4[4];
    char stack20[4];
    vec3f_t raycast_origin = (en->actor).pos;
    raycast_origin.y += 20.0f;

    float r = math_raycast(&gl->col_ctxt, &stack4, &stack20, &en->actor, &raycast_origin);

    if (RAYCAST_SUCCESS(r))
    {
        (en->actor).pos.y = r;
        z_lib_vec3f_copy(&(en->actor).pos_init, &(en->actor).pos);
    }
    else
    {
        //z_console_log("地面に付着失敗\n");
        z_console_log("Failure to attach to the ground!\n");
    }
    return (RAYCAST_SUCCESS(r));
}

static void check_object(z_obj_tsubo_t* en, z64_global_t* gl)
{
    if (OBJ_IS_LOADED(&gl->obj_ctxt, en->obj_index))
    {
        (en->actor).draw_proc = (z64_actorfunc_t*)draw;
        (en->actor).alloc_index = en->obj_index;
        en->state = (z64_actorfunc_t*)func_80BA15BC;
        (en->actor).flags &= 0xFFFFFFEF;
    }
}

static void collider_init(z_obj_tsubo_t* en, z64_global_t* gl)
{
    z_collider_cylinder_alloc(gl, &en->collider);
    z_collider_cylinder_init(gl, &en->collider, &en->actor, &tsubo_collision);
    z_collider_cylinder_update(&en->actor, &en->collider);
}

static void spawn_drop(z_obj_tsubo_t* en, z64_global_t* gl)
{
    uint16_t drop_id = (en->actor).variable & 0x1F;

    if (drop_id < 0x1A)
        z_item_drop(gl, &(en->actor).pos, drop_id);
}

static void set_arc_velocity(z_obj_tsubo_t* en, z64_global_t* gl)
{
    (en->actor).velocity.y += (en->actor).gravity;
    if ((en->actor).velocity.y < (en->actor).min_vel_y)
        (en->actor).velocity.y = (en->actor).min_vel_y;
}

static void func_80BA15BC(z_obj_tsubo_t* en, z64_global_t* gl)
{
    if (!z_actor_is_attached(&en->actor))
    {
        if ((en->actor).bgcheck_flags & BGCHK_IN_WATER0)
        {
            if ((en->actor).water_surface_dist > 15.0f)
            {
                _break_water(en, gl);
                z_sfx_play_position(gl, &(en->actor).pos, 0x14, NA_SE_EV_POT_BROKEN);
                spawn_drop(en, gl);
                z_actor_kill(&en->actor);
            }
        }

        if ((!(en->collider).base.flags_ac & 2) || (!((en->collider).body.hit_item_ac->toucher).flags & 0x4FC1FFFC))
        {
            if ((en->actor).dist_from_link_xz < 600.0f)
            {
                z_collider_cylinder_update(&en->actor, &en->collider);
                (en->collider).base.flags_ac &= 0xFD;
                z_collider_hurtbox(gl, &gl->hit_ctxt, &en->collider);

                if ((en->actor).dist_from_link_xz < 150.0f)
                {
                    z_collider_bumpbox(gl, &gl->hit_ctxt, &en->collider);
                }
            }
            
            if ((en->actor).dist_from_link_xz < 100.0f)
            {
                zh_lift_test(&en->actor, gl, 30.0f, 30.0f);
            }
        }
        else
        {
            _break(en, gl);
            spawn_drop(en, gl);
            z_sfx_play_position(gl, &(en->actor).pos, 0x14, NA_SE_EV_POT_BROKEN);
            z_actor_kill(&en->actor);
        }
    }
    else
    {
        state_set_carry(en, gl);
    }
}

/* Carry the pot. */
static void state_is_carry(z_obj_tsubo_t* en, z64_global_t* gl)
{
    if (z_actor_is_attached(&en->actor))
    {
        (en->actor).room_index = (gl->room_ctxt).rooms->index;
        state_set_thrown(en, gl);
        z_actor_update_pos(&en->actor);
        z_actor_find_bounds(gl, &en->actor, 5.0f, 15.0f, 0.0f, 0x85);
    }
}

static void state_set_carry(z_obj_tsubo_t* en, z64_global_t* gl)
{
    en->state = (z64_actorfunc_t*)state_is_carry;
    (en->actor).room_index = 0xFF;
    z_actor_play_sfx(&en->actor, NA_SE_PL_PULL_UP_POT);
    (en->actor).flags |= 0x10;
}


/* Throw the pot. */
static void state_set_thrown(z_obj_tsubo_t* en, z64_global_t* gl)
{
    en->data_80BA1B50[0] = (int16_t)((math_rand_zero_one() - 0.7f) * 2000.0f);
    en->data_80BA1B50[1] = (int16_t)((math_rand_zero_one() - 0.5f) * 2800.0f);
    en->data_80BA1B50[2] = 0;
    en->data_80BA1B50[3] = 0;

    (en->actor).velocity = (vec3f_t){
        z_sin_s((en->actor).dir.y) * (en->actor).xz_speed
        , (en->actor).velocity.y
        , z_cos_s((en->actor).dir.y) * (en->actor).xz_speed
    };

    (en->actor).mass = 0xF0;
    en->state = (z64_actorfunc_t*)state_is_thrown;
}

static void state_is_thrown(z_obj_tsubo_t* en, z64_global_t* gl)
{
    uint16_t bg_chk = (en->actor).bgcheck_flags;

    if (!(bg_chk & BGCHK_0x0B) && (!(en->collider).base.flags_at & 2))
    {
        /* Check if not colliding with water. */
        if (!(bg_chk & BGCHK_IN_WATER1))
        {
            set_arc_velocity(en, gl);
            z_actor_update_pos(&en->actor);
            z_lib_approx_s(&en->data_80BA1B50[1], en->data_80BA1B50[0], 100);
            z_lib_approx_s(&en->data_80BA1B50[3], en->data_80BA1B50[2], 100);

            (en->actor).rot = (vec3s_t){
                (en->actor).rot.x + en->data_80BA1B50[1]
                , (en->actor).rot.y + en->data_80BA1B50[3]
                , (en->actor).rot.z
            };

            z_actor_find_bounds(gl, &en->actor, 5.0f, 15.0f, 0.0f, 0x85);

            z_collider_cylinder_update(&en->actor, &en->collider);
            z_collider_bumpbox(gl, &gl->hit_ctxt, &en->collider);
            z_collider_hitbox(gl, &gl->hit_ctxt, &en->collider);
        }
        else
        {
            /* Break and shatter on impact with water. */
            _break_water(en, gl);
            spawn_drop(en, gl);
            z_sfx_play_position(gl, &(en->actor).pos, 0x14, NA_SE_EV_POT_BROKEN);
            z_actor_kill(&en->actor);
        }
    }
    else
    {
        /* Break and shatter on impact with anything other than water. */
        _break(en, gl);
        spawn_drop(en, gl);
        z_sfx_play_position(gl, &(en->actor).pos, 0x14, NA_SE_EV_POT_BROKEN);
        z_actor_kill(&en->actor);
    }
}

/* Particle Spawning Functions */

static void _break(z_obj_tsubo_t* en, z64_global_t* gl)
{
    uint16_t rand = 0;

    for(int shard = 0; shard < N_SHARDS; ++shard)
    {
        vec3f_t burst_depth[2];

        /* X Axis */
        burst_depth[0] = (vec3f_t){
            z_sin_s(rand) * 8.0f
            , (math_rand_zero_one() * 5.0f) + 2.0f
            , z_cos_s(rand) * 8.0f
        };

        /* Y Axis */
        burst_depth[1] = (vec3f_t){
            burst_depth[0].x * 0.23f
            , (math_rand_zero_one() * 5.0f) + 2.0f
            , burst_depth[0].z * 0.23f
        };

        VEC3_ADD(burst_depth[0], (en->actor).pos);

        float randf = math_rand_zero_one();

        uint16_t uVar1 = (randf < 0.2f) ? 0x60 : 0x20;
        uVar1 = (randf < 0.6f) ? 0x40 : uVar1;

        int32_t which = TSUBO_WHICH((en->actor).variable);
        z_effect_spawn_fragment(
            gl
            , &burst_depth[0], &burst_depth[1], &(en->actor).pos
            , -0xF0, uVar1, 0x0A
            , 0x0A, 0, (math_rand_zero_one() * 95.0f) + 15.0f
            , 0, 0x20, 0x3C
            , -1, objs[which], dl_shards[which]
        );
        rand = (rand + 0x4E20) & 0xFFFF;
    }
    /* Spawn Various Dust Particles */
    external_func_80033480(
        gl
        , &(en->actor).pos
        , 30.0f
        , 4, 0x14, 0x32, 1
    );
}

static void _break_water(z_obj_tsubo_t* en, z64_global_t* gl)
{
    /* Splish Splash*/
    vec3f_t splash_pos = (en->actor).pos;
    splash_pos.y += (en->actor).water_surface_dist;

    /* Spawn Effect */
    z_effect_spawn_water_splash(
        gl
        , &splash_pos
        , 0, 0, 0, 0x190
    );

    uint16_t rand = 0;

    for(int shard = 0; shard < N_SHARDS; ++shard)
    {
        vec3f_t burst_depth[2];

        /* X Axis */
        burst_depth[0] = (vec3f_t){
            z_sin_s(rand) * 8.0f
            , (math_rand_zero_one() * 5.0f) + 2.0f
            , z_cos_s(rand) * 8.0f
        };

        /* Y Axis */
        burst_depth[1] = (vec3f_t){
            burst_depth[0].x * 0.2f
            , (math_rand_zero_one() * 5.0f) + 2.0f
            , burst_depth[0].z * 0.2f
        };

        VEC3_ADD(burst_depth[0], (en->actor).pos);

        float randf = math_rand_zero_one();

        uint16_t uVar1 = (randf < 0.2f) ? 0x60 : 0x20;
        uVar1 = (randf < 0.6f) ? 0x40 : uVar1;

        int32_t which = TSUBO_WHICH((en->actor).variable);
        z_effect_spawn_fragment(
            gl
            , &burst_depth[0], &burst_depth[1], &(en->actor).pos
            , -0xB4, uVar1, 0x1E
            , 0x1E, 0, (math_rand_zero_one() * 95.0f) + 15.0f
            , 0, 0x20, 0x46
            , -1, objs[which], dl_shards[which]
        );
        rand = (rand + 0x4E20) & 0xFFFF;
    }
}

const z64_actor_init_t init_vars = {
	.number = 0x0111,
	.type = OVLTYPE_PROP,
	.room = 0x00,
	.flags = 0x00000010,
	.object = 0x0001,
	.padding = 0x0000,
	.instance_size = sizeof(z_obj_tsubo_t),
	.init = constructor,
	.dest = destructor,
	.main = behavior,
	.draw = 0x00000000
};