#include <SDL.h>
#include <SDL_mixer.h>
#include "SoundSDL.h"


SoundSDL::SoundSDL()
	: wav(0)
{

}

SoundSDL::~SoundSDL()
{
	this->destroySound();
}

void SoundSDL::loadSound(const char* path)
{
	wav = Mix_LoadWAV(path);
}

void SoundSDL::destroySound()
{
	if (wav) {
		Mix_FreeChunk(wav);
		wav = 0;
	}
}

void SoundSDL::playSound(float volume, float pitch)
{
	Mix_PlayChannel(-1, wav, 0);
}
