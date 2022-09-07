/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** CollisionExplosion
*/

#ifndef CollisionExplosion_HPP_
#define CollisionExplosion_HPP_

#include "System.hpp"
#include "World.hpp"

namespace System {
    class CollisionExplosion : public Engine::System {
        public:
            CollisionExplosion(std::string name);
            ~CollisionExplosion();
            void update(float dt, Engine::World &gdata);

        protected:
        private:
    };
}

#endif /* !CollisionExplosion_HPP_ */
