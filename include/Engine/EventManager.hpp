/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_
#include "Event.hpp"
#include <list>
#include <algorithm>
#include <functional>

#include "Event.hpp"
#include <list>
#include <algorithm>
#include <functional>
#include "EngineDef.hpp"

namespace Engine {
  class EventManager {
  public:
    EventManager();
    ~EventManager();
    void AddListener(EventId eventId, std::function<void(Event&)> const& listener);
    void SendEvent(Event& event);
    void SendEvent(EventId eventId);
  protected:
  private:
    std::map<EventId, std::list<std::function<void(Event&)>>> listeners;
  };

}

#endif
