/*
6.5: Modify the program of exercise 6.4 to demonstrate 
the use of pointer to access the members.
*/

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    double price;
    int stock;

    static int successfulTransactions;
    static int unsuccessfulTransactions;

    // Private member function to update the price
    void updatePrice(double newPrice) {
        price = newPrice;
    }

public:
    // Constructor to initialize book details
    Book(const string& auth, const string& titl, const string& pub, double pr, int st) {
        author = auth;
        title = titl;
        publisher = pub;
        price = pr;
        stock = st;
    }

    // Function to display book details
    void displayDetails() const {
        cout << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "Publisher: " << publisher << "\n"
             << "Price: " << price << "\n"
             << "Stock: " << stock << endl;
    }

    // Function to check if a book matches the given title and author
    bool isMatch(const string& titl, const string& auth) const {
        return title == titl && author == auth;
    }

    // Function to request copies and update stock
    void requestCopies(int numCopies) {
        if (numCopies <= stock) {
            cout << "Total cost: " << numCopies * price << endl;
            stock -= numCopies;
            successfulTransactions++;
        } else {
            cout << "Required copies not in stock" << endl;
            unsuccessfulTransactions++;
        }
    }

    // Public method to update the price using private member function
    void changePrice(double newPrice) {
        updatePrice(newPrice);
    }

    // Static methods to get the transaction counts
    static int getSuccessfulTransactions() {
        return successfulTransactions;
    }

    static int getUnsuccessfulTransactions() {
        return unsuccessfulTransactions;
    }
};

// Initialize static members
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

// Function to search for a book in the inventory
void searchBook(Book* books[], int size, const string& title, const string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i]->isMatch(title, author)) {
            cout << "Book found:\n";
            books[i]->displayDetails();
            cout << "Enter the number of copies required: ";
            int numCopies;
            cin >> numCopies;
            books[i]->requestCopies(numCopies);
            return;
        }
    }
    cout << "Book not available" << endl;
}

int main() {
    // Creating inventory using pointers
    Book* inventory[] = {
        new Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", "Bloomsbury", 20.5, 10),
        new Book("J.R.R. Tolkien", "The Hobbit", "HarperCollins", 15.75, 5),
        new Book("George Orwell", "1984", "Secker & Warburg", 13.25, 7),
    };
    int size = sizeof(inventory) / sizeof(inventory[0]);

    // Taking user input for book search
    string title, author;
    cout << "Enter the title of the book: ";
    getline(cin, title);
    cout << "Enter the author of the book: ";
    getline(cin, author);

    // Searching for the book in the inventory
    searchBook(inventory, size, title, author);

    // Using a pointer to update price for the first book
    Book* bookPtr = inventory[0];
    bookPtr->changePrice(22.0);
    cout << "Updated price of the first book:\n";
    bookPtr->displayDetails();

    // Display transaction statistics
    cout << "Successful transactions: " << Book::getSuccessfulTransactions() << endl;
    cout << "Unsuccessful transactions: " << Book::getUnsuccessfulTransactions() << endl;

    // Deleting allocated memory
    for (int i = 0; i < size; ++i) {
        delete inventory[i];
    }

    return 0;
}
