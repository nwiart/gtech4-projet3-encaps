#pragma once

#include "raylib.h" 
#include "Text.h"

class TextRL : public Text
{
public:

    TextRL();
    virtual ~TextRL();
    virtual void setPosition(int x, int y) override;
    virtual void setSize(int w, int h) override;

    virtual void setColor(ColorRGBA color) override;
private:
    ColorRGBA color;
    int x; int y;
    int w; int h;
};
