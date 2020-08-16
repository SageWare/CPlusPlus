/******************************************************************
 * arithmetic - demonstrates the arithmetic operators in C++
 * Sage Fremont
*******************************************************************/

#include <iostream>
#include <limits>       /* numeric_limits */
#include <math.h>       /* fmod */
#include <windows.h>    /* for Sleep()*/

using namespace std;

int main()
{

    SetConsoleTitle("Arithmetic 0.1");

    cout << "\n:::'###::::'########::'####:'########:'##::::'##:'##::::'##:'########:'########:'####::'######::" << endl;
    cout << "::'## ##::: ##.... ##:. ##::... ##..:: ##:::: ##: ###::'###: ##.....::... ##..::. ##::'##... ##:" << endl;
    cout << ":'##:. ##:: ##:::: ##:: ##::::: ##:::: ##:::: ##: ####'####: ##:::::::::: ##::::: ##:: ##:::..::" << endl;
    cout << "'##:::. ##: ########::: ##::::: ##:::: #########: ## ### ##: ######:::::: ##::::: ##:: ##:::::::" << endl;
    cout << " #########: ##.. ##:::: ##::::: ##:::: ##.... ##: ##. #: ##: ##...::::::: ##::::: ##:: ##:::::::" << endl;
    cout << " ##.... ##: ##::. ##::: ##::::: ##:::: ##:::: ##: ##:.:: ##: ##:::::::::: ##::::: ##:: ##::: ##:" << endl;
    cout << " ##:::: ##: ##:::. ##:'####:::: ##:::: ##:::: ##: ##:::: ##: ########:::: ##::::'####:. ######::" << endl;
    cout << "..:::::..::..:::::..::....:::::..:::::..:::::..::..:::::..::........:::::..:::::....:::......:::" << endl;
    cout << "                                                                     :: (C) 2019 Sage Fremont ::" << endl;
    cout << "                                                                     '''''''''''''''''''''''''''" << endl;

    bool running = false;
    int runCounter = 0;

    // Wait until a key is pressed
    do
    {
        cout << "                           Press ENTER To Start                           \n";
    }
    while (cin.get() != '\n');

    running = true;

    double a;
    double b;

    while (running)
    {
        system("CLS");

        if (runCounter > 0)
        {
            cout << "\nRestarting program";
            Sleep(300);
            cout << ".";
            Sleep(100);
            cout << ".";
            Sleep(100);
            cout << ".";
            Sleep(100);
        }

        system("CLS");

        bool needA = true;
        bool needB = true;

        //user enters a number for a
        cout << "\nPlease enter your first number: ";
        do
        {
            // ensure the correct datatype is entered
            while (!(cin >> a))
            {
                cout << "Invalid input. Please enter your first number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            needA = false;
        }
        while (needA);

        //user enters a number for b
        cout << "\nPlease enter your second number: ";
        do
        {
            // ensure the correct datatype is entered
            while (!(cin >> b))
            {
                cout << "Invalid input. Please enter your second number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            needB = false;
        }
        while (needB);

        // Fancy Calculate
        cout << "\n\nCalculating";
        Sleep(300);
        cout << ".";
        Sleep(100);
        cout << ".";
        Sleep(100);
        cout << ".\n\n";
        Sleep(100);


        cout << "::: Addition :::" << endl;
        cout << a << " + " << b << " = " << a + b << "\n\n";

        cout << "::: Subtraction :::" << endl;
        cout << a << " - " << b << " = " << a - b << "\n\n";

        cout << "::: Multiplication :::" << endl;
        cout << a << " * " << b << " = " << a * b << "\n\n";

        cout << "::: Integer Division :::" << endl;
        if (((int)b != 0) && ((int)b != -0))
        {
            cout << a << " / " << b << " = " << (int)a / (int)b << "\n\n";
        }
        if (((int)b == 0) || ((int)b == -0))
        {
            cout << (int)a << " / " << (int)b << " = nan" << "\n\n";
        }

        cout << "::: Floating Point Division :::" << endl;
        cout << a << " / " << b << " = " << (float)a / b << "\n\n";

        cout << "::: Modulus :::" << endl;
        cout << a << " % " << b << " = " << fmod(a, b) << "\n\n";


        // QUIT or RESTART
        cout << "\nWould you like to quit? (Y or n): ";
        string c;
        getline (cin, c);
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
            runCounter++;
        }


    }

    return 0;

}
