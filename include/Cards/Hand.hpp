#pragma once
#include "Card.hpp"
#include <vector>

class Hand
{
  public:
  Hand();
  ~Hand();
  Card& operator[](int index) {
    return cards[index];
  }

  public:
  Card& GetCard();
  void AddCard(Card n_Card);
  void ClearHand();
  Card& CheckCard(int pos);
  std::vector<Card> GetHand() const;
  int size() const;
  int GetHandValue();
  void SetBustStatus(bool status);
  bool GetBustStatus() const;
  void SetPlaying(bool status);
  bool GetPlayingStatus() const;
  bool GetWinStatus() const;
  void SetWinStatus(bool status);
  bool GetBlackJackStatus() const;
  void SetBlackJackStatus(bool status);
  void SetPush(bool status);
  bool GetPush() const;
  int GetBetAmount() const;
  void SetBetAmount(int bet);

  private:
  std::vector<Card> cards;
  int m_BetAmount    = 0;
  bool m_isBusted    = false;
  bool m_isPlaying   = true;
  bool m_isWinner    = false;
  bool m_isBlackJack = false;
  bool m_isPush      = false;
};
