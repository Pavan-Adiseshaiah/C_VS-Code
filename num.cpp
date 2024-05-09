#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int specialArray(vector<int>& nums) {

//     for (int i=1; i<=nums.size(); i++)   {
//         int count = 0;

//         for (auto num : nums)    {
//             if (num >= i)   {
//                 count++;
//             }
//         }

//         if (count == i) {
//             return i;
//         }
//     }

//     return -1;
    
// }

 int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++){
            if (nums[n-1-i] < i && i <= nums[n-i]){
                return i;
            }
        }
        if (n <= nums[0]) return n;
        return -1;
    }

int main () {
    vector<int> nums {0, 700, 0, 800, 900};

    cout << "result: " << specialArray(nums);
}