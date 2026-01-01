class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.size();
        for (int i = 0; i < n / 2; i++) {
            if (str[i] != str[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void f(int idx, int n, string& s, vector<string>& path,
           vector<vector<string>>& ans) {

        if (idx == n) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < n; i++) {
            string temp = s.substr(idx, i - idx + 1);
            if (isPalindrome(temp)) {
                path.push_back(temp);
                f(i + 1, n, s, path, ans);
                path.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        f(0, n, s, path, ans);
        return ans;
    }
};
