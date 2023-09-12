#include "Card.h"
using namespace std;

Card::Card(Rank rank, Suit suit) : rank{rank}, suit{suit} {}

void Card::print() const {
    cout << this;
}

string Card::rankAsStr() const {
    switch (rank) {
        case Rank::two : return "2";
        case Rank::three : return "3";
        case Rank::four : return "4";
        case Rank::five : return "5";
        case Rank::six : return "6";
        case Rank::seven : return "7";
        case Rank::eight : return "8";
        case Rank::nine : return "9";
        case Rank::ten : return "10";
        case Rank::jack : return "J";
        case Rank::queen : return "Q";
        case Rank::king : return "K";
        case Rank::ace : return "A";
    }
    return "ERROR: Invalid Rank";
}

string Card::suitAsUnicodeStr() const {
    switch (suit) {
        case Suit::clubs : return "\u2663";
        case Suit::diamonds : return "\u2662";
        case Suit::hearts : return "\u2661";
        case Suit::spades : return "\u2660";
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