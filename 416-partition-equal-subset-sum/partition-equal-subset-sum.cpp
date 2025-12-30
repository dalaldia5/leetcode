class Solution {
public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {

        // Base case 1:
        // Agar target 0 ho gaya, matlab required subset mil chuka hai
        if (target == 0)
            return true;

        // Base case 2:
        // Agar sirf 0th element bacha h,
        // toh check karo kya vhi target ke equal hai
        if (idx == 0)
            return target == nums[idx];

        // DP check:
        // Agar iss state ka answer pehle se calculate hai, toh directly return kar do
        if (dp[idx][target] != -1)
            return dp[idx][target];

        // Option 1: current element ko NOT take karo
        // pichle elements ke saath target try karo
        bool not_take = f(idx - 1, target, nums, dp);

        // Option 2: current element ko TAKE karo
        // tabhi possible jab nums[idx] <= target ho
        bool take = false;
        if (nums[idx] <= target) {
            take = f(idx - 1, target - nums[idx], nums, dp);
        }

        // Agar take ya not_take me se koi bhi true hai,
        // toh answer true hoga
        return dp[idx][target] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Array ka total sum calculate karo
        for (auto it : nums) {
            sum += it;
        }

        // Agar total sum odd hai, toh 2 equal subsets possible hi nahi
        if (sum % 2 != 0)
            return false;

        // DP table:
        // dp[idx][target] batayega
        // kya nums[0..idx] se target sum ban sakta hai ya nahi
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        // Last index se recursion start karo aur target = total_sum / 2
        return f(n - 1, sum / 2, nums, dp);
    }
};
