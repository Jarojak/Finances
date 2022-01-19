#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager{
private:
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    int getNewUserId();
    User getNewUserData();
    bool loginExist(string login);
public:
    UserManager(string filenameWithUsers) : fileWithUsers(filenameWithUsers){
        users = fileWithUsers.loadUsersFromFile();
        loggedInUserId = 0;
    };
    void registerUser();
    void displayAllUsers();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    void loginUser();
};

#endif // USERMANAGER_H
