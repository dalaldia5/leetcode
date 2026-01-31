class Solution {
public:
    int minimumK(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int l=1;
        int n=nums.size();
        int r=INT_MAX;
        int ans=nums[n-1];
        while (l<=r){
            int mid=l+(r-l)/2;
            long long ops=0;
            for (auto it: nums){
                ops+=(it+mid-1)/mid; // ceil
            }
            if (ops<=1LL*mid*mid){
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};