#include <SDL.h>
#include <SDL_image.h>

#include "SpriteSDL.h"
#include "WindowSDL.h"


SpriteSDL::SpriteSDL()
	: texture(0), rect({0, 0, 100, 100})
{

}

void SpriteSDL::loadTexture(const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	texture = SDL_CreateTextureFromSurface(WindowSDL::getSDLRenderer(), surface);
	SDL_FreeSurface(surface);
}

void SpriteSDL::destroyTexture()
{
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = 0;
	}
}

void SpriteSDL::setPosition(int x, int y)
{
	rect.x = x;
	rect.y = y;
}

void SpriteSDL::setSize(int w, int h)
{
	rect.w = w;
	rect.h = h;
}
