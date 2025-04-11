#pragma once

// Flags
enum player_flags {
  DEALER,
  SEAT_1,
  SEAT_2,
  SEAT_3,
  SEAT_4,
  SEAT_5,
  SEAT_6,
  SEAT_7,
};

enum game_state {
  GAME_START,
  PLAYER_CHOOSING,
  VERIFY_PLAYERS,
  BET_STAGE,
  ROUND_START,
  PLAYER_GOING,
  DEALER_GOING,
};

namespace DEBUG
{
  inline bool g_AlignDebug = true;
  inline bool g_CardDebug  = false;
  inline bool g_UIDebug    = false;
} // namespace DEBUG
