class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for (int i=0; i<n; i++){
            if (indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};