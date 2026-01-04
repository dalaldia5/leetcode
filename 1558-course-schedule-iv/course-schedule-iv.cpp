class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> ans(queries.size(), false);
        // bfs
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vector<int> vis(n, 0);
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            for (int j = 0; j < queries.size(); j++) {
                if (queries[j][0] == i && vis[queries[j][1]]) {
                    ans[j] = true;
                }
            }
        }
        return ans;
    }
};
