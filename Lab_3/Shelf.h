#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include "book.h"

class Shelf {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void displayBooks() const;
    bool searchBook(const std::string& title) const;
    void removeBook(const std::string& title);
    const std::vector<Book>& getBooks() const;
    size_t size() const;
};
