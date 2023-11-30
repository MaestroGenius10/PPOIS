#include "Luggage.h"
#include <iostream>

Luggage::Luggage() {}

void Luggage::addItem(const std::string& name, double weight, double length, double width, double height) {
    Item item(name, weight, length, width, height);
    luggageItems_.push_back(item);
}

void Luggage::promptUserToAddItem() {
    char addMore;
    do {
        std::cout << "Do you want to add more? (y/n): ";
        std::cin >> addMore;

        if (addMore == 'y' || addMore == 'Y') {
            std::string itemName;
            double itemWeight, itemLength, itemWidth, itemHeight;

            std::cout << "Enter name: ";
            std::cin >> itemName;

            std::cout << "Enter weight (cm): ";
            std::cin >> itemWeight;

            std::cout << "Enter length(cm): ";
            std::cin >> itemLength;

            std::cout << "Enter width (cm) : ";
            std::cin >> itemWidth;

            std::cout << "Enter height (cm): ";
            std::cin >> itemHeight;

            addItem(itemName, itemWeight, itemLength, itemWidth, itemHeight);
        }
    } while (addMore == 'y' || addMore == 'Y');
}

void Luggage::viewLuggage() const {
    std::cout << "List of items in luggage:" << std::endl;
    for (const auto& item : luggageItems_) {
        std::cout << "- " << item.getName() << " (Weight: " << item.getWeight() << " kg, Dimensions: "
            << item.getLength() << "x" << item.getWidth() << "x" << item.getHeight() << " cm)" << std::endl;
    }
}

const std::vector<Item>& Luggage::getItems() const {
    return luggageItems_;
}