#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : public Product{
public: 
    Clothing(const std::string size, const std::string brand, const std::string category, const std::string name, double price, int qty);
    virtual ~Clothing();

    std::set<std::string> keywords() const;

    void dump(std::ostream& os) const;

    std::string displayString() const;


private:
    std::string size_;
    std::string brand_;
};
#endif