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
    if (testing) cout << "Party size Multiplier is set to " << floor((partysize-2)/2) << "\n";
    if (testing) return ("Average Level is " + toString(ave_lvl) + "\nCR is set to " + toString(ave_lvl + seed + floor((partysize-2)/2)) + "\n");
    else return "fail";

    find_terrain();
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

void Encounter::find_terrain() {
  
}
