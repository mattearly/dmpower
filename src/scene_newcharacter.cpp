#include "globalfuncts.h"
#include "scenestack.h"

void SceneStack::charactersMenu_main(){
	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/button_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(190);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/button_Choose.png");
	button_choose.setBlendMode(SDL_BLENDMODE_BLEND);
	button_choose.setAlpha(190);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/button_Back.png");
	button_back.setBlendMode(SDL_BLENDMODE_BLEND);
	button_back.setAlpha(190);

	Texture mountain_ani0;
	mountain_ani0.setRenderer(renderer);
	mountain_ani0.load("res/pngs/mountains.png");
	mountain_ani0.setBlendMode(SDL_BLENDMODE_BLEND);
	mountain_ani0.setAlpha(255);

	Texture unknown_character;
	unknown_character.setRenderer(renderer);
	unknown_character.load("res/pngs/unknown_man.png");

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

	bool createNewCharacter = false;

	bool goback = false;
	while (!goback && !fullQuit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				fullQuit = true;
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
					break;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					goback = true;
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
						createNewCharacter = true;
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						// CHOOSE BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						goback = true;
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
					button_new.setAlpha(190);
				}
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_choose.setAlpha(255);
				} else {
					button_choose.setAlpha(190);
				}
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(190);
				}


				break;
			default: break;
			}
		}

		Graphics_Engine.clear();

		mountain_ani0.draw();
		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		unknown_character.draw();

		Graphics_Engine.render();

		//otherwise we'll be in a loop
		if (newSceneProcced && createNewCharacter) {
			newSceneProcced = false;
			createNewCharacter = false;
			charactersMenu_new1();
		}
	}
}

void SceneStack::charactersMenu_new1() {
	Texture button_next;
	button_next.setRenderer(renderer);
	button_next.load("res/pngs/button_Next.png");
	button_next.setBlendMode(SDL_BLENDMODE_BLEND);
	button_next.setAlpha(190);
	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/button_Back.png");
	button_back.setBlendMode(SDL_BLENDMODE_BLEND);
	button_back.setAlpha(190);
	Texture separatorBar;
	separatorBar.setRenderer(renderer);
	separatorBar.load("res/pngs/separatorBar.png");
	const std::string text_CHOOSERACE = "CHOOSE RACE";
	const std::string text_CHOOSECLASS = "CHOOSE CLASS";
	const std::string text_SETNAME = "Enter a Name";
	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSERACE.c_str(), Orange);
	SDL_Texture *chooserace_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSECLASS.c_str(), Orange);
	SDL_Texture *chooseclass_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_SETNAME.c_str(), Orange);
	SDL_Texture *nameLabel = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	enum SelectedRace { NO_RACE = -1, DRAGONBORN = 0, HALFLING, DWARF, HALFORC, ELF, HUMAN,\
						GNOME, TIEFLING, HALFELF };
	SelectedRace selectedrace = NO_RACE;
	enum SelectedClass { NO_CLASS = -1, CLERIC = 0, PALADIN, FIGHTER, SORCERER, ROGUE, BARD,\
						 WIZARD, MONK, BARBARIAN, RANGER, DRUID, WARLOCK };
	SelectedClass selectedclass = NO_CLASS;
	vector<Texture> allraces; // 9 races
	//	vector<SDL_Rect> racelistrect;
	vector<Texture> allclasses; // 12 classes
	//	vector<SDL_Rect> classlistrect;
	//	SDL_Rect tmp;
	const int RACE_X = 55;
	const int _Y = 155;
	const int _DY = 3;
	const int CLASS_X = 500;
	const int _WIDTH = 330;
	const int _HEIGHT = 100;
	for (int i = 0; i < allRaces.size(); i++) {
		string strload = "res/pngs/racelist_" + allRaces[i] + ".png";
		Texture textureload;
		textureload.setRenderer(renderer);
		textureload.load(strload);
		//		textureload.setBlendMode(SDL_BLENDMODE_MOD);
		allraces.push_back(textureload);
	}
	for (int i = 0; i < allClasses.size(); i++) {
		string strload = "res/pngs/classlist_" + allClasses[i] + ".png";
		Texture textureload;
		textureload.setRenderer(renderer);
		textureload.load(strload);
		//		textureload.setBlendMode(SDL_BLENDMODE_MOD);
		allclasses.push_back(textureload);
	}
	SDL_Rect racerect = { 60,50,330,100 };
	SDL_Rect classrect = { 520,50,330,100 };
	SDL_Rect namelabelrect = { 1000, 480, 230, 60 };
	const int BAR1_X = 440;
	const int BAR2_X = 900;
	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_back.getWidth();
	const int BUTTON_HEIGHT = button_back.getHeight();
	bool goback = false;
	while (!goback && !fullQuit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				fullQuit = true;
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
					break;
				case SDLK_q:
				case SDLK_ESCAPE:
					// ESCAPE OR 'q' PRESSED
					goback = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					/*if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
					} else */
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						newSceneProcced = true;
						// NEXT BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						goback = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				/* button Next Hover */
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_next.setAlpha(255);
				} else {
					button_next.setAlpha(190);
				}
				/* button Back Hover */
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(190);
				}
				break;
			default: break;
			}
		}
		Graphics_Engine.clear();
		button_next.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		separatorBar.draw(BAR1_X,0);
		separatorBar.draw(BAR2_X,0);
		SDL_RenderCopy(renderer, chooserace_Title, NULL, &racerect);
		SDL_RenderCopy(renderer, chooseclass_Title, NULL, &classrect);
		SDL_RenderCopy(renderer, nameLabel, NULL, &namelabelrect);
		for (int i = 0; i < allraces.size(); i++) {
			allraces[i].draw(RACE_X, _Y+_HEIGHT*i);
		}
		for (int i = 0; i < allclasses.size(); i++) {
			if (i < allclasses.size()/2) {
				allclasses[i].draw(CLASS_X, _Y+_HEIGHT*i);
			} else {
				allclasses[i].draw(CLASS_X+_WIDTH, _Y+_HEIGHT*(i-allraces.size()/2));
			}
		}
		Graphics_Engine.render();

		if (newSceneProcced) {
			newSceneProcced = false;
			charactersMenu_new2();
		}
	}
}


void SceneStack::charactersMenu_new2() {
	Texture button_next;
	button_next.setRenderer(renderer);
	button_next.load("res/pngs/button_Next.png");
	button_next.setBlendMode(SDL_BLENDMODE_BLEND);
	button_next.setAlpha(190);
	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/button_Back.png");
	button_back.setBlendMode(SDL_BLENDMODE_BLEND);
	button_back.setAlpha(190);
	Texture separatorBar;
	separatorBar.setRenderer(renderer);
	separatorBar.load("res/pngs/separatorBar.png");
	const std::string text_CHOOSERACE = "SET DETAILS";
	const std::string text_CHOOSECLASS = "SET DETAILS";
	const std::string text_SETNAME = "RIOT";
	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSERACE.c_str(), Orange);
	SDL_Texture *chooserace_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSECLASS.c_str(), Orange);
	SDL_Texture *chooseclass_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_SETNAME.c_str(), Orange);
	SDL_Texture *nameLabel = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	vector<SDL_Texture *> allraces;
	//	vector<SDL_Texture *> allclasses;
	//	vector<SDL_Rect> racelistrect;
	//	vector<SDL_Rect> classlistrect;
	//	SDL_Rect tmp;
	//		for (int i = 0; i < allRaces.size(); i++) {
	//			surfaceMessage = TTF_RenderText_Solid(Bookman, allRaces[i].c_str(), White);
	//			allraces.push_back(SDL_CreateTextureFromSurface(renderer, surfaceMessage));
	//			tmp.x = 55; tmp.y = 160+50*i; tmp.w = 320; tmp.h = 45;
	//			racelistrect.push_back(tmp);
	//		}
	//	for (int i = 0; i < allClasses.size(); i++) {
	//		surfaceMessage= TTF_RenderText_Solid(Bookman, allClasses[i].c_str(), White);
	//		allclasses.push_back(SDL_CreateTextureFromSurface(renderer, surfaceMessage));
	//		tmp.x = 515; tmp.y = 160+50*i; tmp.w = 320; tmp.h = 45;
	//		classlistrect.push_back(tmp);
	//	}
	SDL_FreeSurface(surfaceMessage);
	SDL_Rect racerect = { 60,50,330,100 };
	SDL_Rect classrect = { 520,50,330,100 };
	SDL_Rect namelabelrect = { 1000, 480, 230, 60 };
	const int BAR1_X = 440;
	const int BAR2_X = 900;
	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_back.getWidth();
	const int BUTTON_HEIGHT = button_back.getHeight();
	bool goback = false;
	while (!goback && !fullQuit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				fullQuit = true;
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
					goback = true;
					break;
				default: break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftX = e.button.x;
					mouseLeftY = e.button.y;
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
						newSceneProcced = true;
						// NEXT BUTTON PRESSED
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						// BACK BUTTON PRESSED
						goback = true;
					}
					break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseLeftX = e.motion.x;
				mouseLeftY = e.motion.y;
				// BUTTON HOVER EFFECTS
				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY && mouseLeftY < BUTTON_Y+BUTTON_DY+BUTTON_HEIGHT)){
					button_next.setAlpha(255);
				} else {
					button_next.setAlpha(190);
				}

				if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
					button_back.setAlpha(255);
				} else {
					button_back.setAlpha(190);
				}
				break;
			default: break;
			}
		}
		Graphics_Engine.clear();

		button_next.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);
		separatorBar.draw(BAR1_X,0);
		separatorBar.draw(BAR2_X,0);
		SDL_RenderCopy(renderer, chooserace_Title, NULL, &racerect);
		SDL_RenderCopy(renderer, chooseclass_Title, NULL, &classrect);
		SDL_RenderCopy(renderer, nameLabel, NULL, &namelabelrect);

		//		for (int i = 0; i < allraces.size(); i++) {
		//			SDL_RenderCopy(renderer, allraces[i], NULL, &racelistrect[i]);
		//		}
		//		for (int i = 0; i < allclasses.size(); i++) {
		//			SDL_RenderCopy(renderer, allclasses[i], NULL, &classlistrect[i]);
		//		}

		Graphics_Engine.render();

		if (newSceneProcced) {
			newSceneProcced = false;

		}
	}
}
