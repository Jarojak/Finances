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
        incomesManager = new IncomesManager(FILENAME_WITH_INCOMES,userManager.getLoggedInUserId());
    }
}

void Finances::logoutUser()
{
    userManager.logoutUser();
    incomesManager->deleteIncomes();
    delete incomesManager;
    incomesManager = NULL;
}

void Finances::changePassword()
{
    userManager.changePassword();
}

int Finances::getLoggedInUserId()
{
    return userManager.getLoggedInUserId();
}


void Finances::addTransaction()
{
    if(userManager.isUserLoggedIn())
    {
        incomesManager->addTransaction();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}


void Finances::currentMonthBalance()
{
    incomesManager->currentMonthBalance();
}
/*
void Finances::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void Finances::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}

void Finances::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}

void Finances::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}
*/

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
    cout << "2. " << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "6. " << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();
}

char Finances::getChoice()
{
    return choice;
}
