#pragma once
#include <string>
#include <vector>
#include "book.h"

class Notification {
protected:
    std::string message;

public:
    Notification(const std::string& message);
    virtual void displayMessage() const;

    virtual ~Notification() = default;
};

class BorrowNotification : public Notification {
private:
    std::vector<Book> borrowedBooks;

public:
    BorrowNotification(const std::string& message, const std::vector<Book>& books);
    void displayMessage() const override;
    void displayBorrowedBooks() const;
};
