//
//  globalfuncts.h
//  DM-Power
//
//  Created by Matthew Early on 6/22/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#ifndef __dm_power_poly__globalfuncts__
#define __dm_power_poly__globalfuncts__

#include <iostream>
#include <sstream>
#include <random>
#include <type_traits>
#include "colors.h"

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

    // getNumber with a message variable first
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

    // getNumber without a message variable
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

void simpleClearScreen();

char getYorN(const std::string&);

void pressEnterToContinue();

int rollstats_hi_power();

int rollstats_standard();

#endif /* defined(__dm_power_poly__globalfuncts__) */
