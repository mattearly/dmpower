//
//  globalfuncts.cpp
//  DM-Power
//
//  Created by Matthew Early on 6/22/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#include "globalfuncts.h"
using namespace std;


void simpleClearScreen() {
    for (int i=0; i < 14; i++) {
        std::cout << "\n\n\n\n\n";
    }
}

char getYorN(const std::string& message) {
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

void pressEnterToContinue() {
    std::cin.clear();
    std::cout << "\nPress 'ENTER' to continue.\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}


int rollstats_hi_power() {
    int r1, r2, r3, r4;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    r4 = rolld6(mgen);
    cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << ", " << r4 << endl;
    if (r1 <= r2 && r1 <= r3 && r1 <= r4) {
        return (r2 + r3 + r4);
    }
    else if (r2 <= r1 && r2 <= r3 && r2 <= r4) {
        return (r1 + r3 + r4);
    }
    else if (r3 <= r1 && r3 <= r2 && r3 <= r4) {
        return (r1 + r2 + r4);
    }
    else if (r4 <= r1 && r4 <= r2 && r4 <= r3) {
        return (r1 + r2 + r3);
    }
    else {
        cout << "error in rolling function for 4d6 drop lowest";
        exit(-1);
    }
}

int rollstats_standard() {
    int r1, r2, r3;
    r1 = rolld6(mgen);
    r2 = rolld6(mgen);
    r3 = rolld6(mgen);
    cout << "Rolls: " << r1 << ", " << r2 << ", " << r3 << endl;
    return (r1 + r2 + r3);
}

int randomNumber(const int& start, const int& end) {
    std::uniform_int_distribution<int> totalroll(start, end);
    return totalroll(mgen);
}

float xpgenerator() {
    float xp = 0;
    int cr = 0;
    char ans;
    cout << "\nA Reference Level Chart (FYI):\n\n"
         << " 2. 300\n"
         << " 3. 900\n"
         << " 4. 2,700\n"
         << " 5. 6,500\n"
         << " 6. 14,000\n"
         << " 7. 23,000\n"
         << " 8. 34,000\n"
         << " 9. 48,000\n"
         << "10. 64,000\n"
         << "11. 85,000\n"
         << "12. 100,000\n"
         << "13. 120,000\n"
         << "14. 140,000\n"
         << "15. 165,000\n"
         << "16. 195,000\n"
         << "17. 225,000\n"
         << "18. 265,000\n"
         << "19. 305,000\n"
         << "20. 355,000\n\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    pressEnterToContinue();
    do {
        cout << "Challenge Rating Chart\n\n"
             << " 1. CR 0      18. CR 14\n"
             << " 2. CR 1/8    19. CR 15\n"
             << " 3. CR 1/4    20. CR 16\n"
             << " 4. CR 1/2    21. CR 17\n"
             << " 5. CR 1      22. CR 18\n"
             << " 6. CR 2      23. CR 19\n"
             << " 7. CR 3      24. CR 20\n"
             << " 8. CR 4      25. CR 21\n"
             << " 9. CR 5      26. CR 22\n"
             << "10. CR 6      27. CR 23\n"
             << "11. CR 7      28. CR 24\n"
             << "12. CR 8      29. CR 25\n"
             << "13. CR 9      30. CR 26\n"
             << "14. CR 10     31. CR 27\n"
             << "15. CR 11     32. CR 28\n"
             << "16. CR 12     33. CR 29\n"
             << "17. CR 13     34. CR 30\n\n"
             << " tip: add 'y' after your choice to continue picking.(ex: 9y)\n\n";
        cr = getNumber("Choose CR by the chart(1-34)", 1, 34);
        switch (cr) {
        case 1:
            xp += 10;
            break;
        case 2:
            xp += 25;
            break;
        case 3:
            xp += 50;
            break;
        case 4:
            xp += 100;
            break;
        case 5:
            xp += 200;
            break;
        case 6:
            xp += 450;
            break;
        case 7:
            xp += 700;
            break;
        case 8:
            xp += 1100;
            break;
        case 9:
            xp += 1800;
            break;
        case 10:
            xp += 2300;
            break;
        case 11:
            xp += 2900;
            break;
        case 12:
            xp += 3900;
            break;
        case 13:
            xp += 5000;
            break;
        case 14:
            xp += 5900;
            break;
        case 15:
            xp += 7200;
            break;
        case 16:
            xp += 8400;
            break;
        case 17:
            xp += 10000;
            break;
        case 18:
            xp += 11500;
            break;
        case 19:
            xp += 13000;
            break;
        case 20:
            xp += 15000;
            break;
        case 21:
            xp += 18000;
            break;
        case 22:
            xp += 20000;
            break;
        case 23:
            xp += 22000;
            break;
        case 24:
            xp += 25000;
            break;
        case 25:
            xp += 33000;
            break;
        case 26:
            xp += 41000;
            break;
        case 27:
            xp += 50000;
            break;
        case 28:
            xp += 62000;
            break;
        case 29:
            xp += 75000;
            break;
        case 30:
            xp += 90000;
            break;
        case 31:
            xp += 105000;
            break;
        case 32:
            xp += 120000;
            break;
        case 33:
            xp += 135000;
            break;
        case 34:
            xp += 155000;
        default:break;
        }
        ans = getYorN("Are there more to add(Y/N)?");
    } while (ans == 'Y');
    int party = getNumber("Split between how many party members?(1-10)", 1, 10);
    return (xp /= party);
}
