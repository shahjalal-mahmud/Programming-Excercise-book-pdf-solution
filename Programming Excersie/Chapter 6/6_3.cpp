/*
6.3: A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system searches
the list and displays whether it is available or not. If it is not, an appropriate message is
displayed. If it is, then the system displays the book details and requests for the number of
copies required. If the requested copies are available, the total cost of the requested copies is
displayed; otherwise “Required copies not in stock” is displayed.
Design a system using a class called books with suitable member functions and constructors.
Use new operator in constructors to allocate memory space required.
*/

#include <iostream>
using namespace std;
class Book
{
    string author;
    string title;
    string publisher;
    double price;
    int stock;

public:
    Book(const string &aut, const string &ti, const string &pub, double pri, int st)
    {
        author = aut;
        title = ti;
        publisher = pub;
        price = pri;
        stock = st;
    }
    void Display() const
    {
        cout << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "Publisher: " << publisher << "\n"
             << "Price: " << price << "\n"
             << "Stock: " << stock << std::endl;
    }
    bool isMatch(const string &ti, const string &aut) const
    {
        return title == ti && author == aut;
    }
    void requestCopies(int numCopies)
    {
        if (numCopies <= stock)
        {
            cout << "Total cost: " << numCopies * price << endl;
            stock -= numCopies;
        }
        else
        {
            cout << "Required copies not in stock" << endl;
        }
    }
};
// Function to search for a book in the inventory
void searchBook(Book *books[], int size, const string &title, const string &author)
{
    for (int i = 0; i < size; ++i)
    {
        if (books[i]->isMatch(title, author))
        {
            cout << "Book found:\n";
            books[i]->Display();
            cout << "Enter the number of copies required: ";
            int numCopies;
            cin >> numCopies;
            books[i]->requestCopies(numCopies);
            return;
        }
    }
    cout << "Book not available" << endl;
}

int main()
{
    // Creating inventory
    Book *inventory[] = {
        new Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", "Bloomsbury", 20.5, 10),
        new Book("J.R.R. Tolkien", "The Hobbit", "HarperCollins", 15.75, 5),
        new Book("George Orwell", "1984", "Secker & Warburg", 13.25, 7),
    };
    int size = sizeof(inventory) / sizeof(inventory[0]);

    string title, author;
    cout << "Enter the title of the book: ";
    getline(cin, title);
    cout << "Enter the author of the book: ";
    getline(cin, author);

    searchBook(inventory, size, title, author);

    // Deleting allocated memory
    for (int i = 0; i < size; ++i)
    {
        delete inventory[i];
    }

    return 0;
}