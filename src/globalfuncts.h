#ifndef GLOBALFUNCTS_H
#define GLOBALFUNCTS_H
#pragma once

#include <iostream>
#include <sstream>
#include <random>
#include <type_traits>
#include "terminal_colors.h"

static std::random_device rgen;
static std::mt19937 mgen(rgen());
static std::uniform_int_distribution<int> rolld4(1, 4);
static std::uniform_int_distribution<int> rolld6(1, 6);
static std::uniform_int_distribution<int> rolld8(1, 8);
static std::uniform_int_distribution<int> rolld10(1, 10);
static std::uniform_int_distribution<int> rolld12(1, 12);
static std::uniform_int_distribution<int> rolld20(1, 20);
static std::uniform_int_distribution<int> rolld100(1, 100);

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string toString(const T &a)
{
    std::string tmp = "";
    std::stringstream stringconverter;
    stringconverter << a;
    tmp += stringconverter.str();
    return tmp;
}

int randomNumber(const int &, const int &);

int getNumber(const std::string &message, const int &a, const int &b);

int getNumber(const int &a, const int &b);

template <class T>
std::string D_D_Ability_Modifier(const T &a)
{
    std::string tmp = "";
    int mod = ((a - 10) / 2);
    if (mod > 0)
    {
        tmp += "+";
        tmp += toString(mod);
    }
    if (mod <= 0)
    {
        if (a < 10 && a % 2 == 1)
        {
            mod--;
        }
        if (mod < 0)
        {
            tmp += toString(mod);
        }
        else
        {
            tmp = "  ";
        }
    }
    return tmp;
}

int getAbilityMod(const int &);

void simpleClearScreen();

char getYorN(const std::string &);

void pressEnterToContinue();

int rollstats_hi_power();

int rollstats_standard();

//Trims whitespace - from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string trim(const std::string &str, const std::string &whitespace = " \t");

//Reduces whitespace - from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string reduce(const std::string &str,
                   const std::string &fill = " ",
                   const std::string &whitespace = " \t");

#endif /* defined(GLOBALFUNCTS_H) */
