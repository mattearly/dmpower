#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class SDL_graphics {
    SDL_graphics();
    ~SDL_graphics();
    bool init();
    void close();
};