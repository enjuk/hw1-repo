#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

enum class Rank {
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen,
    king, ace
};

enum class Suit {
    clubs = 1, diamonds, hearts, spades
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