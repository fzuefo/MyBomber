/*
** EPITECH PROJECT, 2022
** indie
** File description:
** map_to_components
*/

#include "Map.hpp"
#include <fstream>
#include <filesystem>

namespace Game {

    Map::Map(Engine::World &world, unsigned int width, unsigned int height, unsigned int nbPlayers):
    _world(world),
    _width(width),
    _height(height),
    _map(std::make_shared<map_2d>(_generateMap(width, height, nbPlayers))),
    _factory(world)
    {
        _loadEntities();
    }

    Map::Map(Engine::World &world, std::string path):
    _world(world),
    _map(std::make_shared<map_2d>(_load(path))),
    _factory(world)
    {
        _loadEntities();
    }

    Map::~Map()
    {}

    std::string &Map::operator[](unsigned int y)
    {
        return (*_map)[y];
    }

    map_2d &Map::operator*()
    {
        return *_map;
    }

    Entity Map::_createEntity(char c)
    {
        //Entity e;

        switch (c) {
            case MAP_WALL_BREAKABLE:
                return _factory.createFromFile("src/Game/baseEntities/wall_destructible.json");
            case MAP_WALL_UNBREAKABLE:
                return _factory.createFromFile("src/Game/baseEntities/wall_undestructible.json");
            case MAP_PLAYER:
                _nbPlayers++;
                return _createPlayer();
            default:
                throw std::runtime_error("Invalid map element");
        }
    }

    Entity Map::_createPlayer()
    {
        Entity player;

        switch (_nbPlayers) {
            case 1:
                player = _factory.createFromFile("src/Game/baseEntities/player1.json");
                break;
            case 2:
                player = _factory.createFromFile("src/Game/baseEntities/player2.json");
                break;
            case 3:
                player = _factory.createFromFile("src/Game/baseEntities/player3.json");
                break;
            case 4:
                player = _factory.createFromFile("src/Game/baseEntities/player4.json");
                break;
            default:
                throw std::runtime_error("Can't create more than 4 players and less than 1");
        }
        _players.emplace_back(player);
        return player;
    }

    void Map::_placeMapElement(Entity e, unsigned int x, unsigned int y)
    {
        auto &el = _world.getComponent<GameComponents::MapElement>(e);
        el.map = _map;
        el.position[0] = x;
        el.position[1] = y;

        auto &transform = _world.getComponent<GameComponents::Transform>(e);
        auto &model = _world.getComponent<GameComponents::Model>(e);

        transform.position.x = x * 2;
        transform.position.z = y * 2;
        model.model->setPos(transform.position);
    }

    void Map::display() const
    {
        auto &vector = *(_map.get());
        for (auto &it: vector) {
            std::cout << it << std::endl;
        }
    }

    map_2d Map::_load(std::string path)
    {
        map_2d map;
        std::string line;
        std::ifstream file(path);

        if (!file.is_open())
            throw std::runtime_error("Could not open saved file");
        while (file) {
            std::getline(file, line);
            map.emplace_back(line);
        }
        return map;
    }

    void Map::_loadEntities()
    {
        Entity e;

        for (unsigned int y = 0; y < _map->size(); y++) {
            for (unsigned int x = 0; x < (*_map)[y].size(); x++) {
                char c = (*_map)[y][x];
                if (c != MAP_NONE) {
                    e = _createEntity(c);
                    _placeMapElement(e, x, y);
                }
                _createBedrock(x, y);
            }
        }
    }

    std::vector<Entity> Map::getPlayers() const
    {
        return _players;
    }

    void Map::_createBedrock(unsigned int x, unsigned int y)
    {
        Entity e = _factory.createFromFile("src/Game/baseEntities/bedrock.json");
        auto &transform = _world.getComponent<GameComponents::Transform>(e);

        transform.position.x = x * 2;
        transform.position.z = y * 2;

        auto &model = _world.getComponent<GameComponents::Model>(e);
        model.model->setPos(transform.position);
    }



    bool Map::_checkSpecial(int i, int y, int width, int length)
    {
        if (i == 1 || i == length - 2) {
            if (y == 1 || y == 2 || y == width - 2 || y == width - 3)
                return true;
        }

        if (i == 2 || i == length - 3) {
            if (y == 1 || y == width - 2)
                return true;
        }
        return false;
    }

    map_2d Map::_getBaseMap(int width, int length)
    {
        std::vector<std::string> res;

        std::string s;
        for (int i = 0; i != length; i++) {
            for (int y = 0; y != width; y++) {
                if (_checkSpecial(i, y, width, length))
                    s.push_back(MAP_WALL_TMP_GENERATION);
                else if (i == 0 || i == length - 1 || y == 0 ||
                y == width - 1 || (y % 2 == 0 && i % 2 == 0 ))
                    s.push_back(MAP_WALL_UNBREAKABLE);
                else
                    s.push_back(MAP_NONE);
            }
            res.push_back(s);
            s.clear();
        }
        return res;
    }

    map_2d Map::_randomiseMap(map_2d &map)
    {
        srand(time(nullptr));
        int rdm = 0;

        for(std::size_t i = 0; i < map.size(); ++i) {
            for (std::size_t y = 0; y < map[i].size(); ++y) {
                rdm = rand() % 100 + 1;
                if (map[i][y] == MAP_NONE && rdm >= 1 && rdm < 75)
                    map[i][y] = MAP_WALL_BREAKABLE;
                if (map[i][y] == MAP_WALL_TMP_GENERATION)
                    map[i][y] = MAP_NONE;
            }
        }
        return map;
    }

    void Map::_placePlayers(map_2d &map, unsigned int nbPlayers)
    {
        if (nbPlayers < 2 || nbPlayers > 4)
            throw std::runtime_error("Players must be between 1 and 4 included");
        map[1][1] = MAP_PLAYER;
        map[_height - 2][1] = MAP_PLAYER;
        if (nbPlayers < 3)
            return;
        map[1][_width - 2] = MAP_PLAYER;
        if (nbPlayers < 4)
            return;
        map[_height - 2][_width - 2] = MAP_PLAYER;
    }

    map_2d Map::_generateMap(int x, int y, unsigned int nbPlayers)
    {
        if (x < 10 || y < 10)
            throw std::runtime_error("Minimum map size: 10 x 10");
        map_2d map = _getBaseMap(x, y);
        map = _randomiseMap(map);
        _placePlayers(map, nbPlayers);
        return map;
    }

    void Map::save()
    {
        std::filesystem::create_directory("saves");
        std::ofstream file("saves/save.indie");

        if (!file.is_open())
            throw std::runtime_error("Could not save game");
        for (auto &it: *_map) {
            file << it << std::endl;
        }
        file.close();
    }
}
