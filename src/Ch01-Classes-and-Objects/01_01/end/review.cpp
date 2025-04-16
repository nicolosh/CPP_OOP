#include <iostream>

// rating, title and text
class Review
{
public:
  // operates on data / variables of the class Review with no modification
  void displayDetails() const
  {
    std::cout << "Rating: " << rating << "\nTitle: " << title << "\nText: " << text << std::endl;
  }

private:
  unsigned int rating;
  std::string title;
  std::string text;
};
