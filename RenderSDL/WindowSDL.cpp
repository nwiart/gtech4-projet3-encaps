#include <SDL.h>

#include "WindowSDL.h"
#include "SpriteSDL.h"
#include "FontSDL.h"
#include "TextSDL.h"


SDL_Window* WindowSDL::window = 0;
SDL_Renderer* WindowSDL::renderer = 0;


WindowSDL::WindowSDL()
	: isOpen(false)
{

}

WindowSDL::~WindowSDL()
{

}

bool WindowSDL::initialize()
{
	return SDL_Init(SDL_INIT_VIDEO) == 0;
}

void WindowSDL::quit()
{
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = 0;
	}

	if (window) {
		SDL_DestroyWindow(window);
		window = 0;
	}

	SDL_Quit();
}

bool WindowSDL::createWindow(int width, int height, const char* title)
{
	if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) != 0) {
		return false;
	}

	SDL_SetWindowTitle(window, title);
	SDL_RenderSetVSync(renderer, true);

	isOpen = true;

	return true;
}

bool WindowSDL::isWindowOpen() const
{
	return isOpen;
}

void WindowSDL::processEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) > 0)
	{
		if (e.type == SDL_QUIT)
		{
			isOpen = false;
		}
	}
}

void WindowSDL::setTitle(const char* title)
{
	SDL_SetWindowTitle(window, title);
}


Sprite* WindowSDL::createSprite()
{
	SpriteSDL* s = new SpriteSDL();
	return s;
}

FontBase* WindowSDL::createFont()
{
	FontSDL* f = new FontSDL();
	return f;
}

void WindowSDL::setBackgroundColor(float r, float g, float b)
{
	backgroundColor = ColorRGBA(r, g, b);
}

void WindowSDL::beginDraw()
{
	SDL_SetRenderDrawColor(renderer, backgroundColor.getR(), backgroundColor.getG(), backgroundColor.getB(), 255);
	SDL_RenderClear(renderer);
}

void WindowSDL::drawSprite(Sprite* sprite)
{
	SpriteSDL* s = reinterpret_cast<SpriteSDL*>(sprite);
	if (!s->texture) {
		return;
	}

	SDL_RenderCopyEx(renderer, s->texture, 0, &s->rect, 0.0, 0, SDL_FLIP_NONE);
}

void WindowSDL::drawText(Text* text)
{
	TextSDL* t = reinterpret_cast<TextSDL*>(text);
	SDL_RenderCopy(renderer, t->texture, 0, &t->rect);
}

void WindowSDL::endDraw()
{
	SDL_RenderPresent(renderer);
}
