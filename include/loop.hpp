/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** my
*/

#ifndef LOOP_H_
#define LOOP_H_

#include "IndieStudio.hpp"
#include "World.hpp"
#include "IndieStudio.hpp"
#include "WindowManager.hpp"
#include "RaylibWindow.hpp"
#include "RaylibText.hpp"
#include "RaylibCamera.hpp"
#include "RaylibModel.hpp"
#include "RaylibTexture.hpp"
#include "Map.hpp"
#include "Factory.hpp"
#include "CameraSystem.hpp"
#include "mRender3D.hpp"
#include "IsAlive.hpp"
#include "ControlPlayer.hpp"
#include "DropBomb.hpp"
#include "EndEffect.hpp"
#include "IsBombAlive.hpp"
#include "Timer.hpp"
#include "Animation3D.hpp"
#include "ButtonActionSystem.hpp"
#include "Render2D.hpp"

using Entity = std::uint32_t;

namespace Indie {
    class IndieGame
    {
        public :
            IndieGame();
            ~IndieGame();
            void Loop();
            void init(Engine::World &world);
            void register_system(Engine::World &world);
            void init_sys(Entities::Factory &f, Engine::World &world);
            void rendering2D(Engine::World &world, float dt);
            void rendering3D(Engine::World &world, float dt);
            void runMenu(Engine::World &world, float dt);
            void initGame(Engine::World &world);
            void runGame(Engine::World &world, float dt);
            float update(Engine::World &world, float dt, WindowManager &window);

        private:
            size_t status;
            std::shared_ptr<CameraSystem> camSys;
            std::shared_ptr<mRender3D> ren;
            std::shared_ptr<System::Animation3D> anim;
            std::shared_ptr<System::IsAlive> isAlive;
            std::shared_ptr<System::ControlPlayer> playerMovement;
            std::shared_ptr<System::DropBomb> dropB;
            std::shared_ptr<System::EndEffect> endEffect;
            std::shared_ptr<System::IsBombAlive> isBonbAlive;
            std::shared_ptr<System::Timer> timer;
            std::shared_ptr<System::ButtonActionSystem> buttonAct;
            std::shared_ptr<System::render2DSysteme> ren2D;
            std::shared_ptr<Game::Map> map;
            Entity menu;
    };
}


#endif /* !MY_H_ */
