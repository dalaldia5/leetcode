class Solution {
public:
    vector<int> computeZArray(const string& s) {
        vector<int> z(s.size(), 0);
        int l = 0, r = 0;
        for (int i = 1; i < s.size(); i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int strStr(string haystack, string needle) {
        int ans = 0;
        string zString = needle + "$" + haystack;

        // call and store result properly
        vector<int> z = computeZArray(zString);

        for (int i = 0; i < z.size(); i++) {
            if (z[i] == needle.length()) {
                ans = i - (needle.length() + 1);
                return ans;
            }
        }

        return -1;
    }
};
