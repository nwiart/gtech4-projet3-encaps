#pragma once

#include "Window.h"
#include "Color.h"
#include "InputSDL.h"

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;


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
	virtual void processEvents() override;

	virtual void setTitle(const char* title) override;

	virtual Input* getInput() override;


	// Drawing methods.
	virtual Sprite* createSprite() override;
	virtual FontBase* createFont() override;
	virtual Texture* createTexture() override;

	virtual void setBackgroundColor(float r, float g, float b) override;

	virtual void beginDraw() override;
	virtual void drawSprite(Sprite* sprite) override;
	virtual void endDraw() override;


	static inline SDL_Renderer* getSDLRenderer() { return renderer; }


private:

	static SDL_Window* window;
	static SDL_Renderer* renderer;

	static InputSDL* input;

	ColorRGBA backgroundColor;

	bool isOpen;
};
