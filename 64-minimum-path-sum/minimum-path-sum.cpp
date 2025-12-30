class Solution {
private:
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        if (i == 0 && j == 0)
            return grid[i][j];

        // IF INDICES GO OUT OF BOUND, RETURN SUCH A HIGH VALUE SO THAT IT'S NOT
        // CONSIDERED
        if (i < 0 || j < 0)
            return 1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = grid[i][j] +
                          min(f(i - 1, j, dp, grid), f(i, j - 1, dp, grid));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};