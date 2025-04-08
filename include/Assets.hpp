#include <raylib.h>
#pragma once

namespace Graphics
{
  inline Texture2D g_suitImage;

  inline Rectangle SpadeBounds   = {0, 0, 33.75, 45};
  inline Rectangle HeartBounds   = {33.75, 0, 33.75, 45};
  inline Rectangle ClubBounds    = {67.5, 0, 33.75, 45};
  inline Rectangle DiamondBounds = {101.25, 0, 33.75, 45};
} // namespace Graphics

namespace Fonts
{
  inline Font g_btn_font   = GetFontDefault();
  inline Font g_title_font = GetFontDefault();
  inline Font g_card_font  = GetFontDefault();
} // namespace Fonts
