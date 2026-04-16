class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for (auto it: nums){
            total+=it;
        }
        int target=total-x;
        int l=0;
        int maxLen=INT_MIN;
        if (target==0){
            return nums.size();
        }
        int sum=0;
        for (int r=0; r<nums.size(); r++){
            sum+=nums[r];
            while (l<=r && sum>target) {
                sum-=nums[l];
                l++;
            }
            if (sum==target) {
                maxLen=max(maxLen, r-l+1);
            }
        }
        if (maxLen==INT_MIN){
            return -1;
        }
        return nums.size()-maxLen;
    }
};