#ifndef _DECK_H
#define _DECK_H

#include "card.h"
#include <deque>
#include<string>
#include<exception>

class Deck {
     public:
          Deck();
          void Shuffle();
          Card DrawCard();
          void Reset();
          deque<Card> cards; 
};

class EmptyDeckException : public exception {
    private:
    string message;

    public:
    EmptyDeckException(const string& msg) : message(msg) {}
    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif