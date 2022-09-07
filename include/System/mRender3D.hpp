/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Render3D
*/

#ifndef MRENDER3D_HPP_
#define MRENDER3D_HPP_

#include "World.hpp"
#include "Event.hpp"
#include "GameComponents.hpp"

class mRender3D : public Engine::System {
public:
  mRender3D(std::string name);
  ~mRender3D();
  void update(float dt, Engine::World &gdata);
  
protected:
private:
};

#endif /* !Render3D_HPP_ */
