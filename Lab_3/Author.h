#pragma once
#include <string>
#include <vector>

class Author {
private:
    std::string name;
    std::vector<std::string> shortInfo;
    std::vector<std::string> popularBooks;
    std::string favoriteGenre;

public:
    Author(const std::string& name, const std::vector<std::string>& shortInfo,
        const std::vector<std::string>& popularBooks, const std::string& favoriteGenre);

    std::string getName() const;
    std::vector<std::string> getShortInfo() const;
    std::vector<std::string> getPopularBooks() const;
    std::string getFavoriteGenre() const;

    void displayInfo() const;
};