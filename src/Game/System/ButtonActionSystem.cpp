/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** ButtonActionSystem
*/

#include "ButtonActionSystem.hpp"
#include "System.hpp"

namespace System {

    ButtonActionSystem::ButtonActionSystem(std::string name) : Engine::System(name)
    {
    }

    ButtonActionSystem::~ButtonActionSystem()
    {
    }

    void ButtonActionSystem::init(Engine::World &gData)
    {
        status = 0;
        tmpStatus = 0;
        gData.AddEventListener(METHOD_LISTENER(Engine::EventType::KEY_PRESSED, ButtonActionSystem::listener));
    }

    void ButtonActionSystem::listener(Engine::Event &ev)
    {
        auto key = ev.getData();

        if (key == Engine::KEY_ENTER) {
            tmpStatus = 1;
        }
    }

    void ButtonActionSystem::update()
    {
        // for (auto const& entity : mEntities)
        // {
        //     std::cout << "IS IN THE FUNC UPDATE"<< "\n";
        //     if (tmpStatus == 1) {
        //         status = 1;
        //         std::cout << "THIS IS A TEST" << status << "\n";
        //     }
        // }
        if (tmpStatus == 1) {
            status = 1;
        }
    }
}