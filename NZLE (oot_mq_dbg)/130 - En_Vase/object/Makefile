PROGRAM = object_vase
OBJOUT = $(PROGRAM).zobj
ADDRESS = 0x06000000
OBJCOPY = mips64-objcopy
OBJDUMP = mips64-objdump
PARTS = $(PROGRAM).o

CC   = mips64-gcc
LD   = mips64-ld

CFLAGS = -G 0 -Os --std=gnu99 -mtune=vr4300 -mabi=32 -mips3 -mno-check-zero-division -mno-explicit-relocs -mno-memcpy
LDFLAGS = -L$(Z64OVL_LD) -T z64ovl.ld --emit-relocs

# Default make
default: clean entry $(PROGRAM).obj map

$(PROGRAM).obj: $(PARTS)
	$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	$(OBJCOPY) -R .MIPS.abiflags -O binary $(PROGRAM).elf $(OBJOUT)

# Create `entry.ld`
entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld

map:
	@echo -n "" > map.h
	@$(OBJDUMP) -t $(PROGRAM).elf | grep " dl_" > map.txt
	grep " dl_" map.txt | while read -r line ; do \
		echo -n "#define " >> map.h; \
		head -1 map.txt | grep " dl_" | rev | cut -d" " -f1 -z | rev >> map.h; \
		echo -n " 0x" >> map.h; \
		head -1 map.txt | grep " dl_" | head -c 8 >> map.h; \
		echo "" >> map.h; \
		tail -n +2 map.txt > map1.txt; \
		mv map1.txt map.txt; \
	done
	rm -fv map.txt map1.txt

# Remove compilation parts and some cleanup.
clean:
	rm -fv $(PROGRAM).elf $(OBJOUT) $(PARTS) entry.ld map.h