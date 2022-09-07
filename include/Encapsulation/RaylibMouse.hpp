/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibMouse
*/

#ifndef RAYLIBMOUSE_HPP_
#define RAYLIBMOUSE_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibMouse {
        public:
            RaylibMouse(const int &button);
            ~RaylibMouse();
            void setButton(const int &button);
            float getMouseWheelMove();
            int getMouseX();
            int getMouseY();
            Vector2 getMousePosition();
            Vector2 getMouseDelta();
            bool isMouseButtonPressed();
            bool isMouseButtonDown();
            bool isMouseButtonReleased();
            bool isMouseButtonUp();

        private:
            int _button;
    };   
}

#endif /* !RAYLIBMOUSE_HPP_ */
