/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ControlCamera
*/

#ifndef ControlCamera_HPP_
#define ControlCamera_HPP_

#include "System.hpp"
#include "World.hpp"

namespace System {
    class ControlCamera : public Engine::System {
        public:
            ControlCamera(std::string name);
            ~ControlCamera();
            void update(float dt, Engine::World &gdata);

        protected:
        private:
    };
}

#endif /* !ControlCamera_HPP_ */
