#include "Genre.h"
#include <iostream>

Genre::Genre(const std::string& name, int bookCount, const std::vector<std::string>& famousAuthors, const std::vector<Book>& bestBooks)
    : name(name), bookCount(bookCount), famousAuthors(famousAuthors), bestBooks(bestBooks) {}

void Genre::displayInfo() const {
    std::cout << "Genre: " << name << "\n";
    std::cout << "Number of Books: " << bookCount << "\n";

    std::cout << "Famous Authors:\n";
    for (const auto& author : famousAuthors) {
        std::cout << author << "\n";
    }

    std::cout << "Best Books:\n";
    for (const auto& book : bestBooks) {
        book.displayInfo();
        std::cout << "-------------------\n";
    }
}