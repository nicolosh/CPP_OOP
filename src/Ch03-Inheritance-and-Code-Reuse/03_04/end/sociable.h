#ifndef SOCIABLE_H
#define SOCIABLE_H

#include <iostream>

class Sociable
{
protected:
    unsigned int likes = 0;
    unsigned int shares = 0;
    std::vector<std::string> comments;

public:
    void like() { ++likes; }
    void share() { ++shares; }

    void addComment(const std::string &comment);
    void displaySocialStats() const;
};

#endif