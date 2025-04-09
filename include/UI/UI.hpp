#pragma once
#include "Button.hpp"
#include "raylib.h"
#include <map>
#include <string>

namespace UI
{
  inline std::map<std::string, Button> g_btn_map;
  inline unsigned int SCREEN_WIDTH  = 1920;
  inline unsigned int SCREEN_HEIGHT = 1080;

  inline Vector2 m_btn_hit_pos  = {UI::SCREEN_WIDTH * 0.45f, UI::SCREEN_HEIGHT * 0.9f};
  inline Vector2 m_btn_stay_pos = {UI::SCREEN_WIDTH * 0.55f, UI::SCREEN_HEIGHT * 0.9f};
  inline Vector2 m_btn_dd_pos;
  inline Vector2 m_btn_ins_pos;
  inline Vector2 m_btn_split_pos;
  inline Vector2 m_btn_add_pos;
  inline Vector2 m_btn_rmv_pos;
  inline Vector2 m_btn_bet_pos;
  inline Vector2 m_btn_play_pos = {UI::SCREEN_WIDTH * 0.45f, UI::SCREEN_HEIGHT * 0.5f};
  inline Vector2 m_btn_sit_pos  = {UI::SCREEN_WIDTH * 0.55f, UI::SCREEN_HEIGHT * 0.5f};
} // namespace UI
