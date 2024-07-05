/*3.2 Write a function that creates a vector of
user-given size M using new operator.*/

#include <iostream>
using namespace std;
int *Vector(int M)
{
    int *vec = new int[M];
    for (int i = 0; i < M; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> vec[i];
    }

    return vec;
}
void Display_Vector(int* vec, int M){
    cout << "Vector: [";
    for (int i = 0; i < M; i++) {
        cout << vec[i];
        if (i != M - 1) {
            cout << ", ";
        } else {
            cout << "]" << endl;
        }
    }
}
int main()
{
    int M;
    cout << "Enter a numer: ";
    cin >> M;

    int* vector = Vector(M);
    Display_Vector(vector, M);
    return 0;
}