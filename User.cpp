#include "User.h"

int User::getUserId(){
	return userId;
}
void User::setUserId(int newUserId){
	if(newUserId >= 0)
    userId = newUserId;
}
string User::getLogin(){
	return login;
}
void User::setLogin(string newLogin){
	login = newLogin;
}
string User::getPassword(){
	return password;
}
void User::setPassword(string newPassword){
	password = newPassword;
}
string User::getName(){
	return name;
}
void User::setName(string newName){
	name = newName;
}
string User::getSurname(){
	return surname;
}
void User::setSurname(string newSurname){
	surname = newSurname;
}
