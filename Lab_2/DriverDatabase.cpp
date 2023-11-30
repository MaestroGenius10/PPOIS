#include "DriverDatabase.h"
#include <iostream>
#include <fstream>
#include <iomanip>

DriverDatabase::DriverDatabase(const std::string& filename) : filename(filename) {
    loadFromFile();
}

DriverDatabase::~DriverDatabase() {
    saveToFile();
}
bool DriverDatabase::addDriver(const std::string& firstName, const std::string& lastName,
    const std::string& phoneNumber, int rating) {

    DriverData newDriver;
    newDriver.firstName = firstName;
    newDriver.lastName = lastName;
    newDriver.phoneNumber = phoneNumber;
    newDriver.rating = rating;

    drivers.push_back(newDriver);
    saveToFile();
    return true;
}

const std::vector<DriverData>& DriverDatabase::getDrivers() const {
    return drivers;
}


bool DriverDatabase::saveToFile() const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return false;
    }

    for (const auto& driver : drivers) {
        outFile << driver.firstName << " "
            << driver.lastName << " "
            << driver.phoneNumber << " "
            << driver.rating << "\n";
    }

    outFile.close();
}

bool DriverDatabase::loadFromFile() {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Warning: Unable to open file for reading." << std::endl;
        return false;
    }

    drivers.clear();

    while (inFile >> std::ws) {
        DriverData driver;
        inFile >> driver.firstName
            >> driver.lastName
            >> driver.phoneNumber
            >> driver.rating;

        drivers.push_back(driver);
    }
    inFile.close();
}


void DriverDatabase::displayAllDrivers() const {
    for (const auto& driver : drivers) {
        std::cout << "Name: " << driver.firstName << " " << driver.lastName << "\n";
        std::cout << "Phone Number: " << driver.phoneNumber << "\n";
        std::cout << "Rating: " << driver.rating << "\n\n";
    }
}