/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** window manager cpp
*/

#include "WindowManager.hpp"

WindowManager::WindowManager(Engine::World &gData, const int &width, const int &height, std::string &title) : _window(width, height, title), _gData(gData)
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::poolEvent()
{
  int key = 0;
  std::array<KeyboardKey, 33> keys = {
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_SPACE,
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_UP,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_DOWN
  };
  Raylib::RaylibKeyboard keyBoard(0);
  
  for (int i = 0; i < 33; i++) {
    keyBoard.setKey(keys[i]);
    if (keyBoard.isKeyDown()) {
      INTER_LOG("KEY PUSH");
      _gData.SendEvent(this->convertEnumToId(keys[i]));
    }
  }
}

EventId WindowManager::convertEnumToId(const int enume)
{
  switch (enume) {
  case (KEY_W):
    return Engine::KEY_Z;
  case (KEY_A):
    return Engine::KEY_Q;
  case (KEY_B):
    return Engine::KEY_B;
  case (KEY_C):
    return Engine::KEY_C;
  case (KEY_D):
    return Engine::KEY_D;
  case (KEY_E):
    return Engine::KEY_E;
  case (KEY_F):
    return Engine::KEY_F;
  case (KEY_G):
    return Engine::KEY_G;
  case (KEY_H):
    return Engine::KEY_H;
  case (KEY_I):
    return Engine::KEY_I;
  case (KEY_J):
    return Engine::KEY_J;
  case (KEY_K):
    return Engine::KEY_K;
  case (KEY_L):
    return Engine::KEY_L;
  case (KEY_M):
    return Engine::KEY_M;
  case (KEY_N):
    return Engine::KEY_N;
  case (KEY_O):
    return Engine::KEY_O;
  case (KEY_P):
    return Engine::KEY_P;
  case (KEY_Q):
    return Engine::KEY_A;
  case (KEY_R):
    return Engine::KEY_R;
  case (KEY_S):
    return Engine::KEY_S;
  case (KEY_T):
    return Engine::KEY_T;
  case (KEY_U):
    return Engine::KEY_U;
  case (KEY_V):
    return Engine::KEY_V;
  case (KEY_X):
    return Engine::KEY_X;
  case (KEY_Y):
    return Engine::KEY_Y;
  case (KEY_Z):
    return Engine::KEY_W;
  case (KEY_SPACE):
    return Engine::KEY_SPACE;
  case (KEY_ENTER):
    return Engine::KEY_ENTER;
  case (KEY_ESCAPE):
    return Engine::KEY_ESCAPE;
  }
  return 0;
}

void WindowManager::start_draw()
{
  _window.beginDrawing();
  _window.clearBackground();
}

void WindowManager::end_draw()
{
  _window.endDrawing();
}

bool WindowManager::isActive()
{
  return !(_window.windowShouldClose());
}
