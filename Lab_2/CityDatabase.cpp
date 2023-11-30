#include "CityDatabase.h"
#include <iostream>
#include <fstream>

CityDatabase::CityDatabase(const std::string& filename) : filename(filename) {
    loadFromFile();
}

bool CityDatabase::addCity(const std::string& cityName, const std::string& departureTime,
    const std::string& arrivalTime, double tripDuration, double tripCost,
    const std::string& departureDate) {

    CityData newCity;
    newCity.cityName = cityName;
    newCity.departureTime = departureTime;
    newCity.arrivalTime = arrivalTime;
    newCity.tripDuration = tripDuration;
    newCity.tripCost = tripCost;
    newCity.departureDate = departureDate;

    cities.push_back(newCity);
    saveToFile();
    return true;
}

const std::vector<CityData>& CityDatabase::getCities() const {
    return cities;
}

bool CityDatabase::saveToFile() const {
    std::ofstream outFile(filename);

    for (const auto& city : cities) {
        outFile << city.cityName << " "
            << city.departureTime << " "
            << city.arrivalTime << " "
            << city.tripDuration << " "
            << city.tripCost << " "
            << city.departureDate << "\n";
    }

    outFile.close();
    return true;
}

bool CityDatabase::loadFromFile() {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Warning: Unable to open file for reading. Using default data." << std::endl;
    }

    cities.clear();

    while (inFile >> std::ws) {
        CityData city;
        inFile >> city.cityName
            >> city.departureTime
            >> city.arrivalTime
            >> city.tripDuration
            >> city.tripCost
            >> city.departureDate;

        cities.push_back(city);
    }
    inFile.close();
    return true;
}

CityDatabase::~CityDatabase() {
    saveToFile();
}

void CityDatabase::displayAllCities() const {
    for (const auto& city : cities) {
        std::cout << "City: " << city.cityName << "\n";
        std::cout << "Departure Date: " << city.departureDate << "\n";
        std::cout << "Departure Time: " << city.departureTime << "\n";
        std::cout << "Arrival Time: " << city.arrivalTime << "\n";
        std::cout << "Trip Duration: " << city.tripDuration << " hours\n";
        std::cout << "Trip Cost: BYN " << city.tripCost << "\n\n";
    }
}