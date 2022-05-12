//
// Created by Chris Simaan on 4/8/22.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
private:
    string face;
    string suit;
    int value;
    bool ace;

public:

    Card(string f, string s, int v, bool a) {
        make(f, s, v, a);
    };

    ~Card();

    void make(string f, string s, int v, bool a) {
        f = face;
        s = suit;
        v = value;
        a = ace;
    }

    string getFace() {return face;}
    string getSuit() {return suit;}
    int getValue() {return value;}
    bool isAce() {return ace;}
};

class Deck {
private:
    vector<Card> card;

public:
    Deck();

    ~Deck();

    void generateDeck();

    void shuffle();

    void push(Card);

    void pop();

    void top();

    bool isEmpty();

};