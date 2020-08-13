#pragma once

#include "globalfuncts.h"
#include <string>

using std::string;

class Dungeon
{

public:
	Dungeon();
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
	string genStairs() const;
	//Generate Inhabitants
	string dungeonFactions() const;
	string dungeonEcology() const;
	string dungeonDifficulty() const;

	// other randomize
	string genPassageWidth() const;
	string genBeyondDoor() const;
	string genChamberExits(int chamberSize) const;
	string genChamberExitType() const;

private:
	//Stocking a Dungeon
	string chamberPurpose;
	string otherCharacteristics;

	//Area Map
	//TODO


};
