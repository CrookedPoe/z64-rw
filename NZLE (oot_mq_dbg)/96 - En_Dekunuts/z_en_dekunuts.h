/*** object documentation ***/
#define OBJ_ID 						74 /* object_dekunuts */
#define SKL 						0x06003268 /* Skeleton */
/* Display Lists*/
#define	DL_HEAD 					0x060018C0
#define	DL_RFOOT 					0x060019F8
#define	DL_RTHIGH 					0x06001AA8
#define	DL_TORSO 					0x06001B48
#define	DL_SNOUT 					0x06001BF0
#define	DL_LTHIGH 					0x06001D08
#define	DL_LFOOT 					0x06001DA8
#define	DL_HAT 						0x06001E58
#define	DL_HAT_TIP 					0x06001F50
#define	DL_DEKU_NUT 				0x06002028 /* Used by En_Nutsball */
#define	DL_FLOWER 					0x06002298
/* Animations */
#define ANIM_SHOOT_DEKU_NUT         0x060001C4
#define	ANIM_STUN_SPIN 			    0x06000368
#define	ANIM_BURROW 				0x060004D8
#define	ANIM_DEAD_FALL 			    0x060006B0
#define	ANIM_JUMP 					0x060008C4
#define	ANIM_LOOK_AROUND 		    0x06000AF0
#define	ANIM_RISE 					0x06000D1C
#define	ANIM_IDLE 					0x06000E6C
#define	ANIM_FLINCHING 			    0x06001024
#define	ANIM_FLAIL 					0x06003650
/* Skeleton Limbs */
#define	L_ROOT                      1
#define	L_BLANK0                    2
#define	L_BLANK1                    3
#define	L_HEAD  					4
#define	L_BLANK2  					5
#define	L_BLANK3					6
#define	L_SNOUT						7
#define	L_BLANK4					8
#define	L_BLANK5					9
#define	L_HAT						10
#define	L_BLANK6					11
#define	L_BLANK7					12
#define	L_HAT_TOP					13
#define	L_TORSO						14
#define	L_BLANK8					15
#define	L_BLANK9					16
#define	L_BLANKA					17
#define	L_LFOOT						18
#define	L_LTHIGH					19
#define	L_BLANKB					20
#define	L_BLANKC					21
#define	L_BLANKD					22
#define	L_RFOOT						23
#define	L_RTHIGH					24
#define LIMB_TOTAL 					24

/* Sound Effects */
#define  SOUND_SLASHED       NA_SE_EN_NUTS_CUTBODY    /* killed */
#define  SOUND_EMERGE        NA_SE_EN_NUTS_UP         /* emerging sound */
#define  SOUND_BURROW        NA_SE_EN_NUTS_DOWN       /* burrowing sound */
#define  SOUND_SPIT          NA_SE_EN_NUTS_THROW      /* spit deku nut */
#define  SOUND_WALK          NA_SE_EN_NUTS_WALK       /* walk sound */
#define  SOUND_DAMAGE        NA_SE_EN_NUTS_DAMAGE     /* hurt by Link */
#define  SOUND_KILLED        NA_SE_EN_NUTS_DEAD       /* last hit */
#define  SOUND_FAINT         NA_SE_EN_NUTS_FAINT      /* TODO describe this better */
#define  SOUND_STUN          NA_SE_EN_GOMA_JR_FREEZE  /* stunned by thrown deku nut */

/* Variables */
#define VAR_FLOWER          0x000A /* Usually a single flower pad is spawned when the actor uses this variable. */
