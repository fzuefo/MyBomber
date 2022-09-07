


#ifndef CAMERASYS_H_
#define CAMERASYS_H_
#include "World.hpp"
#include "Event.hpp"
#include "GameComponents.hpp"


class CameraSystem : public Engine::System
{
 public:
  CameraSystem(std::string name);
  ~CameraSystem();
  
  void init(Engine::World &gData);
  void update(Engine::World &gData);
  void listener(Engine::Event &ev);
  void begin(Engine::World &gData);
  void end(Engine::World &gData);
  
private:
  bool button;
};
#endif




