/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** System
*/

#include "System.hpp"

namespace Engine {

  System::System(std::string name)
  {
    _name = name;
  }
  System::~System() {
  }

  void System::addEntity(Entity entity)
  {
    if (mEntities.count(entity) == 0) {
      mEntities.insert(entity);
      SYS_LOG("Entity :" + std::to_string(entity) + " add to system " + _name);
    }
    if (mEntities.empty() == true)
      SYS_LOG("ERRRPRPRPRPPRPRP");
    SYS_LOG("their is :");
    SYS_LOG(mEntities.size());
  }

  void System::removeEntity(Entity entity)
  {
    if (mEntities.count(entity) == 1) {
      mEntities.extract(entity);
      SYS_LOG("Entity :" + std::to_string(entity) + " removed from system " + _name);
    }
  }
}
