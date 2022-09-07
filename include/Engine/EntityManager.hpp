/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "IndieStudio.hpp"
#include "System.hpp"

namespace Engine {
  class EntityManager {
  public:
    EntityManager();
    ~EntityManager();
    Entity CreateEntity();
    void destroyEntity(Entity entity);

    void setSignature(Entity entity, Signature sig);
    Signature getSignature(Entity entity);
  
  protected:
  private:
    std::queue<Entity> _availableEntity; // queue set with all id possible, assure the good balance of the id
    std::array<Signature, MAX_ENTITY> _signature;  // array indexed with all enttity for acces signature of the entity
    std::size_t _livingEntityCount;
  };
}
#endif /* !ENTITYMANAGER_HPP_ */
