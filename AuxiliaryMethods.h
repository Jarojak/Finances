#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

class AuxiliaryMethods{

public:
    static string loadLine();
    static string IntToStr(int number);
    static int StrToInt(string stringNumber);
    static char loadChar();
};

#endif // AUXILIARYMETHODS_H
