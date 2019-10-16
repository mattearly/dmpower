#pragma once

#include <string>

class Encounter
{
public:
  bool testing = false;
  Encounter();

  ///
  /// \brief Gen_Encounter prompts user for information about the party
  /// \return a string with details about the type of encounter generated
  ///
  std::string Gen_Encounter();

private:
  void set_party_level();
  int ave_lvl;
  int partysize;

  std::string getDifficulty(const int &val);

  // void find_terrain();
  // std::string terrain();
  // enum TerrainType
  // {
  // 	NOT_SURE,
  // 	ARTIC,
  // 	COAST,
  // 	DESERT,
  // 	FOREST,
  // 	GRASSLAND,
  // 	MOUNTAIN,
  // 	SWAMP,
  // 	UNDERDARK
  // };
  // TerrainType terraintype;

  // void pull_encounter_list();
  // enum MonsterType
  // {
  // 	UNKNOWN,
  // 	ABERATIONS,
  // 	BEASTS,
  // 	CELESTIALS,
  // 	CONSTRUCTS,
  // 	DRAGONS,
  // 	ELEMENTALS,
  // 	FEY,
  // 	FIENDS,
  // 	GIANTS,
  // 	MONSTROSITIES,
  // 	OOZES,
  // 	PLANTS,
  // 	UNDEAD
  // };
  // MonsterType monstertype;
};
