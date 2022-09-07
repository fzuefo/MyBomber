/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EndEffect
*/

#include "EndEffect.hpp"
#include "World.hpp"
#include "Component.hpp"

namespace System {

    EndEffect::EndEffect(std::string name) : Engine::System(name)
    {
    }

    EndEffect::~EndEffect()
    {
    }

    void EndEffect::update(float dt, Engine::World &gData)
    {
        for (auto const& entity : mEntities)
        {
            auto &effect = gData.getComponent<GameComponents::Effect>(entity);
            auto &hp = gData.getComponent<GameComponents::Health>(entity);

	    if (effect.time >= effect.duration) {
	      hp.pv = 0;
            }
            effect.time += dt;
        }
    }
}
