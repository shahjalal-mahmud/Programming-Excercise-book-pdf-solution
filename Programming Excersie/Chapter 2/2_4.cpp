/*2.4 Write a program to read the values of a, b and c and display the value of x,
where x = a/b-c
Test your program for the following values:
(a) a = 250, b = 85, c = 25
(b) a = 300, b = 70, c = 70
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter values of a, b, c: ";
    cin >> a >> b >> c;
    int x = (a / b) - c;
    cout << "x = " << x << endl;
    return 0;
}