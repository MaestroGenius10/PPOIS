#include "Notification.h"
#include <iostream>

Notification::Notification(const std::string& message) : message(message) {}

void Notification::displayMessage() const {
    std::cout << "Notification: " << message << "\n";
}

BorrowNotification::BorrowNotification(const std::string& message, const std::vector<Book>& books)
    : Notification(message), borrowedBooks(books) {}

void BorrowNotification::displayMessage() const {
    std::cout << "Borrow Notification: " << message << "\n";
}

void BorrowNotification::displayBorrowedBooks() const {
    std::cout << "Borrowed Books:\n";
    for (const auto& book : borrowedBooks) {
        book.displayInfo();
        std::cout << "-------------------\n";
    }
}