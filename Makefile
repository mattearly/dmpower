TARGET = dmpower
DEL = rm -vf

all:
	+$(MAKE) -C src

run:
	+$(MAKE) -C src
	./dmpower

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src clean 


# This is the main makefile that calls the makefile in the src directory
### Valid commands
# 'make' to build or update
# 'make run' to build or update and run
# 'make clean' to start fresh

