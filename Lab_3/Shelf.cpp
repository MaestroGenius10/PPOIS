#include "shelf.h"
#include <iostream>

void Shelf::addBook(const Book& book) {
    books.push_back(book);
}

void Shelf::displayBooks() const {
    std::cout << "Books on the shelf:\n";
    for (const auto& book : books) {
        book.displayInfo();
        std::cout << "-------------------\n";
    }
}

bool Shelf::searchBook(const std::string& title) const {
    auto it = std::find_if(books.begin(), books.end(),
        [title](const Book& book) { return book.getTitle() == title; });

    if (it != books.end()) {
        std::cout << "Book \"" << title << "\" found on the shelf.\n";
        return true;
    }
    else {
        std::cout << "Book \"" << title << "\" not found on the shelf.\n";
        return false;
    }
}

void Shelf::removeBook(const std::string& title) {
    auto it = std::remove_if(books.begin(), books.end(),
        [title](const Book& book) { return book.getTitle() == title; });

    books.erase(it, books.end());
}

size_t Shelf::size() const {
    return books.size();
}

const std::vector<Book>& Shelf::getBooks() const {
    return books;
}