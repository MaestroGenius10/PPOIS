#pragma once
#include "CityDatabase.h"
#include "CarDatabase.h"
#include "DriverDatabase.h"
#include "luggage.h"
#include "reviews.h"
class Menu {
public:
    Menu(const CityDatabase& cityDB, const CarDatabase& carDB, const DriverDatabase& driverDB, const Reviews& reviwesList);
    void run();

private:
    const CityDatabase& cityDatabase;
    const CarDatabase& carDatabase;
    const DriverDatabase& driverDatabase;
    const Reviews& reviewsList;

    void viewDriverInfoByName();
    void viewTripsToCity();
    void addLuggage();
    void viewAllReviwes();
};
