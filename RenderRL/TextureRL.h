#pragma once

#include "raylib.h"
#include "Texture.h"

class TextureRL : public Texture
{
public:
    virtual void loadTexture(const char* path) override;
    virtual void destroyTexture() override;
    virtual void* getTexture() const override;

private:
    Texture2D s;
};