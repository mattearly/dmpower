#include "charts.h"
#include "globalfuncts.h"
#include <fstream>

using namespace std;

void Charts::showChartMenu()
{
    while (chart_choice != 5)
    {
        cout
            << "1. Level Up Chart" << endl
            << "2. Poison Sales Chart" << endl
            << "3. Madness Chart" << endl
            << "4. Disease Chart" << endl
            << "5. Back to Main Menu" << endl;
        chart_choice = getNumber("Choose: ", 1, 5);
        simpleClearScreen();
        switch (chart_choice)
        {
        case 1:
            displayExperienceChart();
            break;
        case 2:
            displayPoisonSalesChart();
            break;
        case 3:
            displayMadnessChart();
            break;
        case 4:
            displayDiseaseChart();
            break;
        case 5:
            return;
        default:
            break;
        }
        pressEnterToContinue();
    }
}

void Charts::displayExperienceChart()
{
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
}

void Charts::displayPoisonSalesChart()
{
    fstream poisonfile;
    poisonfile.open("./settings/poisonlist.dat");
    if (!poisonfile.is_open())
    {
        cout << "Error Opening poisonlist.dat, check your file.\n\n";
    }
    string poisons = "";
    if (poisonfile.is_open())
    {
        while (!poisonfile.eof())
        {
            poisons += poisonfile.get();
        }
    }
    poisons.erase(poisons.length() - 1, poisons.length()); //erase that last random [box] character
    cout << poisons;
    poisonfile.close();
}

void Charts::displayDiseaseChart()
{
    fstream diseasefile;
    diseasefile.open("./settings/diseaselist.dat");
    if (!diseasefile.is_open())
    {
        cout << "Error Opening diseaselist.dat, check your file.\n\n";
    }
    else
    {
        string diseases = "";
        if (diseasefile.is_open())
        {
            while (!diseasefile.eof())
            {
                diseases += diseasefile.get();
            }
        }
        diseases.erase(diseases.length() - 1, diseases.length()); //erase that last random [box] character
        cout << diseases;
        diseasefile.close();
    }
}

void Charts::displayMadnessChart()
{
    fstream madnessfile;
    madnessfile.open("./settings/madnesslist.dat");
    if (!madnessfile.is_open())
    {
        cout << "Error Opening madnesslist.dat, check your file.\n\n";
    }
    string madness = "";
    if (madnessfile.is_open())
    {
        while (!madnessfile.eof())
        {
            madness += madnessfile.get();
        }
    }
    madness.erase(madness.length() - 1, madness.length()); //erase that last random [box] character
    cout << madness;
    madnessfile.close();
}
