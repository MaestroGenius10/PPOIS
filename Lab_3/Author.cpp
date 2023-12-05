#include "Author.h"
#include <iostream>

Author::Author(const std::string& name, const std::vector<std::string>& shortInfo,
    const std::vector<std::string>& popularBooks, const std::string& favoriteGenre)
    : name(name), shortInfo(shortInfo), popularBooks(popularBooks), favoriteGenre(favoriteGenre) {}

std::string Author::getName() const {
    return name;
}

std::vector<std::string> Author::getShortInfo() const {
    return shortInfo;
}

std::vector<std::string> Author::getPopularBooks() const {
    return popularBooks;
}

std::string Author::getFavoriteGenre() const {
    return favoriteGenre;
}

void Author::displayInfo() const {
    std::cout << "Name: " << name << "\nShort Info: ";
    for (const auto& book : shortInfo) {
        std::cout << book;
    }
    std::cout << "\nPopular Books: ";
    for (const auto& book : popularBooks) {
        std::cout << book << ", ";
    }
    std::cout << "\nFavorite Genre: " << favoriteGenre << std::endl;
}