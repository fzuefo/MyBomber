/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EntityManager
*/

#include "EntityManager.hpp"
namespace Engine
{		
  EntityManager::EntityManager()
  {
    _livingEntityCount = 0;
    for (Entity it = 1; it < MAX_ENTITY; it++)
      _availableEntity.push(it);
    ENTI_LOG("ENTITY manger construct");
  }

  EntityManager::~EntityManager()
  {}

  Entity EntityManager::CreateEntity()
  {
    Entity enti;

    if (_livingEntityCount >= MAX_ENTITY) {
      throw std::runtime_error("too much entities");
    }
    enti = _availableEntity.front();
    _availableEntity.pop();
    _livingEntityCount += 1;
    ENTI_DISP("CReation of entity id:", enti);
    return (enti);
  }

  void EntityManager::destroyEntity(Entity entity)
  {
    if (entity >= MAX_ENTITY || entity < 0) {
      throw std::runtime_error("Entity not in range");
    }
    _signature[entity].reset();
    _availableEntity.push(entity);
    _livingEntityCount -= 1;
  }

  void EntityManager::setSignature(Entity entity, Signature sig)
  {
    _signature[entity] = sig;
  }
  
  Signature EntityManager::getSignature(Entity entity)
  {
    return (_signature[entity]);
  }
  
}
