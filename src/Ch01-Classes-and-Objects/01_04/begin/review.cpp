#include "review.h"

Review::Review(unsigned int r, const std::string &t, const std::string &txt)
{
  setRating(r);
  setTitle(t);
  setTxt(txt);
}

Review::~Review()
{
  std::cout << "Review object is being deleted; " << std::endl;
}

void Review::displayDetails() const
{
  ++accessCount;
  std::cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << "\nRead " << accessCount << " times " << std::endl;
}

void Review::setRating(unsigned int r)
{
  if (!(r >= MIN_RATING && r <= MAX_RATING))
    throw std::invalid_argument("The rating must be between 1 and 5!");
  rating = r;
}

void Review::setTitle(const std::string &t)
{
  // check the input parameters length of t is no more than 128 characters: if yes we simply trim it
  title = validateAndTrim(t, MAX_TITLE_LENGTH, "title");
}

void Review::setTxt(const std::string &txt)
{
  // check the input parameters length of txt is no more than 1024 characters: if yes we simply trim it
  text = validateAndTrim(txt, MAX_TEXT_LENGTH, "text");
}

std::string Review::validateAndTrim(const std::string &str,
                                    unsigned int maxLength,
                                    const std::string &fieldName) const
{
  // validates for an empty input
  if (str == "") // if(str.empty())
    throw std::invalid_argument("The review " + fieldName + " must not be empty");

  return str.length() > maxLength ? str.substr(0, maxLength) : str;
}