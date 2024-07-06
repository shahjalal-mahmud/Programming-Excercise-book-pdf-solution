/*
3.8 Write a program to print a table of values of the function
y = e^(-x) for x varying from 0 to 10 in steps of 0.1.
The table should appear as follows.
TABLE FOR Y = EXP [-X]
    X   0.1     0.2     0.3     0.4     0.5     0.6     0.7        0.8      0.9
    0
    1
    2
    .
    .
    9
*/
// All credits goes to Me(90%) and chatGPT(10%).

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printTable() {
    // Header
    cout << "TABLE FOR Y = EXP [-X]\n";
    cout << "    X";
    for (int i = 1; i <= 9; ++i) {
        cout << setw(8) << i * 0.1;
    }
    cout << "\n";

    // Rows
    for (int i = 0; i <= 9; ++i) {
        int x_base = i;
        cout << setw(5) << x_base;
        for (int j = 1; j <= 9; ++j) {
            double x = x_base + j * 0.1;
            double y = exp(-x);
            cout << setw(8) << fixed << setprecision(4) << y;
        }
        cout << "\n";
    }
}

int main() {
    printTable();
    return 0;
}
