/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibModel
*/

#include "RaylibModel.hpp"
#include "raymath.h"

namespace Raylib
{   
    RaylibModel::RaylibModel(
        const std::string &filename,
        const Vector3 &pos,
        const Vector3 &rotationAxis,
        const float &rotationAngle,
        const Vector3 &scale,
        const Color &color,
        const Vector3 &matrixRotate
    )
    {
        _model = LoadModel(filename.c_str());
        _pos = pos;
        _rotationAxis = rotationAxis;
        _rotationAngle = rotationAngle;
        _scale = scale;
        _tint = color;
        if (matrixRotate.x != 0)
	        _model.transform = MatrixRotateX(DEG2RAD * matrixRotate.x);
        if (matrixRotate.y != 0)
	        _model.transform = MatrixRotateY(DEG2RAD * matrixRotate.y);
        if (matrixRotate.z != 0)
	        _model.transform = MatrixRotateZ(DEG2RAD * matrixRotate.z);
        _matrixRotate = matrixRotate;
    }

    RaylibModel::~RaylibModel()
    {
        UnloadModel(_model);
    }

    void RaylibModel::setModel(const std::string &filename)
    {
        _model = LoadModel(filename.c_str());
    }

    void RaylibModel::setPos(const Vector3 &pos)
    {
        _pos.x = pos.x;
        _pos.y = pos.y;
        _pos.z = pos.z;
    }

    void RaylibModel::setScale(const Vector3 &scale)
    {
        _scale = scale;
    }

    void RaylibModel::setColor(const Color &color)
    {
        _tint.a = color.a;
        _tint.b = color.b;
        _tint.g = color.g;
        _tint.r = color.r;
    }

    void RaylibModel::setMaterialTexture(const int &mapType, const Texture2D &texture)
    {
        SetMaterialTexture(&_model.materials[0], mapType, texture);
    }

    void RaylibModel::setMatrixRotate(const Vector3 &matrixRotate)
    {
        if (matrixRotate.x != 0)
	        _model.transform = MatrixRotateX(DEG2RAD * matrixRotate.x);
        if (matrixRotate.y != 0)
	        _model.transform = MatrixRotateY(DEG2RAD * matrixRotate.y);
        if (matrixRotate.z != 0)
	        _model.transform = MatrixRotateZ(DEG2RAD * matrixRotate.z);
        _matrixRotate = matrixRotate;   
    }
    
    void RaylibModel::unsetModel()
    {
        UnloadModel(_model);
    }

    void RaylibModel::draw() const
    {
        DrawModelEx(_model, _pos, _rotationAxis, _rotationAngle, _scale, _tint);
    }

    Model RaylibModel::getModel() const
    {
        return _model;
    }

    Vector3 RaylibModel::getPos() const
    {
        return _pos;
    }

    Vector3 RaylibModel::getScale() const
    {
        return _scale;
    }

    Color RaylibModel::getColor() const
    {
        return  _tint;
    }

    Vector3 RaylibModel::getMatrixRotate() const
    {
        return _matrixRotate;
    }

}
