#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class Account
{
private:
    // Personal Deatils Of Account holder
    long accnumber;
    string fname;
    string lname;
    float balance;
    static long NextAccountNumber; // Static function to provide account number to the people.

public:
    Account() {}                            // Default Constructors
    Account(string, string, float);         // Parameterized Constructor
    long getAccno() { return accnumber; }   // Accessors Acc number
    string getfirstName() { return fname; } // Accessors First Name
    string getLastName() { return lname; }  // Accessors Second Name
    float getBalance() { return balance; }  // Accessors Balance
    void deposit(float ammount);            // Function For depositing the money in the account.
    void withdraw(float ammount);           // Function For Withdraw money from the Bank Acc.
    friend ostream &operator<<(ostream &os, Account &acc);
    friend ofstream &operator<<(ofstream &ofs, Account &acc);
    friend ifstream &operator>>(ifstream &ifs, Account &acc);
};

long Account::NextAccountNumber = 0; // static variable declartion.

Account ::Account(string fname, string lname, float balance)
{

    NextAccountNumber++;
    accnumber = NextAccountNumber;
    this->fname = fname;
    this->lname = lname;
    this->balance = balance;
}

void Account ::deposit(float amount)
{
    balance += amount;
}

void Account ::withdraw(float amount)
{
    if (amount > balance)
    {
        cout << "Insuffcient Balnce" << endl;
        exit(0);
    }
    else
    {
        balance -= amount;
    }
}

// Operator Overladong For <<
ostream &operator<<(ostream &os, Account &acc)
{
    os << "First Name : " << acc.getfirstName() << endl;
    os << "Last Name : " << acc.getLastName() << endl;
    os << "Account Number : " << acc.getAccno() << endl;
    os << "Balance : " << acc.getBalance() << endl;
    return os;
}

// For witing data in the file.
ofstream &operator<<(ofstream &ofs, Account &acc)
{
    ofs << acc.accnumber << endl;
    ofs << acc.fname << endl;
    ofs << acc.lname << endl;
    ofs << acc.balance << endl;
    return ofs;
}
// For reading data in the file.

ifstream &operator>>(ifstream &ifs, Account &acc)
{
    ifs >> acc.accnumber;
    ifs >> acc.fname;
    ifs >> acc.lname;
    ifs >> acc.balance;
    return ifs;
}

class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank() {}
    Account OpenAccount(string, string, float);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float balance);
    Account Withdraw(long accountNumber, float balance);
    void CloseAccount(long accountnumber);
    void ShowAllAccounts();
};

Account Bank::OpenAccount(string fname, string lname, float Balance)
{
    ofstream outfile;
    Account account(fname, lname, Balance);
    accounts.insert(pair<long, Account>(account.getAccno(), account));
    outfile.open("bankingDetails.txt", ios::app);
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(long accountnumber)
{
    map<long, Account>::iterator itr = accounts.find(accountnumber);
    return itr->second;
}
Account Bank::Deposit(long accountNumber, float balance)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.deposit(balance);
    return itr->second;
}

Account Bank::Withdraw(long accountNumber, float balance)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.withdraw(balance);
    return itr->second;
}
void Bank::CloseAccount(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    cout << "Account Deleted" << itr->second;
    accounts.erase(accountNumber);
}
void Bank::ShowAllAccounts()
{
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        cout << "Account " << itr->first << endl
             << itr->second << endl;
    }
}

int main()
{
    Bank b;              // Class Bank
    Account acc;         // class Account
    int choice;          // For choice Selection
    string fname, lname; // For Taking FirstName and LastName Variable.
    long accountNumber;  // For Acc number
    float balance;       // for Balamce
    float amount;        // For Withdra amount
    cout << "***Banking System***" << endl;
    do
    {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Balance Enquiry";
        cout << "\n\t3 Deposit";
        cout << "\n\t4 Withdrawal";
        cout << "\n\t5 Close an Account";
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter initil Balance: ";
            cin >> balance;
            acc = b.OpenAccount(fname, lname, balance);
            cout << "\nCongradulation Account is Created" << endl;
            cout << acc;
            break;

        case 2:

            cout << "Enter Account Number:";
            cin >> accountNumber;
            acc = b.BalanceEnquiry(accountNumber);
            cout << endl
                 << "Your Account Details" << endl;
            cout << acc;
            break;

        case 3:

            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Deposit(accountNumber, amount);
            cout << endl
                 << "Amount is Deposited" << endl;
            cout << acc;
            break;

        case 4:

            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Withdraw(accountNumber, amount);
            cout << endl
                 << "Amount Withdrawn" << endl;
            cout << acc;
            break;

        case 5:

            cout << "Enter Account Number:";
            cin >> accountNumber;
            b.CloseAccount(accountNumber);
            cout << endl
                 << "Account is Closed" << endl;
            cout << acc;

        case 6:

            b.ShowAllAccounts();
            break;

        case 7:

            break;
        default:
            cout << "\nEnter corret choice";
            exit(0);
        }
    } while (choice != 7);
    return 0;
}
