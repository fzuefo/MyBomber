/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#include "Factory.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <map>
#include "GameComponents.hpp"
#include <memory>

namespace Entities {
    namespace pt = boost::property_tree;

    Vector3 createVector3(float x, float y, float z) {
        Vector3 v;
        v.x = x;
        v.y = y;
        v.z = z;
        return v;
    }

    Factory::Factory(Engine::World &world):
    _world(world)
    {
        _initializers["Player"] = &Factory::_initPlayerComponent;
        _initializers["Render"] = &Factory::_initRenderComponent;
        _initializers["Model"] = &Factory::_initModelComponent;
        _initializers["Sound"] = &Factory::_initSoundComponent;
        _initializers["Animate"] = &Factory::_initAnimateComponent;
        _initializers["CollisionRect"] = &Factory::_initCollisionRectComponent;
        _initializers["Transform"] = &Factory::_initTransformComponent;
        _initializers["Velocity"] = &Factory::_initVelocityComponent;
        _initializers["Health"] = &Factory::_initHealthComponent;
        _initializers["MapElement"] = &Factory::_initMapElementComponent;
        _initializers["Destructible"] = &Factory::_initDestructibleComponent;
        _initializers["Music"] = &Factory::_initMusicComponent;
        _initializers["Camera"] = &Factory::_initCameraComponent;
        _initializers["Wall"] = &Factory::_initWallComponent;
        _initializers["Texture2D"] = &Factory::_initTexture2DComponent;
        _initializers["Bomb"] = &Factory::_initBombComponent;
        _initializers["Effect"] = &Factory::_initEffectComponent;
    }

    Factory::~Factory()
    {
    }

    Entity Factory::createFromFile(std::string path) {
        pt::ptree root;
        Entity e = _world.CreateEntity();
        initializer_mptr ptr;

        if (!std::filesystem::exists(path))
            throw std::runtime_error("This file does not exist: " + path);
        pt::read_json(path, root);
        pt::ptree &components = root.get_child("components");
        for (auto &it: components) {
            auto &key = it.first;
            auto &value = it.second;
            if (_initializers.find(key) == _initializers.end()) {
                _world.destroyEntity(e);
                throw std::runtime_error("No initializing method found for component: " + key);
            }
            ptr = _initializers.at(key);
            (this->*ptr)(e, value);
        }
        return e;
    }

    void Factory::_initTexture2DComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Texture2D component;
        auto &transform = _world.getComponent<GameComponents::Transform>(entity);
        Vector2 vecou = {transform.position.x, transform.position.y};

        component.path = root.get<std::string>("path");

        component.sprite = std::make_shared<Raylib::RaylibTexture>(component.path);
        component.sprite->setPosition(vecou);
        component.sprite->setScale(transform.scale.x);
        component.sprite->setRotation(transform.rotation.x);
        _world.addComponent(entity, component);
    }

    GameComponents::SoundStatus Factory::_stringToSoundStatus(std::string status) {
        std::map<std::string, GameComponents::SoundStatus> converter {
            {"stop", GameComponents::SoundStatus::STOP},
            {"play", GameComponents::SoundStatus::PLAY},
            {"pause", GameComponents::SoundStatus::PAUSE},
        };

        return converter.at(status);
    }

    void Factory::_initPlayerComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Player component;

        component.name = root.get<std::string>("name");
        _world.addComponent(entity, component);
    }

    void Factory::_initBombComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Bomb component;

        _world.addComponent(entity, component);
    }

    void Factory::_initRenderComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Render component;
        _world.addComponent(entity, component);
    }

    void Factory::_initModelComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Model component;
        auto &t = _world.getComponent<GameComponents::Transform>(entity);
	    std::function<void(Entity entity, Raylib::AnimTypeEnum type)> tmp;

        component.animation = tmp;
        component.rotion.x = 0;
        component.rotion.y = 1;
        component.rotion.z = 0;

        component.path_mod = root.get<std::string>("path_model");
        component.path_tex = root.get<std::string>("path_texture");

        component.texture = std::make_shared<Raylib::RaylibTexture>(component.path_tex);
        component.model = std::make_shared<Raylib::RaylibModel>(component.path_mod, t.position, component.rotion, 0.0f, t.scale, WHITE, createVector3(90.0f, 0.0f, 0.0f));
        component.model->setMaterialTexture(MATERIAL_MAP_DIFFUSE, component.texture->getTexture());
        _world.addComponent(entity, component);
    }

    void Factory::_initSoundComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Sound component;

        component.path = root.get<std::string>("path");
        component.volume = root.get<float>("volume");
        component.status = _stringToSoundStatus(root.get<std::string>("status"));
        _world.addComponent(entity, component);
    }

    void Factory::_initAnimateComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Animate component;
	//	std::shared_ptr<Raylib::RaylibModelAnimation> tmp(nullptr);
	//component._anim = tmp;
	    component.delay = root.get<float>("delay");
        _world.addComponent(entity, component);
    }

    void Factory::_initCollisionRectComponent(Entity entity, pt::ptree root)
    {
        GameComponents::CollisionRect component;
        auto origin = as_vector<float>(root, "origin");
        auto end = as_vector<float>(root, "end");

        component.origin.x = origin[0];
        component.origin.y = origin[1];
        component.end.x = end[0];
        component.end.y = end[1];
        _world.addComponent(entity, component);
    }

    void Factory::_initTransformComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Transform component;
        auto position = as_vector<float>(root, "position");
        auto rotation = as_vector<float>(root, "rotation");
        auto scale = as_vector<float>(root, "scale");

        component.position.x = position[0];
        component.position.y = position[1];
        component.position.z = position[2];
        component.rotation.x = rotation[0];
        component.rotation.y = rotation[1];
        component.rotation.z = rotation[2];
        component.scale.x = scale[0];
        component.scale.y = scale[1];
        component.scale.z = scale[2];
        _world.addComponent(entity, component);
    }

    void Factory::_initVelocityComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Velocity component;

        component.speed = root.get<float>("speed");
        component.acceleration = root.get<float>("acceleration");
        _world.addComponent(entity, component);
    }

    void Factory::_initHealthComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Health component;

        component.pv = root.get<unsigned int>("pv");
        _world.addComponent(entity, component);
    }

    void Factory::_initMapElementComponent(Entity entity, pt::ptree root)
    {
        GameComponents::MapElement component;
        auto position = as_vector<unsigned int>(root, "position");

        component.position[0] = position[0];
        component.position[1] = position[1];
        _world.addComponent(entity, component);
    }

    void Factory::_initDestructibleComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Destructible component;
        _world.addComponent(entity, component);
    }

    void Factory::_initMusicComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Sound component;

        component.path = root.get<std::string>("path");
        component.volume = root.get<float>("volume");
        component.status = _stringToSoundStatus(root.get<std::string>("status"));
        _world.addComponent(entity, component);
    }

    Vector3 createVector(float x, float y, float z) {
        Vector3 v;
        v.x = x;
        v.y = y;
        v.z = z;
        return v;
    }

    void Factory::_initCameraComponent(Entity entity, pt::ptree root)
    {
      GameComponents::mCamera component;
      auto targ = as_vector<float>(root, "target");
      auto pos = as_vector<float>(root, "pos");
      //Vector3 position;
      component.position.x = pos[0];
      component.position.y = pos[1];
      component.position.z = pos[2];

      component.fovy = root.get<float>("fovy");
      component.projection = root.get<int>("projection");
      component.target.x = targ[0];
      component.target.y = targ[1];
      component.target.z = targ[2];

      //      ENTI_LOG(component.fovy << "|" << component.position.x << " " << component.position.y << " " << component.position.z << "|" << component.projection << "|" << component.target.x << " " << component.target.y << " " << component.target.z); 
      //std::shared_ptr<Raylib::RaylibCamera> came = std::make_shared<Raylib::RaylibCamera>(component.fovy, component.position, component.projection, component.target, (0.0f,0.1f,0.0f));
      // std::shared_ptr<Raylib::RaylibCamera> came = std::make_shared<Raylib::RaylibCamera>(45.0f, { 0.2f, 0.4f, 0.2f }, 0, { 0.0f, 0.0f, 0.0f }, {0.0f, 0.1f, 0.0f});
      std::shared_ptr<Raylib::RaylibCamera> came = std::make_shared<Raylib::RaylibCamera>(component.fovy, component.position, component.projection, component.target, createVector(0.0f, 0.1f, 0.0f));

      component.cam = came;
      //component.cam->setCameraMode(CAMERA_FIRST_PERSON);
      component.cam->setCameraMode(CAMERA_CUSTOM);
      //component.cam->setCameraMoveControls(KEY_W, KEY_S, KEY_D, KEY_A, KEY_Q, KEY_E);

      _world.addComponent(entity, component);
    }

    void Factory::_initWallComponent(Entity entity, pt::ptree root)
    {
        GameComponents::Wall component;

        _world.addComponent(entity, component);
    }

  void Factory::_initEffectComponent(Entity entity, pt::ptree root)
  {
      GameComponents::Effect component;
      component.duration = root.get<int>("time");
      component.time = 0;
      _world.addComponent(entity, component);


  }

}
