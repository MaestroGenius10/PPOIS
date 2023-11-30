#include "Menu.h"
#include <iostream>
#include <iomanip>


Menu::Menu(const CityDatabase& cityDB, const CarDatabase& carDB, const DriverDatabase& driverDB, const Reviews& reviewsList)
    : cityDatabase(cityDB), carDatabase(carDB), driverDatabase(driverDB), reviewsList(reviewsList) {}

void Menu::run() {
    int choice;
    do {
        std::cout << "Menu:\n"
            << "1. View Driver Information by Name\n"
            << "2. View Trips to a Specific City\n"
            << "3. Add Luggage\n"
            << "4. View all reviews about company\n"
            << "5. Exit\n"
            << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewDriverInfoByName();
            break;
        case 2:
            viewTripsToCity();
            break;
        case 3:
            addLuggage();
            break;
        case 4:
            viewAllReviwes();
            break;
        case 5:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }

    } while (choice != 5);
}

void Menu::viewDriverInfoByName() {
    DriverDatabase driverDB("driver_data.txt");
    driverDB.displayAllDrivers();
}

void Menu::viewTripsToCity() {
    CityDatabase CityDB("city_data.txt");
    CityDB.displayAllCities();
}

void Menu::addLuggage() {
    Luggage luggage;
    luggage.promptUserToAddItem();
    luggage.viewLuggage();
}

void Menu::viewAllReviwes()
{
    Reviews reviewList("reviews.txt");
    reviewList.displayReviews();
}
