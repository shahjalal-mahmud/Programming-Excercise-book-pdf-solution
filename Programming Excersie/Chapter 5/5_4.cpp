/*
5.4: Modify the class and the program of Exercise 5.2 such that the program would be
able to add two vectors and display the resultant vector. (Note that we can pass objects as
function arguments)
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
    vector add(const vector &other); // Function to add two vectors
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

vector vector ::add(const vector &other)
{
    vector result;
    if (this->size != other.size)
    {
        cout << "Vectors must be of the same size to add!" << endl;
        return result;
    }
    result.size = this->size;
    for (int i = 0; i < size; i++)
    {
        result.element[i] = this->element[i] + other.element[i];
    }
    return result;
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
    int element1[5] = {10, 20, 30, 40, 50};
    int element2[5] = {2, 4, 6, 8, 10};

    vector v1, v2, v3;

    v1.create(5, element1);
    v2.create(5, element2);

    v1.display();
    v2.display();

    v2 = v1.add(v2);
    v2.display();
    return 0;
}