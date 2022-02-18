// Lab1Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Account.h"
#include <iostream>


using namespace std;

int menu();
void clearScreen();
void pauseScreen();

int main() {
    int input = 0;
    double deposit = 0;
    double withdrawl = 0;
    int months = 0;
    Account acct(100.00); // create instance of account
    do {
        input = menu();
        switch (input) {
        case 1:
            cout << acct.getBalance();
            pauseScreen();
            break;
        case 2:
            cout << acct.getRate();
            pauseScreen();
            break;
        case 3:
            cout << "How much would you like to deposit? " << endl;
            cin >> deposit;
            acct.deposit(deposit);
            cout << "Deposited: $" << deposit << endl;
            cout << "Balance: $" << acct.getBalance() << endl;
            pauseScreen();
            break;
        case 4:
            cout << "How much would you like to withdrawl? " << endl;
            cin >> withdrawl;
            if (withdrawl <= acct.getBalance()) {
                acct.withdrawl(withdrawl);
                cout << "Withdrew: $" << withdrawl << endl;
                cout << "Balance: $" << acct.getBalance() << endl;
            } else {
                cout << "Cannot withdraw $" << withdrawl << " you only have $" << acct.getBalance() << endl;
            }
            pauseScreen();
            break;
        case 5:
            cout << "How many months to accrue interest?" << endl;
            cin >> months;
            acct.accrueinterest(months);
            cout << "Balance With Accrued Interest: $" << acct.getBalance() << endl;
            pauseScreen();
            break;
        case 6:
            cout << "Goodbye";
            pauseScreen();
        }
        clearScreen();
    } while (input != 6);
}
int menu() {
    int input;
    cout << "Enter the number for the eoperation you wish to perform from the menu." << endl
        << "1. Check Balance" << endl
        << "2. Check Current Rate" << endl
        << "3. Deposit to Account" << endl
        << "4. Withdraw from Account" << endl
        << "5. Accrue Interest" << endl
        << "6. Exit program" << endl
        << endl;
    cout << "Enter Choice: ";
    cin >> input;
    while (input < 1 or input > 6) {
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