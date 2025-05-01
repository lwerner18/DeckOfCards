DeckOfCards: main.o deck.o card.o
	g++ -std=c++20 -o DeckOfCards main.o deck.o card.o
	chmod 755 DeckOfCards

main.o: main.cpp deck.h
	g++ -std=c++20 -c main.cpp

deck.o: deck.cpp deck.h card.h
	g++ -std=c++20 -c deck.cpp

card.o: card.cpp card.h
	g++ -std=c++20 -c card.cpp

clean:
	rm -fr *.o *~ DeckOfCards
