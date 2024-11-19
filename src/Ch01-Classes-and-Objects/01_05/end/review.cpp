#include "review.h"

Review::Review(unsigned int r, const string &t, const string &txt)
{
  rating = r;
  title = t;
  text = txt;
}

Review::~Review()
{
  cout << "Review object is being deleted." << endl;
}

void Review::displayDetails() const
{
  cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << endl;
}