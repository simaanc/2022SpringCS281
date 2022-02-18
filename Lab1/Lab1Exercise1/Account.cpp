#include "Account.h"
// constructor
Account::Account()
{
    balance = 0;
    rate = .05;
}
Account::Account(double startingBalance)
{
    balance = startingBalance;
    rate = .05;
}
double Account::getBalance()
{
    return balance;
}
double Account::getRate() 
{
    return rate;
}
bool Account::deposit(double x) {
    balance = balance + x;
    return balance;

}