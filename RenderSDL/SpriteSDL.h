#pragma once

#include "Sprite.h"


class SpriteSDL : public Sprite
{
	friend class WindowSDL;

public:

	SpriteSDL();

	virtual void loadTexture(const char* path) override;
	virtual void destroyTexture() override;

	virtual void setPosition(int x, int y) override;
	virtual void setSize(int w, int h) override;

	virtual void draw() override;
};
