class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pref = 1;
        int suff = 1;
        for (int i = 0; i < nums.size(); i++) {
            pref *= nums[i];
            ans = max(ans, pref);
            if (pref == 0) {
                pref = 1;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suff *= nums[i];
            ans = max(ans, suff);
            if (suff == 0) {
                suff = 1;
            }
        }
        return ans;
    }
};