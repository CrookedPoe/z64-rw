#include <z64ovl/oot/debug.h>
#include <z64ovl/oot/helpers.h>

#define OBJ_ID 3

/*** object ***/
#define DL_TUBO 0x05017870

/*** sounds ***/
#define NA_SE_PL_BODY_HIT          0x083E
#define NA_SE_IT_SHIELD_REFLECT_SW 0x1808
#define NA_SE_EV_EXPLOSION         0x2802
#define NA_SE_EV_BOMB_DROP_WATER   0x2817
#define NA_SE_EV_POT_BROKEN        0x2887
#define	NA_SE_EV_POT_MOVE_START    0x28C4
#define NA_SE_EN_TUBOOCK_FLY       0x3037

typedef struct {
	z64_actor_t actor; 				 							 /* 0x0000, 0x013C */
	uint8_t inst_unk[16];  	   							 /* 0x013C, 0x0010 */
	z64_actorfunc_t *playfunc; 							 /* 0x014C, 0x0004 */
	float pos_y_seek;          							 /* 0x0150, 0x0004 */
	vec3f_t pos_init;          							 /* 0x0154, 0x000C */
	z64_collider_cylinder_main_t capsule;		 /* 0x0160, 0x004C */
} entity_t; /* 01AC */


/*** function prototypes ***/
void draw(entity_t *en, z64_global_t *gl); /* Confirmed */
void dest(entity_t *en, z64_global_t *gl); /* Confirmed */
void tubo_trap_drop_collectible(entity_t *en, z64_global_t *gl); /* Confirmed */
void tubo_trap_initialize_attack(entity_t *en); /* Confirmed */
void tubo_trap_test_levitate(entity_t *en, z64_global_t *gl); /* Confirmed */
void init(entity_t *en, z64_global_t *gl); /* Confirmed */
void func_80B25A18(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 160 lines */
void func_80B25C8C(entity_t *en, z64_global_t *gl); /* 0 internal, 5 external, 161 lines */
void play(entity_t *en, z64_global_t *gl); /* Confirmed */
void tubo_trap_fly(entity_t *en, z64_global_t *gl); /* Confirmed */
void func_80B25F08(entity_t *en, z64_global_t *gl); /* Confirmed */


/*** variables ***/
const uint32_t data_80B264E0[] =
{
	0x0A110900,
	0x20010000,
	0x00000000,
	0xFFCFFFFF,
	0x00040000,
	0xFFCFFFFF,
	0x00000000,
	0x01010000,
	0x00090017,
	0x00000000,
	0x00000000
};
/*	0x011D0600,
	0x00000010,
	0x00030000,
	0x000001AC,
	(uint32_t)(void*)init,
	(uint32_t)(void*)dest,
	(uint32_t)(void*)play,
	(uint32_t)(void*)draw,
	0x00000000,
};*/
const uint32_t data_80B26530[] =
{
	0x0A0A0000
};
const uint32_t data_80B26534[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xC4DBA5C8,
	0xA5E9A5C3,
	0xA5D720A1,
	0xF9A1F9A1,
	0xF9A1F9A1,
	0xF9202578,
	0x0A1B5B6D,
	0x00000000
};
const uint32_t data_80B26564[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xA4EFA4C6,
	0x20202020,
	0x20A1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0x25660A1B,
	0x5B6D0000
};
const uint32_t data_80B26590[] =
{
	0x1B5B3332,
	0x6DA1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0xA4AAA4A4,
	0xA4C9A4F3,
	0x20A1F9A1,
	0xF9A1F9A1,
	0xF9A1F920,
	0x25660A1B,
	0x5B6D0000
};
const uint32_t data_80B265BC[] =
{
	0x0A0A0000
};
const uint32_t data_80B265C0[] =
{
	0x3E6B851F
};
const uint32_t data_80B265C4[] =
{
	0x3E4CCCCD
};
const uint32_t data_80B265C8[] =
{
	0x3F199999
};
const uint32_t data_80B265CC[] =
{
	0x3E4CCCCD
};
const uint32_t data_80B265D0[] =
{
	0x3E4CCCCD,
	0x00000000,
	0x00000000,
	0x00000000
};


/*** functions ***/
void draw(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 13 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldraw: \n"
	);

	draw_static_dlist_opa(gl, DL_TUBO);
}

void dest(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ldest: \n"
	);

	actor_capsule_free(gl, &en->capsule);
}

void tubo_trap_drop_collectible(entity_t *en, z64_global_t *gl) /* 0 internal, 1 external, 25 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ltubo_trap_drop_collectible: \n"
	);

	uint16_t uVar1;
	uint32_t uVar2;

	uVar2 = SEXT24((en->actor).variable);
	uVar1 = uVar2 >> 6 & 0x03FF;
	if (uVar1 < 0x001A)
	{
		item_drop_collectible(gl, &(en->actor).pos_2, (uVar1 | (uVar2 & 0x3F) << 8));
	}
}

void tubo_trap_initialize_attack(entity_t *en) /* 0 internal, 1 external, 36 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ltubo_trap_initialize_attack: \n"
	);

	(en->actor).rot_2.y += 5000;
	external_func_8007841C(&(en->actor).pos_2.y, en->pos_y_seek, 0.8f, 3.0f); /* Tween levitation */
	if (ABS((en->actor).pos_2.y - en->pos_y_seek) < 10.0f)
	{
		(en->actor).xz_speed = 10.0f;
		(en->actor).xz_dir = (en->actor).rot_toward_link_y;
		en->playfunc = (z64_actorfunc_t *)tubo_trap_fly;
	}
}

void tubo_trap_test_levitate(entity_t *en, z64_global_t *gl) /* 0 internal, 3 external, 95 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ltubo_trap_test_levitate: \n"
	);

	z64_player_t *player = helper_get_player(gl);

	if ((AVAL(0x8015FA90, int16_t, 0x12D8)) != 0)
	{
		float pos_y = (en->actor).pos_2.y;
		//debug_message(&data_80B26564, gl, (pos_y >> 0x20), SUB84(pos_y, 0));
		//debug_message(&data_80B26590);
		//debug_message(&data_80B265BC);
	}

	float link_y = (player->actor).pos_2.y;

	if (((en->actor).dist_from_link_xz < 200.0f) && ((en->actor).pos_2.y <= link_y))
	{
			float seek_y;

			external_func_80033748(gl, /*gl->actor_ctxt*/&AVAL(gl, char, 0x1C24), &en->actor, 5);
			(en->actor).flags |= 1;
			seek_y = 40.0f - (10.0f * zh_link_is_child()); /* 10 units lower if Child */
			en->pos_y_seek = link_y + seek_y;
			if (en->pos_y_seek < (en->actor).pos_2.y)
			{
					en->pos_y_seek = (en->actor).pos_2.y + seek_y;
			}
			(en->pos_init).x = en->actor.pos_2.x;
			(en->pos_init).y = en->actor.pos_2.y;
			(en->pos_init).z = en->actor.pos_2.z;
			sound_play_actor2(&en->actor, NA_SE_EV_POT_MOVE_START);
			en->playfunc = (z64_actorfunc_t *)tubo_trap_initialize_attack;
	}
}

void init(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 40 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Linit: \n"
	);

	actor_init_shadow(&(en->actor).rot_2, 0, &ACTOR_SHADOW_DRAWFUNC_CIRCLE, 2.0f);
	//debug_message(&data_80B26530);
	//debug_message(&data_80B26534, (en->actor).variable);
	actor_capsule_alloc(gl, &en->capsule);
	actor_capsule_init(gl, &en->capsule, &en->actor, data_80B264E0);
	actor_set_scale(&en->actor, 0.1f);
	en->playfunc = (z64_actorfunc_t *)tubo_trap_test_levitate;
}

void func_80B25A18(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 160 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B25A18: \n"
	);
	asm(
		"addiu           $sp,$sp,-224                           \n"
		"sdc1            $f30,112($sp)                          \n"
		"lui             $at,%hi(data_80B265C0)                 \n"
		"lwc1            $f30,%lo(data_80B265C0)($at)           \n"
		"sdc1            $f28,104($sp)                          \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f28                               \n"
		"sdc1            $f26,96($sp)                           \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f26                               \n"
		"sw              $s6,144($sp)                           \n"
		"sdc1            $f24,88($sp)                           \n"
		"lui             $at,0x4100                             \n"
		"sw              $s8,152($sp)                           \n"
		"sw              $s7,148($sp)                           \n"
		"sw              $s5,140($sp)                           \n"
		"sw              $s4,136($sp)                           \n"
		"sw              $s3,132($sp)                           \n"
		"sw              $s2,128($sp)                           \n"
		"sw              $s1,124($sp)                           \n"
		"lui             $s6,0x0501                             \n"
		"mtc1            $at,$f24                               \n"
		"or              $s8,$a1,$zero                          \n"
		"sw              $ra,156($sp)                           \n"
		"sw              $s0,120($sp)                           \n"
		"sdc1            $f22,80($sp)                           \n"
		"sdc1            $f20,72($sp)                           \n"
		"addiu           $s6,$s6,31328                          \n"
		"addiu           $s1,$a0,36                             \n"
		"or              $s2,$zero,$zero                        \n"
		"or              $s3,$zero,$zero                        \n"
		"addiu           $s4,$sp,200                            \n"
		"addiu           $s5,$sp,188                            \n"
		"addiu           $s7,$zero,15                           \n"
		".L000003:                                              \n"
		"sll             $a0,$s2,16                             \n"
		"jal             0x80077870                 \n"
		"sra             $a0,$a0,16                             \n"
		"sll             $a0,$s2,16                             \n"
		"mov.s           $f20,$f0                               \n"
		"jal             0x80077834                 \n"
		"sra             $a0,$a0,16                             \n"
		"mul.s           $f4,$f20,$f24                          \n"
		"mov.s           $f22,$f0                               \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f4,200($sp)                           \n"
		"mul.s           $f6,$f0,$f26                           \n"
		"lwc1            $f16,200($sp)                          \n"
		"mul.s           $f10,$f22,$f24                         \n"
		"nop                                                    \n"
		"mul.s           $f18,$f16,$f30                         \n"
		"add.s           $f8,$f6,$f28                           \n"
		"swc1            $f10,208($sp)                          \n"
		"swc1            $f8,204($sp)                           \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f18,188($sp)                          \n"
		"mul.s           $f4,$f0,$f26                           \n"
		"lwc1            $f8,208($sp)                           \n"
		"lwc1            $f16,200($sp)                          \n"
		"mul.s           $f10,$f8,$f30                          \n"
		"add.s           $f6,$f4,$f28                           \n"
		"swc1            $f10,196($sp)                          \n"
		"swc1            $f6,192($sp)                           \n"
		"lwc1            $f18,0($s1)                            \n"
		"lwc1            $f6,204($sp)                           \n"
		"add.s           $f4,$f16,$f18                          \n"
		"swc1            $f4,200($sp)                           \n"
		"lwc1            $f10,4($s1)                            \n"
		"add.s           $f16,$f6,$f10                          \n"
		"swc1            $f16,204($sp)                          \n"
		"lwc1            $f18,8($s1)                            \n"
		"add.s           $f4,$f8,$f18                           \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f4,208($sp)                           \n"
		"lui             $at,%hi(data_80B265C4)                 \n"
		"lwc1            $f6,%lo(data_80B265C4)($at)            \n"
		"lui             $at,%hi(data_80B265C8)                 \n"
		"c.lt.s          $f0,$f6                                \n"
		"nop                                                    \n"
		"bc1f            .L000001                               \n"
		"nop                                                    \n"
		"b               .L000002                               \n"
		"addiu           $s0,$zero,96                           \n"
		".L000001:                                              \n"
		"lwc1            $f10,%lo(data_80B265C8)($at)           \n"
		"addiu           $s0,$zero,32                           \n"
		"c.lt.s          $f0,$f10                               \n"
		"nop                                                    \n"
		"bc1f            .L000002                               \n"
		"nop                                                    \n"
		"b               .L000002                               \n"
		"addiu           $s0,$zero,64                           \n"
		".L000002:                                              \n"
		"jal             0x800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4282                             \n"
		"mtc1            $at,$f16                               \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f18                               \n"
		"mul.s           $f8,$f0,$f16                           \n"
		"addiu           $t6,$zero,-240                         \n"
		"addiu           $t7,$zero,10                           \n"
		"addiu           $t8,$zero,10                           \n"
		"addiu           $t1,$zero,32                           \n"
		"addiu           $t2,$zero,60                           \n"
		"addiu           $t3,$zero,-1                           \n"
		"add.s           $f4,$f8,$f18                           \n"
		"addiu           $t4,$zero,3                            \n"
		"sw              $t4,56($sp)                            \n"
		"sw              $t3,52($sp)                            \n"
		"trunc.w.s       $f6,$f4                                \n"
		"sw              $t2,48($sp)                            \n"
		"sw              $t1,44($sp)                            \n"
		"sw              $t8,28($sp)                            \n"
		"mfc1            $t0,$f6                                \n"
		"sw              $t7,24($sp)                            \n"
		"sw              $t6,16($sp)                            \n"
		"or              $a0,$s8,$zero                          \n"
		"or              $a1,$s4,$zero                          \n"
		"or              $a2,$s5,$zero                          \n"
		"or              $a3,$s1,$zero                          \n"
		"sw              $s0,20($sp)                            \n"
		"sw              $zero,32($sp)                          \n"
		"sw              $zero,40($sp)                          \n"
		"sw              $s6,60($sp)                            \n"
		"jal             0x80029E8C                 \n"
		"sw              $t0,36($sp)                            \n"
		"addiu           $s2,$s2,20000                          \n"
		"sll             $s2,$s2,16                             \n"
		"addiu           $s3,$s3,1                              \n"
		"bne             $s3,$s7,.L000003                       \n"
		"sra             $s2,$s2,16                             \n"
		"addiu           $t5,$zero,20                           \n"
		"addiu           $t6,$zero,50                           \n"
		"sw              $t6,20($sp)                            \n"
		"sw              $t5,16($sp)                            \n"
		"or              $a0,$s8,$zero                          \n"
		"or              $a1,$s1,$zero                          \n"
		"lui             $a2,0x41F0                             \n"
		"addiu           $a3,$zero,4                            \n"
		"jal             0x80033480                 \n"
		"sw              $zero,24($sp)                          \n"
		"lw              $ra,156($sp)                           \n"
		"ldc1            $f20,72($sp)                           \n"
		"ldc1            $f22,80($sp)                           \n"
		"ldc1            $f24,88($sp)                           \n"
		"ldc1            $f26,96($sp)                           \n"
		"ldc1            $f28,104($sp)                          \n"
		"ldc1            $f30,112($sp)                          \n"
		"lw              $s0,120($sp)                           \n"
		"lw              $s1,124($sp)                           \n"
		"lw              $s2,128($sp)                           \n"
		"lw              $s3,132($sp)                           \n"
		"lw              $s4,136($sp)                           \n"
		"lw              $s5,140($sp)                           \n"
		"lw              $s6,144($sp)                           \n"
		"lw              $s7,148($sp)                           \n"
		"lw              $s8,152($sp)                           \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,224                            \n"
	);
}
void func_80B25C8C(entity_t *en, z64_global_t *gl) /* 0 internal, 5 external, 161 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80B25C8C: \n"
	);
	asm(
		"addiu           $sp,$sp,-224                           \n"
		"sw              $s1,124($sp)                           \n"
		"sw              $ra,156($sp)                           \n"
		"sw              $s8,152($sp)                           \n"
		"sw              $s7,148($sp)                           \n"
		"sw              $s6,144($sp)                           \n"
		"sw              $s5,140($sp)                           \n"
		"sw              $s4,136($sp)                           \n"
		"sw              $s3,132($sp)                           \n"
		"sw              $s2,128($sp)                           \n"
		"sw              $s0,120($sp)                           \n"
		"sdc1            $f30,112($sp)                          \n"
		"sdc1            $f28,104($sp)                          \n"
		"sdc1            $f26,96($sp)                           \n"
		"sdc1            $f24,88($sp)                           \n"
		"sdc1            $f22,80($sp)                           \n"
		"sdc1            $f20,72($sp)                           \n"
		"addiu           $s1,$a0,36                             \n"
		"lw              $t7,0($s1)                             \n"
		"addiu           $s5,$sp,200                            \n"
		"or              $s4,$a1,$zero                          \n"
		"sw              $t7,0($s5)                             \n"
		"lw              $t6,4($s1)                             \n"
		"addiu           $t8,$zero,400                          \n"
		"or              $a2,$zero,$zero                        \n"
		"sw              $t6,4($s5)                             \n"
		"lw              $t7,8($s1)                             \n"
		"or              $a3,$zero,$zero                        \n"
		"sw              $t7,8($s5)                             \n"
		"lwc1            $f4,204($sp)                           \n"
		"lwc1            $f6,132($a0)                           \n"
		"or              $a0,$a1,$zero                          \n"
		"or              $a1,$s5,$zero                          \n"
		"add.s           $f8,$f4,$f6                            \n"
		"sw              $t8,20($sp)                            \n"
		"sw              $zero,16($sp)                          \n"
		"jal             0x8002949C                 \n"
		"swc1            $f8,204($sp)                           \n"
		"lui             $at,0x40A0                             \n"
		"mtc1            $at,$f30                               \n"
		"lui             $at,%hi(data_80B265CC)                 \n"
		"lwc1            $f28,%lo(data_80B265CC)($at)           \n"
		"lui             $at,0x4000                             \n"
		"mtc1            $at,$f26                               \n"
		"lui             $at,0x4100                             \n"
		"lui             $s7,0x0501                             \n"
		"mtc1            $at,$f24                               \n"
		"addiu           $s7,$s7,31328                          \n"
		"or              $s3,$zero,$zero                        \n"
		"or              $s2,$zero,$zero                        \n"
		"addiu           $s8,$zero,15                           \n"
		"addiu           $s6,$sp,188                            \n"
		".L000005:                                              \n"
		"sll             $a0,$s2,16                             \n"
		"jal             0x80077870                 \n"
		"sra             $a0,$a0,16                             \n"
		"sll             $a0,$s2,16                             \n"
		"mov.s           $f20,$f0                               \n"
		"jal             0x80077834                 \n"
		"sra             $a0,$a0,16                             \n"
		"mul.s           $f10,$f20,$f24                         \n"
		"mov.s           $f22,$f0                               \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f10,200($sp)                          \n"
		"mul.s           $f16,$f0,$f30                          \n"
		"lwc1            $f6,200($sp)                           \n"
		"mul.s           $f4,$f22,$f24                          \n"
		"nop                                                    \n"
		"mul.s           $f8,$f6,$f28                           \n"
		"add.s           $f18,$f16,$f26                         \n"
		"swc1            $f4,208($sp)                           \n"
		"swc1            $f18,204($sp)                          \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f8,188($sp)                           \n"
		"lui             $at,0x4080                             \n"
		"mtc1            $at,$f10                               \n"
		"lwc1            $f4,208($sp)                           \n"
		"lwc1            $f8,200($sp)                           \n"
		"mul.s           $f16,$f0,$f10                          \n"
		"add.s           $f18,$f16,$f26                         \n"
		"mul.s           $f6,$f4,$f28                           \n"
		"swc1            $f18,192($sp)                          \n"
		"lwc1            $f18,204($sp)                          \n"
		"swc1            $f6,196($sp)                           \n"
		"lwc1            $f10,0($s1)                            \n"
		"add.s           $f16,$f8,$f10                          \n"
		"swc1            $f16,200($sp)                          \n"
		"lwc1            $f6,4($s1)                             \n"
		"add.s           $f8,$f18,$f6                           \n"
		"swc1            $f8,204($sp)                           \n"
		"lwc1            $f10,8($s1)                            \n"
		"add.s           $f16,$f4,$f10                          \n"
		"jal             0x800FD9AC                 \n"
		"swc1            $f16,208($sp)                          \n"
		"lui             $at,%hi(data_80B265D0)                 \n"
		"lwc1            $f18,%lo(data_80B265D0)($at)           \n"
		"addiu           $s0,$zero,32                           \n"
		"c.lt.s          $f0,$f18                               \n"
		"nop                                                    \n"
		"bc1f            .L000004                               \n"
		"nop                                                    \n"
		"b               .L000004                               \n"
		"addiu           $s0,$zero,64                           \n"
		".L000004:                                              \n"
		"jal             0x800FD9AC                 \n"
		"nop                                                    \n"
		"lui             $at,0x4282                             \n"
		"mtc1            $at,$f6                                \n"
		"lui             $at,0x4170                             \n"
		"mtc1            $at,$f4                                \n"
		"mul.s           $f8,$f0,$f6                            \n"
		"addiu           $t9,$zero,-180                         \n"
		"addiu           $t0,$zero,30                           \n"
		"addiu           $t1,$zero,30                           \n"
		"addiu           $t4,$zero,32                           \n"
		"addiu           $t5,$zero,70                           \n"
		"addiu           $t6,$zero,-1                           \n"
		"add.s           $f10,$f8,$f4                           \n"
		"addiu           $t7,$zero,3                            \n"
		"sw              $t7,56($sp)                            \n"
		"sw              $t6,52($sp)                            \n"
		"trunc.w.s       $f16,$f10                              \n"
		"sw              $t5,48($sp)                            \n"
		"sw              $t4,44($sp)                            \n"
		"sw              $t1,28($sp)                            \n"
		"mfc1            $t3,$f16                               \n"
		"sw              $t0,24($sp)                            \n"
		"sw              $t9,16($sp)                            \n"
		"or              $a0,$s4,$zero                          \n"
		"or              $a1,$s5,$zero                          \n"
		"or              $a2,$s6,$zero                          \n"
		"or              $a3,$s1,$zero                          \n"
		"sw              $s0,20($sp)                            \n"
		"sw              $zero,32($sp)                          \n"
		"sw              $zero,40($sp)                          \n"
		"sw              $s7,60($sp)                            \n"
		"jal             0x80029E8C                 \n"
		"sw              $t3,36($sp)                            \n"
		"addiu           $s2,$s2,20000                          \n"
		"sll             $s2,$s2,16                             \n"
		"addiu           $s3,$s3,1                              \n"
		"bne             $s3,$s8,.L000005                       \n"
		"sra             $s2,$s2,16                             \n"
		"lw              $ra,156($sp)                           \n"
		"ldc1            $f20,72($sp)                           \n"
		"ldc1            $f22,80($sp)                           \n"
		"ldc1            $f24,88($sp)                           \n"
		"ldc1            $f26,96($sp)                           \n"
		"ldc1            $f28,104($sp)                          \n"
		"ldc1            $f30,112($sp)                          \n"
		"lw              $s0,120($sp)                           \n"
		"lw              $s1,124($sp)                           \n"
		"lw              $s2,128($sp)                           \n"
		"lw              $s3,132($sp)                           \n"
		"lw              $s4,136($sp)                           \n"
		"lw              $s5,140($sp)                           \n"
		"lw              $s6,144($sp)                           \n"
		"lw              $s7,148($sp)                           \n"
		"lw              $s8,152($sp)                           \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,224                            \n"
	);
}

void play(entity_t *en, z64_global_t *gl) /* 0 internal, 6 external, 46 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lplay: \n"
	);

	z64_actorfunc_t *playfunc = en->playfunc;
	playfunc(en, gl);
	external_func_8002D8E0(&en->actor); /* Probably to haul ass towards Link */
	external_func_8002E4B4(gl, &en->actor, 10.0f, 10.0f, 20.0f, 0x1D); /* Necessary for drawing a shadow */
	actor_set_height(&en->actor, 0);
	actor_capsule_update(&en->actor, &en->capsule);
	actor_collision_check_set_ac(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
	actor_collision_check_set_at(gl, /*&gl->sbc_group_at_1*/AADDR(gl, 0x011E60), &en->capsule);
}

void tubo_trap_fly(entity_t *en, z64_global_t *gl) /* 1 internal, 2 external, 52 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Ltubo_trap_fly: \n"
	);

	vec3f_t pos_delta;
	int16_t rot_y;

	VEC3_SUB(pos_delta, en->pos_init, en->actor.pos_2);
	sound_play_actor2(&en->actor, NA_SE_EN_TUBOOCK_FLY);
	if (240.0f < SQRT((pos_delta.x * pos_delta.x) + (pos_delta.y * pos_delta.y) + (pos_delta.z * pos_delta.z)))
	{
		external_func_8007841C(&(en->actor).gravity, -3.0f, 0.2f, 0.5f); /* Tween to ground */
		rot_y = (en->actor).rot_2.y;
	}
	else
	{
		rot_y = (en->actor).rot_2.y;
	}
	(en->actor).rot_2.y = rot_y + 5000;
	func_80B25F08(en, gl);
}

void func_80B25F08(entity_t *en, z64_global_t *gl) /* 3 internal, 2 external, 144 lines */
{
	asm(
		".set at        \n"
		".set reorder   \n"
		".Lfunc_80B25F08: \n"
	);

	uint8_t bVar1, bVar2;
	uint16_t uVar3;
	z64_actor_t *collided_actor;
	z64_player_t *player = helper_get_player(gl);

	if (((en->actor).bgcheck_flags & 20) == 0)
	{
		bVar1 = (en->capsule).base.collider_flags;
	}
	else
	{
		if ((en->actor).water_surface_dist > 15.0f)
		{
			func_80B25C8C(en, gl);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_BOMB_DROP_WATER);
			tubo_trap_drop_collectible(en, gl);
			actor_kill(&en->actor);
			return;
		}
		bVar1 = (en->capsule).base.collider_flags;
	}

	if ((bVar1 & 4) == 0)
	{
		bVar2 = (en->capsule).base.collide_flags;
		if ((bVar2 & 2) == 0)
		{
			if ((bVar1 & 2) == 0)
			{
				uVar3 = (en->actor).bgcheck_flags;
			}
			else
			{
				collided_actor = (en->capsule).base.unk_actor_1;
				(en->capsule).base.collider_flags = bVar1 & 0xFD;
				if (collided_actor == &(player->actor))
				{
					func_80B25A18(en, gl);
					sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
					sound_play_position(gl, &(player->actor).pos_2, 0x28, NA_SE_PL_BODY_HIT);
					tubo_trap_drop_collectible(en, gl);
					actor_kill(&en->actor);
					return;
				}
				uVar3 = (en->actor).bgcheck_flags;
			}
			if (((uVar3 & 8) != 0) || ((uVar3 & 1) != 0))
			{
				func_80B25A18(en, gl);
				sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
				tubo_trap_drop_collectible(en, gl);
				actor_kill(&en->actor);
			}
		}
		else
		{
			(en->capsule).base.collide_flags = bVar2 & 0xFD;
			func_80B25A18(en, gl);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_EXPLOSION);
			sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
			tubo_trap_drop_collectible(en, gl);
			actor_kill(&en->actor);
		}
	}
	else
	{
		(en->capsule).base.collider_flags = bVar1 & 0xFB;
		func_80B25A18(en, gl);
		sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_IT_SHIELD_REFLECT_SW);
		sound_play_position(gl, &(en->actor).pos_2, 0x28, NA_SE_EV_POT_BROKEN);
		tubo_trap_drop_collectible(en, gl);
		actor_kill(&en->actor);
	}
}

const z64_actor_init_t init_vars = {
	.number = 0xDEAD, .padding = 0xBEEF, /* for use with zzromtool */
	.type = 0x06,
	.room = 0x00,
	.flags = 0x00000010,
	.object = OBJ_ID,
	.instance_size = sizeof(entity_t),
	.init = init,
	.dest = dest,
	.main = play,
	.draw = draw
};
