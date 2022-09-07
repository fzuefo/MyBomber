// /*
// ** EPITECH PROJECT, 2022
// ** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
// ** File description:
// ** World
// */

#include "World.hpp"
namespace Engine {
   World::World()
   {
     mComponentManager = std::make_unique<ComponentManager>();
     mEntityManager = std::make_unique<EntityManager>();
     mSystemManager = std::make_unique<SystemManager>();
     mEventManager = std::make_unique<EventManager>();
   }

   World::~World()
   {
   }

   void World::init()
   {
     INTER_LOG("Initialisation");

     /*
 	_camera = { 0 };
 	_camera.position = { 0.0f, 10.0f, 10.0f };   Camera position
     _camera.target = { 0.0f, 0.0f, 0.0f };       Camera looking at point
     _camera.up = { 0.0f, 1.0f, 0.0f };           Camera up vector (rotation towards target)
     _camera.fovy = 45.0f;                                 Camera field-of-view Y
     _camera.projection = CAMERA_PERSPECTIVE;  
 	 this->initEntities();
 	 this->initComponents();
 	 this->initSystems();
 	*/
   }
   /*
   Camera3D World::getCamera()
   {
     return (_camera);
   }
   */

Entity World::CreateEntity()
  {
    return this->mEntityManager->CreateEntity();
  }
  
 }
