/*
	CS281 � Spring 2022
	Lab 3: Dictionary
	Christopher Simaan
	May 8th 2022
	Create a dictionary that saves defined words into a separate file
    Program will populate from data file on start
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

int menu();
void clearScreen();
void pauseScreen();
void altpauseScreen();

string selectedWord;

bool wordSelected = false;

int main() {
    Dictionary dict;

    int input = 0;

    string word;
    string definition;

    do {
        input = menu();
        switch (input) {
            //exit program if input = 0
            case 0:
                break;
            case 1:
                //Add Word to Dictionary
                cout << "Enter Word: ";
                cin >> word;
                cin.ignore();
                cout << "Enter Definition: ";
                getline(cin,definition, '\n');
                dict.putItem(word,definition);
                altpauseScreen();
                break;
            case 2:
                //Select Word
                cout << "Enter Word: ";
                cin >> word;

                if (dict.findItem(word)) {
                    dict.findItem(word);
                    cout << "Found Word" << endl;
                    selectedWord = word;
                    wordSelected = true;
                }
                else {
                    cout << "Could Not Find Word";
                    wordSelected = false;
                }

                pauseScreen();
                break;
            case 3:
                //Edit Word
                if (wordSelected) {
                    cout << "Now Editing: "
                         << selectedWord
                         << endl;
                    dict.deleteItem(selectedWord);

                    cout << "Enter New Name: ";

                    cin >> word;
                    cin.ignore();
                    cout << "Enter New Definition: ";
                    getline(cin,definition, '\n');

                    dict.putItem(word, definition);
                    dict.findItem(word);
                    selectedWord = word;
                }
                else {
                    cout << "No Word Selected!" << endl;
                }

                altpauseScreen();
                break;
            case 4:
                //Delete Word
                if (wordSelected) {
                    cout << "Deleted: "
                         << selectedWord
                         << endl;
                    dict.deleteItem(selectedWord);
                    selectedWord.clear();
                    wordSelected = false;
                }
                else {
                    cout << "No Word Selected!" << endl;
                }

                pauseScreen();
                break;
            case 5:
                //Display Word
                if (wordSelected) {
                    cout << "Definition: " << dict.getDefinition(selectedWord);
                }
                else {
                    cout << "No Word Selected!" << endl;
                }


                pauseScreen();
                break;
        }
        clearScreen();
    } while (input != 0);
    return 0;
}
//Create a menu
int menu() {
    int input;
    cout << "***Main Menu***" << endl
         << "1. Add Word" << endl
         << "2. Find Word" << endl
         << "3. Edit Word" << endl
         << "4. Delete Word" << endl
         << "5. Display Definition" << endl
         << "0. Quit" << endl
         << endl;
    if (wordSelected) {
        cout << "Current Word: "
             << selectedWord
             << endl;
    }
    else {
        cout << "Current Word: None" << endl;
    }
    cout << endl;
    cout << "Enter Choice: ";
    cin >> input;
    while (input < 0 or input > 5) {
        cout << "Enter a valid Choice from the menu: ";
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        cin >> input;
    }
    return input;
}

void clearScreen() {
    system("CLS");
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}
void pauseScreen() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\n---Enter to Continue!---\n";
    std::cin.get();
}

void altpauseScreen() {
    std::cin.clear();
    std::cout << "\n---Enter to Continue!---\n";
    std::cin.get();
}