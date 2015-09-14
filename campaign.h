//
//  campaign.h
//  DM-Power
//
//  Created by Matthew Early on 6/12/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#ifndef dm_power_poly_campaign_h
#define dm_power_poly_campaign_h

#include <fstream>
#include "globalfuncts.h"
#include "characters.h"


class Generic_Character_Class;


class Campaign {

public:
    //PLAYER CHARACTER CREATION
    std::list<Generic_Character_Class*> character_list;
    Generic_Character_Class* tmp;
    void pc_menu();
    std::ofstream& dumpCharacter(std::ofstream&); //save
    std::ifstream& retrieveCharacter(std::ifstream&);  //load
    bool checkname(const std::string&) const;
private:
    void makecharacter(Generic_Character_Class *tmp, int& starting_level);

};

#endif
