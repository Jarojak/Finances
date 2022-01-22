#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "Markup.h"

class FileWithIncomes : public XMLFile
{
    CMarkup xml;
    int lastTransactionId;

    int getUserIdFromXML();
    int getTransactionIdFromXML();
public:
    FileWithIncomes(string filenameWithIncomes) :
        XMLFile(filenameWithIncomes)
        {};
    void addTransactionToFile(Income income);
    vector <Income> loadTransactionsOfLoggedInUserFromXMLFile(int loggedUserId);
    void setLastTransactionId(int newLastTransactionId);
    int getLastTransactionId();
};


#endif // PLIKZADRESATAMI_H
