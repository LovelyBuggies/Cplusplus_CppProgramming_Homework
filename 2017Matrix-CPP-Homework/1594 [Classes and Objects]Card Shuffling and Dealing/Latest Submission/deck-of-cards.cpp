#include "card.hpp"
#include "deck-of-cards.hpp"

DeckOfCards::DeckOfCards(){
  currentCard=0;
  for(int j=0;j<Card::totalSuits;j++)
  	for(int i=0;i<Card::totalFaces;i++) {
    	deck.push_back(Card(i, j));
   }
}

Card DeckOfCards::dealCard() {
  currentCard++;
  return deck[currentCard-1];
}

bool DeckOfCards::moreCards() const {
  return (currentCard == 52)? false : true;
}