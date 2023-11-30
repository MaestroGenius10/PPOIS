#include "RegistrationValidator.h"
#include <regex>

bool RegistrationValidator::isValidPassword(const std::string& password) {

    if (password.length() < 8 || password.length() > 20) {
        return false;
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUpperCase = true;
        }
        else if (std::islower(ch)) {
            hasLowerCase = true;
        }
        else if (std::isdigit(ch)) {
            hasDigit = true;
        }
    }

    return hasUpperCase && hasLowerCase && hasDigit;
}

bool RegistrationValidator::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailRegex);
}