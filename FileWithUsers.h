#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XMLFile{

    CMarkup xml;
public:
    FileWithUsers(string filenameWithUsers) : XMLFile(filenameWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif // FILEWITHUSERS_H
