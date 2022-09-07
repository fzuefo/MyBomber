

#include "CameraSystem.hpp"
              
CameraSystem::CameraSystem(std::string name) : System(name)
{
  button = false;
}

CameraSystem::~CameraSystem()
{
}


void CameraSystem::init(Engine::World &gData)
{
  gData.AddEventListener(METHOD_LISTENER(Engine::KEY_SPACE, CameraSystem::listener));
}

void CameraSystem::update(Engine::World &gData)
{
      if (this->mEntities.empty() == true)
	SYS_LOG("no camera found");
      for (auto& it : this->mEntities) {
	auto &pos = gData.getComponent<GameComponents::Transform>(it);
	auto &mcam = gData.getComponent<GameComponents::mCamera>(it);
	
	if (button == true) {
	  std::cout << "do something" << std::endl;
	  
	  mcam.cam->setCameraMode(CAMERA_CUSTOM);                            

	}
	mcam.cam->updateCamera();
      }

      this->button = false;
}

void CameraSystem::begin(Engine::World &gData)
{
  for (auto& it : this->mEntities) {
	auto &mcam = gData.getComponent<GameComponents::mCamera>(it);
	BeginMode3D(mcam.cam->getCamera());
  }
}

void CameraSystem::end(Engine::World &gData)
{
  for (auto& it : this->mEntities) {
	auto &mcam = gData.getComponent<GameComponents::mCamera>(it);
        EndMode3D();
  }
}


void CameraSystem::listener(Engine::Event &ev)
{
  button = true;
  SYS_LOG("buuton == true");
}


