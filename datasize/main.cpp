/******************************************************************
 * datasize - prints the Size and Limits of fundamental data types
 * Sage Fremont
*******************************************************************/

#include <iostream>
#include <limits>       /* for numeric_limits */
#include <windows.h>    /* for Sleep() */
#include <sstream>      /* for ostringstream */

using namespace std;

int main()
{
    SetConsoleTitle("DataSize 1.0");

    cout << "                                                                              " << endl;
    cout << "     _/_/_/                _/                  _/_/_/  _/                     " << endl;
    cout << "    _/    _/    _/_/_/  _/_/_/_/    _/_/_/  _/            _/_/_/_/    _/_/    " << endl;
    cout << "   _/    _/  _/    _/    _/      _/    _/    _/_/    _/      _/    _/_/_/_/   " << endl;
    cout << "  _/    _/  _/    _/    _/      _/    _/        _/  _/    _/      _/          " << endl;
    cout << " _/_/_/      _/_/_/      _/_/    _/_/_/  _/_/_/    _/  _/_/_/_/    _/_/_/     " << endl;
    cout << "                                                                              " << endl;
    cout << "                                                    (C) 2019 Sage Fremont      \n\n";

    bool running = false;
    int runCounter = 0;

    // Wait until Enter is pressed
    do
    {
        cout << "                           Press ENTER To Start                           \n";
    }
    while (cin.get() != '\n');


    // declaring output string stream (to convert numbers to string to get the length)
    ostringstream numToString;


    running = true;
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
            system("CLS");
        }

        bool wantsSize = false;
        bool wantsLimit = false;

        cout << "+----------------------------+" << endl;
        cout << "|       PROGRAM OPTIONS      |" << endl;
        cout << "+------+---------------------+" << endl;
        cout << "| CODE |        OPTION       |" << endl;
        cout << "+------+---------------------+" << endl;
        cout << "|   0  |  Get Datatype Size  |" << endl;
        cout << "+------+---------------------+" << endl;
        cout << "|   1  | Get Datatype Limits |" << endl;
        cout << "+------+---------------------+" << endl;

        // User selects option
        cin.clear();
        cout << "\nSelect an option by entering the designated code: ";
        string op;
        while ((!(cin >> op)) || ((op[0] != '0') && (op[0] != '1')) || (op.length() > 1))
        {
            getline (cin, op);
            cout << "Invalid code. Please enter code 0 or 1: ";
            cin.clear();
        }
        switch (op[0])
        {
        case '0':
            wantsSize = true;
            break;
        case '1':
            wantsLimit = true;
            break;
        }


        //DATATYPE SIZE
        while (wantsSize)
        {
            system("CLS");

            cout << "+--------------------+" << endl;
            cout << "|    SIZE OPTIONS    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "| CODE |   DATATYPE  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   0  |     bool    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   1  |     char    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   2  |  wide char  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   3  |    short    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   4  |     int     |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   5  |     long    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   6  |  long long  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   7  |    float    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   8  |    double   |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   9  | long double |" << endl;
            cout << "+------+-------------+" << endl;

            // User selects code
            int i;
            string iString;
            cin.clear();
            numToString.str("");
            numToString.clear();
            cout << "\nSelect a datatype by entering the designated code: ";
            // ensure the correct datatype, allowed range, and allowed length is entered
            while ((!(cin >> i)) || ((i < 0) || (i > 9)) || (iString.length() > 1))
            {
                numToString << i;
                iString = numToString.str(); // the str() coverts number into string
                //handle exception & clear all variables to restart
                cout << "Invalid code. Please enter between 0 - 9: ";
                numToString.str("");
                numToString.clear();
                iString = "";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

            cout << "\nFetching your datatype size... \n\n";

            // Apply the code
            switch (i)
            {
            case 0: //bool
                cout << "Size of bool: " << sizeof(bool) << " byte(s)" << endl;
                break;
            case 1: //char
                cout << "Size of char: " << sizeof(char) << " byte(s)" << endl;
                break;
            case 2: //wide char
                cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte(s)" << endl;
                break;
            case 3: //short
                cout << "Size of short: " << sizeof(short) << " byte(s)" << endl;
                break;
            case 4: //int
                cout << "Size of int: " << sizeof(int) << " byte(s)" << endl;
                break;
            case 5: //long
                cout << "Size of long: " << sizeof(long) << " byte(s)" << endl;
                break;
            case 6: //long long
                cout << "Size of long long: " << sizeof(long long) << " byte(s)" << endl;
                break;
            case 7: //float
                cout << "Size of float: " << sizeof(float) << " byte(s)" << endl;
                break;
            case 8: //double
                cout << "Size of double: " << sizeof(double) << " byte(s)" << endl;
                break;
            case 9: //long double
                cout << "Size of long double: " << sizeof(long double) << " byte(s)" << endl;
                break;
            }

            // Get Another Size?
            cout << "\nWould you like to fetch another size? (Y or n): ";
            string s;
            getline (cin, s);
            while ((!(cin >> s)) || ((s[0] != 'Y') && (s[0] != 'y') && (s[0] != 'N') && (s[0] != 'n')) || (s.length() > 1))
            {
                cout << "Invalid input. Would you like to fetch another size? (Y or n): ";
                cin.clear();
            }
            if ((s[0] == 'N') || (s[0] == 'n'))
            {
                wantsSize = false;
            }

        } // END OF wantsSize



        //DATATYPE LIMITS
        while (wantsLimit)
        {

            system("CLS");

            cout << "+--------------------+" << endl;
            cout << "|   LIMITS OPTIONS   |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "| CODE |   DATATYPE  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   0  |     bool    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   1  |     char    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   2  |  wide char  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   3  |    short    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   4  |     int     |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   5  |     long    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   6  |  long long  |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   7  |    float    |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   8  |    double   |" << endl;
            cout << "+------+-------------+" << endl;
            cout << "|   9  | long double |" << endl;
            cout << "+------+-------------+" << endl;

            // User selects code
            int j;
            string jString;
            cin.clear();
            numToString.str("");
            numToString.clear();
            cout << "\nSelect a datatype by entering the designated code: ";
            // ensure the correct datatype, allowed range, and allowed length is entered
            while ((!(cin >> j)) || ((j < 0) || (j > 9)) || (jString.length() > 1))
            {
                numToString << j;
                jString = numToString.str(); // the str() coverts number into string
                //handle exception & clear all variables to restart
                cout << "Invalid code. Please enter between 0 - 9: ";
                numToString.str("");
                numToString.clear();
                jString = "";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

            cout << "\nFetching your datatype limits... \n\n";

            // Apply the code
            switch (j)
            {
            case 0: //bool
                cout << "Limits of bool: " << numeric_limits<bool>::min() << " to " << numeric_limits<bool>::max() << endl;
                break;
            case 1: //char
                cout << "Limits of char: " << CHAR_MIN << " to " << CHAR_MAX << endl;
                break;
            case 2: //wide char
                cout << "Limits of wchar_t: " << numeric_limits<wchar_t>::min() << " to " << numeric_limits<wchar_t>::max() << endl;
                break;
            case 3: //short
                cout << "Limits of short: " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << endl;
                break;
            case 4: //int
                cout << "Limits of int: " << numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << endl;
                break;
            case 5: //long
                cout << "Limits of long: " << numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << endl;
                break;
            case 6: //long long
                cout << "Limits of long long: " << numeric_limits<long long>::min() << " to " << numeric_limits<long long>::max() << endl;
                break;
            case 7: //float
                cout << "Limits of float: " << numeric_limits<float>::min() << " to " << numeric_limits<float>::max() << endl;
                break;
            case 8: //double
                cout << "Limits of double: " << numeric_limits<double>::min() << " to " << numeric_limits<double>::max() << endl;
                break;
            case 9: //long double
                cout << "Limits of long double: " << numeric_limits<long double>::min() << " to " << numeric_limits<long double>::max() << endl;
                break;
            }

            // Get Another Limit?
            cout << "\nWould you like to fetch another limit range? (Y or n): ";
            string g;
            getline (cin, g);
            while ((!(cin >> g)) || ((g[0] != 'Y') && (g[0] != 'y') && (g[0] != 'N') && (g[0] != 'n')) || (g.length() > 1))
            {
                cout << "Invalid input. Would you like to fetch another size? (Y or n): ";
                cin.clear();
            }
            if ((g[0] == 'N') || (g[0] == 'n'))
            {
                wantsLimit = false;
            }

        } // END OF wantsLimit


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
            Sleep(300);
            cout << ".";
            Sleep(100);
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

    } //END OF running

    return 0;
}
