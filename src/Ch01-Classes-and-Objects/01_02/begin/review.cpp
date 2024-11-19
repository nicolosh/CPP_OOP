#include <iostream>
using namespace std;

class Review
{
  unsigned int rating;
  string title;
  string text;

  void displayDetails() const
  {
    cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << endl;
  }
};