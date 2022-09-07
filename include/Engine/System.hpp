


/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "IndieStudio.hpp"
#include "Component.hpp"

namespace Engine {
  class System {
  public:
    System(std::string name);
    ~System();

    void addEntity(Entity entity);
    void removeEntity(Entity entity);
    
    std::set<Entity> mEntities;
  private:
    std::string _name;
  };


  class Signature  {
  public:
    Signature(){}
    ~Signature(){}

    void settingBit(ComponentType id)
    {
      SYS_DISP("Setting bit: ", id);
      _signature.set(id);
      SYS_DISP("Setting : ", _signature);
    }
    /*
    void settingBit(std::array<ComponentType> id)
    {
      for (size_t i = 0; i < id.size(); i++)
	  _signature.set(id[i]);
	  }*/


    void reset()
    {
      _signature.reset();
    }

    void reset(ComponentType id)
    {
      _signature.reset(id);      
    }
    void setSig(std::bitset<MAX_COMPONENTS> sets)
    {
     	_signature = sets; 
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Signature&dt)
    {
      stream << dt._signature;
      return stream;
    }

    friend bool operator ==(const Signature &a, const Signature &b)
    {
      return (a._signature == b._signature);
    }

    friend Signature operator &(const Signature &a, const Signature &b)
    {
      Signature tmp;
      tmp._signature = a._signature & b._signature;
      return tmp;
    }    
  private:
    std::bitset<MAX_COMPONENTS> _signature;
  };

}
#endif /* !SYSTEM_HPP_ */
