/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** IsAlive
*/

#ifndef IsAlive_HPP_
#define IsAlive_HPP_

#include "World.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"
#include "Component.hpp"

namespace System {
    class IsAlive : public Engine::System {
        public:
            IsAlive(std::string name);
            ~IsAlive();
            void update(float dt, Engine::World &gData);

        protected:
        private:
    };
}

#endif /* !IsAlive_HPP_ */
