class Solution {
private:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: Agar hum 0th coin par aa gaye hain
        if (ind == 0) {
            // Agar target coins[0] se exactly divide ho raha hai,
            // toh utne coins chahiye
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9; // impossible case
        }
        // DP check: Agar iss state ka answer pehle se calculated hai
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // Option 1: current coin ko NOT take karo pichle coins par move karo
        int notTake = f(ind - 1, target, coins, dp);
        // Option 2: current coin ko TAKE karo
        // (same coin ko multiple times le sakte hain toh ind-1 mt kro)
        int take = INT_MAX;
        if (coins[ind] <= target) {
            take = 1 + f(ind, target - coins[ind], coins, dp);
        }
        // Dono options me se minimum store karo
        return dp[ind][target] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        // DP table:
        // dp[ind][target] = minimum coins needed
        // using coins[0..ind] to make 'target'
        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));
        int ans = f(n - 1, amt, coins, dp);
        // Agar answer bahut bada hai, matlab possible nahi
        return ans >= 1e9 ? -1 : ans;
    }
};
