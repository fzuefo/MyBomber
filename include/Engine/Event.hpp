/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Event
*/


#ifndef EVENT_H_
#define EVENT_H_

#include "IndieStudio.hpp"
#include "EngineDef.hpp"

namespace Engine {

  enum EventType {
    KEY_PRESSED,
    KEY_RELEASED,
    MOUSE_MOVE,
    MOUSE_BUTTON_PRESSED
  };

  enum Keys {
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_SPACE,
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_CTRL,
    KEY_UP,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_DOWN
  };

  class Event
  {
  public:
    Event(EventId id, EventId control = 0, Vector2 mouse = {0,0})
    {
      _data = id;
      _controler = control;
      _mousePose = mouse;
    }
    
    EventId getData()
    {
      return _data;
    }
    
    EventId getControler()
    {
      return _controler;
    }
    
    Vector2 getMouse()
    {
      return _mousePose;
    }
    
  private:
    EventId _data;
    EventId _controler;
    Vector2 _mousePose;
  };
}
#endif
