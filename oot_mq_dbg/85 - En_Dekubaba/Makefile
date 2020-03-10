PROGRAM = En_Dekubaba-nzle
OVLOUT = $(PROGRAM).zovl
ADDRESS = 0x80800000
INIT = 0x809E8EAC
GAME = OOT_DEBUG
PARTS = $(PROGRAM).o

Z64OVL_LD  = /opt/n64/mips64/include/z64ovl/z64ovl.ld

CC   = mips64-gcc
LD   = mips64-ld
NOVL = novl
ZZCOVL = C:/Z64/tools/zzcovl.exe

CFLAGS = -G 0 -Os --std=gnu99 -mtune=vr4300 -mabi=32 -mips3 -mno-explicit-relocs -mno-memcpy
LDFLAGS = -T $(Z64OVL_LD) --emit-relocs
NOVLFLAGS = -v -c -A $(ADDRESS) -o $(OVLOUT)
ZZCOVLFLAGS = $(PROGRAM).zovl --entry_point=$(ADDRESS) --actor_init=$(INIT) --define=$(GAME) > $(PROGRAM).c

default: $(PROGRAM).ovl

$(PROGRAM).ovl: $(PARTS)
	$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf

covl:
	$(ZZCOVL) $(ZZCOVLFLAGS)

clean:
	rm -fv $(PROGRAM).elf $(OVLOUT) $(PARTS)

copy:
	cp $(PROGRAM).zovl "C:/Z64/mg_dbg_zzrtl/actor/130 - En_Vase/actor.zovl"

build:
	start "C:/Z64/tools/zzrtl.exe" --nowaiting "C:/Z64/mg_dbg_zzrtl/oot_build.rtl"

routine:
	make clean
	make
	make copy
	make build
