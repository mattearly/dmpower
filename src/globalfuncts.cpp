/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2016 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/


#include <iomanip>
#include "globalfuncts.h"
#include <cmath>

using namespace std;

void simpleClearScreen()
{
    for (int i = 0; i < 14; i++)
    {
        std::cout << "\n\n\n\n\n";
    }
}

char getYorN(const std::string &message)
{
    char tmp;
    do
    {
        std::cout << message;
        std::cin >> tmp;
        tmp = toupper(tmp);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!(tmp == 'Y' || tmp == 'N'))
            std::cout << "Invalid, Try again (only takes 'Y', 'N', 'y', or 'n'.\n";

    } while (!(tmp == 'Y' || tmp == 'N'));
    return tmp;
}

void pressEnterToContinue()
{
    std::cin.clear();
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPress 'ENTER' to continue.\n\n";
    std::cin.get();
}

int rollstats_hi_power()
{
    int r1, r2, r3, r4;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    r4 = rolld6(mgen);
    cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << ", " << r4 << endl;
    if (r1 <= r2 && r1 <= r3 && r1 <= r4)
    {
        return (r2 + r3 + r4);
    }
    else if (r2 <= r1 && r2 <= r3 && r2 <= r4)
    {
        return (r1 + r3 + r4);
    }
    else if (r3 <= r1 && r3 <= r2 && r3 <= r4)
    {
        return (r1 + r2 + r4);
    }
    else if (r4 <= r1 && r4 <= r2 && r4 <= r3)
    {
        return (r1 + r2 + r3);
    }
    else
    {
        cout << "error in rolling function for 4d6 drop lowest";
        exit(-1);
    }
}

int rollstats_standard()
{
    int r1, r2, r3;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << endl;
    return (r1 + r2 + r3);
}

int randomNumber(const int &start, const int &end)
{
    std::uniform_int_distribution<int> totalroll(start, end);
    return totalroll(mgen);
}

int getAbilityMod(const int &ability)
{
    float tmp = (ability - 10) / 2;
    int mod = floor(tmp);
    return mod;
}
