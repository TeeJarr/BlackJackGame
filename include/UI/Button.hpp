#pragma once
#include "raylib.h"
class Button
{
  public:
  Button(const char* Button_Name, Vector2 Button_Pos);

  void Draw();
  bool isClicked();
  void SetPos(Vector2 new_Button_Pos);

  private:
  Rectangle GetBounds() const;
  const char* m_Button_Name;
  Vector2 m_Button_Pos = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
};
