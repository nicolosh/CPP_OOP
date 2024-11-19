#include <iostream>
using namespace std;

class Review
{
private:
  // Constants to define the limits for rating, title, and text length
  static constexpr unsigned int RATING_MIN = 1;
  static constexpr unsigned int RATING_MAX = 5;
  static constexpr size_t TITLE_MIN_LENGTH = 5;
  static constexpr size_t TITLE_MAX_LENGTH = 64;
  static constexpr size_t TEXT_MIN_LENGTH = 10;
  static constexpr size_t TEXT_MAX_LENGTH = 1024;

  // Member variables to hold data for each review
  unsigned int rating; // Range [1, 5]
  string title;        // Max 64 characters
  string text;         // Max 1024 characters

public:
  // Member function to display details of the review
  void displayDetails()
  {
    cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << endl;
  }

  // Setter for rating with validation
  void setRating(unsigned int r)
  {
    if (r < RATING_MIN || r > RATING_MAX)
    {
      cout << "Invalid rating. Please enter a value between 1 and 5." << endl;
    }
    else
    {
      rating = r;
    }
  }

  // Getter for rating
  unsigned int getRating()
  {
    return rating;
  }

  // Setter for title
  // Setter for title
  void setTitle(const string &t)
  {
    if (t.length() < TITLE_MIN_LENGTH || t.length() > TITLE_MAX_LENGTH)
    {
      cout << "The title should be between " << TITLE_MIN_LENGTH << " and " << TITLE_MAX_LENGTH << " characters." << endl;
    }
    else
    {
      title = t;
    }
  }

  // Getter for title
  string getTitle()
  {
    return title;
  }

  // Setter for text
  void setText(const string &t)
  {
    if (t.length() < TEXT_MIN_LENGTH || t.length() > TEXT_MAX_LENGTH)
    {
      cout << "The text should be between " << TEXT_MIN_LENGTH << " and " << TEXT_MAX_LENGTH << " characters." << endl;
    }
    else
    {
      text = t;
    }
  }

  // Getter for text
  string getText()
  {
    return text;
  }
};

int main()
{
  Review r = {5, "Great Desk Lamp", "Completely exceeded my expectations!"};

  // r.setRating(5);
  // r.setTitle("Great Desk Lamp");
  // r.setText("Completely exceeded my expectations!");

  r.displayDetails();

  return 0;
}