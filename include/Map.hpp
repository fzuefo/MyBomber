/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "IndieStudio.hpp"
#include "Factory.hpp"

#define MAP_WALL_BREAKABLE 'd'
#define MAP_WALL_UNBREAKABLE 'u'
#define MAP_NONE ' '
#define MAP_WALL_TMP_GENERATION 'o'
#define MAP_PLAYER 'p'
#define MAP_BOMB 'b'

namespace Game {
    using map_2d = std::vector<std::string>;

    map_2d my_map(int x, int y);
    class Map {
        public:
            Map(Engine::World &, unsigned int width, unsigned int height, unsigned int nbPlayers);
            Map(Engine::World &, std::string path);
            ~Map();
            std::string &operator[](unsigned int y);
            map_2d &operator*();
            void save();
            void display() const;
            [[nodiscard]] std::vector<Entity> getPlayers() const;
        protected:
        private:
            Engine::World &_world;
            unsigned int _width;
            unsigned int _height;
            std::shared_ptr<map_2d> _map;
            Entities::Factory _factory;
            unsigned int _nbPlayers = 0;
            std::vector<Entity> _players;
            map_2d _load(std::string path);
            Entity _createEntity(char c);
            void _placeMapElement(Entity e, unsigned int x, unsigned int y);
            void _loadEntities();
            bool _checkSpecial(int i, int y, int width, int length);
            map_2d _getBaseMap(int width, int length);
            map_2d _randomiseMap(map_2d &map);
            map_2d _generateMap(int x, int y, unsigned int nbPlayers);
            Entity _createPlayer();
            void _placePlayers(map_2d &map, unsigned int nbPlayers);
            void _createBedrock(unsigned int x, unsigned int y);
    };
}


#endif /* !MAP_HPP_ */
