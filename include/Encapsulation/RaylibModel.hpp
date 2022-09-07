/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibModel
*/

#ifndef RAYLIBMODEL_HPP_
#define RAYLIBMODEL_HPP_

#include "IndieStudio.hpp"

namespace Raylib
{
    class RaylibModel {
        public:
            RaylibModel(
                const std::string &filename,
                const Vector3 &pos,
                const Vector3 &rotationAxis,
                const float &rotationAngle,
                const Vector3 &scale,
                const Color &color,
                const Vector3 &matrixRotate = { 0, 0, 0 }
            );
            ~RaylibModel();
            void setModel(const std::string &filename);
            void setPos(const Vector3 &pos);
            void setScale(const Vector3 &scale);
            void setColor(const Color &color);
            void setAngle(float angle)
            {
	      _rotationAngle = angle;
	    }

            void setMaterialTexture(
                const int &mapType,
                const Texture2D &texture
            );
            void setMatrixRotate(const Vector3 &matrixRotate);
            void unsetModel();
            void draw() const;
            Model getModel() const;
            Vector3 getPos() const;
            Vector3 getScale() const;
            Color getColor() const;
            Vector3 getMatrixRotate() const;

        private:
            Model _model;
            Vector3 _pos;
            Vector3 _rotationAxis;
            float _rotationAngle;
            Vector3 _scale;
            Color _tint;
            Vector3 _matrixRotate;
    };
}

#endif /* !RAYLIBMODEL_HPP_ */
