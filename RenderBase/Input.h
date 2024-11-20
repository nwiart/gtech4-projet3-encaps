#pragma once

class Input 
{
    virtual int getMouseX() = 0;
    virtual int getMouseY() = 0;
    virtual bool isMouseBtnDown(int b) = 0;
};
