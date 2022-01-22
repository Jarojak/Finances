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
            if(!dateValidation) cout << "niepoprawny format daty! sporbuj ponownie:";
        }while(!dateValidation);

        income.setDate(AuxiliaryMethods::convertStringDateYYYYMMDDFormatToIntDate(date));
    }

    cout << "podaj kwote transakcji: ";
    string stringAmount;
    bool amountValid = false;
    do{
        stringAmount = AuxiliaryMethods::loadLine();
        amountValid = amountValidate(stringAmount);
        if(!amountValid) cout << "podano bledna kwote! sprobuj pownownie:";
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
    system("cls");
    if (!incomes.empty())
    {
        cout << "      >>> Bilans przychodow z biezacego miesiaca <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            displayTransactionData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "brak transakcji w tym miesiacu." << endl << endl;
    }
    system("pause");
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
