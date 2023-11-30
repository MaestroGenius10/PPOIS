#pragma once
#include <vector>
#include <string>

class Reviews {
public:

    Reviews(const std::string& filename);
    ~Reviews();

    void addReview(const std::string& review);

    void displayReviews() const;

    void saveToFile() const;

    void loadFromFile();

    const std::vector<std::string>& getReviews() const;

private:
    std::vector<std::string> reviews;
    std::string filename;
};