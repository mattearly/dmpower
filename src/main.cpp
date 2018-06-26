/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include "campaign.h"
#include "gen_reward.h"
#include "gen_name.h"
#include "gen_insult.h"
#include "gen_encounter.h"
#include "gen_experience.h"
#include "charts.h"
#include <string>
#include <cstdlib>

using namespace std;

extern void load_file(bool &, string &, Campaign &);
extern void main_loop(bool &, string &, Campaign &);

int main()
{
    bool loadSuccess = false;
    string loadedFile = "";

    Campaign myGame;
    simpleClearScreen();
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|" << YELLOW << "Dungeon Master Power " << RESET << "- " << RED << "Dungeons & Dragons " << RESET << "- " << CYAN << "5e Core Version" << RESET << "|" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "| * Design & Code by:  " << GREEN << "matthewjearly@gmail.com" << RESET << "              |" << endl;
    cout << "| * Repo:  " << GREEN << "github.com/mattearly/DM-Power-Core-Version" << RESET << "       |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;

    load_file(loadSuccess, loadedFile, myGame);

    main_loop(loadSuccess, loadedFile, myGame);

    return EXIT_SUCCESS;
}
