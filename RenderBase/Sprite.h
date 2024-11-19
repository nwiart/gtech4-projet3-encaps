#pragma once

#include "Color.h"


class Sprite
{
	friend class Window;

public:

	Sprite() { }

	virtual ~Sprite() { }

	virtual void loadTexture(const char* path) = 0;
	virtual void destroyTexture() = 0;

	virtual void getPosition(int& x, int& y) const = 0;

	virtual void setPosition(int x, int y) = 0;
	virtual void setSize(int w, int h) = 0;
	virtual void setColor(ColorRGBA color) = 0;
};
