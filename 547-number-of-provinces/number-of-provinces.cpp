class Solution {
public:
    // Find the connected components of an undirected graph given adjacency
    // matrix
    void dfs(int idx, vector<int>& vis, vector<vector<int>>& M) {
        vis[idx] = 1;
        for (auto i = 0; i < M[idx].size(); i++) {
            if (!vis[i] && M[idx][i] == 1)
                dfs(i, vis, M);
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        vector<int> vis(M.size(), 0);
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, M);
            }
        }

        return count;
    }
};