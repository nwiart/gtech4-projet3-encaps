#include "TextureRL.h"

void TextureRL::loadTexture(const char* path)
{
    s = LoadTexture(path);
}

void TextureRL::destroyTexture()
{
    UnloadTexture(s);
}

void* TextureRL::getTexture() const
{
    return (void*)&s;
}
