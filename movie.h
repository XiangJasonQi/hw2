#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : public Product{
public: 
    Movie(const std::string genre, const int rating, const std::string category, const std::string name, double price, int qty);
    virtual ~Movie();

    std::set<std::string> keywords() const;

    void dump(std::ostream& os) const;

    std::string displayString() const;


private:
    std::string genre_;
    int rating_;
};
#endif