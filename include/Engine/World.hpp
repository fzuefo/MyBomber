// /*
// ** EPITECH PROJECT, 2022
// ** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
// ** File description:
// ** World
// */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <memory>

#include "IndieStudio.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "EventManager.hpp"

namespace Engine {

  /**
   * @brief Class root of the engine
   *
   * @details User need to only use func that are in the public field
   */
  class World {
  public:
    World();
    ~World();

     /**
      * @brief Initialize the engine
      * @details need to be call before all other function
      */
     void init();

     /**
      * @brief create a new entity
      *
      * @details register a new entity in the system
      *
      * @return the Entity(ID) newly create 
      */
     Entity CreateEntity();
    
    /**
     * @brief register the component type in the engine
     * @details type specified with the template <T>
     */
    template<typename T>
    void registerComponent()
    {
      mComponentManager->cRegister<T>();
    }

     /**
      * @brief register the Systeme in the system
      * @details type specified with the template <T>
      * @return ptr to the system register
      */
     template<typename T>
     std::shared_ptr<T> registerSystem()
     {
       return mSystemManager->sRegister<T>();
     }
    
    /**
     * @brief Func for setting the signature(code bar) of the system
     *
     * @params The signature that will be used by the system
     *
     * @warning can be used after all the component Type are registered
     */
    template<typename T>
    void setSystemSignature(Signature signature)
    {
      mSystemManager->setSystemSignature<T>(signature);
    }
    
    /**
     * @brief integrate a instance of a component linked to a Entity
     *
     * @params Entity to link
     * @params Component filled wiht base data
     */
    template<typename T>
    void addComponent(Entity entity, T component)
    {
      INTER_LOG(">>-----------------------------------------\\");
      INTER_DISP("add new componant to", entity);
      mComponentManager->addComponent(entity, component);
      INTER_LOG("update entity with his new signature");
      auto signature = mEntityManager->getSignature(entity);
      signature.settingBit(mComponentManager->getComponentType<T>());
      mEntityManager->setSignature(entity, signature);
      INTER_LOG("update system with the new signature");
      mSystemManager->sigTest(entity, signature);
      INTER_LOG("end of the ADD COMPONANT");
      INTER_LOG("\\-----------------------------------------/");
    }
    
    /**
     * @brief remove the instance of a component linked the Entity
     *
     * @details component remove specified from templta
     *
     * @params Entity where the component is deduce
     */
    template<typename T>
    void removeComponent(Entity entity)
    {
      INTER_LOG(">>-----------------------------------------\\");
      INTER_DISP("remove componant to", entity);
      mComponentManager->removeComponent<T>(entity);
      INTER_LOG("update entity with his new signature");
      auto signature = mEntityManager->getSignature(entity);
      signature.reset(mComponentManager->getComponentType<T>());
      INTER_LOG("update system with the new signature");
      mSystemManager->sigTest(entity, signature);
      INTER_LOG("end of the ADD COMPONANT");
      INTER_LOG("\\-----------------------------------------/");
    }

    //        template<typename T>
    // ..... getComponent(Entity entity)

    /**
     * @brief get component type
     * @details use the template for specifie the componant
     * @details use important for seting the signature
     *
     * @return ComponentType
     */
    template<typename T>
    ComponentType getComponentType()
    {
      return mComponentManager->getComponentType<T>();
    }

    template<typename T>
    T& getComponent(Entity entity)
    {
      return mComponentManager->getComponent<T>(entity);
    }
    
    //      Camera3D getCamera();
    //    void initSystems();
    //   void initComponents();
    //   void initEntities();
    void destroyEntity(Entity entity)
    {
      mSystemManager->destroyEntity(entity);
      mComponentManager->destroyEntity(entity);
      mEntityManager->destroyEntity(entity);
     }
    
    void AddEventListener(EventId eventId, std::function<void(Event&)> const& listener)
    {
      mEventManager->AddListener(eventId, listener);
    }
    void SendEvent(Event& event)
    {
      mEventManager->SendEvent(event);
    }
    void SendEvent(EventId eventId)
    {
      mEventManager->SendEvent(eventId);
    }
    
  protected:
  private:
    std::unique_ptr<ComponentManager> mComponentManager;
    std::unique_ptr<EntityManager> mEntityManager;
    std::unique_ptr<SystemManager> mSystemManager;
    std::unique_ptr<EventManager> mEventManager;    
    //Camera3D _camera;
  };
}
#endif /* !WORLD_HPP_ */
