#include <gtest/gtest.h>
#include <iostream>
#include "card.h"
#include "deck.h"


/* ########################## Card Tests ########################## */
TEST(Card, ReadableName_2OfHearts_WorksAsExpected) {
     Card c(HEARTS, 2);

     std::ostringstream oss;
     oss << c;

     EXPECT_EQ(oss.str(), "2 of Hearts");
}

TEST(Card, ReadableName_JackOfClubs_WorksAsExpected) {
     Card c(CLUBS, 11);

     std::ostringstream oss;
     oss << c;

     EXPECT_EQ(oss.str(), "Jack of Clubs");
}

TEST(Card, ReadableName_QueenOfDiamonds_WorksAsExpected) {
     Card c(DIAMONDS, 12);

     std::ostringstream oss;
     oss << c;

     EXPECT_EQ(oss.str(), "Queen of Diamonds");
}

TEST(Card, ReadableName_KingOfSpades_WorksAsExpected) {
     Card c(SPADES, 13);

     std::ostringstream oss;
     oss << c;

     EXPECT_EQ(oss.str(), "King of Spades");
}

TEST(Card, ReadableName_AceOfHearts_WorksAsExpected) {
     Card c(HEARTS, 14);

     std::ostringstream oss;
     oss << c;

     EXPECT_EQ(oss.str(), "Ace of Hearts");
}

/* ########################## Deck Tests ########################## */
TEST(Deck, CreateDeck_WorksAsExpected) {
     Deck deck;

     EXPECT_EQ(52, deck.cards.size());
}

TEST(Deck, DrawCard_WorksAsExpected) {
     Deck deck;

     Card topCard = deck.cards.at(0);
     Card drawnCard = deck.DrawCard();

     EXPECT_EQ(topCard, drawnCard);
     EXPECT_EQ(51, deck.cards.size());
}

TEST(Deck, DrawCard_Exception_WhenEmpty) {
     Deck deck;

     while (!deck.cards.empty()) {
          deck.DrawCard();
     }

     ASSERT_THROW(deck.DrawCard(), EmptyDeckException);
}

TEST(Deck, DrawCard_NoException_WhenNotEmpty) {
     Deck deck;

     ASSERT_FALSE(deck.cards.empty());

     ASSERT_NO_THROW(deck.DrawCard());
}

TEST(Deck, Shuffle_Exception_WhenEmpty) {
     Deck deck;

     while (!deck.cards.empty()) {
          deck.DrawCard();
     }

     ASSERT_THROW(deck.Shuffle(), EmptyDeckException);
}

TEST(Deck, Shuffle_NoException_WhenNotEmpty) {
     Deck deck;

     ASSERT_FALSE(deck.cards.empty());

     ASSERT_NO_THROW(deck.Shuffle());
}

TEST(Deck, Shuffle_WorksAsExpected) {
     Deck deck;
     Deck originalDeck = deck;

     deck.Shuffle();

     ASSERT_NE(originalDeck.cards, deck.cards);
}

TEST(Deck, Reset_ShuffleOnly_WorksAsExpected) {
     Deck deck;
     Deck originalDeck = deck;

     deck.Shuffle();
     deck.Reset();

     ASSERT_EQ(originalDeck.cards, deck.cards);
}

TEST(Deck, Reset_ShuffleAndDraw_WorksAsExpected) {
     Deck deck;
     Deck originalDeck = deck;

     deck.Shuffle();
     deck.DrawCard();
     deck.Reset();

     ASSERT_EQ(originalDeck.cards, deck.cards);
}

/* ########################## Main Function ########################## */
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}