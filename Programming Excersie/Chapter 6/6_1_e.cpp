/*
6.1: Design constructors for the classes designed in Programming Exercise 5.1 through 5.5 
of Chapter 5.

5.5: Create two classes DM and DB which store the value of distances. DM stores distances
in meters and centimeters and DB in feet and inches. Write a program that can read values
for the class objects and add one object of DM with another object of DB.
Use a friend function to carry out the addition operation. The object that stores the results
may be a DM object or DB object, depending on the units in which the results are required.
The display should be in the format of feet and inches or meters and centimeters depending
on the object on display.
*/


#include <iostream>
#include <cmath>
using namespace std;
class DB; // Forward declearation

class DM
{
    double meter;
    double centimeter;

public:
    DM(double m = 0, double cm = 0) : meter(m), centimeter(cm) {}
    void Read();
    void Display();
    friend DM addDistances(const DM &dm, const DB &db);
};
class DB
{
    double feet;
    double inch;

public:
    DB(double ft = 0, double in = 0) : feet(ft), inch(in) {}
    void Read();
    void Display();
    friend DM addDistances(const DM &dm, const DB &db);
};
void DM ::Read()
{
    cout << "Enter distance in meters and centimeters: ";
    cin >> meter >> centimeter;
}
void DM ::Display()
{
    cout << meter << " meters " << centimeter << " centimeters" << endl;
}
void DB ::Read()
{
    cout << "Enter distance in feet and inches: ";
    cin >> feet >> inch;
}
void DB ::Display()
{
    cout << feet << " feet " << inch << " inches" << endl;
}
DM addDistances(const DM &dm, const DB &db)
{
    double total_cm_DM = dm.meter * 100 + dm.centimeter;
    double total_cm_DB = db.feet * 30.48 + db.inch * 2.54;

    double result_cm = total_cm_DM + total_cm_DB;

    double result_m = result_cm / 100;
    double result_cm_Rem = fmod(result_cm, 100);

    return DM(result_m, result_cm_Rem);
}
int main()
{
    DM dm(30, 50);
    DB db(5, 9);

    dm.Display();
    db.Display();

    DM result = addDistances(dm, db);
    result.Display();

    return 0;
}