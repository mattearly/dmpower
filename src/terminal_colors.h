#pragma once
#include <string>
#ifdef __unix__
// const std::string BLINK = "\e[5m";
// const std::string BOLD = "\e[1m";
const std::string RESET = "\e[0m";
// const std::string ERROR = "\e[1;41;37m\a";
// const std::string MENU = "\e[44;37m";
// const std::string BLACK = "\e[30m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";
const std::string YELLOW = "\e[33m";
const std::string BLUE = "\e[34m";
const std::string MAGENTA = "\e[35m";
const std::string CYAN = "\e[36m";
// const std::string WHITE = "\e[37m";
// const std::string B_BLACK = "\e[40m";
// const std::string B_RED = "\e[41m";
// const std::string B_GREEN = "\e[42m";
// const std::string B_YELLOW = "\e[43m";
// const std::string B_BLUE = "\e[44m";
// const std::string B_MAGENTA = "\e[45m";
// const std::string B_CYAN = "\e[46m";
// const std::string B_WHITE = "\e[47m";
#elif _WIN32
const std::string RESET = "";
const std::string RED = "";
const std::string GREEN = "";
const std::string YELLOW = "";
const std::string BLUE = "";
const std::string MAGENTA = "";
const std::string CYAN = "";
#endif
