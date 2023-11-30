#pragma once
#include <string>
#include <vector>
#include "RegistrationValidator.h"

class UserDatabase {
public:

    UserDatabase();
    ~UserDatabase();

    bool addUser(const std::string& firstName, const std::string& lastName,
        const std::string& email, const std::string& password);

    bool userExists(const std::string& email, const std::string& password) const;

private:
    struct UserData {
        std::string firstName;
        std::string lastName;
        std::string email;
        std::string password;
    };
    std::vector<UserData> users;

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};
