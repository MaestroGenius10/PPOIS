#include "Reviews.h"
#include <iostream>
#include <fstream>
Reviews::Reviews(const std::string& filename) : filename(filename) {
    loadFromFile();
}

Reviews::~Reviews() {
    saveToFile();
}

void Reviews::addReview(const std::string& review) {
    reviews.push_back(review);

    saveToFile();
}

void Reviews::displayReviews() const {
    std::cout << "All Reviews:\n";
    for (const auto& review : reviews) {
        std::cout << review << "\n";
    }
}

void Reviews::saveToFile() const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing reviews." << std::endl;
        return;
    }

    for (const auto& review : reviews) {
        outFile << review << "\n";
    }

    outFile.close();
}

const std::vector<std::string>& Reviews::getReviews() const {
    return reviews;
}

void Reviews::loadFromFile() {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "No existing reviews file found. Creating a new one." << std::endl;
        return;
    }

    reviews.clear();
    inFile.close();
}