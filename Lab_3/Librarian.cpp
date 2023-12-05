#include "librarian.h"
#include <iostream>
#include<stdexcept>

Librarian::Librarian(const std::string& firstName, const std::string& lastName, int age)
    : User(firstName, lastName, age) {}

void Librarian::searchBookOnShelf(Shelf& shelf, const std::string& title, User& user) const {
    std::cout << "Librarian " << getFirstName() << " " << getLastName() << " is searching for the book \"" << title << "\"...\n";
    try {
        if (shelf.searchBook(title)) {
            std::cout << "Librarian " << getFirstName() << " " << getLastName() << " is giving the book \"" << title << "\" to User " << user.getFirstName() << " " << user.getLastName() << ".\n";
            shelf.removeBook(title);
        }
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Exception caught: " << ex.what() << "\n";
    }
}

void Librarian::displayInfo() const {
    std::cout << "Librarian: " << getFirstName() << " " << getLastName() << ", Age: " << getAge() << "\n";
}