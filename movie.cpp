#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"
#include "movie.h"
#include "util.h"

using namespace std;



Movie::Movie(const std::string genre, const std::string rating, const std::string category, const std::string name, double price, int qty):
    Product(category, name, price, qty), 
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> keyword;

    int count = 0;
    std::string temp_keyword;
    //check genre
    for(size_t i = 0; i < genre_.size(); i++){
        if((genre_[i] <= 'z' && genre_[i] >= 'a') || (genre_[i] <= 'Z' && genre_[i] >= 'A')){
            temp_keyword.push_back(genre_[i]);
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

void Movie::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}


std::string Movie::displayString() const{
    std::string display_string;

    display_string += name_;
    display_string.push_back('\n');

    display_string += "Genre: ";
    display_string += genre_;

    display_string += " Rating: ";
    display_string += rating_;
    display_string.push_back('\n');

    display_string += to_string(price_);
    display_string.push_back(' ');

    display_string += to_string(qty_);
    display_string += " left.";

    return display_string;
}

