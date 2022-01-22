#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;

class AuxiliaryMethods{

public:
    static string loadLine();
    static string IntToStr(int number);
    static int StrToInt(string stringNumber);
    static char loadChar();
    static double StrToDouble(string stringNumber);
    static string DoubleToStr(double doubleNumber);
    static int convertTmDateStructureToIntDateYYYYMMDDFormat(tm date_tm);
    static string convertTmDateStructureToStringDateYYYYMMDDFormat(tm date_tm);
    static tm convertStringDateYYYYMMDDFormatToTmDateStructure(string date);
    static int numberOfDaysInMonthFromTmDateStructure(tm date_tm);
    static int numberOfDaysInMonthFromStringDateYYYYMMDDFormat(string date);
    static int convertStringDateYYYYMMDDFormatToIntDate(string date);
    static string convertIntDateYYYYMMDDFormatToStringDate(int date);
    static bool dateValidationStringFormatYYYYMMDD(string date);
};

#endif // AUXILIARYMETHODS_H
