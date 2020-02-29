typedef struct{
  z64_actor_t actor; /* Base Actor */
} z_en_tana_t;

void draw_80B17FC4(z_en_tana_t *en, z64_global_t *gl)
{
  Gfx *opa = &ZQDL(gl, poly_opa);
  Mtx *m;
  z64_gfx_t *gfx = (gl->common).gfx_ctxt;
  //Gfx aGStack24 [3];

  //external_func_800C6AC4(aGStack24, gfx, "../z_en_tana.c", __LINE__);
  external_func_80093D18(gfx);
  m = matrix_alloc(gfx , "../z_en_tana.c"/*, __LINE__*/);
  gSPMatrix(opa->p++, m, G_MTX_LOAD)
  gSPDisplayList(opa->p++, data_80B18214[(en->actor).variable])
  //external_func_800C6B54(aGStack24, gfx, "../z_en_tana.c", __LINE__);
}

void draw_80B1809C(z_en_tana_t *en, z64_global_t *gl)
{
  Gfx *opa = &ZQDL(gl, poly_opa);
  Mtx *m;
  z64_gfx_t *gfx = (gl->common).gfx_ctxt;
  //Gfx aGStack24 [3];

  //external_func_800C6AC4(aGStack24, gfx, "../z_en_tana.c", __LINE__);
  external_func_80093D18(gfx);
  gSPSegment(opa->p++, G_MWO_SEGMENT_8, zh_seg2ram(data_80B18220[(en->actor).variable]));
  m = matrix_alloc(gfx , "../z_en_tana.c"/*, __LINE__*/);
  gSPMatrix(opa->p++, m, G_MTX_LOAD)
  gSPDisplayList(opa->p++, data_80B18214[(en->actor).variable])
  //external_func_800C6B54(aGStack24, gfx, "../z_en_tana.c", __LINE__);
}

void init_80B17F30(z_en_tana_t *en, z64_global_t *gl)
{
  //debug_message(&DAT_80b18240,(&PTR_DAT_80b18200)[(en->actor).variable]);
  actor_set_scale(en, 1.0f);
  (en->actor).flags &= 0xFFFFFFFE;
  (en->actor).draw_proc = (void*)data_80B18208[(en->actor).variable]);
  return;
}

void main_80B17FB8(z_en_tana_t *en, z64_global_t *gl)
{
  return;
}
