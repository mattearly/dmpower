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

#include <fstream>
#include <list>
#include "characters.h"

class Generic_Character_Class;

class Campaign {
public:
    //PLAYER CHARACTER CREATION
    std::list<Generic_Character_Class*> character_list;
    Generic_Character_Class* tmp;
    void pc_menu();
    std::ofstream& dumpCharacter(std::ofstream&) const; //save
    std::ifstream& retrieveCharacter(std::ifstream&);  //load
    bool checkname(const std::string&) const;
private:
    void makecharacter(Generic_Character_Class *tmp, int& starting_level);

};

#endif  //CAMPAIGN_H
