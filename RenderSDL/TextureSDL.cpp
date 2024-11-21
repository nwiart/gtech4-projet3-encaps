#include <SDL.h>
#include <SDL_image.h>
#include "TextureSDL.h"

#include "WindowSDL.h"


TextureSDL::TextureSDL()
	: texture(0)
{

}

TextureSDL::~TextureSDL()
{
	this->destroyTexture();
}

void TextureSDL::loadTexture(const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	texture = SDL_CreateTextureFromSurface(WindowSDL::getSDLRenderer(), surface);
	SDL_FreeSurface(surface);
}

void TextureSDL::destroyTexture()
{
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = 0;
	}
}
