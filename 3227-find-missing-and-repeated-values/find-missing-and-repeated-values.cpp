class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mpp[grid[i][j]]++;
            }
        }
        for (auto it : mpp) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        for (int i = 0; i < n * n; i++) {
            if (mpp.find(i + 1) == mpp.end()) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};