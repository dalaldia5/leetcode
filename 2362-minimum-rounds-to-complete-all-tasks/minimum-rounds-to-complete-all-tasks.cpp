class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for (auto it : tasks) {
            mpp[it]++;
        }
        int ans = 0;
        for (auto it : mpp) {
            if (it.second < 2) {
                return -1;
                break;
            } else if (it.second == 2 || it.second == 3) {
                ans++;
            } else {
                ans += (it.second + 2) / 3;
            }
        }
        return ans;
    }
};