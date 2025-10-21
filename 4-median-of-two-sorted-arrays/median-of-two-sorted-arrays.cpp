class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while (i < n)
            ans.push_back(nums1[i++]);
        while (j < m)
            ans.push_back(nums2[j++]);
        int s = ans.size();
        if (s % 2)
            return ans[s / 2.0];
        else
            return (ans[s / 2 - 1] + ans[s / 2]) / 2.0;
    }
};