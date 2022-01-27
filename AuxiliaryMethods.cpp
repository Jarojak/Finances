#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::IntToStr(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::StrToInt(string stringNumber){
    int intNumber;
    istringstream iss(stringNumber);
    iss >> intNumber;

    return intNumber;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

double AuxiliaryMethods::StrToDouble(string stringNumber){

    double intNumber;
    istringstream iss(stringNumber);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::DoubleToStr(double doubleNumber){
    ostringstream strs;
    strs << fixed << setprecision(2) << doubleNumber;
    string stringNumber = strs.str();
    return stringNumber;
}

int AuxiliaryMethods::convertTmDateStructureToIntDateYYYYMMDDFormat(tm date_tm)
{
    string dateString = "";
    int dateInt = 0;

    dateString = convertTmDateStructureToStringDateYYYYMMDDFormat(date_tm);
    dateInt = convertStringDateYYYYMMDDFormatToIntDate(dateString);

    return dateInt;
}

string AuxiliaryMethods::convertTmDateStructureToStringDateYYYYMMDDFormat(tm date_tm)
{
    string date = "";

    if(date_tm.tm_mon < 9) date = IntToStr((date_tm.tm_year+1900)) + "-0" +  IntToStr((date_tm.tm_mon+1));
    else date = IntToStr((date_tm.tm_year+1900)) + "-" +  IntToStr((date_tm.tm_mon+1));
    if(date_tm.tm_mday < 10) date += "-0" + IntToStr((date_tm.tm_mday));
    else date += "-" + IntToStr((date_tm.tm_mday));

    return date;
}

tm AuxiliaryMethods::convertStringDateYYYYMMDDFormatToTmDateStructure(string date)
{
    tm date_tm;
    char bufferYear[4], bufferMonth[3], bufferDay[3];

    //year
    size_t length = date.copy(bufferYear,4,0);
    bufferYear[length]='\0';
    date_tm.tm_year = (atoi(bufferYear)-1900);

    //month
    length = date.copy(bufferMonth,2,5);
    bufferMonth[length]='\0';
    date_tm.tm_mon = (atoi(bufferMonth)-1);

    //day
    length = date.copy(bufferDay,2,8);
    bufferDay[length]='\0';
    date_tm.tm_mday = (atoi(bufferDay));

    return date_tm;
}

int AuxiliaryMethods::numberOfDaysInMonthFromTmDateStructure(tm date_tm){
    if ((date_tm.tm_mon+1) == 4 || (date_tm.tm_mon+1) == 6 || (date_tm.tm_mon+1) == 9 || (date_tm.tm_mon+1) == 11)
		return 30;

	else if ((date_tm.tm_mon+1) == 02)
	{
		bool leapyear = ((date_tm.tm_year+1900) % 4 == 0 && (date_tm.tm_year+1900) % 100 != 0) || ((date_tm.tm_year+1900) % 400 == 0);

		if (leapyear)
				return 29;
		else
				return 28;
	}

	else
        return 31;
}

//obliczanie ile dni ma miesiąc w celu weryfikacji daty
int AuxiliaryMethods::numberOfDaysInMonthFromStringDateYYYYMMDDFormat(string date){
    char bufferYear[4], bufferMonth[3];
    size_t length = date.copy(bufferYear,4,0);
    bufferYear[length]='\0';
    int year = (atoi(bufferYear));
    length = date.copy(bufferMonth,2,5);
    bufferMonth[length]='\0';
    int month = (atoi(bufferMonth));
    if ((month) == 4 || (month) == 6 || (month) == 9 || (month) == 11)
		return 30;

	else if ((month) == 02)
	{
		bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (leapyear)
				return 29;
		else
				return 28;
	}

	else
        return 31;
}

int AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(string date)
{
    int date_int = 0;
    char bufferYear[4], bufferMonth[3], bufferDay[3];

    //year
    size_t length = date.copy(bufferYear,4,0);
    bufferYear[length]='\0';
    date_int += (atoi(bufferYear) * 10000);

    //month
    length = date.copy(bufferMonth,2,5);
    bufferMonth[length]='\0';
    date_int += (atoi(bufferMonth) * 100);

    //day
    length = date.copy(bufferDay,2,8);
    bufferDay[length]='\0';
    date_int += atoi(bufferDay);

    return date_int;
}

string AuxiliaryMethods::convertIntDateYYYYMMDDFormatToStringDate(int date){
    string strDate = "";
    int x = date/10000;
    strDate += IntToStr(x);
    x = (date%10000)/100;
    if(x < 10) strDate += "-0" + IntToStr(x);
    else  strDate += '-' + IntToStr(x);
    x = date%100;
    if(x < 10) strDate += "-0" + IntToStr(x);
    else  strDate += '-' + IntToStr(x);
    return strDate;
}

bool AuxiliaryMethods::dateValidationStringFormatYYYYMMDD(string date)
{
    if(date.length() != 10) return 0;
    if(date[4] != '-' || date[7] != '-') return 0;
    int date_int = convertStringDateYYYYMMDDFormatToIntDate(date);
    if(date_int < 20000101 || date_int > 20991231) return 0;
    if(date_int % 1000 < 100) return 0;
    int month = (date_int % 10000) / 100;
    if(month < 1 || month > 12) return 0;
    int day = (date_int % 100);
    int days_in_month = numberOfDaysInMonthFromStringDateYYYYMMDDFormat(date);
    if(day > days_in_month || day < 1) return 0;
    return 1;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
