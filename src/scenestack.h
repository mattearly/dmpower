#pragma once
#include "sdl_graphics.h"
#include "texture.h"

class SceneStack {

public:
	SceneStack() {
		/* Scene Preload */

		Black = {0,0,0,0};
		Orange = {255, 115, 35, 0};
		newSceneProcced = false;
		renderer = Graphics_Engine.getRenderer();
		SCREEN_HEIGHT = Graphics_Engine.getScreenHeight();
		SCREEN_WIDTH = Graphics_Engine.getScreenWidth();
		Leadcoat=TTF_OpenFont("res/fonts/Leadcoat.ttf", 54);
		if(!Leadcoat) { printf("TTF_OpenFont Leadcoat: %s\n", TTF_GetError()); }
		Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 31);
		if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
		//	Verdana=TTF_OpenFont("res/fonts/Verdana.ttf", 55);
		//	if(!Verdana) { printf("TTF_OpenFont Verdana: %s\n", TTF_GetError()); }s
		///ADJUST FONT HINTING
		//	TTF_SetFontHinting(Verdana, TTF_HINTING_LIGHT);
		//	TTF_SetFontStyle(Verdana, TTF_STYLE_BOLD);
		//	TTF_SetFontHinting(Bookman, TTF_HINTING_MONO);
		TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);

		///RECTANGULUR BACKDROP

//		backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};





	}


	~SceneStack(){
	}

	/*!
	 * \brief Controls the rootmost screen
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void mainscreen();

private:
	/*!
	 * \brief charactersMenu_main screen to choose a character or begin
	 *        creating a new one
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void charactersMenu_main();
	/*!
	 * \brief charactersMenu_new1 first screen of character generation
	 *        choose race, class, and name
	 * \param graphics_engine
	 */
	void charactersMenu_new1();
	/*!
	 * \brief charactersMenu_new2 second screen
	 * \param graphics_engine is passed in via reference for rendering
	 */
	void charactersMenu_new2();

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
    };

	/* Preloaded variables */
	bool newSceneProcced;
	SDL_Color Black;
	SDL_Color Orange;
	SDL_Renderer *renderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_graphics Graphics_Engine;
	TTF_Font *Leadcoat;
	TTF_Font *Bookman;
	//	TTF_Font *Verdana;
	SDL_Rect backdropRect;
};
