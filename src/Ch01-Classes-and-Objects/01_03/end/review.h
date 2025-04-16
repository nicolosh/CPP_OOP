#ifndef REVIEW_H
#define REVIEW_H
#include <iostream>

// rating, title and text
class Review
{
public:
  // operates on data / variables of the class Review with no modification
  void displayDetails() const;

private:
  unsigned int rating;
  std::string title;
  std::string text;
};

#endif