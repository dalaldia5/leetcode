class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int mini = INT_MAX;
        int maxi = 0;
        for (auto &p : v) {
            int idx = p.second;
            mini = min(mini, idx);
            maxi = max(maxi, idx - mini);
        }
        return maxi;
    }
};