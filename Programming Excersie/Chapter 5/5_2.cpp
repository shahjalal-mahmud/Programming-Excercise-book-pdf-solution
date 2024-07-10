/*
5.2: Write a class to represent a vector (a series of float values). Include member functions
to perform the following tasks:
    (a) To create the vector.
    (b) To modify the value of a given element.
    (c) To multiply by a scalar value.
    (d) To display the vector in the form (10, 20, 30 …)
Write a program to test your class.
*/

#include <iostream>
using namespace std;

class vector
{
private:
    int element[100];
    int size;

public:
    vector(); // Constructor to initialize size
    void create(int size, int ele[]);
    void modify(int index, int value);
    void multiple(int scalar);
    void display();
};
vector ::vector()
{
    size = 0;
}
void vector ::create(int size, int ele[])
{
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        this->element[i] = ele[i];
    }
}
void vector ::modify(int index, int value)
{
    element[index] = value;
}
void vector ::multiple(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        element[i] = element[i] * scalar;
    }
}
void vector ::display()
{
    cout << "(";
    for (int i = 0; i < size; i++)
    {
        cout << element[i];
        if (i != size - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ")";
        }
    }
    cout << endl;
}
int main()
{
    // int size = 5;
    //  cout << "Enter the size of the vector: ";
    //  cin >> size;

    int element[5] = {10, 20, 30, 40, 50};

    vector v1;
    v1.create(5, element);
    v1.display();

    // int index, value;
    // cout << "Enter index and value: ";
    // cin >> index >> value;

    v1.modify(2, 25);
    v1.display();

    // int scalar;
    // cout << "Enter a number: ";
    // cin >> scalar;

    v1.multiple(2);
    v1.display();

    return 0;
}