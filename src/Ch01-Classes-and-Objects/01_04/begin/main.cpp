#include "review.h"

int main()
{
  Review review = Review(5, "Excellent", "Exceeded my expectations");
  review.displayDetails();

  review.setRating(4);
  review.setTitle("Good");
  review.setTxt("Almost perfect!");
  review.displayDetails();

  return 0;
}