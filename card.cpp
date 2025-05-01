#include"card.h"
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

/* ########################## Helper Functions ########################## */
string suitToString(Suit suit) {
    switch (suit) {
        case CLUBS:    return "Clubs";
        case DIAMONDS: return "Diamonds";
        case HEARTS:   return "Hearts";
        case SPADES:   return "Spades";
        default:       return "Unknown suit";
    }
}

string rankToString(int rank) {
    switch (rank) {
        case 14: return "Ace";
        case 13: return "King";
        case 12: return "Queen";
        case 11: return "Jack";
        default: return to_string(rank);
    }
}

/* ########################## Implementations ########################## */
ostream& operator<<(ostream& os, const Card& c) {
     os << rankToString(c.rank) << " of " << suitToString(c.suit);

     return os;
}

bool operator==(const Card& c1, const Card& c2) {
     return c1.suit == c2.suit && c1.rank == c2.rank;
}