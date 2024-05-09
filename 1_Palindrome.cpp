#include <iostream>

using namespace std;

int main () {
    int n, num, temp=0;

    cout << "Enter a num: ";
    cin >> n;

    num = n;
    if (num < 0)    {
        cerr << "Enter a positive number" << endl;
        exit (EXIT_FAILURE);
    }
    else    {
        while (num != 0)    {
            temp = temp * 10 + num % 10;
            num /= 10;
        }
    }
    if (n == temp)
        cout << "Number is a Palindrome." << endl;
    else
        cout << "Number is not a Palindrome" << endl;
    
    exit (EXIT_SUCCESS);
}