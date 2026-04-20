class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    unordered_map<long long, int> mpp;
    
    for (auto row : wall) {
        long long pos = 0;
        for (int i = 0; i < row.size() - 1; i++) {
            pos += row[i];
            mpp[pos]++;
        }
    }
    
    int maxEdges = 0;
    for (auto it : mpp) {
        maxEdges = max(maxEdges, it.second);
    }
    
    return wall.size() - maxEdges;
}
};