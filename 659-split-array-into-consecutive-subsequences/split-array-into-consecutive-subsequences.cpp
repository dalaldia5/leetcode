class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, end;
        for (int i : nums)
            freq[i]++;
        for (int i = 0; i < nums.size(); i++) {
            int it = nums[i];
            if (freq[it] == 0)
                continue;
            freq[it]--;
            if (end[it - 1] > 0) {
                end[it - 1]--;
                end[it]++;
            } else if (freq[it + 1] > 0 && freq[it + 2] > 0) {
                freq[it + 1]--;
                freq[it + 2]--;
                end[it + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};