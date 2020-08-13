#include "gen_dungeon.h"
#include "globalfuncts.h"

Dungeon::Dungeon()
{
	chamberPurpose = "na";
	otherCharacteristics = "na";
}

// string determineLocation() const;
// string determineExoticLocation() const;

//Generate Creator
// string dungeonCreator() const;
// string dungeonCult() const;
// string dungeonCreatorClass() const;
// string dungeonPurpose() const;
// string dungeonHistory() const;
//Generate Areas

string Dungeon::genStartingArea() const
{
	std::string result = "na";
	switch (rolld10(mgen))
	{
	case 1:
		result = "Square, 20 x 20ft.; passage on each wall";
		break;
	case 2:
		result = "Square, 20 x 20f.; door on two walls, passage in third wall";
		break;
	case 3:
		result = "Square, 40 x 40 ft.; door on three walls";
		break;
	case 4:
		result = "Rectangle, 80 x 20 ft.; with row of pillars down the middle; two passages leading from each long wall, doors on each short wall";
		break;
	case 5:
		result = "Rectangle, 20 x 40 ft.; passage on each wall";
		break;
	case 6:
		result = "Circle, 40 ft. diameter; one passage on each wall";
		break;
	case 7:
		result = "Circle, 40 ft., diameter; one passage in each cardinal direction; well in the midle of room (might lead down to lower level)";
		break;
	case 8:
		result = "Square, 20 x 20 ft.; door on two walls, passage on thrid wall, secret door on fourth wall";
		break;
	case 9:
		result = "Passage, 10 ft wide; T intersection";
		break;
	case 10:
		result = "Passage, 10 ft wide; four-way intersection";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}
	return result;
}

string Dungeon::genPassage() const
{
	std::string result = "na";
	switch (rolld20(mgen))
	{
	case 1:
	case 2:
		result = "Continue straight 30ft., no doors or side passages";
		break;
	case 3:
		result = "Continue straight 20ft., door to the rightr, then an additional 10 ft. ahead";
		break;
	case 4:
		result = "Continue straight 20ft., door to the left, then door to the left, then an additional 10 ft. ahead.";
		break;
	case 5:
		result = "Continue straight 20ft., passage ends in a door.";
		break;
	case 6:
	case 7:
		result = "Continue straight 20ft., side passage to the right, then an additional 10ft. ahead";
		break;
	case 8:
	case 9:
		result = "Continue straight 20ft., side passage to the left, then an additional 10 ft. ahead";
		break;
	case 10:
		result = "Continue straight 20ft., comes to a dead end; 10 percent chance of secret door";
		break;
	case 11:
	case 12:
		result = "Continue straight 20ft., then passage turns left and continues 10ft.";
		break;
	case 13:
	case 14:
		result = "Continue straight 20ft., then passage turns right and continues 10ft.";
		break;
	case 15:
	case 16:
	case 17:
	case 19:
		result = genChamber();
		break;
	case 20:
		result = genStairs();
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
		break;
	}
	return result;
}
string Dungeon::genDoor() const
{
	string result = "na";
	switch (rolld20(mgen))
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		result = "Wooden";
		break;
	case 11:
	case 12:
		result = "Wooden, barred or locked";
		break;
	case 13:
		result = "Stone";
		break;
	case 14:
		result = "Stone, barred or locked";
		break;
	case 15:
		result = "Iron";
		break;
	case 16:
		result = "Iron, barred or locked";
		break;
	case 17:
		result = "Portcullis";
		break;
	case 18:
		result = "Portcullis, locked in place";
		break;
	case 19:
		result = "Secret door";
		break;
	case 20:
		result = "Secret door, barred or locked";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}

	result += ". ";
	result += genBeyondDoor();

	return result;
}
string Dungeon::genChamber() const
{
	string result = "na";
	int randRoll = rolld20(mgen);
	switch (randRoll)
	{
	case 1:
	case 2:
		result = "Square, 20 x 20 ft.";
		break;
	case 3:
	case 4:
		result = "Square, 30 x 30 ft.";
		break;
	case 5:
	case 6:
		result = "Square, 40 x 40 ft.";
		break;
	case 7:
	case 8:
	case 9:
		result = "Rectangle, 20 x 30 ft.";
		break;
	case 10:
	case 11:
	case 12:
		result = "Rectangle, 30 x 40 ft.";
		break;
	case 13:
	case 14:
		result = "Rectangle, 40 x 50 ft.";
		break;
	case 15:
		result = "Rectangle, 50 x 80 ft.";
		break;
	case 16:
		result = "Circle, 30 ft. diameter";
		break;
	case 17:
		result = "Circle, 50 ft. diameter";
		break;
	case 18:
		result = "Octagon, 40 x 40 ft.";
		break;
	case 19:
		result = "Octagon, 60 x 60 ft.";
		break;
	case 20:
		result = "Trapezoid, roughly 40 x 60 ft.";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}

	int chamberSize = 1;
	if (randRoll > 12)
		chamberSize = 2;

	result += " ";
	result += genChamberExits(chamberSize);

	return result;
}
string Dungeon::genStairs() const
{
	string result = "na";
	switch (rolld20(mgen))
	{
		case 1: case 2: case 3: case 4:
		result = "Down one level to a chamber";
		break;
		case 5: case 6: case 7: case 8:
		result = "Down one level to a passage 20 ft. long";
		break;
		case 9:
		result = "Down two levels to a chamber";
		break;
		case 10:
		result = "Down two levels to a passage 20 ft. long";
		break;
		case 11:
		result = "Down three levels to a chamber";
		break;
		case 12:
		result = "Down three levels to a passage 20 ft. long";
		break;
		case 13:
		result = "Up one level to a chamber";
		break;
		case 14:
		result = "Up one level to a passage 20 ft. long";
		break;
		case 15:
		result = "Up to a dead end";
		break;
		case 16:
		result = "Down to a dead end";
		break;
		case 17:
		result = "Chimney up one level to a passage 20 ft. long";
		break;
		case 18:
		result = "Chimney up two levels to a passage 20 ft. long";
		break;
		case 19:
		result = "Shaft (with or without elevator) down one level to a chamber";
		break;
		case 20:
		result = "Shaft (with or without elevator) up one level to a chamber and down one level to a chamber";
		break;
		default: std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}
	return result;
}

//Generate Inhabitants
// string dungeonFactions() const;
// string dungeonEcology() const;
// string dungeonDifficulty() const;

//other randomize
string Dungeon::genPassageWidth() const
{
	string result = "na";
	switch (rolld20(mgen))
	{
	case 1:
	case 2:
		result = "5 ft.";
		;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		result = "10 ft.";
		break;
	case 13:
	case 14:
		result = "20 ft.";
		break;
	case 15:
	case 16:
		result = "30 ft.";
		break;
	case 17:
		result = "40 ft., with row of pillars down the middle";
		break;
	case 18:
		result = "40 ft., with double row of pillars";
		break;
	case 19:
		result = "40 ft. wide, 20ft. hight";
		break;
	case 20:
		result = "40 ft. wide, 20 ft. high, gallery 10ft. above floor allows access to level above";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}
	return result;
}
string Dungeon::genBeyondDoor() const
{
	string result = "na";
	switch (rolld20(mgen))
	{
	case 1:
	case 2:
		result = "Passage extending 10 ft., then T intersection extending 10 ft. to the right and left";
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		result = "Passage extending 20 ft. straight ahead";
		break;
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		result = genChamber();
		break;
	case 19:
		result = genStairs();
		break;
	case 20:
		result = "False door with trap";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}

	return result;
}
string Dungeon::genChamberExits(int chamberSize) const
{
	// chamber size 1 = NORMAL, 2 = LARGE

	// first, get number of chamber exits
	int numberOfExits = 0;
	switch (rolld20(mgen))
	{
	case 1:
	case 2:
	case 3:
		// numberOfExits = 0;  // already this, no need to do anything
		break;
	case 4:
	case 5:
		if (chamberSize == 1)
			break;
		else
			numberOfExits = 1;
		break;
	case 6:
	case 7:
	case 8:
		numberOfExits = 1;
		break;
	case 9:
	case 10:
	case 11:
		if (chamberSize == 1)
			numberOfExits = 1;
		else
			numberOfExits = 2;
		break;
	case 12:
	case 13:
		numberOfExits = 2;
		break;
	case 14:
	case 15:
		if (chamberSize == 1)
			numberOfExits = 2;
		else
			numberOfExits = 3;
		break;
	case 16:
	case 17:
		numberOfExits = 3;
		break;
	case 18:
		if (chamberSize == 1)
			numberOfExits = 3;
		else
			numberOfExits = 4;
		break;
	case 19:
		if (chamberSize == 1)
			numberOfExits = 4;
		else
			numberOfExits = 5;
		break;
	case 20:
		if (chamberSize == 1)
			numberOfExits = 4;
		else
			numberOfExits = 6;
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}

	// second get exit locations and type
	string result = "";
	for (int i = 0; i < numberOfExits; ++i)
	{
		result += "Exit " + toString(i + 1) + ": ";
		switch (rolld20(mgen))
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			result += "Wall opposite entrance with ";
			result += genChamberExitType();
			break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			result += "Wall left of entrance with ";
			result += genChamberExitType();
			break;
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
			result += "Wall right of entrance with ";
			result += genChamberExitType();
			break;
		case 18:
		case 19:
		case 20:
			result += "Same wall as entrance with ";
			result += genChamberExitType();
			break;
		default:
			std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
		}
	}
	return result;
}

//used by genChamberExits
string Dungeon::genChamberExitType() const
{
	string result = "na";
	switch (randomNumber(1, 2))
	{
	case 1:
		result = genDoor();
		break;
	case 2:
		result = "Corridor, 10 ft. long";
		break;
	default:
		std::cout << "ERROR IN DUNGEON GEN!! check code at " << __FILE__ << " " << __LINE__ << '\n';
	}
	return result;
}
