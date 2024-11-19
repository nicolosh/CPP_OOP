#include "review.h"

void Review::displayDetails() const
{
  cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << endl;
}