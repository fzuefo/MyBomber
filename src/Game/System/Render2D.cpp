/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RenderTexture
*/

#include "Render2D.hpp"

namespace System {

    render2DSysteme::render2DSysteme(std::string name) : Engine::System(name)
    {
    }

    render2DSysteme::~render2DSysteme()
    {
    }

    void render2DSysteme::update(float dt, Engine::World &gdata)
    {
      for (auto& it : this->mEntities) {
        SYS_LOG(it);
        SYS_LOG("rendering 2D obe");
        auto &pos = gdata.getComponent<GameComponents::Transform>(it);
        auto &text = gdata.getComponent<GameComponents::Texture2D>(it);
        Vector2 tmp = {pos.position.x, pos.position.y};
      	text.sprite->setPosition(tmp);
	      text.sprite->draw();
      }
    }
}
