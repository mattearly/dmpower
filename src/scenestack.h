#include "sdl_graphics.h"
#include "texture.h"

class SceneStack {

public:
	SceneStack(){
//		Leadcoat=TTF_OpenFont("res/fonts/Leadcoat.ttf", 54);
//		if(!Leadcoat) { printf("TTF_OpenFont Leadcoat: %s\n", TTF_GetError()); }
	}
	~SceneStack(){
//		TTF_CloseFont(Leadcoat);
//		Leadcoat = NULL;
	}
	void mainscreen(SDL_graphics &graphics_engine);

private:

	void charactersMenu_main(SDL_graphics &graphics_engine);
	void charactersMenu_new1(SDL_graphics &graphics_engine);
	void charactersMenu_new2(SDL_graphics &graphics_engine);

	void menuScene2_magic_items(SDL_graphics &graphics_engine);
	void menuScene3_encounters(SDL_graphics &graphics_engine);
	void menuScene4_tools(SDL_graphics &graphics_engine);
	void menuScene5_export(SDL_graphics &graphics_engine);

	int CycleRight_5(const int &, const int &);
	bool newSceneProcced = false;

	/// PRELOADED COLORS
	SDL_Color Black = {0,0,0,0};
	SDL_Color Orange = {255, 115, 35, 0};

	/// TITLE FONT
//	TTF_Font *Leadcoat;

};
