#include "librarian.h"
#include <iostream>

Librarian::Librarian(const std::string& firstName, const std::string& lastName, int age)
    : User(firstName, lastName, age) {}

void Librarian::searchBookOnShelf(Shelf& shelf, const std::string& title, User& user) const {
    std::cout << "Librarian " << getFirstName() << " " << getLastName() << " is searching for the book \"" << title << "\"...\n";
    if (shelf.searchBook(title)) {
        std::cout << "Librarian " << getFirstName() << " " << getLastName() << " is giving the book \"" << title << "\" to User " << user.getFirstName() << " " << user.getLastName() << ".\n";
        shelf.removeBook(title);
    }
    else {
        std::cout << "Sorry, we don't have a book with this title " << "\n";
    }
}

void Librarian::displayInfo() const {
    std::cout << "Librarian: " << getFirstName() << " " << getLastName() << ", Age: " << getAge() << "\n";
}