#pragma once
#include <string>
#include <vector>
#include "Book.h"

class Genre {
private:
    std::string name;
    int bookCount;
    std::vector<std::string> famousAuthors;
    std::vector<Book> bestBooks;

public:
    Genre(const std::string& name, int bookCount, const std::vector<std::string>& famousAuthors, const std::vector<Book>& bestBooks);

    void displayInfo() const;
};
