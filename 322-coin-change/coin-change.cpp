class Solution {
private:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % coins[ind] == 0) {
                return target / coins[ind];
            } else {
                return 10001;
            }
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = f(ind - 1, target, coins, dp);
        int take = INT_MAX;
        if (coins[ind] <= target) {
            take = 1 + f(ind, target - coins[ind], coins, dp);
        }
        return dp[ind][target] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));
        int ans = f(n - 1, amt, coins, dp);
        if (ans >= 10001)
            return -1;
        else
            return ans;
    }
};