#include "scenestack.h"


void SceneStack::mainscreen(SDL_graphics &graphics_engine) {
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();
	///LOAD SOME FONTS

	TTF_Font *Leadcoat;
	Leadcoat=TTF_OpenFont("res/fonts/Leadcoat.ttf", 55);
	if(!Leadcoat) { printf("TTF_OpenFont Leadcoat: %s\n", TTF_GetError()); }
	TTF_Font *Bookman;
	Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 31);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	//	TTF_Font *Verdana;
	//	Verdana=TTF_OpenFont("res/fonts/Verdana.ttf", 55);
	//	if(!Verdana) { printf("TTF_OpenFont Verdana: %s\n", TTF_GetError()); }
	//		 TTF_SetFontHinting(Verdana, TTF_HINTING_LIGHT);
	//		 TTF_SetFontStyle(Verdana, TTF_STYLE_BOLD);
	TTF_SetFontHinting(Bookman, TTF_HINTING_MONO);
	///LOAD SOME COLORS
	//	SDL_Color Teal = {100, 200, 200, 0};
	//	SDL_Color White = {255, 255, 255, 0};
	SDL_Color Black = {0,0,0,0};
	SDL_Color Orange = {255, 135, 35, 0};
	///SOLID FULL SCREEN SIZED RECTANGLE FOR A BACKDROP
	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture defaultScene;
	defaultScene.setRenderer(renderer);
	defaultScene.load("res/pngs/defaultScene.png");

	Texture infoBackground;
	infoBackground.setRenderer(renderer);
	infoBackground.load("res/pngs/defaultInfo.png");

	Texture separatorBar;
	separatorBar.setRenderer(renderer);
	separatorBar.load("res/pngs/separatorBar.png");

	Texture titleItem1;
	titleItem1.setRenderer(renderer);
	titleItem1.load("res/pngs/charactersMenu.png");

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
	beginButton.setBlendMode(SDL_BLENDMODE_BLEND);
	beginButton.setAlpha(220);

	/// MENU RECT LOCATIONS
	const int ITEM3_X = 828;
	const int ITEM3AND4_Y = 420;
	const int ITEM4_X = 1246;
	const int ITEM2_X = 780;
	const int ITEM2AND5_Y = 330;
	const int ITEM5_X = 1294;
	const int ITEM1_X = 853;
	const int ITEM1_Y = 230;
	const int BEGINBUTTONX = 955;
	const int BEGINBUTTONY = 615;
	/// TITLE TEXT
	std::string titleText1 = "CHARACTERS";
	std::string titleText2 = "MAGIC ITEMS";
	std::string titleText3 = "RANDOM ENCOUNTER";
	std::string titleText4 = "TOOLS";
	std::string titleText5 = "SAVE & EXPORT";

	std::string infoText = "Dungeons and Dragons.  Satan's Game.\n  Your children, like it or not, are attracted in their weaker years to the occult, and a game like D&D fuels their imagination, and makes them feel special while drawing them deeper and deeper into the bowls of el Diablo.  This afternoon, the Dead Alwives Watchtower invites you to obserb the previously unobservable...";
	SDL_Surface *surfaceMessage;

	surfaceMessage = TTF_RenderText_Solid(Leadcoat, titleText1.c_str(), Orange);
	SDL_Texture *titleArea1 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, titleText2.c_str(), Orange);
	SDL_Texture *titleArea2 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, titleText3.c_str(), Orange);
	SDL_Texture *titleArea3 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, titleText4.c_str(), Orange);
	SDL_Texture *titleArea4 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, titleText5.c_str(), Orange);
	SDL_Texture *titleArea5 = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//	SDL_Rect titleRect = {830, 65, 550, 115};
	//	SDL_Rect titleRect = {830, 60, 560, 145};
	SDL_Rect titleRect = {830, 58, 560, 145};
	surfaceMessage = TTF_RenderText_Blended_Wrapped(Bookman, infoText.c_str(), Black, 635);
	SDL_Texture *infoArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	int w,h;
	w = surfaceMessage->w;
	h = surfaceMessage->h;
	SDL_Rect infoSrcRect = {0, 0, w, h};
	SDL_Rect infoDestRect = {48, 460, w, h};


	SDL_FreeSurface(surfaceMessage);

	/// CURRENTLY SELECTED MENU ITEM
	enum SelectedItem { CHARACTERS = 0, MAGIC_ITEMS, RANDOM_ENCOUNTER, TOOLS, SAVE };
	SelectedItem selectedItem = CHARACTERS;

	int mouseLeftX, mouseLeftY;

	SDL_Event e;

	bool newSceneProcced = false;
	bool quit = false;
	while (!quit) {
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
				case SDLK_LEFT:
					selectedItem = (SelectedItem)CycleRight_5(1, (int)selectedItem);
					break;
				case SDLK_RIGHT:
					selectedItem = (SelectedItem)CycleRight_5(4, (int)selectedItem);
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					newSceneProcced = true;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN: {
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > ITEM1_X && mouseLeftX < ITEM1_X+titleItem1.getWidth()) && (mouseLeftY > ITEM1_Y && mouseLeftY < ITEM1_Y+titleItem1.getHeight())) {
						// ???
					} else if ((mouseLeftX > ITEM2_X && mouseLeftX < (ITEM2_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(1, (int)selectedItem);
					} else if ((mouseLeftX > ITEM3_X && mouseLeftX < (ITEM3_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(2, (int)selectedItem);
					} else if ((mouseLeftX > ITEM4_X && mouseLeftX < (ITEM4_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(3, (int)selectedItem);
					} else if ((mouseLeftX > ITEM5_X && mouseLeftX < (ITEM5_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						selectedItem = (SelectedItem)CycleRight_5(4, (int)selectedItem);
					} else if ((mouseLeftX > BEGINBUTTONX && mouseLeftX < BEGINBUTTONX+beginButton.getWidth()) && (mouseLeftY > BEGINBUTTONY && mouseLeftY < BEGINBUTTONY+beginButton.getWidth()) ) {
						newSceneProcced = true;
					}

					break;
				default: break;
				}
			case SDL_MOUSEMOTION:
					mouseLeftX = e.motion.x;
					mouseLeftY = e.motion.y;
					if ((mouseLeftX > BEGINBUTTONX && mouseLeftX < BEGINBUTTONX+beginButton.getWidth())\
							&& (mouseLeftY > BEGINBUTTONY && mouseLeftY < BEGINBUTTONY+beginButton.getWidth())) {
						beginButton.setAlpha(255);
					} else {
						beginButton.setAlpha(220);

					}
					break;
				}
			default: break;
			}
		}
		graphics_engine.clear();   //clear screen
		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		defaultScene.draw(48, 30);
		infoBackground.draw(48, 460);
		separatorBar.draw(718, 0);

		switch (selectedItem) {
		case CHARACTERS: //0
			titleItem3.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem4.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem2.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem5.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem1.draw(ITEM1_X, ITEM1_Y);
			SDL_RenderCopy(renderer, titleArea1, NULL, &titleRect);
			break;
		case MAGIC_ITEMS:  //1
			titleItem4.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem5.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem3.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem1.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem2.draw(ITEM1_X, ITEM1_Y);
			SDL_RenderCopy(renderer, titleArea2, NULL, &titleRect);
			break;
		case RANDOM_ENCOUNTER:  //2
			titleItem5.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem1.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem4.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem2.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem3.draw(ITEM1_X, ITEM1_Y);
			SDL_RenderCopy(renderer, titleArea3, NULL, &titleRect);
			break;
		case TOOLS:   //3
			titleItem1.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem2.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem5.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem3.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem4.draw(ITEM1_X, ITEM1_Y);
			SDL_RenderCopy(renderer, titleArea4, NULL, &titleRect);
			break;
		case SAVE: //4
			titleItem2.draw(ITEM3_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem3.draw(ITEM4_X, ITEM3AND4_Y, nullptr, &subItem);
			titleItem1.draw(ITEM2_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem4.draw(ITEM5_X, ITEM2AND5_Y, nullptr, &subItem);
			titleItem5.draw(ITEM1_X, ITEM1_Y);
			SDL_RenderCopy(renderer, titleArea5, NULL, &titleRect);
			break;
		default:
			printf("ruh roh!  \n");
			break;
		}
		beginButton.draw(BEGINBUTTONX, BEGINBUTTONY);
		SDL_RenderCopy(renderer, infoArea, &infoSrcRect, &infoDestRect);
		graphics_engine.render();

		if (newSceneProcced) {
			switch (selectedItem) {
			case CHARACTERS: //0
				menuScene1_characters(graphics_engine);
				break;
			case MAGIC_ITEMS:  //1
				menuScene2_magic_items(graphics_engine);
				break;
			case RANDOM_ENCOUNTER:  //2
				menuScene3_encounters(graphics_engine);
				break;
			case TOOLS:   //3
				menuScene4_tools(graphics_engine);
				break;
			case SAVE: //4
				menuScene5_export(graphics_engine);
				break;
			default:
				printf("How is it possible that NO SCENE PROCCED(from mainscene)?!  CHECK CODE!\n");
				break;
			}
			newSceneProcced = false;
		}
	}

	//	TTF_CloseFont(Verdana);
	TTF_CloseFont(Leadcoat);
	TTF_CloseFont(Bookman);

	//	Verdana = NULL;
	Leadcoat = NULL;
	Bookman = NULL;

	//	SDL_FreeSurface(surfaceMessage);
}

void SceneStack::menuScene1_characters(SDL_graphics &graphics_engine){
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	//	Texture character_silhouette;
	//	character_silhouette.setRenderer(renderer);
	//	character_silhouette.load("res/pngs/dummyChar.png");


	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;

	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					//choose button press
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				default: break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					//if
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+40)) {

					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+60 && mouseLeftY < BUTTON_Y+60+40)){
						//choose button press
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+120 && mouseLeftY < BUTTON_Y+120+40)) {
						quit = true;
					}

					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+44)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+44)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+44)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		graphics_engine.clear();

		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		//		character_silhouette.draw();

		graphics_engine.render();
	}
}

void SceneStack::menuScene2_magic_items(SDL_graphics &graphics_engine){
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	//	Texture character_silhouette;
	//	character_silhouette.setRenderer(renderer);
	//	character_silhouette.load("res/pngs/dummyChar.png");


	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;

	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					//scroll left through characters
					break;
				case SDLK_RIGHT:
					//scroll right through characters
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					//choose button press
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				default: break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					//if
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+40)) {

					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+60 && mouseLeftY < BUTTON_Y+60+40)){
						//choose button press
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+120 && mouseLeftY < BUTTON_Y+120+40)) {
						quit = true;
					}

					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+44)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+44)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+44)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		graphics_engine.clear();

		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		//		character_silhouette.draw();

		graphics_engine.render();
	}
}
void SceneStack::menuScene3_encounters(SDL_graphics &graphics_engine){
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	//	Texture character_silhouette;
	//	character_silhouette.setRenderer(renderer);
	//	character_silhouette.load("res/pngs/dummyChar.png");


	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;

	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					//choose button press
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				default: break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					//if
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+40)) {

					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+60 && mouseLeftY < BUTTON_Y+60+40)){
						//choose button press
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+120 && mouseLeftY < BUTTON_Y+120+40)) {
						quit = true;
					}

					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+44)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+44)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+44)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		graphics_engine.clear();

		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		//		character_silhouette.draw();

		graphics_engine.render();
	}
}
void SceneStack::menuScene4_tools(SDL_graphics &graphics_engine){
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	//	Texture character_silhouette;
	//	character_silhouette.setRenderer(renderer);
	//	character_silhouette.load("res/pngs/dummyChar.png");


	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;

	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					//choose button press
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				default: break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					//if
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+40)) {

					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+60 && mouseLeftY < BUTTON_Y+60+40)){
						//choose button press
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+120 && mouseLeftY < BUTTON_Y+120+40)) {
						quit = true;
					}

					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+44)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+44)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+44)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		graphics_engine.clear();

		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		//		character_silhouette.draw();

		graphics_engine.render();
	}
}
void SceneStack::menuScene5_export(SDL_graphics &graphics_engine){
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	//	Texture character_silhouette;
	//	character_silhouette.setRenderer(renderer);
	//	character_silhouette.load("res/pngs/dummyChar.png");


	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;

	int mouseLeftX, mouseLeftY;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					//choose button press
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				default: break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					//if
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+40)) {

					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+60 && mouseLeftY < BUTTON_Y+60+40)){
						//choose button press
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+105) && (mouseLeftY > BUTTON_Y+120 && mouseLeftY < BUTTON_Y+120+40)) {
						quit = true;
					}

					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+44)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+44)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+115) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+44)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		graphics_engine.clear();

		SDL_RenderFillRect(renderer, &backdropRect);  // render black background rect

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		//		character_silhouette.draw();

		graphics_engine.render();
	}
}

///returns 0-4 as appropriate for our special case cycling menu
int SceneStack::CycleRight_5(const int &amt, const int &current){
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
	case 3:{
		switch (current) {
		case 0: return 3;
		case 1: return 4;
		case 2: return 0;
		case 3: return 1;
		case 4: return 2;
		default:break;
		} break;
	}
	case 4:{
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

	//or we could do it the obvious fast way but the numbers go to high like that
	//	return (current + amt);
}
