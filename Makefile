#makefile

TARGET = dmpower
DEL = rm -vf

all:
	+$(MAKE) -C src

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src clean 

