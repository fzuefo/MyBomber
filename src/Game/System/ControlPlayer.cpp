/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ControlPlayer
*/

#include "ControlPlayer.hpp"
#include "Map.hpp"
#include <cmath>

#define ABS(x) (x) > 0 ? (x) : ((x) * -1)

namespace System {

    void ControlPlayer::init(Engine::World &gData)
    {
        gData.AddEventListener(METHOD_LISTENER(Engine::EventType::KEY_PRESSED, ControlPlayer::listener));
    }

    void ControlPlayer::addPlayer(Entity player, std::array<Engine::Keys, 4> &movementKeys)
    {
        _playerMovementKeys[player] = movementKeys;
        _playerNextMove[player] = MovementDirection::NONE;
    }

    ControlPlayer::ControlPlayer(std::string name) : Engine::System(name)
    {
    }

    ControlPlayer::~ControlPlayer()
    {
    }

    void ControlPlayer::listener(Engine::Event &ev)
    {
        auto key = ev.getData();

        for (auto &it: _playerMovementKeys) {
            _applyMovement(it.first, key, it.second);
        }
    }

    void ControlPlayer::_applyMovement(Entity player, EventId key, std::array<Engine::Keys, 4> &keys)
    {
        for (int i = 0; i < 4; i++) {
            if (key == keys[i]) {
                _playerNextMove[player] = static_cast<MovementDirection>(i);
            }
        }
    }

    void ControlPlayer::addAi(Entity ai)
    {
        if (_playerMovementKeys.find(ai) != _playerMovementKeys.end())
            _playerMovementKeys.erase(ai);
        _playerNextMove[ai] = NONE;
    }

    void ControlPlayer::moveAi(Entity ai, ControlPlayer::MovementDirection dir)
    {
        _playerNextMove[ai] = dir;
    }

    void ControlPlayer::update(float dt, Engine::World &gData)
    {
        // I changed the mEntities from private to protected to acces
        static float dtb = 0;
        dtb += dt;
        for (auto const& entity : mEntities)
        {
            auto &transform = gData.getComponent<GameComponents::Transform>(entity);
            auto &model = gData.getComponent<GameComponents::Model>(entity);
            auto &velocity = gData.getComponent<GameComponents::Velocity>(entity);
            auto &mapEl = gData.getComponent<GameComponents::MapElement>(entity);
            auto &pos = mapEl.position;
            auto &map = *(mapEl.map.get());
            int directionSign;
            float *transformAxis;
            unsigned int *positionAxis;

	        switch (_playerNextMove[entity]) {
                case UP:
                    directionSign = -1;
                    // y and z are inverted in 3d display
                    transformAxis = &(transform.position.z);
                    positionAxis = &pos[1];
                    model.model->setAngle(180);
                    model.animation(entity, Raylib::WALK);
                    break;
                case DOWN:
                    directionSign = 1;
                    transformAxis = &(transform.position.z);
                    positionAxis = &(pos[1]);
                    model.model->setAngle(0);
                    model.animation(entity, Raylib::WALK);
           	        break;
                case RIGHT:
                    directionSign = 1;
                    transformAxis = &(transform.position.x);
                    positionAxis = &pos[0];
                    model.model->setAngle(90);
	 	            model.animation(entity, Raylib::WALK);
           	        break;
                case LEFT:
                    directionSign = -1;
                    transformAxis = &(transform.position.x);
                    positionAxis = &(pos[0]);
		            model.model->setAngle(270);
            	    model.animation(entity, Raylib::WALK);
                    break;
                default:
            	    model.animation(entity, Raylib::FLOSS);
                    continue;
            }
            _playerNextMove[entity] = NONE;
            bool isCentered = ABS((*transformAxis / 2.0) - *positionAxis) <= 0.1;
            if (isCentered || !_collide(directionSign, map, pos, positionAxis)) {
                if (map[pos[1]][pos[0]] == MAP_PLAYER)
                    map[pos[1]][pos[0]] = MAP_NONE;
                *transformAxis += directionSign * velocity.speed * dt * 2;
                *positionAxis = round(*transformAxis / 2.0);
                model.model->setPos(transform.position);
                if (map[pos[1]][pos[0]] == MAP_NONE)
                    map[pos[1]][pos[0]] = MAP_PLAYER;
                if (dtb > 1) {
                   for (auto &it: map)
                        std::cout << it << std::endl;
                    dtb = 0;
                    std::cout << std::endl << std::endl;
                }
            }
        }
        // - texture 2d
        // - transform
    }

    bool ControlPlayer::_collide(int nextMoveSign, map_2d &map, std::array<unsigned int, 2> &position, unsigned int *axis)
    {
        bool ret;
        char block = map[position[1]][position[0]];

        *axis += nextMoveSign;
        block = map[position[1]][position[0]];
        ret = block != MAP_NONE;
        *axis -= nextMoveSign;
        return ret;
    }
}
