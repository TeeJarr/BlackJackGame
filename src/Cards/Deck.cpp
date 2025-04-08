#include "Deck.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

Deck::Deck(int numDecks) : NumDecks(numDecks) {
  CreateDeck();
}

void Deck::CreateDeck() {
  for (int DeckNum = 0; DeckNum < NumDecks; DeckNum++) {
    // Number Cards
    for (int val = 1; val < 10; val++) {
      for (int suit = 0; suit < 4; suit++) {
        Card newCard(val, suit, 0);
        deck.push_back(newCard);
      }
    }

    // Face Cards
    for (int val = 0; val < 4; val++) {
      for (int suit = 0; suit < 4; suit++) {
        Card newCard(10, suit, val);
        deck.push_back(newCard);
      }
    }
  }

  std::cout << "Created Deck\n";
}

Card& Deck::DealCard() {
  Card& card = deck.back();
  deck.pop_back();
  return card;
}

void Deck::ShuffleDeck() {
  std::random_device rd;
  static std::mt19937 rng(rd());
  std::shuffle(deck.begin(), deck.end(), rng);
}

std::vector<Card> Deck::GetDeck() const {
  return deck;
}
