/*
 * counter.cpp - Implementation of counter class
 * Arthur Vo
 * CS 320
 * 11/12/2021
 */
#include "counter.h"
using namespace std;

Counter::Counter(){ val = 0; }
Counter::Counter(int x){ val = x; }

//fucntion member implementation
int Counter::getCount(){ return val; }
Counter Counter::operator++(){
    Counter c;
    c.val = ++val;
    return c;
}
Counter Counter::operator++(int){
    Counter c;
    c.val = val++;
    return c;
}