/*2.3 Write a program to input an integer value from keyboard
 and display on screen "WELL DONE" that many times.
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter an integer value: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "WELL DONE" << endl;
    }

    return 0;
}