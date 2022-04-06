/*
     CS281 – Spring 2022
     Lab1Exercise1
     Christopher Simaan
     02/19/22
     Accounting program that keeps track of a balance with a varying annual interest rate
*/

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
            //output balance in dollar amount
            cout << "$" << acct.getBalance();
            pauseScreen();
            break;
        case 2:
            //output rate in percentage
            cout << (acct.getRate() * 100) << "%";
            pauseScreen();
            break;
        case 3:
            cout << "How much would you like to deposit? ";
            
            //get deposit amount + input verification
            while (!(cin >> deposit) || deposit < 0) {
                cout << "Please enter a valid amount: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            acct.deposit(deposit);
            
            //confirm and output current balance
            cout << "Deposited: $" << deposit << endl;
            cout << "New Balance: $" << acct.getBalance() << endl;

            pauseScreen();
            break;
        case 4:
            cout << "How much would you like to withdraw? ";
            
            //get withdrawl amount + input verification
            while (!(cin >> withdrawl) || withdrawl > acct.getBalance() || withdrawl < 0) {
                if (withdrawl > acct.getBalance()) {
                    cout << "Cannot withdraw $" << withdrawl << " you only have $" << acct.getBalance() << endl;
                }
                cout << "Please enter a valid amount: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            acct.withdrawl(withdrawl);
            //confirm and output
            cout << "Withdrew: $" << withdrawl << endl;
            cout << "New Balance: $" << acct.getBalance() << endl;

            pauseScreen();
            break;
        case 5:
            cout << "How many months to accrue interest? ";
            
            //get number of months + input verification
            while (!(cin >> months) || months < 0) {
                cout << "Please enter a valid number of months: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
            acct.accrueinterest(months);
            
            //output new balance
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