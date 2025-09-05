class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        set<int> set1, set2, set3;
        for (auto x : nums1)
            set1.insert(x);
        for (auto x : nums2)
            set2.insert(x);
        for (auto x : nums3)
            set3.insert(x);
        map<int, int> mpp;
        for (auto x : set1)
            mpp[x]++;
        for (auto x : set2)
            mpp[x]++;
        for (auto x : set3)
            mpp[x]++;
        vector<int> ans;
        for (auto x : mpp) {
            if (x.second > 1)
                ans.push_back(x.first);
        }
        return ans;
    }
};