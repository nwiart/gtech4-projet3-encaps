#pragma once

#include "Texture.h"


class TextureSDL : public TextureBase
{
	friend class WindowSDL;

public:

	TextureSDL();
	virtual ~TextureSDL();

	virtual void loadTexture(const char* path) override;
	virtual void destroyTexture() override;
	virtual void* getTexture() const override;

private:

	SDL_Texture* texture;
};
