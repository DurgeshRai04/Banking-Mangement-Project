#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;
const int SIZE = 20;
extern string bookTitle[SIZE];
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyonHand[20];
extern double wholesale[20];
extern double retail[20];

void invmenu()
{
    bookTitle[0] = "c++";
    isbn[0] = "isbn1";
    author[0] = "C.V.Raman";
    publisher[0] = "Bkp";
    dateAdded[0] = "2-02-2020";
    qtyonHand[0] = 6;
    wholesale[0] = 8;
    retail[0] = 9;
    bookTitle[1] = "c";
    isbn[1] = "isbn2";
    author[1] = "K.V.Raman";
    publisher[1] = "bkp";
    dateAdded[1] = "2-02-2019";
    qtyonHand[1] = 10;
    wholesale[1] = 5;
    retail[1] = 10;

    system("cls");
    cout << "Serendipity Booksellers\n";
    cout << "  Inventory Database\n\n\n";

    int option = 0;

    do
    {
        cout << "1. Look Up a Book\n";
        cout << "2. Add a Book\n";
        cout << "3. Edit a Book's Record\n";
        cout << "4. Delete a Book\n";
        cout << "5. Return to the Main Menu\n\n";

        cin >> option;

        while (option < 1 || option > 5)
        {
            system("cls");
            cout << "You have entered a wrong Input\n";
            cout << "Please choose correct option\n\n";
            cout << "1. Look Up a Book\n";
            cout << "2. Add a Book\n";
            cout << "3. Edit a Book's Record\n";
            cout << "4. Delete a Book\n";
            cout << "5. Return to the Main Menu\n\n";
            cin >> option;
        }

        switch (option)
        {
        case 1:
            system("cls");
            lookUpBook();
            cout << endl;
            getch();
            break;
        case 2:
            system("cls");

            addBook();
            cout << "\nSuccessFully Added the record of book in Database: \n"
                 << endl;
            break;
        case 3:
            system("cls");

            editBook();
            break;
        case 4:
            system("cls");

            deleteBook();
            break;
        case 5:
            system("cls");

            cout << "Successfully Return to the Main-menu \n";
            break;
        }
    } while (option != 5);
}

// This function help us to look for the book in the record.
void lookUpBook()

{
    bool found = false;
    int index = 0;
    string searchTitle;
    fflush(stdin);
    cout << "Enter the Title of the book : " << endl;
    getline(cin, searchTitle);

    while (!found && index < SIZE)
    {
        if (bookTitle[index] == searchTitle)
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    if (found)
    {
        bookinfo(bookTitle[index], isbn[index], author[index], publisher[index],
                 dateAdded[index], qtyonHand[index], wholesale[index], retail[index]);
    }
    else
    {
        cout << "No Such record found! " << endl;
    }
}
void addBook()

{
    bool found = false;
    int index = 0;
    while (!found && index < SIZE)
    {
        if (bookTitle[index] == "")
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    if (found)
    {
        cout << "Enter the Title : ";
        fflush(stdin);
        getline(cin, bookTitle[index]);

        cout << "Enter the ISBN : ";
        fflush(stdin);
        getline(cin, isbn[index]);

        cout << "Enter the Author name : ";
        fflush(stdin);
        getline(cin, author[index]);

        cout << "Enter the Publisher : ";
        fflush(stdin);
        getline(cin, publisher[index]);

        cout << "Enter the Date to add in the inventory : ";
        fflush(stdin);
        getline(cin, dateAdded[index]);

        cout << "Enter the Qty to add in the inventory : ";
        fflush(stdin);

        cin >> qtyonHand[index];

        cout << "Enter the Wholesale price to add in the inventory : ";
        fflush(stdin);
        cin >> wholesale[index];

        cout << "Enter the Retail Price to add in the inventory : ";
        fflush(stdin);
        cin >> retail[index];
    }
    else
    {

        cout << "No more record can be added! " << endl;
    }
}
void editBook()

{
    int option;
    bool found = false;
    int index = 0;
    string sreachtilee;
    fflush(stdin);
    cout << "Enter the Title of the book: \n";
    getline(cin, sreachtilee);

    while (!found && index < SIZE) // WE HAVE TO CHECK BOTH THAT ONLY NOT FOUND PLUS THE INDEXING IS ALSO IMPORTANT
    {
        if (bookTitle[index] == sreachtilee)
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    if (found)
    {
        // HERE I HAVE CALLED THE BOOK INFO FUCNTION TO SELL THE BOOK DATA
        bookinfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyonHand[index], wholesale[index], retail[index]);
        do
        {
            cout << "Enter the otpion u want to edit" << endl;
            cout << "1. ISBN: " << endl;
            cout << "2. Title: " << endl;
            cout << "3. Author: " << endl;
            cout << "4. Publisher: " << endl;
            cout << "5. Date Added: " << endl;
            cout << "6. Quantity-On hand: " << endl;
            cout << "7. Wholesale Cost: " << endl;
            cout << "8. Retail Price: " << endl;
            cout << "9. EXIT " << endl;
            fflush(stdin);
            cin >> option;
            while (option < 1 || option > 9)
            {
                cout << "\nPlease enter a number in the range between 1 and 9." << endl;
                cout << "Enter your choice :";
                cin >> option;
            }

            switch (option)
            {
            case 1:
                cout << "Currenlty the ISBN : " << isbn[index];
                cout << endl;
                cout << "Enter the new isbn:  ";
                fflush(stdin);
                getline(cin, isbn[index]);

                break;
            case 2:
                cout << "Currenlty the Title : " << bookTitle[index] << endl;
                cout << "Enter the new Title:  ";
                fflush(stdin);
                getline(cin, bookTitle[index]);
                break;
            case 3:
                cout << "Currenlty the Author : " << author[index];
                cout << endl;
                cout << "Enter the new Author:  ";
                fflush(stdin);
                getline(cin, author[index]);
                break;
            case 4:
                cout << "Currenlty the Publisher : " << publisher[index];
                cout << endl;
                cout << "Enter the new Publisher:  ";
                fflush(stdin);
                getline(cin, publisher[index]);
                break;
            case 5:
                cout << "Currenlty the Date Added : " << dateAdded[index];
                cout << endl;
                cout << "Enter the new Date to add :  ";
                fflush(stdin);
                getline(cin, dateAdded[index]);
                break;
            case 6:
                cout << "Currenlty the Quantity-On hand : " << qtyonHand[index];
                cout << endl;
                cout << "Enter the new Quantity-On hand :  ";
                fflush(stdin);

                cin >> qtyonHand[index];
                break;
            case 7:
                cout << "Currenlty the Wholesale Cost : " << wholesale[index];
                cout << endl;
                cout << "Enter the new Wholesale Cost :  ";
                fflush(stdin);
                cin >> wholesale[index];
                break;
            case 8:
                cout << "Currenlty the Retail Price: " << retail[index];
                cout << endl;
                cout << "Enter the new Retail Price: :  ";
                fflush(stdin);
                cin >> retail[index];
                break;
            case 9:
                system("cls");
                break;
            }
        } while (option != 9);
    }
    else
    {
        cout << "\nNo Such record found! " << endl;
    }
}

void deleteBook()

{
    bool found = false;
    int index = 0;
    char confirm;
    string sreachtilee;
    fflush(stdin);
    cout << "Enter the Title of the book: \n";
    getline(cin, sreachtilee);

    while (!found && index < SIZE)
    {
        if (bookTitle[index] == sreachtilee)
        {
            found = true;
        }
        else
        {
            index++;
        }
    }
    if (found)
    {
        bookinfo(isbn[index], bookTitle[index], author[index], publisher[index],
                 dateAdded[index], qtyonHand[index], wholesale[index], retail[index]);
        cout << "Are you sure you want to delete this book. Press (Y/N) ? " << endl;
        cin >> confirm;

        system("cls");
        cout << "Successfully deleted last record!" << endl;

        if (confirm == 'Y' || confirm == 'y')
        {
            bookTitle[index] = " ";
            isbn[index] = " ";
            author[index] = " ";
            publisher[index] = " ";
            dateAdded[index] = " ";
            qtyonHand[index] = 0;
            wholesale[index] = 0;
            retail[index] = 0;
        }
    }
    else
        cout << "\nNo Such record found! \n";
}