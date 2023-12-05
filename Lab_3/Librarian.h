#pragma once
#include "User.h"
#include "Shelf.h"

class Librarian : public User {
public:
    Librarian(const std::string& firstName, const std::string& lastName, int age);
    void searchBookOnShelf(Shelf& shelf, const std::string& title, User& user) const;
    void displayInfo() const;
};
