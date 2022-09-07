/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Timer
*/

#ifndef Timer_HPP_
#define Timer_HPP_

#include "System.hpp"
#include "World.hpp"
#include "Component.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"

namespace System {
    class Timer : public Engine::System {
        public:
            Timer(std::string name);
            ~Timer();
            void update(float dt, Engine::World &gData);

        protected:
        private:
            size_t move;
    };
}

#endif /* !Timer_HPP_ */
