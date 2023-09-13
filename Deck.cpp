#include "Deck.h"
#include <iostream>
#include <iomanip>
using namespace std;

const Rank Deck::allRanks[RANK_SIZE] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                                      EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

const Suit Deck::allSuits[SUIT_SIZE] = {CLUBS, DIAMONDS, HEARTS, SPADES};

Deck::Deck() { 
    for (const auto& suit : allSuits) {
        for (const auto& rank : allRanks) {
            cards.push_back(new Card(rank, suit));
        }
    }
}

Deck::~Deck() {
    for (const auto& card : cards) {
        delete card;
    }
}

void Deck::print() const {
    list<Card*>::const_iterator it = cards.begin();
    for (int i = 0; it != cards.end(); it++, i++) {
        // print out the cards in rows of RANK_SIZE
        cout << setw(3) << **it << ((i + 1) % RANK_SIZE == 0 ? "\n" : " ");
    }
}

void Deck::performPerfectShuffle() {
    list<Card*>::iterator itTopHalf = cards.begin();
    itTopHalf++;

    list<Card*>::iterator itBottomHalf = cards.begin();
    advance(itBottomHalf, cards.size() / 2);

    for (; itBottomHalf != cards.end(); itTopHalf++) {
        cards.insert(itTopHalf, *itBottomHalf);
        itBottomHalf = cards.erase(itBottomHalf);
    }
}

bool Deck::operator==(const Deck& other) const {
    list<Card*>::const_iterator it = cards.begin();
    list<Card*>::const_iterator itOther = other.cards.begin();

    for (; it != cards.end(); it++, itOther++) {
        if (**it != **itOther) {
            return false;
        }
    }
    return true;
}

bool Deck::operator!=(const Deck& other) const {
    list<Card*>::const_iterator it = cards.begin();
    list<Card*>::const_iterator itOther = other.cards.begin();
    
    for (; it != cards.end(); it++, itOther++) {
        if (**it != **itOther) {
            return true;
        }
    }
    return false;
}