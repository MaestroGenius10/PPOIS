#pragma once
#include <string>
#include <vector>

struct DriverData {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    int rating;
};

class DriverDatabase {
public:

    DriverDatabase(const std::string& filename);
    ~DriverDatabase();

    bool addDriver(const std::string& firstName, const std::string& lastName,
        const std::string& phoneNumber, int rating);

    const std::vector<DriverData>& getDrivers() const;
    void displayAllDrivers() const;

private:
    std::string filename;
    std::vector<DriverData> drivers;

    bool saveToFile() const;
    bool loadFromFile();
};

 