#include "Payment.h"
#include <iomanip>
#include"JournalCatalogue.h"
Payment::Payment(double amount, const std::string& paymentMethod) : amount(amount), paymentMethod(paymentMethod) {}

void Payment::displayInfo() const {
    std::cout << "Payment Details:\n";
    std::cout << "Amount: $" << amount << "\n";
    std::cout << "Payment Method: " << paymentMethod << "\n";
}

void Payment::payWithCreditCard(const std::string& cardNumber, const std::string& expirationDate) {
    if (cardNumber.size() == 16 && expirationDate.size() == 5) {
        std::cout << "Payment with Credit Card successful.\n";
    }
    else {
        std::cout << "Invalid Credit Card details. Payment failed.\n";
    }
}

void Payment::payWithPhoneNumber(const std::string& phoneNumber, const std::string& confirmationCode) {
    if (confirmationCode.size() == 4) {
        std::cout << "Payment with Phone Number successful.\n";
    }
    else {
        std::cout << "Invalid Confirmation Code. Payment failed.\n";
    }
}

void Payment::payForSubscription(int months) {
    double subscriptionCost = calculateSubscriptionCost(months);

    std::cout << "Paying for subscription...\n";
    displayInfo();
    std::cout << "Subscription Amount: $" << subscriptionCost << "\n";
    std::cout << "Payment Method: Credit Card\n";
    std::cout << "Subscription payment successful.\n";
}

double Payment::calculateSubscriptionCost(int months) {
    return 0.3 * months;
}



