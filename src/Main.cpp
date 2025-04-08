#include "Assets.hpp"
#include "GameLoop.hpp"
#include "UI.hpp"
#include "raylib.h"

void LoadTextures();
void LoadButtons();

int main() {
  InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "Black Jack");
  SetTargetFPS(60);
  LoadTextures();
  LoadButtons();

  GameLoop game;

  while (!WindowShouldClose()) {
    game.Update();
    game.Draw();
  }

  CloseWindow();
  return 0;
}

void LoadTextures() {
  Image baseSuitImage = LoadImage("../../res/images/suits.png");
  ImageResize(&baseSuitImage, 135, 45);
  Graphics::g_suitImage = LoadTextureFromImage(baseSuitImage);
  UnloadImage(baseSuitImage);
}

void LoadButtons() {
  UI::g_btn_map.emplace("Hit", Button("Hit", UI::m_btn_hit_pos));
  UI::g_btn_map.emplace("Stay", Button("Stay", UI::m_btn_stay_pos));
  UI::g_btn_map.emplace("Double", Button("Double Down", UI::m_btn_dd_pos));
  UI::g_btn_map.emplace("Play", Button("Play Hand", UI::m_btn_play_pos));
  UI::g_btn_map.emplace("Sit", Button("Sit Hand", UI::m_btn_sit_pos));
}
