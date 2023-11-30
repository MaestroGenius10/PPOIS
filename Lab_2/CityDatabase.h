#pragma once
#include <string>
#include <vector>

class CityData {
public:
    std::string cityName;
    std::string departureTime;
    std::string arrivalTime;
    double tripDuration;
    double tripCost;
    std::string departureDate;
};

class CityDatabase {
public:
    CityDatabase(const std::string& filename);
    ~CityDatabase();

    bool addCity(const std::string& cityName, const std::string& departureTime,
        const std::string& arrivalTime, double tripDuration, double tripCost,
        const std::string& departureDate);

    const std::vector<CityData>& getCities() const;
    void displayAllCities() const;

private:

    const std::string filename;
    std::vector<CityData> cities;

    bool saveToFile() const;
    bool loadFromFile();
};
