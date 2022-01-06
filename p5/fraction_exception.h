/* 
   File:        fraction_exception.h
   Author:      Arthur Vo
   Description: Header file for class Fraction_Exception
*/

#include <cstdlib>  // stdlib.h for C++
#include <exception>

using namespace std;

class FractionException: public exception{
public:
    const char* what() const throw(){
        return  "ZeroDivisonError";
    }
};