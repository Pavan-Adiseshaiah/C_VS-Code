#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// int main () {
//     unordered_map<int, int> umap {{1, 'a'}, {2, 'b'}, {3, 'c'}};

//     cout << char (umap[1]) << endl;            // To access
//     umap[4] = 'd';                          // Add key, values;

//     for (auto it : umap)    {
//         cout << it.first << ":" << char (it.second) << endl;
//     }

//     umap.insert(pair <int, char> (5, 'e'));

//     cout << "After insert\n";
//     for (unordered_map<int, int> :: iterator it = umap.begin(); it != umap.end(); it++)  {
//         cout << it->first << ":" << char (it->second) << endl;
//     }

//     auto res = umap.find(5);
//     if (res != umap.end())  {
//         cout << "Found\n";
//     }

//     auto res1 = umap.find(6);
//     if (res1 == umap.end())  {
//         cout << "Not Found\n";
//     }

// }

int findShortestSubarray(vector<int>& nums) {
    unordered_map<int, int> count;
    unordered_map<int, int> firstOccurrence;
    int maxDegree = 0;
    int minLength = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i]]++;
        if (firstOccurrence.find(nums[i]) == firstOccurrence.end()) {       // If first occurance
            firstOccurrence[nums[i]] = i;
        }

        if (count[nums[i]] == maxDegree) {
            minLength = min(minLength, i - firstOccurrence[nums[i]] + 1); // min is important => 2 nums degree is equal
        } else if (count[nums[i]] > maxDegree) {
            maxDegree = count[nums[i]];
            minLength = i - firstOccurrence[nums[i]] + 1;
        }
    }

    for (auto i : count)    {
        cout << i.first << endl;
    }

    return minLength;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 1};
    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};

    int result1 = findShortestSubarray(nums1);
    int result2 = findShortestSubarray(nums2);

    cout << result1 << endl;     // Output: 2
    cout << result2 << endl;    // Output: 6

    string str = "abcdef";

    char c = str[0];

    cout << c << endl;

    exit (EXIT_SUCCESS);
}
