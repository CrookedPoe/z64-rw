void func_80A9F350(entity_t* en, z64_global_t* gl) /* 0 internal, 2 external, 49 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80A9F350: \n"
	);
	asm(
		"addiu           $sp,$sp,-40                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a0,40($sp)                            \n"
		"lw              $v0,7236($a1)                          \n"
		"lw              $t6,1664($v0)                          \n"
		"sll             $t7,$t6,14                             \n"
		"bgezl           $t7,.L000008                           \n"
		"lw              $t1,1660($v0)                          \n"
		"lb              $t8,2114($v0)                          \n"
		"lui             $a3,0x8013                             \n"
		"addiu           $a3,$a3,13280                          \n"
		"slti            $at,$t8,24                             \n"
		"bne             $at,$zero,.L000009                     \n"
		"addiu           $a0,$zero,6179                         \n"
		"lui             $t9,0x8013                             \n"
		"addiu           $t9,$t9,13288                          \n"
		"addiu           $a1,$v0,228                            \n"
		"sw              $a1,32($sp)                            \n"
		"sw              $t9,20($sp)                            \n"
		"addiu           $a2,$zero,4                            \n"
		"jal             0x800F738C                 \n"
		"sw              $a3,16($sp)                            \n"
		"lui             $a3,0x8013                             \n"
		"lui             $t0,0x8013                             \n"
		"addiu           $a3,$a3,13280                          \n"
		"addiu           $t0,$t0,13288                          \n"
		"lw              $a1,32($sp)                            \n"
		"sw              $t0,20($sp)                            \n"
		"sw              $a3,16($sp)                            \n"
		"addiu           $a0,$zero,6168                         \n"
		"jal             0x800F738C                 \n"
		"addiu           $a2,$zero,4                            \n"
		".L000009:                                              \n"
		"jal             0x8002D570                 \n"
		"lw              $a0,40($sp)                            \n"
		"beq             $zero,$zero,.L000010                   \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $t1,1660($v0)                          \n"
		".L000008:                                              \n"
		"andi            $t2,$t1,0x1000                         \n"
		"bnel            $t2,$zero,.L000010                     \n"
		"lw              $ra,28($sp)                            \n"
		"jal             0x8002D570                 \n"
		"lw              $a0,40($sp)                            \n"
		"lw              $ra,28($sp)                            \n"
		".L000010:                                              \n"
		"addiu           $sp,$sp,40                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}