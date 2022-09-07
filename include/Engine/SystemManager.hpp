/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "IndieStudio.hpp"
#include "System.hpp"

namespace Engine {
  class SystemManager {
  public:
    SystemManager();
    ~SystemManager();

    template<typename T>
    std::shared_ptr<T> sRegister()
    {
      const char *name = typeid(T).name();
      auto var = std::make_shared<T>(name);
      SYS_LOG("Register Sys: " + std::string(name));
      _allSys.insert({name, var});
      return var;
    }

    template<typename T>
    void setSystemSignature(Signature sig)
    {
      const char *name = typeid(T).name();
      
      SYS_DISP("New signature for the SYS" + std::string(name), sig);
      _allSignature.insert({name, sig});
    }
    
    void sigTest(Entity entity, Signature sig)
    {
      bool partof = true;

      SYS_LOG("SystemSignature updating ENtity list"); 
      LOG_MAP(_allSys);
      LOG_MAP(_allSignature);
      for (const auto& [key, value] : _allSys) {
	Engine::System &sis = *value.get();
	if ((_allSignature[key] & sig) == _allSignature[key]) {
	  SYS_LOG("ADD new entity to sys"); 
	  sis.addEntity(entity);
	} else {
	  SYS_LOG("remove entity from sys"); 
	  sis.removeEntity(entity);
	}
	SYS_LOG("---END SYS LOOP");
      }      
    }
    void destroyEntity(Entity entity)
    {
      
      for (const auto& [key, value] : _allSys) {
	  value->removeEntity(entity);
      }
    }
  
  protected:
  private:
    std::map<const char *, std::shared_ptr<System>> _allSys;
    std::map<const char *, Signature> _allSignature;
  };
}
#endif /* !SYSTEMMANAGER_HPP_ */
