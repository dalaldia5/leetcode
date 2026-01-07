class Solution {
public:
    //  cycle detection using dsu
    int find(int u, vector<int>& parent) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u], parent);
    }

    void dfsUnion(int u, int v, vector<int>& parent, vector<int>& rank) {
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);
        if (u_parent == v_parent)
            return;
        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } else if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } else {
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    bool cycleDetect(int node, int V, vector<int>& vis,
                     vector<vector<int>>& adj) {
        vector<int> parent(V+1);
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }
        vector<int> rank(V+1, 0);
        for (int u = 1; u <= V; u++) {
            for (auto v : adj[u]) {
                if (u < v) {
                    int u_parent = find(u, parent);
                    int v_parent = find(v, parent);
                    if (u_parent == v_parent) {
                        return true;
                    } else {
                        dfsUnion(u, v, parent, rank);
                    }
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> vis(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            if (!vis[u]) {
                if (cycleDetect(u, n, vis, adj)) {
                    return it;
                }
            }
        }
        return {};
    }
};