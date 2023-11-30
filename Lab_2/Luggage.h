#pragma once
#include <vector>
#include "item.h"

class Luggage {
public:
    Luggage();

    void addItem(const std::string& name, double weight, double length, double width, double height);
    void promptUserToAddItem();
    void viewLuggage() const;
    const std::vector<Item>& getItems() const;

private:
    std::vector<Item> luggageItems_;
};
