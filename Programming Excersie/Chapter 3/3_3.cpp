/*
3.3 Write a program to print the following output using for loops.
                1
                22
                333
                4444
                55555
*/

#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}