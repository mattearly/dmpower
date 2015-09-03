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
#include "gear.h"

class Generic_Character_Class;
class Gear;

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


public:
    //REWARD ITEM GENERATOR
    std::vector<Gear> full_gear_list;
    void treasure_menu();
private:
    void GenerateIndividualTreasureCR_0_4();
    void GenerateIndividualTreasureCR_5_10();
    void GenerateIndividualTreasureCR_11_16();
    void GenerateIndividualTreasureCR_17();

    void GenerateHoardTreasureCR_0_4();
    void GenerateHoardTreasureCR_5_10();
    void GenerateHoardTreasureCR_11_16();
    void GenerateHoardTreasureCR_17();

    Gear tableA();
    Gear tableB();
    Gear tableC();
    Gear tableD();
    Gear tableE();
    Gear tableF();
    Gear tableG();
    Gear tableH();
    Gear tableI();

private:

};

#endif
