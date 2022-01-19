#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

#include "UserManager.h"
//#include "AdresatMenedzer.h"

using namespace std;

class Finances{
    UserManager userManager;
    //AdresatMenedzer *adresatMenedzer;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;
    char choice;
public:
    Finances(string filenameWithUsers) :
        userManager(filenameWithUsers)
      //  NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        //adresatMenedzer = NULL;
    };
    ~Finances()
    {
      //delete adresatMenedzer;
      //adresatMenedzer = NULL;
    };
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void logoutUser();
    void changePassword();
    int isUserLoggedIn();
    int getLoggedInUserId();
    //void dodajAdresata();
    //void wyswietlWszystkichAdresatow();
    //void usunAdresata();
    //void edytujAdresata();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    void selectOptionFromMainMenu();
    void selectOptionFromUserMenu();
    char getChoice();
};

#endif // FINANCES_H
