#include "filewithtransactions.h"

void FileWithTransactions::addTransactionToFile(Transaction transaction)
{
    string filename = getFileName();
    string parentName = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(filename.substr(0,filename.length()-4));
    string childrenName = parentName.substr(0,parentName.length()-1);

    xml.ResetMainPos();
    xml.FindElem(parentName.c_str());
    xml.IntoElem();
    while(xml.FindElem(childrenName.c_str())) {}; // set position at last element;
    xml.AddElem(childrenName.c_str());
    xml.IntoElem();
    xml.AddElem( "Id" , transaction.getId());
    xml.AddElem( "UserId", transaction.getUserId());
    xml.AddElem( "Date" , transaction.getDate());
    xml.AddElem( "Item" , transaction.getItem());
    xml.AddElem( "Amount" , AuxiliaryMethods::DoubleToStr(transaction.getAmount()));
    xml.OutOfElem();

    xml.Save( filename.c_str() );

    lastTransactionId = transaction.getId();
}

vector <Transaction> FileWithTransactions::loadTransactionsOfLoggedInUserFromXMLFile(int loggedUserId)
{
    string filename = getFileName();
    string parentName = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(filename.substr(0,filename.length()-4));
    string childrenName = parentName.substr(0,parentName.length()-1);

    bool fileExists = xml.Load( filename.c_str() );

    if (!fileExists)
    {
        //cout << "file not exist, new file will be created" << endl;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( parentName.c_str() );
    }
    else
    {
        //cout << "file loaded" << endl;
    }

    vector <Transaction> transactions;
    Transaction transaction;

    xml.ResetMainPos();
    xml.FindElem( parentName.c_str() );
    xml.IntoElem();
    while ( xml.FindElem( childrenName.c_str() ) ) {
        xml.IntoElem();
            xml.FindElem( "Id" );
            transaction.setId(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "UserId" );
            transaction.setUserId(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "Date" );
            transaction.setDate(AuxiliaryMethods::StrToInt(xml.GetData()));
            xml.FindElem( "Item" );
            transaction.setItem(xml.GetData());
            xml.FindElem( "Amount" );
            transaction.setAmount(AuxiliaryMethods::StrToDouble(xml.GetData()));
        xml.OutOfElem();

        if(transaction.getUserId() == loggedUserId) transactions.push_back(transaction);
    }
    xml.OutOfElem();

    if (fileExists){
        // after end of while loop(at top of this function) we will have last element
        lastTransactionId = transaction.getId();
    }
    else{
        lastTransactionId = 0;
    }

    return transactions;
}

void FileWithTransactions::setLastTransactionId(int newLastTransactionId)
{
    lastTransactionId = newLastTransactionId;
}

int FileWithTransactions::getLastTransactionId()
{
    return lastTransactionId;
}
