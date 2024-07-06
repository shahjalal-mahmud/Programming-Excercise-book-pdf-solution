/*
3.9: Write a program to calculate the variance and standard deviation of
N numbers
    Variance =1/N ∑(xi -x)^2
    Standard deviation=√1/N ∑(xi -x)^2
    Where x = 1/N ∑xi
*/
// All credit goes to solution of this book

#include <iostream>
#include <cmath>
using namespace std;
void variance(int n)
{
    float *x;
    x = new float[n];
    float sum;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }
    float mean;
    mean = sum / n;
    float v, v1;
    v1 = 0;
    for (int i = 0; i < n; i++)
    {
        v = x[i] - mean;
        v1 += pow(v, 2);
    }
    float variance, std_deviation;
    variance = v1 / n;
    std_deviation = sqrt(variance);
    cout << "\n\n variance = "
         << variance
         << "\n standard deviation = "
         << std_deviation << "\n";
    delete x;
}
int main()
{

    cout << " How many number ? :";
    int n;
    cin >> n;

    variance(n);
    return 0;
}