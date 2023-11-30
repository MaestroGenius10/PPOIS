#include"pch.h"
#include<iostream>
#include "CppUnitTest.h"
#include"../TransportCompany/CarDatabase.h"
#include"../TransportCompany/CityDatabase.h"
#include"../TransportCompany/DriverDatabase.h"
#include"../TransportCompany/Item.h"
#include"../TransportCompany/Luggage.h"
#include"../TransportCompany/Menu.h"
#include"../TransportCompany/RegistrationManager.h"
#include"../TransportCompany/RegistrationValidator.h"
#include"../TransportCompany/Reviews.h"
#include"../TransportCompany/UserDatabase.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CarDatabaseTestNamespace
{ 
    TEST_CLASS(CityDatabaseTests)
    {
    public:
        TEST_METHOD(AddCar)
        {
            CarDatabase carDB("test_cars.txt");
            carDB.addCar("Toyota", "ABC123", "Blue", 5);
            const auto& cars = carDB.getCars();
            carDB.displayAllCars();
            Assert::AreEqual<size_t>(1, cars.size());
            Assert::AreEqual<std::string>("Toyota", cars[0].brand);
            Assert::AreEqual<std::string>("ABC123", cars[0].registrationNumber);
            Assert::AreEqual<std::string>("Blue", cars[0].colour);
            Assert::AreEqual<int>(5, cars[0].capacity);
        }
        TEST_METHOD(AddCIty)
        {
            CityDatabase cityDB("test_cities.txt");
            bool result = cityDB.addCity("TestCity", "10:00", "14:00", 4.0, 30.0, "2023-12-02");
            const auto& cities = cityDB.getCities();
            cityDB.displayAllCities();
            Assert::IsTrue(result);
        }
        
        TEST_METHOD(Driver) {
            DriverDatabase driverDB("test_drivers.txt");
            bool result = driverDB.addDriver("Anton", "Petrov", "+375334456721", 5);
            bool result2= driverDB.addDriver("Oleg", "Petrov", "+375334456721", 5);
            const auto& driver = driverDB.getDrivers();
            driverDB.displayAllDrivers();
            Assert::IsTrue(result);
            Assert::IsTrue(result2);
        }
        TEST_METHOD(SaveAndLoadReviews)
        {
            Reviews reviews("test_reviews.txt");
            reviews.addReview("Super!");
            reviews.displayReviews();
            const std::vector<std::string>& allReviews = reviews.getReviews();
            Assert::AreEqual(static_cast<size_t>(1), allReviews.size());
            Assert::AreEqual(std::wstring(L"Super!"), std::wstring(allReviews[0].begin(), allReviews[0].end()));
        }
        TEST_METHOD(Items)
        {
            Item item("Book", 1.5, 10.0, 5.0, 2.0);
            const std::string& name = item.getName();
            double weight = item.getWeight();
            double length = item.getLength();
            double width = item.getWidth();
            double height = item.getHeight();
            Assert::AreEqual("Book", name.c_str());
            Assert::AreEqual(1.5, weight);
            Assert::AreEqual(10.0, length);
            Assert::AreEqual(5.0, width);
            Assert::AreEqual(2.0, height);
        }
        TEST_METHOD(LuggageAndItem)
        {
            Luggage luggage;
            luggage.addItem("Book", 1.5, 10.0, 5.0, 2.0);
            luggage.viewLuggage();
            const std::vector<Item>& items = luggage.getItems();
            Assert::AreEqual<int>(1, items.size());
            Assert::AreEqual("Book", items[0].getName().c_str());
            Assert::AreEqual(1.5, items[0].getWeight());
            Assert::AreEqual(10.0, items[0].getLength());
            Assert::AreEqual(5.0, items[0].getWidth());
            Assert::AreEqual(2.0, items[0].getHeight());
        }

        TEST_METHOD(PromptUserToAddItem)
        {
            Luggage luggage;
            std::stringstream input("y\nBook 1.5 10.0 5.0 2.0\nn\n");
            std::streambuf* original = std::cin.rdbuf(input.rdbuf());
            luggage.promptUserToAddItem();
            const std::vector<Item>& items = luggage.getItems();
            std::cin.rdbuf(original);
            Assert::AreEqual<int>(1, items.size());
        }
        
        TEST_METHOD(IsValidPassword)
        {
            bool result1 = RegistrationValidator::isValidPassword("Password123");
            bool result2 = RegistrationValidator::isValidPassword("short");
            Assert::IsTrue(result1);
            Assert::IsFalse(result2);
        }

        TEST_METHOD(IsValidEmail)
        {
            bool result1 = RegistrationValidator::isValidEmail("user@example.com");
            bool result2 = RegistrationValidator::isValidEmail("invalid.email");
            Assert::IsTrue(result1);
            Assert::IsFalse(result2);
        }
        
        TEST_METHOD(AddUser)
        {
            UserDatabase userDatabase;
            bool result1 = userDatabase.addUser("John", "Doe", "john.doe@example.com", "SecurePass123");
            bool result2 = userDatabase.addUser("Jane", "Smith", "jane.smith@example.com", "Weak");
            Assert::IsTrue(result1);
            Assert::IsFalse(result2);
        }

        TEST_METHOD(UserExists)
        {
            UserDatabase userDatabase;
            bool result1 = userDatabase.userExists("john.doe@example.com", "SecurePass123");
            bool result2 = userDatabase.userExists("nonexistent@example.com", "InvalidPass");
            Assert::IsTrue(result1);
            Assert::IsFalse(result2);
        }
    };
}