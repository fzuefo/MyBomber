/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Animation3D
*/

#ifndef Animation3D_HPP_
#define Animation3D_HPP_
#include "World.hpp"
#include "Event.hpp"
#include "GameComponents.hpp"

#include <functional>
namespace System {
    class Animation3D : public Engine::System {
        public:
            Animation3D(std::string name);
            ~Animation3D();
            void update(float dt, Engine::World &gdata);
      void swapType(Entity entity, Raylib::AnimTypeEnum type);
      void setFunc(GameComponents::Model &mod, std::function<void(Entity, Raylib::AnimTypeEnum)> const &func);

        protected:
        private:
      std::map<Entity, Raylib::AnimTypeEnum> newAnim;
    };
  
}
#define METHODE_ANIMATION(func) std::bind(&func, this, std::placeholders::_1)


#endif /* !Animation3D_HPP_ */
