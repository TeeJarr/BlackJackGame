#pragma once
#include "raylib.h"

class TextBox
{
  public:
  TextBox();
  bool CollectInput();
  void Draw();

  private:
  unsigned int let_count = 0;
#define MAX_INPUT_CHARS 5
  char char_buff[MAX_INPUT_CHARS + 1] = "\0";
  Vector2 m_pos;
};
