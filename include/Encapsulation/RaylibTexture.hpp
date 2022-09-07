/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibTexture.hpp
*/

#pragma once

#include "IndieStudio.hpp"

/**
 * @brief Namespace for encapsulation of Raylib Texture functions
 */
namespace Raylib {

    /**
     * @brief Class for encapsulation of Raylib Texture functions
     */
    class RaylibTexture {
        public:
            explicit RaylibTexture(const std::string &texturePath);
            ~RaylibTexture();

            void draw();

            void setTexture(const std::string &texturePath);
            void setPosition(Vector2 position);
            void setRotation(float rotation);
            void setScale(float scale);
            void setColor(Color color);

            [[nodiscard]] Texture2D getTexture() const;
            [[nodiscard]] Vector2 getPosition() const;
            [[nodiscard]] float getRotation() const;
            [[nodiscard]] float getScale() const;
            [[nodiscard]] Color getColor() const;

        private:
            Texture2D _texture;
            Vector2 _position;
            float _rotation;
            float _scale;
            Color _color;
    }; // class Texture
} // namespace Raylib