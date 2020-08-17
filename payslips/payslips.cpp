/***************************************************
 * payslips - calculates & prints employee payslips
 * Sage Fremont 2019
****************************************************/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void employee(string &name, float &hoursWorked, float &payRate)
{
    cout << "Enter Employee Name: ";
    getline (cin, name);

    cin.clear();
    cout << "Enter Hours Worked: ";
    cin >> hoursWorked;

    cin.clear();
    cout << "Enter Hourly Payrate: ";
    cin >> payRate;
    cin.clear();
}

float calculatePay(float hw, float pr, float &pay)
{

    float overtime;
    float bonus;
    if (hw <= 40)
    {
        pay = hw * pr;
    }
    if (hw > 40)
    {
        overtime = hw - 40;
        bonus = overtime * (pr * 1.5);
        pay = (40 * pr) + bonus;
    }

    return pay;
}

void createPayslip(string name, float hw, float pr, float pay)
{

    float overtime;
    float bonus;
    if (hw <= 40)
    {
        overtime = 0;
        bonus = 0;
    }
    if (hw > 40)
    {
        overtime = hw - 40;
        bonus = overtime * (pr * 1.5);
    }

    cout << "\nPAYSLIP FOR: " << name << endl;
    cout << " Hours Worked: " << hw << endl;
    cout << " Hourly Payrate: " << pr << endl;
    cout << " Overtime Clocked: " << overtime << endl;
    cout << " Overtime Bonus Earned: $" << bonus << endl;
    cout << " Total Payment Earned: $" << pay << endl;
    //print name, hours worked, number of overtime hours, hourly pay rate, pay
}

int main()
{

    bool running = true;
    string name;
    float hoursWorked;
    float payRate;
    float pay;

    while (running)
    {

        employee(name, hoursWorked, payRate);

        calculatePay(hoursWorked, payRate, pay);

        createPayslip(name, hoursWorked, payRate, pay);



        // QUIT or RESTART
        cout << "\nWould you like to quit? (Y or n): ";
        string c;
        while ((!(cin >> c)) || ((c[0] != 'Y') && (c[0] != 'y') && (c[0] != 'N') && (c[0] != 'n')) || (c.length() > 1))
        {
            cout << "Invalid input. Would you like to quit? (Y or n): ";
            cin.clear();
        }
        if ((c[0] == 'Y') || (c[0] == 'y'))
        {
            cout << "\n\nTerminating program";
            Sleep(400);
            cout << ".";
            Sleep(200);
            cout << ".";
            Sleep(100);
            cout << ".";
            Sleep(100);
            running = false;
        }
        if ((c[0] == 'N') || (c[0] == 'n'))
        {
            cout << "\n\nrestarting...\n\n\n";
        }
    }

    return 0;
}
