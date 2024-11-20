#pragma once

class Input 
{
public:

    virtual int getMouseX() = 0;
    virtual int getMouseY() = 0;
    virtual bool isMouseBtnDown(int b) = 0;
};
