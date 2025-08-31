class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        map<float, int> mpp;
        vector<string> ans;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (mpp.find(float(i) / j) != mpp.end()) {
                    continue;
                } else {
                    mpp[float(i) / j] = 1;
                    ans.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return ans;
    }
};