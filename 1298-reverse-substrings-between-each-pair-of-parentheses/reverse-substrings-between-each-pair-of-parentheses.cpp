class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st2;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st2.push(s[i]);
            } else if (s[i] == ')') {
                string temp = "";
                while (!st2.empty() && st2.top() != '(') {
                    temp += st2.top();
                    st2.pop();
                }
                if (!st2.empty())
                    st2.pop(); // remove '('

                for (char c : temp)
                    st2.push(c);
            } else {
                st2.push(s[i]);
            }
        }
        while (st2.size()) {
            int alpha = st2.top();
            st2.pop();
            ans += alpha;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};