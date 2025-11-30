class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long numsSum = 0;

        for (int i = 0; i < n; i++) {
            numsSum += nums[i];
        }

        int remainder = numsSum % p;
        if (remainder == 0)
            return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long prefixSum = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int targetMod = (currMod - remainder + p) % p;
            if (mpp.find(targetMod) != mpp.end()) {
                ans = min(ans, i - mpp[targetMod]);
            }
            mpp[currMod] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};
