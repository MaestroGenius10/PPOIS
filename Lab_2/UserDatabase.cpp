#include "UserDatabase.h"
#include <iostream>
#include <fstream>
#include "RegistrationValidator.h"

UserDatabase::UserDatabase() {
    loadFromFile("user_data.txt");
}

bool UserDatabase::addUser(const std::string& firstName, const std::string& lastName,
    const std::string& email, const std::string& password) {
    auto existingUser = std::find_if(users.begin(), users.end(),
        [&email](const UserData& user) {
            return user.email == email;
        });

    if (existingUser != users.end()) {
        std::cerr << "Error: User with this email already exists.\n";
        return false;
    }

    if (!RegistrationValidator::isValidEmail(email)) {
        std::cerr << "Error: Invalid email address.\n";
        return false;
    }

    if (!RegistrationValidator::isValidPassword(password)) {
        std::cerr << "Error: Invalid password. Password must be 8-20 characters, contain uppercase and lowercase letters, and digits.\n";
        return false;
    }

    UserData newUser;
    newUser.firstName = firstName;
    newUser.lastName = lastName;
    newUser.email = email;
    newUser.password = password;

    users.push_back(newUser);

    saveToFile("user_data.txt");

    return true;
}

bool UserDatabase::userExists(const std::string& email, const std::string& password) const {

    auto user = std::find_if(users.begin(), users.end(),
        [&email, &password](const UserData& userData) {
            return userData.email == email && userData.password == password;
        });

    return user != users.end();
}

bool UserDatabase::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return false;
    }

    for (const auto& user : users) {
        outFile << user.firstName << " "
            << user.lastName << " "
            << user.email << " "
            << user.password << "\n";
    }

    outFile.close();
    return true;
}

bool UserDatabase::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Warning: Unable to open file for reading. Using default data." << std::endl;
        return false;
    }

    users.clear();

    while (inFile >> std::ws) {
        UserData user;
        inFile >> user.firstName
            >> user.lastName
            >> user.email
            >> user.password;

        if (inFile.fail()) {

            std::cerr << "Error: Failed to read data from file." << std::endl;
            inFile.close();
            return false;
        }

        users.push_back(user);
    }

    inFile.close();
    return true;
}

UserDatabase::~UserDatabase() {
    saveToFile("user_data.txt");
}