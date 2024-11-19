#pragma once

#include "Text.h"

typedef struct SDL_Texture SDL_Texture;


class TextSDL : public Text
{
	friend class WindowSDL;

public:

	TextSDL(SDL_Texture* t);
	virtual ~TextSDL();

	virtual void setPosition(int x, int y) override;
	virtual void setSize(int w, int h) override;

	virtual void setColor(ColorRGBA color) override;

private:

	SDL_Rect rect;
	SDL_Texture* texture;
};
