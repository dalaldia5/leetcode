class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& graph, vector<int>& vis,
                    vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (checkCycle(it, graph, vis, dfsVis)) {
                    return true;
                }
            } else if (dfsVis[it] == 1) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> dfsVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                checkCycle(i, graph, vis, dfsVis);
            }
        }
        vector<int> safenodes;
        for (int i = 0; i < dfsVis.size(); i++) {
            if (dfsVis[i] == 0) {
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};