


#include "EventManager.hpp"

namespace Engine {

  EventManager::EventManager() {};
  EventManager::~EventManager() {};

  void EventManager::AddListener(EventId eventId, std::function<void(Event&)> const& listener)
  {
    listeners[eventId].push_back(listener);
    INTER_LOG("add event listener");
  }
  void EventManager::SendEvent(Event& event)
  {
    uint32_t type = event.getControler();
    INTER_LOG(static_cast<enum EventType>(type));
    INTER_LOG(": EVENT send");
    for (auto const& listener : listeners[type])
    {
	    listener(event);
    }
  }

  void EventManager::SendEvent(EventId eventId)
  {
    Event event(eventId, Engine::KEY_PRESSED);
    INTER_LOG(static_cast<enum EventType>(eventId));
    INTER_LOG(": EVENT send");
    for (auto const& listener : listeners[Engine::KEY_PRESSED]) {
      listener(event);
    }
  }
}
