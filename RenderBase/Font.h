#pragma once

class Text;

class FontBase
{
public:
    virtual ~FontBase() { }

    virtual void loadFont(const char* path) = 0;
    virtual void destroyFont() = 0;

    virtual void renderText(const char* str, int x, int y) = 0;
};
