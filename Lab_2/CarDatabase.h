#pragma once
#include <string>
#include <vector>

class CarData {
    public:
    std::string brand;
    std::string registrationNumber;
    std::string colour;
    int capacity;
};

class CarDatabase {
public:
    CarDatabase(const std::string& filename);
    ~CarDatabase();

    void addCar(const std::string& brand, const std::string& registrationNumber,
        const std::string colour, int capacity);

    const std::vector<CarData>& getCars() const;
    void displayAllCars() const;

private:
    std::vector<CarData> cars;
    std::string filename;

    void saveToFile() const;
    bool loadFromFile();
};
