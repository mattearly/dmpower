#include "gen_experience.h"
#include "globalfuncts.h"
// #include <vector>
// #include <string>
// #include <iostream>

using namespace std;

float Gen_Experience::xpgenerator() {
    float xp = 0;
    int cr = 0;
    vector<string> crlist;
    char ans;
    cout << "A Reference Level Chart (FYI):\n\n"
         << "CR    EXP\n"
         << "---|--------"
         << "1/2   100\n"
         << " 1.   200\n"
         << " 2.   300\n"
         << " 3.   900\n"
         << " 4.   2,700\n"
         << " 5.   6,500\n"
         << " 6.   14,000\n"
         << " 7.   23,000\n"
         << " 8.   34,000\n"
         << " 9.   48,000\n"
         << "10.   64,000\n"
         << "11.   85,000\n"
         << "12.   100,000\n"
         << "13.   120,000\n"
         << "14.   140,000\n"
         << "15.   165,000\n"
         << "16.   195,000\n"
         << "17.   225,000\n"
         << "18.   265,000\n"
         << "19.   305,000\n"
         << "20.   355,000\n" << endl;
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
             << " tip: add 'y' after your choice to continue picking.(ex: 9y)\n"
             << "CRs so far: ";
        for (auto i : crlist) {
            cout << i << ", ";
        }
        cout << endl;
        cr = getNumber("Choose CR by the chart(1-34): ", 1, 34);
        switch (cr) {
        case 1:
            xp += 10;
            crlist.push_back("0");
            break;
        case 2:
            xp += 25;
            crlist.push_back("1/8");
            break;
        case 3:
            xp += 50;
            crlist.push_back("1/4");
            break;
        case 4:
            xp += 100;
            crlist.push_back("1/2");
            break;
        case 5:
            xp += 200;
            crlist.push_back("1");
            break;
        case 6:
            xp += 450;
            crlist.push_back("2");
            break;
        case 7:
            xp += 700;
            crlist.push_back("3");
            break;
        case 8:
            xp += 1100;
            crlist.push_back("4");
            break;
        case 9:
            xp += 1800;
            crlist.push_back("5");
            break;
        case 10:
            xp += 2300;
            crlist.push_back("6");
            break;
        case 11:
            xp += 2900;
            crlist.push_back("7");
            break;
        case 12:
            xp += 3900;
            crlist.push_back("8");
            break;
        case 13:
            xp += 5000;
            crlist.push_back("9");
            break;
        case 14:
            xp += 5900;
            crlist.push_back("10");
            break;
        case 15:
            xp += 7200;
            crlist.push_back("11");
            break;
        case 16:
            xp += 8400;
            crlist.push_back("12");
            break;
        case 17:
            xp += 10000;
            crlist.push_back("13");
            break;
        case 18:
            xp += 11500;
            crlist.push_back("14");
            break;
        case 19:
            xp += 13000;
            crlist.push_back("15");
            break;
        case 20:
            xp += 15000;
            crlist.push_back("16");
            break;
        case 21:
            xp += 18000;
            crlist.push_back("17");
            break;
        case 22:
            xp += 20000;
            crlist.push_back("18");
            break;
        case 23:
            xp += 22000;
            crlist.push_back("19");
            break;
        case 24:
            xp += 25000;
            crlist.push_back("20");
            break;
        case 25:
            xp += 33000;
            crlist.push_back("21");
            break;
        case 26:
            xp += 41000;
            crlist.push_back("22");
            break;
        case 27:
            xp += 50000;
            crlist.push_back("23");
            break;
        case 28:
            xp += 62000;
            crlist.push_back("24");
            break;
        case 29:
            xp += 75000;
            crlist.push_back("25");
            break;
        case 30:
            xp += 90000;
            crlist.push_back("26");
            break;
        case 31:
            xp += 105000;
            crlist.push_back("27");
            break;
        case 32:
            xp += 120000;
            crlist.push_back("28");
            break;
        case 33:
            xp += 135000;
            crlist.push_back("29");
            break;
        case 34:
            xp += 155000;
            crlist.push_back("30");
        default:break;
        }
        cout << "Total unsplit so far: " << xp << "xp" << endl;
        ans = getYorN("Are there more to add(Y/N)?");
    } while (ans == 'Y');
    int party = getNumber("Split between how many party members?(max=20)", 1, 20);
    return (xp /= party);
}