#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H
#include <string>

class Encounter {
public:
		bool testing = true;
		Encounter();
		std::string Gen_Encounter();


private:
		void set_party_level();
		int ave_lvl;
		int partysize;

		void find_terrain();
		std::string terrain();
		enum TerrainType { NOT_SURE, ARTIC, COAST, DESERT, FOREST, GRASSLAND, MOUNTAIN, SWAMP, UNDERDARK };
		TerrainType terraintype;

		void pull_encounter_list();
		enum MonsterType { UNKNOWN, ABERATIONS, BEASTS, CELESTIALS, CONSTRUCTS, DRAGONS, ELEMENTALS, FEY, FIENDS, GIANTS, MONSTROSITIES, OOZES, PLANTS, UNDEAD };
		MonsterType monstertype;

};



#endif //ENCOUNTERS_H
