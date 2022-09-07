/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Render3D
*/

#include "mRender3D.hpp"

mRender3D::mRender3D(std::string name) : Engine::System(name)
{
}

mRender3D::~mRender3D()
{
}

void mRender3D::update(float dt, Engine::World &gdata)
{
  for (auto& it : this->mEntities) {
    SYS_LOG(it);
    SYS_LOG("rendering");
    auto &pos = gdata.getComponent<GameComponents::Transform>(it);
    auto &mod = gdata.getComponent<GameComponents::Model>(it);
    
    mod.model->setPos(pos.position);      
    mod.model->draw();
  }
} 
