#pragma once

#include "Sound.h"

typedef struct Mix_Chunk Mix_Chunk;


class SoundSDL : public SoundBase
{
public:

	SoundSDL();
	virtual ~SoundSDL();

	virtual void loadSound(const char* path) override;
	virtual void destroySound() override;

	virtual void playSound(float volume = 1.0F, float pitch = 1.0F) override;

private:

	Mix_Chunk* wav;
};
