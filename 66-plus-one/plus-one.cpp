class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        if (digits[n - 1] >= 0 && digits[n - 1] < 9) {
            for (int i = 0; i <= n - 2; i++) {
                ans.push_back(digits[i]);
            }
            ans.push_back(digits[n - 1] + 1);
        } else {
            ans.push_back(0);
            int carry = 1;
            for (int i = n - 2; i >= 0; i--) {
                if (digits[i] + carry == 10) {
                    ans.push_back(0);
                } else {
                    ans.push_back(digits[i] + carry);
                    carry = 0;
                }
            }
            if (carry)
                ans.push_back(1);
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};