/*2.6 Redo Exercise 2.5 using a class called temp and member functions.*/

#include <iostream>
using namespace std;
class temp
{
    int F;

public:
    void setValue(int a)
    {
        F = a;
    }
    void getValue()
    {
        cout << "Temperature in Fahrenheit: " << F << endl;
    }
    int ToCelsius(int a)
    {
        double Celsius = ((a - 32) * 5) / 9;
        return Celsius;
    }
};
int main()
{
    double Fahrenheit;
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> Fahrenheit;

    temp obj1;
    obj1.setValue(Fahrenheit);
    double Celsius = obj1.ToCelsius(Fahrenheit);
    cout << "Temerature in Celsius: " << Celsius << endl;
    return 0;
}