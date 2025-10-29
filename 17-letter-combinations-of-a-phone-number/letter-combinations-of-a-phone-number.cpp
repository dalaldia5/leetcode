class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> pad = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        ans.push_back("");
        for (auto key : digits) {
            vector<string> temp;
            for (auto candidate : pad[key - '0']) {
                for (auto c : ans) {
                    temp.push_back(c + candidate);
                }
            }
            ans = temp;
        }
        return ans;
    }
};