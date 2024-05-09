#include <iostream>
#include <vector>
using namespace std;

/*
Fibonacci number series
Knapsack problem
Tower of Hanoi
Shortest path by Dijkstra
Matrix chain Multiplication
*/

/*Used to solve Optimization problems (max/min) Bell-Ford, Longest common subsequence, Optimal BST
Properties of problems where DP can be applied - Overlapping sub problem, Optimal substructure
=>TC = decreased (reusing prev result - "Memoization" (cache)); SC = increased (storing subresults)*/

//---------------------------------------Fibonacci Series------------------------------------------
//Recurssion method
/*
static int count=0;
int fib(int n)  {
    count += 1;
    if (n<0)
        cout << "No negative numbers in Fibonacci series" << endl;
    if (n==0 | n==1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}
int main () {
    cout << "Fib of 10 = " << fib(10) << endl;
    cout << "Same Calculation done in fib() func = " << count << endl;      //O(2^N)
}*/

//DP  -- Memoization, top-down approach
vector <int> memo;
static int count=0;

int fib(int n)  {
    if (memo[n] != -1)
        return memo[n];
    if (n==0 | n==1)
        return n;
    else    {
        count++;
        memo[n] = fib(n-1) + fib(n-2);
    }
    
    return memo[n];
}

int main()  {
    int n=5;
    memo.resize(n+1, -1);

    memo[0] = 0;
    memo[1] = 1;

    /*Using Recursion
    cout << "Fib of 5 = " << fib(5) << endl;
    cout << "Same Calculation done in fib() func = " << count << endl;
    */

    //best approach
    //bottom-up approach
    for (int i=2; i<n+1; i++)
        memo[i] = memo[i-1] + memo[i-2];
    
    cout << "Fib of 5 = " << memo[n];
}

//-------------------------------------Coin Change Problem-----------------------------------------

