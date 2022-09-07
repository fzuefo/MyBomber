/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "GameComponents.hpp"
#include "World.hpp"

namespace Entities {
    namespace pt = boost::property_tree;
    using map_2d = std::vector<std::string>;
    class Factory {
        using initializer_mptr = void(Factory::*)(Entity, pt::ptree);
        public:
            Factory(Engine::World &world);
            ~Factory();
            Entity createFromFile(std::string path);
        protected:
        private:
            Engine::World &_world;
            GameComponents::SoundStatus _stringToSoundStatus(std::string status);
            void _initPlayerComponent(Entity entity, pt::ptree);
            void _initRenderComponent(Entity entity, pt::ptree);
            void _initModelComponent(Entity entity, pt::ptree);
            void _initSoundComponent(Entity entity, pt::ptree);
            void _initAnimateComponent(Entity entity, pt::ptree);
            void _initCollisionRectComponent(Entity entity, pt::ptree);
            void _initTransformComponent(Entity entity, pt::ptree);
            void _initVelocityComponent(Entity entity, pt::ptree);
            void _initHealthComponent(Entity entity, pt::ptree);
            void _initMusicComponent(Entity entity, pt::ptree);
            void _initMapElementComponent(Entity entity, pt::ptree);
            void _initDestructibleComponent(Entity entity, pt::ptree);
            void _initCameraComponent(Entity entity, pt::ptree);
            void _initWallComponent(Entity entity, pt::ptree root);
            void _initTexture2DComponent(Entity entity, pt::ptree root);
            void _initBombComponent(Entity entity, pt::ptree root);
            void _initEffectComponent(Entity entity, pt::ptree root);


            std::map<std::string, initializer_mptr> _initializers;
    };

    template <typename T>
    std::vector<T> as_vector(pt::ptree const &tree, pt::ptree::key_type const &key)
    {
        std::vector<T> r;
        for (auto& item : tree.get_child(key))
            r.push_back(item.second.get_value<T>());
        return r;
}
}


#endif /* !FACTORY_HPP_ */
