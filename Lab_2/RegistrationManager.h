#pragma once
#include "UserDatabase.h"
#include "RegistrationValidator.h"

class RegistrationManager {
public:

    RegistrationManager(UserDatabase& userDB);

    void startRegistration();

private:
    UserDatabase& userDB;

    void getUserData(std::string& firstName, std::string& lastName,
        std::string& email, std::string& password);

    bool validateRegistration(const std::string& email, const std::string& password);
};