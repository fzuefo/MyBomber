/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** IsBombAlive
*/

#ifndef IsBombAlive_HPP_
#define IsBombAlive_HPP_

#include "System.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"
#include "World.hpp"
#include "Factory.hpp"

namespace System {
    class IsBombAlive : public Engine::System {
        public:
            IsBombAlive(std::string name);
            ~IsBombAlive();
            void update(float dt, Engine::World &gData);

        protected:
        private:
    };
}

#endif /* !IsBombAlive_HPP_ */
