#include "sdl_graphics.h"
#include <SDL2/SDL_image.h>

bool SDL_graphics::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    else
    {
        mainWindow = SDL_CreateWindow("DMPOWER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        if (mainWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (mainRenderer == NULL)
            {
                printf("SDL Failed to Create Renderer! ERROR: %s. \n", SDL_GetError());
                return false;
            }
        }
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            printf("SDL_image could not initialize! SDL_image Error %s\n", IMG_GetError());
            return false;
        }
    }
    return true;
}

void SDL_graphics::clear(void)
{
    SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mainRenderer);
}

SDL_graphics::~SDL_graphics(void)
{
    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = NULL;
    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;
}