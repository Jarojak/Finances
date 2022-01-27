#include "Finances.h"

using namespace std;

int main(){
    Finances finances("users.xml","incomes.xml","outcomes.xml");

    while (true)
    {
        if (finances.getLoggedInUserId() == 0)
        {
            finances.selectOptionFromMainMenu();

            switch (finances.getChoice())
            {
            case '1':
                finances.registerUser();
                break;
            case '2':
                finances.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            finances.selectOptionFromUserMenu();

            switch (finances.getChoice())
            {
            case '1':
                finances.addIncome();
                break;
            case '2':
                finances.addOutcome();
                break;
            case '3':
                finances.currentMonthBalance();
                break;
            case '4':
                finances.lastMonthBalance();
                break;
            case '5':
                finances.selectedDatesBalance();
                break;
            case '6':
                finances.changePassword();
                break;
            case '7':
                finances.logoutUser();
                break;
            }
        }
    }

    return 0;
}
