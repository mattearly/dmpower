//
//  rand_dungeon.h
//  DM-Power
//
//  Created by Matthew Early on 6/22/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#ifndef __RAND_DUNGEON_H
#define __RAND_DUNGEON_H

#include "./../global functs.h"

class Dungeon {

public:
	//building a dungeon
	//Location
	string determineLocation() const;
	string determineExoticLocation() const;

	
	
	//Generate Creator
	string dungeonCreator() const;
	string dungeonCult() const;
	string dungeonCreatorClass() const;
	string dungeonPurpose() const;
	string dungeonHistory() const;
	//Generate Areas
    string genStartingArea() const;
	string genPassage() const;
	string genDoor() const;  
	string genChamber() const;
	string genStair() const;
	//Generate Inhabitants
	string dungeonFactions() const;
	string dungeonEcology() const;
	string dungeonDifficulty() const;
	//
	
	
	//Stocking a Dugneon
	string chamberPurpose

private:

    
};

#endif //__RAND_DUNGEON_H