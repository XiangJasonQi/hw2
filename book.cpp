#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;



Book::Book(const std::string ISBN, const std::string author, const std::string category, const std::string name, double price, int qty):
    Product(category, name, price, qty), 
    ISBN_(ISBN),
    author_(author)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const{
    std::set<std::string> keyword;
    keyword.insert(ISBN_);

    int count = 0;
    std::string temp_keyword;
    //check author
    for(size_t i = 0; i < author_.size(); i++){
        if((author_[i] <= 'z' && author_[i] >= 'a') || (author_[i] <= 'Z' && author_[i] >= 'A')){
            temp_keyword.push_back(author_[i]);
            count++;
        } else{
            if(count >= 2){
                keyword.insert(convToLower(temp_keyword));
            }
            temp_keyword.clear();
            count = 0;
        }
    }

    if(count >= 2){
        keyword.insert(convToLower(temp_keyword));
    }
    temp_keyword.clear();
    count = 0;

    //check name
    for(size_t i = 0; i < name_.size(); i++){
        if((name_[i] <= 'z' && name_[i] >= 'a') || (name_[i] <= 'Z' && name_[i] >= 'A')){
            temp_keyword.push_back(name_[i]);
            count++;
        } else{
            if(count >= 2){
                keyword.insert(convToLower(temp_keyword));
            }
            temp_keyword.clear();
            count = 0;
        }
    }



    //check if the last word of each input is a key word. 
    if(count >= 2){
        keyword.insert(convToLower(temp_keyword));
    }

    return keyword;
}

void Book::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << endl;
}


std::string Book::displayString() const{
    std::string display_string;

    display_string += name_;
    display_string.push_back('\n');

    display_string += "Author: ";
    display_string += author_;

    display_string += " ISBN: ";
    display_string += ISBN_;
    display_string.push_back('\n');

    display_string += to_string(price_);
    display_string.push_back(' ');

    display_string += to_string(qty_);
    display_string += " left.";

    return display_string;
}

