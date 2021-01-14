#include "inputregex.h"
#include <regex>

bool checkUsernameRegex(std::string &input) {
    if (std::regex_match(input, std::regex("^[a-zA-Z][a-zA-Z_0-9]*$"))) {
        return true;
    }
    return false;
}

bool checkPasswordRegex(std::string &input) {
    if (std::regex_match(input, std::regex("^[a-zA-Z][a-zA-Z_0-9]*$"))) {
        return true;
    }
    return false;
}

bool checkEmailRegex(std::string &input) {
    if (std::regex_match(input, std::regex("^[a-zA-Z][a-zA-Z_0-9]*@[a-zA-Z]*[.]\\b[a-zA-Z]*$"))) {       
        return true;
    }
    return false;
}
