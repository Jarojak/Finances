#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "Markup.h"

class FileWithTransactions : public XMLFile
{
    CMarkup xml;
    int lastTransactionId;

    int getUserIdFromXML();
    int getTransactionIdFromXML();
public:
    FileWithTransactions(string filenameWithTransactions) :
        XMLFile(filenameWithTransactions)
        {};
    void addTransactionToFile(Transaction transaction);
    vector <Transaction> loadTransactionsOfLoggedInUserFromXMLFile(int loggedUserId);
    void setLastTransactionId(int newLastTransactionId);
    int getLastTransactionId();
};


#endif // FILEWITHTRANSACTIONS_H
