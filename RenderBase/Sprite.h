#pragma once


class Sprite
{
	friend class Window;

public:

	Sprite() { }

	virtual ~Sprite() { }

	virtual void loadTexture(const char* path) = 0;
	virtual void destroyTexture() = 0;

	virtual void setPosition(int x, int y) = 0;
	virtual void setSize(int w, int h) = 0;
};
