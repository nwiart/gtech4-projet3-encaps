#pragma once

#include "Window.h"


class WindowSDL : public Window
{
public:

	WindowSDL();

	virtual ~WindowSDL();


	// Lib initialization and cleanup, mandatory before calling "createWindow()"
	virtual bool initialize() override;

	virtual void quit() override;


	// Creating a window. Only one can be active at a time.
	virtual bool createWindow(int width, int height, const char* title) override;

	virtual bool isWindowOpen() const override;

	virtual void setTitle(const char* title) override;


	// Drawing methods.
	virtual Sprite* createSprite(const char* imagePath) override;

	virtual void setBackgroundColor(float r, float g, float b) override;

	virtual void drawSprite(Sprite* sprite, int x, int y) override;
};
