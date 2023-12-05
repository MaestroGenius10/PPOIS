#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, const std::string& genre, int year)
    : title(title), author(author), genre(genre), year(year) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getGenre() const {
    return genre;
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Genre: " << genre << "\n";
    std::cout << "Year: " << year << "\n";
}