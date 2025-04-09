#pragma once
#include "Deck.hpp"
#include "Flags.hpp"
#include "Hand.hpp"
#include <sys/types.h>
#include <vector>

class GameLogic
{
  public:
  GameLogic();

  void Hit(Hand* hand);
  void DrawHands();
  void DealerTurn();
  void PlayerTurn(int player_flag);
  void DealCards();
  void StartTurn();

  // state functions
  int GetPlayerCount() const {
    return m_NumPlayers;
  }
  void AddPlayer();
  void RemovePlayer();
  uint GetGameState() const {
    return m_GAME_STATE;
  }
  void SetGameState(uint a_GAME_STATE) {
    m_GAME_STATE = a_GAME_STATE;
  }
  int GetTurnCount() const {
    return m_TurnCount;
  }
  void SetPlayers(int cur_player);
  bool VerifyPlayers();
  Hand* GetHands(int index) {
    return m_HandsInPlay[index];
  }

  private:
  void CreateHands();
  bool CheckBust(Hand* hand) const;
  bool CheckBlackJack(Hand* hand) const;
  void CheckWinners();
  void Payout();

  private:
  // Variables
  std::vector<Hand*> m_HandsInPlay;
  int m_NumPlayers;
  int m_TurnCount      = m_NumPlayers;
  int m_MAX_PLAYERS    = 7;
  bool m_isTurnStarted = false;

  uint m_GAME_STATE  = GAME_START;
  uint m_PLAYER_FLAG = m_TurnCount;
  Deck deck;
};
