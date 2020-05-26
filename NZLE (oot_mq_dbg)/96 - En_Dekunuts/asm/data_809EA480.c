void data_809EA480(entity_t* en) /* 1 internal, 2 external, 28 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_809EA480: \n"
	);
	asm(
		"addiu           $sp,$sp,-32                            \n"
		"or              $a2,$a0,$zero                          \n"
		"sw              $ra,20($sp)                            \n"
		"addiu           $a0,$a0,332                            \n"
		"sw              $a1,36($sp)                            \n"
		"sw              $a0,28($sp)                            \n"
		"jal             0x800A49FC                 \n"
		"sw              $a2,32($sp)                            \n"
		"lw              $a0,28($sp)                            \n"
		"jal             0x800A56C8                 \n"
		"addiu           $a1,$zero,0                            \n"
		"beq             $v0,$zero,.L000060                     \n"
		"lw              $a2,32($sp)                            \n"
		"lh              $v0,406($a2)                           \n"
		"beq             $v0,$zero,.L000060                     \n"
		"addiu           $t6,$v0,-1                             \n"
		"sh              $t6,406($a2)                           \n"
		".L000060:                                              \n"
		"lh              $t7,406($a2)                           \n"
		"bnel            $t7,$zero,.L000061                     \n"
		"lw              $ra,20($sp)                            \n"
		"jal             func_809E9920                          \n"
		"or              $a0,$a2,$zero                          \n"
		"lw              $ra,20($sp)                            \n"
		".L000061:                                              \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
