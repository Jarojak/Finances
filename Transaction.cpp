#include "Transaction.h"

int Transaction::getId()
{
    return id;
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getDate()
{
    return date;
}

string Transaction::getItem()
{
    return item;
}

double Transaction::getAmount()
{
    return amount;
}

void Transaction::setId(int newId)
{
    id = newId;
}

void Transaction::setUserId(int newUserId)
{
    userId = newUserId;
}

void Transaction::setDate(int newDate)
{
    date = newDate;
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(double newAmount)
{
    amount = newAmount;
}
