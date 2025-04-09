#include "GameLoop.hpp"
#include "Assets.hpp"
#include "Flags.hpp"
#include "TextBox.hpp"
#include "UI.hpp"
#include "raylib.h"
#include <iostream>
#include <string>

GameLoop::GameLoop() {}

void GameLoop::Draw() {
  BeginDrawing();
  ClearBackground(m_Bg_Color);
  DrawUI();
  EndDrawing();
}

void GameLoop::Update() {
  if (bet_input.CollectInput() &&
      game.GetGameState() == GAME_START) { // Should Be Bet Stage Going Forward
    std::cout << "Enter Pressed and players are now going\n";
    game.SetGameState(PLAYER_CHOOSING);
    game.StartTurn();
  }

  if (game.GetGameState() == PLAYER_CHOOSING) {
    if (game.GetTurnCount() == 0) {
      game.SetGameState(VERIFY_PLAYERS);
    }
    game.SetPlayers(game.GetTurnCount());
  }

  if (game.GetGameState() == VERIFY_PLAYERS) {
    if (game.VerifyPlayers()) {
      std::cout << "Dealing Cards and starting game\n";
      game.DealCards();
      game.SetGameState(PLAYER_GOING);
      std::cout << "Restarting gam\n";
    } else {
      game.SetGameState(GAME_START);
    }
  }

  if (game.GetGameState() == PLAYER_GOING) {
    // std::cout << "Turns are starting\n";
    game.PlayerTurn(game.GetTurnCount());
    // game.SetGameState(DEALER_GOING);
  }

  if (game.GetGameState() == DEALER_GOING) {
    std::cout << "Dealer Going\n";
    game.DealerTurn();
    game.SetGameState(GAME_START);
  }
}

void GameLoop::DrawUI() {
  if (game.GetGameState() == GAME_START) {
    DrawTextEx(GetFontDefault(), "Press Enter to start...",
               {UI::SCREEN_WIDTH * 0.5f, UI::SCREEN_HEIGHT * 0.5f}, 36, 1, WHITE);
  }

  if (game.GetGameState() == PLAYER_CHOOSING) {
    DrawTextEx(GetFontDefault(),
               (std::string("Player: ") + std::to_string(game.GetTurnCount())).c_str(),
               {UI::SCREEN_WIDTH * 0.5f, UI::SCREEN_HEIGHT * 0.45f}, 36, 1, WHITE);
    UI::g_btn_map.at("Play").Draw();
    UI::g_btn_map.at("Sit").Draw();
  }
  if (game.GetGameState() == PLAYER_GOING) {
    DrawTextEx(GetFontDefault(),
               std::to_string(game.GetHands(game.GetTurnCount())->GetHandValue()).c_str(),
               {UI::SCREEN_WIDTH * 0.5f, UI::SCREEN_HEIGHT * 0.85f}, 36, 1, WHITE);
    UI::g_btn_map.at("Hit").Draw();
    UI::g_btn_map.at("Stay").Draw();
  }

  bet_input.Draw();
}
