#include <iostream>
#include <algorithm>

using namespace std;
/*
Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort, Radix Sort, Tim Sort
*/

void Bubble_Sort(int arr[], int n) {                //Worst case TC = O(N^2), Space Complexity = O(1)
    bool swapped;                                   //Best case TC = O(N); because of swapped

    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {            //Sorting R -> L
            if(arr[j] > arr[j + 1]) {               // change the sign for descending order.
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Selection_Sort(int *arr, int n) {  //Reduces no of swaps. Comparison remains same
                                        //TC = O(N^2), Space Complexity = O(1)
    for(int i = 0; i < n-1; i++) {
        int min = i;                   //Only the index no is noted. Swapping once every iteration
        for(int j = i+1; j < n; j++) {  //Sorting L -> R
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void Insertion_Sort(int arr[], int n) { //For Partial sorted arrays. TC = O(N^2), Space Complexity = O(1)
    for(int i = 1; i < n; i++) {        //Left of i is sorted.
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) { //j goes from ith index to 0.
            arr[j + 1] = arr[j];        //Values greater than key are moved to right
            j--;                        //and key is inserted at the leftmost place
        }
        arr[j + 1] = key;
    }
}

//--------------------------------------Merge Sort-----------------------------------------------------
void merge (int *arr, int lb, int mid, int ub)    { //Create 2 sub arrays and Merge them
    int l_size = mid - lb + 1;                      //Determines left sub-array size
    int r_size = ub - mid;                          //Right sub array size
    int L[l_size], R[r_size];

    for (int i=0; i < l_size; i++)
        L[i] = arr [lb + i];
    
    for (int j=0; j < r_size; j++)
        R[j] = arr [mid + 1 + j];
    

    int i = 0, j = 0;
    int k = lb;

    while (i < l_size && j < r_size) {              //Merge
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < l_size)
        arr[k++] = L[i++];
    
    while (j < r_size)
        arr[k++] = R[j++];
}

void Merge_Sort (int *arr, int lb, int ub)  {       //Recursive. Divide & Conquer
    if (lb < ub)    {                               //Time Complexity = O(Nlog(N))
        int mid = (lb + ub) / 2;                    //logN => to Divide the original array
        Merge_Sort (arr, lb, mid);                  //N => To merge (compare all N elements in worst case)
        Merge_Sort (arr, mid + 1, ub);              //Space Complexity = O(N)
        merge (arr, lb, mid, ub);                   //N extra space required before merging.
    }
}

//----------------------------------Quick Sort--------------------------------------------------------
//pivot=1st element of sub-array. Sort such that elements <= pivot are on the left, > pivot on the right.
//returns index of pivot.
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];    // Choose pivot as 1st element
    int start = lb;         //better choose pivot => sort 1st, mid and last, pivot = mid
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot & start < ub)
            start++;                    //element less than pivot. No swapping
        while (arr[end] > pivot)        //element greater than pivot. No swapping
            end--;
        if (start < end)                //found elements, less than and greater than pivot => Swap
            swap (arr[start], arr[end]);
    }                                    //start & end overlapped => end <= pivot. Therefore swap
    swap (arr[end], arr[lb]);           //Swap the pivot and return the pivot index
    return end;
}

//Quick_Sort function recursively partitions the array around the pivot,
//and then sorts the sub-arrays before and after the pivot.
void Quick_Sort(int arr[], int lb, int ub) {//SC=O(log N) - best, O(N) - worst.
    if (lb < ub) {          //TC = O(NLog(N))->avg, N-partitioning, (log N)-height. O(N^2)->worst case.
        int pi = partition(arr, lb, ub);    //pi = pivot index

        // Recursively sort elements before partition and after partition
        Quick_Sort(arr, lb, pi-1);      //element at pi i,e pivot is at the correct place already!
        Quick_Sort(arr, pi+1, ub);
    }
}

//------------------------------------------Heap Sort-------------------------------------------------
//Max Heap - Parent >= children --> Used to sort in increasing order.
//           Insertion  - At leaf. L->R, compare with parent and swap if required.  TC = O(Log N)
//           Deletion   - Delete Root, replace with last leaf (rightmost).
//                        Compare with highest child and swap.                      TC = O(Log N)
//Min Heap - Parent <= children --> Used to sort in decreasing order.
//Heap Sort - Insertion + Deletion = O(N LogN) + O(N Log N) = O(2(N LogN)) = O(NLogN); for N values.
//            To reduce to O(N), Use Heapify
//Heapify -> To get the max Heap (or min Heap) instead of insertion method.
//Heapify only on non leaf nodes.
//In a Balanced (almost) tree -> leaf nodes = (n/2) to (n-1).
void heapify (int arr[], int n, int i)  {   //To create Max Heap
    int largest = i;
    int l = 2*i+ 1;         //left child
    int r = 2*i+ 2;         //right child

    if (l < n && arr[l] > arr[largest]) //check if left node is bigger than the root
        largest = l;

    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    
    if (largest != i) {             //if root value is not largest.
        swap(arr[i], arr[largest]); //Swap the largest element with root.
        heapify(arr, n, largest);   //Recursively heapify affected sub-tree. Because of swapping above.
    } 
}

void Heap_Sort (int *arr, int n)    {
    int i;                          //TC = O(N*Log N), SC = O(1)

    for (i=n/2-1; i>-1; i--)        //Create a max Heap. Pass only non leaf nodes. (Insertion)
        heapify (arr, n, i);        //i = non leaf node i,e root of a sub tree; n = heap size
    
    for (i=n-1; i>-1; i--)  {       //Deletion is at the root. Deletion => Sorting. Sorting is from largest to smallest (R->L).
        swap (arr[0], arr[i]);      //Delete root and replace with the last element.
        heapify (arr, i, 0);        //i=size after deleting the element, 0=root index
    }
}

//--------------------------------------------Radix Sort-----------------------------------------------
//Count Sort works only for +ve (Or else make the lowest -ve number 0. Add that value to all other nums)
//Good if the range(k) is less or comparable with n. Bad when k=n^2. Eg: n=100, k=(0 to 10,000)
void Count_Sort (int *arr, int n, int pos)  {
    int count[10] = {0};                    //Base 10
    int output [n];                         //TC = O(n+k), k=range, SC = O(n+k)
    int i;

    for (i=0; i < n; i++)                   //To get count of each num based on pos
        count [(arr[i]/pos)%10]++;          //To get the index value of count for pos.

    for (i=1; i<10; i++)                    //To get actual pos of each num in the sorted array.
        count[i] += count [i-1];
    
    for (i = n-1; i >=0; i--)               //R->L to maintain stability
        output[--count[(arr[i]/pos)%10]] = arr[i];  //copy in ascending order after each pass.
    
    for (i=0; i < n; i++)                   //Update the original array
        arr[i] = output [i];
}

void Radix_Sort (int *arr, int n)   {
    int max=0;                                  //TC = O(d*(n+k)), d = num width, SC = O(n+k)
    //max = *std::max_element (arr, arr + n);   //defined in algorithm
    for (int i=0; i <n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int pos=1; max/pos > 0; pos *= 10)
        Count_Sort (arr, n, pos);
}

int main () {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    //Bubble_Sort (arr, n);
    //Selection_Sort (arr, n);
    //Insertion_Sort (arr, n);
    //Merge_Sort (arr, 0, n-1);
    //Quick_Sort (arr, 0, n-1);
    //Heap_Sort (arr, n-1);
    Radix_Sort (arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}