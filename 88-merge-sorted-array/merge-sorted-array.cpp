class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m - 1;
        int nIdx = n - 1;
        int r = m + n - 1; 
        while(nIdx>=0){
            if(mIdx>=0 && nums1[mIdx]>nums2[nIdx]){
                nums1[r]=nums1[mIdx];
                mIdx--;
            }
            else{
                nums1[r]=nums2[nIdx];
                nIdx--;
            }
            r--;
        }
    }
};