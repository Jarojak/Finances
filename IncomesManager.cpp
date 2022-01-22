#include "incomesmanager.h"

void IncomesManager::addTransaction()
{
    Income income;

    system("cls");
    cout << " >>> NOWA TRANSAKCJA <<<" << endl << endl;
    income = getNewTransactionData();

    incomes.push_back(income);
    fileWithIncomes.addTransactionToFile(income);
}

Income IncomesManager::getNewTransactionData()
{
    Income income;

    income.setId(fileWithIncomes.getLastTransactionId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);

    time_t currentTime;
    currentTime = time(NULL);
    struct tm currentTimeStruct;
    currentTimeStruct = *localtime(&currentTime);

    string dateNow = AuxiliaryMethods::convertTmDateStructureToStringDateYYYYMMDDFormat(currentTimeStruct);

    char choice;
    cout << "transakcja dotyczy dzisiejszego dnia: " << dateNow << "? (t/n): ";
    do{ choice = AuxiliaryMethods::loadChar();
        if(choice != 't' && choice != 'n') cout << "bledny wybor, jeszcze raz (t/n):";
     }
    while(choice != 't' && choice != 'n');
    if(choice == 't'){
        income.setDate(AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(dateNow));
    }
    else if(choice == 'n'){
        string date;
        bool dateValidation = false;
        cout << "wpisz date, ktorej dotyczy transakcja w formacie YYYY-MM-DD" << endl;
        do{
            date = AuxiliaryMethods::loadLine();
            dateValidation = AuxiliaryMethods::dateValidationStringFormatYYYYMMDD(date);
            if(!dateValidation) cout << "niepoprawny format daty! sprobuj ponownie" << endl;
            else income.setDate(AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(date));
        }while(!dateValidation);
    }

    cout << "podaj kwote transakcji: ";
    string stringAmount;
    bool amountValid = false;
    do{
        stringAmount = AuxiliaryMethods::loadLine();
        amountValid = amountValidate(stringAmount);
        if(!amountValid) cout << "podano bledna kwote! sprobuj pownownie:" << endl;
    }while(!amountValid);
    income.setAmount(stringAmountToDouble(stringAmount));

    cout << "podaj opis transakcji: ";
    income.setItem(AuxiliaryMethods::loadLine());

    return income;
}

void IncomesManager::deleteIncomes()
{
    incomes.clear();
}

void IncomesManager::currentMonthBalance()
{
    time_t currentTime;
    currentTime = time(NULL);
    struct tm currentTimeStruct;
    currentTimeStruct = *localtime(&currentTime);
    currentDate = AuxiliaryMethods::convertTmDateStructureToIntDateYYYYMMDDFormat(currentTimeStruct);

    system("cls");
    if (!incomes.empty())
    {
        cout << "      >>> Bilans przychodow z biezacego miesiaca <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        incomeBalance = 0;
        bool transactionExists = false;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if((currentDate/100) == (itr->getDate()/100)){
                displayTransactionData(*itr);
                incomeBalance += itr->getAmount();
                transactionExists = true;
            }
        }
        if(!transactionExists) cout << endl << "brak transakcji w tym miesiacu." << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "brak transakcji w tym miesiacu." << endl << endl;
    }
    //system("pause");
}

void IncomesManager::lastMonthBalance()
{
    time_t currentTime;
    currentTime = time(NULL);
    struct tm currentTimeStruct;
    currentTimeStruct = *localtime(&currentTime);
    currentDate = AuxiliaryMethods::convertTmDateStructureToIntDateYYYYMMDDFormat(currentTimeStruct);

    system("cls");
    if (!incomes.empty())
    {
        cout << "      >>> Bilans przychodow z poprzedniego miesiaca <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        int currentMonth = (currentDate%10000)/100;
        int currentYear = currentDate/10000;
        currentMonth--;
        if(currentMonth == 0){
            currentMonth = 12;
            currentYear--;
        }

        int incomeMonth = 0;
        int incomeYear = 0;

        incomeBalance = 0;
        bool transactionExists = false;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            incomeMonth = (itr->getDate()%10000)/100;
            incomeYear = itr->getDate()/10000;
            if(incomeMonth == currentMonth && incomeYear == currentYear){
                displayTransactionData(*itr);
                incomeBalance += itr->getAmount();
                transactionExists = true;
            }
        }
        if(!transactionExists) cout << endl << "brak transakcji z poprzedniego miesiaca." << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "brak transakcji z poprzedniego miesiaca." << endl << endl;
    }
    //system("pause");
}

void IncomesManager::selectedDatesBalance()
{
    time_t currentTime;
    currentTime = time(NULL);
    struct tm currentTimeStruct;
    currentTimeStruct = *localtime(&currentTime);
    currentDate = AuxiliaryMethods::convertTmDateStructureToIntDateYYYYMMDDFormat(currentTimeStruct);

    system("cls");
    if (!incomes.empty())
    {
        int beginDate;
        int endDate;

        string date;
        bool dateValidation = false;
        cout << "wpisz date, (od) w formacie YYYY-MM-DD" << endl;
        do{
            date = AuxiliaryMethods::loadLine();
            dateValidation = AuxiliaryMethods::dateValidationStringFormatYYYYMMDD(date);
            if(!dateValidation) cout << "niepoprawny format daty! sprobuj ponownie" << endl;
            else beginDate = AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(date);
        }while(!dateValidation);

        dateValidation = false;
        cout << "wpisz date, (do) w formacie YYYY-MM-DD" << endl;
        do{
            date = AuxiliaryMethods::loadLine();
            dateValidation = AuxiliaryMethods::dateValidationStringFormatYYYYMMDD(date);
            if(!dateValidation) cout << "niepoprawny format daty! sprobuj ponownie" << endl;
            else endDate = AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(date);
            if(endDate < beginDate){
                cout << "data (do) nie może być wcześniej niż data (od), sprobuj ponownie" << endl;
                dateValidation = false;
            }
        }while(!dateValidation);

        system("cls");
        cout << ">>> Bilans przychodow w okresie od: "
            << AuxiliaryMethods::convertIntDateYYYYMMDDFormatToStringDate(beginDate)
            << " do: "
            << AuxiliaryMethods::convertIntDateYYYYMMDDFormatToStringDate(endDate)
            << " <<<" << endl;
        cout << "----------------------------------------------------------------" << endl;

        incomeBalance = 0;
        bool transactionExists = false;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if(itr->getDate() >= beginDate && itr->getDate() <= endDate){
                displayTransactionData(*itr);
                incomeBalance += itr->getAmount();
                transactionExists = true;
            }
        }
        if(!transactionExists) cout << endl << "brak transakcji w danym okresie czasu." << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "brak transakcji w danym okresie czasu." << endl << endl;
    }
    //system("pause");
}

void IncomesManager::displayTransactionData(Income income)
{
    cout << endl;
    cout << "Data:      " << AuxiliaryMethods::convertIntDateYYYYMMDDFormatToStringDate(income.getDate()) << endl;
    cout << "Kwota:     " << fixed << setprecision(2) << income.getAmount() << endl;
    cout << "Opis:      " << income.getItem() << endl;
}

bool IncomesManager::amountValidate(string amount){
    if(amount.length() > 10) return false;
    if((amount[0]=='0' && amount[1]=='0') || amount[0] =='.' || amount[0] ==',') return false; //two zeros, dot, coma at beginning
    int dotsCnt = 0;
    for(int i=0;i<amount.length();i++){
        if(!((amount[i]>='0'&&amount[i]<='9')||amount[i]=='.'||amount[i]==',')) return false;
        if(amount[i]=='.'||amount[i]==',') {
            dotsCnt++;
            if(dotsCnt>1) return false;
            if((amount.length()-1 - i) != 2) return false; //decimal place not equal '2'
        }
    }
    if(dotsCnt==0) return false;
    return true;
}

double IncomesManager::stringAmountToDouble(string amount){
    double val = 0.00;
    double dec = 0.01;
    int cnt = 0;
    for(int i=amount.length()-1; i>=0; i--){
        if(cnt!=2){
            val = val + ((amount[i]-48)*dec);
            dec = dec * 10.0;
        }
        cnt++;
    }
    return val;
}

double IncomesManager::getIncomeBalance()
{
    return incomeBalance;
}
