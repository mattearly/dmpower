#pragma once
#include "sdl_graphics.h"
#include "texture.h"
#include "campaign.h"
#include <vector>

using std::vector;

class SceneStack {

public:

	/*!
	 * \brief Controls the rootmost screen
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void mainscreen();

	SceneStack() {
		/* Scene Preload */
		renderer = Graphics_Engine.getRenderer();
		SCREEN_HEIGHT = Graphics_Engine.getScreenHeight();
		SCREEN_WIDTH = Graphics_Engine.getScreenWidth();
		mouseLeftY = mouseLeftX = 0;
		fullQuit = false;
		newSceneProcced = false;

		Black = {0,0,0,0};
		Orange = {255,115,35,0};
		White = {240,248,240,0};
		Red = {255,0,0,0};
		Blue = {0,0,255,0};
		Teal = {0,191,255,0};

		Leadcoat=TTF_OpenFont("res/fonts/Leadcoat.ttf", 54);
		if(!Leadcoat) { printf("TTF_OpenFont Leadcoat: %s\n", TTF_GetError()); }
		Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 31);
		if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
		TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
		Vivian=TTF_OpenFont("res/fonts/Vivian.ttf", 35);
		if(!Vivian) { printf("TTF_OpenFont Vivian: %s\n", TTF_GetError()); }
	}

	~SceneStack(){
		TTF_CloseFont(Leadcoat);
		Leadcoat = NULL;
		TTF_CloseFont(Bookman);
		Bookman = NULL;
		TTF_CloseFont(Vivian);
		Vivian = NULL;
	}

private:

	/*! Preloaded variables */
	Campaign mygame;  // to build and save characters
	SDL_Color Black, Orange, White, Red, Blue, Teal;
	SDL_Renderer *renderer;
	int SCREEN_WIDTH, SCREEN_HEIGHT;
	SDL_graphics Graphics_Engine;
	TTF_Font *Leadcoat, *Bookman, *Vivian;
	int mouseLeftX, mouseLeftY;  // mouse movement and clicks management
	SDL_Event e;  // key press management
        bool fullQuit;  // application management
	bool newSceneProcced;  // scene management

	/*!
	 * \brief charactersMenu_main screen to choose a character or begin
	 *        creating a new one
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void charactersMenu_00_main();
	/*!
	 * \brief charactersMenu_new1 first screen of character generation
	 *        choose race, class, and name
	 * \param graphics_engine
	 */
	void charactersMenu_01_chooseraceclassname();
	/*!
	 * \brief charactersMenu_new2 second screen
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void charactersMenu_02_roll();

	/*!
	 * \brief menuScene2_magic_items
	 * \param graphics_engine
	 */
	void menuScene2_magic_items();

	/*!
	 * \brief menuScene3_encounters
	 * \param graphics_engine
	 */

	void menuScene3_encounters();

	/*!
	 * \brief menuScene4_tools
	 * \param graphics_engine
	 */
	void menuScene4_tools();

	/*!
	 * \brief menuScene5_export
	 * \param graphics_engine
	 */
	void menuScene5_export();

	/*!
	 * \brief CycleRight_5
	 * \param amt amount to rotate
	 * \param current state of the menu
	 * \return 0-4 as appropriate for our mainscreen window menu
	 */
	int CycleRight_5(const int &amt, const int &current){
		switch (amt) {
		case 1: {
			switch (current) {
			case 0: return 1;
			case 1: return 2;
			case 2: return 3;
			case 3: return 4;
			case 4: return 0;
			default:break;
			} break;
		}
		case 2:{
			switch (current) {
			case 0: return 2;
			case 1: return 3;
			case 2: return 4;
			case 3: return 0;
			case 4: return 1;
			default:break;
			} break;
		}
		case 3: {
			switch (current) {
			case 0: return 3;
			case 1: return 4;
			case 2: return 0;
			case 3: return 1;
			case 4: return 2;
			default:break;
			} break;
		}
		case 4: {
			switch (current) {
			case 0: return 4;
			case 1: return 0;
			case 2: return 1;
			case 3: return 2;
			case 4: return 3;
			default:break;
			} break;
		}
		default:break;
		}
		return 0;
	}

	/*!
	 * \brief RaceClick is a helper function for the New Character building option
	 * \param chosen is the Race clicked
	 * \param races is all the textures in the race list
	 */
	void RaceClick(const int &chosen, vector<Texture> &races) {
		for (std::size_t i=0;i<races.size();i++) {
			if (i != (std::size_t)chosen) races[i].setAlpha(145);
			else races[i].setAlpha(255);
		}
	}

	/*!
	 * \brief ClassClick is a helper function for the New Character building option
	 * \param chosen is the Class clicked
	 * \param classes is all the textures in the race list
	 */
	void ClassClick(const int &chosen, vector<Texture> &classes) {
		for (std::size_t i=0;i<classes.size();i++) {
			if (i != (std::size_t)chosen) classes[i].setAlpha(145);
			else classes[i].setAlpha(255);
		}
	}

};
