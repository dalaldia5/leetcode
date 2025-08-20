class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;
        for (auto el : nums) {
            totalSum += el;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int valLeft = (nums[i] * i) - leftSum;
            int valRight = (totalSum - leftSum - nums[i] * (n - i));
            leftSum += nums[i];
            ans.push_back(valLeft + valRight);
        }
        return ans;
    }
};