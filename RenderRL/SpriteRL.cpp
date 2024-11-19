#include "SpriteRL.h"


SpriteRL::SpriteRL()
    : rect({0, 0, 100, 100})
{

}

void SpriteRL::loadTexture(const char* path)
{
    s = LoadTexture(path);
}

void SpriteRL::destroyTexture()
{
    UnloadTexture(s);
}

void SpriteRL::setPosition(int newX, int newY)
{
    rect.x = newX;
    rect.y = newY;
}

void SpriteRL::getPosition(int& outX, int& outY) const
{
    outX = rect.x;
    outY = rect.y;
}

void SpriteRL::setSize(int w, int h)
{
    rect.width = w;
    rect.height = h;
}

void SpriteRL::setColor(ColorRGBA c)
{
    color = c;
}
