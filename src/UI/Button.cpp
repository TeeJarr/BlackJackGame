#include "Button.hpp"
#include "Assets.hpp"
#include "raylib.h"

Button::Button(const char* Button_Name, Vector2 Button_Pos) : m_Button_Name(Button_Name), m_Button_Pos(Button_Pos) {}

void Button::Draw() {
  DrawRectangleRec(GetBounds(), WHITE);
  DrawTextEx(Fonts::g_btn_font, m_Button_Name, {m_Button_Pos.x, m_Button_Pos.y}, 36, 1, BLACK);
}

void Button::SetPos(Vector2 new_Button_Pos) {
  m_Button_Pos = new_Button_Pos;
}

Rectangle Button::GetBounds() const {
  Vector2 text_size = MeasureTextEx(GetFontDefault(), m_Button_Name, 36, 1);
  return {m_Button_Pos.x, m_Button_Pos.y, text_size.x, text_size.y};
}

bool Button::isClicked() {
  if (CheckCollisionPointRec(GetMousePosition(), GetBounds()) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    return true;
  }
  return false;
}
