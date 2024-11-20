#include <SDL_ttf.h>

#include "WindowSDL.h"
#include "FontSDL.h"

#include <string.h>


FontSDL::FontSDL()
	: font(0)
{

}

FontSDL::~FontSDL()
{
	this->destroyFont();
}

void FontSDL::loadFont(const char* path)
{
	if (font) {
		return;
	}

	font = TTF_OpenFont(path, 32);

	SDL_Surface* surface, *text;
	SDL_Rect dest;

	memset(glyphRects, 0, sizeof(SDL_Rect) * NUM_GLYPHS);

	const int FONT_TEXTURE_SIZE = 512;

	surface = SDL_CreateRGBSurface(0, FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE, 32, 0xFF, 0xFF00, 0xFF0000, 0xFF000000);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGBA(surface->format, 0, 0, 0, 0));

	dest.x = dest.y = 0;

	for (int c = 0; c < NUM_GLYPHS; c++) {
		char str[2] = { c, 0 };
		if (TTF_SizeText(font, str, &dest.w, &dest.h) == -1) {
			continue;
		}

		text = TTF_RenderGlyph_Blended(font, c, { 255, 255, 255, 255 });

		if (dest.x + dest.w >= FONT_TEXTURE_SIZE) {
			dest.x = 0;

			dest.y += dest.h + 1;

			if (dest.y + dest.h >= FONT_TEXTURE_SIZE) {
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "Out of glyph space in %dx%d font atlas texture map.", FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE);
				exit(1);
			}
		}

		SDL_BlitSurface(text, NULL, surface, &dest);

		SDL_Rect* g = &glyphRects[c];
		g->x = dest.x;
		g->y = dest.y;
		g->w = dest.w;
		g->h = dest.h;

		SDL_FreeSurface(text);

		dest.x += dest.w;
	}

	textureAtlas = SDL_CreateTextureFromSurface(WindowSDL::getSDLRenderer(), surface);

	SDL_FreeSurface(surface);
}

void FontSDL::destroyFont()
{
	if (font) {
		TTF_CloseFont(font);
		font = 0;
	}
}

void FontSDL::renderText(const char* str, int x, int y)
{
	SDL_Rect dest = { x, y, 0, 0 };
	SDL_Rect* g = 0;

	while (*str) {
		g = &glyphRects[*str];

		dest.w = g->w;
		dest.h = g->h;

		SDL_RenderCopy(WindowSDL::getSDLRenderer(), textureAtlas, g, &dest);

		dest.x += g->w;

		str++;
	}
}
