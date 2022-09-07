/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibWindow
*/

#ifndef RAYLIBWINDOW_HPP_
#define RAYLIBWINDOW_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibWindow
    {   
        public:
            RaylibWindow(
                const int &width,
                const int &height,
                const std::string &title
            );
            ~RaylibWindow();
            void setTargetFPS(const int &fps);
            int getScreenWidth();
            int getScreenHeight();
            bool windowShouldClose();
            void beginDrawing();
            void endDrawing();
            void clearBackground();
    };
}

#endif /* !RAYLIBWINDOW_HPP_ */
