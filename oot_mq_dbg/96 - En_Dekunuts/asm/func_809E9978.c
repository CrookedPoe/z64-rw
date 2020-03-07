void func_809E9978(entity_t* en) /* 0 internal, 1 external, 25 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E9978: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,4132                           \n"
		"sw              $a2,24($sp)                            \n"
		"jal             0x800A52F8                 \n"
		"addiu           $a0,$a0,332                            \n"
		"lw              $a2,24($sp)                            \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $t6,$zero,3                            \n"
		"lbu             $v0,405($a2)                           \n"
		"lui             $t8,%hi(data_809EA480)                 \n"
		"sh              $t6,406($a2)                           \n"
		"beq             $v0,$zero,.L000007                     \n"
		"swc1            $f4,104($a2)                           \n"
		"addiu           $t7,$v0,-1                             \n"
		"sb              $t7,405($a2)                           \n"
		".L000007:                                              \n"
		"addiu           $t8,$t8,%lo(data_809EA480)             \n"
		"sw              $t8,400($a2)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
