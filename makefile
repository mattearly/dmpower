#makefile for DM-Power-Final
#MACROS
OBJS = main.o campaign.o characters.o races.o gear.o globalfuncts.o reward_gen.o name_gen.o
EXES = dmpower
FLAGS = -c -std=c++11
CC = g++


all: $(EXES)

clean: 
	rm $(OBJS) $(EXES)

dmpower: $(OBJS)
	$(CC) $(OBJS) -o dmpower

main.o: main.cpp globalfuncts.h
	$(CC) $(FLAGS) main.cpp

campaign.o: campaign.cpp campaign.h
	$(CC) $(FLAGS) campaign.cpp

characters.o: characters.cpp characters.h
	$(CC) $(FLAGS) characters.cpp

races.o: races.cpp races.h
	$(CC) $(FLAGS) races.cpp

gear.o: gear.cpp gear.h
	$(CC) $(FLAGS) gear.cpp

globalfuncts.o: globalfuncts.cpp globalfuncts.h
	$(CC) $(FLAGS) globalfuncts.cpp

reward_gen.o: reward_gen.cpp reward_gen.h
	$(CC) $(FLAGS) reward_gen.cpp

name_gen.o: name_gen.cpp name_gen.h
	$(CC) $(FLAGS) name_gen.cpp