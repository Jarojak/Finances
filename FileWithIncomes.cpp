#include "filewithincomes.h"

void FileWithIncomes::addTransactionToFile(Income income)
{
    xml.ResetMainPos();
    xml.FindElem("Incomes");
    xml.IntoElem();
    while(xml.FindElem("Income")) {}; // set position at last element;
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "Id" , income.getId());
    xml.AddElem( "UserId", income.getUserId());
    xml.AddElem( "Date" , income.getDate());
    xml.AddElem( "Item" , income.getItem());
    xml.AddElem( "Amount" , AuxiliaryMethods::DoubleToStr(income.getAmount()));
    xml.OutOfElem();

    xml.Save( getFileName().c_str() );

    lastTransactionId = income.getId();
}

vector <Income> FileWithIncomes::loadTransactionsOfLoggedInUserFromXMLFile(int loggedUserId)
{
    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists)
    {
        //cout << "file not exist, new file will be created" << endl;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    else
    {
        //cout << "file loaded" << endl;
    }

    vector <Income> incomes;
    Income income;

    xml.ResetMainPos();
    xml.FindElem( "Incomes" );
    xml.IntoElem();
    while ( xml.FindElem("Income") ) {
        xml.IntoElem();
            xml.FindElem( "Id" );
            income.setId(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "UserId" );
            income.setUserId(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "Date" );
            income.setDate(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "Item" );
            income.setItem(xml.GetData());
            xml.FindElem( "Amount" );
            income.setAmount(AuxiliaryMethods::StrToDouble(xml.GetData()));
        xml.OutOfElem();

        if(income.getUserId() == loggedUserId) incomes.push_back(income);
    }
    xml.OutOfElem();

    if (fileExists){
        // after end of while loop(at top of this function) we will have last element
        lastTransactionId = income.getId();
    }
    else{
        lastTransactionId = 0;
    }

    return incomes;
}

void FileWithIncomes::setLastTransactionId(int newLastTransactionId)
{
    lastTransactionId = newLastTransactionId;
}

int FileWithIncomes::getLastTransactionId()
{
    return lastTransactionId;
}
