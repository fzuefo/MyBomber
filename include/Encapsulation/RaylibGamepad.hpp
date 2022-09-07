/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibGamepad
*/

#ifndef RAYLIBGAMEPAD_HPP_
#define RAYLIBGAMEPAD_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibGamepad {
        public:
            RaylibGamepad(const int &gamepad, const int &button);
            ~RaylibGamepad();
            void setGamepad(const int &gamepad);
            void setButton(const int &button);
            int setGamepadMappings(const std::string &mappings);
            const std::string getGamepadName();
            int getGamepadButtonPressed(void);
            int getGamepadAxisCount();
            float getGamepadAxisMovement(int axis);
            bool isGamepadAvailable();
            bool isGamepadButtonPressed();
            bool isGamepadButtonDown();
            bool isGamepadButtonReleased();
            bool isGamepadButtonUp();

        private:
            int _gamepad;
            int _button;
    };
}

#endif /* !RAYLIBGAMEPAD_HPP_ */
