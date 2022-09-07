/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** DropBomb
*/

#ifndef DropBomb_HPP_
#define DropBomb_HPP_

#include "System.hpp"
#include "World.hpp"
#include "GameComponents.hpp"
#include "Event.hpp"

namespace System {
  class DropBomb : public Engine::System {
  public:
    DropBomb(std::string name);
    ~DropBomb();
    void init(Engine::World &gData);
    void update(float dt, Engine::World &gData);
    void listener(Engine::Event &ev);
    void addPlayer(Entity player, Engine::Keys dropKey);

  protected:
  private:
    std::map<Entity, bool> _playerDrop;
    std::map<Entity, Engine::Keys> _playerDropKeys;
    void _applyDrop(Entity player, EventId key, Engine::Keys dropKey);

  };
}

#endif /* !DropBomb_HPP_ */
