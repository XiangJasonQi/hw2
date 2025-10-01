#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "product.h"
#include "user.h"
#include "mydatastore.h"
#include "util.h"

using namespace std;

void mydatastore::addProduct(Product *p)
{
    set<string> keyword = p->keywords();
    product_store_[keyword] = p;
}

void mydatastore::addUser(User *u)
{
    user_cart<User*, std::set<Product*>> new_user = {u, {}};
    user_store_.push_back(new_user);
}

std::vector<Product *> mydatastore::search(std::vector<std::string> &terms, int type)
{
    vector<Product *> search_result; 
    set<string> temp_terms(terms.begin(), terms.end());
    map<set<string>, Product*>::iterator it; 

    //0 = and, 1 = or
    if(type == 0){
        for(it = product_store_.begin(); it != product_store_.end(); ++it){
            set<string> temp_keyword;

            temp_keyword = setIntersection(temp_terms, it->first);
            if(temp_keyword.size() == temp_terms.size()){
                search_result.push_back(it->second);
            }
        }

    } else if(type == 1){
        for(it = product_store_.begin(); it != product_store_.end(); ++it){
            set<string> temp_keyword;

            temp_keyword = setIntersection(temp_terms, it->first);
            if(temp_keyword.size() != 0){
                search_result.push_back(it->second);
            }
        }
    }

    return search_result;
}

void mydatastore::dump(std::ostream &ofile)
{
    map<set<string>, Product*>::iterator it; 
    for(it = product_store_.begin(); it != product_store_.end(); ++it){
        Product* current_product = it->second;
        current_product->dump(ofile);
    }
    vector<user_cart<User*, set<Product*>>>::iterator user_it;
    for(user_it = user_store_.begin(); user_it != user_store_.end(); ++user_it){
        User* current_user = user_it->User;
        current_user->dump(ofile);
    }

}


//runs in O(n) time
int mydatastore::check_user(std::string &username)
{
    for(int i = 0; i < user_store_.size(); i++){
        if(username== user_store_[i].User->getName()){
            return i;
        }
    }

    return -1;
}


void mydatastore::view_cart(string &username, vector<Product*> &hits)
{
    int user_index = check_user(username);
    if(user_index == -1){
        cout << "Invalid username" << endl;
        return;
    }

    user_cart<User*, set<Product*>> curr_user = user_store_[user_index];

    set<Product*>::iterator it;

    for(it = curr_user.Cart.begin(); it != curr_user.Cart.end(); ++it){
        Product* curr_product = *it;
        hits.push_back(curr_product);
    }

    return;
}

void mydatastore::buy_cart(string &username)
{
    int user_index = check_user(username);
    if(user_index == -1){
        cout << "Invalid username" << endl;
        return;
    }

    user_cart<User*, set<Product*>> curr_user = user_store_[user_index];

    set<Product*>::iterator it;

    set<Product*> leftover_cart;

    for(it = curr_user.Cart.begin(); it != curr_user.Cart.end(); ++it){
        Product* curr_product = *it;
        if(curr_user.User->getBalance() > curr_product->getPrice() && curr_product->getQty() > 0){
            curr_user.User->deductAmount(curr_product->getPrice());
            curr_product->subtractQty(1);
        } else {
            leftover_cart.insert(curr_product); //does this lead to memory leak? 
        }

    }

    curr_user.Cart = leftover_cart;

}

void mydatastore::add_cart(string &username, vector<Product*> &hit_product, int hit_index)
{
    int user_index = check_user(username);
    if(user_index == -1){
        cout << "Invalid username" << endl;
        return;
    }

    user_cart<User*, set<Product*>> curr_user = user_store_[user_index];

    curr_user.Cart.insert(hit_product[hit_index]);

}
