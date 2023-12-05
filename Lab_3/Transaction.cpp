#include "Transaction.h"
#include <iostream>

Transaction::Transaction(const std::string& username, const std::vector<Book>& books)
    : username(username), borrowedBooks(books) {}

void Transaction::displayTransaction() const {
    std::cout << "Transaction for User: " << username << "\n";
    std::cout << "Books:\n";
    for (const auto& book : borrowedBooks) {
        book.displayInfo();
        std::cout << "-------------------\n";
    }
}