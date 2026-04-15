class Solution {
public:
    void generatePattern(string currStr, int open, int close, int n, vector<string>& ans) {
        
        if (open == n && close == n) {
            ans.push_back(currStr);
            return;
        }
        if (open < n) {
            generatePattern(currStr + "(", open + 1, close, n, ans);
        }
        if (close < open) {
            generatePattern(currStr + ")", open, close + 1, n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generatePattern("", 0, 0, n, ans);
        return ans;
    }
};