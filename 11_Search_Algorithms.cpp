#include <iostream>

using namespace std;
/*
Linear Search, Binary Search, Depth First Search (DFS), Breadth First Search (BFS), Jump Search
*/
int Linear_Search (int arr[], int n, int num)   {
    for (int i=0; i<n; i++)                     //TC=O(N), SC=O(1)
        if (arr[i] == num)
            return i;
    
    return -1;
}

int Binary_Search (int *arr, int l, int r, int num)    {   //Array must be sorted!
    while (l<=r)    {                           //TC = O(Log N), SC = O(1)
        int mid = (l+r)/2;

        if (arr[mid] == num)
            return mid;

        if (arr[mid] < num)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

//--------------------------------------Depth First Search--------------------------------------------
/*
For searching/traversing in Tree or Graph DS.
Starts at root. Arbitrary node in case of graph*/


int main()  {
    int arr [] = {5, 7, 12, 15, 33, 46, 50};
    int n = sizeof(arr) / sizeof (arr[0]);
    
    int result = Linear_Search (arr, n, 33);
    //int result = Binary_Search (arr, 0, n-1, 33);

    if ( result == -1)
        cout << "Number not found" << endl;
    else
        cout << "Number found at index: " << result << endl;
    
    return 0;
}