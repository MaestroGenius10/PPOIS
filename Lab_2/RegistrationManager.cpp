#include "RegistrationManager.h"
#include <iostream>

RegistrationManager::RegistrationManager(UserDatabase& userDB) : userDB(userDB) {}

void RegistrationManager::startRegistration() {
    std::string firstName, lastName, email, password;

    getUserData(firstName, lastName, email, password);

    while (!validateRegistration(email, password)) {
        std::cerr << "Error: Invalid email or password. Please try again.\n";

        getUserData(firstName, lastName, email, password);
    }

    if (userDB.addUser(firstName, lastName, email, password)) {
        std::cout << "Registration successful. Welcome, " << firstName << " " << lastName << "!\n";
    }
    else {
        std::cerr << "Error: Registration failed. User with this email already exists.\n";
    }
}

void RegistrationManager::getUserData(std::string& firstName, std::string& lastName,
    std::string& email, std::string& password) {
    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::cout << "Enter your email: ";
    std::cin >> email;

    std::cout << "Enter your password: ";
    std::cin >> password;
}

bool RegistrationManager::validateRegistration(const std::string& email, const std::string& password) {
    return RegistrationValidator::isValidEmail(email) && RegistrationValidator::isValidPassword(password);
}