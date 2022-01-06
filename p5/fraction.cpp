/* 
   File:        fraction.cpp
   Author:      Arthur Vo
   Description: Implementation for class Fraction and Fraction_Exception
*/

#include <cstdlib>  // stdlib.h for C++
//include header files
#include "fraction.h"
#include "fraction_exception.h"

using namespace std;

//      FRACTION CLASS IMPLEMENTATION     //
// Constructors
Fraction::Fraction(int n, int d){
    num = n;
    den = d;
    this->reduceFraction();
}
Fraction::Fraction() : Fraction(0){}

//Function members
void Fraction::setNumbers(int n, int d){
    this->num = n;
    this->den = d;

//    cout << "num: " << num << " den: " << den << endl;
    this->reduceFraction();
}
float Fraction::getFloat(){
    return (float) num / (float) den;
}

/* reduceFraction()
 * Uses Euclid's Algorithm to find the greatest common divisor
 * Simplify fraction by dividing num and den by divisor
 * Handle negative denominator
 */
int gcd(int a, int b){  //helper function for reduceFraction
    int x = abs(a), y = abs(b), r;

    while(y > 0){
        r = x%y;

        x = y;
        y = r;
    }
    return x;
}
void Fraction::reduceFraction(){
    if(den == 0)
        throw FractionException();

    //negative denominator handling
    if(den < 0){
        if(num < 0){ //num negative and den negative
            num = abs(num);
            den = abs(den);
        }
        else{       //num positive and den negative
            num = -num;
            den = abs(den);
        }
    }

    int divisor = gcd(num, den);
//    cout << "divisor: " << divisor << endl;
    num /= divisor;
    den /= divisor;
}

//Overloaded Operators
Fraction& Fraction::operator=(const Fraction & f){
    num = f.num;
    den = f.den;
    return *this;
}

//Assignment operators
int Fraction::operator==(const Fraction & f) const{
    // if(num==f.num && den==f.den)
    //     return 1;
    return num==f.num && den==f.den;
}
int Fraction::operator!=(const Fraction & f) const{
    // if(*this==f)
    //     return 0;
    // return 1;
    // return !(num==f.num && den==f.den);
    return !(*this==f);
}
int Fraction::operator>(const Fraction & f) const{
    return ((float) num / (float) den) > ((float) f.num / (float) f.den);
}

int Fraction::operator>=(const Fraction & f) const{
    return ((float) num / (float) den) >= ((float) f.num / (float) f.den);
}

int Fraction::operator<(const Fraction & f) const{
    return ((float) num / (float) den) < ((float) f.num / (float) f.den);
}

int Fraction::operator<=(const Fraction & f) const{
    return ((float) num / (float) den) <= ((float) f.num / (float) f.den);
}

//Arithmetic operators
Fraction Fraction::operator+(const Fraction & f){
    Fraction out(num * f.den + den * f.num, den * f.den);
    out.reduceFraction();
    return out;
}
Fraction Fraction::operator-(const Fraction & f){
    Fraction out(num * f.den - den * f.num, den * f.den);
    out.reduceFraction();
    return out;
}
Fraction Fraction::operator*(const Fraction & f){
    Fraction out(num * f.num, den * f.den);
    out.reduceFraction();
    return out;
}
Fraction Fraction::operator/(const Fraction & f){
    Fraction out(num * f.den, den * f.num);
    out.reduceFraction();
    return out;
}
Fraction& Fraction::operator+=(const Fraction & f){
    this->num = num * f.den + den * f.num;
    this->den *= f.den;
    this->reduceFraction();
    return *this;
}
Fraction& Fraction::operator-=(const Fraction & f){
    this->num = (num * f.den) - (den * f.num); 
    this->den *= f.den;
    this->reduceFraction();
    return *this;
}
Fraction& Fraction::operator*=(const Fraction & f){
    this->num *= f.num;
    this->den *= f.den;
    this->reduceFraction();
    return *this;
}
Fraction& Fraction::operator/=(const Fraction & f){
    this->num *= f.den;
    this->den *= f.num;
    this->reduceFraction();
    return *this;
}

//Stream operators
ostream& operator<<(ostream& output, const Fraction& f){
    if(f.num == 0) //num = 0
        output << 0;
    else if(f.den == 1) //den = 1
        output << f.num;
    else    // print format "a/b"
        output << f.num << '/' << f.den;
    return output;
}
istream& operator>>(istream& input, Fraction& f){
    string in;
    input >> in;

    int pos = in.find("/");
    f.num = stoi(in.substr(0, pos));
    f.den = stoi(in.substr(pos + 1));


    f.reduceFraction();
    return input;
}