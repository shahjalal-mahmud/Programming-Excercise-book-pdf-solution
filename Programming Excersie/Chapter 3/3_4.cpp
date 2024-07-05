/*
3.4 Write a program to evaluate the following investment equation
        V = P(1+r)^n
and print the tables which would give the value of V
for various combination of the following values of P, r and n:
        P: 1000, 2000, 3000,..., 10,000
        r: 0.10, 0.11, 0.12,...., 0.20
        n: 1, 2, 3,.....10

(Hint: P is the principal amount and V is the value of money at the end of n years.
This equation can be recursively written as
        V = P(1+r)
        P=V
In other words, the value of money at the end of the first year becomes
the principal amount for the next year, and so on.
*/

#include <iostream>
#include <cmath>
using namespace std;
void display_P()
{
        int P = 1000;
        cout << "P: ";
        while (P <= 10000)
        {
                cout << "\t" << P;
                P = P + 1000;
        }
        cout << endl;
}
void display_r()
{
        float r = 0.10;
        cout << "r: ";
        while (r <= 0.20)
        {
                cout << "\t" << r;
                r = r + 0.01;
        }
        cout << endl;
}
void display_n()
{
        int n = 1;
        cout << "n: ";
        while (n <= 10)
        {
                cout << "\t" << n;
                n++;
        }
        cout << endl;
}
void display_V()
{
        double V;
        int P = 1000;
        float r = 0.10;
        int n = 1;

        cout << "V: ";
        while (P <= 10000 && r <= 0.20 && n <= 10)
        {
                V = P * pow((1 + r), n);
                cout << "\t" << V;
                P += 1000;
                r += 0.01;
                n++;
        }
        cout << endl;
}
int main()
{
        display_P();
        display_r();
        display_n();
        display_V();

        return 0;
}