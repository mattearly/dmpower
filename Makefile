TARGET = dmpower
RUN = ./dmpower
SRC_DIR = src
BUILD_DIR = bin
CFLAGS = -std=c++11 -O2 -Wall -Wextra
OBJFLAGS = -fsanitize=leak -c
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(addprefix $(BUILD_DIR)/, $(SOURCES:$(SRC_DIR)/%.cpp=%.o))

default: 
	@mkdir -p bin
	+$(MAKE) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $(OBJFLAGS) $< -o $@ 

.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: rebuild
rebuild:
	+$(MAKE) clean
	+$(MAKE) default

.PHONY: run
run: 
	+$(MAKE) default
	$(RUN)

.PHONY: help
help:
	@echo \'make\' - builds/updates everything, is ready to run with \'./dmpower\' after completion
	@echo \'make clean\' - removes object file folder and executable
	@echo \'make rebuild\' - removes object file folder and executable and then builds and updates everything
	@echo \'make run\' - builds/updates everything, runs immediately 
