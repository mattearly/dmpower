#makefile

TARGET = dmpower
CC = g++
CFLAGS = -std=c++11 -Wall -O2
SOCFLAGS = -c -std=c++11 -Wall -O2
OBJS = campaign.o \
characters.o \
main.o \
gear.o \
gen_dungeon.o \
gen_encounter.o \
gen_name.o \
gen_reward.o \
gen_insult.o \
globalfuncts.o \
races.o
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
races.cpp
DEL = rm -v

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
clean:
	$(DEL) $(OBJS) $(TARGET) *.stackdump *.exe *.out

###compile:

main.o: main.cpp
	$(CC) $(SOCFLAGS) main.cpp
campaign.o: campaign.cpp campaign.h
	$(CC) $(SOCFLAGS) campaign.cpp
characters.o: characters.cpp characters.h
	$(CC) $(SOCFLAGS) characters.cpp
gear.o: gear.cpp gear.h
	$(CC) $(SOCFLAGS) gear.cpp
gen_dungeon.o: gen_dungeon.cpp gen_dungeon.h
	$(CC) $(SOCFLAGS) gen_dungeon.cpp
gen_encounter.o: gen_encounter.cpp gen_encounter.h
	$(CC) $(SOCFLAGS) gen_encounter.cpp
gen_name.o: gen_name.cpp gen_name.h
	$(CC) $(SOCFLAGS) gen_name.cpp
gen_reward.o: gen_reward.cpp gen_reward.h
	$(CC) $(SOCFLAGS) gen_reward.cpp
gen_insult.o: gen_insult.cpp gen_insult.h
	$(CC) $(SOCFLAGS) gen_insult.cpp
globalfuncts.o: globalfuncts.cpp globalfuncts.h
	$(CC) $(SOCFLAGS) globalfuncts.cpp
races.o: races.cpp races.h
	$(CC) $(SOCFLAGS) races.cpp
