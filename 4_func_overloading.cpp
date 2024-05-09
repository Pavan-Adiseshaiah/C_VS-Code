#include <iostream>

using namespace std;
/*
Two or more functions in the same scope have the same name but different parameters.
Function are called overloaded functions.
You can overload both member functions and free functions
Function overloading can be considered as an example of a "Polymorphism" feature in C++.
Overloaded functions cannot differ "only in the return types!"

How does Function Overloading work?
1) Exact match:- (Function name and Parameter)
2) If not a exact match:–
    ->Char, Unsigned char, and short are promoted to an int.
    ->Float is promoted to double
3) ELSE ERROR
*/
int sum (int a, int b)  {
    return a + b;
}

float sum (float a, float b)  {
    return a + b;
}

double sum (double a, double b, double c)   {
    return a + b + c;
}

int main () {
    cout << sum (3, 4) << endl;
    cout << sum (float(3.5), float(5.3)) << endl;       //default considers double. Therefore typecast
    cout << sum (3.4, 5.3, 3.8) << endl;

}