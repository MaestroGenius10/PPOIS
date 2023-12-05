#include "Journal.h"
#include <iostream>

Journal::Journal(const std::string& title, const std::string& author, int year, int issueNumber)
    : Book(title, author, "Journal", year), issueNumber(issueNumber) {}

int Journal::getIssueNumber() const {
    return issueNumber;
}

int Journal::getYear() const {
    return year;
}

void Journal::displayInfo() const {
    std::cout << "Title: " << getTitle() << "\n";
    std::cout << "Author: " << getAuthor() << "\n";
    std::cout << "Type: Journal\n";
    std::cout << "Year: " << getYear() << "\n";
    std::cout << "Issue Number: " << issueNumber << "\n";
}