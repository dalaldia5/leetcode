class Solution {
private:
    int f(int ind, int prevInd, int n, vector<int>& nums,
          vector<vector<int>>& dp) {

        // Base case:
        // Agar hum array ke end tak pahunch gaye,
        // toh LIS ki length 0 hogi
        if (ind == n)
            return 0;

        // DP check:
        // Agar is state ka answer pehle se calculate ho chuka hai
        // toh wahi return kar do
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        // Option 1: current element ko NOT pick karo
        // Simply next index par move kar jao
        int len = 0 + f(ind + 1, prevInd, n, nums, dp);

        // Option 2: current element ko pick karo
        // Pick tabhi kar sakte ho jab:
        // 1) abhi tak koi previous element pick nahi hua (prevInd == -1)
        // 2) ya current element > previous picked element ho
        if (prevInd == -1 || nums[ind] > nums[prevInd]) {
            len = max(len, 1 + f(ind + 1, ind, n, nums, dp));
        }

        // Jo bhi maximum length mili (pick vs not pick),
        // usko dp table me store karke return kar do
        return dp[ind][prevInd + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // DP table:
        // dp[ind][prevInd + 1]
        // prevInd + 1 isliye use kiya kyunki prevInd -1 bhi ho sakta hai
        // (coordinate shifting)
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Recursion start karo index 0 se
        // aur prevInd = -1 (abhi kuch pick nahi hua)
        return f(0, -1, n, nums, dp);
    }
};
