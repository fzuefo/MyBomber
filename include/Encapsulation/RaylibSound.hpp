/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibSound.hpp
*/

#pragma once

#include "IndieStudio.hpp"

/**
 * @brief Namespace for the encapsulation of the Raylib Sound functions
 */
namespace Raylib {

    /**
     * @brief Class for the encapsulation of the Raylib Sound functions
     */
    class RaylibSound {
        public:
            explicit RaylibSound(const std::string &soundPath);
            ~RaylibSound();

            void play();
            void stop();
            void pause();
            void resume();
            void restart();

            bool isPlaying();

            void setVolume(float volume);

            [[nodiscard]] float getVolume() const;

        private:
            Sound _sound;
            float _volume;
    }; /* !CSound */
} /* !Raylib */