class Solution {
public:
    vector<string> result;
    void generatePattern(string currStr, int open, int close, int n) {
        if (open == n && close == n) {
            result.push_back(currStr);
            return;
        }
        if (open < n) {
            generatePattern(currStr + "(", open + 1, close, n);
        }
        if (close < open) {
            generatePattern(currStr + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        generatePattern("", 0, 0, n);
        return result;
    }
};