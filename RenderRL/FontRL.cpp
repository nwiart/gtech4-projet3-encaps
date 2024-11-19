#include "FontRL.h"

FontRL::FontRL()
{

}

FontRL::~FontRL()
{

}

void FontRL::loadFont(const char* path)
{
    font = LoadFont(path);
}

void FontRL::destroyFont()
{
    UnloadFont(font);
}

void FontRL::renderText(const char* str, int x, int y)
{
    DrawTextEx(font, str, Vector2{(float)x ,(float)y}, 16, 0, WHITE);
}
