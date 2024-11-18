#include "SpriteRL.h"


SpriteRL::SpriteRL()
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
    x = newX;
    y = newY;
}

void SpriteRL::getPosition(int& outX, int& outY) const
{
    outX = x;
    outY = y;
}

void SpriteRL::setSize(int w, int h)
{

}

