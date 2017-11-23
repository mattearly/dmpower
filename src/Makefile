#makefile for binaries in source folder
#the makefile in the folder above this calls this one
#do not call this one by itself

TARGET = dmpower
CC = g++
CFLAGS = -std=c++11 -O1
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
DEL = rm -vf


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o ../$@ 


clean:
	$(DEL) $(OBJS)


### compile
.cpp.o:
	$(CC) $(SOCFLAGS) $< -o $@



#### old style of compile before the all-in-one version	
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
