#include "User.h"
#include<iostream>
#include"Notification.h"
#include"Transaction.h"
#include "Book.h"
User::User(const std::string& firstName, const std::string& lastName, int age)
    : firstName(firstName), lastName(lastName), age(age), cardNumber(""), phoneNumber("") {}

std::string User::getFirstName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}

int User::getAge() const {
    return age;
}

void User::displayInfo() const {
    std::cout << "User: " << getFirstName() << " " << getFirstName() << ", age: " << getAge() << "\n";
    std::cout << "Card number: " << (cardNumber.empty() ? "Not set" : cardNumber) << "\n";
    std::cout << "Phone number: " << (phoneNumber.empty() ? "Not set" : phoneNumber) << "\n";
}

void User::borrowBooks(const std::vector<Book>& books) {
    borrowedBooks.insert(borrowedBooks.end(), books.begin(), books.end());
    notifications.push_back(BorrowNotification("You have borrowed a book", books));
    transactions.push_back(Transaction(firstName + " " + lastName, books));
}

void User::returnBooks(const std::vector<Book>& books) {
    returnedBooks.insert(returnedBooks.end(), books.begin(), books.end());
    notifications.push_back(Notification("You have returned a book"));
    transactions.push_back(Transaction(firstName + " " + lastName + " returned ", books));
}

void User::displayNotifications() const {
    std::cout << "User notifications:\n";
    for (const auto& notification : notifications) {
        notification.displayMessage();
        std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    }
}

void User::displayTransactions() const {
    std::cout << "User transactions:\n";
    for (const auto& transaction : transactions) {
        transaction.displayTransaction();
        std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    }
}

void User::setCardNumber(const std::string& newCardNumber) {
    cardNumber = newCardNumber;
}

void User::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

std::string User::getCardNumber() const {
    return cardNumber;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

const std::vector<Book>& User::getBorrowedBook() const {
    return borrowedBooks;
}

const std::vector<Book>& User::getReturnedBook() const {
    return returnedBooks;
}