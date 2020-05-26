void func_809E9920(entity_t* en) /* 0 internal, 1 external, 22 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E9920: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,13904                          \n"
		"sw              $a2,24($sp)                            \n"
		"jal             0x800A52F8                 \n"
		"addiu           $a0,$a0,332                            \n"
		"lw              $a2,24($sp)                            \n"
		"lui             $t9,%hi(data_809EA240)                 \n"
		"addiu           $t6,$zero,2                            \n"
		"lbu             $t7,729($a2)                           \n"
		"addiu           $t9,$t9,%lo(data_809EA240)             \n"
		"sh              $t6,406($a2)                           \n"
		"ori             $t8,$t7,0x1                            \n"
		"sb              $zero,404($a2)                         \n"
		"sb              $t8,729($a2)                           \n"
		"sw              $t9,400($a2)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
