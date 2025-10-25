class Solution {
public:
    string longestPalindrome(string s) {
        // expanding through the center
        int resLen = 0;
        string ans = "";
        int l, r;
        for (int i = 0; i < s.size(); i++) {
            // odd length
            l = i, r = i;
            while (l >= 0 && r <= s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    ans = s.substr(l, r - l + 1);
                    resLen = (r - l + 1);
                }
                l--;
                r++;
            }
            // even length
            l = i, r = i + 1;
            while (l >= 0 && r <= s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    ans = s.substr(l, r - l + 1);
                    resLen = (r - l + 1);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};