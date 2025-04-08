#include "TextBox.hpp"
#include "Assets.hpp"
#include "UI.hpp"
#include "raylib.h"
#include <iostream>

TextBox::TextBox() : m_pos({UI::SCREEN_WIDTH / 2.0f, UI::SCREEN_HEIGHT / 2.0f}) {}

bool TextBox::CollectInput() {
  int key = GetKeyPressed();

  while (key > 0) {
    if ((key > 47) && (key < 58) && (let_count < MAX_INPUT_CHARS)) {
      std::cout << key << std::endl;
      char_buff[let_count]     = (char)key;
      char_buff[let_count + 1] = '\0';
      let_count++;
    }
    key = GetKeyPressed();
  }

  if (IsKeyPressed(KEY_BACKSPACE)) {
    let_count--;
    if (let_count < 0 || let_count > MAX_INPUT_CHARS) {
      let_count = 0;
    }
    char_buff[let_count] = '\0';
  }

  if (IsKeyPressed(KEY_ENTER)) {
    std::cout << char_buff << '\n';
    return true;
  }
  return false;
}

void TextBox::Draw() {
  DrawTextEx(Fonts::g_btn_font, char_buff, m_pos, 36, 1, BLACK);
}
