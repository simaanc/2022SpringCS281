/*
     CS281 – Spring 2022
     Lab1Exercise1
     Christopher Simaan
     02/19/22
     Accounting program that keeps track of a balance with a varying annual interest rate
*/

#pragma once
class Account {
private:
    double balance;
    double rate;

public:
    Account();
    Account(double); //enter balance
    double getBalance(); //get balance
    double getRate(); //get rate
    bool deposit(double); //deposit amount
    bool withdrawl(double); //withdraw amount
    bool accrueinterest(int); //calculate accrued interest
};