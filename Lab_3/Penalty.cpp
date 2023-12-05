#include "Penalty.h"

Penalty::Penalty(const User* user) : penaltyAmount(0.0), user(user), payment(0.0, "") {}

double Penalty::calculatePenalty(int overdueDays, int overdueBooks) {
    penaltyAmount = 0.60 * overdueDays * overdueBooks;
    return penaltyAmount;
}

void Penalty::displayInfo() const {
    if (user) {
        std::cout << "Penalty for User " << user->getFirstName() << " " << user->getLastName() << ":\n";
        std::cout << "Penalty Amount: $" << penaltyAmount << "\n";
        payment.displayInfo();
    }
}

void Penalty::setUser(const User* newUser) {
    user = newUser;
}