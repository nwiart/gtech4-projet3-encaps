#pragma once

class TextureBase
{
public:
    virtual ~TextureBase() { }

    virtual void loadTexture(const char* path) = 0;
    virtual void destroyTexture() = 0;
    virtual void* getTexture() const = 0;
};