#pragma once
#include <string>
#include"Genre.h"
#include"Author.h"
class Book {
protected:
    std::string title;
    Author author;
    Genre genre;
    int year;

public:
    Book(const std::string& title, const Author& author, const Genre& genre, int year);
    std::string getTitle() const;
    Author getAuthor() const;
    Genre getGenre() const;
    virtual void displayInfo() const;
};
