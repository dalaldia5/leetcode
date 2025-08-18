class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Adjacency list to store graph: adj[node] = list of {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);

        // Build the graph from edges
        // Each edge is of the form {u, v, w}
        for (auto e : edges) {
            // Add edge u -> v with cost w
            adj[e[0]].push_back(make_pair(e[1], e[2]));
            // Add edge v -> u with cost 2*w (asymmetric edge cost)
            adj[e[1]].push_back(make_pair(e[0], 2 * e[2]));
        }

        // Distance array, initialized to infinity (INT_MAX means not visited
        // yet)
        vector<int> dist(n, INT_MAX);

        // Min-heap (priority queue) storing {distance, node}
        // greater<> makes it a min-heap (smallest distance at top)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Start from node 0 with distance = 0
        pq.push({0, 0});

        // Dijkstra’s algorithm main loop
        while (pq.size()) {
            // Extract node with smallest distance
            auto [d, v] = pq.top();
            pq.pop();

            // If node v is already finalized (visited), skip it
            if (dist[v] != INT_MAX)
                continue;

            // Otherwise, assign its shortest distance
            dist[v] = d;

            // Explore neighbors of v
            for (auto [x, w] : adj[v]) {
                // If neighbor x hasn’t been visited yet
                if (dist[x] == INT_MAX) {
                    // Push new possible distance to priority queue
                    pq.push({w + d, x});
                }
            }
        }

        // If the last node (n-1) is unreachable, return -1
        if (dist.back() == INT_MAX) {
            return -1;
        } else {
            // Otherwise return its shortest distance
            return dist.back();
        }
    }
};
