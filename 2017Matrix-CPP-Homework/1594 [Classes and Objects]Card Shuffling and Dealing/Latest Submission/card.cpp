#include "card.hpp"
#include <string>

using namespace std;

const char* Card::faceNames[totalFaces] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char* Card::suitNames[totalSuits] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int cardFace, int cardSuit) {
  face = cardFace;
  suit = cardSuit;
}

std::string Card::toString() const {
  string str1 = faceNames[face];
  string str2 = suitNames[suit];
  return str1 + " of " + str2;
}

int Card::getFace() const { return face; }

int Card::getSuit() const { return suit; }
