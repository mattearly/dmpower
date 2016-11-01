#makefile

TARGET = dmpower
DEL = rm -vf

all:
	+$(MAKE) -C Source

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C Source clean 

