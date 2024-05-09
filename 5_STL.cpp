// STL - Standard Template Libraries
// Allows to define templates for the compiler so that it can generate the code later on the fly.
// Can be applied to both func and classes

#include <iostream>
#include <vector>

using namespace std;

// template <class T>
// void print (const T &obj)   {
//     cout << obj << endl;
// }
// int main () {            //Here, print template is intantiated twice - int, float
//     print (3);           //print <int> (3)
//     print (3.3);        //print <float> (3.3)
// }

//------------------------------------------Templates vs Function Overloading------------------------------------------------------

template <typename T>
T add (const T &a, const T &b) {        // const ==> using values (3, 5) directly. If variables used, not required.
    return a + b;
}

// Function overloading
int add_fo (const int &a, const int &b)    {
    return a + b;
}

double add_fo (const double &a, const double &b)  {
    return a + b;
}

int main () {
    cout << add (3, 5) << endl;              //add <int>
    cout << add (2.5, 3.5) << endl;

    cout << add_fo (3, 5) << endl;
    cout << add_fo (3.5, 1.5) << endl;
}

// ------------------------------------------------------Templates-----------------------------------------------------
// Allow you to have generic code that works with variety of types without duplicating code.
// Support for new type => no new code to be added
// Compiler error messages become complex.

// ---------------------------------------------------Function Overloading----------------------------------------------
// Explicit control over different implementations of different types
// Duplicate code - Logic / code same for different types.
// Support for new type => creating a new overloaded function.



// ------------------------------------------------------Flexible template-----------------------------------------------
template <typename T, typename U>
auto add (const T &a, const U &b) -> decltype (a + b)  {
    return a + b;
}

int main () {
    cout << add (3, 5) << endl;
    cout << add (2.5, 3.5) << endl;
    cout << add (3.5, 3) << endl;                       // add <double, int>
}

//Standard STLs
/*
array <int, 5> a;                            // Array = Static array. Can't add or delete items.
vector <double> v;                          // Vector = Dynamic array
list <double> dl;                          // Doubly Linked List
deque <double> dq;                        // Doubly ended Queue
forward_list <double> fl;                // Singly Linked list
map <int, int> m;                       // Key-Value pairs. Ordered by Keys
unordered_map <int, int> um;           // Key-Value pairs. Hashmap (Similar to dict in Python)
*/

// -----------------------------------Iterators-------------------------------------------------
// To iterate between elements in a Data Structure
// it = it -> next same as it++ for Linked List
// Common Member functions
