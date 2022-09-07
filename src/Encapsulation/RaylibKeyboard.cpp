/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibKeyboard
*/

#include "RaylibKeyboard.hpp"

namespace Raylib
{
    RaylibKeyboard::RaylibKeyboard(const int &key)
    {
        _key = key;
    }

    RaylibKeyboard::~RaylibKeyboard()
    {

    }

    void RaylibKeyboard::setKey(const int &key)
    {
        _key = key;
    }

    void RaylibKeyboard::setExitKey()
    {
        SetExitKey(_key);
    }

    int RaylibKeyboard::getKeyPressed()
    {
        return GetKeyPressed();
    }

    int RaylibKeyboard::getCharPressed()
    {
        return GetCharPressed();
    }

    bool RaylibKeyboard::isKeyPressed()
    {
        return IsKeyPressed(_key);
    }

    bool RaylibKeyboard::isKeyDown()
    {
        return IsKeyDown(_key);
    }

    bool RaylibKeyboard::isKeyReleased()
    {
        return IsKeyReleased(_key);
    }

    bool RaylibKeyboard::isKeyUp()
    {
        return IsKeyUp(_key);
    }

}
