#include <SDL.h>
#include <SDL_image.h>

#include "SpriteSDL.h"
#include "WindowSDL.h"


SpriteSDL::SpriteSDL()
	: texture(0), rect({0, 0, 100, 100})
{

}

void SpriteSDL::setTexture(Texture* tex)
{
	texture = reinterpret_cast<TextureSDL*>(tex);
}

void SpriteSDL::getPosition(int& x, int& y) const
{
	x = rect.x + rect.w / 2;
	y = rect.y + rect.h / 2;
}

void SpriteSDL::setPosition(int x, int y)
{
	rect.x = x - rect.w / 2;
	rect.y = y - rect.h / 2;
}

void SpriteSDL::setSize(int w, int h)
{
	rect.x += (rect.w - w) / 2;
	rect.y += (rect.h - h) / 2;

	rect.w = w;
	rect.h = h;
}

void SpriteSDL::setColor(ColorRGBA color)
{
	this->color = color;
}
