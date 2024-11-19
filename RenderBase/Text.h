#pragma once

#include "Color.h"

class Text
{
    friend class Window;

public:
    Text() { }
    virtual ~Text() { }

    virtual void setPosition(int x, int y) = 0;
    virtual void setSize(int w, int h) = 0;

    virtual void setColor(ColorRGBA color) = 0;

};