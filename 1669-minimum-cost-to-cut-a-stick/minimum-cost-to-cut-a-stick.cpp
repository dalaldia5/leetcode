class Solution {
private:
    // f(i, j) = minimum cost to cut the stick
    // jab hume cuts[i] se cuts[j] tak ke cuts lgane hain
    // aur current stick ki boundary cuts[i-1] se cuts[j+1] tk hai
    
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {

        // Base case:
        // Agar i > j ho gaya,
        // matlab iss stick segment me koi cut bacha hi nahi
        // toh cost = 0
        if (i > j)
            return 0;

        // DP check:
        // Agar iss state ka answer pehle se calculated hai,
        // toh directly return kar do
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        // Har possible cut ko pehle cut ke liye try karo (i se j ke beech)
        for (int ind = i; ind <= j; ind++) {
            // Current cut ka cost:
            // = current stick ki length
            // = right boundary - left boundary
            int cost =
                (cuts[j + 1] - cuts[i - 1]) + // current stick ki poori length
                f(i, ind - 1, cuts, dp) +     // left part ka minimum cost
                f(ind + 1, j, cuts, dp);      // right part ka minimum cost

            // Har possible cut ke cost me se minimum choose karo
            mini = min(mini, cost);
        }

        // Answer dp table me store karke return karo
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {

        // Stick ke dono ends add kar rahe hain:
        // 0 = start of stick
        // n = end of stick
        // Taaki har cut ke liye stick ki boundaries (length) clear ho
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Cuts ko increasing order me sort karna zaroori hai
        // so that stick segments sahi bane
        sort(cuts.begin(), cuts.end());

        int c = cuts.size(); // total cuts (including 0 and n)

        // DP table:
        // dp[i][j] = minimum cost to perform cuts from i to j
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // Recursion sirf REAL cuts ke liye start hoti hai
        // cuts[0] = 0 (boundary)
        // cuts[c-1] = n (boundary)
        // actual cuts = 1 se c-2 tak
        return f(1, c - 2, cuts, dp);
    }
};
