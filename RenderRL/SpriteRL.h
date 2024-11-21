#pragma once

#include "Sprite.h"
#include "raylib.h"
#include "TextureRL.h"

class SpriteRL : public Sprite
{
	friend class WindowRL;

public:

	SpriteRL();

	virtual void setTexture(TextureBase* txt) override;

	virtual void setPosition(int x, int y) override;
	virtual void getPosition(int& x, int& y) const override;
	virtual void setSize(int w, int h) override;
	virtual void setColor(ColorRGBA color) override;


private:
	TextureRL* txtRL;
	Rectangle rect;
	ColorRGBA color;
};
