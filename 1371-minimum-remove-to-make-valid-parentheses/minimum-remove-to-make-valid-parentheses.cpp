class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int leftCnt = 0;
        int rightCnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                leftCnt++;
            } else if (ch == ')') {
                rightCnt++;
            }
            if (rightCnt > leftCnt) {
                rightCnt--;
                continue;
            } else {
                st.push(ch);
            }
        }
        string result = "";
        while (!st.empty()) {
            char currCh = st.top();
            st.pop();
            if (leftCnt > rightCnt && currCh == '(') {
                leftCnt--;
            } else {
                result += currCh;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};