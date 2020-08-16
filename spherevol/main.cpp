/******************************************************
 * spherevol - calculates the volume of a sphere
 * Sage Fremont
*******************************************************/

#include <iostream>
#include <windows.h>    /* for Sleep() */
#include <limits>
#include <math.h>       /* pow */

using namespace std;

int main()
{

    SetConsoleTitle("SphereVol 1.0");

    cout << "   _____       _                __      __   _ " << endl;
    cout << "  / ____|     | |               \\ \\    / /  | |" << endl;
    cout << " | (___  _ __ | |__   ___ _ __ __\\ \\  / /__ | |" << endl;
    cout << "  \\___ \\| '_ \\| '_ \\ / _ \\ '__/ _ \\ \\/ / _ \\| |" << endl;
    cout << "  ____) | |_) | | | |  __/ | |  __/\\  / (_) | |" << endl;
    cout << " |_____/| .__/|_| |_|\\___|_|  \\___| \\/ \\___/|_|" << endl;
    cout << "        | |                                    " << endl;
    cout << "        |_|              (C) 2019 Sage Fremont " << endl;


    bool running = false;
    int runCounter = 0;

    // Wait until Enter is pressed
    do
    {
        cout << "\n             Press ENTER To Start              \n";
    }
    while (cin.get() != '\n');

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

        //Get the radius from the user
        float r;
        cout << "\nEnter the sphere's radius: ";
        // ensure the correct datatype and range is entered
        while ((!(cin >> r)) || (r <= 0))
        {
            cout << "Invalid radius. The radius must be a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //Calculate the volume
        float rcubed = pow(r, 3.0);
        float v = ((4 * M_PI * rcubed)/3);
        cout << "\nCalculating the volume of the sphere... \n\n";
        cout << "The formula is (4 * pi * " << r << "^3)/3" << endl;
        cout << "Volume = " << v << endl;


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

    } //END OF running


    return 0;

}
