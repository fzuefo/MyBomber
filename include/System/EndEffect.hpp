/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EndEffect
*/

#ifndef EndEffect_HPP_
#define EndEffect_HPP_

#include "System.hpp"
#include "World.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"

namespace System {
    class EndEffect : public Engine::System {
        public:
            EndEffect(std::string name);
            ~EndEffect();
            void update(float dt, Engine::World &gData);

        protected:
        private:
    };
}

#endif /* !EndEffect_HPP_ */
