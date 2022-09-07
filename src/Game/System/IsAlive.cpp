/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** IsAlive
*/

#include "IsAlive.hpp"
namespace System {

    IsAlive::IsAlive(std::string name) : Engine::System(name)
    {
    }

    IsAlive::~IsAlive()
    {
    }

    void IsAlive::update(float dt, Engine::World &gData)
    {
      std::vector<Entity> list;
   
      for (auto const& entity : mEntities)
        {
            auto &health = gData.getComponent<GameComponents::Health>(entity);
            if (health.pv == 0) {
	      list.push_back(entity);
	    }
        }
      
      for (auto it : list) {
	std::cout << "start destoy" << std::endl;
	gData.destroyEntity(it);
	std::cout << "destroy" << std::endl;
      }
      std::cout << "func en" << std::endl;
    }

}
