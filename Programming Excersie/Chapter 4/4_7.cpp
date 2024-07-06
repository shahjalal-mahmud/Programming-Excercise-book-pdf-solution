/*
4.7: Write a function power() to raise a number m to power n. The function takes a double
value for m and int value for n and returns the result correctly.
Use a default value of 2 for n to make the function to calculate the squares
when this argument is omitted. Write a main that gets the values of m and n
from the user to test the function.
*/

#include <iostream>
using namespace std;

double power(double m, int n = 2)
{
    double result = 1.0;
    for (int i = 0; i < n; ++i)
    {
        result *= m;
    }
    return result;
}

int main()
{
    double m;
    int n;
    char choice;

    cout << "Enter the base number (m): ";
    cin >> m;

    cout << "Do you want to enter the exponent (n)? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the exponent (n): ";
        cin >> n;
        cout << m << " raised to the power " << n << " is: " << power(m, n) << endl;
    }
    else
    {
        cout << m << " squared is: " << power(m) << endl;
    }

    return 0;
}
