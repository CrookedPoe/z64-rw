void data_80ABBD74(entity_t* en, z64_global_t* gl) /* 0 internal, 6 external, 73 lines */
{
	asm(
		".set noat        \n"
		".set noreorder   \n"
		".Ldata_80ABBD74: \n"
	);
	asm(
		"addiu           $sp,$sp,-64                            \n"
		"sw              $ra,44($sp)                            \n"
		"sw              $s2,40($sp)                            \n"
		"sw              $s1,36($sp)                            \n"
		"sw              $s0,32($sp)                            \n"
		"lw              $v0,7236($a1)                          \n"
		"lui             $at,0x3000                             \n"
		"ori             $at,$at,0xc0                           \n"
		"lw              $t6,1660($v0)                          \n"
		"or              $s0,$a0,$zero                          \n"
		"or              $s2,$a1,$zero                          \n"
		"and             $t7,$t6,$at                            \n"
		"beql            $t7,$zero,.L000012                     \n"
		"lw              $t9,332($s0)                           \n"
		"lw              $t9,332($a0)                           \n"
		"lui             $t8,%hi(data_80ABBB34)                 \n"
		"addiu           $t8,$t8,%lo(data_80ABBB34)             \n"
		"bnel            $t8,$t9,.L000013                       \n"
		"lw              $ra,44($sp)                            \n"
		"lw              $t9,332($s0)                           \n"
		".L000012:                                              \n"
		"or              $a0,$s0,$zero                          \n"
		"or              $a1,$s2,$zero                          \n"
		"jalr            $t9                                    \n"
		"nop                                                    \n"
		"jal             0x8002D8E0                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lui             $v0,%hi(data_80ABBFC0)                 \n"
		"addiu           $v0,$v0,%lo(data_80ABBFC0)             \n"
		"lh              $t0,32($v0)                            \n"
		"lh              $t1,34($v0)                            \n"
		"addiu           $t2,$zero,5                            \n"
		"mtc1            $t0,$f4                                \n"
		"mtc1            $t1,$f6                                \n"
		"sw              $t2,20($sp)                            \n"
		"cvt.s.w         $f4,$f4                                \n"
		"or              $a0,$s2,$zero                          \n"
		"or              $a1,$s0,$zero                          \n"
		"lui             $a2,0x4120                             \n"
		"cvt.s.w         $f8,$f6                                \n"
		"mfc1            $a3,$f4                                \n"
		"jal             0x8002E4B4                 \n"
		"swc1            $f8,16($sp)                            \n"
		"addiu           $s1,$s0,340                            \n"
		"or              $a1,$s1,$zero                          \n"
		"jal             0x800626DC                 \n"
		"or              $a0,$s0,$zero                          \n"
		"lw              $t3,4($s0)                             \n"
		"lui             $at,0x0100                             \n"
		"or              $a0,$s2,$zero                          \n"
		"or              $t4,$t3,$at                            \n"
		"lui             $at,0x0001                             \n"
		"ori             $at,$at,0x1e60                         \n"
		"sw              $t4,4($s0)                             \n"
		"addu            $a1,$s2,$at                            \n"
		"sw              $a1,48($sp)                            \n"
		"jal             0x8005D79C                 \n"
		"or              $a2,$s1,$zero                          \n"
		"or              $a0,$s2,$zero                          \n"
		"lw              $a1,48($sp)                            \n"
		"jal             0x8005D9F4                 \n"
		"or              $a2,$s1,$zero                          \n"
		"or              $a0,$s2,$zero                          \n"
		"lw              $a1,48($sp)                            \n"
		"jal             0x8005DC4C                 \n"
		"or              $a2,$s1,$zero                          \n"
		"lw              $ra,44($sp)                            \n"
		".L000013:                                              \n"
		"lw              $s0,32($sp)                            \n"
		"lw              $s1,36($sp)                            \n"
		"lw              $s2,40($sp)                            \n"
		"jr              $ra                                    \n"
		"addiu           $sp,$sp,64                             \n"
	);
}
