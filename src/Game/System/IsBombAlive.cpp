/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** IsBombAlive
*/

#include "IsBombAlive.hpp"
#include "System.hpp"
#include "Map.hpp"

namespace System {

    IsBombAlive::IsBombAlive(std::string name) : Engine::System(name)
    {
    }

    IsBombAlive::~IsBombAlive()
    {
    }

    void IsBombAlive::update(float dt, Engine::World &gData)
    {
        Entities::Factory f(gData);
        for (auto const& entity : mEntities)
        {
            //auto player = coord.getComponentType<GameComponents::Player>();
            auto &health = gData.getComponent<GameComponents::Health>(entity);
            auto &transform = gData.getComponent<GameComponents::Transform>(entity);
            auto &mapEl = gData.getComponent<GameComponents::MapElement>(entity);
            auto &map = *mapEl.map.get();

            if (health.pv == 0) {
                Entity explosion = f.createFromFile("src/Game/baseEntities/explosion.json");
                auto &transformExplo = gData.getComponent<GameComponents::Transform>(explosion);
                auto &mapElExplo = gData.getComponent<GameComponents::MapElement>(explosion);
                transformExplo.position.x = mapEl.position[0];
                transformExplo.position.y = transform.position.y;
                transformExplo.position.z = mapEl.position[1];
                mapElExplo.position[0] = mapEl.position[0];
                mapElExplo.position[1] = mapEl.position[1];
                map[mapEl.position[1]][mapEl.position[0]] = MAP_NONE;
                gData.destroyEntity(entity);
            }
        }
    }
}
