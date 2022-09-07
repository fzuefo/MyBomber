/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** EncRaylibText.hpp
*/

#pragma once

#include "IndieStudio.hpp"

/**
 * @brief Namespace for the encapsulation Raylib functions
 */
namespace Raylib {

    /**
     * @brief Class for the encapsulation of the Raylib Text functions
     */
    class RaylibText {
        public:
            RaylibText(std::string  text, const std::string &fontPath);
            ~RaylibText();

            void draw();

            void setFont(const std::string &fontPath);
            void setText(const std::string &text);
            void setPos(Vector2 pos);
            void setOrigin(Vector2 origin);
            void setRotation(float rotation);
            void setFontSize(float fontSize);
            void setSpacing(float spacing);
            void setColor(Color color);

            [[nodiscard]] Font getFont() const;
            [[nodiscard]] std::string getText() const;
            [[nodiscard]] Vector2 getPos() const;
            [[nodiscard]] Vector2 getOrigin() const;
            [[nodiscard]] float getRotation() const;
            [[nodiscard]] float getFontSize() const;
            [[nodiscard]] float getSpacing() const;
            [[nodiscard]] Color getColor() const;

        private:
            Font _font;
            std::string _text;
            Vector2 _position;
            Vector2 _origin;
            float _rotation;
            float _fontSize;
            float _spacing;
            Color _color;
    }; // class Text

} // namespace Raylib::Text