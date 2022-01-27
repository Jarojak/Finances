#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
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
    bool operator< (const Transaction &other) const {
        return date < other.date;
    }
};



#endif // TRANSACTION_H
