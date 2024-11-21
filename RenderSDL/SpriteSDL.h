#pragma once

#include "Sprite.h"

class TextureSDL;


class SpriteSDL : public Sprite
{
	friend class WindowSDL;

public:

	SpriteSDL();

	virtual void setTexture(Texture* tex) override;

	virtual void getPosition(int& x, int& y) const override;

	virtual void setPosition(int x, int y) override;
	virtual void setSize(int w, int h) override;
	virtual void setColor(ColorRGBA color) override;


private:

	SDL_Rect rect;
	ColorRGBA color;
	TextureSDL* texture;
};
