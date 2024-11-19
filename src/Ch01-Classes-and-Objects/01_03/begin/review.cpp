#include <iostream>
using namespace std;

class Review
{
public:
  void displayDetails() const
  {
    cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << endl;
  }

private:
  unsigned int rating;
  string title;
  string text;
};