/*
5.3: Modify the class and the program of Exercise 5.1 for handling 10 customers.
*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    string accountType;
    int balance;

public:
    BankAccount(string name, int accountNumber, string accountType, int balance); // Constructor
    void deposit();
    void withdraw();
    void display() const;
    ~BankAccount(); // Destructor
};

BankAccount::BankAccount(string name, int accountNumber, string accountType, int balance)
{
    this->name = name;
    this->accountNumber = accountNumber;
    this->accountType = accountType;
    this->balance = balance;
    cout << "Account for " << name << " created successfully." << endl;
}

void BankAccount::deposit()
{
    int amount;
    cout << "Enter deposit amount for account " << accountNumber << ": ";
    cin >> amount;
    balance += amount;
    cout << "New balance: " << balance << endl;
}

void BankAccount::withdraw()
{
    int amount;
    cout << "Enter withdraw amount for account " << accountNumber << ": ";
    cin >> amount;
    if (amount > balance)
    {
        cout << "Insufficient Balance." << endl;
    }
    else
    {
        balance -= amount;
        cout << "New balance: " << balance << endl;
    }
}

void BankAccount::display() const
{
    cout << "Name: " << name << endl
         << "Account Number: " << accountNumber << endl
         << "Account Type: " << accountType << endl
         << "Balance: " << balance << endl;
}

BankAccount::~BankAccount()
{
    cout << "Account for " << name << " with account number " << accountNumber << " is being deleted." << endl;
}

int main()
{
    const int numCustomers = 10;
    BankAccount *accounts[numCustomers];

    for (int i = 0; i < numCustomers; ++i)
    {
        string name;
        int accountNumber;
        string accountType;
        int balance = 0;

        cout << "Enter name for customer " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter account number for customer " << i + 1 << ": ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter account type for customer " << i + 1 << ": ";
        getline(cin, accountType);

        accounts[i] = new BankAccount(name, accountNumber, accountType, balance);
    }

    for (int i = 0; i < numCustomers; ++i)
    {
        cout << "\nCustomer " << i + 1 << " details:\n";
        accounts[i]->display();
        accounts[i]->deposit();
        accounts[i]->withdraw();
        accounts[i]->display();
    }

    for (int i = 0; i < numCustomers; ++i)
    {
        delete accounts[i];
    }

    return 0;
}
