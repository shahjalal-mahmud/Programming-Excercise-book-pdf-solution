/*3.1 Write a function using reference variables as
arguments to swap the values of a pair of integers.*/

#include <iostream>
using namespace std;
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "After swap: ";
    Swap(&num1, &num2);
    cout << num1 << endl
         << num2 << endl;
    return 0;
}