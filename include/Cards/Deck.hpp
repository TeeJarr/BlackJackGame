#pragma once
#include "Card.hpp"
#include <vector>

class Deck
{
  public:
  Deck(int numDecks);
  void CreateDeck();
  Card& DealCard();
  void ShuffleDeck();
  std::vector<Card> GetDeck() const;

  private:
  int NumDecks;
  int DeckSize;
  std::vector<Card> deck;
};
