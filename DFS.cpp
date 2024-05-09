#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(const vector<int>& employees, int current_employee, unordered_set<int>& visited, unordered_set<int>& group) {
    visited.insert(current_employee);
    group.insert(current_employee);

    int next_employee = 1;
    while (next_employee <= employees.size()) {
        if (employees[current_employee] & (1 << next_employee)) {
            if (visited.find(next_employee) == visited.end()) {
                dfs(employees, next_employee, visited, group);
            }
        }
        next_employee++;
    }
}

vector<unordered_set<int>> findGroups(const vector<int>& employees) {
    vector<unordered_set<int>> groups;
    unordered_set<int> visited;

    for (int i = 0; i < employees.size(); ++i) {
        if (visited.find(i) == visited.end()) {
            unordered_set<int> group;
            dfs(employees, i, visited, group);
            groups.push_back(group);
        }
    }

    return groups;
}

int main() {
    vector<int> employees = {8, 16, 24}; // Example input

    vector<unordered_set<int>> groups = findGroups(employees);

    cout << "Groups of employees who work together:" << endl;
    for (int i = 0; i < groups.size(); ++i) {
        cout << "Group " << i << ": ";
        for (int employee : groups[i]) {
            cout << employee << " ";
        }
        cout << endl;
    }

    return 0;
}
