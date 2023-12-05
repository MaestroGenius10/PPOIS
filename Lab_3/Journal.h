#pragma once
#include "Book.h"

class Journal : public Book {
private:
    int issueNumber;

public:
    Journal(const std::string& title, const std::string& author, int year, int issueNumber);
    int getIssueNumber() const;
    int getYear() const;
    void displayInfo() const override;
};