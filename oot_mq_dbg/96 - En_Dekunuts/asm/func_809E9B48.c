void func_809E9B48(entity_t* en) /* 0 internal, 2 external, 20 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E9B48: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,1712                           \n"
		"sw              $a2,24($sp)                            \n"
		"jal             0x800A51E8                 \n"
		"addiu           $a0,$a0,332                            \n"
		"lw              $a0,24($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"lui             $t6,%hi(data_809EA5B0)                 \n"
		"addiu           $t6,$t6,%lo(data_809EA5B0)             \n"
		"addiu           $a1,$zero,14465                        \n"
		"sw              $t6,400($a0)                           \n"
		"jal             0x8002F828                 \n"
		"swc1            $f4,104($a0)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
