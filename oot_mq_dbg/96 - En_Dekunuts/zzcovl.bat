@echo off
SET ovlin=En_Dekunuts-nzle
SET vstart=809E9560
SET init=809EAB30
SET game=OOT_DEBUG

START zzcovl %ovlin%.zovl --entry_point=%vstart% --actor_init=%init% --define=%game% > %ovlin%_zzcovl.c