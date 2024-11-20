#include "WindowRL.h"
#include "SpriteRL.h"
#include "FontRL.h"
#include "InputRL.h"
#include "rlgl.h"

InputRL* WindowRL::input = 0;

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
    SetConfigFlags(FLAG_VSYNC_HINT);

    input = new InputRL();

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

Input* WindowRL::getInput()
{
    return input;
}

Sprite* WindowRL::createSprite()
{
    SpriteRL* s = new SpriteRL();
    return s;
}

FontBase* WindowRL::createFont()
{
    FontRL* f = new FontRL();
    return f;
}

void WindowRL::setBackgroundColor(float r, float g, float b)
{
    color = ColorRGBA(r, g, b);
}

void WindowRL::beginDraw()
{
    BeginDrawing();
    //ClearBackground(Color{ color.getR(), color.getG(), color.getB(), color.getA()});
    
    rlSetBlendFactorsSeparate(0x0302, 0x0303, 1, 0x0303, 0x8006, 0x8006);
    BeginBlendMode(BLEND_CUSTOM_SEPARATE);
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{ color.getR(), color.getG(), color.getB(), 20 });
    EndBlendMode();
}

void WindowRL::drawSprite(Sprite* sprite)
{
    SpriteRL* s = reinterpret_cast<SpriteRL*>(sprite);

    if (!s)
    {
        return;
    }

    ColorRGBA& c = s->color;
    DrawTexturePro(s->s, Rectangle{ 0, 0,  (float)s->s.width,  (float)s->s.height }, s->rect, {s->rect.width / 2, s->rect.height / 2}, 0, Color{c.getR(), c.getG(), c.getB(), 255});
}

void WindowRL::endDraw()
{
    EndDrawing();
}
