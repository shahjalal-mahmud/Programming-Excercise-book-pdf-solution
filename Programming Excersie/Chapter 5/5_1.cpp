/*
5.1: Define a class to represent a bank account. Include the following members:

    Data members:
        1. Name of the depositor.
        2. Account number.
        3. Type of account.
        4. Balance amount in the account.

    Member functions:
        1. To assign initial values.
        2. To deposit an amount.
        3. To withdraw an amount after checking the balance.
        4. To display the name and balance.

Write a main program to test the program
*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    int balance;

public:
    void setValues(string name, int accountNumber, string accountType, int balance);
    void deposit();
    void withdraw();
    void display() const;
};

void BankAccount::setValues(string name, int accountNumber, string accountType, int balance) {
    this->name = name;
    this->accountNumber = accountNumber;
    this->accountType = accountType;
    this->balance = balance;
}

void BankAccount::deposit() {
    int amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    balance += amount;
    cout << "New balance: " << balance << endl;
}

void BankAccount::withdraw() {
    int amount;
    cout << "Enter withdraw amount: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient Balance." << endl;
    } else {
        balance -= amount;
        cout << "New balance: " << balance << endl;
    }
}

void BankAccount::display() const {
    cout << "Name: " << name << endl
         << "Account Number: " << accountNumber << endl
         << "Account Type: " << accountType << endl
         << "Balance: " << balance << endl;
}

int main() {
    string name;
    int accountNumber;
    string accountType;
    int balance = 0;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accountNumber;
    cin.ignore();  

    cout << "Enter account type: ";
    getline(cin, accountType);

    BankAccount account;
    account.setValues(name, accountNumber, accountType, balance);
    account.display();
    account.deposit();
    account.withdraw();
    account.display();
    return 0;
}
