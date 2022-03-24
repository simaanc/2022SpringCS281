/*
     CS281 – Spring 2022
     Lab1Exercise1
     Christopher Simaan
     02/19/22
     Accounting program that keeps track of a balance with a varying annual interest rate
*/

#include "Account.h"
#include <cmath>
// constructor
Account::Account() {
    balance = 0;
    rate = .05;
}
Account::Account(double startingBalance) {
    balance = startingBalance;
    rate = .05;
}
double Account::getBalance() {
    return round(balance * 100.0) / 100.0;
}
double Account::getRate() {
    return rate;
}
bool Account::deposit(double x) {
    balance += x;

    return true;
}
bool Account::withdrawl(double x) {
    balance -= x;

    return true;
}
bool Account::accrueinterest(int x) {
    for (int i = 0; i < x; i++) {
        balance = ((balance * rate) / 12) + balance;
    }
    return true;
}