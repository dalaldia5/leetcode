class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int sum = 0, maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);

            if (sum == 0) {
                maxi = i + 1;
            } else if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            } else {
                mpp[sum] = i; // store first occurrence of this sum
            }
        }
        return maxi;
    }
};
