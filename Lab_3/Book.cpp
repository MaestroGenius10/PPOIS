#include "Book.h"
#include "Author.h"
#include"Genre.h"
#include <iostream>

Book::Book(const std::string& title, const Author& author, const Genre& genre, int year)
    : title(title), author(author), genre(genre), year(year) {}

std::string Book::getTitle() const {
    return title;
}

Author Book::getAuthor() const {
    return author;
}

Genre Book::getGenre() const {
    return genre;
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: \n";
    author.displayInfo();
    std::cout << "Genre: \n";
    genre.displayInfo();
    std::cout << "Year: " << year << "\n";
}