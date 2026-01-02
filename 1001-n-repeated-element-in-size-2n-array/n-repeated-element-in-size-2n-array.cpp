class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int ans;
        for (auto it : nums) {
            mpp[it]++;
        }
        for (auto i : mpp) {
            if (i.second == (n / 2)) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};