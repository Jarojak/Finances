#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    xml.ResetMainPos();
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User")) {}; // set position at last element;
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserId", user.getUserId());
    xml.AddElem( "Login" , user.getLogin());
    xml.AddElem( "Password" , user.getPassword());
    xml.AddElem( "Name" , user.getName());
    xml.AddElem( "Surname" , user.getSurname());
    xml.OutOfElem();

    xml.Save( getFileName().c_str() );
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists)
    {
        //cout << "file not exist, new file will be created" << endl;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    else
    {
        //cout << "file loaded" << endl;
    }

    User user;
    vector <User> users;

    xml.ResetMainPos();
    xml.FindElem( "Users" );
    xml.IntoElem();
    while ( xml.FindElem("User") ) {
        xml.IntoElem();
            xml.FindElem( "UserId" );
            user.setUserId(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "Login" );
            user.setLogin(xml.GetData());
            xml.FindElem( "Password" );
            user.setPassword(xml.GetData());
            xml.FindElem( "Name" );
            user.setName(xml.GetData());
            xml.FindElem( "Surname" );
            user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
    xml.OutOfElem();

    return users;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users){
    xml.ResetMainPos();

    xml.FindElem("Users");
    xml.RemoveElem();

    xml.AddElem("Users");
    xml.IntoElem();
    for(int i = 0; i < users.size(); i++){
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem( "UserId", users[i].getUserId());
        xml.AddElem( "Login" , users[i].getLogin());
        xml.AddElem( "Password" , users[i].getPassword());
        xml.AddElem( "Name" , users[i].getName());
        xml.AddElem( "Surname" , users[i].getSurname());
        xml.OutOfElem();
    }
    xml.OutOfElem();

    xml.Save( getFileName().c_str() );
}
