#pragma once
class Account
{
private:
    double balance;
    double rate;

public:
    Account();
    Account(double); // enter balance
    double getBalance();
    double getRate();
    bool deposit(double);
    bool withdrawl(double);
    bool accrueinterest(int);
};