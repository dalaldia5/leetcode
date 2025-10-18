class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        unordered_set<int> set;
        long long last = LLONG_MIN;
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // allowed range for current number
            long long low = (long long)nums[i] - k;
            long long high = (long long)nums[i] + k;

            // pick the smallest possible number greater than last
            long long val = max(low, last + 1);

            if (val <= high) {
                set.insert(val);
                cnt++;
                last = val;
            }
        }

        return cnt;
    }
};
