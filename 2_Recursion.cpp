#include <iostream>

using namespace std;

int recursive_sum (int m, int n)    {
    if (m == n)
        return m;
    return m + recursive_sum (m+1, n);
}

int factorial (int n)   {
    if (!n)
        return 1;
    return n * factorial (n - 1);
}

int main () {
    cout << "Recursive sum = " << recursive_sum (1, 9) << endl;
    cout << "Factorial = " << factorial(6) << endl;
}