#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

#include "UserManager.h"
#include "TransactionsManager.h"

using namespace std;

class Finances{
    UserManager userManager;
    TransactionsManager *transactionsManager;
    const string FILENAME_WITH_INCOMES;
    const string FILENAME_WITH_OUTCOMES;
    char choice;
    double balance;
public:
    Finances(string filenameWithUsers, string filenameWithIncomes, string filenameWithOutcomes) :
        userManager(filenameWithUsers),
        FILENAME_WITH_INCOMES(filenameWithIncomes),
        FILENAME_WITH_OUTCOMES(filenameWithOutcomes)
    {
        transactionsManager = NULL;
    };
    ~Finances()
    {
        delete transactionsManager;
        transactionsManager = NULL;
    };
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void logoutUser();
    void changePassword();
    int isUserLoggedIn();
    int getLoggedInUserId();
    void addIncome();
    void addOutcome();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedDatesBalance();
    void selectOptionFromMainMenu();
    void selectOptionFromUserMenu();
    char getChoice();
};

#endif // FINANCES_H
