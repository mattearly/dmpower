#include "charts.h"
#include "globalfuncts.h"

void Charts::displayExperienceChart()
{
    simpleClearScreen();
    std::cout << "Experience Required to Level\n\n"
         << "Level  EXP\n"
         << "------|--------\n"
         << " 2.    300\n"
         << " 3.    900\n"
         << " 4.    2,700\n"
         << " 5.    6,500\n"
         << " 6.    14,000\n"
         << " 7.    23,000\n"
         << " 8.    34,000\n"
         << " 9.    48,000\n"
         << "10.    64,000\n"
         << "11.    85,000\n"
         << "12.    100,000\n"
         << "13.    120,000\n"
         << "14.    140,000\n"
         << "15.    165,000\n"
         << "16.    195,000\n"
         << "17.    225,000\n"
         << "18.    265,000\n"
         << "19.    305,000\n"
         << "20.    355,000\n"
         << std::endl;
    pressEnterToContinue();
}
