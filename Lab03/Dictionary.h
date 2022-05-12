//
// Created by Chris Simaan on 5/6/22.
//

#ifndef LAB03_DICTIONARY_H
#define LAB03_DICTIONARY_H

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Node {
public:
    string word;
    string def;
    Node* right, * left;

    Node(string w, string d) {
        word = w;
        def = d;
        right = nullptr;

        left = nullptr;
    }
};

class Dictionary {
private:
    Node* Root;
    Node* current;
    fstream dictData;

    void put(Node*,string, string);
    void empty(Node*);
    void orderPrint(Node*);
    void deleteNode(Node*);
    Node* findParent(Node*);
    Node* rightMostLeft(Node*);

    void saveToFile(Node*);
    void save();
public:
    Dictionary();
    ~Dictionary();

    void populateFromFile();
    void putItem(string, string);
    bool deleteItem(string);
    bool findItem(string);
    bool isEmpty();
    void makeEmpty();
    void printOrderedList();
    string getCurrent();

    void saveFile();
    string getDefinition(string);
};


#endif //LAB03_DICTIONARY_H
