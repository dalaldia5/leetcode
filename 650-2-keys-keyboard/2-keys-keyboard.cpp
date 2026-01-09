class Solution {
public:
    int f(int currA, int clip, int n, vector<vector<int>>& dp) {
        if (currA == n)
            return 0;
        if (currA > n)
            return 1001;
        if (dp[currA][clip] != -1)
            return dp[currA][clip];
        int copyAllPaste = 2 + f(currA * 2, currA, n, dp);
        int paste = 1 + f(currA + clip, clip, n, dp);
        return dp[currA][clip] = min(copyAllPaste, paste);
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + f(1, 1, n, dp);
    }
};
