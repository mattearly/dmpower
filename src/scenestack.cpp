#include "scenestack.h"


void SceneStack::mainscreen() {
	///IMAGERY
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
	titleItem2.load("res/pngs/magicitemsMenu.png");
	Texture titleItem3;
	titleItem3.setRenderer(renderer);
	titleItem3.load("res/pngs/randomencounterMenu.png");
	Texture titleItem4;
	titleItem4.setRenderer(renderer);
	titleItem4.load("res/pngs/toolsMenu.png");
	Texture titleItem5;
	titleItem5.setRenderer(renderer);
	titleItem5.load("res/pngs/saveMenu.png");
	SDL_Rect subItem = {0,0,144,90};
	Texture beginButton;
	beginButton.setRenderer(renderer);
	beginButton.load("res/pngs/defBeginButton.png");
	beginButton.setBlendMode(SDL_BLENDMODE_BLEND);
	beginButton.setAlpha(220);
	///MENU RECT LOCATIONS
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
	///TEXT
	const std::string titleText1 = "CHARACTERS";
	const std::string titleText2 = "MAGIC ITEMS";
	const std::string titleText3 = "RANDOM ENCOUNTERS";
	const std::string titleText4 = "TOOLS";
	const std::string titleText5 = "SAVE & EXPORT";
	std::string infoText = "Dungeons and Dragons.  Satan's Game.\n  Your children, like it or not, are attracted in their weaker years to the occult, and a game like D&D fuels their imagination, and makes them feel special while drawing them deeper and deeper into the bowels of el Diablo.  This afternoon, the Dead Alwives Watchtower invites you to obserb the previously unobservable...";
	///SURFACES FOR TEXT
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
	///RECTANGLE FOR TEXT
	SDL_Rect titleRect = {830, 58, 560, 145};
	/// WRAP INFO AREA TEXT TO INFO AREA SIZE
	surfaceMessage = TTF_RenderText_Blended_Wrapped(Bookman, infoText.c_str(), Black, 635);
	SDL_Texture *infoArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	int w,h;
	w = surfaceMessage->w;
	h = surfaceMessage->h;
	SDL_Rect infoSrcRect = {0, 0, w, h};
	SDL_Rect infoDestRect = {48, 460, w, h};
	///DONE WITH surfaceMessage
	SDL_FreeSurface(surfaceMessage);
	/// FOR CURRENTLY SELECTED MENU ITEM
	enum SelectedItem { CHARACTERS = 0, MAGIC_ITEMS, RANDOM_ENCOUNTER, TOOLS, SAVE };
	SelectedItem selectedItem = CHARACTERS;
	/// THE MAIN SCENE LOOP BEGINS HERE UNTIL QUIT
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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					selectedItem = (SelectedItem)CycleRight_5(1, (int)selectedItem);
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					selectedItem = (SelectedItem)CycleRight_5(4, (int)selectedItem);
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN: {
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > ITEM1_X && mouseLeftX < ITEM1_X+titleItem1.getWidth()) && (mouseLeftY > ITEM1_Y && mouseLeftY < ITEM1_Y+titleItem1.getHeight())) {
						// ALREADY SELECTED ITEM CLICKED
					} else if ((mouseLeftX > ITEM2_X && mouseLeftX < (ITEM2_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						// ITEM 2 CLICKED
						selectedItem = (SelectedItem)CycleRight_5(1, (int)selectedItem);
					} else if ((mouseLeftX > ITEM3_X && mouseLeftX < (ITEM3_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						// ITEM 3 CLICKED
						selectedItem = (SelectedItem)CycleRight_5(2, (int)selectedItem);
					} else if ((mouseLeftX > ITEM4_X && mouseLeftX < (ITEM4_X+subItem.w)) && (mouseLeftY > ITEM3AND4_Y && mouseLeftY < (ITEM3AND4_Y+subItem.h))) {
						// ITEM 4 CLICKED
						selectedItem = (SelectedItem)CycleRight_5(3, (int)selectedItem);
					} else if ((mouseLeftX > ITEM5_X && mouseLeftX < (ITEM5_X+subItem.w)) && (mouseLeftY > ITEM2AND5_Y && mouseLeftY < (ITEM2AND5_Y+subItem.h))) {
						// ITEM 5 CLICKED
						selectedItem = (SelectedItem)CycleRight_5(4, (int)selectedItem);
					} else if ((mouseLeftX > BEGINBUTTONX && mouseLeftX < BEGINBUTTONX+beginButton.getWidth()) && (mouseLeftY > BEGINBUTTONY && mouseLeftY < BEGINBUTTONY+beginButton.getWidth()) ) {
						// CHOOSE BUTTON CLICKED
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
						// HOVER OVER CHOOSE VISUAL FEEDBACK EFFFECT
						beginButton.setAlpha(255);
					} else {
						beginButton.setAlpha(220);

					}
					break;
				}
			default: break;
			}
		}
		// CLEAR SCREEN TO BLACK
		Graphics_Engine.clear();

		// DRAW LEFT SIDE OF SCREEN
		defaultScene.draw(48, 30);
		infoBackground.draw(48, 460);
		separatorBar.draw(718, 0);

		// DRAW MENU BASED ON WHICH ITEM IS CURRENTLY CHOSEN
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

		// DRAW CHOOSE BUTTON
		beginButton.draw(BEGINBUTTONX, BEGINBUTTONY);
		SDL_RenderCopy(renderer, infoArea, &infoSrcRect, &infoDestRect);
		// DISPLAY LATEST FRAME
		Graphics_Engine.render();

		if (newSceneProcced) {
			switch (selectedItem) {
			case CHARACTERS: //0
				charactersMenu_main();
				break;
			case MAGIC_ITEMS:  //1
				menuScene2_magic_items();
				break;
			case RANDOM_ENCOUNTER:  //2
				menuScene3_encounters();
				break;
			case TOOLS:   //3
				menuScene4_tools();
				break;
			case SAVE: //4
				menuScene5_export();
				break;
			default:
				printf("How is it possible that NO SCENE PROCCED(from mainscene)?!  CHECK CODE!\n");
				break;
			}
			newSceneProcced = false;
		}
	}
}

void SceneStack::charactersMenu_main(){
	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/characterMenuButton_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(220);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/characterMenuButton_Choose.png");
	button_choose.setBlendMode(SDL_BLENDMODE_BLEND);
	button_choose.setAlpha(220);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/characterMenuButton_Back.png");
	button_back.setBlendMode(SDL_BLENDMODE_BLEND);
	button_back.setAlpha(220);

	Texture mountain_ani0;
	mountain_ani0.setRenderer(renderer);
	mountain_ani0.load("res/pngs/mountains.png");
	mountain_ani0.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani0.setAlpha(255);

	Texture mountain_ani1;
	mountain_ani1.setRenderer(renderer);
	mountain_ani1.load("res/pngs/mountains_animate1.png");
	mountain_ani1.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani1.setAlpha(0);

	Texture mountain_ani2;
	mountain_ani2.setRenderer(renderer);
	mountain_ani2.load("res/pngs/mountains_animate2.png");
	mountain_ani2.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani2.setAlpha(0);

	Texture mountain_ani3;
	mountain_ani3.setRenderer(renderer);
	mountain_ani3.load("res/pngs/mountains_animate3.png");
	mountain_ani3.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani3.setAlpha(0);

	Texture mountain_ani4;
	mountain_ani4.setRenderer(renderer);
	mountain_ani4.load("res/pngs/mountains_animate4.png");
	mountain_ani4.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani4.setAlpha(0);

	int ani0(255), ani1(0), ani2(0), ani3(0), ani4(0);
	bool reset = true;
	//	const int FADE_INCREMENT = 4;

	Texture unknown_character;
	unknown_character.setRenderer(renderer);
	unknown_character.load("res/pngs/unknown_man.png");

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();


	bool createNewCharacter = false;

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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
					createNewCharacter = true;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					quit = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						quit = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}

		Graphics_Engine.clear();

		/* ANIMATED BACKGROUND */
		if (ani0 > 0 && reset) {
			//fade between 0-1
			ani0--;
			mountain_ani0.setAlpha(ani0);
			if (ani1 < 255) {
				ani1++;
				mountain_ani1.setAlpha(ani1);
			}
		} else if (ani1 > 0) {
			if (reset) reset = false;
			//fade between 1-2
			ani1--;
			mountain_ani1.setAlpha(ani1);
			if (ani2 < 255) {
				ani2++;
				mountain_ani2.setAlpha(ani2);
			}
		} else if (ani2 > 0) {
			//fade btween 2-3
			ani2--;
			mountain_ani2.setAlpha(ani2);
			if (ani3 < 255) {
				ani3++;
				mountain_ani3.setAlpha(ani3);
			}
		} else if (ani3 > 0) {
			//fade between 3-4
			ani3--;
			mountain_ani3.setAlpha(ani3);
			if (ani4 < 255) {
				ani4++;
				mountain_ani4.setAlpha(ani4);
			}
		} else if (ani4 > 0){
			//fade between 4-0
			ani4--;
			mountain_ani4.setAlpha(ani4);
			if (ani0 < 255) {
				ani0++;
				mountain_ani0.setAlpha(ani0);
			}
		} else {
			ani0 = 255;
			ani1 = ani2 = ani3 = ani4 = 25;
			reset = true;
		}


		if (ani4 > 0) {
			mountain_ani4.draw();
		}
		if (ani3 > 0) {
			mountain_ani3.draw();
		}
		if (ani2 > 0) {
			mountain_ani2.draw();
		}
		if (ani1 > 0) {
			mountain_ani1.draw();
		}
		if (ani0 > 0) {
			mountain_ani0.draw();
		}

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		unknown_character.draw();

		Graphics_Engine.render();

		//otherwise we'll be in a loop
		newSceneProcced = false;

	}
}


void SceneStack::charactersMenu_new1() {
	const std::string NEW1TITLE = "SET RACE AND CLASS";
	const std::string SETNAME = "Enter a Name";

}


void SceneStack::charactersMenu_new2() {
	const std::string NEW2TITLE = "SET DETAILS";

}


void SceneStack::menuScene2_magic_items() {
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

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					quit = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						quit = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}

		Graphics_Engine.clear();

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);

		Graphics_Engine.render();

		newSceneProcced = false;
	}
}
void SceneStack::menuScene3_encounters() {
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

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					quit = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						quit = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		Graphics_Engine.clear();

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);

		Graphics_Engine.render();

		newSceneProcced = false;

	}
}
void SceneStack::menuScene4_tools() {
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

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					quit = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						quit = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		Graphics_Engine.clear();

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);

		Graphics_Engine.render();

		newSceneProcced = false;

	}
}
void SceneStack::menuScene5_export() {
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

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

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
					// UP KEY PRESSED
					break;
				case SDLK_DOWN:
					// DOWN KEY PRESSED
					break;
				case SDLK_a:
				case SDLK_LEFT:
					// LEFT KEY OR 'a' PRESSED
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					// RIGHT KEY OR 'd' PRESSED
					break;
				case SDLK_e:
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					// ENTER, RETURN, OR 'e' PRESSSED
					newSceneProcced = true;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					quit = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						quit = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
					button_new.setAlpha(255);
				} else {
					button_new.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(220);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(220);
				}
				break;
			default: break;
			}
		}
		Graphics_Engine.clear();

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);

		Graphics_Engine.render();

		newSceneProcced = false;
	}
}

