class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        string largestSubstring = "";
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                s += num[i];
                s += num[i + 1];
                s += num[i + 2];
                largestSubstring = max(s, largestSubstring);
                s = "";
            }
        }
        return largestSubstring;
    }
};