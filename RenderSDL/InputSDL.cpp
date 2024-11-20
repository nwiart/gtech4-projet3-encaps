#include "InputSDL.h"

#include <SDL.h>


int InputSDL::getMouseX()
{
	int x;
	SDL_GetMouseState(&x, 0);
	return x;
}

int InputSDL::getMouseY()
{
	int y;
	SDL_GetMouseState(0, &y);
	return y;
}

bool InputSDL::isMouseBtnDown(int b)
{
	Uint32 btnMask = SDL_GetMouseState(0, 0);
	switch (b)
	{
	case 0: return (btnMask & SDL_BUTTON_LMASK) != 0;
	case 1: return (btnMask & SDL_BUTTON_RMASK) != 0;
	case 2: return (btnMask & SDL_BUTTON_MMASK) != 0;
	default: return false;
	}
}
