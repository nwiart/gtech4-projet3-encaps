#pragma once

#include "raylib.h"
#include "SoundBase.h"

class SoundRL : public SoundBase
{
public:
    virtual void loadSound(const char* path) override;
    virtual void destroySound() override;
    virtual void playSound(float volume = 1, float pitch = 1) override;
private:
    Sound s;

};