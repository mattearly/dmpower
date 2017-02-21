#include "scenestack.h"
#include "globalfuncts.h"

void SceneStack::menuScene5_export() {
	Texture button_new;
	button_new.setRenderer(renderer);
	button_new.load("res/pngs/button_New.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(190);

	Texture button_choose;
	button_choose.setRenderer(renderer);
	button_choose.load("res/pngs/button_Choose.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(190);

	Texture button_back;
	button_back.setRenderer(renderer);
	button_back.load("res/pngs/button_Back.png");
	button_new.setBlendMode(SDL_BLENDMODE_BLEND);
	button_new.setAlpha(190);

	const int BUTTON_X = 1275;
	const int BUTTON_Y = 620;
	const int BUTTON_DY = 55;
	const int BUTTON_WIDTH = button_new.getWidth();
	const int BUTTON_HEIGHT = button_new.getHeight();

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
					if ((mouseLeftX > BUTTON_X && mouseLeftX < BUTTON_X+BUTTON_WIDTH) && (mouseLeftY > BUTTON_Y && mouseLeftY < BUTTON_Y+BUTTON_HEIGHT)) {
						// NEW BUTTON PRESSED
						newSceneProcced = true;
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

		button_new.draw(BUTTON_X, BUTTON_Y);
		button_choose.draw(BUTTON_X, BUTTON_Y+BUTTON_DY);
		button_back.draw(BUTTON_X, BUTTON_Y+BUTTON_DY*2);

		Graphics_Engine.render();

		newSceneProcced = false;
	}
}
