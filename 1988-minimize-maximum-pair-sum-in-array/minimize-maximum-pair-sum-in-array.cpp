class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int maxi=INT_MIN;
        for (int i=0; i<n; i++){
            maxi=max(maxi, nums[i]+nums[n-i-1]);
        }
        return maxi;
    }
};