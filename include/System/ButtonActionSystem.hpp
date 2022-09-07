/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ButtonActionSystem
*/

#ifndef ButtonActionSystem_HPP_
#define ButtonActionSystem_HPP_

#include "System.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"
#include "World.hpp"

namespace System {
    class ButtonActionSystem : public Engine::System {
        public:
            enum KeyPressed {
                ENTER,
                PAT,            /// FOR PATRICK BUTTON so key P
                NONE
            };
            ButtonActionSystem(std::string name);
            ~ButtonActionSystem();
            void update();
            void init(Engine::World &gData);
            void listener(Engine::Event &ev);
            void chek_key(Entity player, EventId key, std::array<Engine::Keys, 2> &keys);
            size_t getStatus()
            {
                return status;
            }
        private:
            size_t status;
            size_t tmpStatus;
            std::vector<std::array<Engine::Keys, 2>> _buttonKey;
    };
}

#endif /* !ButtonActionSystem_HPP_ */
