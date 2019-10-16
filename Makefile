TARGET = dmpower
RUN = ./$(TARGET)
SRC_DIR = src
BUILD_DIR = bin
CFLAGS = -std=c++11 -O3 -Wall -Wextra
LOADLIBS = -lboost_filesystem -lboost_system
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

default:
	+$(MAKE) $(TARGET)

all:
	+$(MAKE) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS) -o $@ $(LOADLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

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

.PHONY: debug
debug: CFLAGS += -g
debug: $(TARGET)

.PHONY: help
help:
	$(info `make`         - builds/updates everything, is ready to run with `$(RUN)` after completion")
	$(info `make clean`   - removes object file folder and executable)
	$(info `make rebuild` - removes object file folder and executable and then builds and updates everything)
	$(info `make debug`   - builds/updates with -g. Use `make clean` first if a previous build was made)
	$(info `make run`     - builds/updates everything, runs immediately")
