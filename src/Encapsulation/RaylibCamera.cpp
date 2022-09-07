/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibCamera
*/

#include "RaylibCamera.hpp"

namespace Raylib
{
    RaylibCamera::RaylibCamera(
        const float &fovy,
        const Vector3 &pos,
        const int &projection,
        const Vector3 &target,
        const Vector3 &up
    )
    {
        _camera.fovy = fovy;
        _camera.position = { pos.x, pos.y, pos.z };
        _camera.projection = projection;
        _camera.target = { target.x, target.y, target.z };
        _camera.up = { up.x, up.y, up.z };
    }

    RaylibCamera::~RaylibCamera()
    {

    }

    void RaylibCamera::setCamera(
        const float &fovy,
        const Vector3 &pos,
        const int &projection,
        const Vector3 &target,
        const Vector3 &up
    )
    {
        _camera.fovy = fovy;
        _camera.position = { pos.x, pos.y, pos.z };
        _camera.projection = projection;
        _camera.target = { target.x, target.y, target.z };
        _camera.up = { up.x, up.y, up.z };
    }

    void RaylibCamera::setFovy(const float &fovy)
    {
        _camera.fovy = fovy;
    }

    void RaylibCamera::setPos(const Vector3 &pos)
    {
        _camera.position = { pos.x, pos.y, pos.z };
    }

    void RaylibCamera::setProjection(const int &projection)
    {
        _camera.projection = projection;
    }

    void RaylibCamera::setTarget(const Vector3 &target)
    {
        _camera.target = { target.x, target.y, target.z };
    }

    void RaylibCamera::setUp(const Vector3 &up)
    {
        _camera.up = { up.x, up.y, up.z };
    }


    void RaylibCamera::setCameraMode(int mode)
    {
        SetCameraMode(_camera, mode);
    }

    void RaylibCamera::updateCamera()
    {
        UpdateCamera(&_camera);
    }

    void RaylibCamera::setCameraPanControl(int keyPan)
    {
        SetCameraPanControl(keyPan);
    }

    void RaylibCamera::setCameraAltControl(int keyAlt)
    {
        SetCameraAltControl(keyAlt);
    }

    void RaylibCamera::setCameraSmoothZoomControl(int keySmoothZoom)
    {
        SetCameraSmoothZoomControl(keySmoothZoom);
    }

    void RaylibCamera::setCameraMoveControls(
        int keyFront,
        int keyBack,
        int keyRight,
        int keyLeft,
        int keyUp,
        int keyDown
    )
    {
        SetCameraMoveControls(keyFront, keyBack, keyRight,
                            keyLeft, keyUp, keyDown);
    }

    Camera RaylibCamera::getCamera() const
    {
        return _camera;
    }

    float RaylibCamera::getFovy() const
    {
        return _camera.fovy;
    }

    Vector3 RaylibCamera::getPos() const
    {
        return _camera.position;
    }

    int RaylibCamera::getProjection() const
    {
        return _camera.projection;
    }

    Vector3 RaylibCamera::getTarget() const
    {
        return _camera.target;
    }

    Vector3 RaylibCamera::getUp() const
    {
        return _camera.up;
    }

}
