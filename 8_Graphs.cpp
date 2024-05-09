/*
Popular methods to representing graphs
1) Adjacency Matrix - 
2) Adjacency List
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinMaxLatency(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int k) {
    vector<vector<pair<int, int>>> g(g_nodes + 1);

    for (size_t i = 0; i < g_from.size(); i++) {
        g[g_from[i]].emplace_back(g_to[i], g_weight[i]);
        g[g_to[i]].emplace_back(g_from[i], g_weight[i]);
    }

    for (int mx_wt : g_weight) {
        int cc = 0;
        vector<int> vis(g_nodes + 1, 0);

        for (int i = 1; i <= g_nodes; ++i) {
            if (vis[i]) {
                continue;
            }

            vector<int> q = {i};
            vis[i] = 1;
            cc += 1;

            for (size_t j = 0; j < q.size(); ++j) {
                int u = q[j];

                for (auto& edge : g[u]) {
                    int ch = edge.first;
                    int wt = edge.second;

                    if (wt <= mx_wt && vis[ch] == 0) {
                        vis[ch] = 1;
                        q.push_back(ch);
                    }
                }
            }
        }

        if (cc <= k) {
            return mx_wt;
        }
    }

    return 0;
}

/*
Graph Initialization: vector<vector<pair<int, int>>> g(g_nodes + 1); initializes an adjacency list for the graph.
Populating the Graph: A loop fills the adjacency list based on the input g_from, g_to, and g_weight vectors.
Main Loop: The function then iterates through the sorted edge weights (mx_wt) in ascending order.
Depth-First Search (DFS): For each weight, it performs a DFS to count the number of connected components.
Connected Components Count: The connected components count (cc) is compared with the input parameter k.
Result Calculation: If the count of connected components is less than or equal to k, the function returns the current maximum weight (mx_wt).
Fallback: If no suitable weight is found, it returns 0.
*/

int main() {
    // int g_nodes = 3;
    // int k = 1;
    // vector<int> g_from = {1, 3, 1};
    // vector<int> g_to = {2, 2, 3};
    // vector<int> g_weight = {3, 4, 6};

    int g_nodes = 2;
    int k = 1;
    vector<int> g_from = {1};
    vector<int> g_to = {2};
    vector<int> g_weight = {3};

    int result = getMinMaxLatency(g_nodes, g_from, g_to, g_weight, k);
    cout << result << endl;

    return 0;
}
