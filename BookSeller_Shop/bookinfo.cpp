#include "bookinfo.h"
#include <iostream>
#include <string>
using namespace std;

void bookinfo(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyonHand, double wholesale, double retail)
{
    system("cls");
    cout << "Serendipity Book Sellers\n";
    cout << "  Book Information\n\n";
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << bookTitle << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "Quantity-On hand: " << qtyonHand << endl;
    cout << "Wholesale Cost: " << wholesale << endl;
    cout << "Retail Price: " << retail << endl;
}