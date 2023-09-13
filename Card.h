#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

enum Rank {
    TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN,
    KING, ACE
};

enum Suit {
    CLUBS = 1, DIAMONDS, HEARTS, SPADES
};

class Card {
public:
    Card(const Rank rank, const Suit suit);
    std::string rankAsStr() const;
    std::string suitAsUnicodeStr() const;
    void print() const;
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    
private:
    Rank rank;
    Suit suit;
};

#endif