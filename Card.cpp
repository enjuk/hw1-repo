#include "Card.h"
using namespace std;

Card::Card(const string& rank, const string& suit) : rank{rank}, suit{suit} {}

void Card::print() const {
    cout << this;
}

ostream& operator<<(ostream& out, const Card& card) {
    out << card.rank << card.suit;
    return out;
}

bool Card::operator==(const Card& other) const {
    return rank == other.rank && suit == other.suit;
}

bool Card::operator!=(const Card& other) const {
    return rank != other.rank || suit != other.suit;
}