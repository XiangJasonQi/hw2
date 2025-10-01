#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"

#include "datastore.h"


//need to store product and user in some fashion, need to save the database, need to be able to search 

template <class T1, class T2>
struct user_cart {
    T1 User;
    T2 Cart;
};

class mydatastore : public DataStore{

public: 

    ~mydatastore() { }
    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */

    void dump(std::ostream& ofile);

    //check if the username exist, return true if exist. 

    int check_user(std::string &username);

    //input username, first check if it is there, then output all the items in cart using dump.

    void view_cart(std::string &username, std::vector<Product*> &hits);

    //buy item from the cart 

    void buy_cart(std::string &username);

    //add item into the cart

    void add_cart(std::string &username, std::vector<Product*> &hit_product, int hit_index);






private: 
    std::map<std::set<std::string>, Product*> product_store_;
    std::vector<user_cart<User*, std::set<Product*>>> user_store_; 

};

#endif