/*
4.2: Write a program to read a matrix of size m*n from the keyboard and display the same
on the screen using function
*/

#include <iostream>
#include <iomanip>
using namespace std;

class MatrixData {
    int row;
    int column;
    int** matrix; 

public:
    // Destructor to deallocate memory
    ~MatrixData() {
        for (int i = 0; i < row; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void setData(int m, int n) {
        row = m;
        column = n;
        matrix = new int*[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new int[column];
        }
    }

    void setMatrix() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << "Enter element for position (" << i + 1 << "," << j + 1 << ") : ";
                cin >> matrix[i][j];
            }
        }
    }

    void getMatrix() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(5) << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int m, n;
    cout << "Enter value for a matrix row and column (m, n): ";
    cin >> m >> n;

    MatrixData m1;
    m1.setData(m, n);
    m1.setMatrix();
    m1.getMatrix();
    return 0;
}
