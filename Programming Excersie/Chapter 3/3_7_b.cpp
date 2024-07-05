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
void SUM(int n)
{
    float sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + pow(1.0 / i, i);
    }
    cout << fixed << setprecision(8); // Set output precision to 8 digits
    cout << "SUM = " << sum << endl;
}
int main()
{
    int n;
    cout << "Enter the number of term: ";
    cin >> n;

    SUM(n);
    return 0;
}