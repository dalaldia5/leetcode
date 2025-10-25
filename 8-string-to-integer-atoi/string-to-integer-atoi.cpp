class Solution {
public:
    int myAtoi(string s) {
        int idx = 0, sign = 1;
        long ans = 0;
        // dealing w leading whitespaces
        while (idx < s.size() && s[idx] == ' ') {
            idx++;
        }
        // if string is filled with whitespaces only
        if (idx == s.size())
            return 0;
        // dealing w -ve sign
        if (s[idx] == '-') {
            sign = -1;
            idx++;
            // dealing w +ve sign
        } else if (s[idx] == '+') {
            idx++;
        }
        // taking into consideration only digits and leaving the alphabets
        while (idx < s.size() && isdigit(s[idx])) {
            ans = ans * 10 + (s[idx] - '0');
            // dealing w overflow and underflow
            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;
            idx++;
        }
        return ans * sign;
    }
};