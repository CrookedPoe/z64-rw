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
