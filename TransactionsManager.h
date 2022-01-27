#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "Transaction.h"
#include "FileWithTransactions.h"

class TransactionsManager
{
    const int LOGGED_IN_USER_ID;
    int currentDate;
    double incomeBalance;
    double outcomeBalance;
    double accountBalance;
    vector <Transaction> incomes;
    vector <Transaction> outcomes;
    FileWithTransactions fileWithIncomes;
    FileWithTransactions fileWithOutcomes;

    Transaction getNewTransactionData();
    void displayTransactionData(Transaction transaction);
    bool amountValidate(string amount);
    double stringAmountToDouble(string amount);

public:
    TransactionsManager(string filenameWithIncomes, string filenameWithOutcomes, int loggedInUserId) :
        fileWithIncomes(filenameWithIncomes), fileWithOutcomes(filenameWithOutcomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadTransactionsOfLoggedInUserFromXMLFile(LOGGED_IN_USER_ID);
        outcomes = fileWithOutcomes.loadTransactionsOfLoggedInUserFromXMLFile(LOGGED_IN_USER_ID);

        incomeBalance = 0;
        outcomeBalance = 0;
        accountBalance = 0;
    };
    void addIncome();
    void addOutcome();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedDatesBalance();
    void deleteIncomes();
    void deleteOutcomes();
    double getIncomeBalance();
    double getOutcomeBalance();
    double getAccountBalance();
};

#endif // TRANSACTIONMANAGER_H
