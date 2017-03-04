# makefile for binaries in source folder
# the makefile in the folder ^above^ this calls this one
# do not call this one by itself

DEL = rm -f
TARGET = ../dmpower
CC = g++
CFLAGS = -std=c++11
SINGLE_CFLAGS = -c -g -Wall -std=c++11
SDL2 = -lSDL2main -lSDL2
SDL2IMG = -lSDL2_image
SDL2TTF = -lSDL2_ttf
SDL2AUDIO = -lSDL2_mixer
OBJS = sdl_graphics.o \
texture.o \
campaign.o \
characters.o \
main.o \
gear.o \
gen_dungeon.o \
gen_encounter.o \
gen_name.o \
gen_reward.o \
gen_insult.o \
globalfuncts.o \
races.o \
scene_main.o \
scene_newcharacter.o \
scene_encounters.o \
scene_export.o \
scene_rewards.o \
scene_tools.o
SRC = campaign.cpp \
characters.cpp \
colors.cpp \
gear.cpp \
gen_dungeon.cpp \
gen_encounter.cpp \
gen_name.cpp \
gen_reward.cpp \
gen_insult.cpp \
globalfuncts.cpp \
races.cpp \
sdl_graphics.cpp \
texture.cpp \
scene_main.cpp \
scene_newcharacter.cpp \
scene_encountaers.cpp \
scene_export.cpp \
scene_rewards.cpp \
scene_tools.cpp


$(TARGET): $(OBJS)
	@echo Building dmpower...
	$(CC) $(OBJS) $(SDL2) $(SDL2IMG) $(SDL2TTF) $(SDL2AUDIO) $(CFLAGS) -o $@
	@echo Build Complete. Use ./dmpower in your terminal to run it.

clean:
	@echo Deleting objects...
	$(DEL) $(OBJS)


# Compile individual files: all in one version

.cpp.o:
	@echo Building $@ from $< ...
	$(CC) $< $(SINGLE_CFLAGS) -o $@

# main.o: main.cpp
# 	$(CC) $(SOCFLAGS) main.cpp -o $@
# campaign.o: campaign.cpp campaign.h
# 	$(CC) $(SOCFLAGS) campaign.cpp -o $@
# characters.o: characters.cpp characters.h
# 	$(CC) $(SOCFLAGS) characters.cpp -o $@
# gear.o: gear.cpp gear.h
# 	$(CC) $(SOCFLAGS) gear.cpp -o $@
# gen_dungeon.o: gen_dungeon.cpp gen_dungeon.h
# 	$(CC) $(SOCFLAGS) gen_dungeon.cpp -o $@
# gen_encounter.o: gen_encounter.cpp gen_encounter.h
# 	$(CC) $(SOCFLAGS) gen_encounter.cpp -o $@
# gen_name.o: gen_name.cpp gen_name.h
# 	$(CC) $(SOCFLAGS) gen_name.cpp -o $@
# gen_reward.o: gen_reward.cpp gen_reward.h
# 	$(CC) $(SOCFLAGS) gen_reward.cpp -o $@
# gen_insult.o: gen_insult.cpp gen_insult.h
# 	$(CC) $(SOCFLAGS) gen_insult.cpp -o $@
# globalfuncts.o: globalfuncts.cpp globalfuncts.h
# 	$(CC) $(SOCFLAGS) globalfuncts.cpp -o $@
# races.o: races.cpp races.h
# 	$(CC) $(SOCFLAGS) races.cpp -o $@
