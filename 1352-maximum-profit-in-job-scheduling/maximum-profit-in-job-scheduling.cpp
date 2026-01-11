class Solution {
public:
    int findNextIdx(vector<vector<int>>& nums, int currEnd, int l) {
        int r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid][0] >= currEnd) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int f(vector<vector<int>>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int next = findNextIdx(nums, nums[idx][1], idx);
        int take = nums[idx][2] + f(nums, next, dp);
        int notTake = f(nums, idx + 1, dp);
        return dp[idx] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> nums(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(n, -1);
        return f(nums, 0, dp);
    }
};