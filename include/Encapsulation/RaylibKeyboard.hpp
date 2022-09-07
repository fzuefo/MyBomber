/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibKeyboard
*/

#ifndef RAYLIBKEYBOARD_HPP_
#define RAYLIBKEYBOARD_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibKeyboard {
        public:
            RaylibKeyboard(const int &key);
            ~RaylibKeyboard();
            void setKey(const int &key);
            void setExitKey();
            int getKeyPressed();
            int getCharPressed();
            bool isKeyPressed();
            bool isKeyDown();
            bool isKeyReleased();
            bool isKeyUp();

        private:
            int _key;
    };
}

#endif /* !RAYLIBKEYBOARD_HPP_ */
