#include <iostream>
#include <string>

using namespace std;

#ifndef _CARD_H
#define _CARD_H

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};


// Each card has a suit and rank (number). Since the prompt mentioned a 52 card deck, this does not support jokers
// One way a joker could be supported is by allowing suit and rank to be null and interpretting that scenario as a joker
class Card {
     public:
          Card(Suit s, int r) : suit(s), rank(r) {};
          friend ostream& operator<<(ostream& os, const Card& c);  // overload operator to print out Card
          friend bool operator==(const Card& c1, const Card& c2);  // overload operator to compare Cards

     private:
          Suit suit;
          int rank;
};

#endif