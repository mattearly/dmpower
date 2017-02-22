#makefile

TARGET = dmpower
DEL = rm -vf

all:
	@echo Building all needed objects for dmpower...
	+$(MAKE) -C src

.PHONY: run
run:
	@echo Building all needed objects for dmpower and running...
	+$(MAKE) -C src
	./dmpower

clean:
	@echo Deleting dmpower...
	$(DEL) $(TARGET)
	+$(MAKE) -C src clean 

