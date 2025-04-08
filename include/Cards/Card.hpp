#pragma once
#include "string"
#include <raylib.h>

class Card
{
  public:
  Card(const int CardValue, const int Suit, const int a_FaceFlag);
  void swap(Card& other) noexcept;
  ~Card();

  public:
  std::string GetCardName() const;
  int GetCardValue() const;
  int GetSuitValue() const;
  const char* GetSuitName() const;
  std::string GetValueString() const;
  void ChangeValue(int NewValue);
  void DrawCard(Vector2 CardPos) const;
  Vector2 GetCardSize() const;
  const char* GetSuitLetter() const;
  void DrawSuitTexture(Vector2 pos) const;
  void DrawSuitTextureFlipped(Vector2 pos) const;
  int GetFaceFlag() const;

  private:
  Rectangle GetCardRec(Vector2 CardPos) const;
  enum Suits { Clubs, Hearts, Diamond, Spade };
  enum FaceFlags { Jack, Queen, King };
  int CardValue;
  int Suit;

  float base_width  = 2;
  float base_height = 3;
  float scale       = 100;
  float width       = base_width * scale;
  float height      = base_height * scale;

  int CardFontSize = 36;
  int Spacing      = 1;

  float Roundness = 0.2;
  int Segments    = 10;
  float roation   = 180.0f;
  int LineThick   = 3;
  int FaceFlag;
};
