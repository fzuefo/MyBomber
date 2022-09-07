/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibMouse
*/

#include "RaylibMouse.hpp"

namespace Raylib
{
    RaylibMouse::RaylibMouse(const int &button)
    {
        _button = button;
    }

    RaylibMouse::~RaylibMouse()
    {

    }

    float RaylibMouse::getMouseWheelMove()
    {
        return GetMouseWheelMove();
    }

    int RaylibMouse::getMouseX()
    {
        return GetMouseX();
    }

    int RaylibMouse::getMouseY()
    {
        return GetMouseY();
    }

    Vector2 RaylibMouse::getMousePosition()
    {
        return GetMousePosition();
    }

    Vector2 RaylibMouse::getMouseDelta()
    {
        return GetMouseDelta();
    }

    bool RaylibMouse::isMouseButtonPressed()
    {
        return IsMouseButtonPressed(_button);
    }

    bool RaylibMouse::isMouseButtonDown()
    {
        return IsMouseButtonDown(_button);
    }

    bool RaylibMouse::isMouseButtonReleased()
    {
        return IsMouseButtonReleased(_button);
    }

    bool RaylibMouse::isMouseButtonUp()
    {
        return IsMouseButtonUp(_button);
    }

}
