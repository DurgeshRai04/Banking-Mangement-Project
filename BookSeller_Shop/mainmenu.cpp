#include <iostream>
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookinfo.cpp"
#include "cashier.cpp"
#include "invmenu.cpp"
#include "reports.cpp"
using namespace std;
const int SIZEE = 20;
string bookTitle[SIZEE];
string isbn[SIZEE];
string author[SIZEE];
string publisher[SIZEE];
string dateAdded[SIZEE];
int qtyonHand[20];
double wholesale[20];
double retail[20];
int main()
{
    system("cls");
    cout << "Serendipity Booksellers\n";
    cout << "\t MAIN MENU\n\n\n";

    int option = 0;

    do
    {
        cout << "1. Cashier Module" << endl;
        cout << "2. Inventory Database Module" << endl;
        cout << "3. Report Module" << endl;
        cout << "4. Exit\n\n";

        cin >> option;

        while (option < 1 || option > 4)
        {
            system("cls");
            cout << "You have entered a wrong Input\n";
            cout << "Please choose correct option\n\n";
            cout << "1. Cashier Module" << endl;
            cout << "2. Inventory Database Module" << endl;
            cout << "3. Report Module" << endl;
            cout << "4. Exit" << endl;
            cin >> option;
        }

        switch (option)
        {
        case 1:
            system("cls");
            cashier();
            cout << "\n\n";
            break;
        case 2:
            system("cls");
            invmenu();
            cout << "\n\n";
            break;
        case 3:
            system("cls");
            reports();
            cout << "\n\n";
            break;
        case 4:
            system("cls");
            cout << "Successfully Exited \n";
            break;
        }
    } while (option != 4);

    return 0;
}