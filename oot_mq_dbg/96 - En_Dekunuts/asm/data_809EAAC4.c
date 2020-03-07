void data_809EAAC4(entity_t* en, z64_global_t* gl) /* 0 internal, 2 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_809EAAC4: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a0,32($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"lh              $t7,28($a0)                            \n"
		"addiu           $at,$zero,10                           \n"
		"lw              $a0,36($sp)                            \n"
		"bne             $t7,$at,.L000087                       \n"
		"lw              $t8,32($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"jal             0x80035260                 \n"
		"addiu           $a1,$a1,8856                           \n"
		"beq             $zero,$zero,.L000088                   \n"
		"lw              $ra,28($sp)                            \n"
		".L000087:                                              \n"
		"lw              $a1,336($t8)                           \n"
		"lw              $a2,364($t8)                           \n"
		"lui             $a3,%hi(data_809EA98C)                 \n"
		"addiu           $a3,$a3,%lo(data_809EA98C)             \n"
		"sw              $t8,20($sp)                            \n"
		"jal             0x800A15C8                 \n"
		"sw              $zero,16($sp)                          \n"
		"lw              $ra,28($sp)                            \n"
		".L000088:                                              \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
		"nop                                                    \n"
	);
}
