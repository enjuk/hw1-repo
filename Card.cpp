#include "Card.h"
using namespace std;

Card::Card(Rank rank, Suit suit) : rank{rank}, suit{suit} {}

void Card::print() const {
    cout << this;
}

string Card::rankAsStr() const {
    switch (rank) {
        case TWO : return "2";
        case THREE : return "3";
        case FOUR : return "4";
        case FIVE : return "5";
        case SIX : return "6";
        case SEVEN : return "7";
        case EIGHT : return "8";
        case NINE : return "9";
        case TEN : return "10";
        case JACK : return "J";
        case QUEEN : return "Q";
        case KING : return "K";
        case ACE : return "A";
    }
    return "ERROR: Invalid Rank";
}

string Card::suitAsUnicodeStr() const {
    switch (suit) {
        case CLUBS : return "\u2663";
        case DIAMONDS : return "\u2662";
        case HEARTS : return "\u2661";
        case SPADES : return "\u2660";
    }
    return "ERROR: Invalid Suit";
}

ostream& operator<<(ostream& out, const Card& card) {
    out << card.rankAsStr() << card.suitAsUnicodeStr();
    return out;
}

bool Card::operator==(const Card& other) const {
    return rank == other.rank && suit == other.suit;
}

bool Card::operator!=(const Card& other) const {
    return rank != other.rank || suit != other.suit;
}