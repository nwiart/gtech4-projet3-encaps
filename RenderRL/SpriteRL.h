#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRL : public Sprite
{
	friend class WindowRL;

public:

	SpriteRL();

	virtual void loadTexture(const char* path) override;
	virtual void destroyTexture() override;

	virtual void setPosition(int x, int y) override;
	virtual void getPosition(int& x, int& y) const override;
	virtual void setSize(int w, int h) override;


private:
	Texture2D s;
	int x; 
	int y;
};
