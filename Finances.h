#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

#include "UserManager.h"
#include "IncomesManager.h"

using namespace std;

class Finances{
    UserManager userManager;
    IncomesManager *incomesManager;
    const string FILENAME_WITH_INCOMES;
    char choice;
public:
    Finances(string filenameWithUsers, string filenameWithIncomes) :
        userManager(filenameWithUsers),
        FILENAME_WITH_INCOMES(filenameWithIncomes)
    {
        incomesManager = NULL;
    };
    ~Finances()
    {
        delete incomesManager;
        incomesManager = NULL;
    };
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void logoutUser();
    void changePassword();
    int isUserLoggedIn();
    int getLoggedInUserId();
    void addTransaction();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedDatesBalance();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    void selectOptionFromMainMenu();
    void selectOptionFromUserMenu();
    char getChoice();
};

#endif // FINANCES_H
