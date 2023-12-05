#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "Notification.h"

class Transaction {
private:
    std::string username;
    std::vector<Book> borrowedBooks;

public:
    Transaction(const std::string& username, const std::vector<Book>& books);
    void displayTransaction() const;
};
