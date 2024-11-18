#include "WindowRL.h"
#include "raylib.h"


WindowRL::WindowRL()
{

}

WindowRL::~WindowRL()
{

}

bool WindowRL::initialize()
{
    return true;
}

void WindowRL::quit()
{

}

bool WindowRL::createWindow(int width, int height, const char* title)
{
    InitWindow(width, height, title);
    SetTargetFPS(60);
    return true;
}

bool WindowRL::isWindowOpen() const
{
    return !WindowShouldClose();
}

void WindowRL::processEvents()
{
}

void WindowRL::setTitle(const char* title)
{
    SetWindowTitle(title);
}

Sprite* WindowRL::createSprite()
{
    return 0;
}

void WindowRL::setBackgroundColor(float r, float g, float b)
{
    color = ColorRGBA(r, g, b);
}

void WindowRL::beginDraw()
{
    BeginDrawing();
    ClearBackground(Color{ color.getR(), color.getG(), color.getB(), color.getA()});
}

void WindowRL::drawSprite(Sprite* sprite, int x, int y)
{
}


void WindowRL::endDraw()
{
    EndDrawing();
}