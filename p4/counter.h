/*
 * counter.h - Interface for Counter class
 * Arthur Vo
 * CS 320
 * 11/12/2021
 */
#ifndef COUNTER_H       // If stuff in this file is not defined yet
#define COUNTER_H       // then define it beginning here.

class Counter {
public:
    //constructors
    Counter();
    Counter(int);

    //function members
    int getCount();
    Counter operator++();
    Counter operator++(int);
private:
    int val;

};    // The class definition goes here,

#endif                  // and the definition ends here.