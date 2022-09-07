/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include "IndieStudio.hpp"
#include "Component.hpp"
namespace Engine {


  /**
   * @brief Class who manage all the composant type and her warehouse
   * @details use template for all function all are in the .hpp
   *
   * @warning all function will use the registered componantType be sure to put existing type;
   */
  class ComponentManager {
  public:
    ComponentManager();
    ~ComponentManager();
    
    /**
     * @brief Register a new type of componant in the engine
     *
     *@details the type is specified in <>
     */
    template<typename T>
    void cRegister()
    {
      const char *name = typeid(T).name();

      COMP_LOG(std::string(name) + ": register to the engine");
      _allType.insert({name, _typeNbr});
      _data.insert({name, std::make_shared<arrayComponent<T>>()});
      COMP_DISP("Componant register with id: ", _typeNbr);
      _typeNbr++;
      COMP_DISP("the number of composant registered is:", _typeNbr);
    }


    /**
     * @brief get the componant type
     *
     *@details componant type is an ID 
     *
     * @return a unsigned int -> ComposentType
     */
    template<typename T>
    ComponentType getComponentType()
    {
      const char *name = typeid(T).name();

      return _allType[name];
    }

    template<typename T>
    T& getComponent(Entity entity)
    {
      const char *name = typeid(T).name();

      return std::static_pointer_cast<arrayComponent<T>>(_data[name])->getComponent(entity);
    }

    //    template<typename ... args>
    //std::array<ComponentType> getComponentType()
    
    /**
     * @brief Add a instance of a composent to is entity
     * @details will use the registered composant for instanciate and stock the composant in is familie
     *
     * @params the Entity who get the composant
     * @params the newly composant with default setup
     *
     * @warning this function don't need the template is the type of the second param is explicite
     */
    template<typename T>
    void addComponent(Entity entity, T component)
    {
      const char *tmp = typeid(T).name();
      
      std::static_pointer_cast<arrayComponent<T>>(_data[tmp])->push(component, entity);
      COMP_DISP(std::string(tmp) + " Component is added to the entity num:", entity); 
    }

    /**
     * @brief remove the instance the component of the entity 
     *
     * @params index Entity
     *
     */
    template<typename T>
    void removeComponent(Entity entity)
    {
      const char *tmp = typeid(T).name();
    
      std::static_pointer_cast<arrayComponent<T>>(_data[tmp])->remove(entity);
      COMP_DISP(std::string(tmp) + " Component is remove from the entity num:", entity); 
    }
  
    void destroyEntity(Entity entity)
    {
      std::map<const char *, std::shared_ptr<IComponentsArray>>::iterator it;
      
      for (it = _data.begin(); it != _data.end(); it++)
	{
	  it->second->destroyEntity(entity);
	}
    }
    

    
  protected:
                //std::type_info::name return const char *
  private:
    std::map<const char *, ComponentType>  _allType{};
    ComponentType _typeNbr{};
    std::map<const char *, std::shared_ptr<IComponentsArray>> _data{};
  };
}
#endif /* !COMPONENTMANAGER_HPP_ */
