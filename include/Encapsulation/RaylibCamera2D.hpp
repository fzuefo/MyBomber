/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibCamera2D
*/

#ifndef RAYLIBCAMERA2D_HPP_
#define RAYLIBCAMERA2D_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibCamera2D {
        public:
            RaylibCamera2D(
                const Vector2 &offset,
                const float &rotation,
                const Vector2 &target,
                const float &zoom
            );
            ~RaylibCamera2D();
            void setOffset(const Vector2 &offset);
            void setRotation(const float &rotation);
            void setTarget(const Vector2 &target);
            void setZoom(const float &zoom);
            void setCamera2D(
                const Vector2 &offset,
                const float &rotation,
                const Vector2 &target,
                const float &zoom
            );
            Matrix getCameraMatrix2D();
            Vector2 getWorldToScreen2D(Vector2 position);
            Vector2 getScreenToWorld2D(Vector2 position);
            void beginMode2D();
            void endMode2D();

        private:
            Camera2D _camera2D;
    };
}

#endif /* !RAYLIBCAMERA2D_HPP_ */
