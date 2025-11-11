class Solution {
public:
    int strStr(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i + j] != s2[j])
                    break;
                if (j == s2.size() - 1)
                    return i;
            }
        }
        return -1;
    }
};