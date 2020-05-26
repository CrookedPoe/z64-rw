void data_809E96C8(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 14 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_809E96C8: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"sw              $ra,20($sp)                            \n"
		"lh              $t6,28($a0)                            \n"
		"or              $a2,$a0,$zero                          \n"
		"addiu           $at,$zero,10                           \n"
		"beq             $t6,$at,.L000004                       \n"
		"or              $a0,$a1,$zero                          \n"
		"jal             0x8005C3AC                 \n"
		"addiu           $a1,$a2,712                            \n"
		".L000004:                                              \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
