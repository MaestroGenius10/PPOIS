#pragma once
#include <vector>
#include "Journal.h"
#include"Payment.h"

class JournalCatalogue {
private:
    std::vector<Journal> journals;

public:
    void viewAllJournals() const;
    void addJournal(const Journal& journal);
    void subscribeToJournal(const Journal& journal, int months, Payment& payment);
    void unsubscribeFromJournal(const Journal& journal);
    static double calculateSubscriptionCost(int months);
    const std::vector<Journal>& getJournals() const;
};

