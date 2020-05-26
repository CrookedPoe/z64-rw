void func_809E96FC(entity_t* en) /* 0 internal, 3 external, 29 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_809E96FC: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a1,0x0600                             \n"
		"addiu           $a1,$a1,3356                           \n"
		"addiu           $a0,$a0,332                            \n"
		"jal             0x800A529C                 \n"
		"addiu           $a2,$zero,0                            \n"
		"addiu           $a0,$zero,100                          \n"
		"jal             0x80077D90                 \n"
		"addiu           $a1,$zero,50                           \n"
		"addiu           $t6,$zero,5                            \n"
		"sh              $v0,406($s0)                           \n"
		"sh              $t6,778($s0)                           \n"
		"addiu           $a0,$s0,36                             \n"
		"jal             0x80077E40                 \n"
		"addiu           $a1,$s0,8                              \n"
		"lbu             $t7,729($s0)                           \n"
		"lui             $t9,%hi(data_809E9B98)                 \n"
		"addiu           $t9,$t9,%lo(data_809E9B98)             \n"
		"andi            $t8,$t7,0xfffe                         \n"
		"sb              $t8,729($s0)                           \n"
		"sw              $t9,400($s0)                           \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
