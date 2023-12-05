#pragma once
#include <string>
#include"Notification.h"
#include"Transaction.h"
class User {
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string cardNumber;
    std::string phoneNumber;
    std::vector<Book> borrowedBooks;
    std::vector<Book> returnedBooks;
    std::vector<Notification> notifications;
    std::vector<Transaction> transactions;

public:
    User(const std::string& firstName, const std::string& lastName, int age);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    void displayInfo() const;
    void borrowBooks(const std::vector<Book>& books);
    void returnBooks(const std::vector<Book>& books);
    void displayNotifications() const;
    void displayTransactions() const;
    void setPhoneNumber(const std::string& phoneNumber);
    void setCardNumber(const std::string& cardNumber);
    const std::vector<Book>& getBorrowedBook() const;
    const std::vector<Book>& getReturnedBook() const;
    std::string getCardNumber() const;
    std::string getPhoneNumber() const;
};