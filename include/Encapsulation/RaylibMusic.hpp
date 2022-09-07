/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibMusic.hpp
*/

#pragma once

#include "IndieStudio.hpp"

/**
 * @brief Namespace for the encapsulation of the Raylib Music functions
 */
namespace Raylib {

    /**
     * @brief Class for the encapsulation of the Raylib Music functions
     */
    class RaylibMusic {
        public:
            explicit RaylibMusic(const std::string &musicPath);
            ~RaylibMusic();

            void play();
            void stop();
            void pause();
            void resume();
            void restart();

            bool isPlaying();

            void setVolume(float volume);

            [[nodiscard]] float getVolume() const;

        private:
            Music _music;
            float _volume;
    }; /* !RaylibMusic */
} /* !Raylib */