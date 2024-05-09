#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/*If a given number is a power of 4?*/

bool ispow4(int n) {    // 100, 10000, 1000000.  10, 100, 1000, 10000, 100000, 1000000
    if (n<=0)   {
        return false;
    }
    
    int mask = 0;
    int i = sizeof(n) * 2;                // sizeof int = 4 ==> 4*2 = 8
    
    while (i)   {
        mask = (mask << 4) | 0x05;      // 0101 0101 --> 4*8 = 32 bits (4 bits each time)
        i--;
    }
    
    return ((n & (n-1)) == 0) && ((n & mask) == n);
    
    
}


 
// Driver Code
int main()
{
   if (ispow4(256))  {
       cout << "Number is power of 4" << endl;
   } else   {
       cout << "Not a power of 4" << endl;
   }
   
   return 0;
}
