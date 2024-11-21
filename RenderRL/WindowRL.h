#pragma once

#include "Window.h"
#include "Color.h"

class InputRL;


class WindowRL : public Window
{
public:

	WindowRL();

	virtual ~WindowRL();


	// Lib initialization and cleanup, mandatory before calling "createWindow()"
	virtual bool initialize() override;

	virtual void quit() override;


	// Creating a window. Only one can be active at a time.
	virtual bool createWindow(int width, int height, const char* title) override;

	virtual bool isWindowOpen() const override;
	virtual void processEvents() override;

	virtual void setTitle(const char* title) override;

	virtual Input* getInput() override;

	// Drawing methods.
	virtual Sprite* createSprite() override;
	virtual FontBase* createFont() override;
	virtual TextureBase* createTexture() override;
	virtual SoundBase* createSound() override;

	virtual void setBackgroundColor(float r, float g, float b) override;

	virtual void beginDraw() override;
	virtual void drawSprite(Sprite* sprite) override;
	virtual void endDraw() override;


private:
	ColorRGBA color;

	static InputRL* input;
};
