#include "Hand.hpp"
#include <vector>

Hand::Hand() {}

Hand::~Hand() {}

Card& Hand::GetCard() {
  Card& n_Card = cards.back();
  cards.pop_back();
  return n_Card;
}

void Hand::AddCard(Card n_Card) {
  cards.push_back(n_Card);
}

void Hand::ClearHand() {
  cards.clear();
}
std::vector<Card> Hand::GetHand() const {
  return cards;
}

Card& Hand::CheckCard(int pos) {
  return cards[pos];
}

int Hand::size() const {
  return cards.size();
}

int Hand::GetHandValue() {
  int HandValue = 0;
  for (Card card : cards) {
    HandValue += card.GetCardValue();
  }
  return HandValue;
}

void Hand::SetBustStatus(bool status) {
  m_isBusted = status;
}

bool Hand::GetBustStatus() const {
  return m_isBusted;
}

void Hand::SetPlaying(bool status) {
  m_isPlaying = status;
}

bool Hand::GetPlayingStatus() const {
  return m_isPlaying;
}

bool Hand::GetBlackJackStatus() const {
  return m_isBlackJack;
}

void Hand::SetBlackJackStatus(bool status) {
  m_isBlackJack = status;
}

bool Hand::GetWinStatus() const {
  return m_isWinner;
}

void Hand::SetWinStatus(bool status) {
  m_isWinner = status;
}

bool Hand::GetPush() const {
  return m_isPush;
}

void Hand::SetPush(bool status) {
  m_isPush = status;
}
