#pragma once

class Sprite;


class Window
{
public:

	Window() { }

	virtual ~Window() { }


	// Lib initialization and cleanup, mandatory before calling "createWindow()"
	virtual void initialize() = 0;

	virtual void quit() = 0;


	// Creating a window. Only one can be active at a time.
	virtual void createWindow(int width, int height, const char* title) = 0;

	virtual bool isWindowOpen() const = 0;

	virtual void setTitle(const char* title) = 0;


	// Drawing methods.
	virtual Sprite* createSprite(const char* imagePath) = 0;

	virtual void setBackgroundColor(float r, float g, float b) = 0;

	virtual void drawSprite(Sprite* sprite, int x, int y) = 0;
};
