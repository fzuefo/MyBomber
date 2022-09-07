/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** System
*/

#ifndef RENDER2D_HPP_
#define RENDER2D_HPP_

#include "World.hpp"
#include "Event.hpp"
#include "GameComponents.hpp"

namespace System {
  class render2DSysteme : public Engine::System
  {
    public:
      render2DSysteme(std::string name);
      ~render2DSysteme();
      void update(float dt, Engine::World &gdata);
  };
}

#endif /* !RENDER2D_HPP_ */
