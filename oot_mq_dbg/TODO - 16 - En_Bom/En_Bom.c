#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

#define OBJ_ID 1

typedef struct {
	/* 0x0000 */ z64_actor_t actor;
	/* 0x014C */ z64_collider_cylinder_main_t collider_main;
	/* 0x0198 */ z64_collider_cylinder_collection_t cyl_list;
	/* 0x01B8 */ z64_collider_cylinder_t collider_hit;
	/* 0x01F8 */ uint16_t unk_01F8;
	/* 0x01FA */ uint16_t flash_speed;
	/* 0x01FC */ float unk_01FC;
	/* 0x0200 */ uint8_t unk_0200;
	/* 0x0201 */ uint8_t unk_0201;
	/* 0x0204 */ z64_actorfunc_t *machine_state
} entity_t; /* 0208 */


/*** function prototypes ***/
void state_set_809C26D0(entity_t *en, z64_actorfunc_t *state); /* Rewritten */
void dest_809C27EC(entity_t *en, z64_global_t *gl); /* Rewritten */
void state_809C2A38(entity_t *en, z64_global_t *gl); /* Rewritten */
void draw_809C3218(entity_t *en, z64_global_t *gl); /* Rewritten */
void init_809C26D8(entity_t *en, z64_global_t *gl); /* Rewritten */
void state_809C282C(entity_t *en, z64_global_t *gl); /* Rewritten */
void state_main_809C2B88(entity_t *en, z64_global_t *gl); /* 1 internal, 17 external, 445 lines */
void state_809C29F4(entity_t *en, z64_global_t *gl); /* Rewritten */


/*** variables ***/
const uint32_t data_809C3430[] =
{
	0x00002939,
	0x20010000,
	0x02000000,
	0x00000000,
	0x00000000,
	0x0003F828,
	0x00000000,
	0x00010100,
	0x0006000B,
	0x000E0000,
	0x00000000
};
const uint32_t data_809C345C[] =
{
	0x00000000,
	0x00000008,
	0x00080000,
	0x00000000,
	0x00000000,
	0x19000000,
	0x00000000,
	0x00000000,
	0x00000064
};
const uint32_t data_809C3480[] =
{
	0x00390000,
	0x00000000,
	0x00000001,
	(uint32_t)(void*)data_809C345C
};
const uint32_t data_809C3490[] =
{
	0xC0500000,
	0xB04C07D0,
	0x386CF060
};
const uint32_t data_809C349C[] =
{
	0x00000000,
	0x00000000,
	0x00000000
};
const uint32_t data_809C34A8[] =
{
	0x00000000,
	0x3DCCCCCD,
	0x00000000
};
const uint32_t data_809C34B4[] =
{
	0x00000000,
	0x00000000,
	0x00000000
};
const uint32_t data_809C34C0[] =
{
	0x00000000,
	0x3F19999A,
	0x00000000
};
const uint32_t data_809C34CC[] =
{
	0xFFFFFFFF,
};
const uint32_t data_809C34D0[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x626F6D2E,
	0x63000000
};
const uint32_t data_809C34E0[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x626F6D2E,
	0x63000000
};
const uint32_t data_809C34F0[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x626F6D2E,
	0x63000000
};
const uint32_t data_809C3500[] =
{
	0x2E2E2F7A,
	0x5F656E5F,
	0x626F6D2E,
	0x63000000
};
const uint32_t data_809C3510[] =
{
	0x3F333333
};
const uint32_t data_809C3514[] =
{
	0xBE999999
};
const uint32_t data_809C3518[] =
{
	0xBF99999A
};
const uint32_t data_809C351C[] =
{
	0x3E4CCCCD
};
const uint32_t data_809C3520[] =
{
	0x3E4CCCCD
};
const uint32_t data_809C3524[] =
{
	0x3B03126F
};
const uint32_t data_809C3528[] =
{
	0x3C23D70A,
	0x00000000
};


/*** functions ***/
void state_set_809C26D0(entity_t *en, z64_actorfunc_t *state)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lstate_set_809C26D0: \n"
	);

	en->machine_state = state;
}

void dest_809C27EC(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest_809C27EC: \n"
	);

	actor_collider_cylinder_array_free(gl, &en->cyl_list);
	actor_collider_cylinder_free(gl, &en->collider_main);
}

void state_809C2A38(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lstate_809C2A38: \n"
	);

  z64_collider_cylinder_t *hitbox;
  z64_player_t *Link;

  hitbox = (en->cyl_list).list;
  hitbox->unk_0x36 += ((en->actor).rot_2.z + 8);

  if (hitbox->unk_0x2E == 0)
  {
    (en->actor).flags |= 0x20;
    external_func_800AA000((en->actor).dist_from_link_xz, &en->actor, 0xFF, 0x14, 0x96);
  }

  if ((en->actor).variable == 1)
    actor_collision_check_set_at(gl, &gl->sbc_group_at_1, &en->cyl_list);

  if (gl->unk_0x10AB0[0] != 0) { gl->unk_0x10AB0[0] -= 25; }
  if (gl->unk_0x10AB0[1] != 0) { gl->unk_0x10AB0[1] -= 25; }
  if (gl->unk_0x10AB0[2] != 0) { gl->unk_0x10AB0[2] -= 25; }
  if (gl->unk_0x10AB0[3] != 0) { gl->unk_0x10AB0[3] -= 25; }
  if (gl->unk_0x10AB0[4] != 0) { gl->unk_0x10AB0[4] -= 25; }
  if (gl->unk_0x10AB0[5] != 0) { gl->unk_0x10AB0[5] -= 25; }

  if (en->unk_01F8 == 0)
  {
    Link = zh_get_player(gl);
    if (((Link->unk_02_3 & 0x800) != 0) && (&en->actor == Link->unk_00_1))
    {
      (Link->actor).attached_b = 0;
      Link->unk_00_1 = 0;
      Link->unk_01_1 = 0;
      Link->unk_02_3 &= 0xF7FF;
    }
    actor_kill(&en->actor);
  }
}

void draw_809C3218(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw_809C3218: \n"
	);

  #define GFX_POLY_OPA ZQDL(gl, poly_opa)
  z64_disp_buf_t *opa = &GFX_POLY_OPA;
  z64_gfx_t *gfx_ctxt;
  gfx_ctxt = (gl->common).gfx_ctxt;
  uint32_t matrix;

  /*external_func_800C6AC4(auStack28, pzVar3, ""../z_en_bom.c", 0x391);*/

  if ((en->actor).variable == 0)
  {
    external_func_80093D18(gfx_ctxt);
    external_func_800D1FD4(AADDR(gl->unk_1C_, 0x0064));
    external_func_8002EBCC(&en->actor, gl, 0);

    matrix = matrix_alloc(gfx_ctxt, "../z_en_bom.c"/*, 0x3A0*/);
    gSPMatrix(opa->p++, matrix, G_MTX_LOAD);
    gSPDisplayList(opa->p++, 0x04007A50);

    matrix_rotate3s(0x4000, 0, 0, 1);

    matrix = matrix_alloc(gfx_ctxt, "../z_en_bom.c"/*, 0x3A6*/);
    gSPMatrix(opa->p++, matrix, G_MTX_LOAD);
    gDPPipeSync(opa->p++);
    uint32_t color = ((int32_t)(en->unk_01FC)) << 0x18 | 0x28FF;
    gDPSetEnvColor(opa->p++, RED32(color), GREEN32(color), BLUE32(color), ALPHA32(color));
    gDPSetPrimColor(opa->p++, 0, 0, RED32(color), GREEN32(color), BLUE32(color), ALPHA32(color));
    gSPDisplayList(opa->p++, 0x04007860);

    external_func_800628A4(0, &en->cyl_list);
  }

  /*external_func_800C6B54(auStack28, (gl->common).gfx_ctxt, "../z_en_bom.c", 0x3B7);*/
}

void init_809C26D8(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit_809C26D8: \n"
	);

	actor_init_ichain(&en->actor, data_809C3490);
	actor_init_shadow(&(en->actor).rot_2, 700.0f, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 16.0f);

	/* Set Up Collision Check */
	(en->actor).collision_check.mass = -56;
  (en->actor).collision_check.unk_0B_0 = 5;
  (en->actor).collision_check.unk_0B_1 = 10;

	/* Timer Related? */
	en->unk_01F8 = 70;
	en->flash_speed = 7;

	/* Collision Allocation */
	actor_collider_cylinder_alloc(gl, &en->collider_main);
	actor_collider_cylinder_array_alloc(gl, &en->cyl_list);
	actor_collider_cylinder_init(gl, &en->collider_main, &en->actor, &data_809C3430);
	actor_collider_cylinder_array_init(gl, &en->cyl_list, &en->actor, &data_809C3480, &en->collider_hit);

	(en->collider_hit).body.toucher.damage += ((en->actor).rot_2.z >> 8);
	if ((((en->actor).rot_2.z & 0xFF) & 0x80) != 0)
		(en->actor).rot_2.z |= 0xFF00;

	state_set_809C26D0(en, (z64_actorfunc_t *)state_809C282C);
}

void state_809C282C(entity_t *en, z64_global_t *gl)
{
  asm(
    ".set at        \n"
    ".set reorder   \n"
    ".Lstate_809C282C: \n"
  );

  int32_t iVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint16_t bgcf; /* Temporary Variable for bgcheck_flags */
  float yvel; /* Temporary Variable for Y Velocity */

  /* If bomb is held, skip the rest of the function.*/
  if (actor_is_held(&en->actor, gl) != 0)
  {
    state_set_809C26D0(en, (z64_actorfunc_t *)state_809C29F4);
    (en->actor).room_index = 0xFF; /* Don't despawn on room change. */
    return;
  }

/* * * * * * * * * * * * * * * * * * * * * * * * * * */

  yvel = (en->actor).vel_1.y;
  if ((0.0f < yvel) && (((en->actor).bgcheck_flags & 0x10) != 0))
    (en->actor).vel_1.y = -yvel;
  yvel = (en->actor).xz_speed;

/* * * * * * * * * * * * * * * * * * * * * * * * * * */

	bgcf = (en->actor).bgcheck_flags;

	if ((yvel != 0.0f) && ((bgcf & 8) != 0))
	{
	  iVar4 = (en->actor).wall_rot - (en->actor).xz_dir;
	  iVar3 = iVar4 & 0xFFFF;
	  iVar2 = (-1 < iVar3) ? iVar3 : -iVar3;
	  if (0x4000 < iVar2)
	    (en->actor).xz_dir = (iVar4 + (en->actor).wall_rot) - 0x8000;
	  sound_play_actor2(&en->actor, 0x282F); /* NA_SE_EV_BOMB_BOUND */
	  actor_move_towards_direction(&en->actor);
	  bgcf = (en->actor).bgcheck_flags;
	  yvel = (en->actor).xz_speed * 0.7f;
	  (en->actor).bgcheck_flags &= 0xFFF7;
	  (en->actor).xz_speed = yvel;
	}
	bgcf &= 1;

	if (!bgcf)
	  math_approxf(&(en->actor).xz_speed, 0, 0.08f);
	else
	{
	  math_approxf(&(en->actor).xz_speed, 0, 1.0f);
	  if ((((en->actor).bgcheck_flags & 2) != 0) && ((en->actor).vel_1.y < -3.0f))
	  {
	      external_func_8002F850(gl, &en->actor);
	      (en->actor).bgcheck_flags &= 0xFFFD;
	      (en->actor).vel_1.y *= -0.3f;
	  }
	  else if (3 < en->unk_01F8)
	    actor_give_item_gid0(en, gl);
	}
	actor_move_towards_direction(&en->actor);
}

void state_main_809C2B88(entity_t *en, z64_global_t *gl)
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lstate_main_809C2B88: \n"
	);
	asm(
		"addiu           $sp,$sp,-144                           \n"
		"lui             $t7,%hi(data_809C349C)                 \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s0,40($sp)                            \n"
		"sw              $a1,148($sp)                           \n"
		"addiu           $t7,$t7,%lo(data_809C349C)             \n"
		"lw              $t9,0($t7)                             \n"
		"addiu           $t6,$sp,132                            \n"
		"lw              $t8,4($t7)                             \n"
		"sw              $t9,0($t6)                             \n"
		"lw              $t9,8($t7)                             \n"
		"lui             $t3,%hi(data_809C34A8)                 \n"
		"addiu           $t3,$t3,%lo(data_809C34A8)             \n"
		"sw              $t8,4($t6)                             \n"
		"sw              $t9,8($t6)                             \n"
		"lw              $t5,0($t3)                             \n"
		"addiu           $t2,$sp,120                            \n"
		"lw              $t4,4($t3)                             \n"
		"sw              $t5,0($t2)                             \n"
		"lw              $t5,8($t3)                             \n"
		"lui             $t7,%hi(data_809C34B4)                 \n"
		"addiu           $t7,$t7,%lo(data_809C34B4)             \n"
		"sw              $t4,4($t2)                             \n"
		"sw              $t5,8($t2)                             \n"
		"lw              $t9,0($t7)                             \n"
		"addiu           $t6,$sp,108                            \n"
		"lw              $t8,4($t7)                             \n"
		"sw              $t9,0($t6)                             \n"
		"lw              $t9,8($t7)                             \n"
		"lui             $t3,%hi(data_809C34C0)                 \n"
		"addiu           $t3,$t3,%lo(data_809C34C0)             \n"
		"sw              $t8,4($t6)                             \n"
		"sw              $t9,8($t6)                             \n"
		"lw              $t5,0($t3)                             \n"
		"addiu           $t2,$sp,84                             \n"
		"lw              $t4,4($t3)                             \n"
		"sw              $t5,0($t2)                             \n"
		"lw              $t5,8($t3)                             \n"
		"lui             $t6,%hi(data_809C34CC)                 \n"
		"sw              $t4,4($t2)                             \n"
		"sw              $t5,8($t2)                             \n"
		"lw              $t6,%lo(data_809C34CC)($t6)            \n"
		"lui             $at,%hi(data_809C3518)                 \n"
		"lwc1            $f4,%lo(data_809C3518)($at)            \n"
		"sw              $t6,80($sp)                            \n"
		"lh              $v0,504($a0)                           \n"
		"or              $s0,$a0,$zero                          \n"
		"addiu           $at,$zero,67                           \n"
		"beq             $v0,$zero,.L000021                     \n"
		"swc1            $f4,108($a0)                           \n"
		"addiu           $t7,$v0,-1                             \n"
		"sh              $t7,504($a0)                           \n"
		"lh              $v0,504($a0)                           \n"
		".L000021:                                              \n"
		"bne             $v0,$at,.L000022                       \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8002F828                 \n"
		"addiu           $a1,$zero,2100                         \n"
		"lui             $a1,0x3C23                             \n"
		"ori             $a1,$a1,0xd70a                         \n"
		"jal             0x8002D62C                 \n"
		"or              $a0,$s0,$zero                          \n"
		".L000022:                                              \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f8                                \n"
		"lwc1            $f6,144($s0)                           \n"
		"lui             $at,0x42A0                             \n"
		"addiu           $t8,$zero,1                            \n"
		"c.le.s          $f8,$f6                                \n"
		"nop                                                    \n"
		"bc1tl           .L000023                               \n"
		"sb              $t8,512($s0)                           \n"
		"lwc1            $f0,148($s0)                           \n"
		"mtc1            $zero,$f10                             \n"
		"mtc1            $at,$f16                               \n"
		"c.le.s          $f10,$f0                               \n"
		"nop                                                    \n"
		"bc1fl           .L000024                               \n"
		"neg.s           $f2,$f0                                \n"
		"beq             $zero,$zero,.L000024                   \n"
		"mov.s           $f2,$f0                                \n"
		"neg.s           $f2,$f0                                \n"
		".L000024:                                              \n"
		"c.le.s          $f16,$f2                               \n"
		"nop                                                    \n"
		"bc1fl           .L000025                               \n"
		"lw              $t9,516($s0)                           \n"
		"sb              $t8,512($s0)                           \n"
		".L000023:                                              \n"
		"lw              $t9,516($s0)                           \n"
		".L000025:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $a1,148($sp)                           \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f18                               \n"
		"addiu           $t2,$zero,31                           \n"
		"sw              $t2,20($sp)                            \n"
		"lw              $a0,148($sp)                           \n"
		"or              $a1,$s0,$zero                          \n"
		"lui             $a2,0x40A0                             \n"
		"lui             $a3,0x4120                             \n"
		"jal             0x8002E4B4                 \n"
		"swc1            $f18,16($sp)                           \n"
		"lh              $t3,28($s0)                            \n"
		"bnel            $t3,$zero,.L000026                     \n"
		"or              $a0,$s0,$zero                          \n"
		"lh              $t4,504($s0)                           \n"
		"slti            $at,$t4,63                             \n"
		"beq             $at,$zero,.L000027                     \n"
		"lui             $at,%hi(data_809C351C)                 \n"
		"lwc1            $f4,%lo(data_809C351C)($at)            \n"
		"addiu           $t5,$sp,96                             \n"
		"lui             $at,0x4188                             \n"
		"swc1            $f4,88($sp)                            \n"
		"lw              $t7,36($s0)                            \n"
		"mtc1            $at,$f8                                \n"
		"lui             $t9,0x0001                             \n"
		"sw              $t7,0($t5)                             \n"
		"lw              $t6,40($s0)                            \n"
		"or              $a1,$s0,$zero                          \n"
		"addiu           $a2,$sp,96                             \n"
		"sw              $t6,4($t5)                             \n"
		"lw              $t7,44($s0)                            \n"
		"addiu           $a3,$sp,132                            \n"
		"addiu           $t3,$sp,108                            \n"
		"sw              $t7,8($t5)                             \n"
		"lwc1            $f6,100($sp)                           \n"
		"lw              $t8,148($sp)                           \n"
		"add.s           $f10,$f6,$f8                           \n"
		"addu            $t9,$t9,$t8                            \n"
		"or              $a0,$t8,$zero                          \n"
		"swc1            $f10,100($sp)                          \n"
		"lw              $t9,7652($t9)                          \n"
		"andi            $t2,$t9,0x1                            \n"
		"bnel            $t2,$zero,.L000028                     \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x80029184                 \n"
		"sw              $t3,16($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		".L000028:                                              \n"
		"jal             0x8002F828                 \n"
		"addiu           $a1,$zero,4109                         \n"
		"lui             $at,0x4040                             \n"
		"mtc1            $at,$f18                               \n"
		"lwc1            $f16,100($sp)                          \n"
		"addiu           $t4,$sp,80                             \n"
		"addiu           $t5,$zero,50                           \n"
		"add.s           $f4,$f16,$f18                          \n"
		"addiu           $t6,$zero,5                            \n"
		"sw              $t6,28($sp)                            \n"
		"sw              $t5,24($sp)                            \n"
		"swc1            $f4,100($sp)                           \n"
		"sw              $t4,16($sp)                            \n"
		"sw              $t4,20($sp)                            \n"
		"lw              $a0,148($sp)                           \n"
		"addiu           $a1,$sp,96                             \n"
		"addiu           $a2,$sp,132                            \n"
		"jal             0x8002829C                 \n"
		"addiu           $a3,$sp,84                             \n"
		".L000027:                                              \n"
		"addiu           $t7,$s0,36                             \n"
		"sw              $t7,52($sp)                            \n"
		"lbu             $t9,349($s0)                           \n"
		"andi            $t2,$t9,0x2                            \n"
		"bnel            $t2,$zero,.L000029                     \n"
		"sh              $zero,504($s0)                         \n"
		"lbu             $t8,350($s0)                           \n"
		"andi            $t3,$t8,0x2                            \n"
		"beql            $t3,$zero,.L000030                     \n"
		"lh              $t6,504($s0)                           \n"
		"lw              $t4,344($s0)                           \n"
		"addiu           $at,$zero,5                            \n"
		"lbu             $t5,2($t4)                             \n"
		"bnel            $t5,$at,.L000030                       \n"
		"lh              $t6,504($s0)                           \n"
		"sh              $zero,504($s0)                         \n"
		".L000029:                                              \n"
		"beq             $zero,$zero,.L000031                   \n"
		"sh              $zero,184($s0)                         \n"
		"lh              $t6,504($s0)                           \n"
		".L000030:                                              \n"
		"lw              $a0,148($sp)                           \n"
		"lw              $a1,52($sp)                            \n"
		"slti            $at,$t6,101                            \n"
		"bne             $at,$zero,.L000031                     \n"
		"lui             $a2,0x41F0                             \n"
		"jal             0x8008EF5C                 \n"
		"lui             $a3,0x4248                             \n"
		"beq             $v0,$zero,.L000031                     \n"
		"addiu           $t7,$zero,100                          \n"
		"sh              $t7,504($s0)                           \n"
		".L000031:                                              \n"
		"lui             $at,%hi(data_809C3520)                 \n"
		"lwc1            $f6,%lo(data_809C3520)($at)            \n"
		"lw              $t2,52($sp)                            \n"
		"addiu           $t9,$sp,96                             \n"
		"swc1            $f6,88($sp)                            \n"
		"lw              $t3,0($t2)                             \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f10                               \n"
		"sw              $t3,0($t9)                             \n"
		"lw              $t8,4($t2)                             \n"
		"addiu           $at,$zero,3                            \n"
		"sw              $t8,4($t9)                             \n"
		"lw              $t3,8($t2)                             \n"
		"sw              $t3,8($t9)                             \n"
		"lwc1            $f8,100($sp)                           \n"
		"add.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,100($sp)                          \n"
		"lh              $v0,504($s0)                           \n"
		"beq             $v0,$at,.L000032                       \n"
		"addiu           $at,$zero,20                           \n"
		"beq             $v0,$at,.L000032                       \n"
		"addiu           $at,$zero,40                           \n"
		"bnel            $v0,$at,.L000033                       \n"
		"slti            $at,$v0,100                            \n"
		".L000032:                                              \n"
		"lh              $t4,506($s0)                           \n"
		"sh              $zero,184($s0)                         \n"
		"lh              $v0,504($s0)                           \n"
		"sra             $t5,$t4,1                              \n"
		"sh              $t5,506($s0)                           \n"
		"slti            $at,$v0,100                            \n"
		".L000033:                                              \n"
		"beql            $at,$zero,.L000034                     \n"
		"lh              $t9,506($s0)                           \n"
		"lh              $v1,506($s0)                           \n"
		"addiu           $t6,$v1,1                              \n"
		"and             $t7,$v0,$t6                            \n"
		"beql            $t7,$zero,.L000034                     \n"
		"lh              $t9,506($s0)                           \n"
		"mtc1            $v1,$f18                               \n"
		"lui             $at,0x430C                             \n"
		"mtc1            $at,$f0                                \n"
		"cvt.s.w         $f4,$f18                               \n"
		"mtc1            $zero,$f2                              \n"
		"mfc1            $a1,$f0                                \n"
		"addiu           $a0,$s0,508                            \n"
		"lui             $a2,0x3F80                             \n"
		"swc1            $f2,16($sp)                            \n"
		"div.s           $f6,$f0,$f4                            \n"
		"mfc1            $a3,$f6                                \n"
		"jal             0x80078310                 \n"
		"nop                                                    \n"
		"beq             $zero,$zero,.L000035                   \n"
		"lh              $v0,504($s0)                           \n"
		"lh              $t9,506($s0)                           \n"
		".L000034:                                              \n"
		"lui             $at,0x430C                             \n"
		"mtc1            $at,$f0                                \n"
		"mtc1            $t9,$f8                                \n"
		"mtc1            $zero,$f2                              \n"
		"addiu           $a0,$s0,508                            \n"
		"cvt.s.w         $f10,$f8                               \n"
		"mfc1            $a1,$f2                                \n"
		"lui             $a2,0x3F80                             \n"
		"swc1            $f2,16($sp)                            \n"
		"div.s           $f16,$f0,$f10                          \n"
		"mfc1            $a3,$f16                               \n"
		"jal             0x80078310                 \n"
		"nop                                                    \n"
		"lh              $v0,504($s0)                           \n"
		".L000035:                                              \n"
		"slti            $at,$v0,3                              \n"
		"beq             $at,$zero,.L000036                     \n"
		"lui             $at,%hi(data_809C3524)                 \n"
		"lwc1            $f4,%lo(data_809C3524)($at)            \n"
		"lwc1            $f18,80($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f6,$f18,$f4                           \n"
		"mfc1            $a1,$f6                                \n"
		"jal             0x8002D62C                 \n"
		"nop                                                    \n"
		"lh              $v0,504($s0)                           \n"
		".L000036:                                              \n"
		"bne             $v0,$zero,.L000037                     \n"
		"lw              $t8,52($sp)                            \n"
		"lw              $t4,0($t8)                             \n"
		"lw              $a1,148($sp)                           \n"
		"addiu           $t2,$sp,96                             \n"
		"sw              $t4,0($t2)                             \n"
		"lw              $t3,4($t8)                             \n"
		"lui             $at,0x4120                             \n"
		"mtc1            $at,$f10                               \n"
		"sw              $t3,4($t2)                             \n"
		"lw              $t4,8($t8)                             \n"
		"lui             $at,0x0001                             \n"
		"addu            $v1,$a1,$at                            \n"
		"sw              $t4,8($t2)                             \n"
		"lwc1            $f8,100($sp)                           \n"
		"sw              $v1,56($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"add.s           $f16,$f8,$f10                          \n"
		"jal             0x8002F410                 \n"
		"swc1            $f16,100($sp)                          \n"
		"beq             $v0,$zero,.L000038                     \n"
		"lw              $v1,56($sp)                            \n"
		"lui             $at,0x41F0                             \n"
		"mtc1            $at,$f4                                \n"
		"lwc1            $f18,100($sp)                          \n"
		"add.s           $f6,$f18,$f4                           \n"
		"swc1            $f6,100($sp)                           \n"
		".L000038:                                              \n"
		"addiu           $t5,$zero,100                          \n" /* uint16_t scale; Confirmed */
		"sw              $t5,16($sp)                            \n" /* sp + 0x10 */
		"lh              $t6,184($s0)                           \n"
		"sw              $v1,56($sp)                            \n"
		"lw              $a0,148($sp)                           \n" /* z64_global_t *gl; Confirmed */
		"sll             $t7,$t6,2                              \n"
		"subu            $t7,$t7,$t6                            \n"
		"sll             $t7,$t7,1                              \n"
		"addiu           $t9,$t7,19                             \n" /* uint16_t growth_velocity */
		"sw              $t9,20($sp)                            \n" /* sp + 0x14 */
		"addiu           $a1,$sp,96                             \n" /* vec3f_t *position; Confirmed */
		"addiu           $a2,$sp,132                            \n" /* a2 */
		"jal             0x80028E84                 						\n" /* effect_spawn_bomb2 */
		"addiu           $a3,$sp,120                            \n" /* a3 */
		"lwc1            $f8,128($s0)                           \n"
		"lui             $at,0xC6FA                             \n"
		"mtc1            $at,$f10                               \n"
		"swc1            $f8,100($sp)                           \n"
		"lwc1            $f16,128($s0)                          \n"
		"lw              $v1,56($sp)                            \n"
		"lw              $a0,148($sp)                           \n"
		"c.lt.s          $f10,$f16                              \n"
		"addiu           $a1,$sp,96                             \n"
		"addiu           $a2,$sp,132                            \n"
		"addiu           $a3,$sp,108                            \n"
		"bc1fl           .L000039                               \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x80029024                 \n"
		"sw              $v1,56($sp)                            \n"
		"lw              $v1,56($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		".L000039:                                              \n"
		"addiu           $a1,$zero,6158                         \n"
		"jal             0x8002F828                 \n"
		"sw              $v1,56($sp)                            \n"
		"lw              $v1,56($sp)                            \n"
		"lw              $t1,148($sp)                           \n"
		"addiu           $t0,$zero,250                          \n"
		"sh              $t0,2746($v1)                          \n"
		"lh              $v0,2746($v1)                          \n"
		"sh              $t0,2740($v1)                          \n"
		"addiu           $a1,$zero,2                            \n"
		"sh              $v0,2744($v1)                          \n"
		"sh              $v0,2742($v1)                          \n"
		"lh              $v0,2740($v1)                          \n"
		"addiu           $a2,$zero,11                           \n"
		"addiu           $a3,$zero,8                            \n"
		"addiu           $a0,$t1,480                            \n"
		"sh              $v0,2738($v1)                          \n"
		"jal             0x8005AA1C                 \n"
		"sh              $v0,2736($v1)                          \n"
		"lw              $t3,4($s0)                             \n"
		"addiu           $t2,$zero,1                            \n"
		"addiu           $t8,$zero,10                           \n"
		"lui             $a1,%hi(state_809C2A38)                 \n"
		"ori             $t4,$t3,0x20                           \n"
		"sh              $t2,28($s0)                            \n"
		"sh              $t8,504($s0)                           \n"
		"sw              $t4,4($s0)                             \n"
		"addiu           $a1,$a1,%lo(state_809C2A38)             \n"
		"jal             state_set_809C26D0                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000037:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		".L000026:                                              \n"
		"jal             0x8002D5B8                 \n"
		"lui             $a1,0x41A0                             \n"
		"lh              $t5,28($s0)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$s0,332                            \n"
		"bgtz            $t5,.L000040                           \n"
		"nop                                                    \n"
		"jal             0x800626DC                 \n"
		"sw              $a1,56($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8002F410                 \n"
		"lw              $a1,148($sp)                           \n"
		"bnel            $v0,$zero,.L000041                     \n"
		"lw              $a0,148($sp)                           \n"
		"lbu             $t6,512($s0)                           \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x1e60                         \n"
		"beq             $t6,$zero,.L000042                     \n"
		"lw              $a0,148($sp)                           \n"
		"addu            $a1,$a0,$at                            \n"
		"jal             0x8005DC4C                 \n"
		"lw              $a2,56($sp)                            \n"
		".L000042:                                              \n"
		"lw              $a0,148($sp)                           \n"
		".L000041:                                              \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x1e60                         \n"
		"lw              $a2,56($sp)                            \n"
		"jal             0x8005D9F4                 \n"
		"addu            $a1,$a0,$at                            \n"
		".L000040:                                              \n"
		"lui             $at,%hi(data_809C3528)                 \n"
		"lwc1            $f4,%lo(data_809C3528)($at)            \n"
		"lwc1            $f18,80($s0)                           \n"
		"c.le.s          $f4,$f18                               \n"
		"nop                                                    \n"
		"bc1fl           .L000043                               \n"
		"lw              $ra,44($sp)                            \n"
		"lh              $t2,28($s0)                            \n"
		"addiu           $at,$zero,1                            \n"
		"beq             $t2,$at,.L000044                       \n"
		"lui             $at,0x41A0                             \n"
		"mtc1            $at,$f8                                \n"
		"lwc1            $f6,132($s0)                           \n"
		"lw              $a0,148($sp)                           \n"
		"addiu           $a1,$s0,228                            \n"
		"c.le.s          $f8,$f6                                \n"
		"addiu           $a2,$zero,6159                         \n"
		"addiu           $a3,$zero,1                            \n"
		"addiu           $t8,$zero,1                            \n"
		"bc1f            .L000045                               \n"
		"addiu           $t3,$zero,10                           \n"
		"sw              $t8,16($sp)                            \n"
		"jal             0x8002A9F4                 \n"
		"sw              $t3,20($sp)                            \n"
		"jal             0x8002D570                 \n"
		"or              $a0,$s0,$zero                          \n"
		"beq             $zero,$zero,.L000043                   \n"
		"lw              $ra,44($sp)                            \n"
		".L000045:                                              \n"
		"lhu             $v0,136($s0)                           \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$zero,10263                        \n"
		"andi            $t4,$v0,0x40                           \n"
		"beq             $t4,$zero,.L000044                     \n"
		"andi            $t5,$v0,0xffbf                         \n"
		"jal             0x8002F828                 \n"
		"sh              $t5,136($s0)                           \n"
		".L000044:                                              \n"
		"lw              $ra,44($sp)                            \n"
		".L000043:                                              \n"
		"lw              $s0,40($sp)                            \n"
		"addiu           $sp,$sp,144                            \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}

void state_809C29F4(entity_t *en, z64_global_t *gl)
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lstate_809C29F4: \n"
	);

	if (external_func_8002F5A0() != 0)
	{
		state_set_809C26D0(en, (z64_actorfunc_t *)state_809C282C);
		state_809C282C(en, gl);
	}
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* <-- magic values, do not change */
	.type = 0x03,
	.room = 0x00,
	.flags = 0x00000030,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init_809C26D8,
	.dest = dest_809C27EC,
	.main = state_main_809C2B88,
	.draw = draw_809C3218
};
