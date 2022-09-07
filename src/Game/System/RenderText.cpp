/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RenderText
*/

#include "RenderText.hpp"

namespace System {

  RenderText::RenderText(std::string name) : Engine::System(name)
  {
  }

  RenderText::~RenderText()
  {
  }

  void RenderText::update(float dt, Engine::World &gdata)  // rendered + text + transform
  {
    for (auto& it : this->mEntities) {
      SYS_LOG(it);
      SYS_LOG("rendering text");
      auto &pos = gdata.getComponent<GameComponents::Transform>(it);
      auto &text = gdata.getComponent<GameComponents::Text>(it);

      text.position.x = pos.position.x;
      text.position.y = pos.position.y;
      text.model->draw();
    }
  }

}





