#include"deck.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<algorithm>

using namespace std;


/* ########################## Helper Functions ########################## */
void initializeCards(deque<Card>& cards) {
     // add a card of each suit for each rank
     for (int i = 2; i < 15; i++) {
          cards.push_back(Card(CLUBS, i));
          cards.push_back(Card(DIAMONDS, i));
          cards.push_back(Card(HEARTS, i));
          cards.push_back(Card(SPADES, i));
     }
}

/* ########################## Constructors ########################## */
Deck::Deck() {
     initializeCards(cards);
}

/* ########################## Implementations ########################## */

// I know there is a built in shuffle function described here https://cplusplus.com/reference/algorithm/shuffle/
// However, since this is an assesment, I wrote my own shuffling algorithm.
void Deck::Shuffle() {
     if (cards.empty()) {
          throw EmptyDeckException("Cannot shuffle empty deck.");
     }

     // seed my random number generator
     srand(time(0));

     for (int i = 0; i < 104; i++) {
          // get the index of a random card
          int firstRandomCard = rand() % 51;

          // get the index of another random card
          int secondRandomCard = rand() % 51;

          // swap the cards
          iter_swap(cards.begin() + firstRandomCard, cards.begin() + secondRandomCard);
     }
}

Card Deck::DrawCard() {
     if (cards.empty()) {
          throw EmptyDeckException("Cannot draw card from empty deck.");
     }

     Card topCard = cards[0];

     cards.pop_front();

     return topCard;
}

void Deck::Reset() {
     cards.clear();

     initializeCards(cards);
}