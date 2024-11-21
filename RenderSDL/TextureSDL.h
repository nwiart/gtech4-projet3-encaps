#pragma once

#include "Texture.h"


class TextureSDL : public Texture
{
	friend class WindowSDL;

public:

	TextureSDL();
	virtual ~TextureSDL();

	virtual void loadTexture(const char* path) override;
	virtual void destroyTexture() override;

private:

	SDL_Texture* texture;
};
