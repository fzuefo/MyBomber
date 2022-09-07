/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** main_loop
*/

#include "loop.hpp"
#include <chrono>

namespace Indie {

    IndieGame::IndieGame()
    {
    }

    IndieGame::~IndieGame()
    {
    }

    void IndieGame::init(Engine::World &world)
    {
        world.init();

        world.registerComponent<GameComponents::Player>();
        world.registerComponent<GameComponents::Render>();
        world.registerComponent<GameComponents::Sound>();
        world.registerComponent<GameComponents::Animate>();
        world.registerComponent<GameComponents::CollisionRect>();
        world.registerComponent<GameComponents::Model>();
        world.registerComponent<GameComponents::Transform>();
        world.registerComponent<GameComponents::Velocity>();
        world.registerComponent<GameComponents::Health>();
        world.registerComponent<GameComponents::Destructible>();
        world.registerComponent<GameComponents::Bomb>();
        world.registerComponent<GameComponents::Wall>();
        world.registerComponent<GameComponents::Texture2D>();
        world.registerComponent<GameComponents::Music>();
        world.registerComponent<GameComponents::mCamera>();
        world.registerComponent<GameComponents::Button>();
        world.registerComponent<GameComponents::Map>();
        world.registerComponent<GameComponents::MapElement>();
        world.registerComponent<GameComponents::ScoreBoard>();
        world.registerComponent<GameComponents::Timer>();
        world.registerComponent<GameComponents::Text>();
        world.registerComponent<GameComponents::Effect>();
    }

    void IndieGame::register_system(Engine::World &world)
    {
        camSys = world.registerSystem<CameraSystem>();

        Engine::Signature sig;
        sig.settingBit(world.getComponentType<GameComponents::mCamera>());
        sig.settingBit(world.getComponentType<GameComponents::Transform>());
        world.setSystemSignature<CameraSystem>(sig);


        ren = world.registerSystem<mRender3D>();
        Engine::Signature sig2;
        sig2.settingBit(world.getComponentType<GameComponents::Transform>());
        sig2.settingBit(world.getComponentType<GameComponents::Model>());
        sig2.settingBit(world.getComponentType<GameComponents::Render>());
        world.setSystemSignature<mRender3D>(sig2);


        isAlive = world.registerSystem<System::IsAlive>();
        Engine::Signature sig3;
        sig3.settingBit(world.getComponentType<GameComponents::Health>());
        world.setSystemSignature<System::IsAlive>(sig3);

        playerMovement = world.registerSystem<System::ControlPlayer>();
        Engine::Signature sig4;
        sig4.settingBit(world.getComponentType<GameComponents::Player>());
        sig4.settingBit(world.getComponentType<GameComponents::Transform>());
        sig4.settingBit(world.getComponentType<GameComponents::MapElement>());
        sig4.settingBit(world.getComponentType<GameComponents::Velocity>());
        sig4.settingBit(world.getComponentType<GameComponents::Model>());
        world.setSystemSignature<System::ControlPlayer>(sig4);


        dropB = world.registerSystem<System::DropBomb>();
        Engine::Signature sig5;
        sig5.settingBit(world.getComponentType<GameComponents::Player>());
        sig5.settingBit(world.getComponentType<GameComponents::MapElement>());
        world.setSystemSignature<System::DropBomb>(sig5);


        endEffect = world.registerSystem<System::EndEffect>();
        Engine::Signature sig6;
        sig6.settingBit(world.getComponentType<GameComponents::Effect>());
        sig6.settingBit(world.getComponentType<GameComponents::Health>());
        world.setSystemSignature<System::EndEffect>(sig6);


        isBonbAlive = world.registerSystem<System::IsBombAlive>();
        Engine::Signature sig7;
        sig7.settingBit(world.getComponentType<GameComponents::Health>());
        sig7.settingBit(world.getComponentType<GameComponents::Bomb>());
        world.setSystemSignature<System::IsBombAlive>(sig7);


        timer = world.registerSystem<System::Timer>();
        Engine::Signature sig8;
        sig8.settingBit(world.getComponentType<GameComponents::Timer>());
        world.setSystemSignature<System::Timer>(sig8);


        anim = world.registerSystem<System::Animation3D>();
        Engine::Signature sig9;
        sig9.settingBit(world.getComponentType<GameComponents::Animate>());
        world.setSystemSignature<System::Animation3D>(sig9);

        buttonAct = world.registerSystem<System::ButtonActionSystem>();
        Engine::Signature sig10;
        sig10.settingBit(world.getComponentType<GameComponents::Button>());
        sig10.settingBit(world.getComponentType<GameComponents::Transform>());
        world.setSystemSignature<System::ButtonActionSystem>(sig10);

        ren2D = world.registerSystem<System::render2DSysteme>();
        Engine::Signature sig11;
        sig11.settingBit(world.getComponentType<GameComponents::Texture2D>());
        sig11.settingBit(world.getComponentType<GameComponents::Render>());
        sig11.settingBit(world.getComponentType<GameComponents::Transform>());
        world.setSystemSignature<System::render2DSysteme>(sig11);
    }

    void IndieGame::init_sys(Entities::Factory &f, Engine::World &world)
    {
        camSys->init(world);
        buttonAct->init(world);
        Entity cam = f.createFromFile("src/Game/baseEntities/Camera.json");
        menu = f.createFromFile("src/Game/baseEntities/menu.json");
    }

    void IndieGame::rendering2D(Engine::World &world, float dt)
    {
        if (this->status == 0) {
            ren2D->update(dt, world);

        }
    }

    void IndieGame::rendering3D(Engine::World &world, float dt)
    {
        if (this->status == 2) {
            //RenderSystem->update();
            ren->update(dt, world);
            anim->update(dt, world);
        }
    }

    void IndieGame::initGame(Engine::World &world)
    {
        this->map = std::make_shared<Game::Map>(world, 20, 20, 4);
        std::vector<Entity> players = map->getPlayers();

        playerMovement->init(world);
        std::array<Engine::Keys, 4> keys = {Engine::Keys::KEY_Z, Engine::Keys::KEY_Q, Engine::Keys::KEY_S, Engine::Keys::KEY_D};
        playerMovement->addPlayer(players[0], keys);
        std::array<Engine::Keys, 4> keys2 = {Engine::Keys::KEY_T, Engine::Keys::KEY_F, Engine::Keys::KEY_G, Engine::Keys::KEY_H};
        playerMovement->addPlayer(players[1], keys2);
        std::array<Engine::Keys, 4> keys3 = {Engine::Keys::KEY_I, Engine::Keys::KEY_J, Engine::Keys::KEY_K, Engine::Keys::KEY_L};
        playerMovement->addPlayer(players[2], keys3);
        std::array<Engine::Keys, 4> keys4 = {Engine::Keys::KEY_UP, Engine::Keys::KEY_LEFT, Engine::Keys::KEY_DOWN, Engine::Keys::KEY_RIGHT};
        playerMovement->addPlayer(players[3], keys4);

        dropB->init(world);
        dropB->addPlayer(players[0], Engine::Keys::KEY_E);
        dropB->addPlayer(players[1], Engine::Keys::KEY_Y);
        dropB->addPlayer(players[2], Engine::Keys::KEY_O);
        dropB->addPlayer(players[3], Engine::Keys::KEY_CTRL);

        status = 2;
    }

    void IndieGame::runMenu(Engine::World &world, float dt)
    {
        buttonAct->update();
        status = buttonAct->getStatus();
        ren2D->update(dt, world);

    }

    void IndieGame::runGame(Engine::World &world, float dt)
    {
        playerMovement->update(dt, world);
        dropB->update(dt, world);
    }

    float IndieGame::update(Engine::World &world, float dt, WindowManager &window)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        window.poolEvent();
        camSys->update(world);
        // for check the status


	endEffect->update(dt, world);
	isAlive->update(dt, world);
	window.start_draw();
        //----------------------------- rendering 2D (text)

        rendering2D(world, dt);

        //-------------
        camSys->begin(world);

        //------------------------------ rendering 3D (animation)
        rendering3D(world, dt);

        //-------------
        camSys->end(world);

        window.end_draw();
        auto stopTime = std::chrono::high_resolution_clock::now();

        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
        return dt;
    }

    void IndieGame::Loop()
    {
        Engine::World world;
        std::string name = "windob";
        this->status = 0;
        WindowManager window(world, 1920, 1080, name);
        {
            window.start_draw();
            Raylib::RaylibTexture t("assets/landing.png");
            t.setPosition({0.0, 0.0});
            t.draw();
            window.end_draw();
        }
        init(world);
        register_system(world);
        Entities::Factory f(world);
        init_sys(f, world);

        float dt = 1.0f;
        while (window.isActive()) {
            if (status == 0)
                runMenu(world, dt);
            else if (status == 1)
                initGame(world);
            else
                runGame(world, dt);
            dt = update(world, dt, window);
        }
    }
}
