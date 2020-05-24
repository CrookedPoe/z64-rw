PROGRAM = z_en_light
OVLOUT = En_Light.zovl
ADDRESS = 0x80A9DB40
OBJDUMP = mips64-objdump
PARTS = $(PROGRAM).o

CC   = mips64-gcc
LD   = mips64-ld
NOVL = novl

CFLAGS = -G 0 -Os --std=gnu99 -mtune=vr4300 -mabi=32 -mips3 -mno-explicit-relocs -mno-memcpy
LDFLAGS = -L$(Z64OVL_LD) -T z64ovl.ld --emit-relocs
NOVLFLAGS = -v -c -A $(ADDRESS) -o $(OVLOUT)

default: clean entry $(PROGRAM).ovl symbols

$(PROGRAM).ovl: $(PARTS)
	$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf

entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld

symbols:
	@$(OBJDUMP) -t $(PROGRAM).elf > symbols.txt

clean:
	rm -fv $(PROGRAM).elf $(OVLOUT) $(PARTS) entry.ld