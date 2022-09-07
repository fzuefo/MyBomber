/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibCamera
*/

#ifndef RAYLIBCAMERA_HPP_
#define RAYLIBCAMERA_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibCamera {
        public:
            RaylibCamera(
                const float &fovy,
                const Vector3 &pos,
                const int &projection,
                const Vector3 &target,
                const Vector3 &up
            );
            ~RaylibCamera();
            void setCamera(
                const float &fovy,
                const Vector3 &pos,
                const int &projection,
                const Vector3 &target,
                const Vector3 &up
            );
            void setFovy(const float &fovy);
            void setPos(const Vector3 &pos);
            void setProjection(const int &projection);
            void setTarget(const Vector3 &target);
            void setUp(const Vector3 &up);
            void setCameraMode(int mode);
            void updateCamera();
            void setCameraPanControl(int keyPan);
            void setCameraAltControl(int keyAlt);
            void setCameraSmoothZoomControl(int keySmoothZoom);
            void setCameraMoveControls(
                int keyFront,
                int keyBack,
                int keyRight,
                int keyLeft,
                int keyUp,
                int keyDown
            );
            Camera getCamera() const;
            float getFovy() const;
            Vector3 getPos() const;
            int getProjection() const;
            Vector3 getTarget() const;
            Vector3 getUp() const;

        private:
            Camera _camera;
    };
}

#endif /* !RAYLIBCAMERA_HPP_ */
