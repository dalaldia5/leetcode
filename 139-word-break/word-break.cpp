class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int start,
               vector<int>& dp) {

        // Base case:
        // Agar start string ke end par pahunch gaya,
        // matlab poori string successfully break ho chuki hai
        if (start == s.length())
            return true;

        // DP check:
        // Agar is start index ka answer pehle se calculate hai,
        // toh wahi return kar do
        if (dp[start] != -1)
            return dp[start];

        // Current start se saare possible substrings try karo
        for (int end = start + 1; end <= s.length(); end++) {

            // Substring nikalo: s[start .. end-1]
            string word = s.substr(start, end - start);

            // Agar current substring dictionary me present hai
            // aur baaki string (end se aage) bhi break ho sakti hai
            // toh answer true ho jayega
            if (dict.count(word) && solve(s, dict, end, dp))
                return dp[start] = true;
        }

        // Agar koi bhi valid break possible nahi,
        // toh is index se string break nahi ho sakti
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        // unordered_set isliye use kiya
        // kyunki word present hai ya nahi
        // ye check O(1) time me ho jata hai
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // 1-D DP:
        // dp[i] batata hai ki index i se
        // string aage break ho sakti hai ya nahi
        vector<int> dp(s.length(), -1); // -1 = abhi calculate nahi hua

        // Recursion start index 0 se karo
        return solve(s, dict, 0, dp);
    }
};
