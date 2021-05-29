#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//** THIS ARE THE EXRERN FUNCTION FORM THE MAIN FUNCTION //
const int SIZEEE = 20;
extern string bookTitle[SIZEEE];
extern string isbn[SIZEEE];
extern string author[SIZEEE];
extern string publisher[SIZEEE];
extern string dateAdded[SIZEEE];
extern int qtyonHand[20];
extern double wholesale[20];
extern double retail[20];
void cashier()
{
    system("cls");
    const double SALES_TAX = 0.06; // 6% percent;
                                   //** THIS VARIABLE FOR THE CASHIER FUNCTION
    string isbnNumber[SIZEEE];
    string thisTitle[SIZEEE];
    int quantityBooks[SIZEEE];
    double unitPrice[SIZEEE];
    double subTotal[SIZEEE];
    string transdate;
    double ordersalesTax = 0;
    double runningTotal = 0;
    double grandTotal = 0;
    int validQty;
    char choice = 'Y';
    int counter = 0; // THIS FOR THE NUMBER OF BOOK WE WANT TO BUY THIS LOOP WILL BE RUN FOR THAT TIME.
    string message;

    while (choice == 'Y' || choice == 'y')
    {

        cout << "Serendipity Book Sellers\n\n";
        cout << "  Cashier Module Book\n\n";
        fflush(stdin);
        cout << "Enter Date: ";
        getline(cin, transdate);
        cout << "Enter ISBN: ";
        getline(cin, isbnNumber[counter]);

        for (int index = 0; index < SIZEEE; index++)
        {
            if (isbnNumber[counter] == isbn[index])
            {
                cout << "Title: " << bookTitle[index] << endl;
                cout << fixed << showpoint << setprecision(2) << "Price:" << retail[index] << endl;

                unitPrice[counter] = retail[index];
                thisTitle[counter] = bookTitle[index];
                validQty = qtyonHand[index];

                if (validQty == 0)
                {
                    cout << "The book is out of stock!\n\n";
                    return;
                }

                cout << "Enter Quantity of Book: ";
                cin >> quantityBooks[counter];

                while (quantityBooks[counter] < 1 || quantityBooks[counter] > validQty)
                {
                    if (quantityBooks[counter] < 1)
                    {
                        cout << "\nPlease enter a Valid quantit.\n\n";
                    }
                    else
                    {
                        cout << "\nSorry , insuffcient quantity in inventory\n\n";
                    }

                    cout << "Enter the Quantity of Book: ";
                    cin >> quantityBooks[counter];
                }

                qtyonHand[index] = qtyonHand[index] - quantityBooks[counter];
                counter++;
                message = "\nAdd another title to this order? ";

                choice = anotherTransaction(message);
                cout << endl;
                break;
            }
        }
        cout << endl;
    }
    if (counter > 0)
    {

        cout << "\n\nDate: " << transdate;
        cout << "\n\n";

        cout << "Qty\tISBN\t\t\t\tTitle\t\t\t\tPrice\t\tTotal\n";
        cout << "__________________________________________________________________________________________________" << endl;
        cout << "\n";

        for (int i = 0; i < counter; i++)
        {
            subTotal[i] = (quantityBooks[i] * unitPrice[i]);
            ordersalesTax += (subTotal[i] * SALES_TAX);
            runningTotal += subTotal[i];
            grandTotal = (ordersalesTax + runningTotal);

            cout << quantityBooks[i] << "\t";
            cout << left << setw(20) << isbnNumber[i] << "\t";
            cout << left << setw(39) << thisTitle[i] << "\t";
            cout << fixed << showpoint << right << setprecision(2);
            cout << left << setw(10) << unitPrice[i] << "\t$";
            cout << left << setw(16) << subTotal[i] << "\t";
            cout << "\n\n\n\n";
        }
        cout << "\t\tSubtotal\t\t\t\t\t$";
        cout << left << setw(4) << runningTotal << "\n";
        cout << "\t\tTax\t\t\t\t\t\t$";
        cout << left << setw(4) << ordersalesTax << "\n";
        cout << "\t\tTotal\t\t\t\t\t\t$";
        cout << left << setw(4) << grandTotal << "\n\n";

        cout << "\n\nThank you for shopping at Serendipity!\n";
        cout << "\n\n Process Another Transcation (Y/N) \n";

        choice = anotherTransaction(message);
    }
    cout << endl;

    if (choice == 'Y' || choice == 'y')
    {
        cashier();
    }
    else
    {
        exit;
    }
}

char anotherTransaction(string message)
{
    char choice;
    cout << message;
    cout << "Y = Yes/y , < = No\n";
    cout << "Enter your Choice: ";
    fflush(stdin);
    cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        cout << "\nPlease enter Y for yes or N for no\n\n";
        cout << message << endl;
        cin >> choice;
        fflush(stdin);
    }
    return choice;
}