void data_80ABBB0C(entity_t* en, z64_global_t* gl) /* 0 internal, 1 external, 10 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBB0C: \n"
	);
	asm(
		"addiu           $sp,$sp,-24                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $ra,20($sp)                            \n"
		"or              $a0,$a1,$zero                          \n"
		"jal             0x8005C3AC                 \n"
		"addiu           $a1,$a2,340                            \n"
		"lw              $ra,20($sp)                            \n"
		"addiu           $sp,$sp,24                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
