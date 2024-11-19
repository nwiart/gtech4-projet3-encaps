#pragma once

#include "Font.h"

typedef struct _TTF_Font TTF_Font;


class FontSDL : public FontBase
{
	friend class WindowSDL;

public:

	FontSDL();
	virtual ~FontSDL();

	virtual void loadFont(const char* path) override;
	virtual void destroyFont() override;

	virtual Text* renderText(const char* str) override;

private:

	TTF_Font* font;
};
