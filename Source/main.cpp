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

#include "campaign.h"
#include "gen_reward.h"
#include "gen_name.h"
#include "gen_insult.h"
#include "gen_encounter.h"
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <GL/glut.h>



using namespace std;

void load_file(bool&, string&, Campaign&);
void save_file(const bool&, const string&, const Campaign&);


int main() {

    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    //     // create the window
    // sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    // window.setVerticalSyncEnabled(true);

    // // load resources, initialize the OpenGL states, ...

    // // run the main loop
    // bool running = true;
    // while (running)
    // {
    //     // handle events
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             // end the program
    //             running = false;
    //         }
    //         else if (event.type == sf::Event::Resized)
    //         {
    //             // adjust the viewport when the window is resized
    //             glViewport(0, 0, event.size.width, event.size.height);
                
    //         }
    //     }

    //     // clear the buffers
    //     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //     // draw...

    //     // end the current frame (internally swaps the front and back buffers)
    //     window.display();
    // }


    bool loadSuccess = 0;
    string loadedFile = "";
    simpleClearScreen();
    cout << "** && ** Dungeon's & Dragons - 5e Core ** && **" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do {
		cout << "\n----------MAIN MENU----------\n"
			 << "1. Characters\n"
			 << "2. Magic Items, Spells, Rewards, Etc\n"
			 << "3. Experience Calculator\n"
			 << "4. Name Generator\n"
			 << "5. Random Encounter\n"
			 << "6. NPC Insult\n"
			 << "7. Save & Quit\n"
			 << "8. Quit\n"
			 << "-----------------------------\n" << endl;
		choice = getNumber("Choice: ", 1, 8);
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
			cout << "XP per member = " << rewardXP << "\n\n";
        }
            break;
        case 4:{
            CharacterName randomName;
            simpleClearScreen();
			cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
        }
            break;
		case 5:{
            Encounter encounter;
            simpleClearScreen();
            cout << encounter.Gen_Encounter();
            pressEnterToContinue();
        }
			break;
		case 6:{
			Insult insult;
			simpleClearScreen();
			cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
		}
            break;
		case 7:
            save_file(loadSuccess, loadedFile, mygame);
        case 8:
            cout << "Exiting Program.\n";
        default: break;
        }
	} while ( choice < 7 );
    return EXIT_SUCCESS;
}
void load_file(bool& ls, string& lf, Campaign& game) {
    string file;
    ifstream thefile;
    cout << "Load File: ";
    getline(cin, file, '\n');
    thefile.open( ("Saves/" + file + ".dat").c_str() );
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
void save_file(const bool& ls, const string& lf, const Campaign& game) {
    string file;
    ofstream os;    
    if (ls == false) {
        cout << "Save As: ";
        getline(cin, file, '\n');
    } else {
        file = lf;
    }
    //save into file after above is complete
    os.open(("Saves/" + file + ".dat").c_str());
    if (os.is_open()) {
        game.dumpCharacter(os);
        cout << "All data saved in file -> " << file << endl;
        os.close();
    } else {
        cout << "Save failed.\n";
    }
} 
