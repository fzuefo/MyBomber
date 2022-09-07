/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibMusic.cpp
*/
#include "RaylibMusic.hpp"

namespace Raylib {

    /**
     * @brief Constructor of the Raylib Music class
     * @param musicPath: Path to the music file
     * @return Instance of the Raylib Music class
     */
    RaylibMusic::RaylibMusic(const std::string &musicPath) : _music(LoadMusicStream(musicPath.c_str())), _volume(1.0f)
    {
    }

    /**
     * @brief Destructor of the Raylib Music class
     */
    RaylibMusic::~RaylibMusic()
    {
        UnloadMusicStream(_music);
    }

    /**
     * @brief Play the music
     * @return Nothing
     */
    void RaylibMusic::play()
    {
        PlayMusicStream(_music);
    }

    /**
     * @brief Stop the music
     * @return Nothing
     */
    void RaylibMusic::stop()
    {
        StopMusicStream(_music);
    }

    /**
     * @brief Pause the music
     * @return Nothing
     */
    void RaylibMusic::pause()
    {
        PauseMusicStream(_music);
    }

    /**
     * @brief Resume the music
     * @return Nothing
     */
    void RaylibMusic::resume()
    {
        ResumeMusicStream(_music);
    }

    /**
     * @brief Restart the music
     * @return Nothing
     */
    void RaylibMusic::restart()
    {
        StopMusicStream(_music);
        PlayMusicStream(_music);
    }

    /**
     * @brief Check if the music is playing
     * @return True if the music is playing, false otherwise
     */
    bool RaylibMusic::isPlaying()
    {
        return IsMusicStreamPlaying(_music);
    }

    /**
     * @brief Set the volume of the music
     * @param volume: Volume to set
     * @return Nothing
     */
    void RaylibMusic::setVolume(float volume)
    {
        _volume = volume;
        SetMusicVolume(_music, _volume);
    }

    /**
     * @brief Get the volume of the music
     * @return The volume of the music
     */
    float RaylibMusic::getVolume() const
    {
        return _volume;
    }
}
