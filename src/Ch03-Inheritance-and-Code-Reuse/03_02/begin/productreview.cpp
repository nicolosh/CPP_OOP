#include "productreview.h"

ProductReview::ProductReview(unsigned int r,
                             const std::string &t,
                             const std::string &txt,
                             const std::string &id,
                             const std::string &cat)
{
  setRating(r);
  setTitle(t);
  setText(txt);
  setProductId(id);
  setCategory(cat);
}

ProductReview::~ProductReview()
{
  std::cout << "\nProductReview object is being deleted." << std::endl;
}

void ProductReview::displayDetails() const
{
  std::cout << "\nProduct Rating: " << rating << "/5\n"
            << "Title: " << title << "\n"
            << "Text: " << text << "\n"
            << "Product ID: " << productId << "\n"
            << "Category: " << category << std::endl;
}

void ProductReview::setRating(unsigned int r)
{
  if (r < MIN_RATING || r > MAX_RATING)
  {
    throw std::invalid_argument("Rating must be between 1 and 5");
  }
  else
  {
    rating = r;
  }
}

void ProductReview::setTitle(const std::string &t)
{
  title = validateAndTrim(t, MAX_TITLE_LENGTH, "Title");
}

void ProductReview::setText(const std::string &txt)
{
  text = validateAndTrim(txt, MAX_TEXT_LENGTH, "Review text");
}

void ProductReview::setProductId(const std::string &id)
{
  productId = validateAndTrim(id, MAX_PRODUCTID_LENGTH, "Product Id");
}

void ProductReview::setCategory(const std::string &cat)
{
  category = validateAndTrim(cat, MAX_CATEGORY_LENGTH, "Product category");
}

std::string ProductReview::validateAndTrim(const std::string &str,
                                           unsigned int maxLength,
                                           const std::string &fieldName) const
{
  if (str.empty())
  {
    throw std::invalid_argument(fieldName + " cannot be empty");
  }
  return str.length() > maxLength ? str.substr(0, maxLength) : str;
}