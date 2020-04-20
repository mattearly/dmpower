#include "gen_experience.h"
#include "globalfuncts.h"
#include "terminal_colors.h"

using namespace std;

float Gen_Experience::xpgenerator()
{
  float total = 0.0;
  int selected_rating = 0;
  vector<string> crlist;
  char ans;
  do
  {
    if (clearScreens) simpleClearScreen();
    cout << "****EXPERIENCE GENERATOR****\n\n";
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
         << "  TIP: add 'y' after your choice to continue picking.(ex: 9y)\n"
         << "       or add 'n' after your choice if it is the last one. (ex: 5n)\n\n"
         << "CRs so far: ";
    for (auto i : crlist)
    {
      cout << GREEN << i << RESET << ", ";
    }
    cout << "\nTotal unsplit so far: " << GREEN << total << RESET << " total" << '\n';
    cout << '\n';
    selected_rating = getNumber("Choose CR by the chart(1-34): ", 1, 34);
    switch (selected_rating)
    {
    case 1:
      total += 10;
      crlist.push_back("0");
      break;
    case 2:
      total += 25;
      crlist.push_back("1/8");
      break;
    case 3:
      total += 50;
      crlist.push_back("1/4");
      break;
    case 4:
      total += 100;
      crlist.push_back("1/2");
      break;
    case 5:
      total += 200;
      crlist.push_back("1");
      break;
    case 6:
      total += 450;
      crlist.push_back("2");
      break;
    case 7:
      total += 700;
      crlist.push_back("3");
      break;
    case 8:
      total += 1100;
      crlist.push_back("4");
      break;
    case 9:
      total += 1800;
      crlist.push_back("5");
      break;
    case 10:
      total += 2300;
      crlist.push_back("6");
      break;
    case 11:
      total += 2900;
      crlist.push_back("7");
      break;
    case 12:
      total += 3900;
      crlist.push_back("8");
      break;
    case 13:
      total += 5000;
      crlist.push_back("9");
      break;
    case 14:
      total += 5900;
      crlist.push_back("10");
      break;
    case 15:
      total += 7200;
      crlist.push_back("11");
      break;
    case 16:
      total += 8400;
      crlist.push_back("12");
      break;
    case 17:
      total += 10000;
      crlist.push_back("13");
      break;
    case 18:
      total += 11500;
      crlist.push_back("14");
      break;
    case 19:
      total += 13000;
      crlist.push_back("15");
      break;
    case 20:
      total += 15000;
      crlist.push_back("16");
      break;
    case 21:
      total += 18000;
      crlist.push_back("17");
      break;
    case 22:
      total += 20000;
      crlist.push_back("18");
      break;
    case 23:
      total += 22000;
      crlist.push_back("19");
      break;
    case 24:
      total += 25000;
      crlist.push_back("20");
      break;
    case 25:
      total += 33000;
      crlist.push_back("21");
      break;
    case 26:
      total += 41000;
      crlist.push_back("22");
      break;
    case 27:
      total += 50000;
      crlist.push_back("23");
      break;
    case 28:
      total += 62000;
      crlist.push_back("24");
      break;
    case 29:
      total += 75000;
      crlist.push_back("25");
      break;
    case 30:
      total += 90000;
      crlist.push_back("26");
      break;
    case 31:
      total += 105000;
      crlist.push_back("27");
      break;
    case 32:
      total += 120000;
      crlist.push_back("28");
      break;
    case 33:
      total += 135000;
      crlist.push_back("29");
      break;
    case 34:
      total += 155000;
      crlist.push_back("30");
    default:
      break;
    }
    cout << "\nTotal unsplit so far: " << GREEN << total << RESET << " total" << '\n';
    cout << "CRs so far: ";
    for (auto i : crlist)
    {
      cout << GREEN << i << RESET << ", ";
    }
    cout << "\n\n";
    ans = getYorN("Are there more to add(Y/N)?");
  } while (ans == 'Y');
  int party = getNumber("\nSplit between how many party members?(max=10): ", 1, 10);
  if (clearScreens) simpleClearScreen();
  return (total / party);
}
