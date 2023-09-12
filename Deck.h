#include "Card.h"
#include <list>

#ifndef DECK_H
#define DECK_H

class Deck {
public:
    Deck();
    ~Deck();
    void performPerfectShuffle();
    void print() const;
    bool operator==(const Deck& other) const;
    bool operator!=(const Deck& other) const;
    
private:
    const static int RANK_SIZE = 13;
    const static int SUIT_SIZE = 4;
    const static Rank allRanks[RANK_SIZE];
    const static Suit allSuits[SUIT_SIZE];
    std::list<Card*> cards;
};

#endif