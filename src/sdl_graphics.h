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

#pragma once

//#include <SDL2/SDL2.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class SDL_graphics
{
public:
  SDL_graphics(void);
  ~SDL_graphics(void);

  bool init(void);
  void clear(void);
  void render(void) { SDL_RenderPresent(mainRenderer); }

  SDL_Window *getWindow(void) { return mainWindow; }
  int getScreenWidth(void) { return SCREEN_WIDTH; }
  int getScreenHeight(void) { return SCREEN_HEIGHT; }
  SDL_Renderer *getRenderer(void) { return mainRenderer; }

private:
  SDL_Window *mainWindow = NULL;
  SDL_Renderer *mainRenderer = NULL;

  const int SCREEN_WIDTH = 1440;
  const int SCREEN_HEIGHT = 810;
};
