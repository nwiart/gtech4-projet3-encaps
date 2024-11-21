#pragma once

class SoundBase
{
public:
    virtual void loadSound(const char* path) = 0;
    virtual void destroySound() = 0;
    virtual void playSound(float volume = 1, float pitch = 1) = 0;

};