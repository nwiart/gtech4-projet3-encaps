#pragma once

#include "Font.h"

#define NUM_GLYPHS 256

typedef struct _TTF_Font TTF_Font;


class FontSDL : public FontBase
{
	friend class WindowSDL;

public:

	FontSDL();
	virtual ~FontSDL();

	virtual void loadFont(const char* path) override;
	virtual void destroyFont() override;

	virtual void renderText(const char* str, int x, int y) override;

private:

	TTF_Font* font;
	SDL_Texture* textureAtlas;
	SDL_Rect glyphRects[NUM_GLYPHS];
};
