class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time, int i, int wallsLeft,
              vector<vector<int>>& dp) {

        // Base case 1:
        // Agar wallsLeft <= 0 ho gaya
        // matlab saari walls paint ho chuki hain
        if (wallsLeft <= 0) {
            return 0;
        }

        // Base case 2:
        // Agar saare painters check kar liye aur abhi bhi walls bachi hain
        // toh ye invalid case hai
        if (i >= cost.size()) {
            return 1e9;
        }

        // DP check:
        // Agar iss state ka answer pehle se store hai toh wahi return kar do
        if (dp[i][wallsLeft] != -1) {
            return dp[i][wallsLeft];
        } else {
            // Option 1: current painter ko NOT take karo
            // next painter par move karo, wallsLeft same rhengi
            int notTake = solve(cost, time, i + 1, wallsLeft, dp);

            // Option 2: current painter ko TAKE karo
            // cost add hogi aur wallsLeft se (time[i] + 1) walls reduce hongi
            int take =
                cost[i] + solve(cost, time, i + 1, wallsLeft - time[i] - 1, dp);

            // Dono options me se minimum cost choose karo
            return dp[i][wallsLeft] = min(notTake, take);
        }
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // DP table:
        // dp[i][wallsLeft] = minimum cost using painters from index i onwards
        // to paint 'wallsLeft' number of walls
        vector<vector<int>> dp(501, vector<int>(501, -1));
        // Initially:
        // i = 0 (first painter)
        // wallsLeft = total number of walls = time.size()
        return solve(cost, time, 0, time.size(), dp);
    }
};