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


#ifndef REWARD_GEN_H
#define REWARD_GEN_H

#include "gear.h"

/// This class relies on the artObjects.dat and gems.dat files
class Gear;

class Magic_Items {

public:

    void treasure_menu(); //REWARD ITEM GENERATOR MAIN MENU
    
    float xpgenerator();

private:
    std::vector<Gear> full_gear_list;
    
    void GenerateIndividualTreasureCR_0_4();
    void GenerateIndividualTreasureCR_5_10();
    void GenerateIndividualTreasureCR_11_16();
    void GenerateIndividualTreasureCR_17();

    void GenerateHoardTreasureCR_0_4();
    void GenerateHoardTreasureCR_5_10();
    void GenerateHoardTreasureCR_11_16();
    void GenerateHoardTreasureCR_17();

    Gear TableA(const char&);
    Gear TableB(const char&);
    Gear TableC(const char&);
    Gear TableD(const char&);
    Gear TableE(const char&);
    Gear TableF(const char&);
    Gear TableG(const char&);
    Gear TableH(const char&);
    Gear TableI(const char&);
    
    std::string GenerateScroll(const int&) const;
    std::string GenerateGemstone(const int&, const int&) const;
    std::string GenerateArt(const int&, const int&) const;
    


    void MakeSpellbook() const;
    void SingleScroll(const int&) const;

    void showPoisons();
    void showDiseases();
    void showMadness();
};

#endif  //REWARD_GEN_H
