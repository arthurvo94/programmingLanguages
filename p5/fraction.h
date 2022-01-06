/* 
   File:        Fraction.h
   Author:      Arthur Vo
   Description: Header file for class Fraction
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <cstdlib>  // stdlib.h for C++
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Fraction{

   // Overloaded stream insertion and extraction operators
   friend ostream& operator<<(ostream&, const Fraction&);
   friend istream& operator>>(istream&, Fraction&);

   public:
      Fraction(int,int=1);       // constructor
      Fraction();                // constructor

      void setNumbers(int,int);
      float getFloat(void);

      // Overloaded assignment operator
      Fraction& operator=(const Fraction &);

      // Overloaded relational operators
      int operator==(const Fraction &) const;
      int operator!=(const Fraction &) const;
      int operator>(const Fraction &) const;
      int operator>=(const Fraction &) const;
      int operator<(const Fraction &) const;
      int operator<=(const Fraction &) const;

      // Overloaded arithmetic operators
      Fraction operator+(const Fraction &);
      Fraction operator-(const Fraction &);
      Fraction operator*(const Fraction &);
      Fraction operator/(const Fraction &);
      Fraction& operator+=(const Fraction &);
      Fraction& operator-=(const Fraction &);
      Fraction& operator*=(const Fraction &);
      Fraction& operator/=(const Fraction &); 

   private:
      void reduceFraction();
      int num,den;
};

#endif

//  *****   END OF FILE fraction.H   *****