#pragma once
#include <string>

class RegistrationValidator {
public:

    static bool isValidPassword(const std::string& password);

    static bool isValidEmail(const std::string& email);
};