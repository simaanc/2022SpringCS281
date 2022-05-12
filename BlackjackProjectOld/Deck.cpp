//
// Created by Chris Simaan on 4/8/22.
//

#include "Deck.h"

Deck::Deck() {
}

void Deck::generateDeck() {
    Card card [52];

    for (int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            if (i==0)
                card.suit = "Hearts";
            if (i==1)
                card.suit = "Diamonds";
            if (i==2)
                card.suit = "Clubs";
            if (i==3)
                card.suit = "Spades";
            if (j==0) {

            }
        }
    }
}


