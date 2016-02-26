#ifndef REWARD_GEN_H
#define REWARD_GEN_H

#include "gear.h"
#include "globalfuncts.h"
#include "colors.h"
#include <algorithm> //for sort function
#include <fstream>  //to read from files
#include <boost/lexical_cast.hpp>

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

    Gear tableA();
    Gear tableB();
    Gear tableC();
    Gear tableD();
    Gear tableE();
    Gear tableF();
    Gear tableG();
    Gear tableH();
    Gear tableI();
    
    std::string GenerateScroll(const int&) const;
    std::string GenerateGemstone(const int&, const int&) const;
    std::string GenerateArt(const int&, const int&) const;
    


    void MakeSpellbook() const;
    void SingleScroll(const int&) const;

    void showPoisons();
};

#endif  //REWARD_GEN_H
