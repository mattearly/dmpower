#pragma once

#include <fstream>
#include <list>

class Generic_Character_Class;

class Campaign
{
public:
  std::list<Generic_Character_Class *> character_list;

  void pc_menu();

  std::ofstream &dumpCharacter(std::ofstream &) const; //save

  int retrieveCharacter(std::ifstream &); //load

  bool checkname(const std::string &) const;

private:
  void makecharacter(Generic_Character_Class *tmp, int &starting_level);

  void showCampaignCharacterList() const;
};
