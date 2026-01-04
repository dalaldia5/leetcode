class Solution {
public:
    void dfs(int node, vector<int>& vis, stack<int>& st,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> topo;
        vector<vector<int>> adj(n);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        while (!st.empty()) {
            int node = st.top();
            topo.push_back(node);
            st.pop();
        }
        for (int i = 0; i < queries.size(); i++) {
            for (int i = 0; i < n; i++) {
                vis[i] = 0;
            }
            int u = queries[i][0];
            int v = queries[i][1];
            dfs(u, vis, st, adj);
            if (vis[v]) {
                ans[i] = true;
            }
        }
        // for (int i=0; i<topo.size(); i++){
        //     cout<<topo[i];
        // }
        return ans;
    }
};