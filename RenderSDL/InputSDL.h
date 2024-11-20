#pragma once

#include "Input.h"


class InputSDL : public Input
{
public:

    virtual int getMouseX() override;
    virtual int getMouseY() override;
    virtual bool isMouseBtnDown(int b) override;
};
