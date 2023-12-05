#pragma once
#include <iostream>
#include <string>

class Payment {
private:
    double amount;
    std::string paymentMethod;

public:
    Payment(double amount, const std::string& paymentMethod);
    void displayInfo() const;
    void payWithCreditCard(const std::string& cardNumber, const std::string& expirationDate);
    void payWithPhoneNumber(const std::string& phoneNumber, const std::string& confirmationCode);
    void payForSubscription(int months);
    static double calculateSubscriptionCost(int months);
};
