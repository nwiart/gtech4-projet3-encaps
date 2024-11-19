#pragma once

class Sprite;
class FontBase;
class Text;


class Window
{
public:

	Window() { }

	virtual ~Window() { }


	// Lib initialization and cleanup, mandatory before calling "createWindow()"
	virtual bool initialize() = 0;

	virtual void quit() = 0;


	// Creating a window. Only one can be active at a time.
	virtual bool createWindow(int width, int height, const char* title) = 0;

	virtual bool isWindowOpen() const = 0;
	virtual void processEvents() = 0;

	virtual void setTitle(const char* title) = 0;


	// Drawing methods.
	virtual Sprite* createSprite() = 0;
	virtual FontBase* createFont() = 0;

	virtual void setBackgroundColor(float r, float g, float b) = 0;

	virtual void beginDraw() = 0;
	virtual void drawSprite(Sprite* sprite) = 0;
	virtual void drawText(Text* text) = 0;
	virtual void endDraw() = 0;
};
