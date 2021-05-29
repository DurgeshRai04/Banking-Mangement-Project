#include "reports.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZ = 20;
extern string bookTitle[SIZ];
extern string isbn[SIZ];
extern string author[SIZ];
extern string publisher[SIZ];
extern string dateAdded[SIZ];
extern int qtyonHand[20];
extern double wholesale[20];
extern double retail[20];

void reports()
{
    int option = 0;
    system("cls");
    cout << "Serendipity Book Sellers\n";
    cout << "       Reports   \n\n";

    do
    {
        cout << "1. Inventory Listing: " << endl;
        cout << "2. Inventory Wholesale Value: " << endl;
        cout << "3. Inventory Retail Value: " << endl;
        cout << "4. Listing by Quantity: " << endl;
        cout << "5. Listing by Cost: " << endl;
        cout << "6. Listing by Age: " << endl;
        cout << "7. Return to Main Menu: \n\n";
        cin >> option;

        while (option < 1 || option > 7)
        {
            system("cls");
            cout << "You have entered a wrong Input\n";
            cout << "Please choose correct option\n\n";
            cout << "1. Inventory Listing: " << endl;
            cout << "2. Inventory Wholesale Value: " << endl;
            cout << "3. Inventory Retail Value: " << endl;
            cout << "4. Listing by Quantity: " << endl;
            cout << "5. Listing by Cost: " << endl;
            cout << "6. Listing by Age: " << endl;
            cout << "7. Return to Main Menu: \n\n";
            cin >> option;
        }

        switch (option)
        {
        case 1:
            system("cls");
            replisting();
            break;
        case 2:
            system("cls");

            repWholesale();
            break;
        case 3:
            system("cls");

            repRetail();
            break;
        case 4:
            system("cls");

            repQty();
            break;
        case 5:
            system("cls");

            repcost();
            break;
        case 6:
            system("cls");

            repage();
            break;
        case 7:
            system("cls");

            cout << "Successfully Return to the Main-menu \n";

            break;
        }
    } while (option != 7);
}

void replisting()
{

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);

    cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
    cout << "Date: \t\t" << date;

    for (int i = 0; i < SIZ; i++)
    {
        if (isbn[i] != "")
        {
            cout << "\n______________________________________________________________________";
            cout << "\n\nTitle:        \t\t\t" << bookTitle[i];
            cout << "\nISBN:           \t\t\t" << isbn[i];
            cout << "\nAuthor:         \t\t\t" << author[i];
            cout << "\nPublisher:      \t\t\t" << publisher[i];
            cout << "\nDate Added:     \t\t\t" << dateAdded[i];
            cout << fixed << showpoint << left << setprecision(2);
            cout << "\nQuantity on Hand:\t\t\t" << qtyonHand[i];
            cout << "\nWholesale Cost:  \t\t\t" << wholesale[i];
            cout << "\nRetail Price:    \t\t\t" << retail[i];
        }
    }

    cout << "\n\n___________________________________________________________________________";
    cout << "\n\nEnd of Inventory Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}

void repWholesale()
{

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
    cout << "Date: \t\t" << date;

    double itemsubtotal = 0;
    double subtotal = 0;

    for (int i = 0; i < SIZ; i++)
    {
        if (isbn[i] != "")
        {
            cout << "\n\t" << fixed << setw(26) << bookTitle[i];
            cout << left << setw(14) << isbn[i];
            cout << right << setw(6) << qtyonHand[i] << "\t";
            cout << fixed << showpoint << right << setprecision(2);
            cout << setw(6) << "\t$ " << wholesale[i];
            itemsubtotal = qtyonHand[i] * wholesale[i];

            subtotal += itemsubtotal;
        }
    }

    cout << "\n\n\n\tTotal Wholesale Value: $ " << subtotal << endl;
    cout << "\t_____________________________________________________________\n";
    cout << "\n\tEnd of Wholesale Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}
void repRetail()
{

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
    cout << "Date: \t\t" << date;

    double itemsubtotal = 0;
    double subtotal = 0;

    for (int i = 0; i < SIZ; i++)
    {
        if (isbn[i] != "")
        {
            cout << "\n\t" << fixed << setw(26) << bookTitle[i];
            cout << left << setw(14) << isbn[i];
            cout << right << setw(6) << qtyonHand[i] << "\t";
            cout << fixed << showpoint << right << setprecision(2);
            cout << setw(6) << "\t$ " << retail[i];

            itemsubtotal = qtyonHand[i] * retail[i];
            subtotal += itemsubtotal;
        }
    }

    cout << "\n\n\n\tTotal Retail Value: $ " << subtotal << endl;
    cout << "\t_____________________________________________________________\n";
    cout << "\n\tEnd of Retail Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}
void repQty()
{

    int id[SIZ];      // array to track original subscripts
    int *idptr[SIZ];  // pointer to tracking array
    int *qtyptr[SIZ]; // array of ppointer to qtyonhand Array

    for (int i = 0; i < SIZ; i++)
    {
        id[i] = i;
        idptr[i] = &id[i];
        qtyptr[i] = &qtyonHand[i];
    }

    int startscan;
    int maxindex;
    int *tempId;
    int *maxvalue;

    // SELECTION SORT

    for (startscan = 0; startscan < SIZ - 1; startscan++)
    {
        maxindex = startscan;
        maxvalue = qtyptr[startscan];
        tempId = idptr[startscan];

        for (int index = startscan + 1; index < SIZ; index++)
        {
            if (*(qtyptr[index]) > *maxvalue)
            {
                maxvalue = qtyptr[index];
                tempId = idptr[index];
                maxindex = index;
            }
        }

        qtyptr[maxindex] = qtyptr[startscan];
        idptr[maxindex] = idptr[startscan];
        qtyptr[startscan] = maxvalue;
        idptr[startscan] = tempId;
    }

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);
    cout << endl;
    cout << "\n\n\t\tSerendipity Booksellers Quantity Report\n";
    cout << "Date: \t\t" << date;

    cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
    cout << "\t__________________________________________________\n\n";

    for (int j = 0; j < SIZ; j++)
    {
        if (isbn[*(idptr[j])] != "")
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idptr[j])];
            cout << left << setw(14) << isbn[*(idptr[j])];
            cout << right << setw(6) << *qtyptr[j] << "\n";
        }
    }

    cout << "\t_____________________________________________________________\n";
    cout << "\n\tEnd of Quantity Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}
void repcost()
{
    int id[SIZ];           // array to track original subscripts
    int *idptr[SIZ];       // pointer to tracking array
    double *wholePtr[SIZ]; // array of ppointer to qtyonhand Array

    for (int i = 0; i < SIZ; i++)
    {
        id[i] = i;
        idptr[i] = &id[i];
        wholePtr[i] = &wholesale[i];
    }

    int startscan;

    int maxindex;
    int *tempId;
    double *maxvalue;

    // SELECTION SORT

    for (startscan = 0; startscan < SIZ - 1; startscan++)
    {
        maxindex = startscan;
        maxvalue = wholePtr[startscan];
        tempId = idptr[startscan];

        for (int index = startscan + 1; index < SIZ; index++)
        {
            if (*(wholePtr[index]) > *maxvalue)
            {
                maxvalue = wholePtr[index];
                tempId = idptr[index];
                maxindex = index;
            }
        }

        wholePtr[maxindex] = wholePtr[startscan];
        idptr[maxindex] = idptr[startscan];
        wholePtr[startscan] = maxvalue;
        idptr[startscan] = tempId;
    }

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);
    cout << endl;
    cout << "\n\n\t\tSerendipity Booksellers Cost Report\n";
    cout << "Date: \t\t" << date;

    cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
    cout << "\t____________________________________________________________________\n\n";

    for (int j = 0; j < SIZ; j++)
    {
        if (isbn[*(idptr[j])] != "")
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idptr[j])];
            cout << left << setw(14) << isbn[*(idptr[j])];
            cout << fixed << showpoint << right << setprecision(2);
            cout << right << setw(6) << qtyonHand[j];
            cout << setw(6) << "\t$ " << *wholePtr[j] << "\n";
        }
    }

    cout << "\t_____________________________________________________________\n";
    cout << "\n\tEnd of Cost Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}
void repage()
{

    int id[SIZ];          // array to track original subscripts
    int *idptr[SIZ];      // pointer to tracking array
    string *datePtr[SIZ]; // array of ppointer to qtyonhand Array

    for (int i = 0; i < SIZ; i++)
    {
        id[i] = i;
        idptr[i] = &id[i];
        datePtr[i] = &dateAdded[i];
    }

    int startscan;
    int maxindex;
    int *tempId;
    string *maxvalue;

    // SELECTION SORT

    for (startscan = 0; startscan < SIZ - 1; startscan++)
    {
        maxindex = startscan;
        maxvalue = datePtr[startscan];
        tempId = idptr[startscan];

        for (int index = startscan + 1; index < SIZ; index++)
        {
            if (*(datePtr[index]) > *maxvalue)
            {
                maxvalue = datePtr[index];
                tempId = idptr[index];
                maxindex = index;
            }
        }

        datePtr[maxindex] = datePtr[startscan];
        idptr[maxindex] = idptr[startscan];
        datePtr[startscan] = maxvalue;
        idptr[startscan] = tempId;
    }

    string date;
    cout << "\n\nEnter Today's Date" << endl;
    fflush(stdin);
    getline(cin, date);
    cout << endl;
    cout << "\n\n\t\tSerendipity Booksellers Cost Report\n";
    cout << "Date: \t\t" << date;
    cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDateAdded\n";
    cout << "\t_____________________________________________________________________\n\n";

    for (int j = 0; j < SIZ; j++)
    {
        if (isbn[*(idptr[j])] != "")
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idptr[j])];
            cout << left << setw(14) << isbn[*(idptr[j])];
            cout << fixed << showpoint << right << setprecision(2);
            cout << right << setw(6) << qtyonHand[j];
            cout << setw(6) << "\t " << dateAdded[*(idptr[j])] << "\n";
        }
    }

    cout << "\t_____________________________________________________________\n";
    cout << "\n\tEnd of Age Report\n\n\n";

    cout << "Press Enter to continue";
    fflush(stdin);
    cin.get();
}
