/*
2.2 Write a program to read two numbers from the keyboard and display the larger
value on the screen.
*/

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout<<"Enter two numers: ";
    cin >> num1 >> num2;
    if (num1 > num2)
    {
        cout <<"Largest: "<< num1;
    }
    else
    {
        cout <<"Largest: "<< num2;
    }
    return 0;
}