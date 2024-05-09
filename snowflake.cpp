#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findMaxLength(vector<int> skills, int k) {
    int n = skills.size();
    int maxLength = 0;
    unordered_map<int, int> skillCount;

    int start = 0, end = 0;

    while (end < n) {
        skillCount[skills[end]]++;

        while (end - start + 1 - max_element(skillCount.begin(), skillCount.end(),
                                     [](const auto& a, const auto& b) { return a.second < b.second; })->second > k) {
            skillCount[skills[start]]--;
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    return maxLength;
}

int main() {
    // Example usage
    vector<int> skills = {1, 1, 2, 3, 2, 1};
    int k = 2;

    int result = findMaxLength(skills, k);
    cout << "The length of the longest subsequence: " << result << endl;

    return 0;
}