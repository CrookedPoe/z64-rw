void func_80A9F314(entity_t* en, float a1) /* 0 internal, 1 external, 15 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80A9F314: \n"
	);
	asm(
		"mtc1            $a1,$f12                               \n"
		"mtc1            $zero,$f4                              \n"
		"addiu           $sp,$sp,-32                            \n"
		"sw              $ra,28($sp)                            \n"
		"lui             $a2,0x4454                             \n"
		"lui             $a3,0x3E4C                             \n"
		"mfc1            $a1,$f12                               \n"
		"ori             $a3,$a3,0xcccd                         \n"
		"ori             $a2,$a2,0x8000                         \n"
		"jal             0x800773A8                 \n"
		"swc1            $f4,16($sp)                            \n"
		"lw              $ra,28($sp)                            \n"
		"addiu           $sp,$sp,32                             \n"
		"jr              $ra                                    \n"
		"nop                                                    \n"
	);
}
