/*
4.8: Write a function that performs the same operation as that of Exercise 4.18 but takes an
int value for m. Both the functions should have the same name. Write a main that calls both
the functions. Use the concept of function overloading.
*/

#include <iostream>
using namespace std;

// Function to raise a double m to the power n (default n=2)
double power(double m, int n = 2)
{
    double result = 1.0;
    for (int i = 0; i < n; ++i)
    {
        result *= m;
    }
    return result;
}

// Overloaded function to raise an int m to the power n (default n=2)
int power(int m, int n = 2)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
    {
        result *= m;
    }
    return result;
}

int main()
{
    double m_double;
    int m_int, n;
    char choice;

    // Testing the function with double m
    cout << "Enter the base number (double m): ";
    cin >> m_double;

    cout << "Do you want to enter the exponent (n) for double? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the exponent (n): ";
        cin >> n;
        cout << m_double << " raised to the power " << n << " is: " << power(m_double, n) << endl;
    }
    else
    {
        cout << m_double << " squared is: " << power(m_double) << endl;
    }

    // Testing the function with int m
    cout << "Enter the base number (int m): ";
    cin >> m_int;

    cout << "Do you want to enter the exponent (n) for int? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the exponent (n): ";
        cin >> n;
        cout << m_int << " raised to the power " << n << " is: " << power(m_int, n) << endl;
    }
    else
    {
        cout << m_int << " squared is: " << power(m_int) << endl;
    }

    return 0;
}
