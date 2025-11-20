class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        vector<vector<int>> adj(numCourses);
        // preparing adjacency matrix
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        // setting up the indegree array
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                // indegree[it]-- because the node has already been added to
                // topo
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo.size() == numCourses;
    }
};