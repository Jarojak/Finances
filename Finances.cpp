#include "Finances.h"

void Finances::registerUser()
{
    userManager.registerUser();
}

void Finances::displayAllUsers()
{
    userManager.displayAllUsers();
}

void Finances::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn()){
        transactionsManager = new TransactionsManager(FILENAME_WITH_INCOMES,FILENAME_WITH_OUTCOMES,userManager.getLoggedInUserId());
    }
}

void Finances::logoutUser()
{
    userManager.logoutUser();
    transactionsManager->deleteIncomes();
    transactionsManager->deleteOutcomes();
    delete transactionsManager;
    transactionsManager = NULL;
}

void Finances::changePassword()
{
    userManager.changePassword();
}

int Finances::getLoggedInUserId()
{
    return userManager.getLoggedInUserId();
}

void Finances::addIncome()
{
    if(userManager.isUserLoggedIn())
    {
        transactionsManager->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Finances::addOutcome()
{
    if(userManager.isUserLoggedIn())
    {
        transactionsManager->addOutcome();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Finances::currentMonthBalance()
{
    transactionsManager->currentMonthBalance();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans przychodow w biezacym miesiacu: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << transactionsManager->getIncomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans wydatkow w biezacym miesiacu: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout << transactionsManager->getOutcomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans w tym miesiacu: ";
    if(transactionsManager->getAccountBalance() >= 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    }
    cout << transactionsManager->getAccountBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("pause");
}

void Finances::lastMonthBalance()
{
    transactionsManager->lastMonthBalance();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans przychodow w poprzednim miesiacu: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << transactionsManager->getIncomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans wydatkow w poprzednim miesiacu: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout << transactionsManager->getOutcomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans w tym miesiacu: ";
    if(transactionsManager->getAccountBalance() >= 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    }
    cout << transactionsManager->getAccountBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("pause");
}

void Finances::selectedDatesBalance()
{
    transactionsManager->selectedDatesBalance();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans przychodow w wybranym okresie: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << transactionsManager->getIncomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans wydatkow w wybranym okresie: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout << transactionsManager->getOutcomeBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "Bilans w tym miesiacu: ";
    if(transactionsManager->getAccountBalance() >= 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    }
    cout << transactionsManager->getAccountBalance() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("pause");
}

void Finances::selectOptionFromMainMenu()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();
}

void Finances::selectOptionFromUserMenu()
{
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();
}

char Finances::getChoice()
{
    return choice;
}
