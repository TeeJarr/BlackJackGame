#pragma once
#include "GameLogic.hpp"
#include "TextBox.hpp"
#include <raylib.h>

class GameLoop
{
  public:
  GameLoop();

  void Draw();
  void Update();

  private:
  void DrawUI();

  private:
  // UI Variables
  Color m_Bg_Color = DARKGREEN;
  // Buttons
  TextBox bet_input;

  GameLogic game;
  bool gone = true;
};
