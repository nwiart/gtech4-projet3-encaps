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
    DrawText(str, x, y, 0, WHITE);
}
