#include "GameLogic.hpp"
#include "Flags.hpp"
#include "UI.hpp"
#include "raylib.h"
#include <iostream>

GameLogic::GameLogic() : deck(1), m_NumPlayers(2) {
  CreateHands();
  deck.ShuffleDeck();
}

void GameLogic::StartTurn() {
  m_isTurnStarted = true;
  m_TurnCount     = m_NumPlayers;
  m_PLAYER_FLAG   = m_NumPlayers;
  CreateHands();
  SetGameState(PLAYER_CHOOSING);
  // Collect bets for the players and if they are
  // playing the turn or not
}

void GameLogic::PlayerTurn(int player_flag) {
  if (m_TurnCount == 0) {
    SetGameState(DEALER_GOING);
    return;
  }
  // std::cout << "Is playing: " << (bool)m_HandsInPlay[player_flag]->GetPlayingStatus() <<
  // std::endl;
  if (!m_HandsInPlay[player_flag]->GetPlayingStatus()) {
    std::cout << "Is playing: " << (bool)m_HandsInPlay[player_flag]->GetPlayingStatus()
              << std::endl;
    m_TurnCount--;
  }
  // 1. Choose the players with their hand index
  // in descending order
  // 2. Choose Between Hit, Stay, Double, Split,
  // Insurance Options
  // 3. If player goes over 21 auto bust
  // 5. Loops until the player finishes their turn
  if (m_PLAYER_FLAG == player_flag) {
    std::cout << "Player: " << player_flag
              << " hand value: " << m_HandsInPlay[player_flag]->GetHandValue() << std::endl;
    std::cout << "Player turn: " << player_flag << " has started\n";
    m_PLAYER_FLAG--;
  }
  if (UI::g_btn_map.at("Hit").isClicked()) {
    // Hit Logic
    std::cout << "Hit\n";
    Hit(m_HandsInPlay[player_flag]);
    if (CheckBust(m_HandsInPlay[player_flag])) {
      m_TurnCount--;
    }
  }
  if (UI::g_btn_map.at("Stay").isClicked()) {
    // Stay logic
    std::cout << "Stay\n";
    m_TurnCount--;
  }
}
void GameLogic::DealerTurn() {
  // 1. check for dealer black jack
  // 2. check for a player black jack
  // 3. draw cards until the dealer has drawn all the cards
  // 4. check each player hand to see if they won in order to pay out
  if (CheckBlackJack(m_HandsInPlay[DEALER])) {
    std::cout << "Dealer Black Jack\n";
  }
  while (m_HandsInPlay[DEALER]->GetHandValue() < 16) {
    m_HandsInPlay[DEALER]->AddCard(deck.DealCard());
    std::cout << "Dealer Hand Value: " << m_HandsInPlay[DEALER]->GetHandValue() << std::endl;
    if (CheckBust(m_HandsInPlay[DEALER])) {
      std::cout << "Dealer Busts: " << m_HandsInPlay[DEALER]->GetHandValue() << "\n";
    }
  }
  CheckWinners();
}

// ----- | Game Features | ----- //
bool GameLogic::CheckBust(Hand* hand) const {
  int HandVal = hand->GetHandValue();
  std::cout << HandVal << "\n";
  if (HandVal > 21) {
    hand->SetBustStatus(true);
    return true;
  } else {
    return false;
  }
}

bool GameLogic::CheckBlackJack(Hand* hand) const {
  int HandValue = hand->GetHandValue();
  std::cout << HandValue << "\n";
  if (HandValue == 21) {
    hand->SetBlackJackStatus(true);
    return true;
  } else {
    return false;
  }
}

void GameLogic::CheckWinners() {
  if (m_HandsInPlay[DEALER]->GetBustStatus()) {
    return;
  }
  for (int player = SEAT_1; player <= m_NumPlayers; player++) {
    if (!m_HandsInPlay[player]->GetPlayingStatus()) {
      continue;
    }
    if (m_HandsInPlay[player]->GetBustStatus()) {
      std::cout << "player: " << player << " busts\n";
      continue;
    }
    if (m_HandsInPlay[player]->GetHandValue() > m_HandsInPlay[DEALER]->GetHandValue()) {
      std::cout << "player: " << player << " wins\n";
      m_HandsInPlay[player]->SetWinStatus(true);
    } else if (m_HandsInPlay[player]->GetHandValue() < m_HandsInPlay[DEALER]->GetHandValue()) {
      std::cout << "player: " << player << " loses\n";
      m_HandsInPlay[player]->SetWinStatus(false);
      m_HandsInPlay[player]->SetBustStatus(true);
    } else if (m_HandsInPlay[player]->GetHandValue() == m_HandsInPlay[DEALER]->GetHandValue()) {
      std::cout << "player: " << player << " pushes\n";
      m_HandsInPlay[player]->SetPush(true);
    }
  }
}

void GameLogic::Hit(Hand* hand) {
  hand->AddCard(deck.DealCard());
}

void GameLogic::Payout() {
  for (int cur = SEAT_1; cur < m_NumPlayers; cur++) {
    if (m_HandsInPlay[cur]->GetWinStatus()) {
      std::cout << "Player " << cur << ": Wins\n";
      // Double the win amount and return the
      // money to them
    }
    if (m_HandsInPlay[cur]->GetPush()) {
      std::cout << "Player " << cur << ": Pushes\n";
      // return hands bet to them
    }
    if (m_HandsInPlay[cur]->GetBustStatus()) {
      std::cout << "Player " << cur << ": Loses\n";
      // Remove the money from they're bank roll
    }
  }
}

void GameLogic::DealCards() {
  for (int i = 0; i < 2; i++) {
    int index = 0;
    for (Hand* hand : m_HandsInPlay) {
      if (hand->GetPlayingStatus()) {
        Hit(hand);
      } else {
        continue;
      }
      std::cout << "(" << index << ") Card Added, Hand Size: " << hand->size()
                << ", Current Card: " << hand->CheckCard(hand->size() - 1).GetCardName() << "\n";
      index++;
    }
  }
  std::cout << "Cards Dealt\n";
  SetGameState(PLAYER_GOING);
}
// ----- | Helper Functions | ----- //
void GameLogic::CreateHands() {
  std::vector<Hand*> newHands;
  newHands.push_back(new Hand());
  for (int i = 0; i < m_NumPlayers; i++) {
    newHands.push_back(new Hand());
  }
  m_HandsInPlay = newHands;
}

void GameLogic::SetPlayers(int cur_player) {
  // make it use pop up buttons to decided if they
  // are in play or not
  if (m_TurnCount == 0) {
    m_TurnCount = m_NumPlayers;
    return;
  }
  if (UI::g_btn_map.at("Play").isClicked()) {
    m_HandsInPlay[cur_player]->SetPlaying(true);
    m_TurnCount--;
  }
  if (UI::g_btn_map.at("Sit").isClicked()) {
    m_HandsInPlay[cur_player]->SetPlaying(false);
    m_TurnCount--;
  }
}

bool GameLogic::VerifyPlayers() {
  std::cout << "Verifying Players\n";
  for (int i = 1; i <= m_NumPlayers; i++) {
    if (m_HandsInPlay[i]->GetPlayingStatus()) {
      std::cout << "Player: " << i << " is playing\n";
      return true;
    }
  }
  return false;
}

void GameLogic::AddPlayer() {
  m_NumPlayers++;
  CreateHands();
}

void GameLogic::RemovePlayer() {
  m_NumPlayers--;
  CreateHands();
}

// ----- | Drawing Functions | ----- //

void GameLogic::DrawHands() {
  // iteratre through all of the hands that are
  // playing that round
  for (int i = m_NumPlayers; i > 1; i--) {
    // draw every card with the proper offset in
    // accordance to how many cards there are in
    // the hand be able to look at the other non
    // dealer hands that are in play as well
  }
  // draw dealer hands that only show the first
  // card face up until all of the players have
  // finished hitting
}
