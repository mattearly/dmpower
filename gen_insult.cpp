#include "gen_insult.h"
#include "globalfuncts.h"
#include <fstream>
using namespace std;

Insult::Insult()
{
}

string Insult::laydownheat() const {
	string heatstring = "error: check code or insult data file";
	ifstream madfile;
	madfile.open("insults.dat");
	if (madfile.is_open()) {
		string tmpName = "";
//		bool setvalue = false;
		auto chosenSeed = 0;
		chosenSeed = randomNumber(0, 5);
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		for (auto i = 0; i < chosenSeed; i++) { //go over to the proper noun rolled based on seed
			madfile.ignore(numeric_limits<streamsize>::max(), ';');
		}
		getline(madfile, tmpName, ';');
		heatstring = tmpName;
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		chosenSeed = randomNumber(0, 8);
		for (auto i = 0; i < chosenSeed; i++) { //go over to the proper adverb rolled based on seed
			madfile.ignore(numeric_limits<streamsize>::max(), ';');
		}
		getline(madfile, tmpName, ';');
		heatstring += tmpName;
	}
	if (madfile.is_open()) madfile.close();
	return heatstring;


//		for (int i = 0; i < amount; i++) {  //go down into file appropriate amount
//			if (value == 10) {
//				chosenSeed = randomNumber(0, 11);
//				if (!setvalue) {
//					fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//				}
//			}
//			else if (value == 50) {
//				chosenSeed = randomNumber(0, 16);
//				if (!setvalue) {
//					for (int j = 0; j < 3; j++) {
//						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//					}
//				}
//			} else if (value == 100) {
//				chosenSeed = randomNumber(0, 15);
//				if (!setvalue) {
//					for (int j = 0; j < 5; j++) {
//						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//					}
//				}
//			} else if (value == 500) {
//				chosenSeed = randomNumber(0, 5);
//				if (!setvalue) {
//					for (int j = 0; j < 7; j++) {
//						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//					}
//				}
//			} else if (value == 1000) {
//				chosenSeed = randomNumber(0, 9);
//				if (!setvalue) {
//					for (int j = 0; j < 9; j++) {
//						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//					}
//				}
//			} else if (value == 5000) {
//				chosenSeed = randomNumber(0, 6);
//				if (!setvalue) {
//					for (int j = 0; j < 11; j++) {
//						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
//					}
//				}
//			}

//			setvalue = true;
//			int len = fileOfGems.tellg();   //get current position - snapshot of place in file
//			for (auto i = 0; i < chosenSeed; i++) { //go over to the proper gem rolled based on seed
//				fileOfGems.ignore(numeric_limits<streamsize>::max(), ';');
//			}
//			getline(fileOfGems, tmpName, ';');
//			fileOfGems.seekg(len, ios_base::beg);  //return to position - return to snapshot of place in file
//			if (i == 0) {           //very first gem case
//				gemstring = (boost::lexical_cast<string>(value) + "gp Gems:" + tmpName);
//			} else {
//				size_t find_position = gemstring.find(tmpName + ",");
//				if (find_position != string::npos) { //found first duplicate gemname on the list - not last item either
//					gemstring.insert(find_position+tmpName.size(), " x2");
//				} else {
//					find_position = gemstring.find(tmpName);
//					if (find_position == string::npos) {
//						gemstring += ("," + tmpName); //add the new gem
//					} else {
//						if (gemstring.substr(find_position, tmpName.length()+3) == tmpName) {
//							gemstring.insert(find_position+tmpName.length(), " x2");
//						} else {
//							size_t gotx2 = gemstring.find(tmpName + " x2");
//							if (gotx2 != string::npos) {   //if x2 exists
//								gemstring.replace(gotx2+tmpName.size(), 3, " x3");
//							} else {
//								size_t gotx3 = gemstring.find(tmpName + " x3");
//								if (gotx3 != string::npos) {  //if x3 exists
//									gemstring.replace(gotx3+tmpName.size(), 3, " x4");
//								} else {
//									size_t gotx4 = gemstring.find(tmpName + " x4");
//									if (gotx4 != string::npos) { //if x4 exists
//										gemstring.replace(gotx4+tmpName.size(), 3, " x5");
//									} else {
//										gemstring.insert(find_position+tmpName.size(), " x2");
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return gemstring;
}
