/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RenderText
*/



#include "World.hpp"
#include "Event.hpp"
#include "GameComponents.hpp"

#ifndef RenderText_HPP_
#define RenderText_HPP_

namespace System {
    class RenderText : public Engine::System {
        public:
      RenderText(std::string name);
      ~RenderText();
      void update(float dt, Engine::World &gdata);
    protected:
        private:
    };
}

#endif /* !RenderText_HPP_ */
