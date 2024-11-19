#include <SDL_ttf.h>

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
