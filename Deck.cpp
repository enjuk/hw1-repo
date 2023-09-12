#include "Deck.h"
#include <iostream>
#include <iomanip>
using namespace std;

const string Deck::possibleRanks[RANK_SIZE] = {"2", "3", "4", "5", "6", "7",
                                            "8", "9", "10", "J", "Q", "K", "A"};
const string Deck::possibleSuits[SUIT_SIZE] = {"\u2663", "\u2662", "\u2661", 
                                               "\u2660"};
Deck::Deck() { 
    for (const auto& suit : possibleSuits) {
        for (const auto& rank : possibleRanks) {
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