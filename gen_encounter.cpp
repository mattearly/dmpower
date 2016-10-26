//
//  gen_encounter.cpp
//  DM-Power-Core-Version
//
//  Created by Matthew Early on 10/26/1./d
//  Copyright (c) 2016 athenstechgiants. All rights reserved.
//
#include "gen_encounter.h"
#include "globalfuncts.h"
#include <iostream>
#include <cmath>

using namespace std;

Encounter::Encounter() {
    ave_lvl = partysize = 0;
}
    
std::string Encounter::Gen_Encounter() {

    set_party_level();

    int seed = (randomNumber(1, 5) - 3);  

    if (testing) cout << "Seed is set to " << seed << "\n";
    if (testing) cout << "Party size Multiplier is set to " << floor(partysize/2) << "\n";
    
    if (testing) return ("Average Level is " + toString(ave_lvl) + "\nCR is set to " + toString(ave_lvl + seed + floor(partysize/2)) + "\n");
    else return "fail";


    

}
    
    

void Encounter::set_party_level() {
    ave_lvl = 0;
    int tmp(0);
    cout << "total # of party members (1 to 10): ";
    partysize = getNumber(1, 10);
    for (int i = 0; i < partysize; i++) {
        cout << "level of party member " << i+1 << " of " << partysize << " (1-20):";
        tmp += getNumber(1, 20);
    }
    ave_lvl = floor(tmp/partysize);
}
