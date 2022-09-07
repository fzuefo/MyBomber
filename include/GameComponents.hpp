/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** i
*/

#ifndef GAMECOMPONENT_HPP_
#define GAMECOMPONENT_HPP_

#include <string>
#include <vector>
#include <array>
#include <memory>
#include "RaylibCamera.hpp"
#include "RaylibTexture.hpp"
#include "RaylibModel.hpp"
#include "RaylibText.hpp"
#include "RaylibModelAnimation.hpp"
#include "World.hpp"

namespace GameComponents {
  
    /**
     * @brief For playable entities
     */
    struct Player {
        std::string name;
    };

    /**
     * @brief Use this component to indicate that an Entity can be displayed
     * @details Empty. Use with another component
     */
    struct Render {};

    enum SoundStatus {
        PLAY,
        PAUSE,
        STOP
    };
    /**
     * @brief Sound differs from Music as Music's default behaviour is to loop
     */
    struct Sound {
        std::string path;
        float volume;
        SoundStatus status;
    };

    /**
     * @brief Use this with a model to create an animation
     */
    struct Animate {
      std::shared_ptr<Raylib::RaylibModelAnimation> _anim;
      float delay;
    };

    /**
     * @brief Set a collision rectangle, starting from origin and ending in end
     * @details the 2 other points from the rectangle can be deduced from these two.
     * Ex: if origin = [x1, y1] and end = [x2, y2], then the 2 other points are [x1, y2] and [x2, y1]
     */
    struct CollisionRect {
        Vector2 origin;
        Vector2 end;
    };

    /**
     * @brief Create a 3d model. Use struct Transform to set properties
     */
    struct Model {
      std::string path_tex;
      std::string path_mod;
      Vector3 rotion;
      std::shared_ptr<Raylib::RaylibTexture> texture;
      std::shared_ptr<Raylib::RaylibModel> model;
      std::function<void(Entity, Raylib::AnimTypeEnum)> animation;
    };

    /**
     * @brief Set position, rotation and scale of a 3d model
     */
    struct Transform {
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;
    };

    /**
     * @brief Set movement speed and acceleration of a Model or Texture
     */
    struct Velocity {
        float speed;
        float acceleration;
    };

    /**
     * @brief Set health points of a player or a wall
     */
    struct Health {
        unsigned int pv;
    };

    /**
     * @brief If set, an entity with 0 Health will be destroyed
     */
    struct Destructible {};

    /**
     * @brief Entity is a bomb
     */
    struct Bomb {};

    /**
     * @brief Entity is a wall
     */
    struct Wall {};

    /**
     * @brief Entity has a texture
     */
    struct Texture2D {
        std::string path;
        Vector2 postition;
        float rotation;
        float scale;
        std::shared_ptr<Raylib::RaylibTexture> sprite;
    };

    /**
     * @brief Entity can play music.
     */
    struct Music {
        std::string path;
        float volume;
        bool loop;
        SoundStatus status;
    };
    /**
     * @brief Entity is a camera. Sets properties
     */
    struct mCamera {
      std::shared_ptr<Raylib::RaylibCamera> cam;
      float fovy;
      Vector3 position; // tranform
      int projection;
      Vector3 target;
      //Vector3 up; /// rotation in transform
    };
  //  std::ostream &operator<<(std::ostream &out, const mCamera &cam)
  //  {
    // return (out << cam.fovy << "|" << cam.position.x << " " << cam.position.y << " " << cam.position.z << "|" << /cam.projection << "|" << cam.target.x << " " << cam.target.y << " " << cam.target.z);
  // }
    /**
     * @brief Is clickable. Use with a Texture2D. Call callback when cliked upon.
     * @details You can define the callback with a lambda function if you need it to access other code elements.
     */
    struct Button {
        void (*callback)(void);
    };

    /**
     * @brief This component can be used for map update, and for AI pathfinding
     */
    struct Map {
        std::vector<std::string> map;
    };

    /**
     * @brief Players, bombs and walls are part of the map
     */
    struct MapElement {
        std::array<unsigned int, 2> position; // position relative to the map
        std::shared_ptr<std::vector<std::string>> map; // reference to parent map (useful for updating map)
    };

    // TODO: define
    struct ScoreBoard {
        int score;
    };

    // TODO: define
    struct Timer {
        float timer;
    };

    /**
     * @brief Renderable text element
     */
    struct Text {
        std::string fontPath;
        std::string text;
        Vector2 position;
        float rotation;
        float fontSize;
        float spacing;
        Color color;
      std::shared_ptr<Raylib::RaylibText> model;
    };

    /**
     * @brief For elements that have limited duration, such as explosions
     *
     */
    struct Effect {
        unsigned int duration;
        float time;
    };

}

#endif /* !GAMECOMPONENT_HPP_ */
