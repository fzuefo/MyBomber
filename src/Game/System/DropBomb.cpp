/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** DropBomb
*/

#include "DropBomb.hpp"
#include "System.hpp"
#include "Factory.hpp"
#include "Map.hpp"

namespace System {

    DropBomb::DropBomb(std::string name) : Engine::System(name)
    {
    }

    DropBomb::~DropBomb()
    {
    }

    void DropBomb::init(Engine::World &gData)
    {
        gData.AddEventListener(METHOD_LISTENER(Engine::EventType::KEY_PRESSED, DropBomb::listener));
    }

    void DropBomb::addPlayer(Entity player, Engine::Keys dropKey)
    {
        _playerDropKeys[player] = dropKey;
        _playerDrop[player] = false;
    }

    void DropBomb::listener(Engine::Event &ev)
    {
        auto key = ev.getData();

        for (auto &it: _playerDropKeys) {
            _applyDrop(it.first, key, it.second);
        }
    }

    void DropBomb::_applyDrop(Entity player, EventId key, Engine::Keys dropKey)
    {
        if (key == dropKey) {
            std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
            _playerDrop[player] = true;
        }
    }

    void DropBomb::update(float dt, Engine::World &gData)
    {
        Entities::Factory f(gData);
        for (auto const& player : mEntities)
        {
            if (_playerDrop[player] == true) {
                std::cout << __FUNCTION__ << std::endl;
                Entity bomb = f.createFromFile("src/Game/baseEntities/bomb.json");
                //auto player = coord.getComponentType<GameComponents::Player>();
                auto &transform = gData.getComponent<GameComponents::Transform>(player);
                auto &mapEl = gData.getComponent<GameComponents::MapElement>(player);
                auto &map = *mapEl.map.get();
                auto &transformBomb = gData.getComponent<GameComponents::Transform>(bomb);
                auto &mapElBomb = gData.getComponent<GameComponents::MapElement>(bomb);
                auto &model = gData.getComponent<GameComponents::Model>(bomb);


                // placing the bomb right on the center of la case.
                // y and z are switched in a 3d context
                transformBomb.position.x = mapEl.position[0] * 2;
                transformBomb.position.y = 0;
                transformBomb.position.z = mapEl.position[1] * 2;
                mapElBomb.position[0] = mapEl.position[0];
                mapElBomb.position[1] = mapEl.position[1];
                map[mapEl.position[1]][mapEl.position[0]] = MAP_BOMB;
                model.model->setPos(transform.position);
                _playerDrop[player] = false;
            }
        }
    }

}
