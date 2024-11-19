#include <SDL.h>

#include "TextSDL.h"


TextSDL::TextSDL(SDL_Texture* t)
{
	SDL_QueryTexture(t, 0, 0, &rect.w, &rect.h);
}

TextSDL::~TextSDL()
{

}

void TextSDL::setPosition(int x, int y)
{
	rect.x = x;
	rect.y = y;
}

void TextSDL::setSize(int w, int h)
{

}

void TextSDL::setColor(ColorRGBA color)
{

}
