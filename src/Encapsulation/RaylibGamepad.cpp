/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibGamepad
*/

#include "RaylibGamepad.hpp"

namespace Raylib
{
    RaylibGamepad::RaylibGamepad(const int &gamepad, const int &button)
    {
        _gamepad = gamepad;
        _button = button;
    }

    RaylibGamepad::~RaylibGamepad()
    {

    }

    void RaylibGamepad::setGamepad(const int &gamepad)
    {
        _gamepad = gamepad;
    }

    void RaylibGamepad::setButton(const int &button)
    {
        _button = button;
    }

    int RaylibGamepad::setGamepadMappings(const std::string &mappings)
    {
        return SetGamepadMappings(mappings.c_str());
    }

    const std::string RaylibGamepad::getGamepadName()
    {
        return std::string(GetGamepadName(_gamepad));
    }

    int RaylibGamepad::getGamepadButtonPressed()
    {
        return GetGamepadButtonPressed();
    }

    int RaylibGamepad::getGamepadAxisCount()
    {
        return GetGamepadAxisCount(_gamepad);
    }

    float RaylibGamepad::getGamepadAxisMovement(int axis)
    {
        return GetGamepadAxisMovement(_gamepad, axis);
    }

    bool RaylibGamepad::isGamepadAvailable()
    {
        return IsGamepadAvailable(_gamepad);
    }

    bool RaylibGamepad::isGamepadButtonPressed()
    {
        return IsGamepadButtonPressed(_gamepad, _button);
    }

    bool RaylibGamepad::isGamepadButtonDown()
    {
        return IsGamepadButtonDown(_gamepad, _button);
    }

    bool RaylibGamepad::isGamepadButtonReleased()
    {
        return IsGamepadButtonReleased(_gamepad, _button);
    }

    bool RaylibGamepad::isGamepadButtonUp()
    {
        return IsGamepadButtonUp(_gamepad, _button);
    }

}
