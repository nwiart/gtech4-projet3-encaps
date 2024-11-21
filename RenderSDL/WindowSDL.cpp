#include <SDL.h>
#include <SDL_ttf.h>

#include "WindowSDL.h"
#include "SpriteSDL.h"
#include "FontSDL.h"
#include "TextureSDL.h"


SDL_Window* WindowSDL::window = 0;
SDL_Renderer* WindowSDL::renderer = 0;
InputSDL* WindowSDL::input = 0;


WindowSDL::WindowSDL()
	: isOpen(false)
{

}

WindowSDL::~WindowSDL()
{

}

bool WindowSDL::initialize()
{
	return SDL_Init(SDL_INIT_VIDEO) == 0 && TTF_Init() == 0;
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

	input = new InputSDL();

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

Input* WindowSDL::getInput()
{
	return input;
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

TextureBase* WindowSDL::createTexture()
{
	TextureSDL* t = new TextureSDL();
	return t;
}

void WindowSDL::setBackgroundColor(float r, float g, float b)
{
	backgroundColor = ColorRGBA(r, g, b);
}

void WindowSDL::beginDraw()
{
	SDL_SetRenderDrawColor(renderer, backgroundColor.getR(), backgroundColor.getG(), backgroundColor.getB(), 20);
	//SDL_RenderClear(renderer);

	SDL_Rect r = { 0, 0, 1280, 720 };
	SDL_SetRenderDrawBlendMode(renderer, SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_SRC_ALPHA, SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA, SDL_BLENDOPERATION_ADD, SDL_BLENDFACTOR_ONE, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_ADD));
	SDL_RenderFillRect(renderer, &r);
}

void WindowSDL::drawSprite(Sprite* sprite)
{
	SpriteSDL* s = reinterpret_cast<SpriteSDL*>(sprite);
	TextureSDL* t = s->texture;
	if (!t) {
		return;
	}

	SDL_SetTextureColorMod(t->texture, s->color.getR(), s->color.getG(), s->color.getB());
	SDL_RenderCopyEx(renderer, t->texture, 0, &s->rect, 0.0, 0, SDL_FLIP_NONE);
}

void WindowSDL::endDraw()
{
	SDL_RenderPresent(renderer);
}
