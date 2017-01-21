#include "texture.h"

Texture::Texture() {

}

Texture::~Texture() {
	free();
}

void Texture::free() {
	if (SDLtex != NULL) {
		SDL_DestroyTexture(SDLtex);
		SDLtex = NULL;
		width = 0;
		height = 0;
	}
}

bool Texture::load(const std::string &path) {
	free();
	SDL_Texture *newTexture = nullptr;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) {
		printf("failed to load surface in Texture::load function path: %s\n", path.c_str());
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(SDLrenderer, loadedSurface);
		if (newTexture == nullptr) {
			printf("failed to load newTexture in Texture::load function path %s\n", path.c_str());
		} else {
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	SDLtex = newTexture;
	return SDLtex != nullptr;
}

bool Texture::loadFromText(TTF_Font *font, std::string text, SDL_Color text_color){
	free();

	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	if (textSurface != NULL) {
		SDLtex = SDL_CreateTextureFromSurface(SDLrenderer, textSurface);
		if (SDLtex == NULL) {
			printf("SDL Failed to Create Texture from text! ERROR: %s. \n", SDL_GetError());
		} else {
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	} else {
		printf("SDL Failed to Render Texture from text! ERROR: %s. \n", TTF_GetError());
	}
	return SDLtex = NULL;
}

void Texture::draw(int x, int y, SDL_Rect *rect_clip, double angle, SDL_Point *center, SDL_RendererFlip render_flip) {
	SDL_Rect renderQ = {x, y, width, height};

	if (rect_clip != nullptr) {
		renderQ.w = rect_clip->w;
		renderQ.h = rect_clip->h;
	}

	SDL_RenderCopyEx(SDLrenderer, SDLtex, rect_clip, &renderQ, angle, center, render_flip);
}


