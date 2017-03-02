#include "globalfuncts.h"
#include "scenestack.h"
#include "gen_name.h"

void SceneStack::charactersMenu_00_main(){
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
			charactersMenu_01_chooseraceclassname();
		}
	}
}

void SceneStack::charactersMenu_01_chooseraceclassname() {

	const std::string text_CHOOSERACE = "CHOOSE A RACE";
	const std::string text_CHOOSECLASS = "CHOOSE A CLASS";
	const std::string text_SETNAME = "Enter a Name:";
	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSERACE.c_str(), Orange);
	SDL_Texture *chooserace_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSECLASS.c_str(), Orange);
	SDL_Texture *chooseclass_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_SETNAME.c_str(), Orange);
	//	SDL_Texture *nameLabel = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//NOTIFICATION MESSAGES
	const std::string text_NO_RACE = "Choose a race...";
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_NO_RACE.c_str(), Orange);
	SDL_Texture *notification_race = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	const std::string text_NO_CLASS = "Choose a class...";
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_NO_CLASS.c_str(), Orange);
	SDL_Texture *notification_class = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	const std::string text_NO_NAME = "<-'GENERATE RANDOM NAME'";
	surfaceMessage = TTF_RenderText_Solid(Bookman, text_NO_NAME.c_str(), Orange);
	SDL_Texture *notification_name = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect notify_area = { 740, 700, 525, 65 };


	std::string theCharacterName = "";

	//GENERATE RANDOM NAME TEXT BUTTON
	const std::string button_GEN_NAME= "GENERATE RANDOM NAME";
	surfaceMessage = TTF_RenderText_Solid(Bookman, button_GEN_NAME.c_str(), Orange);
	SDL_Texture *random_name_button = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect randomNameRect = { 75, 600, 550, 70 };

	surfaceMessage = TTF_RenderText_Solid(Bookman, " ", White);
	SDL_Texture *generatedName = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect nameAreaRect = { 75, 675, 560, 70 };

	SDL_FreeSurface(surfaceMessage);

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

	bool notify_race = false;
	bool notify_class = false;
	bool notify_name = false;
	const int notify_timer = 75;
	int notify_count = 0;

	vector<Texture> allraces; // 9 races
	allraces.resize(allRaces.size());
	for (std::size_t i=0; i<allRaces.size();i++) {
		string strload = "res/pngs/racelist_" + allRaces[i] + ".png";
		allraces[i].setRenderer(renderer);
		allraces[i].load(strload);
		allraces[i].setBlendMode(SDL_BLENDMODE_BLEND);
		allraces[i].setAlpha(145);
	}
	vector<Texture> allclasses;  //12 classes
	allclasses.resize(allClasses.size());
	for (std::size_t i=0; i<allClasses.size();i++) {
		string strload = "res/pngs/classlist_" + allClasses[i] + ".png";
		allclasses[i].setRenderer(renderer);
		allclasses[i].load(strload);
		allclasses[i].setBlendMode(SDL_BLENDMODE_BLEND);
		allclasses[i].setAlpha(145);
	}


	const int RACE_X = 20;
	const int _Y = 70;
	//	const int _DY = 3;
	const int CLASS_X = 735;
	const int _WIDTH = allraces[0].getWidth();
	const int _HEIGHT = allraces[0].getHeight();
	SDL_Rect racerect = { 180,10,290,67 };
	SDL_Rect classrect = { 905,10,290,67 };
	//	SDL_Rect namelabelrect = { 40, 610, 235, 60 };
	const int BAR1_X = 690;
	//	const int BAR2_X = 1420;
	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_back.getWidth();
	const int BUTTON_HEIGHT = button_back.getHeight();


	enum SelectedRace { NO_RACE = -1, DRAGONBORN = 0, HALFLING, DWARF, HALFORC, ELF, HUMAN,\
						GNOME, TIEFLING, HALFELF };
	SelectedRace selectedrace = NO_RACE;
	enum SelectedClass { NO_CLASS = -1, CLERIC = 0, PALADIN, FIGHTER, SORCERER, ROGUE, BARD,\
						 WIZARD, MONK, BARBARIAN, RANGER, DRUID, WARLOCK };
	SelectedClass selectedclass = NO_CLASS;

	SDL_StartTextInput();
	bool goback = false;
	while (!goback && !fullQuit) {
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				fullQuit = true;
				break;
			case SDL_TEXTINPUT:
				//				strcat(characterName, e.text.text);
				break;
			case SDL_TEXTEDITING:
				//				composition = e.edit.text;
				//				cursor = e.edit.start;
				//				selection_len = e.edit.length;
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
				case SDLK_e:// ENTER, RETURN, OR 'e' PRESSSED
				case SDLK_KP_ENTER:
				case SDLK_RETURN:
					if (selectedrace == NO_RACE) {
						notify_race = true;
					} else if (selectedclass == NO_CLASS) {
						notify_class = true;
					} else if (theCharacterName == "") {
						notify_name = true;
					} else {
						newSceneProcced = true; // NEXT SCENE
					}
					break;
				case SDLK_q:// ESCAPE OR 'q' PRESSED
				case SDLK_ESCAPE:
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
						if (selectedrace == NO_RACE) {
							notify_race = true;
						} else if (selectedclass == NO_CLASS) {
							notify_class = true;
						} else if (theCharacterName == "") {
							notify_name = true;
						} else {
							newSceneProcced = true; // NEXT BUTTON PRESSED
						}
					} else if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y+BUTTON_DY*2 && mouseLeftY < BUTTON_Y+BUTTON_DY*2+BUTTON_HEIGHT)) {
						goback = true; // BACK BUTTON PRESSED

						//BEGIN RACE CLICKS
					} else if ((mouseLeftX > RACE_X && mouseLeftX < RACE_X+_WIDTH) && (mouseLeftY > _Y && mouseLeftY < _Y+_HEIGHT)) {
						RaceClick(0,allraces);
						selectedrace = DRAGONBORN;
					} else if ((mouseLeftX > RACE_X+_WIDTH && mouseLeftX < RACE_X+_WIDTH*2)&&(mouseLeftY > _Y && mouseLeftY < _Y+_HEIGHT)) {
						RaceClick(1,allraces);
						selectedrace = HALFLING;
					} else if ((mouseLeftX > RACE_X && mouseLeftX < RACE_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT && mouseLeftY < _Y+_HEIGHT*2)) {
						RaceClick(2,allraces);
						selectedrace = DWARF;
					} else if ((mouseLeftX > RACE_X+_WIDTH && mouseLeftX < RACE_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT && mouseLeftY < _Y+_HEIGHT*2)) {
						RaceClick(3,allraces);
						selectedrace = HALFORC;
					} else if ((mouseLeftX > RACE_X && mouseLeftX < RACE_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*2 && mouseLeftY < _Y+_HEIGHT*3)) {
						RaceClick(4,allraces);
						selectedrace = ELF;
					} else if ((mouseLeftX > RACE_X+_WIDTH && mouseLeftX < RACE_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*2 && mouseLeftY < _Y+_HEIGHT*3)) {
						RaceClick(5,allraces);
						selectedrace = HUMAN;
					} else if ((mouseLeftX > RACE_X && mouseLeftX < RACE_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*3 && mouseLeftY < _Y+_HEIGHT*4)) {
						RaceClick(6,allraces);
						selectedrace = GNOME;
					} else if ((mouseLeftX > RACE_X+_WIDTH && mouseLeftX < RACE_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*3 && mouseLeftY < _Y+_HEIGHT*4)) {
						RaceClick(7,allraces);
						selectedrace = TIEFLING;
					} else if ((mouseLeftX > RACE_X && mouseLeftX < RACE_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*4 && mouseLeftY < _Y+_HEIGHT*5)) {
						RaceClick(8,allraces);
						selectedrace = HALFELF;

						//BEGIN CLASS CLICKS
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y && mouseLeftY < _Y+_HEIGHT)) {
						ClassClick(0,allclasses);
						selectedclass = CLERIC;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y && mouseLeftY < _Y+_HEIGHT)) {
						ClassClick(1,allclasses);
						selectedclass = PALADIN;
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT && mouseLeftY < _Y+_HEIGHT*2)) {
						ClassClick(2,allclasses);
						selectedclass = FIGHTER;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT && mouseLeftY < _Y+_HEIGHT*2)) {
						ClassClick(3,allclasses);
						selectedclass = SORCERER;
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*2 && mouseLeftY < _Y+_HEIGHT*3)) {
						ClassClick(4,allclasses);
						selectedclass = ROGUE;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*2 && mouseLeftY < _Y+_HEIGHT*3)) {
						ClassClick(5,allclasses);
						selectedclass = BARD;
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*3 && mouseLeftY < _Y+_HEIGHT*4)) {
						ClassClick(6,allclasses);
						selectedclass = WIZARD;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*3 && mouseLeftY < _Y+_HEIGHT*4)) {
						ClassClick(7,allclasses);
						selectedclass = MONK;
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*4 && mouseLeftY < _Y+_HEIGHT*5)) {
						ClassClick(8,allclasses);
						selectedclass = BARBARIAN;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*4 && mouseLeftY < _Y+_HEIGHT*5)) {
						ClassClick(9,allclasses);
						selectedclass = RANGER;
					} else if ((mouseLeftX > CLASS_X && mouseLeftX < CLASS_X+_WIDTH) && (mouseLeftY > _Y+_HEIGHT*5 && mouseLeftY < _Y+_HEIGHT*6)) {
						ClassClick(10,allclasses);
						selectedclass = DRUID;
					} else if ((mouseLeftX > CLASS_X+_WIDTH && mouseLeftX < CLASS_X+_WIDTH*2)&&(mouseLeftY > _Y+_HEIGHT*5 && mouseLeftY < _Y+_HEIGHT*6)) {
						ClassClick(11,allclasses);
						selectedclass = WARLOCK;
					}
					//					SDL_Rect randomNameRect = { 75, 625, 550, 70 };  reference

					// RANDOM NAME GENERATOR CLICK
					else if ((mouseLeftX > 75 && mouseLeftX < 75+550)&&(mouseLeftY > 600 && mouseLeftY < 600+70)) {
						CharacterName rName;
						theCharacterName = rName.grabRandomName();
						surfaceMessage = TTF_RenderText_Solid(Bookman, theCharacterName.c_str(), White);
						//						generatedName->free();
						generatedName = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
						SDL_FreeSurface(surfaceMessage);
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
		//		separatorBar.draw(BAR2_X,0);
		SDL_RenderCopy(renderer, chooserace_Title, NULL, &racerect);
		SDL_RenderCopy(renderer, chooseclass_Title, NULL, &classrect);
		//		SDL_RenderCopy(renderer, nameLabel, NULL, &namelabelrect);

		SDL_RenderCopy(renderer, random_name_button, NULL, &randomNameRect);
		SDL_RenderCopy(renderer, generatedName, NULL, &nameAreaRect);

		for (std::size_t i = 0; i < allraces.size(); i++) {
			if (i%2 == 0) {
				allraces[i].draw(RACE_X, _Y+_HEIGHT*(i/2));
			} else {
				allraces[i].draw(RACE_X+_WIDTH, _Y+_HEIGHT*(i/2));
			}
		}

		for (std::size_t i=0;i<allclasses.size();i++) {
			if (i%2 == 0) {
				allclasses[i].draw(CLASS_X,_Y+_HEIGHT*(i/2));
			} else {
				allclasses[i].draw(CLASS_X+_WIDTH,_Y+_HEIGHT*(i/2));
			}
		}

		if (notify_race) {
			SDL_RenderCopy(renderer, notification_race, NULL, &notify_area);
			notify_count++;
			if (notify_count >= notify_timer) {
				notify_race = false;
				notify_count = 0;
			}
		} else if (notify_class) {
			SDL_RenderCopy(renderer, notification_class, NULL, &notify_area);
			notify_count++;
			if (notify_count >= notify_timer) {
				notify_class = false;
				notify_count = 0;
			}
		} else if (notify_name) {
			SDL_RenderCopy(renderer, notification_name, NULL, &notify_area);
			notify_count++;
			if (notify_count >= notify_timer) {
				notify_name = false;
				notify_count = 0;
			}
		}



		Graphics_Engine.render();  //update scene


		if (newSceneProcced) {  //if next was clicked...
			newSceneProcced = false;
			charactersMenu_02_roll();
		}
	}
	SDL_StopTextInput();
}

void SceneStack::charactersMenu_02_roll() {
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
	Texture button_roll;
	button_roll.setRenderer(renderer);
	button_roll.load("res/pngs/button_Diceroll.png");
	Texture stat_block;
	stat_block.setRenderer(renderer);
	stat_block.load("res/pngs/stat_Form.png");

	const std::string text_SET_STATS = "Set Stats";

	const SDL_Rect setStatsRect = { 400,40,440,100 };
	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_SET_STATS.c_str(), Orange);
	SDL_Texture *setStatsTitle = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	//	Texture separatorBar;
	//	separatorBar.setRenderer(renderer);

	//	separatorBar.load("res/pngs/separatorBar.png");
	//	const std::string text_CHOOSECLASS = "SET DETAILS";
	//	const std::string text_SETNAME = "RIOT";
	//	SDL_Surface *surfaceMessage;
	//	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSERACE.c_str(), Orange);
	//	SDL_Texture *chooserace_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	surfaceMessage = TTF_RenderText_Solid(Leadcoat, text_CHOOSECLASS.c_str(), Orange);
	//	SDL_Texture *chooseclass_Title = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	surfaceMessage = TTF_RenderText_Solid(Bookman, text_SETNAME.c_str(), Orange);
	//	SDL_Texture *nameLabel = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_FreeSurface(surfaceMessage);
	//	SDL_Rect racerect = { 60,50,330,100 };
	//	SDL_Rect classrect = { 520,50,330,100 };
	//	SDL_Rect namelabelrect = { 1000, 480, 230, 60 };
	//	const int BAR1_X = 440;
	//	const int BAR2_X = 900;

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
					//					newSceneProcced = true;
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
		SDL_RenderCopy(renderer, setStatsTitle, NULL, &setStatsRect);
		button_roll.draw(300, 150);
		stat_block.draw(1050,70);

		//		separatorBar.draw(BAR1_X,0);
		//		separatorBar.draw(BAR2_X,0);
		//		SDL_RenderCopy(renderer, chooserace_Title, NULL, &racerect);
		//		SDL_RenderCopy(renderer, chooseclass_Title, NULL, &classrect);
		//		SDL_RenderCopy(renderer, nameLabel, NULL, &namelabelrect);

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


