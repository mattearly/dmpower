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

	///LOAD SOME FONTS
	TTF_Font *Sans;
	Sans=TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", 20);
	if(!Sans) {
		printf("TTF_OpenFont Sans: %s\n", TTF_GetError());
	}
	TTF_Font *Verdana;
	Verdana=TTF_OpenFont("res/fonts/Verdana.ttf", 55);
	if(!Verdana) {
		printf("TTF_OpenFont Verdana: %s\n", TTF_GetError());
	}
	TTF_Font *Bookman;
	Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 30);
	if(!Bookman) {
		printf("TTF_OpenFont Bookman: %s\n", TTF_GetError());
	}

	///LOAD SOME COLORS
	SDL_Color Teal = {100, 200, 200, 0};
	SDL_Color White = {255, 255, 255, 0};
	SDL_Color Black = {0,0,0,0};

	///SOLID FULL SCREEN SIZED RECTANCLE FOR A BACKDROP
	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	///TITLE TEXT
	string titleText = "TITLE";
	string infoText = "Lorem ipsum dolor sit amet, vocent aliquid similique et eos. Apeirian disputationi duo ea, nemore pericula an has. Fierent noluisse accusamus duo at, soluta gubergren prodesset mei ne, intellegam conclusionemque ei eos. Mea postea verterem intellegam ad, malis tractatos mediocrem ex nec. Nec et scaevola dignissim, mea hinc disputationi an, quo impedit eligendi disputationi ad.";
	//   create text
//		 TTF_SetFontHinting(Verdana, TTF_HINTING_LIGHT);
//		 TTF_SetFontStyle(Verdana, TTF_STYLE_BOLD);
		 TTF_SetFontHinting(Bookman, TTF_HINTING_MONO);

//	SDL_Surface *surfaceMessage;

//	surfaceMessage = TTF_RenderText_Solid(Verdana, "TITLE", Teal);
//	SDL_Texture *selectedTitle = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
//	SDL_Rect titleRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) - 150, 400, 85};


	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Magic Items", Teal);
	//	SDL_Texture *menuItem2 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect magicItemsMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) - 90, 400, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Exp Calculator", Teal);
	//	SDL_Texture *menuItem3 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect expCalcMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2)-30, 500, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Name Generator", Teal);
	//	SDL_Texture *menuItem4 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect nameGenMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) + 30, 500, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Random Encounter Generator", Teal);
	//	SDL_Texture *menuItem5 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect randomEncounterMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) + 90, 700, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Generate NPC Insult", Teal);
	//	SDL_Texture *menuItem6 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect insultMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) + 150, 550, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Save & Quit", Teal);
	//	SDL_Texture *menuItem7 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect saveAndQuitMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) + 210, 400, 85};

	//	surfaceMessage = TTF_RenderText_Solid(Verdana, "Quit", Teal);
	//	SDL_Texture *menuItem8 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_Rect quitMenuRect = {(SCREEN_WIDTH / 2) - 140, (SCREEN_HEIGHT / 2) + 270, 140, 85};

//	SDL_FreeSurface(surfaceMessage);

//	Message_rect.x = (SCREEN_WIDTH / 2) - 100;  //controls the rect's x coordinate
//	Message_rect.y = (SCREEN_HEIGHT / 2) - 100; // controls the rect's y coordinte
//	Message_rect.w = 150;                       // controls the width of the rect
//	Message_rect.h = 120;                       // controls the height of the rect



	// use a png for the backgound
	//	Texture mainBackground;
	//	mainBackground.setRenderer(renderer);
	//	mainBackground.load("res/pngs/mainBackground.png");

	Texture defaultScene;
	defaultScene.setRenderer(renderer);
	defaultScene.load("res/pngs/defaultScene.png");
	//	SDL_Rect sceneRect = {0,0,528,330};

	Texture infoBackground;
	infoBackground.setRenderer(renderer);
	infoBackground.load("res/pngs/defaultInfo.png");
	//	SDL_Rect infoRect = {0,0,528,264};

	Texture seperatorBar;
	seperatorBar.setRenderer(renderer);
	seperatorBar.load("res/pngs/seperatorBar.png");

	Texture titleItem1;
	titleItem1.setRenderer(renderer);
	titleItem1.load("res/pngs/defaultItem1.png");

	Texture titleItem2;
	titleItem2.setRenderer(renderer);
	titleItem2.load("res/pngs/defaultItem2.png");

	Texture titleItem3;
	titleItem3.setRenderer(renderer);
	titleItem3.load("res/pngs/defaultItem3.png");

	Texture titleItem4;
	titleItem4.setRenderer(renderer);
	titleItem4.load("res/pngs/defaultItem4.png");

	Texture titleItem5;
	titleItem5.setRenderer(renderer);
	titleItem5.load("res/pngs/defaultItem5.png");

	SDL_Rect subItem = {0,0,144,90};

	Texture beginButton;
	beginButton.setRenderer(renderer);
	beginButton.load("res/pngs/defaultBeginButton.png");





	//	int cursorY = 265;
	//	int cursorIncrement = 60;



	//	Texture menuItem1;
	//	menuItem1.setRenderer(renderer);
	//	Texture menuItem2;
	//	menuItem2.setRenderer(renderer);
	// Texture menuItem3; menuItem3.setRenderer(renderer);
	// Texture menuItem4; menuItem4.setRenderer(renderer);
	// Texture menuItem5; menuItem5.setRenderer(renderer);
	// Texture menuItem6; menuItem6.setRenderer(renderer);
	// Texture menuItem7; menuItem7.setRenderer(renderer);
	// Texture menuItem8; menuItem8.setRenderer(renderer);
	//	menuItem1.loadFromText(Sans, "MENU ITEM ONE", White);
	//	menuItem2.loadFromText(Sans, "MENU ITEM TWO", White);

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					//					if (cursorY > 265) {
					//						cursorY -= cursorIncrement;
					//					}
					break;
				case SDLK_DOWN:
					//					if (cursorY < 685) {
					//						cursorY += cursorIncrement;

					//					}
					break;
				default: break;

				}
			default: break;
			}
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				SDL_Log("Mouse Button 1 (left) is pressed.");
			}
		}
		//clear screen
		//		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		//		SDL_RenderClear(renderer);
		graphics_engine.clear();

		// render black rect
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		//		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		SDL_RenderFillRect(renderer, &backdropRect);

		defaultScene.draw(48, 30);

		infoBackground.draw(48, 460);

		seperatorBar.draw(730, 0);

		titleItem3.draw(873, 420, nullptr, &subItem);
		titleItem4.draw(1201, 420, nullptr, &subItem);
		titleItem2.draw(825, 330, nullptr, &subItem);
		titleItem5.draw(1249, 330, nullptr, &subItem);
		titleItem1.draw(949, 230);

		beginButton.draw(960, 620);

		SDL_Surface *surfaceMessage;
		surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
		SDL_Texture *titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		SDL_Rect titleRect = {830, 65, 550, 115};

		surfaceMessage = TTF_RenderText_Blended_Wrapped(Bookman, infoText.c_str(), Black, 635);
		SDL_Texture *infoArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		int w,h;
		w = surfaceMessage->w;
		h = surfaceMessage->h;
		SDL_Rect infoSrcRect = {0, 0, w, h};
		SDL_Rect infoDestRect = {48, 460, w, h};


		SDL_FreeSurface(surfaceMessage);

		SDL_RenderCopy(renderer, titleArea, NULL, &titleRect);
		SDL_RenderCopy(renderer, infoArea, &infoSrcRect, &infoDestRect);



		//		mainBackground.draw();
		//		logo.draw((SCREEN_WIDTH - logo.getWidth()) / 2, (SCREEN_HEIGHT - logo.getHeight()) / 5);
		// render text
		// SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
		//		SDL_RenderCopy(renderer, menuItem1, NULL, &characterMenuRect);
		//		SDL_RenderCopy(renderer, menuItem2, NULL, &magicItemsMenuRect);
		//		SDL_RenderCopy(renderer, menuItem3, NULL, &expCalcMenuRect);
		//		SDL_RenderCopy(renderer, menuItem4, NULL, &nameGenMenuRect);
		//		SDL_RenderCopy(renderer, menuItem5, NULL, &randomEncounterMenuRect);
		//		SDL_RenderCopy(renderer, menuItem6, NULL, &insultMenuRect);
		//		SDL_RenderCopy(renderer, menuItem7, NULL, &saveAndQuitMenuRect);
		//		SDL_RenderCopy(renderer, menuItem8, NULL, &quitMenuRect);
		//		menuCursor.draw(500, cursorY);
		//		menuItem1.draw((SCREEN_WIDTH - menuItem1.getWidth()) / 2, (SCREEN_HEIGHT - menuItem1.getHeight()) / 2, &Message_rect);
		//		menuItem2.draw((SCREEN_WIDTH - menuItem2.getWidth()) / 2, (SCREEN_HEIGHT - menuItem2.getHeight()) / 2, &Message_rect);
		// update screen



		graphics_engine.render();
	}


	TTF_CloseFont(Sans);
	TTF_CloseFont(Verdana);
	TTF_CloseFont(Bookman);

	Sans = NULL;
	Verdana = NULL;
	Bookman = NULL;

















	/// ORIGINAL TERMINAL CODE
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
	os.open(("saves/" + file + ".save").c_str());
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
