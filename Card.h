#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

class Card {
public:
    Card(const std::string& rank, const std::string& suit);
    void print() const;
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    
private:
    std::string rank;
    std::string suit;
};

#endif