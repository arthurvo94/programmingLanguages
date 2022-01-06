/* 
   File:        driver.cpp
   Author:      Arthur Vo
   Description: Driver for class Fraction
*/

#include "fraction.h"
#include "fraction_exception.h"

using namespace std;

void operatorTester(){
    //Test constructors
    Fraction f1, f2(1,5);
    Fraction f3(38,4);
    cout << "Testing: Constructors Expected: f1: 0 f2: 1/5 f3: 19/2" << endl;
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f3: " << f3 << endl << endl;

    //Test =
    cout << "Testing: '=' Expected: f1: 1/5" << endl;
    cout << "f1: " << f1 << endl;
    f1 = f2;
    cout << "f1 = f2: " << f1 << endl << endl;

    //Test ==
    cout << "Testing: '==' Expected: 1" << endl;
    cout << "f1 == f2: " << (f1 == f2) << endl << endl;

    //Test !=
    cout << "Testing: '!=' Expected: 0" << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl << endl;

    //Test >
    cout << "Testing: '>' Expected: 1" << endl;
    f1.setNumbers(2,5); //f2 = 1/5
    cout << "f1 > f2: " << (f1 > f2) << endl << endl;

    //Test >=
    cout << "Testing: '>=' Expected: 1" << endl;
    cout << "f1 >= f2: " << (f1 >= f2) << endl << endl;

    //Test <
    cout << "Testing: '<' Expected: 0" << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl << endl;

    //Test <=
    cout << "Testing: '<=' Expected: 0" << endl;
    cout << "f1 <= f2: " << (f1 <= f2) << endl << endl;

    f1.setNumbers(17, 32);
    f2.setNumbers(24, 120);
    cout << "f1: " << f1;
    cout << "f2: " << f2;
    //Test +
    cout << "Testing: '+' Expected: 117/160" << endl;
    cout << "f1 + f2: " << (f1 + f2) << endl << endl;

    //Test -
    cout << "Testing: '-' Expected: 53/160" << endl;
    cout << "f1 - f2: " << (f1 - f2) << endl << endl;

    //Test *
    cout << "Testing: '*' Expected: 17/160" << endl;
    cout << "f1 * f2: " << (f1 * f2) << endl << endl;

    //Test /
    cout << "Testing: '/' Expected: 85/32" << endl;
    cout << "f1 / f2: " << (f1 / f2) << endl << endl;

    //Test +=
    cout << "Testing: '+=' Expected: 117/160" << endl;
    f1 += f2;
    cout << "f1 += f2: " << f1 << endl << endl;

    //Test -=
    cout << "Testing: '-=' Expected: 53/160" << endl;
    f1.setNumbers(17,32);
    f1 -= f2;
    cout << "f1 -= f2: " << f1 << endl << endl;

    //Test *=
    cout << "Testing: '*=' Expected: 17/160" << endl;
    f1.setNumbers(17,32);
    f1 *= f2;
    cout << "f1 *= f2: " << f1 << endl << endl;

    //Test /=
    cout << "Testing: '/=' Expected: 85/32" << endl;
    f1.setNumbers(17,32);
    f1 /= f2;
    cout << "f1 /= f2: " << f1 << endl << endl;
}

void exceptionTester(){
//    Exception test
    Fraction f1;
    f1.setNumbers(1,0);
    cout << "Error expected" << endl;
    cout << "f1: " << f1;
}

void instreamTester(){
    Fraction f;
    cout << "Enter fraction in the format 'a/b': " << endl;
    cin >> f;
    cout << "f: " << f << endl;
}

void additionTester(){
    Fraction f1(1,5), f2(-1, 5);
    cout << "f1: " << f1 << " f2: " << f2 << endl;
    cout << (f1 + f2) << endl;
}

void extraTester(){
    Fraction e(24, -5);
    cout << e << endl;
}

int main(){
try{
//    operatorTester();
//    exceptionTester();
//    instreamTester();
//    additionTester();
    extraTester();

    return 0;
}
catch(const FractionException& e){
    cerr << e.what() << endl;
    return 0;
}
}

