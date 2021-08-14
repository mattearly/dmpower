#include "globalfuncts.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <stdexcept>

std::string lastSave;
bool is_random = false; // for the random character gen operation triggers
std::string buildNumber = "12"; // iterate with every new build release
std::string saveVersion = "9"; // oldest version the current saves work with
std::string mainMessage;
bool loadSuccess = false;
std::string loadedFile = "";
const std::string DATA_DIR = "./data/lists/";

Campaign myGame;
std::string insult_mode;
bool clearScreens = true;
bool autoSave = true;
bool autoLoad = true;

void simpleClearScreen() {
  for (int i = 0; i < 14; i++) // 14*5 is sufficient for most terminal sizes
  {
    std::cout << "\n\n\n\n\n";
  }
}

char getYorN(const std::string& message) {

  char tmp;

  if (is_random) {
    rolld6(mgen) < 4 ? tmp = 'Y' : tmp = 'N';  // for human Y/N on variant, Y if 1-3, N if 4-6
    return tmp;
  }

  do {
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

char getYorR(const std::string& message) {
  char tmp;
  do {
    std::cout << message;
    std::cin >> tmp;
    tmp = toupper(tmp);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!(tmp == 'Y' || tmp == 'R'))
      std::cout << "Invalid, Try again (only takes 'Y', 'R', 'y', or 'r'.\n";

  } while (!(tmp == 'Y' || tmp == 'R'));
  return tmp;
}

char getAorRorQ(const std::string& message) {

  if (is_random) {
    return 'A';
  }

  char tmp;
  do {
    std::cout << message;
    std::cin >> tmp;
    tmp = toupper(tmp);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!(tmp == 'A' || tmp == 'R' || tmp == 'Q')) {
      std::cout << "Invalid, Try again (Only accpets A/a/R/r/Q/q)\n";
    }
  } while (!(tmp == 'A' || tmp == 'R' || tmp == 'Q'));
  return tmp;
}

int rollstats_hi_power() {
  int r1, r2, r3, r4;
  r1 = rolld6(mgen);
  r2 = rolld6(mgen);
  r3 = rolld6(mgen);
  r4 = rolld6(mgen);
  int result, d6dropped;
  if (r1 <= r2 && r1 <= r3 && r1 <= r4) {
    d6dropped = r1;
    result = (r2 + r3 + r4);
  } else if (r2 <= r1 && r2 <= r3 && r2 <= r4) {
    d6dropped = r2;
    result = (r1 + r3 + r4);
  } else if (r3 <= r1 && r3 <= r2 && r3 <= r4) {
    d6dropped = r3;
    result = (r1 + r2 + r4);
  } else if (r4 <= r1 && r4 <= r2 && r4 <= r3) {
    d6dropped = r4;
    result = (r1 + r2 + r3);
  } else {
    std::cout << "error in rolling function for 4d6 drop lowest";
    exit(-1);
  }
  std::cout << "d6 rolls: " << r1 << ", " << r2 << ", " << r3 << ", " << r4 << " | dropped d6 roll: " << d6dropped << '\n';
  return result;
}

int rollstats_standard() {
  int r1, r2, r3;
  r1 = rolld6(mgen);
  r2 = rolld6(mgen);
  r3 = rolld6(mgen);
  std::cout << "d6 rolls: " << r1 << ", " << r2 << ", " << r3 << '\n';
  return (r1 + r2 + r3);
}

int randomNumber(const int& start, const int& end) {
  if (start >= end) {
    throw std::invalid_argument("start must be less end end.");
  }
  std::uniform_int_distribution<int> totalroll(start, end);
  return totalroll(mgen);
}

int getAbilityMod(const int& ability) {
  float tmp = floor((ability - 10) / 2.f);
  return static_cast<int>(tmp);
}

int getNumber(const std::string& message, const int& a, const int& b) {
  if (a >= b) {
    throw std::invalid_argument("a must be less than b");
  }
  if (a < 0 || b < 0) {
    throw std::invalid_argument("a and b must be positive");
  }

  if (is_random) {
    int rand_num = randomNumber(a, b);
    std::cout << message << rand_num << '\n';
    return rand_num;
  }

  bool tried_once = false;
  int user_input;
  std::string test;
  std::string numbers;

  do {
    user_input = -1;
    test.clear();
    numbers.clear();
    if (tried_once)
      std::cout << " --Invalid entry.\n";
    std::cout << message;
    std::getline(std::cin, test);
    if (test.size() > 0) {
      for (uint32_t i = 0; i < test.size(); i++) {
        if (isdigit(test[i])) {
          numbers += test[i];
        } else {
          break;
        }
      }
    } else {
      continue;
    }
    if (numbers.size() > 0 && numbers.size() <= LARGEST_INPUT_DIGITS) {
      user_input = std::stoi(numbers);
    }
    tried_once = true;
  } while (user_input < a || user_input > b);
  return user_input;
}

int getNumber(const int& a, const int& b) {
  if (a >= b) {
    throw std::invalid_argument("a must be less than b");
  }
  if (a < 0 || b < 0) {
    throw std::invalid_argument("a and b must be positive");
  }

  if (is_random) {
    int rand_num = randomNumber(a, b);
    return rand_num;
  }

  bool tried_once = false;
  int user_input;
  std::string test;
  std::string numbers;

  do {
    user_input = -1;
    test.clear();
    numbers.clear();
    if (tried_once)
      std::cout << " --Invalid entry.\n";
    std::cout << "Choice(" << a << "-" << b << "): ";
    std::getline(std::cin, test);
    if (test.size() > 0) {
      for (uint32_t i = 0; i < test.size(); i++) {
        if (isdigit(test[i])) {
          numbers += test[i];
        } else {
          break;
        }
      }
    } else {
      continue;
    }
    if (numbers.size() > 0 && numbers.size() <= LARGEST_INPUT_DIGITS) {
      user_input = std::stoi(numbers);
    }
  } while (user_input < a || user_input > b);
  return user_input;
}

int getNumberOrQ(const int& a, const int& b) {
  if (a >= b) {
    throw std::invalid_argument("a must be less than b");
  }
  if (a < 0 || b < 0) {
    throw std::invalid_argument("a and b must be positive");
  }

  if (is_random) {
    int rand_num = randomNumber(a, b);
    return rand_num;
  }

  bool tried_once = false;
  int user_input;
  std::string test;
  std::string numbers;

  do {
    user_input = -1;
    test.clear();
    numbers.clear();
    if (tried_once)
      std::cout << " --Invalid entry.\n";
    std::cout << "Choice(" << a << "-" << b << " or 'q' to quit): ";
    std::getline(std::cin, test);
    if (test.size() > 0) {
      if (test.compare("q") == 0) {
        return -1;
      }
      for (uint32_t i = 0; i < test.size(); i++) {
        if (isdigit(test[i])) {
          numbers += test[i];
        } else {
          break;
        }
      }
    } else {
      continue;
    }
    if (numbers.size() > 0 && numbers.size() <= LARGEST_INPUT_DIGITS) {
      user_input = std::stoi(numbers);
    }
  } while (user_input < a || user_input > b);
  return user_input;
}

void pressEnterToContinue() {
  std::cout << "\n\nPress 'ENTER' to continue.\n\n";
  std::string buf;
  std::getline(std::cin, buf);
}

std::string trim(const std::string& str,
  const std::string& whitespace) {
  const auto strBegin = str.find_first_not_of(whitespace);

  if (strBegin == std::string::npos)
    return ""; // no content

  const auto strEnd = str.find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;

  return str.substr(strBegin, strRange);
}

std::string reduce(const std::string& str,
  const std::string& fill,
  const std::string& whitespace) {
  // trim first
  auto result = trim(str, whitespace);

  // replace sub ranges
  auto beginSpace = result.find_first_of(whitespace);
  while (beginSpace != std::string::npos) {
    const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
    const auto range = endSpace - beginSpace;

    result.replace(beginSpace, range, fill);

    const auto newStart = beginSpace + fill.length();
    beginSpace = result.find_first_of(whitespace, newStart);
  }
  return result;
}
