class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> diagMap;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diagMap[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& it : diagMap) { // important: reference use krna hai
            if (it.first < 0) {
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.rbegin(), it.second.rend());
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = diagMap[i - j].front();
                diagMap[i - j].erase(diagMap[i - j].begin());
            }
        }
        return grid;
    }
};