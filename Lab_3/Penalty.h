#pragma once
#include "User.h"
#include "Payment.h"

class Penalty {
private:
    double penaltyAmount;
    const User* user;
    Payment payment;

public:
    Penalty(const User* user);

    double calculatePenalty(int overdueDays, int overdueBooks);
    void displayInfo() const;
    void setUser(const User* newUser);
};

