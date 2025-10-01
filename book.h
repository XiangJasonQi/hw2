#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product{
public: 
    Book(const std::string ISBN, const std::string author, const std::string category, const std::string name, double price, int qty);
    virtual ~Book();

    std::set<std::string> keywords() const;

    void dump(std::ostream& os) const;

    std::string displayString() const;


private:
    std::string ISBN_;
    std::string author_;
};
#endif