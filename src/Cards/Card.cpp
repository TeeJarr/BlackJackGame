#include "Card.hpp"
#include "Assets.hpp"
#include "UI.hpp"
#include "raylib.h"
#include <string>
#include <utility>

Card::Card(const int a_CardValue, const int a_Suit, const int a_FaceFlag)
    : CardValue(a_CardValue), Suit(a_Suit), FaceFlag(a_FaceFlag) {
  if (CardValue == 1) {
    ChangeValue(11);
  }
}

Card::~Card() {
  // std::cout << "Card Destroyed\n";
}

void Card::swap(Card& other) noexcept {
  std::swap(this->CardValue, other.CardValue);
  std::swap(this->Suit, other.Suit);
  std::swap(this->FaceFlag, other.FaceFlag);
}

std::string Card::GetValueString() const {
  if (CardValue < 10 && CardValue != 1) {
    return std::to_string(CardValue).c_str();
  } else if (CardValue == 11 || CardValue == 1) {
    return "A";
  } else {
    switch (FaceFlag) {
      case Jack : return "J"; break;
      case Queen: return "Q"; break;
      case King : return "K"; break;
      default   : return "10"; break;
    }
  }
}

void Card::DrawCard(Vector2 CardPos) const {
  // std::cout << IsFontValid(GlobalConstants::CardFont) << "\n";
  Color CardColor;
  if (Suit == Clubs || Suit == Spade) {
    CardColor = BLACK;
  } else {
    CardColor = RED;
  }

  DrawRectangleRounded(GetCardRec(CardPos), Roundness, Segments, WHITE);
  DrawRectangleRoundedLinesEx(GetCardRec(CardPos), Roundness, Segments, LineThick, CardColor);

  Vector2 textPos  = {CardPos.x * 1.02f, CardPos.y * 1.02f};
  Vector2 textSize = MeasureTextEx(GetFontDefault(), GetValueString().c_str(), 36, 1);
  DrawTextEx(Fonts::g_card_font, GetValueString().c_str(), textPos, CardFontSize, Spacing, CardColor);
  DrawSuitTexture({textPos.x - textSize.x * 0.5f, textPos.y + textSize.y});

  Vector2 secondPos = {((CardPos.x + width) - textSize.x * 0.5f) * 0.99f,
                       ((CardPos.y + height) - textSize.y * 0.5f) * 0.99f};
  Vector2 origin    = {(textSize.x * 0.5f), (textSize.y * 0.5f)};
  DrawTextPro(Fonts::g_card_font, GetValueString().c_str(), secondPos, origin, roation, CardFontSize, Spacing, BLACK);
  DrawSuitTextureFlipped({secondPos.x - textSize.x * 0.2f, secondPos.y - textSize.y});
}

void Card::DrawSuitTexture(Vector2 pos) const {
  switch (GetSuitValue()) {
    case Clubs  : DrawTextureRec(Graphics::g_suitImage, Graphics::ClubBounds, pos, WHITE); break;
    case Hearts : DrawTextureRec(Graphics::g_suitImage, Graphics::HeartBounds, pos, WHITE); break;
    case Spade  : DrawTextureRec(Graphics::g_suitImage, Graphics::SpadeBounds, pos, WHITE); break;
    case Diamond: DrawTextureRec(Graphics::g_suitImage, Graphics::DiamondBounds, pos, WHITE); break;
  }
}

void Card::DrawSuitTextureFlipped(Vector2 pos) const {
  Vector2 origin = {Graphics::ClubBounds.width * 0.5f, Graphics::ClubBounds.height * 0.5f};
  switch (GetSuitValue()) {
    case Clubs:
      DrawTexturePro(Graphics::g_suitImage, Graphics::ClubBounds,
                     {pos.x, pos.y, Graphics::ClubBounds.width, Graphics::ClubBounds.height}, origin, roation, WHITE);
      break;
    case Hearts:
      DrawTexturePro(Graphics::g_suitImage, Graphics::HeartBounds,
                     {pos.x, pos.y, Graphics::ClubBounds.width, Graphics::ClubBounds.height}, origin, roation, WHITE);
      break;
    case Spade:
      DrawTexturePro(Graphics::g_suitImage, Graphics::SpadeBounds,
                     {pos.x, pos.y, Graphics::ClubBounds.width, Graphics::ClubBounds.height}, origin, roation, WHITE);
      break;
    case Diamond:
      DrawTexturePro(Graphics::g_suitImage, Graphics::DiamondBounds,
                     {pos.x, pos.y, Graphics::ClubBounds.width, Graphics::ClubBounds.height}, origin, roation, WHITE);
      break;
  }
}

Vector2 Card::GetCardSize() const {
  return {width, height};
}

Rectangle Card::GetCardRec(Vector2 CardPos) const {
  return {CardPos.x, CardPos.y, width, height};
}

const char* Card::GetSuitLetter() const {
  switch (Suit) {
    case Clubs  : return "C";
    case Hearts : return "H";
    case Diamond: return "D";
    case Spade  : return "S";
    default     : return "";
  }
}

const char* Card::GetSuitName() const {
  switch (Suit) {
    case Clubs  : return "Clubs";
    case Hearts : return "Hearts";
    case Diamond: return "Diamond";
    case Spade  : return "Spades";
    default     : return "";
  }
}

int Card::GetCardValue() const {
  return CardValue;
}

int Card::GetSuitValue() const {
  return Suit;
}

std::string Card::GetCardName() const {
  std::string FullName = GetValueString() + " of " + GetSuitName();
  return FullName;
}

void Card::ChangeValue(int NewValue) {
  CardValue = NewValue;
}

int Card::GetFaceFlag() const {
  return FaceFlag;
}
