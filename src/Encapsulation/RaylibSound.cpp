/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibSound.cpp
*/

#include "RaylibSound.hpp"

namespace Raylib {

    /**
     * @brief Construct a new RaylibSound::CSound object
     * @param soundPath: The path of the sound
     * @return Nothing
     */
    RaylibSound::RaylibSound(const std::string &soundPath) : _sound(LoadSound(soundPath.c_str())), _volume(1.0f)
    {
    }

    /**
     * @brief Destroy the RaylibSound::CSound object
     * @return Nothing
     */
    RaylibSound::~RaylibSound()
    {
        UnloadSound(_sound);
    }

    /**
     * @brief Play the sound
     * @return Nothing
     */
    void RaylibSound::play()
    {
        PlaySound(_sound);
    }

    /**
     * @brief Stop the sound
     * @return Nothing
     */
    void RaylibSound::stop()
    {
        StopSound(_sound);
    }

    /**
     * @brief Pause the sound
     * @return Nothing
     */
    void RaylibSound::pause()
    {
        PauseSound(_sound);
    }

    /**
     * @brief Resume the sound
     * @return Nothing
     */
    void RaylibSound::resume()
    {
        ResumeSound(_sound);
    }

    /**
     * @brief Restart the sound
     * @return Nothing
     */
    void RaylibSound::restart()
    {
        StopSound(_sound);
        PlaySound(_sound);
    }

    /**
     * @brief Check if the sound is playing
     * @return True if the sound is playing, false otherwise
     */
    bool RaylibSound::isPlaying()
    {
        return IsSoundPlaying(_sound);
    }

    /**
     * @brief Set the volume of the sound
     * @param volume: The volume of the sound
     * @return Nothing
     */
    void RaylibSound::setVolume(float volume)
    {
        _volume = volume;
        SetSoundVolume(_sound, _volume);
    }

    /**
     * @brief Get the volume of the sound
     * @return The volume of the sound
     */
    float RaylibSound::getVolume() const
    {
        return _volume;
    }

}
