#include <z64ovl/n64/gbi.h>
#include "textures.h"
#include "geometry.h"

Gfx dl_pot[] =
{
  gsDPPipeSync(),
  gsDPSetTextureLUT(G_TT_NONE),
  gsSPTexture(qu016(0.999985), qu016(0.999985), 0, G_TX_RENDERTILE, G_ON),
  gsDPLoadTextureBlock(&timg_rgba16_000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
  gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
  gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA), G_RM_AA_ZB_OPA_SURF2),
  gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
  gsSPSetGeometryMode(G_CULL_BACK | G_FOG | G_LIGHTING),
  gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
  gsSPVertex(&v_001400, sizeof(v_001400), 0),
  gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
  gsSP2Triangles(5, 6, 7, 0, 8, 9, 2, 0),
  gsSP2Triangles(1, 0, 10, 0, 1, 10, 11, 0),
  gsSP2Triangles(12, 13, 9, 0, 12, 9, 8, 0),
  gsSP2Triangles(14, 15, 4, 0, 14, 4, 3, 0),
  gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
  gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
  gsSP1Triangle(28, 29, 30, 0),
  gsSPVertex(&v_0015F0, sizeof(v_0015F0), 0),
  gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
  gsSP2Triangles(6, 7, 4, 0, 6, 4, 3, 0),
  gsSP2Triangles(8, 9, 10, 0, 11, 12, 5, 0),
  gsSP2Triangles(13, 14, 12, 0, 13, 12, 11, 0),
  gsSP2Triangles(15, 16, 17, 0, 18, 19, 5, 0),
  gsSP2Triangles(19, 18, 20, 0, 19, 20, 21, 0),
  gsSP1Triangle(22, 23, 24, 0),
  gsDPPipeSync(),
  gsDPLoadTextureBlock(&timg_rgba16_001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
  gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
  gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA), G_RM_AA_ZB_TEX_EDGE2),
  gsSPVertex(v_001780, sizeof(v_001780), 0),
  gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
  gsSPEndDisplayList()
};

Gfx dl_shard[] =
{
  gsDPPipeSync(),
  gsDPSetTextureLUT(G_TT_NONE),
  gsSPTexture(qu016(0.999985), qu016(0.999985), 0, G_TX_RENDERTILE, G_ON),
  gsDPLoadTextureBlock(&timg_rgba16_001200, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
  gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
  gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA), G_RM_AA_ZB_TEX_EDGE2),
  gsSPClearGeometryMode(G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
  gsSPSetGeometryMode(G_CULL_BACK | G_FOG),
  gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
  gsSPVertex(&v_001930, sizeof(v_001930), 0),
  gsSP1Triangle(0, 1, 2, 0),
  gsSPEndDisplayList()
};