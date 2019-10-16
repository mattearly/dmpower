#pragma once

class Charts
{
public:
  void showChartMenu();

private:
  int chart_choice = 0;
  void displayExperienceChart();
  void displayPoisonSalesChart();
  void displayDiseaseChart();
  void displayMadnessChart();
  void walkThroughPlayerBehavioralResolutionChart();
};
