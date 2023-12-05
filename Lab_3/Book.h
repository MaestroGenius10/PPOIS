#pragma once
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    std::string genre;
    int year;

public:
    Book(const std::string& title, const std::string& author, const std::string& genre, int year);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    virtual void displayInfo() const;
};
