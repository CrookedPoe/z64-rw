#ifndef Z_EN_TSUBO
#define Z_EN_TSUBO

//#include "../object/map.h"

#define OBJ_GAMEPLAY_DANGEON_KEEP 0x0003
#define SEG_GAMEPLAY_DANGEON_KEEP 0x05000000
#define OBJ_TSUBO                 0x012C
#define DL_POT_GDK                SEG_GAMEPLAY_DANGEON_KEEP + 0x017870
#define DL_SHARD_GDK              SEG_GAMEPLAY_DANGEON_KEEP + 0x017A60
//#define DL_POT                    dl_pot
//#define DL_SHARD                  dl_shard
#define DL_POT                    0x060017C0
#define DL_SHARD                  0x06001960
#define N_SHARDS                  15

#define TSUBO_WHICH(ACTORVAR) ( ( ACTORVAR >> 8 ) & 1 )

#endif