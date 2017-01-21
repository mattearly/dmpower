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



#ifndef __dm_power_poly__globalfuncts__
#define __dm_power_poly__globalfuncts__

#include <iostream>
#include <sstream>
#include <random>
#include <type_traits>

const std::string BLINK     = "\e[5m";
const std::string BOLD      = "\e[1m";

const std::string RESET     = "\e[0m";
const std::string ERROR     = "\e[1;41;37m\a";
const std::string MENU       = "\e[44;37m";

const std::string BLACK      = "\e[30m";
const std::string RED        = "\e[31m";
const std::string GREEN      = "\e[32m";
const std::string YELLOW     = "\e[33m";
const std::string BLUE       = "\e[34m";
const std::string MAGENTA    = "\e[35m";
const std::string CYAN       = "\e[36m";
const std::string WHITE      = "\e[37m";

const std::string B_BLACK    = "\e[40m";
const std::string B_RED      = "\e[41m";
const std::string B_GREEN   = "\e[42m";
const std::string B_YELLOW  = "\e[43m";
const std::string B_BLUE    = "\e[44m";
const std::string B_MAGENTA = "\e[45m";
const std::string B_CYAN    = "\e[46m";
const std::string B_WHITE   = "\e[47m";

static std::random_device rgen;
static std::mt19937 mgen(rgen());
static std::uniform_int_distribution<int> rolld4(1, 4);
static std::uniform_int_distribution<int> rolld6(1, 6);
static std::uniform_int_distribution<int> rolld8(1, 8);
static std::uniform_int_distribution<int> rolld10(1, 10);
static std::uniform_int_distribution<int> rolld12(1, 12);
static std::uniform_int_distribution<int> rolld20(1, 20);
static std::uniform_int_distribution<int> rolld100(1, 100);

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string toString(const T& a) {
	std::string tmp = "";
	std::stringstream stringconverter;
	stringconverter << a;
	tmp += stringconverter.str();
	return tmp;
};

int randomNumber(const int&, const int&);

/// This version of getNumber takes a string as an console message to the user as well as a lower and higher limit
template<class T>
T getNumber(const std::string& message, const T& a, const T& b) {
    T goodn = 0;
    while ((std::cout << message && !(std::cin >> goodn)) || (goodn < a || goodn > b)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid, try again.\n";
    }
    return goodn;
};

/// This version of getNumber takes a lower and higher limit
template<class T>
T getNumber(const T& a, const T& b) {
    T goodn = 0;
    while (!(std::cin >> goodn) || (goodn < a || goodn > b)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid, try again.\n";
    }
    return goodn;
};

template<class T>
std::string D_D_Ability_Modifier(const T& a) {
    std::string tmp = "";
    int mod = ((a-10)/2);
    if (mod > 0) {
        tmp += "+";
		tmp += toString(mod);
    }
    if (mod <= 0) {
        if (a < 10 && a%2 == 1) { mod--; }
        if (mod < 0) {
			tmp += toString(mod);
        } else {
            tmp = "  ";
        }
    }
    return tmp;
};

int getAbilityMod(const int&);

void simpleClearScreen();

char getYorN(const std::string&);

void pressEnterToContinue();

int rollstats_hi_power();

int rollstats_standard();

#endif /* defined(__dm_power_poly__globalfuncts__) */
