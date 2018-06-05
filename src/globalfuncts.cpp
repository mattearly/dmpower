/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include <iomanip>
#include "globalfuncts.h"
#include <cmath>

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

int rollstats_hi_power()
{
    int r1, r2, r3, r4;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    r4 = rolld6(mgen);
    std::cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << ", " << r4 << std::endl;
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
        std::cout << "error in rolling function for 4d6 drop lowest";
        exit(-1);
    }
}

int rollstats_standard()
{
    int r1, r2, r3;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    std::cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << std::endl;
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

/// getNumber provides a 'message' to the user via console and 
/// continues prompting for a integer 'user_input' such that  'a <= user_input <= b' 
/// doesn't work with negative numbers as -1 is the flag for certainly invalid input
int getNumber(const std::string &message, const int &a, const int &b)
{
    int user_input;
    std::string test;
    std::string numbers;

    do {
        user_input = -1;
        std::cout << message;
        std::getline(std::cin, test);
        for (int i = 0; i < test.size(); i++) {
            if (isdigit(test[i])) {
                numbers += test[i];
            } else {
                break;
            }
        }
        user_input = std::stoi(numbers);
    } while (user_input < a || user_input > b);

    return user_input;
}

/// continues prompting for a integer 'user_input' such that  'a <= user_input <= b'
/// doesn't work with negative numbers as -1 is the flag for certainly invalid input
int getNumber(const int &a, const int &b)
{
    int user_input;
    std::string test;
    std::string numbers;

    do {
        user_input = -1;
        std::getline(std::cin, test);
        for (int i = 0; i < test.size(); i++) {
            if (isdigit(test[i])) {
                numbers += test[i];
            } else {
                break;
            }
        }
        user_input = std::stoi(numbers);

    } while (user_input < a || user_input > b);

    return user_input;
}

void pressEnterToContinue()
{
    // std::cin.clear();
    // if ((std::cin >> std::ws).peek() == '\n') { std::cin.ignore(100, '\n');  }
    std::cout << std::endl;
    std::cout << "\nPress 'ENTER' to continue.\n\n";
    std::string buf;
    std::getline(std::cin, buf);
}

