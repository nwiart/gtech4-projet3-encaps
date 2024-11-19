#pragma once

class Font 
{
public:
    virtual void loadFont(const char* path) = 0;
    virtual void destroyFont() = 0;
};
