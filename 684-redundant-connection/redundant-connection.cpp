class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, adj, vis)) {
                    return true;
                }
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            vector<int> vis(n + 1, 0);
            // jis bhi edge ko add krke cycke bnegi, usko return kr denge
            if (dfs(it[0], -1, adj, vis)) {
                return it;
            }
        }
        return {};
    }
};