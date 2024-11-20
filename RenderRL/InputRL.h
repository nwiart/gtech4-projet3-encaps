#pragma once

#include "Input.h"
#include "raylib.h"

class InputRL : public Input
{
    virtual int getMouseX() override;
    virtual int getMouseY() override;
    virtual bool isMouseBtnDown(int b) override;
};