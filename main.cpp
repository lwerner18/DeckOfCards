#include"deck.h"
#include<iostream>

using namespace std;

int main() {
     char input;
     char capitalInput;

     cout << "Welcome to Deck of Cards. Creating deck now..." << endl;

     Deck deck;

     do {
          cout << "\nThere are " << deck.cards.size() << " cards in the deck." << endl;
          cout << "Would you like to [S]huffle, [D]raw Card, [R]eset the deck or [Q]uit?" << endl;

          cin >> input;
          capitalInput = toupper(input);

          if (capitalInput != 'S' && capitalInput != 'D' && capitalInput != 'R' && capitalInput != 'Q') {
               cout << "Invalid input. Please try again." << endl;
          } else {
               switch (capitalInput) {
                    case 'S':
                         try {
                              deck.Shuffle();
                              cout << "Deck shuffled!" << endl;
                         } catch (EmptyDeckException& e) {
                              cerr << "You cannot shuffle an empty deck" << endl;
                         }
                        
                         break;
                    case 'D':
                         try {
                              Card drawnCard = deck.DrawCard();
                              cout << "You drew the " << drawnCard << endl;
                         } catch (EmptyDeckException& e) {
                              cerr << "You cannot draw on an empty deck" << endl;
                         }
                         
                         break;
                    case 'R':
                         deck.Reset();
                         cout << "Deck reset! You now have " << deck.cards.size() << " cards." << endl;
                         break;
               }
          }

          // In case the user entered more than just one char, clear the buffer.
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
     } while(capitalInput != 'Q');

     cout << "Goodbye!"; 
     
     return 0;
}


