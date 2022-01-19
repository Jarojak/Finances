#include "UserManager.h"

void UserManager::registerUser(){
    User user = getNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData(){
    User user;

    user.setUserId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (loginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    cout << "Podaj Imie: ";
    user.setName(AuxiliaryMethods::loadLine());

    cout << "Podaj Nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExist(string login){
    for(int i = 0; i < users.size(); i++){
        if(users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers(){
    for(int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << "=========================================" << endl;
    }
}

void UserManager::changePassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedInUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

bool UserManager::isUserLoggedIn(){
    if (loggedInUserId > 0)
        return 1;
    else
        return 0;
}

int UserManager::getLoggedInUserId(){
    return loggedInUserId;
}

void UserManager::logoutUser(){
    cout << "Zostales wylogowany." << endl << endl;
    system("pause");
    loggedInUserId = 0;
}

void UserManager::loginUser()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int trysQuantity = 3; trysQuantity > 0; trysQuantity--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << trysQuantity << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            loggedInUserId = 0;
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedInUserId = 0;
    return;
}
