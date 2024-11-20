#include "InputRL.h"



int InputRL::getMouseX()
{
    return GetMouseX();
}

int InputRL::getMouseY()
{
    return GetMouseY();
}

bool InputRL::isMouseBtnDown(int b)
{
    return IsMouseButtonPressed(b);
}
