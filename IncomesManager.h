#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Income.h"
#include "FileWithIncomes.h"

class IncomesManager
{
    const int LOGGED_IN_USER_ID;
    int currentDate;
    double incomeBalance;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income getNewTransactionData();
    void displayTransactionData(Income income);
    bool amountValidate(string amount);
    double stringAmountToDouble(string amount);
public:
    IncomesManager(string filenameWithIncomes, int loggedInUserId) :
        fileWithIncomes(filenameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadTransactionsOfLoggedInUserFromXMLFile(LOGGED_IN_USER_ID);
    };
    void addTransaction();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedDatesBalance();
    void deleteIncomes();
    double getIncomeBalance();
};

#endif // ADRESATMENEDZER_H
