/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ControlPlayer
*/

#ifndef CONTROLPLAYER_HPP_
#define CONTROLPLAYER_HPP_

#include "World.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"
// #include "World.hpp"

namespace System {
    using map_2d = std::vector<std::string>;
    class ControlPlayer : public Engine::System
    {
        public:
            enum MovementDirection {
                UP,
                LEFT,
                DOWN,
                RIGHT,
                NONE
            };
            ControlPlayer(std::string name);
            ~ControlPlayer();
            void init(Engine::World &gData);
            void addPlayer(Entity player, std::array<Engine::Keys, 4> &movementKeys);
            void listener(Engine::Event &ev);
            void update(float dt, Engine::World &gData);
            void moveAi(Entity ai, ControlPlayer::MovementDirection dir);
            void addAi(Entity ai);


        private:
            std::map<Entity, MovementDirection> _playerNextMove;
            std::map<Entity, std::array<Engine::Keys, 4>> _playerMovementKeys;
            void _applyMovement(Entity player, EventId key, std::array<Engine::Keys, 4> &keys);
            bool _collide(int directionSign, map_2d &map, std::array<unsigned int, 2> &position, unsigned int *axis);
    };
}

#endif /* !CONTROLPLAYER_HPP_ */
