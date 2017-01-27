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
#include "sdl_graphics.h"
#include "texture.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void load_file(bool &, string &, Campaign &);
void save_file(const bool &, const string &, const Campaign &);

int main(void)
{
    SDL_graphics graphics_engine;
    SDL_Renderer *renderer = graphics_engine.getRenderer();
    int SCREEN_WIDTH = graphics_engine.getScreenWidth();
    int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

    //create text
    TTF_Font *Sans = TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", 24);
    // TTF_SetFontHinting(Sans, TTF_HINTING_LIGHT);

    SDL_Color White = {255, 255, 255, 0};

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, "Hello", White);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you convert it into a texture
    SDL_FreeSurface(surfaceMessage);
    SDL_Rect Message_rect;                      //create a rect
    Message_rect.x = (SCREEN_WIDTH / 2) - 100;  //controls the rect's x coordinate
    Message_rect.y = (SCREEN_HEIGHT / 2) - 100; // controls the rect's y coordinte
    Message_rect.w = 100;                       // controls the width of the rect
    Message_rect.h = 100;                       // controls the height of the rect

    // rect for the background
    // SDL_Rect fillRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    // use a png for the backgound
    Texture mainBackground;
    mainBackground.setRenderer(renderer);
    mainBackground.load("res/pngs/mainBackground.png");

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                SDL_Log("Mouse Button 1 (left) is pressed.");
            }
        }
        //clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // render black rect
        // SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        // SDL_RenderFillRect(renderer, &fillRect);
        mainBackground.draw(0, 0);

        // render text
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

        // update screen
        graphics_engine.render();
    }

    SDL_DestroyTexture(Message);

    ///here is where all the old stuff begins
    bool loadSuccess = 0;
    string loadedFile = "";
    simpleClearScreen();
    cout << "** && ** Dungeon's & Dragons - 5e Core ** && **" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do
    {
        cout << "\n----------MAIN MENU----------\n"
             << "1. Characters\n"
             << "2. Magic Items, Spells, Rewards, Etc\n"
             << "3. Experience Calculator\n"
             << "4. Name Generator\n"
             << "5. Random Encounter\n"
             << "6. NPC Insult\n"
             << "7. Save & Quit\n"
             << "8. Quit\n"
             << "-----------------------------\n"
             << endl;
        choice = getNumber("Choice: ", 1, 8);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            mygame.pc_menu();
            break;
        case 2:
        {
            Magic_Items gen;
            gen.treasure_menu();
        }
        break;
        case 3:
        {
            Magic_Items gen;
            float rewardXP = gen.xpgenerator();
            simpleClearScreen();
            cout << "XP per member = " << rewardXP << "\n\n";
        }
        break;
        case 4:
        {
            CharacterName randomName;
            simpleClearScreen();
            cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
        }
        break;
        case 5:
        {
            Encounter encounter;
            simpleClearScreen();
            cout << encounter.Gen_Encounter();
            pressEnterToContinue();
        }
        break;
        case 6:
        {
            Insult insult;
            simpleClearScreen();
            cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
        }
        break;
        case 7:
            save_file(loadSuccess, loadedFile, mygame);
        case 8:
            cout << "Exiting Program.\n";
        default:
            break;
        }
    } while (choice < 7);
    return EXIT_SUCCESS;
}
void load_file(bool &ls, string &lf, Campaign &game)
{
    string file;
    ifstream thefile;
    cout << "Load File: ";
    getline(cin, file, '\n');
    thefile.open(("saves/" + file + ".save").c_str());
    if (thefile.is_open())
    {
        game.retrieveCharacter(thefile);
        simpleClearScreen();
        cout << "File '" << file << "' loaded.\n\n";
        ls = true;
        lf = file;
        thefile.close();
    }
    else
    {
        simpleClearScreen();
        cout << "No file named '" << file << "'. Starting new file.\n\n";
    }
}
void save_file(const bool &ls, const string &lf, const Campaign &game)
{
    string file;
    ofstream os;
    if (ls == false)
    {
        cout << "Save As: ";
        getline(cin, file, '\n');
    }
    else
    {
        file = lf;
    }
    //save into file after above is complete
    os.open(("Saves/" + file + ".save").c_str());
    if (os.is_open())
    {
        game.dumpCharacter(os);
        cout << "All data saved in file -> " << file << endl;
        os.close();
    }
    else
    {
        cout << "Save failed.\n";
    }
}
