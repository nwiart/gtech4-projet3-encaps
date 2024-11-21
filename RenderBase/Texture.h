#pragma once

class Texture
{
public:
    virtual void loadTexture(const char* path) = 0;
    virtual void destroyTexture() = 0;
};