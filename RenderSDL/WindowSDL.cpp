#include "WindowSDL.h"

#include "SDL.h"


WindowSDL::WindowSDL()
	: window(0), renderer(0), isOpen(false)
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


Sprite* WindowSDL::createSprite(const char* imagePath)
{
	return 0;
}

void WindowSDL::setBackgroundColor(float r, float g, float b)
{
	backgroundColor = Color(r, g, b);
}

void WindowSDL::beginDraw()
{
	SDL_SetRenderDrawColor(renderer, backgroundColor.getR(), backgroundColor.getG(), backgroundColor.getB(), 255);
	SDL_RenderClear(renderer);
}

void WindowSDL::drawSprite(Sprite* sprite, int x, int y)
{

}

void WindowSDL::endDraw()
{
	SDL_RenderPresent(renderer);
}
