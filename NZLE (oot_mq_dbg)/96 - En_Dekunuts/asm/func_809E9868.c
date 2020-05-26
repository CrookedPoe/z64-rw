void func_809E9868(entity_t* en) /* 0 internal, 2 external, 19 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E9868: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"sw              $a0,24($sp)                            \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,1240                           \n"
		"addiu           $a0,$a0,332                            \n"
		"jal             0x800A5240                 \n"
		"lui             $a2,0xC0A0                             \n"
		"lw              $a0,24($sp)                            \n"
		"jal             0x8002F828                 \n"
		"addiu           $a1,$zero,14461                        \n"
		"lw              $t7,24($sp)                            \n"
		"lui             $t6,%hi(data_809EA0C4)                 \n"
		"addiu           $t6,$t6,%lo(data_809EA0C4)             \n"
		"sw              $t6,400($t7)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
