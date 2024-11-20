#pragma once

class Input 
{
    virtual void getMousePosition() = 0;
    virtual bool isMouseBtnDown(int b) = 0;
};
