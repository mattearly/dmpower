//
//  main.cpp
//  DM-Power
//
//  Created by Matthew Early on 6/12/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//
//  

#include "campaign.h"
#include "reward_gen.h"
#include "name_gen.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void load_file(bool&, string&, Campaign&);
void save_file(const bool&, const string&, Campaign&);

int main() {
    bool loadSuccess = 0;
    string loadedFile = "";
    simpleClearScreen();
    cout << "** && ** Dungeon's & Dragons - 5e Core ** && **" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do {
        cout << "\n----------MAIN MENU----------" << endl
             << "1. Characters" << endl
             << "2. Magic Item Charts" << endl
             << "3. Experience Calculator" << endl
             << "4. Name Generator" << endl
             << "5. Save & Quit" << endl
             << "6. Quit" << endl
             << "-----------------------------" << endl << endl;
        choice = getNumber("Choice: ", 1, 6);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            mygame.pc_menu();
            break;
        case 2: {
            Magic_Items gen;
            gen.treasure_menu();
        }
            break;
        case 3: {
            Magic_Items gen;
            float rewardXP = gen.xpgenerator();
            simpleClearScreen();
            cout << "XP per member = " << rewardXP << endl << endl;
        }
            break;
        case 4:{
            CharacterName randomName;
            simpleClearScreen();
            cout << "Here is a name: " << randomName.grabRandomName() << endl << endl;
        }
            break;
        case 5:
            save_file(loadSuccess, loadedFile, mygame);
            break;
        case 6:
            cout << "Exiting Program.\n";
        default: break;
        }
    } while ( choice < 5 );
    return EXIT_SUCCESS;
}
void load_file(bool& ls, string& lf, Campaign& game) {
    string file;
    ifstream thefile;
    cout << "Load File: ";
    getline(cin, file, '\n');
    thefile.open( (file + ".dat").c_str() );
    if (thefile.is_open()) {
        game.retrieveCharacter(thefile);
        simpleClearScreen();
        cout << "File '" << file << "' loaded.\n\n";
        ls = true;
        lf = file;
        thefile.close();
    } else {
        simpleClearScreen();
        cout << "No file named '" << file << "'. Starting new file.\n\n";
    }
}
void save_file(const bool& ls, const string& lf, Campaign& game) {
    string file;
    ofstream os;
    if (ls == false) {
        cout << "Save As: ";
        getline(cin, file, '\n');
    } else {
        file = lf;
    }
    //save into file after above is complete
    os.open((file + ".dat").c_str());
    if (os.is_open()) {
        game.dumpCharacter(os);
        cout << "All data saved in file -> " << file << endl;
        os.close();
    } else {
        cout << "Save failed.\n";
    }
} 
