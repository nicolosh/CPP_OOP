#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
using namespace std;

class Review
{
public:
  void displayDetails() const;

private:
  unsigned int rating;
  string title;
  string text;
};

#endif