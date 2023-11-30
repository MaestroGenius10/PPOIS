#include "Item.h"

Item::Item(const std::string& name, double weight, double length, double width, double height)
    : name_(name), weight_(weight), length_(length), width_(width), height_(height) {}

const std::string& Item::getName() const {
    return name_;
}

double Item::getWeight() const {
    return weight_;
}

double Item::getLength() const {
    return length_;
}

double Item::getWidth() const {
    return width_;
}

double Item::getHeight() const {
    return height_;
}