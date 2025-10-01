#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> intersection;
    typename std::set<T>::const_iterator it;

    for(it = s1.begin(); it != s1.end(); ++it){
        if(s2.find(*it) != s2.end()){
            intersection.insert(*it);
        }
    }

    return intersection;
}

template <typename T>
std::set<T> setUnion(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> union_set;
    typename std::set<T>::const_iterator it;

    std::set<T> temp_intersect;

    for(it = s1.begin(); it != s1.end(); ++it){

        union_set.insert(*it);

        if(s2.find(*it) != s2.end()){
            temp_intersect.insert(*it);
        } 

    }

    int size = temp_intersect.size();

    while(s2.size() - size != 0){
        for(it = s2.begin(); it != s2.end(); ++it){
            if(temp_intersect.find(*it) == temp_intersect.end()){
                union_set.insert(*it);
                size++;
            }
        }
    }

    return union_set;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
