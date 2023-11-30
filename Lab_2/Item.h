#pragma once
#include <string>

class Item {
public:
    Item(const std::string& name, double weight, double length, double width, double height);

    const std::string& getName() const;
    double getWeight() const;
    double getLength() const;
    double getWidth() const;
    double getHeight() const;

private:
    std::string name_;
    double weight_;
    double length_;
    double width_;
    double height_;
};
