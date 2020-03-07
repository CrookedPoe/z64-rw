void func_809E9800(entity_t* en) /* 0 internal, 1 external, 28 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E9800: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a3,$a0,$zero                          \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,3692                           \n"
		"sw              $a3,24($sp)                            \n"
		"addiu           $a0,$a0,332                            \n"
		"jal             0x800A534C                 \n"
		"lui             $a2,0xC040                             \n"
		"lw              $a3,24($sp)                            \n"
		"lui             $t6,%hi(data_809E9F6C)                 \n"
		"addiu           $t6,$t6,%lo(data_809E9F6C)             \n"
		"lw              $t7,400($a3)                           \n"
		"lui             $t0,%hi(data_809E9E80)                 \n"
		"addiu           $t9,$zero,1                            \n"
		"bne             $t6,$t7,.L000005                       \n"
		"addiu           $t0,$t0,%lo(data_809E9E80)             \n"
		"addiu           $t8,$zero,4098                         \n"
		"beq             $zero,$zero,.L000006                   \n"
		"sh              $t8,406($a3)                           \n"
		".L000005:                                              \n"
		"sh              $t9,406($a3)                           \n"
		".L000006:                                              \n"
		"sw              $t0,400($a3)                           \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
