#include <SDL_ttf.h>

#include "WindowSDL.h"
#include "FontSDL.h"


FontSDL::FontSDL()
	: font(0)
{

}

FontSDL::~FontSDL()
{
	this->destroyFont();
}

void FontSDL::loadFont(const char* path)
{
	if (font) {
		return;
	}

	font = TTF_OpenFont(path, 32);
}

void FontSDL::destroyFont()
{
	if (font) {
		TTF_CloseFont(font);
		font = 0;
	}
}

Text* FontSDL::renderText(const char* str)
{
	SDL_Surface* s = TTF_RenderText_Blended(font, str, {255, 255, 255, 255});
	SDL_Texture* t = SDL_CreateTextureFromSurface(WindowSDL::getSDLRenderer(), s);

	SDL_FreeSurface(s);
}
