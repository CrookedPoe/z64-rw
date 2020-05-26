void data_809EA1D8(entity_t* en) /* 1 internal, 2 external, 27 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_809EA1D8: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $s0,24($sp)                            \n"
		"or              $s0,$a0,$zero                          \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $a1,36($sp)                            \n"
		"jal             0x800A49FC                 \n"
		"addiu           $a0,$a0,332                            \n"
		"beq             $v0,$zero,.L000045                     \n"
		"ori             $at,$zero,0x8000                       \n"
		"lh              $t6,138($s0)                           \n"
		"addiu           $t8,$zero,3                            \n"
		"sb              $t8,405($s0)                           \n"
		"addu            $t7,$t6,$at                            \n"
		"sh              $t7,408($s0)                           \n"
		"jal             func_809E9920                          \n"
		"or              $a0,$s0,$zero                          \n"
		".L000045:                                              \n"
		"addiu           $a0,$s0,182                            \n"
		"lh              $a1,138($s0)                           \n"
		"addiu           $a2,$zero,2                            \n"
		"jal             0x800787BC                 \n"
		"addiu           $a3,$zero,3640                         \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
