void func_80A9EFE0(entity_t* en, z64_actorfunc_t* state) /* 0 internal, 0 external, 2 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Lfunc_80A9EFE0: \n"
	);
	asm(
		"jr              $ra                                    \n"
		"sw              $a1,448($a0)                           \n"
	);
}
