/*2.5 Write a C++ program that will ask for a temperature in Fahrenheit
 and display it in Celsius.
*/

#include <iostream>
using namespace std;
int main()
{
    double Fahrenheit;
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> Fahrenheit;

    double Celsius = ((Fahrenheit - 32) * 5) / 9;
    cout << "Temparature in Celsius: " << Celsius << endl;
    return 0;
}