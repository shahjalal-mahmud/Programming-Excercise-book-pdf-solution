/*
3.6 A cricket team has the following table of batting figures for a series
of test matches:

Player's name       Runs        Innings     Times not out
    Sachin          8430        230             18
    Saurav          4200        130              9
    Rahul           3350        105             11

Write a program to read the figures set out in the above form,
to calculate the batting averages and to print out the complete
table including the averages.
*/

#include <iostream>
#include <string>
using namespace std;
class cricket
{
    string name;
    int run;
    int innings;
    int TNO;

public:
    void Display_Table()
    {
        cout << "Name\t Runs\t Igs\t TNO\t" << "BA" << endl;
    }
    void setData(string n, int r, int in, int T)
    {
        name = n;
        run = r;
        innings = in;
        TNO = T;
    }
    void getData()
    {
        cout << name << "\t" << run << "\t" << innings << "\t" << TNO << "\t" << run / innings << endl;
    }
};
int main()
{
    cricket c1, c2, c3;
    string name1 = "Sachin";

    c1.setData(name1, 8430, 230, 18);

    string name2 = "Saurav";

    c2.setData(name2, 4200, 130, 9);

    string name3 = "Rahul";

    c3.setData(name3, 3350, 105, 11);

    c1.Display_Table();
    c1.getData();
    c2.getData();
    c3.getData();
    return 0;
}