void func_809E98B4(void)
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E98B4: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,2244                           \n"
		"sw              $a3,24($sp)                            \n"
		"addiu           $a0,$a0,332                            \n"
		"jal             0x800A5240                 \n"
		"lui             $a2,0xC040                             \n"
		"lw              $a0,24($sp)                            \n"
		"addiu           $t6,$zero,37                           \n"
		"addiu           $t7,$zero,50                           \n"
		"addiu           $a1,$zero,14464                        \n"
		"sh              $t6,778($a0)                           \n"
		"jal             0x8002F828                 \n"
		"sb              $t7,174($a0)                           \n"
		"lw              $a3,24($sp)                            \n"
		"lui             $t0,%hi(data_809EA1D8)                 \n"
		"addiu           $t0,$t0,%lo(data_809EA1D8)             \n"
		"lbu             $t8,729($a3)                           \n"
		"sw              $t0,400($a3)                           \n"
		"andi            $t9,$t8,0xfffe                         \n"
		"sb              $t9,729($a3)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
