#include "pch.h"
#include "CppUnitTest.h"
#include<locale>
#include"../Library/Author.h"
#include"../Library/Book.h"
#include"../Library/Genre.h"
#include"../Library/Librarian.h"
#include"../Library/Notification.h"
#include"../Library/Payment.h"
#include"../Library/Penalty.h"
#include"../Library/Shelf.h"
#include"../Library/Transaction.h"
#include"../Library/User.h"
#include"../Library/Journal.h"
#include"../Library/JournalCatalogue.h"
#include<sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLibrary
{
	TEST_CLASS(TestLibrary)
	{
	public:

        TEST_METHOD(TestGetShortInfo)
        {
            std::vector<std::string> shortInfo = { "Born in 1970", "Award-winning author" };
            Author author("Jane Doe", shortInfo, {}, "Mystery");
            Assert::IsTrue(shortInfo == author.getShortInfo());
            author.displayInfo();
        }

        TEST_METHOD(TestGetPopularBooks)
        {
            std::vector<std::string> popularBooks = { "Book1", "Book2", "Book3" };
            Author author("Alice Wonderland", {}, popularBooks, "Fantasy");
            Assert::IsTrue(popularBooks == author.getPopularBooks());
            author.displayInfo();
        }
	    
        TEST_METHOD(TestGetInfoAuthorAndBook)
        {
            Author author("John Doe", {}, {}, "Fiction");
            Assert::AreEqual("John Doe", author.getName().c_str());
            Assert::AreEqual("Fiction", author.getFavoriteGenre().c_str());
            Book book("1984", "George Orwell", "Dystopian", 1949);
            Assert::AreEqual("Dystopian", book.getGenre().c_str());
            Assert::AreEqual("George Orwell", book.getAuthor().c_str());
            Assert::AreEqual("1984", book.getTitle().c_str());
        }

        TEST_METHOD(TestCreateGenreWithParameters)
        {
            std::vector<std::string> famousAuthors = { "Author1", "Author2" };
            std::vector<Book> bestBooks = {
                Book("Book1", "Author1", "Genre1", 2000),
                Book("Book2", "Author2", "Genre2", 2010)
            };

            Genre genre("Fantasy", 2, famousAuthors, bestBooks);
            genre.displayInfo();
            Book book("The Hobbit", "J.R.R. Tolkien", "Fantasy", 1937);
            book.displayInfo();
            Assert::AreEqual("The Hobbit", book.getTitle().c_str());
            Assert::AreEqual("J.R.R. Tolkien", book.getAuthor().c_str());
            Assert::AreEqual("Fantasy", book.getGenre().c_str());
        }
        
        TEST_METHOD(TestDisplayMessage1)
        {
            Notification notification("This is a notification message");
            notification.displayMessage();
            
        }

        TEST_METHOD(TestDisplayMessage2)
        {
            std::vector<Book> borrowedBooks = {
                Book("Book1", "Author1", "Genre1", 2000),
                Book("Book2", "Author2", "Genre2", 2010)
            };

            BorrowNotification borrowNotification("Borrow message", borrowedBooks);
            borrowNotification.displayBorrowedBooks();
            borrowNotification.displayMessage();
        }
        
        TEST_METHOD(TestAddAndSearchBook)
        {
            Shelf shelf;
            Book book("Title1", "Author1", "Genre1", 2020);
            shelf.addBook(book);
            shelf.displayBooks();
            Assert::AreEqual(static_cast<size_t>(1), shelf.size());
            Assert::IsTrue(shelf.searchBook("Title1"));
            Assert::IsFalse(shelf.searchBook("Title2"));
        }
        TEST_METHOD(TestRemoveBook)
        {
            Shelf shelf;
            Book book1("Title1", "Author1", "Genre1", 2020);
            Book book2("Title2", "Author2", "Genre2", 2021);
            shelf.addBook(book1);
            shelf.addBook(book2);
            shelf.removeBook("Title1");
            Assert::AreEqual(static_cast<size_t>(1), shelf.size());
            shelf.removeBook("Title3");
            Assert::AreEqual(static_cast<size_t>(1), shelf.size());
        }
   
        TEST_METHOD(TestUserGetters)
        {
            User user("John", "Doe", 25);
            Assert::AreEqual(std::string("John"), user.getFirstName());
            Assert::AreEqual(std::string("Doe"), user.getLastName());
            Assert::AreEqual(25, user.getAge());
            user.displayInfo();
        }
        TEST_METHOD(TestSetCardNumber)
        {
            User user("John", "Doe", 25);
            user.setCardNumber("1234567890123456");
            Assert::AreEqual(std::string("1234567890123456"), user.getCardNumber());
            user.setPhoneNumber("+1234567890");
            Assert::AreEqual(std::string("+1234567890"), user.getPhoneNumber());
        }
        
        TEST_METHOD(TestBorrowAndReturnBooks)
        {
            User user("John", "Doe", 25);
            Book book1("Title1", "Author1", "Genre1", 2020);
            Book book2("Title2", "Author2", "Genre2", 2021);
            std::vector<Book> borrowedBooks;
            borrowedBooks.push_back(book1);
            borrowedBooks.push_back(book2);
            user.borrowBooks(borrowedBooks);
            user.displayTransactions();
            std::vector<Book> returnedBooks;
            returnedBooks.push_back(book1);
            user.returnBooks(returnedBooks);
            user.displayNotifications();
            Assert::AreEqual(size_t(2), user.getBorrowedBook().size());
            Assert::AreEqual(size_t(1), user.getReturnedBook().size());
        }
    
        TEST_METHOD(TestGetIssueNumber)
        {
            Journal journal("Journal Title", "Author", 2023, 1);
            int issueNumber = journal.getIssueNumber();
            int year = journal.getYear();
            journal.displayInfo();
            Assert::AreEqual(1, issueNumber);
            Assert::AreEqual(2023, year);
        }
        TEST_METHOD(TestLibrarian)
        {
            User user("Anton", "Petrov", 18);
            Shelf shelfB;
            Book book1("Title1", "Author1", "Genre1", 2020);
            Book book2("Title2", "Author2", "Genre2", 2021);
            shelfB.addBook(book1);
            shelfB.addBook(book2);
            Librarian newLibrarian("Jane", "Smith", 40);
            newLibrarian.searchBookOnShelf(shelfB, "Title1", user);
            newLibrarian.searchBookOnShelf(shelfB, "unexistedTitle", user);
            newLibrarian.displayInfo();
            Assert::AreEqual(size_t(1), shelfB.getBooks().size());  
        }
        TEST_METHOD(TestPayment)
        {
            User user("John", "Jones", 27);
            Payment newPayment(52, "Credit card");
            newPayment.payWithCreditCard("1234567812345678", "12/25");
            newPayment.payWithCreditCard("4535", "12/25");
            newPayment.displayInfo();
            newPayment.payWithPhoneNumber("+375335566772", "1234");
            newPayment.payWithPhoneNumber("+375335566772", "467535");
            newPayment.payForSubscription(5);
            double expectedCost = newPayment.calculateSubscriptionCost(5);
            Assert::AreEqual(double(1.5), expectedCost);
        }

        TEST_METHOD(TestPenalty)
        {
            User user("John", "Jones", 27);
            User user2("Anton", "Petrov", 17);
            Penalty newPenalty(&user);
            double expectedCost = newPenalty.calculatePenalty(11, 2);
            newPenalty.displayInfo();
            newPenalty.setUser(&user2);
            Assert::AreEqual(double(13.2), expectedCost);
        }
        TEST_METHOD(TestJournalCatalogue)
        {
            JournalCatalogue newCatalogue;
            Journal journal1("HealthJournal", "MikelOrteta", 2023, 1);
            Journal journal2("FutureJournal", "BobBradley", 2022, 4);
            newCatalogue.addJournal(journal1);
            newCatalogue.addJournal(journal2);
            newCatalogue.viewAllJournals();
            double expectedCost = newCatalogue.calculateSubscriptionCost(10);
            Payment paymentForJournal(3, "creditcard");
            newCatalogue.subscribeToJournal(journal1, 10, paymentForJournal);
            newCatalogue.unsubscribeFromJournal(journal1);
            Assert::AreEqual(size_t(2), newCatalogue.getJournals().size());
            Assert::AreEqual(double(3), expectedCost);
        }
    };
}