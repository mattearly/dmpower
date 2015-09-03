//
//  main.cpp
//  DM-Power
//
//  Created by Matthew Early on 6/12/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//
//  

#include "campaign.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void load_file(bool&, string&, Campaign&);
void save_file(const bool&, const string&, Campaign&);

int main() {
    bool loadSuccess = 0;
    string loadedFile = "";
    cout << "** && ** Dungeon's & Dragons - 5e Core ** && **" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do {
        cout << "----------MAIN MENU----------" << endl
			 << "1. Player Characters" << endl
    		 << "2. Magical Items & Rewards" << endl
			 << "3. Save & Quit" << endl
			 << "4. Quit without saving" << endl
			 << "-----------------------------" << endl << endl;
        choice = getNumber("Choice: ", 1, 4);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                mygame.pc_menu();
                break;
            case 2:
                mygame.treasure_menu();
                break;
            case 3:
                save_file(loadSuccess, loadedFile, mygame);
                break;
            case 4:
				cout << "Exiting Program.\n";
            default: break;
        }
    } while ( choice < 3 );
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
        cout << "File '" << file << "' loaded.\n\n";
        ls = true;
        lf = file;
        thefile.close();
    } else {
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
