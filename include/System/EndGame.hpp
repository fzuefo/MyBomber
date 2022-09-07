/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EndGame
*/

#ifndef EndGame_HPP_
#define EndGame_HPP_

#include "System.hpp"
#include "World.hpp"

namespace System {
    class EndGame : public Engine::System {
        public:
            EndGame(std::string name);
            ~EndGame();
            void update(float dt, Engine::World &gdata);

        protected:
        private:
    };
}

#endif /* !EndGame_HPP_ */
