#pragma once

#include "Color.h"

class Texture;

class Sprite
{
	friend class Window;

public:

	Sprite() { }

	virtual ~Sprite() { }

	virtual void setTexture(Texture* txt) = 0;

	virtual void getPosition(int& x, int& y) const = 0;

	virtual void setPosition(int x, int y) = 0;
	virtual void setSize(int w, int h) = 0;
	virtual void setColor(ColorRGBA color) = 0;
};
