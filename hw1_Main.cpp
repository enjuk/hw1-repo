#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    const Deck originalDeck;
    cout << "Original Deck Layout:\n\n";
    originalDeck.print();
    
    Deck shuffledDeck;
    shuffledDeck.performPerfectShuffle();
    cout << "\n\n\nAfter Performing 1 Perfect Shuffle:\n\n";
    shuffledDeck.print();
    int shuffleCount = 1;

    while (shuffledDeck != originalDeck) {
        shuffledDeck.performPerfectShuffle();
        shuffleCount++;
    }

    cout << "\n\n\nIt took " << shuffleCount << " perfect shuffles to get "
         << "to the original configuration.\n\n";

    cout << "Final Shuffled Deck Configuration:\n\n";
    shuffledDeck.print();
    
    return 0;
}