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
//    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
//        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
//    }

}

void Finances::logoutUser()
{
    userManager.logoutUser();
    //adresatMenedzer->wyczyscDaneZWektoraUzytkownicy();
    //delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

void Finances::changePassword()
{
    userManager.changePassword();
}

int Finances::getLoggedInUserId()
{
    return userManager.getLoggedInUserId();
}

/*
void Finances::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Finances::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

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
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
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
