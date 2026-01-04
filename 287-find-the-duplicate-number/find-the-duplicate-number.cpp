class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        for (auto j : mpp) {
            if (j.second > 1) {
                ans = j.first;
            }
        }
        return ans;
    }
};