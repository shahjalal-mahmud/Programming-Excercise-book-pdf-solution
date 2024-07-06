/*
4.1: Write a function to read a matrix of size m*n from the keyboard
*/

#include <iostream>
using namespace std;
void setMatrix(int m, int n)
{
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter element for position (" << i + 1 << "," << j + 1 << ") : ";
            cin >> matrix[i][j];
        }
    }
}
int main()
{
    int m, n;
    cout << "Enter value for a matrix row and colunm(m, n): ";
    cin >> m >> n;
    setMatrix(m, n);
    return 0;
}