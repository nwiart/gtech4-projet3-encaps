#pragma once

#include "Font.h"

typedef struct _TTF_Font TTF_Font;


class FontSDL : public FontBase
{
	friend class WindowSDL;

public:

	FontSDL();
	virtual ~FontSDL();

	virtual void loadFont(const char* path) = 0;
	virtual void destroyFont() = 0;

	virtual Text* renderText(const char* str) = 0;

private:

	TTF_Font* font;
};
