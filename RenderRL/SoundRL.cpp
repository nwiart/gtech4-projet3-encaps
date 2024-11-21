#include "SoundRL.h"

void SoundRL::loadSound(const char* path)
{
    s = LoadSound(path);
}

void SoundRL::destroySound()
{
    UnloadSound(s);
}

void SoundRL::playSound(float volume, float pitch)
{
    PlaySound(s);
    SetSoundPitch(s, pitch);
    SetSoundVolume(s, volume);
}