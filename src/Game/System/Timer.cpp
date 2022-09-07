/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Timer
*/

#include "Timer.hpp"
#include "System.hpp"

namespace System {

    Timer::Timer(std::string name) : Engine::System(name)
    {
    }

    Timer::~Timer()
    {
    }

    void Timer::update(float dt, Engine::World &gData)
    {
        for (auto const& entity : mEntities)
        {
            auto &timer = gData.getComponent<GameComponents::Timer>(entity);

            timer.timer += dt;
        }
    }
}
