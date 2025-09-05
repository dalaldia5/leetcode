class Solution {
    // Recursive function with memoization (top-down DP)
    int dfs(int i, int n, vector<int>& uniqueNums,
            unordered_map<int, int>& freq, vector<int>& dp) {
        // Base case: if we've considered all unique numbers
        if (i == n)
            return 0;

        // If result already computed, return from dp
        if (dp[i] != -1)
            return dp[i];

        // ---- Choice 1: Do NOT pick this number ----
        // Skip current number and move to the next
        int notPick = dfs(i + 1, n, uniqueNums, freq, dp);

        // ---- Choice 2: Pick this number ----
        // If we pick nums[i], we earn "value * frequency"
        int pick = freq[uniqueNums[i]] * uniqueNums[i];

        // But if the next number is consecutive (nums[i] + 1),
        // we cannot take it → so skip to (i + 2)
        if (i + 1 < n && uniqueNums[i] + 1 == uniqueNums[i + 1]) {
            pick += dfs(i + 2, n, uniqueNums, freq, dp);
        }
        // Otherwise, safe to take the next one as well
        else {
            pick += dfs(i + 1, n, uniqueNums, freq, dp);
        }

        // Store the best result for this index in dp
        return dp[i] = max(pick, notPick);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // Step 1: Count the frequency of each number
        // Example: nums = [2,2,3,3,3,4] → freq = {2:2, 3:3, 4:1}
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Extract all unique numbers and sort them
        // We need sorting to handle consecutive numbers properly
        vector<int> uniqueNums;
        for (auto& entry : freq) {
            uniqueNums.push_back(entry.first);
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        int n = uniqueNums.size();

        // Step 3: Initialize DP array for memoization
        // dp[i] = max points we can earn considering numbers from index i → end
        vector<int> dp(n, -1);

        // Step 4: Start recursive DP from index 0
        return dfs(0, n, uniqueNums, freq, dp);
    }
};
