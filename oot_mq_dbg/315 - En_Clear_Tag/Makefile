PROGRAM = En_Clear_Tag
OVLOUT = $(PROGRAM).zovl
ADDRESS = 0x80800000
PARTS = $(PROGRAM).o

Z64OVL_LD  = /opt/n64/mips64/include/z64ovl/z64ovl.ld

CC   = mips64-gcc
LD   = mips64-ld
NOVL = novl

CFLAGS = -G 0 -Os --std=gnu99 -mtune=vr4300 -mabi=32 -mips3 -mno-explicit-relocs -mno-memcpy
LDFLAGS = -T $(Z64OVL_LD) --emit-relocs
NOVLFLAGS = -v -c -A $(ADDRESS) -o $(OVLOUT)

default: $(PROGRAM).ovl

$(PROGRAM).ovl: $(PARTS)
	$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf

clean:
	rm -fv $(PROGRAM).elf $(OVLOUT) $(PARTS)
