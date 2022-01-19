#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
private:
    int userId;
    string login;
    string password;
    string name;
    string surname;
public:
    int getUserId();
    void setUserId(int newUserId);
    string getLogin();
    void setLogin(string newLogin);
    string getPassword();
    void setPassword(string newPassword);
    string getName();
    void setName(string newName);
    string getSurname();
    void setSurname(string newSurname);
};

#endif // USER_H
