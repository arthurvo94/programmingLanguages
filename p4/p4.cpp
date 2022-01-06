/*
 * Program p4 - provides operator overloaded vesion of the '++' operator
 * Arthur Vo
 * CS 320
 * 11/12/2021
 */

#include <iostream>
using namespace std;

//interface class
class Counter{
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
};

//constructor implementation
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

//tester
int  main() {
  Counter c1, c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  ++c1;
  for(int i =0; i < 100; ++i)
     ++c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  c1++;
  c2++;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  Counter c3;
  Counter c4(2);
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = c4++;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = ++c4;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  return 0;
}
