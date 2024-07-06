/*
4.3: Rewrite the program of Exercise 4.2 to make the row parameter
of the matrix as a default argument.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class MatrixData {
    int row;
    int column;
    int** matrix;

public:
    ~MatrixData() {
        for (int i = 0; i < row; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Set data with default row value of 3
    void setData(int n, int m = 3) {
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
    cout << "Enter value for matrix column (n): ";
    cin >> n;
    cout << "Enter value for matrix row (m, default is 3): ";
    cin >> m;

    MatrixData m1;
    m1.setData(n, m);
    m1.setMatrix();
    m1.getMatrix();
    return 0;
}
