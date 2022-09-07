/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Animation3D
*/

#include "Animation3D.hpp"
#include <functional>
	
namespace System {

  Animation3D::Animation3D(std::string name) : Engine::System(name)
  {
  }

  Animation3D::~Animation3D()
  {
  }

  void Animation3D::setFunc(GameComponents::Model &mod, std::function<void(Entity, Raylib::AnimTypeEnum)> const &func)
  {
    mod.animation = func;
  }


  void Animation3D::update(float dt, Engine::World &gData)
  {
    for (auto& it : this->mEntities) {
      auto &mod = gData.getComponent<GameComponents::Model>(it);
      auto &anim = gData.getComponent<GameComponents::Animate>(it);
      if (!anim._anim) {
        anim._anim = std::make_shared<Raylib::RaylibModelAnimation>(mod.path_mod, Raylib::WALK, anim.delay);
        anim._anim->setModel(mod.model->getModel());
      }
      if (mod.animation == nullptr) {
        this->setFunc(mod,std::bind(&Animation3D::swapType, this, std::placeholders::_1, std::placeholders::_2));
      }
      if (newAnim.contains(it)) {
        anim._anim->setType(newAnim[it]);
      }
	    anim._anim->animate();
    }
      newAnim.clear();
  }

    void Animation3D::swapType(Entity entity, Raylib::AnimTypeEnum type)
    {
      this->newAnim.insert({entity, type});
    }
}
