class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt = nums.size();
        unordered_set<long long> st;
        int n = nums.size();
        for (int x : nums)
            st.insert(x);
        for (int i = 0; i < n; i++) {
            long long curr = nums[i];
            unordered_map<int, int> mpp;
            mpp[nums[i]]++;
            for (int j = i + 1; j < n; j++) {
                curr += nums[j];
                mpp[nums[j]]++;
                for (auto it: mpp){
                    if (curr==it.first){
                        cnt++;
                    }
                    else continue;
                }
            }
        }
        return cnt;
    }
};
