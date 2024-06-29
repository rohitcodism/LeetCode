#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Convert edge list to adjacency list
    vector<vector<int>> convertToAdjList(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        return adjList;
    }

    // Perform DFS
    void DFS(int i, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[i] = true;
        for (const auto& nodes : adjList[i]) {
            if (!visited[nodes]) {
                DFS(nodes, adjList, visited);
            }
        }
    }

    // Get ancestors of each node
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = convertToAdjList(n, edges);
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            DFS(i, adjList, visited);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (visited[j]) ans[j].push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 4}};
    
    vector<vector<int>> ancestors = solution.getAncestors(n, edges);
    
    for (int i = 0; i < n; ++i) {
        cout << "Ancestors of node " << i << ": ";
        for (int ancestor : ancestors[i]) {
            cout << ancestor << " ";
        }
        cout << endl;
    }

    return 0;
}
