/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** i
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include  "EngineDef.hpp"
#include "IndieStudio.hpp"

namespace Engine {

  /**
   * @brief Class interface for help store template class
   */
  class IComponentsArray
  {
  public:
    ~IComponentsArray() = default;
    virtual void destroyEntity(Entity entity) = 0;
  };
  
  
  /**
   * @brief Class array Component 
   * @details used for store one type of Component 
   */
  template<class T>
  class arrayComponent : public IComponentsArray {
  public:
    arrayComponent() : _all() {
    }
    ~arrayComponent(){
    }

    /**
     * @brief PUSH a component to the index
     */
    void push(T component, Entity index) {
      _all[index] = component;
    }
    
    /**
     * @brief remove a component a the index
     */
    void remove(Entity index)
    {
      _all.erase(index);
    }
    
    /**
     * @brief get component a index
     * @returns REFERENCES to the component
     */
    T& getComponent(Entity entity)
    {
      return (_all[entity]);
    }
  
    void destroyEntity(Entity entity)
    {
      _all.erase(entity);
    }
  private:
    std::map<Entity, T> _all;  //peu etre pas opti ou contraire a la ECS (Array peu etre obligatoir, mais fesable)
    //  std::array<T, MAX_COMPONENT> _all;  // demande plus de logic pour permetre une utilisation optimal
  };
}



#endif /* !COMPONENT_HPP_ */
