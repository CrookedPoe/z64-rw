ACTOR = z_obj_tsubo.zovl
OBJECT = object_tsubo.zobj

default: all copy

all:
	@$(MAKE) -C object
	@$(MAKE) -C actor

copy:
	cp object/$(OBJECT) $(OBJECT)
	cp actor/$(ACTOR) Obj_Tsubo.zovl

clean:
	@$(MAKE) -C object clean
	@$(MAKE) -C actor clean
	rm -fv Obj_Tsubo.zovl $(OBJECT)