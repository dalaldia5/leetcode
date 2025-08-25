class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        map<int, vector<int>> mpp;

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                mpp[i + j].push_back(matrix[i][j]);

        for (auto it : mpp) {
            if ((it.first) % 2 == 0)
                reverse(it.second.begin(), it.second.end());

            for (auto k : it.second)
                ans.push_back(k);
        }
        return ans;
    }
};