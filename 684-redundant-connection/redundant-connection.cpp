class Solution {
public:
// cycle detection using bfs
    bool detectCycle(int node, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;
        while (!q.empty()) {
            int src = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[src]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, src});
                } else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<int> vis(n + 1, 0);
            if (detectCycle(u, adj, vis)) {
                return e;
            }
        }
        return {};
    }
};
