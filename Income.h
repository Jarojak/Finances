#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int id;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};



#endif // ADRESAT_H
