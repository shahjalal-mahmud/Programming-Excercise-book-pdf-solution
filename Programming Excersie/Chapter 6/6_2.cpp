/*
6.2: Define a class String that could work as a user-defined string type. Include
constructors that will enable us to create an uninitialized string:
    String s1; // string with length 0
    And also initialize an object with a string constant at the time of creation like
    String s2(“Well done!”);
    Include a function that adds two strings to make a third string. Note that the statement
    S2 = s1;
    will be perfectly reasonable expression to copy one string to another.
Write a complete program to test your class to see that it does the following tasks:
    (a) Creates uninitialized string objects.
    (b) Creates objects with string constants.
    (c) Concatenates two strings properly.
    (d) Displays a desired string object
*/

#include <iostream>
#include <cstring>
using namespace std;
class String
{
    char *str;
    int length;

public:
    String() : str(nullptr), length(0) {} // Default constructor

    String(const char *s) // Parameterized constructor
    {
        {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
    }

    String(const String &s) // Copy constructor
    {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    String &operator=(const String &s) // Assignment operator
    {
        if (this == &s)
            return *this;

        delete[] str;
        length = s.length;
        str = new char[length + 1];
        std::strcpy(str, s.str);
        return *this;
    }

    String operator+(const String &s) const // Concatenation operator
    {
        String temp;
        temp.length = length + s.length;
        temp.str = new char[temp.length + 1];
        std::strcpy(temp.str, str);
        std::strcat(temp.str, s.str);
        return temp;
    }

    void display() const
    {
        if (str)
        {
            std::cout << str << std::endl;
        }
        else
        {
            std::cout << "(null)" << std::endl;
        }
    }

    ~String() // Destructor
    {
        delete[] str;
    }
};

int main()
{
    // Test creating uninitialized string
    String s1;
    cout << "s1: ";
    s1.display();

    // Test creating string with constant
    String s2("Well done! ");
    cout << "s2: ";
    s2.display();

    // Test assignment
    s1 = s2;
    cout << "s1 after assignment: ";
    s1.display();

    // Test concatenation
    String s3 = s1 + s2;
    cout << "s3 (concatenation of s1 and s2): ";
    s3.display();
    return 0;
}