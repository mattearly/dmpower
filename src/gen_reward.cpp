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



#include "gen_reward.h"
#include "globalfuncts.h"
#include <algorithm> //for sort function
#include <fstream> 

using namespace std;

void Magic_Items::treasure_menu() {
    int choice = 0;
    Gear item;
    while (choice != 8) {
        simpleClearScreen();
        cout << " -------Random-Treasure-------\n\n"
             << " 1. ROLL Individual Mob Treasure\n"
             << " 2. ROLL Treasure Hoard\n"
             << " 3. Scroll Generator\n"
             << " 4. Spellbook Creator\n"
             << " 5. Poisons Table\n"
             << " 6. Diseases Table\n"
             << " 7. Madness Table\n"
             << " 8. Back to Main Menu\n\n";
        choice = getNumber("Choice(1-8): ", 1, 8);
        switch (choice) {
        case 1:
            cout << "Individual Treasure\n\n"
                 << " 1. Challenge 0-4 \n"
                 << " 2. Challenge 5-10 \n"
                 << " 3. Challenge 11-16 \n"
                 << " 4. Challenge 17+ \n\n";
            choice = getNumber("Choice(1-4): ", 1, 4);
            switch (choice) {
            case 1: GenerateIndividualTreasureCR_0_4(); break;
            case 2: GenerateIndividualTreasureCR_5_10(); break;
            case 3: GenerateIndividualTreasureCR_11_16(); break;
            case 4: GenerateIndividualTreasureCR_17();
            default: break;
            }
            choice = 0;
            pressEnterToContinue();
            break;
        case 2:
            cout << "Treasure Hoard\n\n"
                 << " 1. Challenge 0-4 \n"
                 << " 2. Challenge 5-10 \n"
                 << " 3. Challenge 11-16 \n"
                 << " 4. Challenge 17+ \n\n";
            choice = getNumber("Choice(1-4): ", 1, 4);
            switch (choice) {
            case 1: GenerateHoardTreasureCR_0_4(); break;
            case 2: GenerateHoardTreasureCR_5_10(); break;
            case 3: GenerateHoardTreasureCR_11_16(); break;
            case 4: GenerateHoardTreasureCR_17();
            default: break;
            }
            choice = 0;
            pressEnterToContinue();
            break;
        case 3:
            cout << "Spell figureout-er-er\n\n";
            choice = getNumber("Scroll Level?(1-9): ", 1, 9);
            SingleScroll(choice);
            choice = 0;
            pressEnterToContinue();
            break;
        case 4:
            MakeSpellbook();
            choice = 0;
            pressEnterToContinue();
            break;
        case 5:
            showPoisons();
            break;
        case 6:
            showDiseases();
            break;
        case 7:
            showMadness();
            break;
        case 8:
        default: break;
        }
    }
    simpleClearScreen();
}
void Magic_Items::GenerateIndividualTreasureCR_0_4(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll = " << gr << endl;
    if (gr <= 30) {
        int copper = 0;
        for (int i(0); i < 5; i++) copper += rolld6(mgen);
        Gear tmp(copper, "cp");
        tmplist.push_back(tmp);
    } else if (gr <= 60) {
        int silver = 0;
        for (int i(0); i < 4; i++) silver += rolld6(mgen);
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
    } else if (gr <= 70) {
        int elec = 0;
        for (int i(0); i < 3; i++) elec += rolld6(mgen);
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
    } else if (gr <= 95) {
        int gold = 0;
        for (int i(0); i < 3; i++) gold += rolld6(mgen);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
    } else {
        int plat = 0;
        plat += rolld6(mgen);
        Gear tmp(plat, "pp");
        tmplist.push_back(tmp);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Magic_Items::GenerateIndividualTreasureCR_5_10(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll: " << gr << endl;
    if (gr <= 30) {
        int copper = 0;
        for (int i(0); i < 4; i++) copper += rolld6(mgen);
        copper *= 100;
        Gear tmp(copper, "cp");
        tmplist.push_back(tmp);
        int elec = (rolld6(mgen) * 10);
        Gear tmp1(elec, "ep");
        tmplist.push_back(tmp1);
    } else if (gr <= 60) {
        int silver = 0;
        for (int i(0); i < 6; i++) silver += rolld6(mgen);
        silver *= 10;
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 70) {
        int elec = 0;
        for (int i(0); i < 3; i++) elec += rolld6(mgen);
        elec *= 10;
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 95) {
        int gold = 0;
        for (int i(0); i < 4; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
    } else {
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 3; i++) plat += rolld6(mgen);
        plat *= 10;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Magic_Items::GenerateIndividualTreasureCR_11_16(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);    cout << "Gold Roll: " << gr << endl;
    if (gr <= 20) {
        int silver = 0;
        for (int i(0); i < 4; i++) silver += rolld6(mgen);
        silver *= 100;
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
        int gold = (rolld6(mgen) * 100);
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 35) {
        int elec = (rolld6(mgen) * 100);
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = (rolld6(mgen) * 100);
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 75) {
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = (rolld6(mgen) * 10);
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } else {
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 2; i++) plat += rolld6(mgen);
        plat *= 10;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Magic_Items::GenerateIndividualTreasureCR_17(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll: " << gr << endl;
    if (gr <= 15) {
        int elec = 0;
        for (int i(0); i < 2; i++) elec += rolld6(mgen);
        elec *= 100;
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 8; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 55) {
        int gold = (rolld6(mgen) * 1000);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = (rolld6(mgen) * 100);
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } else {
        int gold = (rolld6(mgen) * 1000);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 2; i++) plat += rolld6(mgen);
        plat *= 100;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}

void Magic_Items::GenerateHoardTreasureCR_0_4(){
    vector<Gear> tmplist;
    int copper(0), silver(0), gold(0);
    for (int i(0); i < 6; i++) copper += rolld6(mgen);
    for (int i(0); i < 3; i++) silver += rolld6(mgen);
    for (int i(0); i < 2; i++) gold += rolld6(mgen);
    copper *= 100;
    silver *= 100;
    gold *= 10;
    Gear tmp(copper, "cp");
    Gear tmp1(silver, "sp");
    Gear tmp2(gold, "gp");
    tmplist.push_back(tmp);
    tmplist.push_back(tmp1);
    tmplist.push_back(tmp2);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 6) {
        cout << "shittiest roll ever.\n";
    } else if (mr <= 16) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        /*Gear tmp(c, "10gp gems");*/
        Gear tmp(c, (GenerateGemstone(c, 10)));
        tmplist.push_back(tmp);
    } else if (mr <= 26) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
    } else if (mr <= 36) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
    } else if (mr <= 44) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 10)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 52) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 60) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 65) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 10)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 70) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 75) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 10)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 92) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 97) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 99) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableG(ans));
    } else {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableG(ans));
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Magic_Items::GenerateHoardTreasureCR_5_10(){
    vector<Gear> tmplist;
    int copper(0), silver(0), gold(0), plat(0);
    for (int i(0); i < 2; i++) copper += rolld6(mgen);
    for (int i(0); i < 2; i++) silver += rolld6(mgen);
    for (int i(0); i < 6; i++) gold += rolld6(mgen);
    for (int i(0); i < 3; i++) plat += rolld6(mgen);
    copper *= 100;
    silver *= 1000;
    gold *= 100;
    plat *= 10;
    Gear tmp(copper, "cp");
    Gear tmp1(silver, "sp");
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp);
    tmplist.push_back(tmp1);
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 4) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 10) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
    } else if (mr <= 16) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
    } else if (mr <= 22) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
    } else if (mr <= 28) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
    } else if (mr <= 32) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 36) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 40) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 44) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
    } else if (mr <= 49) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 54) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 59) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 63) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 66) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 69) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 72) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 76) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableD(ans));
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableD(ans));
    } else if (mr <= 79) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableD(ans));
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableD(ans));;
    } else if (mr <= 84) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 25)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 88) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 50)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 91) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 94) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableF(ans));
    } else if (mr <= 96) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 98) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 99) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 100)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableH(ans));
    } else {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableH(ans));
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }

}
void Magic_Items::GenerateHoardTreasureCR_11_16(){
    vector<Gear> tmplist;
    int gold(0), plat(0);
    for (int i(0); i < 4; i++) gold += rolld6(mgen);
    for (int i(0); i < 5; i++) plat += rolld6(mgen);
    gold *= 1000;
    plat *= 100;
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 3) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 6) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
    } else if (mr <= 9) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
    } else if (mr <= 12) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
    } else if (mr <= 15) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
    } else if (mr <= 19) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 23) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 26) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 29) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableA(ans));
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableB(ans));
    } else if (mr <= 35) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 40) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 45) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 50) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 54) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 58) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 62) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 66) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 68) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableE(ans));
    } else if (mr <= 70) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableE(ans));
    } else if (mr <= 72) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableE(ans));
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableE(ans));;
    } else if (mr <= 76) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableF(ans));
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableF(ans));
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableF(ans));
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 82) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableF(ans));
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 88) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 90) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 92) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 94) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 250)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableI(ans));
    } else if (mr <= 96) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 750)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableI(ans));
    } else if (mr <= 98) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 500)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableI(ans));
    } else {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        tmplist.push_back(TableI(ans));
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }

}
void Magic_Items::GenerateHoardTreasureCR_17(){
    vector<Gear> tmplist;
    int gold(0), plat(0);
    for (int i(0); i < 12; i++) gold += rolld6(mgen);
    for (int i(0); i < 8; i++) plat += rolld6(mgen);
    gold *= 1000;
    plat *= 1000;
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 2) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 5) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 8) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 11) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 14) {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableC(ans));
    } else if (mr <= 22) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 30) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 38) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 46) {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableD(ans));
    } else if (mr <= 52) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableE(ans));
    } else if (mr <= 58) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableE(ans));
    } else if (mr <= 63) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableE(ans));
    } else if (mr <= 68) {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableE(ans));
    } else if (mr <= 69) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 70) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 71) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 72) {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableG(ans));
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 76) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 78) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 80) {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableH(ans));
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, (GenerateGemstone(c, 1000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableI(ans));
    } else if (mr <= 90) {
        int c = rolld10(mgen);
        Gear tmp(c, (GenerateArt(c, 2500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableI(ans));
    } else if (mr <= 95) {
        int c = rolld4(mgen);
        Gear tmp(c, (GenerateArt(c, 7500)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableI(ans));
    } else {
        int c = rolld8(mgen);
        Gear tmp(c, (GenerateGemstone(c, 5000)));
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(TableI(ans));
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
Gear Magic_Items::TableA(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table A Roll = " << roll << endl;
    if (roll <= 50) {
        Gear tmp(1, "Potion of Healing");
        return tmp;
    } else if (roll <= 60) { //was cantrip changed to 1st lvl
        string scroll = GenerateScroll(1);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Potion of Climbing");
        return tmp;
    } else if (roll <= 90) {
        string scroll = GenerateScroll(1);
        Gear tmp(1, scroll);;
        return tmp;
    } else if (roll <= 94) {
        string scroll = GenerateScroll(2);
        Gear tmp(1, scroll);;
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Bag of holding");
        return tmp;
    } else {
        Gear tmp(1, "Driftglobe");
        return tmp;
    }
}
Gear Magic_Items::TableB(const char& r){
    int roll = 0;
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table B Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Potion of greater healing");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Potion of fire breath");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Potion of resistance");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Ammunition, +1");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Potion of animal friendship");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Potion of hill giant strength");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Potion of growth");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Potion of water breathing");
        return tmp;
    } else if (roll <= 59) {
        string scroll = GenerateScroll(2);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 64) {
        string scroll = GenerateScroll(3);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Bag of holding");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Keoghtom's ointment");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Oil of slipperiness");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Dust of disappearance");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Dust of dryness");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Dust of sneezing and choking");
        return tmp;
    } else if (roll <= 81) {
		string loader = "Elemental Gem";
				int quaalvar = rolld100(mgen);
				if (quaalvar < 26) {
					loader += "(Blue sapphire)";
				} else if (quaalvar < 51) {
					loader += "(Yellow Diamond)";
				} else if (quaalvar < 76) {
					loader += "(Red corundum)";
				} else {
					loader += "(Emerald)";
				}
				Gear tmp(1, loader);
				return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Philter of love");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Alchemy jug");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Cap of water breathing");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Cloak of the manta ray");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Driftglobe");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Goggles of night");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Helm of comprehending languages");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Immovable rod");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "lantern of revealing");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Mariner's armor");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Mithral armor");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Potion of poison");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of swimming");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Robe of useful items");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Ring of climbing");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Saddle of the cavalier");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wand of magic detection");
        return tmp;
    } else {
        Gear tmp(1, "Wand of secrets");
        return tmp;
    }
}
Gear Magic_Items::TableC(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table C Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Potion of superior healing");
        return tmp;
    } else if (roll <= 22) {
        string scroll = GenerateScroll(4);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Ammunition, +2");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Potion of clairvoyance");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Potion of diminution");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Potion of gaseous form");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Potion of frost giant strength");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Potion of stone giant strength");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Potion of Heroism");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Potion of invulnerability");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Potion of mind reading");
        return tmp;
    } else if (roll <= 72) {
        string scroll = GenerateScroll(5);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Elixir of health");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Oil of etherealness");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Potion of fire giant strength");
        return tmp;
    } else if (roll <= 84) {
        string loader = "Quaal's Feather Token";
        int quaalvar = rolld100(mgen);
        if (quaalvar < 21) {
            loader += "(Anchor)";
        } else if (quaalvar < 36) {
            loader += "(Bird)";
        } else if (quaalvar < 51) {
            loader += "(Fan)";
        } else if (quaalvar < 66) {
            loader += "(Swan Boat)";
        } else if (quaalvar < 91) {
            loader += "(Tree)";
        } else {
            loader += "(Whip)";
        }
        Gear tmp(1, loader);
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Scroll of Protection");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Bag of beans");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Bead of force");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Chime of opening");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Decanter of endless water");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Eyes of minute seeing");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Folding boat");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Heward's handy haversack");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Horseshoes of speed");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Neckalace of fireballs");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Periapt of health");
        return tmp;
    } else {
        Gear tmp(1, "Sending stones");
        return tmp;
    }
}
Gear Magic_Items::TableD(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table D Roll = " << roll << endl;
    if (roll <= 20) {
        Gear tmp(1, "Potion of supreme healing");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Potion of invisibility");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Potion of speed");
        return tmp;
    } else if (roll <= 50) {
        string scroll = GenerateScroll(6);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 57) {
        string scroll = GenerateScroll(7);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Ammunition, +3");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Oil of sharpness");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Potion of flying");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Potion of cloud giant strength");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Potion of longevity");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Potion of vitality");
        return tmp;
    } else if (roll <= 92) {
        string scroll = GenerateScroll(8);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Horseshoes of a zephyr");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Nolzur's marvelous pigments");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Bag of devouring");
        return tmp;
    } else {
        Gear tmp(1, "PorTable hole");
        return tmp;
    }
}
Gear Magic_Items::TableE(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table E Roll = " << roll << endl;
    if (roll <= 30) {
        string scroll = GenerateScroll(8);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Potion of storm giant strength");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Potion of supreme healing");
        return tmp;
    } else if (roll <= 85) {
        string scroll = GenerateScroll(9);
        Gear tmp(1, scroll);
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Universal solvent");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Arrow of slaying");
        return tmp;
    } else {
        Gear tmp(1, "Sovereign glue");
        return tmp;
    }
}
Gear Magic_Items::TableF(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table F Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Weapon, +1");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Shield, +1");
        return tmp;
    } else if (roll <= 21) {
        Gear tmp(1, "Sentinel Shield");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Amulet of proof against detection and location");
        return tmp;
    } else if (roll <= 25) {
        Gear tmp(1, "Boots of elvenkind");
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Boots of striding of springing");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Bracers of archery");
        return tmp;
    } else if (roll <= 31) {
        Gear tmp(1, "Brooch of shielding");
        return tmp;
    } else if (roll <= 33) {
        Gear tmp(1, "Broom of flying");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Cloak of elvenkind");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Cloak of protection");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Gauntlets of ogre power");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Hat of disguise");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Javelin of lightning");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Pearl of power");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Rod of the pact keeper, +1");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Slippers of spider climbing");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Staff of the adder");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Staff of the python");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Sword of vengeance");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Trident of fish command");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Wand of magic missles");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Wand of the war mage, +1");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Wand of web");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Weapon of warning");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Adamantine armor(chain mail)");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Adamantine armor(chain shirt)");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Adamantine armor(scale mail)");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Bag of tricks(grey)");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Bag of tricks(rust)");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Bag of tricks(tan)");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Boots of the winterlands");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Circlet of blasting");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Deck of illusions");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Eversmoking bottle");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Eyes of charming");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Eyes of the eagle");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Figurine of wondrous power(silver raven)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Gem of brightness");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Gem of missile snaring");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Gloves of swimming and climbing");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Gloves of thievery");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Headband of intellect");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Helm of telepathy");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Instrument of the bards(Doss lute)");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Instrument of the bards(Fochlucan bandore)");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Instrument of the bards(Mac-Fuimidh cittern)");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Medallion of thoughts");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Necklace of adaptation");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Periapt of wound closure");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Pipes of haunting");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Pipes of the sewers");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Ring of jumping");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Ring of mind shielding");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of warmth");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Ring of water walking");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Quiver of Ehlonna");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Stone of good luck");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wind fan");
        return tmp;
    } else {
        Gear tmp(1, "Winged boots");
        return tmp;
    }
}
Gear Magic_Items::TableG(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table G Roll = " << roll << endl;
    if (roll <= 11) {
        Gear tmp(1, "Weapon, +2");
        return tmp;
    } else if (roll <= 14) {
        string loader = "Figurine of wonderous power";
        int d8 = rolld8(mgen);
        if (d8 == 1) {
            loader += "(Bronze griffon)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 2) {
            loader += "(Ebony fly)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 3) {
            loader += "(Golden lions)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 4) {
            loader += "(Ivory goats)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 5) {
            loader += "(Marble elephant)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 <= 7) {
            loader += "(Onyx dog)";
            Gear tmp(1, loader);
            return tmp;
        } else {
            loader += "(Serpentine owl)";
            Gear tmp(1, loader);
            return tmp;
        }
    } else if (roll <= 15) {
        Gear tmp(1, "Adamantine armor(breastplate)");
        return tmp;
    } else if (roll <= 16) {
        Gear tmp(1, "Adamantine armor(splint)");
        return tmp;
    } else if (roll <= 17) {
        Gear tmp(1, "Amulet of health");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Armor of vulnerability");
        return tmp;
    } else if (roll <= 19) {
        Gear tmp(1, "Arrow-catching shield");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Belt of dwarvenkind");
        return tmp;
    } else if (roll <= 21) {
        Gear tmp(1, "Belt of hill giant strength");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Berserker axe");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Boots of levitation");
        return tmp;
    } else if (roll <= 24) {
        Gear tmp(1, "Boots of speed");
        return tmp;
    } else if (roll <= 25) {
        Gear tmp(1, "Bowl of commanding water elementals");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Bracers of defense");
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Brazier of commanding fire elementals");
        return tmp;
    } else if (roll <= 28) {
        Gear tmp(1, "Cape of the mountebank");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Censer of controlling air elementals");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Armor, +1 chain mail");
        return tmp;
    } else if (roll <= 31) {
        Gear tmp(1, "Armor of resistance(chain mail)");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Armor, +1 chain shirt");
        return tmp;
    } else if (roll <= 33) {
        Gear tmp(1, "Armor of resistance(chain shirt)");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Cloak of displacement");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Cloak of the bat");
        return tmp;
    } else if (roll <= 36) {
        Gear tmp(1, "Cube of force");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Daern's instant fortress");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Dagger of venom");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Dimensional shackles");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Dragon slayer");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Elven chain");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Flame tongue");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Gem of seeing");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Giant slayer");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Glammoured studded leather");
        return tmp;
    } else if (roll <= 46) {
        Gear tmp(1, "Helm of teleportation");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Horn of blasting");
        return tmp;
    } else if (roll <= 48) {
        Gear tmp(1, "Horn of Valhalla(silver or brass)");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Instrument of the bards(Canaith Mandolin");
        return tmp;
    } else if (roll <= 50) {
        Gear tmp(1, "Instrument of the bards(Cli lyre)");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Ioun stone(awareness)");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Ioun stone(protection)");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Ioun stone(reverse)");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Ioun stone(sustenance)");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Iron bands of Bilarro");
        return tmp;
    } else if (roll <= 56) {
        Gear tmp(1, "Armor, +1 leather");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Armor of resistance(leather)");
        return tmp;
    } else if (roll <= 58) {
        Gear tmp(1, "Mace of disruption");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Mace of smiting");
        return tmp;
    } else if (roll <= 60) {
        Gear tmp(1, "Mace of terror");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Mantle of spell resistance");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Necklace of prayer beads");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Periapt of proof against poison");
        return tmp;
    } else if (roll <= 64) {
        Gear tmp(1, "Ring of animal influence");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Ring of evasion");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Ring of feather falling");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Ring of free action");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Ring of protection");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Ring of resistance");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Ring of spell storing");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Ring of the ram");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Ring of X-ray vision");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Rob of eyes");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Rod of rulership");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Rod of the pact keeper, +2");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Rope of entanglement");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Armor, +1 scale mail");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Armor of resistance(scale mail)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Shield, +2");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Shield of missle attraction");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Staff of charming");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Staff of healing");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Staff of swarming insects");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Staff of the woodlands");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Staff of the withering");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Stone of controlling earth elementals");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Sun blade");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Sword of life stealing");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Sword of wounding");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Tentacle rod");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Vicious weapon");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Wand of binding");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Wand of enemy detection");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Wand of fear");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Wand of fireballs");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Wand of lightning bolts");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Wand of paralysis");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Wand of the war mage, +2");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wand of wonder");
        return tmp;
    } else {
        Gear tmp(1, "Wings of flying");
        return tmp;
    }
}
Gear Magic_Items::TableH(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table H Roll = " << roll << endl;
    if (roll <= 10) {
        Gear tmp(1, "Weapon, +3");
        return tmp;
    } else if (roll <= 12) {
        Gear tmp(1, "Amulet of the planes");
        return tmp;
    } else if (roll <= 14) {
        Gear tmp(1, "Carpet of flying");
        return tmp;
    } else if (roll <= 16) {
        Gear tmp(1, "Crystal ball(very rare version)");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Ring of regeneration");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Ring of shooting stars");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Ring of telekinesis");
        return tmp;
    } else if (roll <= 24) {
        Gear tmp(1, "Robe of scintillating colors");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Robe of stars");
        return tmp;
    } else if (roll <= 28) {
        Gear tmp(1, "Rod of absorption");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Rod of alertness");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Rod of security");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Rod of the pact keeper, +3");
        return tmp;
    } else if (roll <= 36) {
        Gear tmp(1, "Scimitar of speed");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Shield, +3");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Staff of fire");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Staff of frost");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Staff of power");
        return tmp;
    } else if (roll <= 46) {
        Gear tmp(1, "Staff of striking");
        return tmp;
    } else if (roll <= 48) {
        Gear tmp(1, "Staff of thunder and lightning");
        return tmp;
    } else if (roll <= 50) {
        Gear tmp(1, "Sword of sharpness");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Wand of polymorph");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Wand of the war mage, +3");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Adamantine armor(half plate)");
        return tmp;
    } else if (roll <= 56) {
        Gear tmp(1, "Adamantine armor(plate)");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Animated shield");
        return tmp;
    } else if (roll <= 58) {
        Gear tmp(1, "Belt of fire giant strength");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Belt of stone giant strength");
        return tmp;
    } else if (roll <= 60) {
        Gear tmp(1, "Armor, +1 breastplate");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Armor of resistance(breastplate)");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Candle of invocation");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Armor, +2 chain mail");
        return tmp;
    } else if (roll <= 64) {
        Gear tmp(1, "Armor, +2 chain shirt");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Cloak of arachnida");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Dancing sword");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Demon armor");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Dragon scale mail");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Dwarven plate");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Dwarven thrower");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Efreeti bottle");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Figurine of wondrous power(obsidian steed)");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Frost brand");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Helm of brilliance");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Horn of Valhalla(bronze)");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Instrument of the bards(Anstruth harp)");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Ioun stone(absorption)");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Ioun stone(agility)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Ioun stone(fortitude)");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Ioun stone(insight)");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Ioun stone(intellect)");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Ioun stone(leadership)");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Ioun stone(strength)");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Armor, +2 leather");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Manual of bodily health");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Manual of gainful exercise");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Manual of golems");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Manual of quickness of action");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Mirror of life trapping");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Nine lives stealer");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Oathbow");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Armor, +2 scale mail");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Spellguard shield");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Armor, +1 splint");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Armor of resistance(splint)");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Armor, +1 studded leather");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Armor of resistance(studded leather)");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Tome of clear thought");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Tome of leadership and influecne");
        return tmp;
    } else {
        Gear tmp(1, "Tome of understanding");
        return tmp;
    }
}
Gear Magic_Items::TableI(const char& r){
    int roll = 0;
    // char ans = getYorN("Have system roll for you?(y/n): ");
    if (r == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table I Roll = " << roll << endl;
    if (roll <= 5) {
        Gear tmp(1, "Defender");
        return tmp;
    } else if (roll <= 10) {
        Gear tmp(1, "Hammer of thunderbolts");
        return tmp;
    } else if (roll <= 15) {
        Gear tmp(1, "Luck blade");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Sword of answering");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Holy Avenger");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Ring of djinni summoning");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Ring of invisibility");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Ring of spell turning");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Rod of lordly might");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Staff of the magi");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Vorpal sword");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Belt of cloud giant strength");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Armor, +2 breastplate");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Armor, +3 chain mail");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Armor, +3 chain shirt");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Cloak of invisibility");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Crystal ball(legendary version)");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Armor, +1 half plate");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Iron flask");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Armor, +3 leather");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Armor, +1 plate");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Robe of the archmagi");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Rod of resurrection");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Armor, +1 scale mail");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Scarab of protection");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Armor, +2 splint");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Armor, +2 studded leather");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Well of many worlds");
        return tmp;
    } else if (roll <= 76) {
        string loader = "Armor, ";
        int d12 = rolld12(mgen);
        if (d12 <= 2) {
            loader += "+2 half plate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 4) {
            loader += "+2 plate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 6) {
            loader += "+3 studded leather";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 == 8) {
            loader += "+3 breastplate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 == 10) {
            loader += "+3 splint";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 11) {
            loader += "+3 half plate";
            Gear tmp(1, loader);
            return tmp;
        } else {
            loader += "+3 plate";
            Gear tmp(1, loader);
            return tmp;
        }
    } else if (roll <= 77) {
        Gear tmp(1, "Apparatus of Kwalish");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Amor of invulnerability");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Belt of storm giant strength");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Cubic gate");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Deck of many things");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Efreeti chain");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Armor of resistance(half plate)");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Horn of Valhalla(iron)");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Instrument of the bards(Ollamh harp)");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Ioun stone(greater absorption)");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Ioun stone(mastery)");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Ioun stone(regeneration)");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Plate armor of etherealness");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Plate armor of resistance");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Ring of air elemetnal command");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Ring of fire elemental command");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Ring of three wishes");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of water elemental command");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Sphere of Annihilation");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Talisman of Pure Good");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Talisman of the Sphere");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Talisman of Ultimate Evil");
        return tmp;
    } else {
        Gear tmp(1, "Tome of Stilled Tongue");
        return tmp;
    }
}

string Magic_Items::GenerateScroll(const int& lvl) const{
    int ss = 0;
    string scroll;
    switch (lvl) {
    case 1:
        scroll = "Level 1 Scroll of ";
        ss = randomNumber(1, 61);
        switch (ss) {
        case 1:
            scroll += "Alarm (ranger, wizard)";
            break;
        case 2:
            scroll += "Animal Friendship (bard, druid, ranger)";
            break;
        case 3:
            scroll += "Armor of Agathys (warlock)";
            break;
        case 4:
            scroll += "Arms of Hadar (warlock)";
            break;
        case 5:
            scroll += "Bane (bard, cleric)";
            break;
        case 6:
            scroll += "Bless (cleric, paladin)";
            break;
        case 7:
            scroll += "Burning Hands (sorcerer, wizard)";
            break;
        case 8:
            scroll += "Charm Person (bard, druid, sorcerer, warlock, wizard)";
            break;
        case 9:
            scroll += "Color Spray (sorcerer, wizard)";
            break;
        case 10:
            scroll += "Command (cleric, paladin)";
            break;
        case 11:
            scroll += "Compelled Duel (paladin)";
            break;
        case 12:
            scroll += "Comprehend Languages (bard, sorcerer, warlock, wizard)";
            break;
        case 13:
            scroll += "Create or Destroy Water (cleric, druid)";
            break;
        case 14:
            scroll += "Cure Wounds (bard, cleric, druid, paladin, ranger)";
            break;
        case 15:
            scroll += "Detect Evil and Good (cleric, paladin)";
            break;
        case 16:
            scroll += "Detect Magic (bard, cleric, druid, paladin, ranger, sorcerer, wizard)";
            break;
        case 17:
            scroll += "Detect Poison and Disease (cleric, druid, paladin, ranger)";
            break;
        case 18:
            scroll += "Disguise Self (bard, sorcerer, wizard)";
            break;
        case 19:
            scroll += "Dissonant Whispers (bard)";
            break;
        case 20:
            scroll += "Divine Favor (paladin)";
            break;
        case 21:
            scroll += "Ensnaring Strike (ranger)";
            break;
        case 22:
            scroll += "Entangle (druid)";
            break;
        case 23:
            scroll += "Expeditious Retreat (sorcerer, warlock, wizard)";
            break;
        case 24:
            scroll += "False Life (sorcerer, wizard)";
            break;
        case 25:
            scroll += "Faerie Fire (bard, druid)";
            break;
        case 26:
            scroll += "Feather Fall (bard, sorcerer, wizard)";
            break;
        case 27:
            scroll += "Find Familiar (wizard)";
            break;
        case 28:
            scroll += "Fog Cloud (druid, ranger, sorcerer, wizard)";
            break;
        case 29:
            scroll += "Goodberry (druid, ranger)";
            break;
        case 30:
            scroll += "Grease (wizard)";
            break;
        case 31:
            scroll += "Guiding Bolt (cleric)";
            break;
        case 32:
            scroll += "Hail of Thorns (ranger)";
            break;
        case 33:
            scroll += "Healing Word (bard, cleric, druid)";
            break;
        case 34:
            scroll += "Hellish Rebuke (warlock)";
            break;
        case 35:
            scroll += "Heroism (bard, paladin)";
            break;
        case 36:
            scroll += "Hex (warlock)";
            break;
        case 37:
            scroll += "Hunter's Mark (ranger)";
            break;
        case 38:
            scroll += "Identify (bard, wizard)";
            break;
        case 39:
            scroll += "Illusory Script (bard, warlock, wizard)";
            break;
        case 40:
            scroll += "Inflict Wounds (cleric)";
            break;
        case 41:
            scroll += "Jump (druid, ranger, sorcerer, wizard)";
            break;
        case 42:
            scroll += "Longstrider (bard, druid, ranger, wizard)";
            break;
        case 43:
            scroll += "Mage Armor (sorcerer, wizard)";
            break;
        case 44:
            scroll += "Magic Missle (sorcerer, wizard)";
            break;
        case 45:
            scroll += "Protection from Evil and Good (cleric, paladin, warlock, wizard)";
            break;
        case 46:
            scroll += "Purify Food and Drink (cleric, druid, paladin)";
            break;
        case 47:
            scroll += "Ray of Sickness (sorcerer, wizard)";
            break;
        case 48:
            scroll += "Searing Smite (paladin)";
            break;
        case 49:
            scroll += "Sanctuary (cleric)";
            break;
        case 50:
            scroll += "Shield (sorcerer, wizard)";
            break;
        case 51:
            scroll += "Shield of Faith (cleric, paladin)";
            break;
        case 52:
            scroll += "Silent Image (bard, sorcerer, wizard)";
            break;
        case 53:
            scroll += "Sleep (bard, sorcerer, wizard)";
            break;
        case 54:
            scroll += "Speak with Animals (bard, druid, ranger)";
            break;
        case 55:
            scroll += "Tasha's Hideous Laughter (bard, wizard)";
            break;
        case 56:
            scroll += "Tensor's Floating Disk (wizard)";
            break;
        case 57:
            scroll += "Thunderous Smite (paladin)";
            break;
        case 58:
            scroll += "Thunderwave (bard, druid, sorcerer, wizard)";
            break;
        case 59:
            scroll += "Unseen Servant (bard, warlock, wizard)";
            break;
        case 60:
            scroll += "Witch Bolt (sorcerer, warlock, wizard)";
            break;
        case 61:
            scroll += "Wrathful Smite (paladin)";
            break;
        }
        break;
    case 2:
        scroll = "Level 2 Scroll of ";
        ss = randomNumber(1, 59);
        switch (ss) {
        case 1:
            scroll += "Aid (cleric, paladin)";
            break;
        case 2:
            scroll += "Alter Self (sorcerer, wizard)";
            break;
        case 3:
            scroll += "Animal Messenger (bard, druid, ranger)";
            break;
        case 4:
            scroll += "Arcane Lock (wizard)";
            break;
        case 5:
            scroll += "Augury (cleric)";
            break;
        case 6:
            scroll += "Barkskin (druid, ranger)";
            break;
        case 7:
            scroll += "Beast Sense (druid, ranger)";
            break;
        case 8:
            scroll += "Blindness/Deafness (bard, cleric, sorcerer, wizard)";
            break;
        case 9:
            scroll += "Blur (sorcerer, wizard)";
            break;
        case 10:
            scroll += "Branding Smite (paladin)";
            break;
        case 11:
            scroll += "Calm Emotions (bard, cleric)";
            break;
        case 12:
            scroll += "Cloud of Daggers (bard, sorcerer, warlock, wizard)";
            break;
        case 13:
            scroll += "Continual Flame (cleric, wizard)";
            break;
        case 14:
            scroll += "Cordon of Arrows (ranger)";
            break;
        case 15:
            scroll += "Crown of Madness (bard, sorcerer, warlock, wizard)";
            break;
        case 16:
            scroll += "Darkness (sorcerer, warlock, wizard)";
            break;
        case 17:
            scroll += "Darkvision (druid, ranger, sorcerer, wizard)";
            break;
        case 18:
            scroll += "Detect Thoughts (bard, sorcerer, wizard)";
            break;
        case 19:
            scroll += "Enhance Ability (bard, cleric, druid, sorcerer)";
            break;
        case 20:
            scroll += "Enlarge/Reduce (sorcerer, wizard)";
            break;
        case 21:
            scroll += "Enthrall (bard, warlock)";
            break;
        case 22:
            scroll += "Find Steed (paladin)";
            break;
        case 23:
            scroll += "Find Traps (cleric, druid, ranger)";
            break;
        case 24:
            scroll += "Flame Blade (druid)";
            break;
        case 25:
            scroll += "Flaming Sphere (druid, wizard)";
            break;
        case 26:
            scroll += "Heat Metal (bard, druid)";
            break;
        case 27:
            scroll += "Hold Person (bard, druid, sorcerer, warlock)";
            break;
        case 28:
            scroll += "Gentle Repose (cleric)";
            break;
        case 29:
            scroll += "Gust of Wind (druid, sorcerer)";
            break;
        case 30:
            scroll += "Invisibility (bard, sorcerer, warlock, wizard)";
            break;
        case 31:
            scroll += "Knock (bard, sorcerer, wizard)";
            break;
        case 32:
            scroll += "Lesser Restoration (bard, cleric, druid, paladin, ranger)";
            break;
        case 33:
            scroll += "Levitate (sorcerer, wizard)";
            break;
        case 34:
            scroll += "Locate Animals or Plants (bard, druid, ranger)";
            break;
        case 35:
            scroll += "Locate Object (bard, cleric, druid, paladin, ranger, wizard)";
            break;
        case 36:
            scroll += "Magic Mouth (bard, wizard)";
            break;
        case 37:
            scroll += "Magic Weapon (paladin, wizard)";
            break;
        case 38:
            scroll += "Melf's Acid Arrow (wizard)";
            break;
        case 39:
            scroll += "Mirror Image (sorcerer, warlock, wizard)";
            break;
        case 40:
            scroll += "Misty Step (sorcerer, warlock, wizard)";
            break;
        case 41:
            scroll += "Moonbeam (druid)";
            break;
        case 42:
            scroll += "Nystul's Magic Aura (wizard)";
            break;
        case 43:
            scroll += "Pass without Trace (druid, ranger)";
            break;
        case 44:
            scroll += "Phantasmal Force (bard, sorcerer, wizard)";
            break;
        case 45:
            scroll += "Prayer of Healing (cleric)";
            break;
        case 46:
            scroll += "Protection of Poison (cleric, druid, poison, ranger)";
            break;
        case 47:
            scroll += "Ray of Enfeeblement (warlock, wizard)";
            break;
        case 48:
            scroll += "Rope Trick (wizard)";
            break;
        case 49:
            scroll += "Scorching Ray (sorcerer, wizard)";
            break;
        case 50:
            scroll += "See Invisibility (bard, sorcerer, wizard)";
            break;
        case 51:
            scroll += "Silence (bard, cleric, ranger)";
            break;
        case 52:
            scroll += "Silent Image (bard, sorcerer, wizard)";
            break;
        case 53:
            scroll += "Spider Climb (sorcerer, warlock, wizard)";
            break;
        case 54:
            scroll += "Spike Growth (druid, ranger)";
            break;
        case 55:
            scroll += "Spiritual Weapon (cleric)";
            break;
        case 56:
            scroll += "Suggestion (bard, sorcerer, warlock, wizard)";
            break;
        case 57:
            scroll += "Warding Bond (cleric)";
            break;
        case 58:
            scroll += "Web (sorcerer, wizard)";
            break;
        case 59:
            scroll += "Zone of Truth (bard, cleric, paladin)";
            break;
        }
        break;
    case 3:
        scroll = "Level 3 Scroll of ";
        ss = randomNumber(1, 50);
        switch (ss) {
        case 1:
            scroll += "Animate Dead (cleric, wizard)";
            break;
        case 2:
            scroll += "Aura of Vitality (paladin)";
            break;
        case 3:
            scroll += "Beacon of Hope (cleric)";
            break;
        case 4:
            scroll += "Bestow Curse (bard, cleric, wizard)";
            break;
        case 5:
            scroll += "Blinding Smite (paladin)";
            break;
        case 6:
            scroll += "Blink (sorcerer, wizard)";
            break;
        case 7:
            scroll += "Call Lightning (druid)";
            break;
        case 8:
            scroll += "Clairvoyance (bard, cleric, sorcerer, wizard)";
            break;
        case 9:
            scroll += "Conjure Animals (druid, ranger)";
            break;
        case 10:
            scroll += "Conjure Barrage (ranger)";
            break;
        case 11:
            scroll += "Counterspell (sorcerer, warlock, wizard)";
            break;
        case 12:
            scroll += "Create Food and Water (cleric, paladin)";
            break;
        case 13:
            scroll += "Crusader's Mantle (paladin)";
            break;
        case 14:
            scroll += "Daylight (cleric, druid, paladin, ranger, sorcerer)";
            break;
        case 15:
            scroll += "Dispel Magic (bard, cleric, druid, paladin, sorcerer, warlock, wizard)";
            break;
        case 16:
            scroll += "Elemental Weapon (paladin)";
            break;
        case 17:
            scroll += "Fear (bard, sorcerer, warlock, wizard)";
            break;
        case 18:
            scroll += "Feign Death (bard, cleric, druid, wizard)";
            break;
        case 19:
            scroll += "Fireball (sorcerer, wizard)";
            break;
        case 20:
            scroll += "Fly (sorcerer, warlock)";
            break;
        case 21:
            scroll += "Gaseous Form (sorcerer, warlock, wizard)";
            break;
        case 22:
            scroll += "Glyph of Warding (bard, cleric, wizard)";
            break;
        case 23:
            scroll += "Haste (sorcerer, wizard)";
            break;
        case 24:
            scroll += "Hunger of Hadar (warlock)";
            break;
        case 25:
            scroll += "Hypnotic Pattern (bard, sorcerer, warlock, wizard)";
            break;
        case 26:
            scroll += "Leomund's Tiny Hut (bard, wizard)";
            break;
        case 27:
            scroll += "Lightning Arrow (ranger)";
            break;
        case 28:
            scroll += "Lightning Bolt (sorcerer, wizard)";
            break;
        case 29:
            scroll += "Magic Circle (cleric, paladin, warlock, wizard)";
            break;
        case 30:
            scroll += "Major Image (bard, sorcerer, warlock, wizard)";
            break;
        case 31:
            scroll += "Mass Healing Word (cleric)";
            break;
        case 32:
            scroll += "Meld Into Stone (cleric, druid)";
            break;
        case 33:
            scroll += "Nondetection (bard, ranger, wizard)";
            break;
        case 34:
            scroll += "Phantom Steed (wizard)";
            break;
        case 35:
            scroll += "Plant Growth (bard, druid, ranger)";
            break;
        case 36:
            scroll += "Protection from Energy (cleric, druid, ranger, sorcerer, wizard)";
            break;
        case 37:
            scroll += "Remove Curse (cleric, paladin, warlock)";
            break;
        case 38:
            scroll += "Revivify (cleric, paladin)";
            break;
        case 39:
            scroll += "Sending (bard, cleric, wizard)";
            break;
        case 40:
            scroll += "Sleet Storm (druid, sorcerer, wizard)";
            break;
        case 41:
            scroll += "Slow (sorcerer, wizard)";
            break;
        case 42:
            scroll += "Speak with Dead (bard, cleric)";
            break;
        case 43:
            scroll += "Speak with Plants (bard, druid, ranger)";
            break;
        case 44:
            scroll += "Spirit Guardians (cleric)";
            break;
        case 45:
            scroll += "Stinking Cloud (bard, sorcerer, wizard)";
            break;
        case 46:
            scroll += "Tongues (bard, cleric, sorcerer, warlock, wizard)";
            break;
        case 47:
            scroll += "Vampiric Touch (warlock, wizard)";
            break;
        case 48:
            scroll += "Water Breathing (druid, ranger, sorcerer, wizard)";
            break;
        case 49:
            scroll += "Water Walk (cleric, druid, ranger, sorcerer)";
            break;
        case 50:
            scroll += "Wind Wall (druid, ranger)";
            break;
        }
        break;
    case 4:
        scroll = "Level 4 Scroll of ";
        ss = randomNumber(1, 34);
        switch (ss) {
        case 1:
            scroll += "Aura of Life (paladin)";
            break;
        case 2:
            scroll += "Aura of Purify (paladin)";
            break;
        case 3:
            scroll += "Arcane Eye (wizard)";
            break;
        case 4:
            scroll += "Banishment (cleric, paladin, sorcerer, warlock, wizard)";
            break;
        case 5:
            scroll += "Blight (druid, sorcerer, warlock, wizard)";
            break;
        case 6:
            scroll += "Compulsion (bard)";
            break;
        case 7:
            scroll += "Confusion (bard, druid, sorcerer, wizard)";
            break;
        case 8:
            scroll += "Conjure Minor Elementals (druid, wizard)";
            break;
        case 9:
            scroll += "Conjure Woodland Beings (druid, ranger)";
            break;
        case 10:
            scroll += "Control Water (druid, wizard)";
            break;
        case 11:
            scroll += "Control Weather (cleric)";
            break;
        case 12:
            scroll += "Death Ward (cleric)";
            break;
        case 13:
            scroll += "Dimension Door (bard, warlock, wizard)";
            break;
        case 14:
            scroll += "Divination (cleric)";
            break;
        case 15:
            scroll += "Dominate Beast (druid, sorcerer)";
            break;
        case 16:
            scroll += "Evard's Black Tentacles (wizard)";
            break;
        case 17:
            scroll += "Fabricate (wizard)";
            break;
        case 18:
            scroll += "Fire Shield (wizard)";
            break;
        case 19:
            scroll += "Grasping Vine (druid, ranger)";
            break;
        case 20:
            scroll += "Greater Invisibility (bard, sorcerer, wizard)";
            break;
        case 21:
            scroll += "Guardian of Faith (cleric)";
            break;
        case 22:
            scroll += "Hallucinatory Terrain (bard, druid, warlock, wizard)";
            break;
        case 23:
            scroll += "Ice Storm (druid, sorcerer, wizard)";
            break;
        case 24:
            scroll += "Leomund's Secret Chest (wizard)";
            break;
        case 25:
            scroll += "Locate Creature (bard, cleric, druid, paladin, ranger, wizard)";
            break;
        case 26:
            scroll += "Mordenkainen's Faithful Hound (wizard)";
            break;
        case 27:
            scroll += "Mordenkainen's Private Sanctum (wizard)";
            break;
        case 28:
            scroll += "Otiluke's Resilient Sphere (wizard)";
            break;
        case 29:
            scroll += "Phantasmal Killer (wizard)";
            break;
        case 30:
            scroll += "Polymorph (bard, sorcerer, wizard)";
            break;
        case 31:
            scroll += "Staggering Smite (paladin)";
            break;
        case 32:
            scroll += "Stone Shape (cleric, druid, wizard)";
            break;
        case 33:
            scroll += "Stoneskin (druid, ranger, sorcerer, wizard)";
            break;
        case 34:
            scroll += "Wall of Fire (druid, sorcerer, wizard)";
            break;
        }
        break;
    case 5:
        scroll = "Level 5 Scroll of ";
        ss = randomNumber(1, 42);
        switch (ss) {
        case 1:
            scroll += "Animate Objects (bard, sorcerer, wizard)";
            break;
        case 2:
            scroll += "Antilife Shell (druid)";
            break;
        case 3:
            scroll += "Awaken (bard, druid)";
            break;
        case 4:
            scroll += "Banishing Smite (paladin)";
            break;
        case 5:
            scroll += "Bigby's Hand (wizard)";
            break;
        case 6:
            scroll += "Circle of Power (paladin)";
            break;
        case 7:
            scroll += "Cloudkill (sorcerer, wizard)";
            break;
        case 8:
            scroll += "Commune (cleric)";
            break;
        case 9:
            scroll += "Commune with Nature (druid, ranger)";
            break;
        case 10:
            scroll += "Cone of Cold (sorcerer, wizard)";
            break;
        case 11:
            scroll += "Conjure ELemental (druid, wizard)";
            break;
        case 12:
            scroll += "Conjure Volley (ranger)";
            break;
        case 13:
            scroll += "Contact Other Plane (warlock, wizard)";
            break;
        case 14:
            scroll += "Contagion (cleric, druid)";
            break;
        case 15:
            scroll += "Creation (sorcerer, wizard)";
            break;
        case 16:
            scroll += "Destructive Smite (paladin)";
            break;
        case 17:
            scroll += "Dispel Evil and Good (cleric, paladin)";
            break;
        case 18:
            scroll += "Dominate Person (bard, sorcerer, wizard)";
            break;
        case 19:
            scroll += "Dream (bard, warlock, wizard)";
            break;
        case 20:
            scroll += "Flame Strike (cleric)";
            break;
        case 21:
            scroll += "Geas (bard, cleric, druid, paladin, wizard)";
            break;
        case 22:
            scroll += "Greater Restoration (bard, cleric, druid)";
            break;
        case 23:
            scroll += "Hallow (cleric)";
            break;
        case 24:
            scroll += "Hold Monster (bard, sorcerer, warlock, wizard)";
            break;
        case 25:
            scroll += "Insect Plague (cleric, druid, sorcerer)";
            break;
        case 26:
            scroll += "Legend Lore (bard, cleric, wizard)";
            break;
        case 27:
            scroll += "Mass Cure Wounds (bard, cleric)";
            break;
        case 28:
            scroll += "Mislead (bard, wizard)";
            break;
        case 29:
            scroll += "Modify Memory (bard, wizard)";
            break;
        case 30:
            scroll += "Passwall (wizard)";
            break;
        case 31:
            scroll += "Planar Binding (bard, cleric, druid, wizard)";
            break;
        case 32:
            scroll += "Raise Dead (bard, cleric, paladin)";
            break;
        case 33:
            scroll += "Rary's Telepathic Bond (wizard)";
            break;
        case 34:
            scroll += "Reincarnate (druid)";
            break;
        case 35:
            scroll += "Scrying (bard, cleric, druid, warlock, wizard)";
            break;
        case 36:
            scroll += "Seeming (bard, sorcerer, wizard)";
            break;
        case 37:
            scroll += "Swift Quiver (ranger)";
            break;
        case 38:
            scroll += "Telekinesis (sorcerer, wizard)";
            break;
        case 39:
            scroll += "Teleportation Circle (bard, sorcerer, wizard)";
            break;
        case 40:
            scroll += "Tree Stride (druid, ranger)";
            break;
        case 41:
            scroll += "Wall of Force (wizard)";
            break;
        case 42:
            scroll += "Wall of Stone (druid, sorcerer, wizard)";
            break;
        }
        break;
    case 6:
        scroll = "Level 6 Scroll of ";
        ss = randomNumber(1, 32);
        switch (ss) {
        case 1:
            scroll += "Arcane Gate (sorcerer, warlock, wizard)";
            break;
        case 2:
            scroll += "Blade Barrier (cleric)";
            break;
        case 3:
            scroll += "Chain Lightning (sorcerer, wizard)";
            break;
        case 4:
            scroll += "Circle of Death (sorcerer, warlock, wizard)";
            break;
        case 5:
            scroll += "Conjure Fey (druid, warlock)";
            break;
        case 6:
            scroll += "Contingency (wizard)";
            break;
        case 7:
            scroll += "Create Undead (cleric, warlock, wizard)";
            break;
        case 8:
            scroll += "Disintegrate (sorcerer, wizard)";
            break;
        case 9:
            scroll += "Drawmij's Instant Summons (wizard)";
            break;
        case 10:
            scroll += "Eyebit (bard, sorcerer, warlock, wizard)";
            break;
        case 11:
            scroll += "Find the Path (bard, cleric, druid)";
            break;
        case 12:
            scroll += "Flesh to Stone (warlock, wizard)";
            break;
        case 13:
            scroll += "Forbiddance (cleric)";
            break;
        case 14:
            scroll += "Globe of Invulnerability (sorcerer, wizard)";
            break;
        case 15:
            scroll += "Guards and Wards (bard, wizard)";
            break;
        case 16:
            scroll += "Harm (cleric)";
            break;
        case 17:
            scroll += "Heal (cleric, druid)";
            break;
        case 18:
            scroll += "Heroes' Feast (cleric, druid)";
            break;
        case 19:
            scroll += "Magic Jar (wizard)";
            break;
        case 20:
            scroll += "Mass Suggestion (bard, sorcerer, warlock, wizard)";
            break;
        case 21:
            scroll += "Move Earth (druid, sorcerer, wizard)";
            break;
        case 22:
            scroll += "Otiluke's Freezing Sphere (wizard)";
            break;
        case 23:
            scroll += "Otto's Irresistible Dance (bard, wizard)";
            break;
        case 24:
            scroll += "Planar Ally (cleric)";
            break;
        case 25:
            scroll += "Programmed Illusion (bard, wizard)";
            break;
        case 26:
            scroll += "Sunbeam (druid, sorcerer, wizard)";
            break;
        case 27:
            scroll += "Transport via Plants (druid)";
            break;
        case 28:
            scroll += "True Seeing (bard, cleric, sorcerer, warlock, wizard)";
            break;
        case 29:
            scroll += "Wall of Ice (wizard)";
            break;
        case 30:
            scroll += "Wall of Thorns (druid)";
            break;
        case 31:
            scroll += "Wind Walk (druid)";
            break;
        case 32:
            scroll += "Word of Recall (cleric)";
            break;
        }
        break;
    case 7:
        scroll = "Level 7 Scroll of ";
        ss = randomNumber(1, 20);
        switch (ss) {
        case 1:
            scroll += "Conjure Celestial (cleric)";
            break;
        case 2:
            scroll += "Delayed Blast Fireball (sorcerer, wizard)";
            break;
        case 3:
            scroll += "Divine Word (cleric)";
            break;
        case 4:
            scroll += "Etherealness (bard, cleric, sorcerer, wizard)";
            break;
        case 5:
            scroll += "Finger of Death (sorcerer, wizard)";
            break;
        case 6:
            scroll += "Fire Storm (cleric, druid, sorcerer)";
            break;
        case 7:
            scroll += "Forcecage (bard, wizard)";
            break;
        case 8:
            scroll += "Mirage Arcane (bard, druid, wizard)";
            break;
        case 9:
            scroll += "Mordenkainen's Magnificent Mansion (bard, wizard)";
            break;
        case 10:
            scroll += "Mordenkainen's Sword (bard, wizard)";
            break;
        case 11:
            scroll += "Plane Shift (cleric, druid, sorcerer, wizard)";
            break;
        case 12:
            scroll += "Prismatic Spray (sorcerer, wizard)";
            break;
        case 13:
            scroll += "Project Image (bard, wizard)";
            break;
        case 14:
            scroll += "Regenerate (bard, cleric, druid)";
            break;
        case 15:
            scroll += "Resurrection (bard, cleric)";
            break;
        case 16:
            scroll += "Reverse Gravity (druid, sorcerer, wizard)";
            break;
        case 17:
            scroll += "Sequester (wizard)";
            break;
        case 18:
            scroll += "Simulacrum (wizard)";
            break;
        case 19:
            scroll += "Symbol (bard, cleric, wizard)";
            break;
        case 20:
            scroll += "Teleport (bard, sorcerer, wizard)";
            break;
        }
        break;
    case 8:
        scroll = "Level 8 Scroll of ";
        ss = randomNumber(1, 19);
        switch (ss) {
        case 1:
            scroll += "Animal Shapes (druid)";
            break;
        case 2:
            scroll += "Antimagic Field (cleric, wizard)";
            break;
        case 3:
            scroll += "Antipathy/Sympathy (druid, wizard)";
            break;
        case 4:
            scroll += "Clone (wizard)";
            break;
        case 5:
            scroll += "Control Weather (cleric, druid, wizard)";
            break;
        case 6:
            scroll += "Demiplane (warlock, wizard)";
            break;
        case 7:
            scroll += "Dominate Monster (bard, sorcerer, warlock, wizard)";
            break;
        case 8:
            scroll += "Earthquake (cleric, druid, sorcerer)";
            break;
        case 9:
            scroll += "Feeblemind (bard, druid, warlock, wizard)";
            break;
        case 10:
            scroll += "Glibness (bard, warlock)";
            break;
        case 11:
            scroll += "Holy Aura (cleric)";
            break;
        case 12:
            scroll += "Incendiary Cloud (sorcerer, wizard)";
            break;
        case 13:
            scroll += "Maze (wizard)";
            break;
        case 14:
            scroll += "Mind Blank (bard, wizard)";
            break;
        case 15:
            scroll += "Power Word Stun (bard, sorcerer, warlock, wizard)";
            break;
        case 16:
            scroll += "Sunburst (druid, sorcerer, wizard)";
            break;
        case 17:
            scroll += "Telepathy (wizard)";
            break;
        case 18:
            scroll += "Trap the Soul (wizard)";
            break;
        case 19:
            scroll += "Tsunami (druid)";
            break;
        }
        break;
    case 9:
        scroll = "Level 9 Scroll of ";
        ss = randomNumber(1, 16);
        switch (ss) {
        case 1:
            scroll += "Astral Projection (cleric, warlock, wizard)";
            break;
        case 2:
            scroll += "Foresight (bard, druid, warlock, wizard)";
            break;
        case 3:
            scroll += "Gate (cleric, sorcerer, wizard)";
            break;
        case 4:
            scroll += "Imprisonment (warlock, wizard)";
            break;
        case 5:
            scroll += "Mass Heal (cleric)";
            break;
        case 6:
            scroll += "Meteor Swarm (sorcerer, wizard)";
            break;
        case 7:
            scroll += "Power Word Heal (bard)";
            break;
        case 8:
            scroll += "Power Word Kill (bard, sorcerer, warlock, wizard)";
            break;
        case 9:
            scroll += "Prismatic Wall (wizard)";
            break;
        case 10:
            scroll += "Shapechange (druid, wizard)";
            break;
        case 11:
            scroll += "Storm of Vengeance (druid)";
            break;
        case 12:
            scroll += "Time Stop (sorcerer, wizard)";
            break;
        case 13:
            scroll += "True Polymorph (bard, warlock, wizard)";
            break;
        case 14:
            scroll += "True Resurrection (cleric, druid)";
            break;
        case 15:
            scroll += "Weird (wizard)";
            break;
        case 16:
            scroll += "Wish (sorcerer, wizard)";
            break;
        }
        break;
    }
    return scroll;
}
void Magic_Items::SingleScroll(const int& lvl) const {
    int ss = 0;
    switch (lvl) {
    case 1:
        cout << "\n Level 1 Scroll of -> ";
        ss = randomNumber(1, 61);
        switch (ss) {
        case 1:
            cout << "Alarm (ranger, wizard)";
            break;
        case 2:
            cout << "Animal Friendship (bard, druid, ranger)";
            break;
        case 3:
            cout << "Armor of Agathys (warlock)";
            break;
        case 4:
            cout << "Arms of Hadar (warlock)";
            break;
        case 5:
            cout << "Bane (bard, cleric)";
            break;
        case 6:
            cout << "Bless (cleric, paladin)";
            break;
        case 7:
            cout << "Burning Hands (sorcerer, wizard)";
            break;
        case 8:
            cout << "Charm Person (bard, druid, sorcerer, warlock, wizard)";
            break;
        case 9:
            cout << "Color Spray (sorcerer, wizard)";
            break;
        case 10:
            cout << "Command (cleric, paladin)";
            break;
        case 11:
            cout << "Compelled Duel (paladin)";
            break;
        case 12:
            cout << "Comprehend Languages (bard, sorcerer, warlock, wizard)";
            break;
        case 13:
            cout << "Create or Destroy Water (cleric, druid)";
            break;
        case 14:
            cout << "Cure Wounds (bard, cleric, druid, paladin, ranger)";
            break;
        case 15:
            cout << "Detect Evil and Good (cleric, paladin)";
            break;
        case 16:
            cout << "Detect Magic (bard, cleric, druid, paladin, ranger, sorcerer, wizard)";
            break;
        case 17:
            cout << "Detect Poison and Disease (cleric, druid, paladin, ranger)";
            break;
        case 18:
            cout << "Disguise Self (bard, sorcerer, wizard)";
            break;
        case 19:
            cout << "Dissonant Whispers (bard)";
            break;
        case 20:
            cout << "Divine Favor (paladin)";
            break;
        case 21:
            cout << "Ensnaring Strike (ranger)";
            break;
        case 22:
            cout << "Entangle (druid)";
            break;
        case 23:
            cout << "Expeditious Retreat (sorcerer, warlock, wizard)";
            break;
        case 24:
            cout << "False Life (sorcerer, wizard)";
            break;
        case 25:
            cout << "Faerie Fire (bard, druid)";
            break;
        case 26:
            cout << "Feather Fall (bard, sorcerer, wizard)";
            break;
        case 27:
            cout << "Find Familiar (wizard)";
            break;
        case 28:
            cout << "Fog Cloud (druid, ranger, sorcerer, wizard)";
            break;
        case 29:
            cout << "Goodberry (druid, ranger)";
            break;
        case 30:
            cout << "Grease (wizard)";
            break;
        case 31:
            cout << "Guiding Bolt (cleric)";
            break;
        case 32:
            cout << "Hail of Thorns (ranger)";
            break;
        case 33:
            cout << "Healing Word (bard, cleric, druid)";
            break;
        case 34:
            cout << "Hellish Rebuke (warlock)";
            break;
        case 35:
            cout << "Heroism (bard, paladin)";
            break;
        case 36:
            cout << "Hex (warlock)";
            break;
        case 37:
            cout << "Hunter's Mark (ranger)";
            break;
        case 38:
            cout << "Identify (bard, wizard)";
            break;
        case 39:
            cout << "Illusory Script (bard, warlock, wizard)";
            break;
        case 40:
            cout << "Inflict Wounds (cleric)";
            break;
        case 41:
            cout << "Jump (druid, ranger, sorcerer, wizard)";
            break;
        case 42:
            cout << "Longstrider (bard, druid, ranger, wizard)";
            break;
        case 43:
            cout << "Mage Armor (sorcerer, wizard)";
            break;
        case 44:
            cout << "Magic Missile (sorcerer, wizard)";
            break;
        case 45:
            cout << "Protection from Evil and Good (cleric, paladin, warlock, wizard)";
            break;
        case 46:
            cout << "Purify Food and Drink (cleric, druid, paladin)";
            break;
        case 47:
            cout << "Ray of Sickness (sorcerer, wizard)";
            break;
        case 48:
            cout << "Searing Smite (paladin)";
            break;
        case 49:
            cout << "Sanctuary (cleric)";
            break;
        case 50:
            cout << "Shield (sorcerer, wizard)";
            break;
        case 51:
            cout << "Shield of Faith (cleric, paladin)";
            break;
        case 52:
            cout << "Silent Image (bard, sorcerer, wizard)";
            break;
        case 53:
            cout << "Sleep (bard, sorcerer, wizard)";
            break;
        case 54:
            cout << "Speak with Animals (bard, druid, ranger)";
            break;
        case 55:
            cout << "Tasha's Hideous Laughter (bard, wizard)";
            break;
        case 56:
            cout << "Tensor's Floating Disk (wizard)";
            break;
        case 57:
            cout << "Thunderous Smite (paladin)";
            break;
        case 58:
            cout << "Thunderwave (bard, druid, sorcerer, wizard)";
            break;
        case 59:
            cout << "Unseen Servant (bard, warlock, wizard)";
            break;
        case 60:
            cout << "Witch Bolt (sorcerer, warlock, wizard)";
            break;
        case 61:
            cout << "Wrathful Smite (paladin)";
            break;
        }
        cout << endl;
        break;
    case 2:
        cout << "\n Level 2 Scroll of -> ";
        ss = randomNumber(1, 59);
        switch (ss) {
        case 1:
            cout << "Aid (cleric, paladin)";
            break;
        case 2:
            cout << "Alter Self (sorcerer, wizard)";
            break;
        case 3:
            cout << "Animal Messenger (bard, druid, ranger)";
            break;
        case 4:
            cout << "Arcane Lock (wizard)";
            break;
        case 5:
            cout << "Augury (cleric)";
            break;
        case 6:
            cout << "Barkskin (druid, ranger)";
            break;
        case 7:
            cout << "Beast Sense (druid, ranger)";
            break;
        case 8:
            cout << "Blindness/Deafness (bard, cleric, sorcerer, wizard)";
            break;
        case 9:
            cout << "Blur (sorcerer, wizard)";
            break;
        case 10:
            cout << "Branding Smite (paladin)";
            break;
        case 11:
            cout << "Calm Emotions (bard, cleric)";
            break;
        case 12:
            cout << "Cloud of Daggers (bard, sorcerer, warlock, wizard)";
            break;
        case 13:
            cout << "Continual Flame (cleric, wizard)";
            break;
        case 14:
            cout << "Cordon of Arrows (ranger)";
            break;
        case 15:
            cout << "Crown of Madness (bard, sorcerer, warlock, wizard)";
            break;
        case 16:
            cout << "Darkness (sorcerer, warlock, wizard)";
            break;
        case 17:
            cout << "Darkvision (druid, ranger, sorcerer, wizard)";
            break;
        case 18:
            cout << "Detect Thoughts (bard, sorcerer, wizard)";
            break;
        case 19:
            cout << "Enhance Ability (bard, cleric, druid, sorcerer)";
            break;
        case 20:
            cout << "Enlarge/Reduce (sorcerer, wizard)";
            break;
        case 21:
            cout << "Enthrall (bard, warlock)";
            break;
        case 22:
            cout << "Find Steed (paladin)";
            break;
        case 23:
            cout << "Find Traps (cleric, druid, ranger)";
            break;
        case 24:
            cout << "Flame Blade (druid)";
            break;
        case 25:
            cout << "Flaming Sphere (druid, wizard)";
            break;
        case 26:
            cout << "Heat Metal (bard, druid)";
            break;
        case 27:
            cout << "Hold Person (bard, druid, sorcerer, warlock)";
            break;
        case 28:
            cout << "Gentle Repose (cleric)";
            break;
        case 29:
            cout << "Gust of Wind (druid, sorcerer)";
            break;
        case 30:
            cout << "Invisibility (bard, sorcerer, warlock, wizard)";
            break;
        case 31:
            cout << "Knock (bard, sorcerer, wizard)";
            break;
        case 32:
            cout << "Lesser Restoration (bard, cleric, druid, paladin, ranger)";
            break;
        case 33:
            cout << "Levitate (sorcerer, wizard)";
            break;
        case 34:
            cout << "Locate Animals or Plants (bard, druid, ranger)";
            break;
        case 35:
            cout << "Locate Object (bard, cleric, druid, paladin, ranger, wizard)";
            break;
        case 36:
            cout << "Magic Mouth (bard, wizard)";
            break;
        case 37:
            cout << "Magic Weapon (paladin, wizard)";
            break;
        case 38:
            cout << "Melf's Acid Arrow (wizard)";
            break;
        case 39:
            cout << "Mirror Image (sorcerer, warlock, wizard)";
            break;
        case 40:
            cout << "Misty Step (sorcerer, warlock, wizard)";
            break;
        case 41:
            cout << "Moonbeam (druid)";
            break;
        case 42:
            cout << "Nystul's Magic Aura (wizard)";
            break;
        case 43:
            cout << "Pass without Trace (druid, ranger)";
            break;
        case 44:
            cout << "Phantasmal Force (bard, sorcerer, wizard)";
            break;
        case 45:
            cout << "Prayer of Healing (cleric)";
            break;
        case 46:
            cout << "Protection of Poison (cleric, druid, poison, ranger)";
            break;
        case 47:
            cout << "Ray of Enfeeblement (warlock, wizard)";
            break;
        case 48:
            cout << "Rope Trick (wizard)";
            break;
        case 49:
            cout << "Scorching Ray (sorcerer, wizard)";
            break;
        case 50:
            cout << "See Invisibility (bard, sorcerer, wizard)";
            break;
        case 51:
            cout << "Silence (bard, cleric, ranger)";
            break;
        case 52:
            cout << "Silent Image (bard, sorcerer, wizard)";
            break;
        case 53:
            cout << "Spider Climb (sorcerer, warlock, wizard)";
            break;
        case 54:
            cout << "Spike Growth (druid, ranger)";
            break;
        case 55:
            cout << "Spiritual Weapon (cleric)";
            break;
        case 56:
            cout << "Suggestion (bard, sorcerer, warlock, wizard)";
            break;
        case 57:
            cout << "Warding Bond (cleric)";
            break;
        case 58:
            cout << "Web (sorcerer, wizard)";
            break;
        case 59:
            cout << "Zone of Truth (bard, cleric, paladin)";
            break;
        }
        cout << endl;
        break;
    case 3:
        cout << "\n Level 3 Scroll of -> ";
        ss = randomNumber(1, 50);
        switch (ss) {
        case 1:
            cout << "Animate Dead (cleric, wizard)";
            break;
        case 2:
            cout << "Aura of Vitality (paladin)";
            break;
        case 3:
            cout << "Beacon of Hope (cleric)";
            break;
        case 4:
            cout << "Bestow Curse (bard, cleric, wizard)";
            break;
        case 5:
            cout << "Blinding Smite (paladin)";
            break;
        case 6:
            cout << "Blink (sorcerer, wizard)";
            break;
        case 7:
            cout << "Call Lightning (druid)";
            break;
        case 8:
            cout << "Clairvoyance (bard, cleric, sorcerer, wizard)";
            break;
        case 9:
            cout << "Conjure Animals (druid, ranger)";
            break;
        case 10:
            cout << "Conjure Barrage (ranger)";
            break;
        case 11:
            cout << "Counterspell (sorcerer, warlock, wizard)";
            break;
        case 12:
            cout << "Create Food and Water (cleric, paladin)";
            break;
        case 13:
            cout << "Crusader's Mantle (paladin)";
            break;
        case 14:
            cout << "Daylight (cleric, druid, paladin, ranger, sorcerer)";
            break;
        case 15:
            cout << "Dispel Magic (bard, cleric, druid, paladin, sorcerer, warlock, wizard)";
            break;
        case 16:
            cout << "Elemental Weapon (paladin)";
            break;
        case 17:
            cout << "Fear (bard, sorcerer, warlock, wizard)";
            break;
        case 18:
            cout << "Feign Death (bard, cleric, druid, wizard)";
            break;
        case 19:
            cout << "Fireball (sorcerer, wizard)";
            break;
        case 20:
            cout << "Fly (sorcerer, warlock)";
            break;
        case 21:
            cout << "Gaseous Form (sorcerer, warlock, wizard)";
            break;
        case 22:
            cout << "Glyph of Warding (bard, cleric, wizard)";
            break;
        case 23:
            cout << "Haste (sorcerer, wizard)";
            break;
        case 24:
            cout << "Hunger of Hadar (warlock)";
            break;
        case 25:
            cout << "Hypnotic Pattern (bard, sorcerer, warlock, wizard)";
            break;
        case 26:
            cout << "Leomund's Tiny Hut (bard, wizard)";
            break;
        case 27:
            cout << "Lightning Arrow (ranger)";
            break;
        case 28:
            cout << "Lightning Bolt (sorcerer, wizard)";
            break;
        case 29:
            cout << "Magic Circle (cleric, paladin, warlock, wizard)";
            break;
        case 30:
            cout << "Major Image (bard, sorcerer, warlock, wizard)";
            break;
        case 31:
            cout << "Mass Healing Word (cleric)";
            break;
        case 32:
            cout << "Meld Into Stone (cleric, druid)";
            break;
        case 33:
            cout << "Nondetection (bard, ranger, wizard)";
            break;
        case 34:
            cout << "Phantom Steed (wizard)";
            break;
        case 35:
            cout << "Plant Growth (bard, druid, ranger)";
            break;
        case 36:
            cout << "Protection from Energy (cleric, druid, ranger, sorcerer, wizard)";
            break;
        case 37:
            cout << "Remove Curse (cleric, paladin, warlock)";
            break;
        case 38:
            cout << "Revivify (cleric, paladin)";
            break;
        case 39:
            cout << "Sending (bard, cleric, wizard)";
            break;
        case 40:
            cout << "Sleet Storm (druid, sorcerer, wizard)";
            break;
        case 41:
            cout << "Slow (sorcerer, wizard)";
            break;
        case 42:
            cout << "Speak with Dead (bard, cleric)";
            break;
        case 43:
            cout << "Speak with Plants (bard, druid, ranger)";
            break;
        case 44:
            cout << "Spirit Guardians (cleric)";
            break;
        case 45:
            cout << "Stinking Cloud (bard, sorcerer, wizard)";
            break;
        case 46:
            cout << "Tongues (bard, cleric, sorcerer, warlock, wizard)";
            break;
        case 47:
            cout << "Vampiric Touch (warlock, wizard)";
            break;
        case 48:
            cout << "Water Breathing (druid, ranger, sorcerer, wizard)";
            break;
        case 49:
            cout << "Water Walk (cleric, druid, ranger, sorcerer)";
            break;
        case 50:
            cout << "Wind Wall (druid, ranger)";
            break;
        }
        cout << endl;
        break;
    case 4:
        cout << "\n Level 4 Scroll of -> ";
        ss = randomNumber(1, 34);
        switch (ss) {
        case 1:
            cout << "Aura of Life (paladin)";
            break;
        case 2:
            cout << "Aura of Purify (paladin)";
            break;
        case 3:
            cout << "Arcane Eye (wizard)";
            break;
        case 4:
            cout << "Banishment (cleric, paladin, sorcerer, warlock, wizard)";
            break;
        case 5:
            cout << "Blight (druid, sorcerer, warlock, wizard)";
            break;
        case 6:
            cout << "Compulsion (bard)";
            break;
        case 7:
            cout << "Confusion (bard, druid, sorcerer, wizard)";
            break;
        case 8:
            cout << "Conjure Minor Elementals (druid, wizard)";
            break;
        case 9:
            cout << "Conjure Woodland Beings (druid, ranger)";
            break;
        case 10:
            cout << "Control Water (druid, wizard)";
            break;
        case 11:
            cout << "Control Weather (cleric)";
            break;
        case 12:
            cout << "Death Ward (cleric)";
            break;
        case 13:
            cout << "Dimension Door (bard, warlock, wizard)";
            break;
        case 14:
            cout << "Divination (cleric)";
            break;
        case 15:
            cout << "Dominate Beast (druid, sorcerer)";
            break;
        case 16:
            cout << "Evard's Black Tentacles (wizard)";
            break;
        case 17:
            cout << "Fabricate (wizard)";
            break;
        case 18:
            cout << "Fire Shield (wizard)";
            break;
        case 19:
            cout << "Grasping Vine (druid, ranger)";
            break;
        case 20:
            cout << "Greater Invisibility (bard, sorcerer, wizard)";
            break;
        case 21:
            cout << "Guardian of Faith (cleric)";
            break;
        case 22:
            cout << "Hallucinatory Terrain (bard, druid, warlock, wizard)";
            break;
        case 23:
            cout << "Ice Storm (druid, sorcerer, wizard)";
            break;
        case 24:
            cout << "Leomund's Secret Chest (wizard)";
            break;
        case 25:
            cout << "Locate Creature (bard, cleric, druid, paladin, ranger, wizard)";
            break;
        case 26:
            cout << "Mordenkainen's Faithful Hound (wizard)";
            break;
        case 27:
            cout << "Mordenkainen's Private Sanctum (wizard)";
            break;
        case 28:
            cout << "Otiluke's Resilient Sphere (wizard)";
            break;
        case 29:
            cout << "Phantasmal Killer (wizard)";
            break;
        case 30:
            cout << "Polymorph (bard, sorcerer, wizard)";
            break;
        case 31:
            cout << "Staggering Smite (paladin)";
            break;
        case 32:
            cout << "Stone Shape (cleric, druid, wizard)";
            break;
        case 33:
            cout << "Stoneskin (druid, ranger, sorcerer, wizard)";
            break;
        case 34:
            cout << "Wall of Fire (druid, sorcerer, wizard)";
            break;
        }
        cout << endl;
        break;
    case 5:
        cout << "\n Level 5 Scroll of -> ";
        ss = randomNumber(1, 42);
        switch (ss) {
        case 1:
            cout << "Animate Objects (bard, sorcerer, wizard)";
            break;
        case 2:
            cout << "Antilife Shell (druid)";
            break;
        case 3:
            cout << "Awaken (bard, druid)";
            break;
        case 4:
            cout << "Banishing Smite (paladin)";
            break;
        case 5:
            cout << "Bigby's Hand (wizard)";
            break;
        case 6:
            cout << "Circle of Power (paladin)";
            break;
        case 7:
            cout << "Cloudkill (sorcerer, wizard)";
            break;
        case 8:
            cout << "Commune (cleric)";
            break;
        case 9:
            cout << "Commune with Nature (druid, ranger)";
            break;
        case 10:
            cout << "Cone of Cold (sorcerer, wizard)";
            break;
        case 11:
            cout << "Conjure ELemental (druid, wizard)";
            break;
        case 12:
            cout << "Conjure Volley (ranger)";
            break;
        case 13:
            cout << "Contact Other Plane (warlock, wizard)";
            break;
        case 14:
            cout << "Contagion (cleric, druid)";
            break;
        case 15:
            cout << "Creation (sorcerer, wizard)";
            break;
        case 16:
            cout << "Destructive Smite (paladin)";
            break;
        case 17:
            cout << "Dispel Evil and Good (cleric, paladin)";
            break;
        case 18:
            cout << "Dominate Person (bard, sorcerer, wizard)";
            break;
        case 19:
            cout << "Dream (bard, warlock, wizard)";
            break;
        case 20:
            cout << "Flame Strike (cleric)";
            break;
        case 21:
            cout << "Geas (bard, cleric, druid, paladin, wizard)";
            break;
        case 22:
            cout << "Greater Restoration (bard, cleric, druid)";
            break;
        case 23:
            cout << "Hallow (cleric)";
            break;
        case 24:
            cout << "Hold Monster (bard, sorcerer, warlock, wizard)";
            break;
        case 25:
            cout << "Insect Plague (cleric, druid, sorcerer)";
            break;
        case 26:
            cout << "Legend Lore (bard, cleric, wizard)";
            break;
        case 27:
            cout << "Mass Cure Wounds (bard, cleric)";
            break;
        case 28:
            cout << "Mislead (bard, wizard)";
            break;
        case 29:
            cout << "Modify Memory (bard, wizard)";
            break;
        case 30:
            cout << "Passwall (wizard)";
            break;
        case 31:
            cout << "Planar Binding (bard, cleric, druid, wizard)";
            break;
        case 32:
            cout << "Raise Dead (bard, cleric, paladin)";
            break;
        case 33:
            cout << "Rary's Telepathic Bond (wizard)";
            break;
        case 34:
            cout << "Reincarnate (druid)";
            break;
        case 35:
            cout << "Scrying (bard, cleric, druid, warlock, wizard)";
            break;
        case 36:
            cout << "Seeming (bard, sorcerer, wizard)";
            break;
        case 37:
            cout << "Swift Quiver (ranger)";
            break;
        case 38:
            cout << "Telekinesis (sorcerer, wizard)";
            break;
        case 39:
            cout << "Teleportation Circle (bard, sorcerer, wizard)";
            break;
        case 40:
            cout << "Tree Stride (druid, ranger)";
            break;
        case 41:
            cout << "Wall of Force (wizard)";
            break;
        case 42:
            cout << "Wall of Stone (druid, sorcerer, wizard)";
            break;
        }
        cout << endl;
        break;
    case 6:
        cout << "\n Level 6 Scroll of -> ";
        ss = randomNumber(1, 32);
        switch (ss) {
        case 1:
            cout << "Arcane Gate (sorcerer, warlock, wizard)";
            break;
        case 2:
            cout << "Blade Barrier (cleric)";
            break;
        case 3:
            cout << "Chain Lightning (sorcerer, wizard)";
            break;
        case 4:
            cout << "Circle of Death (sorcerer, warlock, wizard)";
            break;
        case 5:
            cout << "Conjure Fey (druid, warlock)";
            break;
        case 6:
            cout << "Contingency (wizard)";
            break;
        case 7:
            cout << "Create Undead (cleric, warlock, wizard)";
            break;
        case 8:
            cout << "Disintegrate (sorcerer, wizard)";
            break;
        case 9:
            cout << "Drawmij's Instant Summons (wizard)";
            break;
        case 10:
            cout << "Eyebite (bard, sorcerer, warlock, wizard)";
            break;
        case 11:
            cout << "Find the Path (bard, cleric, druid)";
            break;
        case 12:
            cout << "Flesh to Stone (warlock, wizard)";
            break;
        case 13:
            cout << "Forbiddance (cleric)";
            break;
        case 14:
            cout << "Globe of Invulnerability (sorcerer, wizard)";
            break;
        case 15:
            cout << "Guards and Wards (bard, wizard)";
            break;
        case 16:
            cout << "Harm (cleric)";
            break;
        case 17:
            cout << "Heal (cleric, druid)";
            break;
        case 18:
            cout << "Heroes' Feast (cleric, druid)";
            break;
        case 19:
            cout << "Magic Jar (wizard)";
            break;
        case 20:
            cout << "Mass Suggestion (bard, sorcerer, warlock, wizard)";
            break;
        case 21:
            cout << "Move Earth (druid, sorcerer, wizard)";
            break;
        case 22:
            cout << "Otiluke's Freezing Sphere (wizard)";
            break;
        case 23:
            cout << "Otto's Irresistible Dance (bard, wizard)";
            break;
        case 24:
            cout << "Planar Ally (cleric)";
            break;
        case 25:
            cout << "Programmed Illusion (bard, wizard)";
            break;
        case 26:
            cout << "Sunbeam (druid, sorcerer, wizard)";
            break;
        case 27:
            cout << "Transport via Plants (druid)";
            break;
        case 28:
            cout << "True Seeing (bard, cleric, sorcerer, warlock, wizard)";
            break;
        case 29:
            cout << "Wall of Ice (wizard)";
            break;
        case 30:
            cout << "Wall of Thorns (druid)";
            break;
        case 31:
            cout << "Wind Walk (druid)";
            break;
        case 32:
            cout << "Word of Recall (cleric)";
            break;
        }
        cout << endl;
        break;
    case 7:
        cout << "\n Level 7 Scroll of -> ";
        ss = randomNumber(1, 20);
        switch (ss) {
        case 1:
            cout << "Conjure Celestial (cleric)";
            break;
        case 2:
            cout << "Delayed Blast Fireball (sorcerer, wizard)";
            break;
        case 3:
            cout << "Divine Word (cleric)";
            break;
        case 4:
            cout << "Etherealness (bard, cleric, sorcerer, wizard)";
            break;
        case 5:
            cout << "Finger of Death (sorcerer, wizard)";
            break;
        case 6:
            cout << "Fire Storm (cleric, druid, sorcerer)";
            break;
        case 7:
            cout << "Forcecage (bard, wizard)";
            break;
        case 8:
            cout << "Mirage Arcane (bard, druid, wizard)";
            break;
        case 9:
            cout << "Mordenkainen's Magnificent Mansion (bard, wizard)";
            break;
        case 10:
            cout << "Mordenkainen's Sword (bard, wizard)";
            break;
        case 11:
            cout << "Plane Shift (cleric, druid, sorcerer, wizard)";
            break;
        case 12:
            cout << "Prismatic Spray (sorcerer, wizard)";
            break;
        case 13:
            cout << "Project Image (bard, wizard)";
            break;
        case 14:
            cout << "Regenerate (bard, cleric, druid)";
            break;
        case 15:
            cout << "Resurrection (bard, cleric)";
            break;
        case 16:
            cout << "Reverse Gravity (druid, sorcerer, wizard)";
            break;
        case 17:
            cout << "Sequester (wizard)";
            break;
        case 18:
            cout << "Simulacrum (wizard)";
            break;
        case 19:
            cout << "Symbol (bard, cleric, wizard)";
            break;
        case 20:
            cout << "Teleport (bard, sorcerer, wizard)";
            break;
        }
        cout << endl;
        break;
    case 8:
        cout << "\n Level 8 Scroll of -> ";
        ss = randomNumber(1, 19);
        switch (ss) {
        case 1:
            cout << "Animal Shapes (druid)";
            break;
        case 2:
            cout << "Antimagic Field (cleric, wizard)";
            break;
        case 3:
            cout << "Antipathy/Sympathy (druid, wizard)";
            break;
        case 4:
            cout << "Clone (wizard)";
            break;
        case 5:
            cout << "Control Weather (cleric, druid, wizard)";
            break;
        case 6:
            cout << "Demiplane (warlock, wizard)";
            break;
        case 7:
            cout << "Dominate Monster (bard, sorcerer, warlock, wizard)";
            break;
        case 8:
            cout << "Earthquake (cleric, druid, sorcerer)";
            break;
        case 9:
            cout << "Feeblemind (bard, druid, warlock, wizard)";
            break;
        case 10:
            cout << "Glibness (bard, warlock)";
            break;
        case 11:
            cout << "Holy Aura (cleric)";
            break;
        case 12:
            cout << "Incendiary Cloud (sorcerer, wizard)";
            break;
        case 13:
            cout << "Maze (wizard)";
            break;
        case 14:
            cout << "Mind Blank (bard, wizard)";
            break;
        case 15:
            cout << "Power Word Stun (bard, sorcerer, warlock, wizard)";
            break;
        case 16:
            cout << "Sunburst (druid, sorcerer, wizard)";
            break;
        case 17:
            cout << "Telepathy (wizard)";
            break;
        case 18:
            cout << "Trap the Soul (wizard)";
            break;
        case 19:
            cout << "Tsunami (druid)";
            break;
        }
        cout << endl;
        break;
    case 9:
        cout << "\n Level 9 Scroll of -> ";
        ss = randomNumber(1, 16);
        switch (ss) {
        case 1:
            cout << "Astral Projection (cleric, warlock, wizard)";
            break;
        case 2:
            cout << "Foresight (bard, druid, warlock, wizard)";
            break;
        case 3:
            cout << "Gate (cleric, sorcerer, wizard)";
            break;
        case 4:
            cout << "Imprisonment (warlock, wizard)";
            break;
        case 5:
            cout << "Mass Heal (cleric)";
            break;
        case 6:
            cout << "Meteor Swarm (sorcerer, wizard)";
            break;
        case 7:
            cout << "Power Word Heal (bard)";
            break;
        case 8:
            cout << "Power Word Kill (bard, sorcerer, warlock, wizard)";
            break;
        case 9:
            cout << "Prismatic Wall (wizard)";
            break;
        case 10:
            cout << "Shapechange (druid, wizard)";
            break;
        case 11:
            cout << "Storm of Vengeance (druid)";
            break;
        case 12:
            cout << "Time Stop (sorcerer, wizard)";
            break;
        case 13:
            cout << "True Polymorph (bard, warlock, wizard)";
            break;
        case 14:
            cout << "True Resurrection (cleric, druid)";
            break;
        case 15:
            cout << "Weird (wizard)";
            break;
        case 16:
            cout << "Wish (sorcerer, wizard)";
            break;
        }
        cout << endl;
        break;
    }
}
string Magic_Items::GenerateGemstone(const int& amount, const int& value) const {
    string gemstring = "error: check code or gemfile";
    ifstream fileOfGems;
    fileOfGems.open("./settings/gems.dat");
    if (fileOfGems.is_open()) {
        string tmpName = "";
        bool setvalue = false;
        auto chosenSeed = 0;
        for (int i = 0; i < amount; i++) {  //go down into file appropriate amount
            if (value == 10) {
                chosenSeed = randomNumber(0, 11);
                if (!setvalue) {
                    fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else if (value == 50) {
                chosenSeed = randomNumber(0, 16);
                if (!setvalue) {
                    for (int j = 0; j < 3; j++) {
                        fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (value == 100) {
                chosenSeed = randomNumber(0, 15);
                if (!setvalue) {
                    for (int j = 0; j < 5; j++) {
                        fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (value == 500) {
                chosenSeed = randomNumber(0, 5);
                if (!setvalue) {
                    for (int j = 0; j < 7; j++) {
                        fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (value == 1000) {
                chosenSeed = randomNumber(0, 9);
                if (!setvalue) {
                    for (int j = 0; j < 9; j++) {
                        fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (value == 5000) {
                chosenSeed = randomNumber(0, 6);
                if (!setvalue) {
                    for (int j = 0; j < 11; j++) {
                        fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            }

            setvalue = true;
            int len = fileOfGems.tellg();   //get current position - snapshot of place in file
            for (auto i = 0; i < chosenSeed; i++) { //go over to the proper gem rolled based on seed
                fileOfGems.ignore(numeric_limits<streamsize>::max(), ';');
            }
            getline(fileOfGems, tmpName, ';');
            fileOfGems.seekg(len, ios_base::beg);  //return to position - return to snapshot of place in file
            if (i == 0) {           //very first gem case
                gemstring = toString(value) + "gp Gems:" + tmpName;
            } else { 
                size_t find_position = gemstring.find(tmpName + ",");
				if (find_position != string::npos) { //found first duplicate gemname on the list - not last item either
					gemstring.insert(find_position+tmpName.size(), " x2");
                } else {
					find_position = gemstring.find(tmpName);
					if (find_position == string::npos) {
						gemstring += ("," + tmpName); //add the new gem
					} else {
						if (gemstring.substr(find_position, tmpName.length()+3) == tmpName) {
							gemstring.insert(find_position+tmpName.length(), " x2");
						} else {
							size_t gotx2 = gemstring.find(tmpName + " x2");
							if (gotx2 != string::npos) {   //if x2 exists
								gemstring.replace(gotx2+tmpName.size(), 3, " x3");
							} else {
								size_t gotx3 = gemstring.find(tmpName + " x3");
								if (gotx3 != string::npos) {  //if x3 exists
									gemstring.replace(gotx3+tmpName.size(), 3, " x4");
								} else {
									size_t gotx4 = gemstring.find(tmpName + " x4");
									if (gotx4 != string::npos) { //if x4 exists
										gemstring.replace(gotx4+tmpName.size(), 3, " x5");
									} else {
										gemstring.insert(find_position+tmpName.size(), " x2");
									}
								}
							}
						}
					}
				}
            }
        }
    }
    return gemstring;
}


string Magic_Items::GenerateArt(const int& amount, const int& value) const {
    string artstring = "error: check code or artfile";
    ifstream fileOfArt;
    fileOfArt.open("./settings/artObjects.dat");
    if (fileOfArt.is_open()) {
        string tmpName = "";
        bool setvalue = false;
        auto chosenSeed = 0;
        for (int i = 0; i < amount; i++) {  //go down into file appropriate amount and choose a proper seed
                if (value == 25) {
                    chosenSeed = randomNumber(0, 9);
                    if (!setvalue) {
                        fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else if (value == 250) {
                    chosenSeed = randomNumber(0, 9);
                    if (!setvalue) {
                        for (int j = 0; j < 3; j++) {
                            fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } else if (value == 750) {
                    chosenSeed = randomNumber(0, 9);
                    if (!setvalue) {
                        for (int j = 0; j < 5; j++) {
                            fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } else if (value == 2500) {
                    chosenSeed = randomNumber(0, 9);
                    if (!setvalue) {
                        for (int j = 0; j < 7; j++) {
                            fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } else if (value == 7500) {
                    chosenSeed = randomNumber(0, 7);
                    if (!setvalue) {
                        for (int j = 0; j < 9; j++) {
                            fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                }
            setvalue = true;
            int len = fileOfArt.tellg();   //get current position  //snapshot of place in file
            for (auto i = 0; i < chosenSeed; i++) { //go over to the proper Art rolled
                fileOfArt.ignore(numeric_limits<streamsize>::max(), ';');
            }
            getline(fileOfArt, tmpName, ';');
            fileOfArt.seekg(len, ios_base::beg);  //return to position//return to snapshot of place in file
            if (i == 0) {  //first time through
                artstring = (toString(value) + "gp Art Objects:" + tmpName);
            } else { 
                size_t find_position = artstring.find(tmpName + ",");
				if (find_position != string::npos) { //found first duplicate Artname on the list - not last item either
					artstring.insert(find_position+tmpName.size(), " x2");
                } else {
					find_position = artstring.find(tmpName);
					if (find_position == string::npos) {
						artstring += ("," + tmpName); //add the new Art
					} else {
						if (artstring.substr(find_position, tmpName.length()+3) == tmpName) {
							artstring.insert(find_position+tmpName.length(), " x2");
						} else {
							size_t gotx2 = artstring.find(tmpName + " x2");
							if (gotx2 != string::npos) {   //if x2 exists
								artstring.replace(gotx2+tmpName.size(), 3, " x3");
							} else {
								size_t gotx3 = artstring.find(tmpName + " x3");
								if (gotx3 != string::npos) {  //if x3 exists
									artstring.replace(gotx3+tmpName.size(), 3, " x4");
								} else {
									size_t gotx4 = artstring.find(tmpName + " x4");
									if (gotx4 != string::npos) { //if x4 exists
										artstring.replace(gotx4+tmpName.size(), 3, " x5");
									} else {
										artstring.insert(find_position+tmpName.size(), " x2");
									}
								}
							}
						}
					}
				}
			}
		}
	}
    return artstring;
}

float Magic_Items::xpgenerator() {
    float xp = 0;
    int cr = 0;
    vector<string> crlist;
    char ans;
    cout << "A Reference Level Chart (FYI):\n\n"
         << " 2. 300\n"
         << " 3. 900\n"
         << " 4. 2,700\n"
         << " 5. 6,500\n"
         << " 6. 14,000\n"
         << " 7. 23,000\n"
         << " 8. 34,000\n"
         << " 9. 48,000\n"
         << "10. 64,000\n"
         << "11. 85,000\n"
         << "12. 100,000\n"
         << "13. 120,000\n"
         << "14. 140,000\n"
         << "15. 165,000\n"
         << "16. 195,000\n"
         << "17. 225,000\n"
         << "18. 265,000\n"
         << "19. 305,000\n"
         << "20. 355,000\n" << endl;
    pressEnterToContinue();
    do {
        cout << "Challenge Rating Chart\n\n"
             << " 1. CR 0      18. CR 14\n"
             << " 2. CR 1/8    19. CR 15\n"
             << " 3. CR 1/4    20. CR 16\n"
             << " 4. CR 1/2    21. CR 17\n"
             << " 5. CR 1      22. CR 18\n"
             << " 6. CR 2      23. CR 19\n"
             << " 7. CR 3      24. CR 20\n"
             << " 8. CR 4      25. CR 21\n"
             << " 9. CR 5      26. CR 22\n"
             << "10. CR 6      27. CR 23\n"
             << "11. CR 7      28. CR 24\n"
             << "12. CR 8      29. CR 25\n"
             << "13. CR 9      30. CR 26\n"
             << "14. CR 10     31. CR 27\n"
             << "15. CR 11     32. CR 28\n"
             << "16. CR 12     33. CR 29\n"
             << "17. CR 13     34. CR 30\n\n"
             << " tip: add 'y' after your choice to continue picking.(ex: 9y)\n"
             << "CRs so far: ";
        for (auto i : crlist) {
            cout << i << ", ";
        }
        cout << endl;
        cr = getNumber("Choose CR by the chart(1-34): ", 1, 34);
        switch (cr) {
        case 1:
            xp += 10;
            crlist.push_back("0");
            break;
        case 2:
            xp += 25;
            crlist.push_back("1/8");
            break;
        case 3:
            xp += 50;
            crlist.push_back("1/4");
            break;
        case 4:
            xp += 100;
            crlist.push_back("1/2");
            break;
        case 5:
            xp += 200;
            crlist.push_back("1");
            break;
        case 6:
            xp += 450;
            crlist.push_back("2");
            break;
        case 7:
            xp += 700;
            crlist.push_back("3");
            break;
        case 8:
            xp += 1100;
            crlist.push_back("4");
            break;
        case 9:
            xp += 1800;
            crlist.push_back("5");
            break;
        case 10:
            xp += 2300;
            crlist.push_back("6");
            break;
        case 11:
            xp += 2900;
            crlist.push_back("7");
            break;
        case 12:
            xp += 3900;
            crlist.push_back("8");
            break;
        case 13:
            xp += 5000;
            crlist.push_back("9");
            break;
        case 14:
            xp += 5900;
            crlist.push_back("10");
            break;
        case 15:
            xp += 7200;
            crlist.push_back("11");
            break;
        case 16:
            xp += 8400;
            crlist.push_back("12");
            break;
        case 17:
            xp += 10000;
            crlist.push_back("13");
            break;
        case 18:
            xp += 11500;
            crlist.push_back("14");
            break;
        case 19:
            xp += 13000;
            crlist.push_back("15");
            break;
        case 20:
            xp += 15000;
            crlist.push_back("16");
            break;
        case 21:
            xp += 18000;
            crlist.push_back("17");
            break;
        case 22:
            xp += 20000;
            crlist.push_back("18");
            break;
        case 23:
            xp += 22000;
            crlist.push_back("19");
            break;
        case 24:
            xp += 25000;
            crlist.push_back("20");
            break;
        case 25:
            xp += 33000;
            crlist.push_back("21");
            break;
        case 26:
            xp += 41000;
            crlist.push_back("22");
            break;
        case 27:
            xp += 50000;
            crlist.push_back("23");
            break;
        case 28:
            xp += 62000;
            crlist.push_back("24");
            break;
        case 29:
            xp += 75000;
            crlist.push_back("25");
            break;
        case 30:
            xp += 90000;
            crlist.push_back("26");
            break;
        case 31:
            xp += 105000;
            crlist.push_back("27");
            break;
        case 32:
            xp += 120000;
            crlist.push_back("28");
            break;
        case 33:
            xp += 135000;
            crlist.push_back("29");
            break;
        case 34:
            xp += 155000;
            crlist.push_back("30");
        default:break;
        }
        cout << "Total unsplit so far: " << xp << "xp" << endl;
        ans = getYorN("Are there more to add(Y/N)?");
    } while (ans == 'Y');
    int party = getNumber("Split between how many party members?(max=20)", 1, 20);
    return (xp /= party);
}

void Magic_Items::MakeSpellbook() const {
    simpleClearScreen();
    cout << "  Generating Spellbook details\n Questions about this spellbook: " << endl << endl;
    int first = getNumber("1. How many first level spells?(0-31): ", 0, 31);
    int second = getNumber("2. How many second level spells?(0-30): ", 0, 30);
    int third = getNumber("3. How many third level spells?(0-27): ", 0, 27);
    int fourth = getNumber("4. How many fourth level spells?(0-23): ", 0, 23);
    int fifth = getNumber("5. How many fifth level spells?(0-23): ", 0, 23);
    int sixth = getNumber("6. How many sixth level spells?(0-20): ", 0, 20);
    int seventh = getNumber("7. How many seventh level spells?(0-15): ", 0, 15);
    int eighth = getNumber("8. How many eighth level spells?(0-14): ", 0, 14);
    int ninth = getNumber("9. How many ninth level spells?(0-12): ", 0, 12);
    int usedpages = ((first)+(second*2)+(third*3)+(fourth*4)+(fifth*5)+(sixth*6)+(seventh*7)+(eighth*8)+(ninth*9));
    cout << "\n ->Based on the number of spells, there are at least " << RED << usedpages << RESET << " pages in this spellbook." << endl << endl;
    int totalpages = getNumber("Most spellbooks have between 70 to 150 pages in total, but can be more or less.\n How many pages are in this one?\n ->", usedpages, 900);
    cout << "Spellbooks are often bound in leather or thick cloth, but can be made out of anything.\n What kind of material is this spellbook made out of? (enter anything)\n -> ";
    string material;
    cin.ignore(100, '\n');
    getline(cin, material);
    vector<string> spellholder;
    simpleClearScreen();
    cout << " Spellbook\n\n";
    cout << usedpages << " / " << totalpages << " pages used." << endl;
    cout << "Made out of: " << material << endl;
    //LEVEL 1 SPELLS
    if (first > 0) {
        cout << "\nLevel 1 Spells\n----------------\n";
        for (int i = 0; i < first; i++) {
            string tmp = GenerateScroll(1);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 2 SPELLS
    if (second > 0) {
        cout << "\nLevel 2 Spells\n----------------\n";
        for (int i = 0; i < second; i++) {
            string tmp = GenerateScroll(2);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 3 SPELLS
    if (third > 0) {
        cout << "\nLevel 3 Spells\n----------------\n";
        for (int i = 0; i < third; i++) {
            string tmp = GenerateScroll(3);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 4 SPELLS
    if (fourth > 0) {
        cout << "\nLevel 4 Spells\n----------------\n";
        for (int i = 0; i < fourth; i++) {
            string tmp = GenerateScroll(4);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 5 SPELLS
    if (fifth > 0) {
        cout << "\nLevel 5 Spells\n----------------\n";
        for (int i = 0; i < fifth; i++) {
            string tmp = GenerateScroll(5);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 6 SPELLS
    if (sixth > 0) {
        cout << "\nLevel 6 Spells\n----------------\n";
        for (int i = 0; i < sixth; i++) {
            string tmp = GenerateScroll(6);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 7 SPELLS
    if (seventh > 0) {
        cout << "\nLevel 7 Spells\n----------------\n";
        for (int i = 0; i < seventh; i++) {
            string tmp = GenerateScroll(7);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 8 SPELLS
    if (eighth > 0) {
        cout << "\nLevel 8 Spells\n----------------\n";
        for (int i = 0; i < eighth; i++) {
            string tmp = GenerateScroll(8);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 9 SPELLS
    if (ninth > 0) {
        cout << "\nLevel 9 Spells\n----------------\n";
        for (int i = 0; i < ninth; i++) {
            string tmp = GenerateScroll(9);
            if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
                tmp.erase(0, 18);  //removes the scroll property
                tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
            } else {
                i--;   //didn't roll a wizard spell, trying again.
                continue;
            }
            bool not_duplicateSpell = true;
            for (auto i : spellholder) {
                if (i == tmp) not_duplicateSpell = false;
            }
            if (not_duplicateSpell) {
                spellholder.push_back(tmp);
            } else {
                i--;
                continue;
            }
        }
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    // add save option later
    // which might need vector<string> lvl1, lvl2, lvl3, lvl4, lvl5, lvl6, lvl7, lvl8, lvl9;
}

void Magic_Items::showPoisons() {
    fstream poisonfile;
    poisonfile.open("./settings/poisonlist.dat");
    if (!poisonfile.is_open()) {
        cout << "Error Opening poisonlist.dat, check your file.\n\n";
    }
    string poisons = "";
    if (poisonfile.is_open()) {
        while(!poisonfile.eof()) {
            poisons += poisonfile.get();
        }
    }
    poisons.erase(poisons.length()-1, poisons.length()); //erase that last random [box] character
    cout << poisons;
    poisonfile.close();
    pressEnterToContinue();

}

void Magic_Items::showDiseases() {
    fstream diseasefile;
    diseasefile.open("./settings/diseaselist.dat");
    if (!diseasefile.is_open()) {
        cout << "Error Opening diseaselist.dat, check your file.\n\n";
    } else {
        string diseases = "";
        if (diseasefile.is_open()) {
            while(!diseasefile.eof()) {
                diseases += diseasefile.get();
            }
        }
        diseases.erase(diseases.length()-1, diseases.length()); //erase that last random [box] character
        cout << diseases;
        diseasefile.close();
        pressEnterToContinue();
    }

}

void Magic_Items::showMadness() {
    fstream madnessfile;
    madnessfile.open("./settings/madnesslist.dat");
    if (!madnessfile.is_open()) {
        cout << "Error Opening madnesslist.dat, check your file.\n\n";
    }
    string madness = "";
    if (madnessfile.is_open()) {
        while(!madnessfile.eof()) {
            madness += madnessfile.get();
        }
    }
    madness.erase(madness.length()-1, madness.length()); //erase that last random [box] character
    cout << madness;
    madnessfile.close();
    pressEnterToContinue();

}
