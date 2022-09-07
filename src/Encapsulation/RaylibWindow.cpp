/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibWindow
*/

#include "RaylibWindow.hpp"

namespace Raylib
{
    RaylibWindow::RaylibWindow(const int &width, const int &height,
                            const std::string &title)
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        SetTargetFPS(60);
        InitWindow(width, height, title.c_str());
    }

    RaylibWindow::~RaylibWindow()
    {
        CloseWindow();
    }

    void setTargetFPS(const int &fps)
    {
        SetTargetFPS(fps);
    }

    int RaylibWindow::getScreenWidth()
    {
        return GetScreenWidth();
    }

    int RaylibWindow::getScreenHeight()
    {
        return GetScreenHeight();
    }

    bool RaylibWindow::windowShouldClose()
    {
        return WindowShouldClose();
    }

    void RaylibWindow::beginDrawing()
    {
        BeginDrawing();
    }
    
    void RaylibWindow::endDrawing()
    {
        EndDrawing();
    }

    void RaylibWindow::clearBackground()
    {
        ClearBackground(GRAY);
    }
}