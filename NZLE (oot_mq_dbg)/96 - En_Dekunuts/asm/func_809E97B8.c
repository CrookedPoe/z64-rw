void func_809E97B8(entity_t* en) /* 0 internal, 1 external, 18 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E97B8: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,452                            \n"
		"sw              $a2,24($sp)                            \n"
		"jal             0x800A51E8                 \n"
		"addiu           $a0,$a0,332                            \n"
		"lw              $a2,24($sp)                            \n"
		"lui             $t7,%hi(data_809E9F6C)                 \n"
		"addiu           $t7,$t7,%lo(data_809E9F6C)             \n"
		"lh              $t6,410($a2)                           \n"
		"sw              $t7,400($a2)                           \n"
		"sh              $t6,406($a2)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
