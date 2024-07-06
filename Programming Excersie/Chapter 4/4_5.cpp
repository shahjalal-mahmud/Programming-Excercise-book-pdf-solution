/*
4.5: Write a macro that obtains the largest of the three numbers
*/

#include <iostream>
#include <iomanip>
using namespace std;

float large(float a, float b, float c)
{
    float largest;
    if (a > b)
    {
        if (a > c)
            largest = a;
        else
            largest = c;
    }
    else
    {
        if (b > c)
            largest = b;
        else
            largest = c;
    }
    return largest;
}
int main()
{
    float x, y, z;
    cout << " Enter three values : ";
    cin >> x >> y >> z;
    float largest = large(x, y, z);
    cout << " large = " << largest << endl;
    return 0;
}