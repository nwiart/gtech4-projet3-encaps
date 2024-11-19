#pragma once

#include "raylib.h"
#include "Font.h"

class FontRL : public FontBase
{
public:

    FontRL();
    virtual ~FontRL();

    virtual void loadFont(const char* path) override;
    virtual void destroyFont() override;
    virtual void renderText(const char* str, int x, int y);

private:
    Font font;
};
