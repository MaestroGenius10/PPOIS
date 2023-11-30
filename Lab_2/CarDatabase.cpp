#include "CarDatabase.h"
#include <iostream>
#include <fstream>

CarDatabase::CarDatabase(const std::string& filename) : filename(filename) {
    loadFromFile();
}

CarDatabase::~CarDatabase() {
    saveToFile();
}

void CarDatabase::addCar(const std::string& brand, const std::string& registrationNumber,
    const std::string colour, int capacity) {
    
    CarData newCar;
    newCar.brand = brand;
    newCar.registrationNumber = registrationNumber;
    newCar.colour = colour;
    newCar.capacity = capacity;
    cars.push_back(newCar);

    saveToFile();
}

const std::vector<CarData>& CarDatabase::getCars() const {
    return cars;
}

void CarDatabase::saveToFile() const {
    std::ofstream outFile(filename);

    for (const auto& car : cars) {
        outFile << car.brand << " " << car.registrationNumber << " "
            << car.colour << " " << car.capacity << "\n";
    }

    outFile.close();
}

bool CarDatabase::loadFromFile() {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return false;
    }

    cars.clear();

    while (inFile >> std::ws) {
        CarData car;
        inFile >> car.brand >> car.registrationNumber
            >> car.colour >> car.capacity;
        cars.push_back(car);
    }
    inFile.close();
}

void CarDatabase::displayAllCars() const {
    for (const auto& car : cars) {
        std::cout << "Brand: " << car.brand << "\n";
        std::cout << "Registration Number: " << car.registrationNumber << "\n";
        std::cout << "Colour: " << car.colour << "\n";
        std::cout << "Capacity: " << car.capacity << " passengers\n\n";
    }
}