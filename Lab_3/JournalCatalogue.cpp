#include "JournalCatalogue.h"
#include <iostream>
#include"Payment.h"
void JournalCatalogue::viewAllJournals() const {
    std::cout << "Journal Catalogue:\n";
    for (const auto& journal : journals) {
        journal.displayInfo();
        std::cout << "-----------------\n";
    }
}

void JournalCatalogue::addJournal(const Journal& journal) {
    journals.push_back(journal);
}

void JournalCatalogue::subscribeToJournal(const Journal& journal, int months, Payment& payment) {
    payment.payForSubscription(months);
    std::cout << "Subscribed to " << journal.getTitle() << " for " << months << " months.\n";
}

void JournalCatalogue::unsubscribeFromJournal(const Journal& journal) {

    std::cout << "Unsubscribed from " << journal.getTitle() << ".\n";
}

double JournalCatalogue::calculateSubscriptionCost(int months) {
    return Payment::calculateSubscriptionCost(months);
}

const std::vector<Journal>& JournalCatalogue::getJournals() const {
    return journals;
}