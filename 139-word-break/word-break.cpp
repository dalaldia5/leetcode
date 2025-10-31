class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int start,
               vector<int>& dp) {
        // Base case: reached end of string
        if (start == s.length())
            return true;

        // Already computed result
        if (dp[start] != -1)
            return dp[start];

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);

            // If prefix is in dictionary and rest of string can also be broken
            if (dict.count(word) && solve(s, dict, end, dp))
                return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1); // -1 = unvisited
        return solve(s, dict, 0, dp);
    }
};
