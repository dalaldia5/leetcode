class Solution {
public:
    // Ye function binary search se next job ka index nikalta hai
    // jiska start time >= current job ke end time ho
    int getNextIdx(vector<vector<int>>& nums, int l, int currJobEnd) {

        // Right pointer last job tak
        int r = nums.size() - 1;

        // Result store karega valid next job ka index
        int result = nums.size(); // default = no next job

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Agar mid job ka start time current job ke end se bada ya equal
            // hai
            if (nums[mid][0] >= currJobEnd) {
                result = mid; // possible answer
                r = mid - 1;  // left me aur better (earlier) answer dhundo
            } else {
                l = mid + 1; // right side jao
            }
        }
        return result;
    }

    // Recursive function:
    // idx = current job index jisko consider kar rahe hain
    int f(vector<vector<int>>& nums, int idx, vector<int>& dp) {

        // Base case:
        // Agar saare jobs process ho chuke hain
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];
        // Option 1: current job ko TAKE karo
        // next non-overlapping job ka index nikaalo
        int next = getNextIdx(nums, idx + 1, nums[idx][1]);

        // current profit + aage ka best profit
        int take = nums[idx][2] + f(nums, next, dp);

        // Option 2: current job ko NOT TAKE karo
        int not_take = f(nums, idx + 1, dp);

        // Dono me se maximum profit return karo
        return dp[idx] = max(take, not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        // nums[i] = {startTime, endTime, profit}
        vector<vector<int>> nums(n, vector<int>(3, 0));

        // Input arrays ko ek single structure me pack kar rahe hain
        for (int i = 0; i < n; i++) {
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }

        // Jobs ko start time ke according sort karte hain
        // taaki binary search possible ho
        sort(nums.begin(), nums.end());

        vector<int> dp(n, -1);
        // Recursion start karo first job se
        return f(nums, 0, dp);
    }
};
