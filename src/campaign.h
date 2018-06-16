/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2016 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#pragma once

#include <fstream>
#include <list>

class Generic_Character_Class;
// class Barbarian;
// class Bard;
// class Cleric;
// class Druid;
// class Fighter;
// class Monk;
// class Paladin;
// class Ranger;
// class Rouge;
// class Sorcerer;
// class Warlock;
// class Wizard;

class Campaign
{
  public:
    std::list<Generic_Character_Class *> character_list;

    void pc_menu();

    std::ofstream &dumpCharacter(std::ofstream &) const; //save

    bool retrieveCharacter(std::ifstream &); //load

    bool checkname(const std::string &) const;

  private:
    void makecharacter(Generic_Character_Class *tmp, int &starting_level);
};

#endif //CAMPAIGN_H