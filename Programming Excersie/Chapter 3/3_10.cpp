/*
3.10: An electricity board charges the following rates to domestic users to
discourage large consumption of energy:
    For the first 100 units     –   60P per unit
    For the first 200 units     –   80P per unit
    For the first 300 units     –   90P per unit
All users are charged a minimum of Rs. 50.00. If the total amount is more than Rs. 300.00
then an additional surcharge of 15% is added.
Write a program to read the names of users and number of units consumed and print out the
charges with names
*/

// All credits goes to ChatGPT.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Electricity {
    int units;
    string name;

public:
    void setData(const string& n, int u) {
        name = n;
        units = u;
    }
    
    string getName() const {
        return name;
    }
    
    int getUnits() const {
        return units;
    }

    double calculation() const {
        double charged = 0.0;
        int u = units;

        if (u <= 100) {
            charged = u * 0.60;
        } else if (u <= 200) {
            charged = 100 * 0.60 + (u - 100) * 0.80;
        } else if (u <= 300) {
            charged = 100 * 0.60 + 100 * 0.80 + (u - 200) * 0.90;
        } else {
            charged = 100 * 0.60 + 100 * 0.80 + 100 * 0.90 + (u - 300) * 0.90;
        }

        if (charged < 50.0) {
            charged = 50.0;
        }

        if (charged > 300.0) {
            charged += charged * 0.15;
        }

        return charged;
    }
};

int main() {
    int n;
    cout << "How many users? : ";
    cin >> n;
    
    vector<Electricity> users(n);
    cin.ignore(); // to clear the newline character from the input buffer

    for (int i = 0; i < n; ++i) {
        string name;
        int units;
        cout << "Enter the name of user " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter the consumed units for user " << i + 1 << ": ";
        cin >> units;
        cin.ignore(); 
        users[i].setData(name, units);
    }

    cout << "\nCharges Table:\n";
    cout << setw(20) << left << "Name" << setw(15) << "Units Consumed" << setw(15) << "Total Charge" << endl;
    cout << string(50, '-') << endl;

    for (const auto& user : users) {
        cout << setw(20) << left << user.getName()
             << setw(15) << user.getUnits()
             << setw(15) << fixed << setprecision(2) << user.calculation() << endl;
    }

    return 0;
}
