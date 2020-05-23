ACTOR = z_en_vase.zovl
OBJECT = object_vase.zobj

default: all copy

all:
	@$(MAKE) -C object
	@$(MAKE) -C actor

copy:
	cp object/$(OBJECT) $(OBJECT)
	cp actor/$(ACTOR) En_Vase.zovl

clean:
	@$(MAKE) -C object clean
	@$(MAKE) -C actor clean
	rm -fv En_Vase.zovl $(OBJECT)