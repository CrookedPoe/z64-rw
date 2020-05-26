void data_809EA4E8(entity_t* en) /* 1 internal, 2 external, 20 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_809EA4E8: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"sw              $a1,28($sp)                            \n"
		"addiu           $a1,$zero,0                            \n"
		"addiu           $a0,$a0,104                            \n"
		"jal             0x80077A00                 \n"
		"lui             $a2,0x3F80                             \n"
		"lw              $a0,24($sp)                            \n"
		"jal             0x800A49FC                 \n"
		"addiu           $a0,$a0,332                            \n"
		"beql            $v0,$zero,.L000062                     \n"
		"lw              $ra,20($sp)                            \n"
		"jal             func_809E9B48                          \n"
		"lw              $a0,24($sp)                            \n"
		"lw              $ra,20($sp)                            \n"
		".L000062:                                              \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
