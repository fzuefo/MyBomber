/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibCamera2D
*/

#include "RaylibCamera2D.hpp"

namespace Raylib
{

    RaylibCamera2D::RaylibCamera2D(
        const Vector2 &offset,
        const float &rotation,
        const Vector2 &target,
        const float &zoom
    )
    {
        _camera2D.offset = offset;
        _camera2D.rotation = rotation;
        _camera2D.target = target;
        _camera2D.zoom = zoom;
    }

    RaylibCamera2D::~RaylibCamera2D()
    {
        
    }

    void RaylibCamera2D::setOffset(const Vector2 &offset)
    {
        _camera2D.offset = offset;
    }

    void RaylibCamera2D::setRotation(const float &rotation)
    {
        _camera2D.rotation = rotation;
    }

    void RaylibCamera2D::setTarget(const Vector2 &target)
    {
        _camera2D.target = target;
    }

    void RaylibCamera2D::setZoom(const float &zoom)
    {
        _camera2D.zoom = zoom;
    }

    void RaylibCamera2D::setCamera2D(
        const Vector2 &offset,
        const float &rotation,
        const Vector2 &target,
        const float &zoom
    )
    {
        _camera2D.offset = offset;
        _camera2D.rotation = rotation;
        _camera2D.target = target;
        _camera2D.zoom = zoom;
    }

    Matrix RaylibCamera2D::getCameraMatrix2D()
    {
        return GetCameraMatrix2D(_camera2D);
    }

    Vector2 RaylibCamera2D::getWorldToScreen2D(Vector2 position)
    {
        return GetWorldToScreen2D(position, _camera2D);
    }

    Vector2 RaylibCamera2D::getScreenToWorld2D(Vector2 position)
    {
        return GetScreenToWorld2D(position, _camera2D);
    }

    void RaylibCamera2D::beginMode2D()
    {
        return BeginMode2D(_camera2D);
    }

    void RaylibCamera2D::endMode2D()
    {
        return EndMode2D();
    }

}
