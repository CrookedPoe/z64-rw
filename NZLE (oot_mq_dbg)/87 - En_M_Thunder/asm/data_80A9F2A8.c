void data_80A9F2A8(entity_t* en, z64_global_t* gl) /* 1 internal, 3 external, 28 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80A9F2A8: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"sw              $s0,24($sp)                            \n"
		"sw              $a0,32($sp)                            \n"
		"lbu             $t7,458($a0)                           \n"
		"or              $s0,$a1,$zero                          \n"
		"beql            $t7,$zero,.L000007                     \n"
		"lw              $a1,32($sp)                            \n"
		"jal             0x800876C8                 \n"
		"or              $a0,$a1,$zero                          \n"
		"lw              $a1,32($sp)                            \n"
		".L000007:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             0x8005C3AC                 \n"
		"addiu           $a1,$a1,332                            \n"
		"or              $a0,$s0,$zero                          \n"
		"jal             func_80A9F314                          \n"
		"addiu           $a1,$zero,0                            \n"
		"lw              $t8,32($sp)                            \n"
		"or              $a0,$s0,$zero                          \n"
		"addiu           $a1,$s0,1960                           \n"
		"jal             0x8007A7C4                 \n"
		"lw              $a2,408($t8)                           \n"
		"lw              $ra,28($sp)                            \n"
		"lw              $s0,24($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
