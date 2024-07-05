/*
3.7 Write programs to evaluate the following functions to 0.0001% accuracy.

        (a) sin x = x - (x^3/3!) + (x^5/5!) - (x^7/7!) + ......

        (b) SUM=1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + .......

        (c) cos x = x - (x^2/2!) + (x^4/4!) - (x^6/6!) + ......
*/

#include <iostream>
#include <cmath>
#include <iomanip> // For setting precision
using namespace std;
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
void calculate(double x, int y)
{
    int n = 2, m = 1;
    long double sum = 0;
    for (int i = 1; i <= y; i++)
    {
        sum += ((pow((-1), n)) * (pow(x, m) / factorial(m)));
        n++;
        m = m + 2;
    }
    cout << fixed << setprecision(10); // Set output precision to 10 digits
    cout << "sin " << "x = " << sum << endl;
}

int main()
{
    double x;
    int y;
    cout << "Enter a value for x(in radians): ";
    cin >> x;
    cout << "Enter the number of term: ";
    cin >> y;

    calculate(x, y);

    return 0;
}